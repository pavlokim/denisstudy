<?php

/**
 * @file
 *  batire_links.inc
 */

/**
 * Store links from document to documents in separate table
 * @param string $bid - Bid of link from document
 * @param string $id - Id of links from document
 * @param array $links  -  array( array('bid'=> '<>' , 'title' => '<>', 'rel_type' => '<>' ), ...)
 */
function batire_store_links($bid, $id, &$links) {
  $sql_values = array();
  $sql_placeholders = array();
  if (empty($links)) {
    return TRUE;
  }

  // Get root term for bid
  $types = array(BATIRE_SITE_VID_FM, BATIRE_SITE_VID_LIVRES, BATIRE_SITE_VID_TO);
  $query = db_query('
    SELECT tn.tid
    FROM {batire_hierarchy} bh
    LEFT JOIN {term_node} tn ON tn.nid = bh.nid
    LEFT JOIN {term_data} td ON td.tid = tn.tid
    WHERE bh.bid = "%s" AND td.vid IN (' . db_placeholders($types) . ')
    GROUP BY tn.tid
  ', array_merge(array($bid), $types));
  $root_tid = db_result($query);

  $count = 0;
  db_query('DELETE FROM {batire_links} WHERE bid_from = "%s"', $bid);
  $sql_100 = 'INSERT INTO {batire_links} (`bid_from`, `id_from`, `bid_to`, `id_to`, `rel_type`, `title`) VALUES ' .
        str_repeat("('%s','%s','%s','%s','%s','%s'), ", 99) . "('%s','%s','%s','%s','%s','%s')";

  $query_values = array();
  foreach ($links as $link) {
    if (empty($link) || $link['sens'] == 'cible') {
      continue;
    }
    $key = $bid . '-' . $link['bid'] . '-' . $link['type'];
    if (!isset($query_values[$key])) {
      $query_values[$key] = array(
        'bid_from' => $bid,
        'id_from' => $id,
        'bid_to' => $link['bid'],
        'id_to' => $link['id'],
        'rel_type' => $link['type'],
        'title' => $link['title'],
      );
    }
    // Update backlinks in referenced documents
    $nid = batire_hierarchy_get_by_bid($link['bid'], 'nid');
    $node = node_load($nid);
    if (isset($node->field_cites)) {
      $exists = FALSE;
      foreach ($node->field_cites as $cite) {
        if ($cite['value'] == $root_tid) {
          $exists = TRUE;
          break;
        }
      }
      if (!$exists) {
        $node->field_cites[]['value'] = $root_tid;
        node_save($node);
      }
    }
  }
  foreach ($query_values as $value) {
    $count ++;
    // $sql_values[] = '(\''.implode('\',\'',array($bid, $id, $link['bid'], $link['id'], $link['type'], $link['title'])).'\')';
    // @todo need to replcace with db_placeholders
//    $sql_placeholders[] = "('%s','%s','%s','%s','%s','%s')";
    //$sql_values = array_merge($sql_values, array($bid, $id, $link['bid'], $link['id'], $link['type'], $link['title']));
    $sql_values[] = $value['bid_from'];
    $sql_values[] = $value['id_from'];
    $sql_values[] = $value['bid_to'];
    $sql_values[] = $value['id_to'];
    $sql_values[] = $value['rel_type'];
    $sql_values[] = $value['title'];


    if ($count == 100) {
      db_query($sql_100, $sql_values);
      $count = 0;
      $sql_values = array();
    }
  }
  if ($count) {
    $sql = 'INSERT INTO {batire_links} (`bid_from`, `id_from`, `bid_to`, `id_to`, `rel_type`, `title`) VALUES ' .
        str_repeat("('%s','%s','%s','%s','%s','%s'), ", $count - 1) . "('%s','%s','%s','%s','%s','%s')";
    db_query($sql, $sql_values);

  }
  //$sql_query = 'REPLACE {batire_links} (`bid_from`, `id_from`, `bid_to`, `id_to`, `rel_type`, `title`) VALUES ' . implode(',', $sql_placeholders);
  return TRUE;
}

//function batire_get_links_by_bid($bid) {
//  $result = array('refs' => array(), 'backrefs' => array());
//  $res = db_query('SELECT {batire_hierarchy}.nid as nid, {batire_hierarchy}.`type` as `node_type`,
//   {batire_hierarchy}.`title` as node_title,  {batire_links}.bid_to as bid,
//{batire_links}.`rel_type` as link_type, {batire_links}.title as `link_tytle`
//FROM {batire_hierarchy}
//left join {batire_links} on {batire_links}.`bid_to` = {batire_hierarchy}.`bid`
// where {batire_hierarchy}.`bid` = \'%s\'', $bid);
//  while ($row = db_fetch_array($res)) {
//    $result['refs'][] = $row;
//  }
//  $res = db_query('SELECT {batire_hierarchy}.nid as nid, {batire_hierarchy}.`type` as `node_type`,
//   {batire_hierarchy}.`title` as node_title,  {batire_links}.bid_from as bid,
//{batire_links}.`rel_type` as link_type, {batire_links}.title as `link_tytle`
//FROM {batire_hierarchy}
//left join {batire_links} on {batire_links}.`bid_from` = {batire_hierarchy}.`bid`
// where {batire_hierarchy}.`bid` = \'%s\'', $bid);
//  while ($row = db_fetch_array($res)) {
//    $result['backrefs'][] = $row;
//  }
//  return $result;
//}

/**
 * Get document links
 * @param $bid
 * @return Array List of links
 */
function batire_hierarchy_get_links_by_bid($bid) {
  $result = array('refs' => array(), 'backrefs' => array());
  $refs = db_query('
    SELECT bl.bid_from, bl.bid_to, bl.rel_type, bl.title, bh.nid, bh.type
    FROM {batire_links} bl
    LEFT JOIN {batire_hierarchy} bh ON bh.bid = bl.bid_to
    WHERE bl.bid_from = "%s" AND NOT(bl.bid_to REGEXP "%s")
  ', $bid, '-[0-9]{8,}$');
  while ($row = db_fetch_object($refs)) {
    $result['refs'][] = $row;
  }

  $brefs = db_query('
    SELECT bl.bid_from, bl.bid_to, bl.rel_type, bl.title, bh.nid, bh.type
    FROM {batire_links} bl
    LEFT JOIN {batire_hierarchy} bh ON bh.bid = bl.bid_from
    WHERE bl.bid_to = "%s" AND NOT(bl.bid_from REGEXP "%s")
  ', $bid, '-[0-9]{8,}$');
  while ($row = db_fetch_object($brefs)) {
    $result['backrefs'][] = $row;
  }
  return $result;
}

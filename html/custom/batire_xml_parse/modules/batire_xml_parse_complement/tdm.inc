<?php

function _batire_xml_parse_ct_summary_parse(&$data, $dom) {

  $xpath = batire_xml_get_xpath($dom);
  $dom_nodes = batire_xml_xpath_run_query($xpath, "/qc:doc-root/qc:doc-content/tdm");
  if (!$dom_nodes || !$dom_nodes->length) {
    throw new Batire_Xml_Parse_Exception("Incorrect TDM format");
  }

  $parsed = batire_xml_multiple_node_value_get($xpath, array(
    'id_hz' => '/qc:doc-root/qc:doc-meta/ns0:id',
    'date_document' => '/qc:doc-root/qc:doc-meta/ns0:date-document | /qc:doc-root/qc:doc-meta/ns1:date-document | /qc:doc-root/qc:doc-meta/gm:date-document',
    'super_id' => '/qc:doc-root/qc:doc-meta/ns0:id-edmon | /qc:doc-root/qc:doc-content/tdm/@id',
    'release' => '/qc:doc-root/qc:doc-content/tdm/@num-parution'
    ));
  $data['id'] = $parsed['super_id'];
  $data['bid'] = batire_hierarchy_get_document_bid($data['id'], BATIRE_HIERARCHY_DT_LIVRE);
  $data['super_bid'] = batire_hierarchy_get_document_bid($parsed['super_id'], BATIRE_HIERARCHY_DT_LIVRE);
  $data['page_version'] = batire_xml_parse_convert_date($parsed['date_document']);
  $data['taxonomy'] = batire_xml_get_taxonomy($xpath);
  $data = array_merge($data, $parsed);
  $data['tree'] = _batire_xml_parse_ct_summary_parse_recursive($dom_nodes->item(0), $xpath);
  foreach ($data['tree'] as & $page) {
    if ($page['bid'] == $data['bid']) {
      $page['version'] = $data['page_version'];
      //$term = batire_xml_parse_search_term($data['id'], BATIRE_SITE_VID_, NULL, 'description');
      $page['title'] = $term['name'];
    }
  }
  //return $data;
}

function _batire_xml_parse_ct_summary_parse_recursive($dom_node, $xpath) {

  $documentNodeList = $xpath->query('ud', $dom_node);

  if (is_object($documentNodeList) && $documentNodeList->length > 0) {
    $data = array();
    foreach ($documentNodeList as $documentNode) {
       $page =  batire_xml_multiple_node_value_get($xpath, array(
        'id' => './@id',
        'title' => './titre',
        'date' => './@datemaj'

      ), $documentNode);
      $page['bid'] = batire_hierarchy_get_document_bid($page['id'], BATIRE_HIERARCHY_DT_LIVRE);
      $page['tree'] = _batire_xml_parse_ct_summary_parse_recursive($documentNode, $xpath);
      $data[] = $page;
    }
    return $data;
  }
  return NULL;
}

function _batire_xml_parse_ct_summary_store(&$data) {
  $hierarchy = batire_hierarchy_get_by_bid($data['bid']);
  if ($hierarchy && $hierarchy->version && $hierarchy->version > $data['page_version']) {
    //like we have more fresh summary imported, just ignore this
    $data['op'] = 'ignore';
    return;
  }
  batire_hierarchy_destroy_hierarchy($data['bid']);
  $result =  _batire_xml_parse_ct_summary_store_tree_recursive($data['tree'], $data['bid'], $data['id']);
  $data['op'] = 'hierarchy';
  return $result;

}

function _batire_xml_parse_ct_summary_store_tree_recursive($children, $parent_bid = NULL, $parent_id = NULL) {
  static $doc_type;//static for performance
  if (!$doc_type) {
    $doc_type = batire_hierarchy_get_doc_type(BATIRE_HIERARCHY_DT_LIVRE);
  }

  $result = TRUE;
  foreach ($children as $position => $child) {
    $child_row = (object) $child;
    if (!isset($child_row->type)) {
      $child_row->type = $doc_type['content_type'];
    }
    batire_hierarchy_update_smart($child_row);
    batire_hierarchy_attach_children($parent_bid, $child_row->bid, $position + 1, $parent_id);
    if (!empty($child['tree'])) {
      $result = _batire_xml_parse_ct_summary_store_tree_recursive($child['tree'], $child_row->bid, $child_row->id) && $result;
    }
  }
  return $result;
}

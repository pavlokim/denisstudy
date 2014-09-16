<?php

/**
 * @file
 *  batire_site.url.inc
 */
function custom_url_rewrite_outbound(&$path, &$options, $original_path) {
  $path_ar = explode('/', $path);
  if ($path_ar[0] == 'node' && is_numeric($path_ar[1]) && !isset($path_ar[2])) {
    $bid = batire_hierarchy_get_by_nid($path_ar[1], 'bid');
    if (!empty($bid)) {
      $path = 'document/' . $bid;
    }
  }
  if ($path_ar[0] == 'node' && is_numeric($path_ar[1]) && isset($path_ar[2]) && $path_ar[2] == 'norme-afnor') {
    $bid = batire_hierarchy_get_by_nid($path_ar[1], 'bid');
    if (!empty($bid)) {
      $path = 'document/' . $bid . '/norme-afnor';
    }
  }
  if ($path_ar[0] == 'print' && is_numeric($path_ar[1]) && !isset($path_ar[2])) {
    $bid = batire_hierarchy_get_by_nid($path_ar[1], 'bid');
    if (!empty($bid)) {
      $path = 'print/' . $bid;
    }
  }
}

function custom_url_rewrite_inbound(&$result, $path, $path_language) {
  $path_ar = explode('/', $path);
  if ($path_ar[0] == 'document') {
    $nid = batire_hierarchy_get_by_bid($path_ar[1], 'nid');
    if ($nid && !isset($path_ar[2])) {
      $result = 'node/' . $nid;
    } elseif ($nid && isset($path_ar[2]) && $path_ar[2] == 'norme-afnor') {
      $result = 'node/' . $nid . '/norme-afnor';
    } else {
      // try to resolve link with anchor
      $bid_ar = explode('-', $path_ar[1]);
      $last_part = array_pop($bid_ar);
      $part_length = strlen($last_part);
      $cuted_part = 2;
      while (!($nid = batire_hierarchy_get_by_bid(substr($path_ar[1], 0, -$cuted_part), 'nid')) && 1 < $part_length - $cuted_part) {
        $cuted_part += 2;
      }
      if ($nid) {
        $bid_ar = explode('-', $path_ar[1]);
        array_shift($bid_ar);
        $fragment_name = implode('-', $bid_ar);
        $path_ar[1] = substr($path_ar[1], 0, -$cuted_part);
        $redirect_url = implode('/', $path_ar);
        require_once './includes/common.inc';
        drupal_goto($redirect_url, NULL, $fragment_name);
      }
    }
  }
  if ($path_ar[0] == 'print' && $nid = batire_hierarchy_get_by_bid($path_ar[1], 'nid')) {
    $result = 'print/' . $nid;
  }
}

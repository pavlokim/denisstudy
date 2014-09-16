<?php

/**
 * @file
 *  batire_search_ui.inc
 * Addional functions
 */

/**
 * Clean search storage
 */
function _batire_search_ui_clean_search_cookies() {
  $admin_search_count = variable_get('batire_search_count_searches_to_display', BATIRE_SEARCH_COUNT_SEARCH_TO_DISPLAY);
  $count = ceil($admin_search_count / BATIRE_SEARCH_UI_COUNT_COOKIE_IDS);
  for ($i = 0; $i < $count; $i++) {
    _batire_site_set_cookie('search_documents_' . $i);
  }
}

/**
 * Get search data for search id just for search  results page.
 */
function _batire_search_ui_get_search_data_result_page() {
  $search_data = array();
  $args = arg();
  if ($args[0] == 'recherche-avancee' && $args[1] == 'resultats') {
    $sid = $args[2];
    $search_data = batire_search_load_search_criteries($sid);
    $search_data['sid'] = $sid;
  }
  if (isset($args[1]) && is_numeric($args[1])) {
    $node = node_load($args[1]);
    $node_type_list = batire_site_get_document_types_list();

    if (in_array($node->type, array_keys($node_type_list))) {
      if (isset($_GET['sl'])) {
        $sid = explode('-', $_GET['sl']);
        $search_data = batire_search_load_search_criteries($sid[0]);
        $search_data['sid'] = $sid[0];
      }
    }
  }
  return $search_data;
}

/**
 * Check if key from url is real search id
 * @param type $check_r_search
 * @return Search id OR FALSE
 */
function batire_search_ui_check_is_url_has_search_id($check_r_search = FALSE) {
  if (array_key_exists('sl', $_GET) && !empty($_GET['sl'])) {
    $output = NULL;
    $sl = $_GET['sl'];
    $keys = explode('-', $sl);
    if (!$check_r_search) {
      if (mongodb_search_find_search_id($keys[0])) {
        return $keys[0];
      }
    }
    else {
      if (isset($keys[1])) {
        if (mongodb_search_find_search_id($keys[1])) {
          return $keys[1];
        }
      }
    }
  }
  return FALSE;
}

/**
 * Check current node if it displays after search
 * @param $args List of arguments from url
 * @return TRUE OR FALSE
 */
function batire_search_ui_check_is_node_after_search($args) {
  $node = node_load($args[1]);
  if (_batire_site_is_document($node->type)) {
    return (bool) batire_search_ui_check_is_url_has_search_id();
  }
  return FALSE;
}

/**
 * Check related search id
 * @return BOOLEAN
 */
function batire_search_ui_check_related_search_id() {
  $sid = arg(2);
  $r_sid = arg(3);
  if (!empty($r_sid)) {
    if (mongodb_search_find_search_id($r_sid)) {
      $related_search_data = mongodb_search_get_search_data($r_sid);
      if ($related_search_data['data']['related_search'] == $sid) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

/**
 * Set params to pager
 * @param $pager Additional parameters for pager
 * @param $element An optional integer to distinguish between multiple pagers on one page.
 */
function batire_search_ui_set_pager_data($pager, $element = 0) {
  global $pager_page_array, $pager_total, $pager_total_items;
  $pager_total_items[$element] = $pager->total;
  $pager_total[$element] = ceil($pager_total_items[$element] / $pager->per_page);
  $pager_page_array[$element] = max(0, min((int) $pager->get_page, ((int) $pager_total[$element]) - 1));
}

/**
 * Run search process
 * @param $sid Search id
 * @param $r_sid Related search id
 */
function _batire_search_ui_search_process($sid, $r_sid = NULL) {
  global $user;
  if (!$replace_user = batire_gc_ip_replace_user()) {
    $replace_user = $user;
  }

  _batire_search_ui_related_search_process($sid, $r_sid);
  $w_sid = $sid;
  if (!empty($r_sid) && mongodb_search_find_search_id($r_sid)) {
    $w_sid = $r_sid;
    $search_sid = mongodb_search_get_search_data($sid);
  }

  $refine_search = batire_search_filter_search($sid);
  /*if (empty($r_sid) && !empty($refine_search)) {
    _batire_site_set_var(BATIRE_SEARCH_SESSION_VIEWS_NAMESPACE, $sid . '_ref', $refine_search);
  }
  elseif(empty($r_sid) && empty($refine_search)) {
    $pager = _batire_site_get_var(BATIRE_SEARCH_SESSION_VIEWS_NAMESPACE, $sid, NULL);
    if (isset($pager->pager_list) && count($pager->pager_list) > 1) {
      $pager->pager_list = array();
      _batire_site_set_var(BATIRE_SEARCH_SESSION_VIEWS_NAMESPACE, $sid, $pager);
    }
  }*/

  if ($sid != $w_sid) {
    batire_search_filter_search($w_sid);
  }
  $pager = batire_search_run_search($sid, $r_sid); // start to search

  //Login popup for TN only
  $data = mongodb_search_get_search_data($sid);
  $tn_only = (isset($data['data']['tn_only'])) ? $data['data']['tn_only'] : FALSE;
  unset($data);

  if (!$replace_user->uid && $tn_only) {

    $query = $_REQUEST;

    if (isset($query['q'])) {
      unset($query['q']);
    }

    $query_str = array();
    if (count($query)) {
      foreach($query as $key => $val) {
        $query_str[] = $key . '=' . $val;
      }
    }

    drupal_add_js(
      array(
        'batire_search' => array(
          'popupType' => 'access-denied',
          'showPopup' => 1,
          'showPopupRedirect' => url($_REQUEST['q'], array('query' => implode('&', $query_str))),
        )
      ), 'setting'
    );
  }
}

/**
 * Pre register search process
 * @param $sid Search id
 * @return
 */
function _batire_search_ui_preregister_process($sid, $r_sid) {
  global $user;
  $w_sid = $sid;
  if (!empty($r_sid) && mongodb_search_find_search_id($r_sid)) {
    $w_sid = $r_sid;
  }

  $search_data = mongodb_search_get_search_data($w_sid);
  $nid = $search_data['nid'];
  if (!empty($nid) && is_numeric($nid)) {
    $node = node_load($nid);
    if (isset($node->nid) && $user->uid == $node->uid) {
      $data = array('search_depend' => $w_sid);
      return batire_search_create_search_copy($w_sid, $data);
    }
  }
  return $w_sid;
}

/**
 * Get number of page from pager for navigation
 * @param $pager Search pager
 * @param $nid Node nid from results
 *
 * @return Integer Number of page or 0
 */
/*
function _batire_search_ui_document_pager_get_doc_pager_page($pager, $nid) {
  if (!empty($pager) && !empty($pager->pager_list)) {
    foreach ($pager->pager_list as $key => $item) {
      if (in_array($nid, $item)) {
        return $key;
      }
    }
  }
  return 0;
}*/
<?php

/**
 * @file
 *  search_results_filters.inc
 * Create block of search results filters
 */

/**
 * Implementation of hook_contant_type_ctools_content_types().
 */
function batire_search_ui_search_results_filters_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Batire search results filters'),
    'description' => t('Block of search results filters'),
    'icon' => '',
    'category' => t('Batire'),
    'defaults' => array(),
  );
}

/**
 * Implementation of hook_content_type_content_type_render().
 */
function batire_search_ui_search_results_filters_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = '';
  $args = arg();
  $count = batire_search_get_count_results($args[2]);
  if ($count) {
    if (!empty($args[3]) && mongodb_search_find_search_id($args[3])) {
      $sid = $args[3];
    }
    else {
      $sid = $args[2];
    }
    $refine_criteries = batire_search_load_refine_criteries_as_text($sid);
    $search = mongodb_select_one(MONGODB_SEARCH_COLLECTION, array('sid' => $sid));
    //$session = _batire_site_get_var(BATIRE_SEARCH_SESSION_VIEWS_NAMESPACE, $args[2], NULL);
    $results['filters'] = (object) $search['pager'];
    $results['refine'] = $refine_criteries;
    $block->content = theme('batire_search_ui_search_results_filters_content', $results);
  }
  return $block;
}
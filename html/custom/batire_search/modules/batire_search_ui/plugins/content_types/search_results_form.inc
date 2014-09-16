<?php

/**
 * @file
 *  search_results_form.inc
 * Create block of search results form
 */

/**
 * Implementation of hook_contant_type_ctools_content_types().
 */
function batire_search_ui_search_results_form_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Batire search results form'),
    'description' => t('Block of search results form'),
    'icon' => '',
    'category' => t('Batire'),
    'defaults' => array(),
  );
}

/**
 * Implementation of hook_content_type_content_type_render().
 */
function batire_search_ui_search_results_form_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = '';
  $search_id = arg(2);
  // save search id to session for each new search and clean cookies for old search
  /*
  $ses_search_id = _batire_site_get_var(BATIRE_SEARCH_UI_SESSION_NAMESPACE, 'search_id', $search_id);
  if ($ses_search_id != $search_id) {
    _batire_site_set_var(BATIRE_SEARCH_UI_SESSION_NAMESPACE, 'search_id', $search_id);
    _batire_search_ui_clean_search_cookies();
  }
  else {
    _batire_site_set_var(BATIRE_SEARCH_UI_SESSION_NAMESPACE, 'search_id', $search_id);
  }
  */
  if (batire_search_get_count_results($search_id)) {
    $block->content = drupal_get_form('batire_search_ui_search_results_form', $search_id);
  }
  return $block;
}
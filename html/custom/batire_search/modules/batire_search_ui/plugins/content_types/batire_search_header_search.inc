<?php

/**
 * @file
 *  batire_search_header_search.inc
 * Create block "search simple form" for site
 */

/**
 * Implementation of hook_contant_type_ctools_content_types().
 */
function batire_search_ui_batire_search_header_search_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Batire header search block'),
    'description' => t('Block with header search form'),
    'icon' => '',
    'category' => t('Batire'),
    'defaults' => array(),
  );
}

/**
 * Implementation of hook_content_type_content_type_render().
 */
function batire_search_ui_batire_search_header_search_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->content = theme('batire_search_ui_header_search_block_content', array('content' => drupal_get_form('batire_search_ui_header_search_form')));
  return $block;
}
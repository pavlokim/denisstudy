<?php

/**
 * @file
 *  batire_usersession_info.inc
 * Batire user sessions content type.
 */

/**
 * Callback function to supply a list of content types.
 */
function batire_usersession_batire_usersession_info_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Batire ma session box'),
    'description' => t('Info box with session info'),
    'icon' => '',
    'category' => t('Batire'),
    'defaults' => array(),
  );
}

/**
 * Output function for the 'batire_usersession_info' content type.
 */
function batire_usersession_batire_usersession_info_content_type_render($subtype, $conf, $panel_args, $context) {
  // Make a new empty "block" which will be a Pane you can add to your Panel.
  $block = new stdClass();
  $docs_cnt = 0;
  $searches_cnt = 0;
  $total_cnt = 0;

  $recents = batire_usersession_get_recents();

  if ($recents) {
    if (is_array($recents)) {
      $recent_keys = array_keys($recents);
      $docs_keys = array_flip(array_filter($recent_keys, "batire_usersession_get_docs"));
      $docs_cnt = count(array_intersect_key($recents, $docs_keys));
      $search_keys = array_flip(array_filter($recent_keys, "batire_usersession_get_searches"));
      $searches_cnt = count(array_intersect_key($recents, $search_keys));
      $total_cnt = $docs_cnt + $searches_cnt;
    }

    if ($total_cnt > 0) {
      drupal_add_js(
      array(
        'batire_usersession' => array(
          "info_load_url" => url('js/batire_usersession/getinfo')
        )
      ), 'setting'
      );
      drupal_add_js(drupal_get_path('module', 'batire_usersession') . '/scripts/batire_usersessions.getinfo.js');
      $block->content = theme('batire_usersession_info_content', $docs_cnt, $searches_cnt);
    }
  }
  return $block;
}
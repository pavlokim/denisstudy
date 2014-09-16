<?php

/**
 * @file
 * Provide views data for batire_user_docs.module.
 */

/**
 * Implementation of hook_views_api().
 */
function batire_user_docs_views_api() {
  return array(
    'api' => '3.0',
    'path' => drupal_get_path('module', 'batire_user_docs') . '/includes/views',
  );
}

/**
 * Implementation of hook_views_data().
 */
function batire_user_docs_views_data() {
  $data = array();
  $data['batire_user_docs']['table']['group'] = t('Batire User Docs');

  $data['batire_user_docs']['table']['join'] = array(
    '#global' => array()
  );

  $data['batire_user_docs']['date_added'] = array(
    'title' => t('Date d\'enregistrement'),
    'help' => t('Sorts results based on "date d\'enregistrement"'),
    'real field' => 'field_folder_documents_added',
    'sort' => array(
      'handler' => 'batire_user_docs_handler_sort_date_add'
    ),
    'field' => 'field_folder_documents_added',
  );

  $data['batire_user_docs']['date_empty'] = array(
    'title' => t('Date vide'),
    'help' => t('Sorts results based on "date vide"'),
    'sort' => array(
      'handler' => 'batire_user_docs_handler_sort_date_empty'
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function batire_user_docs_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'batire_user_docs') . '/includes/views'
    ),
    'handlers' => array(
      'batire_user_docs_handler_sort_date_add' => array(
        'parent' => 'views_handler_sort',
      ),
      'batire_user_docs_handler_sort_date_empty' => array(
        'parent' => 'views_handler_sort',
      )
    )
  );
}
<?php
/**
 * @file
 * Provide views data for batire_user_searches.module.
 */
/**
 * Implementation of hook_views_api().
 */
function batire_user_searches_views_api() {
  return array(
    'api' => '3.0',
    'path' => drupal_get_path('module', 'batire_user_searches') . '/includes/views',
  );
}

/**
 * Implementation of hook_views_data().
 */
function batire_user_searches_views_data() {
  $data = array();
  $data['batire_user_searches']['table']['group'] = t('Batire User Searches');
  $data['batire_user_searches']['table']['join'] = array(
    '#global' => array()
  );
  $data['batire_user_searches']['new'] = array(
    'title' => t('Number of new items since last search'),
    'help' => t('Sorts results based on number of new items since last search'),
    'real field' => 'field_search_new_value',
    'sort' => array(
      'handler' => 'batire_user_searches_handler_sort_new_alert'
    ),
    'field' => 'field_search_new_value',
  );

  return $data;
}
/**
 * Implementation of hook_views_handlers().
 */
function batire_user_searches_views_handlers() {
  return array(
    'info' => array(
      'path'  => drupal_get_path('module', 'batire_user_searches') .'/includes/views'
    ),
    'handlers' => array(
      'batire_user_searches_handler_sort_new_alert' => array(
        'parent' => 'views_handler_sort',
      ),
    )
  );
}
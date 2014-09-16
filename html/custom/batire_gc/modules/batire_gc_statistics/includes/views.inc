<?php

/**
 * @file
 * Provide views data for batire_gc_statistics.module.
 */

/**
 * Implementation of hook_views_api().
 */
function batire_gc_statistics_views_api() {
  return array(
    'api' => '3.0',
    'path' => drupal_get_path('module', 'batire_gc_statistics') . '/includes/views',
  );
}

/**
 * Implementation of hook_views_data().
 */
function batire_gc_statistics_views_data() {
  $data = array();
  $data['batire_gc_statistics']['table']['group'] = t('Batire GC Statistics');

  $data['batire_gc_statistics']['table']['join'] = array(
    '#global' => array()
  );

  $data['batire_gc_statistics']['password'] = array(
    'title' => t('Access to statistics'),
    'help' => t('Shows current users permission to statistics application.'),
    'field' => array(
      'handler' => 'batire_gc_statistics_handler_field_access_statistics',
      'click sortable' => FALSE,
      'notafield' => TRUE,
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function batire_gc_statistics_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'batire_gc_statistics') . '/includes/views'
    ),
    'handlers' => array(
      'batire_gc_statistics_handler_field_access_statistics' => array(
        'parent' => 'views_handler_field',
      ),
    )
  );
}

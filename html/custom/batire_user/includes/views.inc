<?php

/**
 * @file
 * Provide views data for batire_user.module.
 */

/**
 * Implementation of hook_views_api().
 */
function batire_user_views_api() {
  return array(
    'api' => '3.0',
    'path' => drupal_get_path('module', 'batire_user') . '/includes/views',
  );
}

/**
 * Implementation of hook_views_data().
 */
function batire_user_views_data() {
  $data = array();
  $data['batire_user']['table']['group'] = t('Batire User');

  $data['batire_user']['table']['join'] = array(
    '#global' => array()
  );

  $data['batire_user']['password'] = array(
    'title' => t('User password'),
    'help' => t('Displays user SVC password.'),
    'field' => array(
      'handler' => 'batire_user_handler_field_password',
      'click sortable' => FALSE,
      'notafield' => TRUE,
    ),
  );
  $data['batire_user']['abo_admin'] = array(
    'title' => t('Abo admin'),
    'help' => t('Displays abo admin for secondary user.'),
    'field' => array(
      'handler' => 'batire_user_handler_field_abo_admin',
      'click sortable' => FALSE,
      'notafield' => TRUE,
    ),
  );
  $data['batire_user']['products'] = array(
    'title' => t('User products'),
    'help' => t('Displays user products within Modular Offer.'),
    'field' => array(
      'handler' => 'batire_user_handler_field_products',
      'click sortable' => FALSE,
      'notafield' => TRUE,
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function batire_user_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'batire_user') . '/includes/views'
    ),
    'handlers' => array(
      'batire_user_handler_field_password' => array(
        'parent' => 'views_handler_field',
      ),
      'batire_user_handler_field_abo_admin' => array(
        'parent' => 'views_handler_field',
      ),
      'batire_user_handler_field_products' => array(
        'parent' => 'views_handler_field',
      ),
    )
  );
}

<?php

/**
 * @file
 * Views integration
 */

/**
 * Implementation of hook_views_api().
 */
function batire_webmaster_views_api() {
  return array(
    'api'   => 3,
    'path'  => drupal_get_path('module', 'batire_webmaster') .'/includes/views'
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function batire_webmaster_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'batire_webmaster') .'/includes/views/handlers',
    ),
    'handlers' => array(
      'batire_webmaster_handler_field_modify_free' => array(
        'parent' => 'views_handler_field_custom',
      ),
      'batire_webmaster_handler_field_grand_user' => array(
        'parent' => 'views_handler_field_custom',
      ),
    )
  );
}

/**
 * Implementation of hook_views_data_alter().
 */
function batire_webmaster_views_data() {
  $data = array();

  $data['users']['modify_free'] = array(
    'title' => t('Modify free user term'),
    'help' => t('Provide modify free user term link.'),
    'field' => array(
      'handler' => 'batire_webmaster_handler_field_modify_free',
    ),
  );

  $data['users']['grand_user'] = array(
    'title' => t('Multiadmin info'),
    'help' => t('Provide multi-admin info.'),
    'field' => array(
      'handler' => 'batire_webmaster_handler_field_grand_user',
    ),
  );

  $data['users']['abo_num'] = array(
    'title' => t('Abonnement'),
    'help' => t('Abonnement'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'abo_num',
    ),
    'filter' => array(
      'title' => t('Abonnement'),
      'handler' => 'views_handler_filter_equality',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['users']['svc_login'] = array(
    'title' => t('SVC Login'),
    'help' => t('SVC Login'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'svc_login',
    ),
    'filter' => array(
      'title' => t('SVC Login'),
      'handler' => 'views_handler_filter_equality',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}
<?php

/**
 * @file
 * Provide drush integration for purging database
 */

/**
 * Implementation of hook_drush_help().
 */
function batire_database_purge_drush_help($section) {
  switch ($section) {
    case 'drush:database-purge':
      return dt("Usage: drush [options] database-purge type - type users|docs|all");
  }
}

/**
 * Implementation of hook_drush_command().
 */
function batire_database_purge_drush_command() {
  $items['database-purge'] = array(
    'description' => 'Database purge.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    'arguments' => array(
      'type' => 'Database purge type.',
    ),
  );

  return $items;
}

/**
 * Drush callback; Start initial import to Antidot.
 */
function drush_batire_database_purge_database_purge($type = '') {
  if (!(isset($type) && $type)) {
    $types = array(
      'users' => 'Delete users data',
      'docs' => 'Delete documents data',
      'all' => 'Delete all data',
    );
    $type = drush_choice($types, 'Enter a number to choose database purge type.', '!value');
  }

  $submit = drush_confirm('Are you sure?');

  if ($type !== FALSE && $submit !== FALSE) {

    variable_set('batire_database_purge_time_start', time());
    switch ($type) {
      case 'users' :
        $batch = array(
          'operations' => array(),
          'finished' => 'batire_database_purge_purge_batch_finished',
          'title' => t('Purging all user related data')
        );

        batire_database_purge_users($batch);
        break;
      case 'docs' :
        $batch = array(
          'operations' => array(),
          'finished' => 'batire_database_purge_purge_batch_finished',
          'title' => t('Purging all documents related data')
        );

        batire_database_purge_docs($batch);
        break;
      case 'all' :
        $batch = array(
          'operations' => array(),
          'finished' => 'batire_database_purge_purge_batch_finished',
          'title' => t('Purging all data')
        );

        batire_database_purge_users($batch);
        batire_database_purge_docs($batch);
        break;
    }
    batch_set($batch);
    drush_backend_batch_process();
  }
}
<?php

/**
 * @file
 * Handle the 'mon compte' override task.
 *
 * This plugin overrides mon-compte/% and reroutes it to the page manager, where
 * a list of tasks can be used to service this request based upon criteria
 * supplied by access plugins.
 */

/**
 * Implementation of hook_page_manager_task_tasks().
 */
function batire_site_batire_site_mon_compte_page_manager_tasks() {
  return array(
    // This is a 'page' task and will fall under the page admin UI
    'task type' => 'page',
    'title' => t('Mon compte template'),
    'admin title' => t('Mon compte template'),
    'admin description' => t('When enabled, this overrides the default Drupal behavior for displaying content at <em>mon-compte/%</em>. If you add variants, you may use selection criteria such as node type or language or user access to provide different content. If no variant is selected, the default Drupal content view will be used.'),
    'admin path' => 'mon-compte/%',
    // Menu hooks so that we can alter the mon-compte/% menu entry to point to us.
    'hook menu' => 'batire_site_batire_site_mon_compte_menu',
//    'hook menu alter' => 'batire_site_batire_site_mon_compte_menu_alter',
    // This is task uses 'context' handlers and must implement these to give the
    // handler data it needs.
    'handler type' => 'context',
    'get arguments' => 'batire_site_batire_site_mon_compte_get_arguments',
    'get context placeholders' => 'batire_site_batire_site_mon_compte_get_contexts',
    // Allow this to be enabled or disabled:
    'disabled' => variable_get('batire_site_batire_site_mon_compte_disabled', TRUE),
    'enable callback' => 'batire_site_batire_site_mon_compte_enable',
  );
}

/**
 * Callback defined by batire_site_batire_site_mon_compte_page_manager_tasks().
 */
function batire_site_batire_site_mon_compte_menu(&$items, $task) {
  if (variable_get('batire_site_batire_site_mon_compte_disabled', TRUE)) {
    return;
  }
  $items['mon-compte'] = array(
    'title' => 'Mes documents',
    'page arguments' => array('mon-compte/mes-documents'),
    'page callback' => 'drupal_goto',
    'access arguments' => array('access user docs'),
    'type' => MENU_CALLBACK
  );
  $items['mon-compte/%'] = array(
    'type' => MENU_CALLBACK,
    'page callback' => 'batire_site_batire_site_mon_compte',
    'page arguments' => array(1),
    'access arguments' => array('access user docs'),
    'file path' => drupal_get_path('module', 'batire_site') . '/plugins/tasks',
    'file' => 'batire_site_mon_compte.inc'
  );
}

/**
 * Entry point for add new menu item.
 */
function batire_site_batire_site_mon_compte($url) {
  $task = page_manager_get_task('batire_site_mon_compte');
  ctools_include('context');
  ctools_include('context-task-handler');
  $output = ctools_context_handler_render($task, '', array(), array());
  if ($output !== FALSE) {
    return $output;
  }
  return '';
}

/**
 * Callback to get arguments provided by this task handler.
 */
function batire_site_batire_site_mon_compte_get_arguments($task, $subtask_id) {
  return array(
    array(
      'keyword' => 'page',
      'identifier' => t('Page being viewed'),
      'id' => 1,
      'name' => 'page',
      'settings' => array(),
    ),
  );
}

/**
 * Callback to get context placeholders provided by this handler.
 */
function batire_site_batire_site_mon_compte_get_contexts($task, $subtask_id) {
  return ctools_context_get_placeholders_from_argument(batire_site_batire_site_mon_compte_get_arguments($task, $subtask_id));
}

/**
 * Callback to enable/disable the page from the UI.
 */
function batire_site_batire_site_mon_compte_enable($cache, $status) {
  variable_set('batire_site_batire_site_mon_compte_disabled', $status);
}

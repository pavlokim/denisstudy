<?php

/**
 * @file
 *  search_results.inc
 * Handle the 'search results' override task.
 *
 * This plugin overrides recherche-avancee/resultats/% and reroutes it to the page manager, where
 * a list of tasks can be used to service this request based upon criteria
 * supplied by access plugins.
 */

/**
 * Implementation of hook_page_manager_task_tasks().
 */
function batire_search_ui_search_results_page_manager_tasks() {
  return array(
    // This is a 'page' task and will fall under the page admin UI
    'task type' => 'page',
    'title' => t('Search results template'),
    'admin title' => t('Search results template'),
    'admin description' => t('When enabled, this overrides the default Drupal behavior for displaying content at <em>recherche-avancee/resultats/%</em>.'),
    'admin path' => 'recherche-avancee/resultats/%',
    // Menu hooks so that we can alter the mon-compte/% menu entry to point to us.
    'hook menu' => 'batire_search_ui_search_results_menu',
    // This is task uses 'context' handlers and must implement these to give the
    // handler data it needs.
    'handler type' => 'context',
    'get arguments' => 'batire_search_ui_search_results_get_arguments',
    'get context placeholders' => 'batire_search_ui_search_results_get_contexts',
    // Allow this to be enabled or disabled:
    'disabled' => variable_get('batire_search_ui_search_results_disabled', TRUE),
    'enable callback' => 'batire_search_ui_search_results_enable',
  );
}

/**
 * Callback defined by batire_site_batire_site_mon_compte_page_manager_tasks().
 */
function batire_search_ui_search_results_menu(&$items, $task) {
  if (variable_get('batire_search_ui_search_results_disabled', TRUE)) {
    return;
  }
  $items['recherche-avancee/resultats'] = array(
    'title' => 'Résultats de recherche',
    'type' => MENU_CALLBACK,
    'page callback' => 'batire_search_ui_search',
    'access arguments' => array('access content'),
    'file path' => drupal_get_path('module', 'batire_search_ui') . '/plugins/tasks',
    'file' => 'search_results.inc'
  );
  $items['recherche-avancee/resultats/%'] = array(
    'title' => 'Résultats de recherche',
    'type' => MENU_CALLBACK,
    'page callback' => 'batire_search_ui_search_results',
    'page arguments' => array(2),
    'access arguments' => array('access content'),
    'file path' => drupal_get_path('module', 'batire_search_ui') . '/plugins/tasks',
    'file' => 'search_results.inc'
  );
}

/**
 * Redirect to advanced search form
 */
function batire_search_ui_search() {
  $sid = batire_search_generate_id();
  drupal_goto('recherche-avancee/' . $sid);
}

/**
 * Entry point for add new menu item.
 */
function batire_search_ui_search_results($sid) {
  $r_sid = arg(3);
  batire_search_filter_sid($sid);
  batire_search_filter_sid($r_sid);
  if (!mongodb_search_find_search_id($sid) || !batire_search_search_is_active($sid)) {
    return drupal_not_found();
  }
  else {
    /*$ses_sid = _batire_site_get_var(BATIRE_SEARCH_UI_SESSION_NAMESPACE, 'search_id', FALSE);
    if ($ses_sid) {
      $search_data = mongodb_search_get_search_data($sid);
      if ($search_data['uid'] == 0) {
        batire_search_save_search_criteria($sid, $search_data['data'], NULL, 'update');
        _batire_site_set_var(BATIRE_SEARCH_UI_SESSION_NAMESPACE, 'search_id');
        _batire_site_set_var(BATIRE_SEARCH_UI_SESSION_NAMESPACE, 'search_id', $sid);
      }
      if ($ses_sid != $sid) {
        _batire_search_ui_clean_search_cookies();
      }
    }*/
  }
  _batire_search_ui_search_process($sid, $r_sid); // run search process

  $task = page_manager_get_task('search_results');
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
function batire_search_ui_search_results_get_arguments($task, $subtask_id) {
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
function batire_search_ui_search_results_disabled($task, $subtask_id) {
  return ctools_context_get_placeholders_from_argument(batire_search_ui_search_results_get_arguments($task, $subtask_id));
}

/**
 * Callback to enable/disable the page from the UI.
 */
function batire_search_ui_search_results_enable($cache, $status) {
  variable_set('batire_search_ui_search_results_disabled', $status);
}
<?php

/**
 * @file
 *  norme_afnor.inc
 * Handle the 'search results' override task.
 *
 * This plugin overrides recherche-avancee/resultats/% and reroutes it to the page manager, where
 * a list of tasks can be used to service this request based upon criteria
 * supplied by access plugins.
 */

/**
 * Implementation of hook_page_manager_task_tasks().
 */
function batire_user_docs_pdf_norme_afnor_page_manager_tasks() {
  return array(
    // This is a 'page' task and will fall under the page admin UI
    'task type' => 'page',

    'title' => t('Norme afnor page'),
    'admin title' => t('Norme afnor page'),
    'admin description' => t('When enabled, this overrides the default Drupal behavior for viewing node pages'),
    'admin path' => 'node/%node/norme-afnor',

    // Menu hooks so that we can alter the node/%node menu entry to point to us.
    'hook menu' => 'batire_user_docs_pdf_norme_afnor_menu',

    // This is task uses 'context' handlers and must implement these to give the
    // handler data it needs.
    'handler type' => 'context',
    'get arguments' => 'batire_user_docs_pdf_norme_afnor_get_arguments',
    'get context placeholders' => 'batire_user_docs_pdf_norme_afnor_contexts',

    // Allow this to be enabled or disabled:
    'disabled' => variable_get('batire_user_docs_pdf_norme_afnor_disabled', TRUE),
    'enable callback' => 'batire_user_docs_pdf_norme_afnor_enable',
  );
}

/**
 * Callback defined by batire_site_batire_site_mon_compte_page_manager_tasks().
 */
function batire_user_docs_pdf_norme_afnor_menu(&$items, $task) {
  if (variable_get('batire_user_docs_pdf_norme_afnor_disabled', TRUE)) {
    return;
  }
  $items['node/%node/norme-afnor'] = array(
    'title callback' => 'node_page_title',
    'title arguments' => array(1),
    'page callback' => 'batire_user_docs_pdf_norme_afnor_viewer',
    'page arguments' => array(1),
    'access arguments' => array('access content'),
    'type' => MENU_CALLBACK,
    'file path' => drupal_get_path('module', 'batire_user_docs_pdf') . '/plugins/tasks',
    'file' => 'norme_afnor.inc'
  );
}

/**
 * Entry point for add new menu item.
 */
function batire_user_docs_pdf_norme_afnor_viewer($node) {
  if (isset($node->nid) && $node->type == BATIRE_SITE_CT_TN && (batire_site_get_TN_content_type($node) == BATIRE_SITE_TN_TYPE_NORMAL) && (bool)batire_user_docs_get_document_attached_pdf($node)) {
//    $node->build_mode = 'pdf_viewer';
    $node->pdf_content = batire_user_docs_add_pdf_flash_viewer($node);
    // Load my task plugin
    $task = page_manager_get_task('norme_afnor');
    // Load the node into a context.
    ctools_include('context');
    ctools_include('context-task-handler');
    $contexts = ctools_context_handler_get_task_contexts($task, '', array($node));

    $output = ctools_context_handler_render($task, '', $contexts, array($node->nid));
    if ($output !== FALSE) {
      node_tag_new($node->nid);
      return $output;
    }
    $function = 'node_page_view';
    foreach (module_implements('page_manager_override') as $module) {
      $call = $module . '_page_manager_override';
      if (($rc = $call('node_view')) && function_exists($rc)) {
        $function = $rc;
        break;
      }
    }
    // Otherwise, fall back.
    return $function($node);
  }
  else {
    drupal_goto(BATIRE_SITE_NOT_FOUND_URL);
  }
}

/**
 * Callback to get arguments provided by this task handler.
 */
function batire_user_docs_pdf_norme_afnor_get_arguments($task, $subtask_id) {
  return array(
    array(
      'keyword' => 'node',
      'identifier' => t('Node being viewed'),
      'id' => 1,
      'name' => 'nid',
      'settings' => array(),
    ),
  );
}

/**
 * Callback to get context placeholders provided by this handler.
 */
function batire_user_docs_pdf_norme_afnor_contexts($task, $subtask_id) {
  return ctools_context_get_placeholders_from_argument(batire_user_docs_pdf_norme_afnor_get_arguments($task, $subtask_id));
}

/**
 * Callback to enable/disable the page from the UI.
 */
function batire_user_docs_pdf_norme_afnor_enable($cache, $status) {
  variable_set('batire_user_docs_pdf_norme_afnor_disabled', $status);
}
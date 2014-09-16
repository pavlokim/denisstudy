<?php

/*
 * Entry point for add new menu item.
 */
function batire_pdf_norme_afnor_viewer($node) {
  if (isset($node->nid) && $node->type == BATIRE_SITE_CT_TN && (batire_site_get_TN_content_type($node) == BATIRE_SITE_TN_TYPE_NORMAL) && (bool)batire_user_docs_get_document_attached_pdf($node)) {
    if($pdf_content = batire_pdf_flash_viewer($node)) {
      $node->pdf_content = $pdf_content;
    }
    else {
      $node->pdf_content = batire_user_docs_add_pdf_flash_viewer($node);
    }
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

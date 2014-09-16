<?php

/**
 * @file
 * Built in plugins for Views output handling.
 *
 */

/**
 * Implementation of hook_views_plugins().
 */
function batire_site_views_plugins() {
  $plugins = array(
    'module' => 'batire_site', // This just tells our themes are elsewhere.
    'cache' => array(
      'time_get' => array(
        'parent' => 'time',
        'title' => t('Time-based with GET values'),
        'help' => t('Simple time-based caching of data with GET values.'),
        'handler' => 'batire_site_plugin_cache_time_get',
        'uses options' => TRUE,
        'path' => drupal_get_path('module', 'batire_site') . '/includes/views/plugins', // not necessary for most modules
      ),
    ),
    'pager' => array(
      'full_limit' => array(
        'parent' => 'full',
        'title' => t('Paged output, full pager with limit'),
        'help' => t('Paged output, full Drupal style with limit'),
        'handler' => 'batire_site_plugin_pager_full_limit',
        'uses options' => TRUE,
        'path' => drupal_get_path('module', 'batire_site') . '/includes/views/plugins', // not necessary for most modules
      ),
    ),
  );

  return $plugins;
}

/**
 * Implementation of hook_views_pre_execute().
 */
function batire_site_views_pre_execute(&$view) {
  $query = $view->query;
  // check if value from $_GET['page'] more then real count pages with results.
  if ($query->final_query && !empty($_GET['page'])) {
    $replacements = $query->view->substitutions();
    $batire_final_query = str_replace(array_keys($replacements), $replacements, $query->final_query);
    $count_query = 'SELECT COUNT(*) FROM (' . str_replace(array_keys($replacements), $replacements, $batire_final_query) . ') count_alias';
    $args = $query->query_args;
    if (is_array($args)) {
      foreach ($args as $id => $arg) {
        $args[$id] = str_replace(array_keys($replacements), $replacements, $arg);
      }
    }
    if ($query->pager->use_count_query() || !empty($query->get_total_rows)) {
      $total = $query->pager->execute_count_query($count_query, $args);
      $items_per_page = $view->query->pager->options['items_per_page'];
      $count_pages = floor($total / $items_per_page);
      if ($count_pages > 0 && $count_pages*$items_per_page == $total) {
        $count_pages--;
      }
      if ($_GET['page'] > $count_pages) {
        $view->current_page = $count_pages;
        $view->query->offset = $view->current_page * $items_per_page;
      }
    }
  }
}
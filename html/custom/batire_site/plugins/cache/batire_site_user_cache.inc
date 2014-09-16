<?php
/**
 * @file
 * Provides a simple time-based caching with user id option for panel panes.
 */

// Plugin definition
$plugin = array(
  'title' => t("Batire site per user cache"),
  'description' => t('Simple time-based cache with user id. This is a hard limit, and once cached it will remain that way until the time limit expires.'),
  'cache get' => 'batire_site_user_cache_get_cache',
  'cache set' => 'batire_site_user_cache_set_cache',
  'cache clear' => 'batire_site_user_cache_clear_cache',
  'settings form' => 'batire_site_user_cache_settings_form',
  'settings form submit' => 'batire_site_user_cache_settings_form_submit',
  'defaults' => array(
    'lifetime' => 21600,
  ),
);

/**
 * Get cached content.
 */
function batire_site_user_cache_get_cache($conf, $display, $args, $contexts, $pane = NULL) {
  $cid = batire_site_user_cache_get_id($conf, $display, $args, $contexts, $pane);
  $cache = cache_get($cid, 'cache');
  if (!$cache) {
    return FALSE;
  }

  if ((time() - $cache->created) > $conf['lifetime']) {
    return FALSE;
  }

  return $cache->data;
}

/**
 * Set cached content.
 */
function batire_site_user_cache_set_cache($conf, $content, $display, $args, $contexts, $pane = NULL) {
  $cid = batire_site_user_cache_get_id($conf, $display, $args, $contexts, $pane);
  cache_set($cid, $content);
}

/**
 * Clear cached content.
 *
 * Cache clears are always for an entire display, regardless of arguments.
 */
function batire_site_user_cache_clear_cache($display) {
  $cid = 'batire_site_user_cache';

  // This is used in case this is an in-code display, which means did will be something like 'new-1'.
  if (isset($display->owner) && isset($display->owner->id)) {
    $cid .= ':' . $display->owner->id;
  }
  $cid .= ':' . $display->did;

  cache_clear_all($cid, 'cache', TRUE);
}

/**
 * Figure out an id for our cache based upon input and settings.
 */
function batire_site_user_cache_get_id($conf, $display, $args, $contexts, $pane) {
  global $user;
  $id = 'batire_site_user_cache';

  // This is used in case this is an in-code display, which means did will be something like 'new-1'.
  if (isset($display->owner) && isset($display->owner->id)) {
    $id .= ':' . $display->owner->id;
  }
  $id .= ':' . $display->did;

  if ($pane) {
    $id .= ':' . $pane->pid;
  }

  if (user_access('view pane admin links')) {
    $id .= ':admin';
  }

  if (module_exists('locale')) {
    global $language;
    $id .= ':' . $language->language;
  }

  if ($user->uid) {
    $id .= ':' . $user->uid;
  }

  return $id;
}

function batire_site_user_cache_settings_form($conf, $display, $pid) {
  $options = drupal_map_assoc(array(3600, 7200, 14400, 21600, 28800, 43200, 86400, 172800, 259200, 345600, 604800), 'format_interval');
  $form['lifetime'] = array(
    '#title' => t('Lifetime'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => $conf['lifetime'],
  );

  return $form;
}


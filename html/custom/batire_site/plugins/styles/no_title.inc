<?php
/**
 * @file
 * Definition of the 'no_title' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('No Title'),
  'description' => t('Display the pane as a system block without title.'),
  'render pane' => 'batire_site_no_title_pane',
  'weight' => -10,
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_batire_site_no_title_pane($content, $pane, $display) {
  return $content->content;
}
<?php
/**
 * @file
 * Plugin to handle the 'batire_site_breadcrumb' content type which allows the
 * breadcrumb trail of the current page to be embedded into a panel.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Batire Breadcrumb'),
  'single' => TRUE,
  'description' => t('Add the breadcrumb trail as content.'),
  'icon' => '',
  'category'    => t('Batire'),
  'render last' => TRUE,
);

/**
 * Output function for the 'page_breadcrumb' content type.
 *
 * Outputs the breadcrumb for the current page.
 */


function batire_site_batire_site_breadcrumb_content_type_render($subtype, $conf, $panel_args) {
  $block = new stdClass();

  $block->content = theme('breadcrumb', batire_site_build_breadcrumb());

  return $block;
}

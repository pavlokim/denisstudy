<?php
/**
 * @file
 * Site top block functionality
 */

/**
 * Callback function to supply a list of content types.
 */
function batire_site_batire_site_top_info_ctools_content_types() {
  return array(
    'single'      => TRUE,
    'title'       => t('Batire info header'),
    'description' => t('Info header of main page'),
    'icon'        => '',
    'category'    => t('Batire'),
    'defaults'    => array(),
  );
}

/**
 * Output function for the 'batire_site_top_info' content type.
 */
function batire_site_batire_site_top_info_content_type_render($subtype, $conf, $panel_args, $context) {
  // Make a new empty "block" which will be a Pane you can add to your Panel.
  $block = new stdClass();

  $site_slogan = variable_get('site_slogan', NULL);
  $menu = menu_tree('menu-batire-site-top');

  $block->content = theme('batire_site_top', $site_slogan, $menu);

  return $block;
}
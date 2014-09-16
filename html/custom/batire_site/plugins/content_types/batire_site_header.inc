<?php
/**
 * @file
 * Site header functionality
 */

/**
 * Callback function to supply a list of content types.
 */
function batire_site_batire_site_header_ctools_content_types() {
  return array(
    'single'      => TRUE,
    'title'       => t('Batire header'),
    'description' => t('Header of main page'),
    'icon'        => '',
    'category'    => t('Batire'),
    'defaults'    => array(),
  );
}

/**
 * Output function for the 'batire_site_header' content type.
 */
function batire_site_batire_site_header_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  // Make a new empty "block" which will be a Pane you can add to your Panel.
  $block = new stdClass();

  $site_logo = theme_get_setting('logo');

  if ($user->uid > 0) {
    $user_profile = mongodb_user_get_user($user->uid);
    $auth_block = theme('batire_site_user_header', $user_profile);
  } else {
    $auth_block = theme('batire_site_header_login_form', drupal_get_form('user_login_block'));
  }

  $block->content = theme('batire_site_header', $site_logo, $auth_block);

  return $block;
}

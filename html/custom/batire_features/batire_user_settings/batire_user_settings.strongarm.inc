<?php

/**
 * Implementation of hook_strongarm().
 */
function batire_user_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_batire_user_profile';
  $strongarm->value = array(
    'weight' => '0',
    'user_display' => 'full',
    'edit_link' => 0,
    'edit_tab' => 'sub',
    'add_link' => 1,
    'registration_use' => 0,
    'admin_user_create_use' => 0,
    'registration_hide' => array(
      0 => 'title',
      1 => 'field_user_subacc',
      2 => 'field_user_last_login_date',
      3 => 'field_user_login_date',
      4 => 'field_default_search',
    ),
  );
  $export['content_profile_batire_user_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_batire_user_profile';
  $strongarm->value = 1;
  $export['content_profile_use_batire_user_profile'] = $strongarm;

  return $export;
}

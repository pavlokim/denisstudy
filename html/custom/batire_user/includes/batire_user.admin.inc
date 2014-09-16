<?php

/**
 * @file
 * Administration related functionality for the module
 */

function batire_user_manage_system_users() {
  $form = array();

  $form['batire_user_system_user_logins'] = array(
    '#type'           => 'textarea',
    '#title'          => t('List of system user logins'),
    '#description'    => t('Enter list of logins, one per line. These users would not be authentified via SVC'),
    '#default_value'  => variable_get('batire_user_system_user_logins', "admin\nwebmaster\nbatire2011\nafnor77")
  );

  return system_settings_form($form);
}

function batire_user_admin_settings() {
  $form = array();

  $form['batire_user_free_trial_days'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Free trial period, days'),
    '#description' => t('Free trial period, days'),
    '#default_value' => variable_get('batire_user_free_trial_days', 15)
  );

  $form['batire_user_date_to_expiration'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Warning before expiration, days'),
    '#description' => t('Time before account expiration to show warning, days'),
    '#default_value' => variable_get('batire_user_date_to_expiration', 2)
  );

  $form['batire_user_commercials_email'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('E-mail of commercials'),
    '#default_value' => variable_get('batire_user_commercials_email', 'mjcpgm@gmail.com')
  );

  $form['batire_user_email_cc'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail (CC)'),
    '#default_value' => variable_get('batire_user_email_cc', '')
  );

  return system_settings_form($form);
}

function batire_user_admin_notification_settings() {
  $form = array();

  $form['batire_user_notifications_delay_1'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('First notification delay'),
    '#default_value' => variable_get('batire_user_notifications_delay_1', 2)
  );

  $form['batire_user_notifications_delay_2'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Second notification delay'),
    '#default_value' => variable_get('batire_user_notifications_delay_2', 4)
  );

  $form['batire_user_notifications_delay_3'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Third notification delay'),
    '#default_value' => variable_get('batire_user_notifications_delay_3', 10)
  );

  $form['batire_user_notifications_delay_4'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Fourth notification delay'),
    '#default_value' => variable_get('batire_user_notifications_delay_4', 25)
  );

  return system_settings_form($form);
}

<?php

/**
 * Admin settings form.
 */
function batire_gc_trial_tn_admin_settings_form() {
  $form = array();

  $form['batire_gc_trial_tn_httpauth_login'] = array(
    '#type' => 'textfield',
    '#title' => t('Trial TN basic-auth login'),
    '#default_value' => variable_get('batire_gc_trial_tn_httpauth_login', 'user'),
  );
  $form['batire_gc_trial_tn_httpauth_pass'] = array(
    '#type' => 'textfield',
    '#title' => t('Trial TN basic-auth password'),
    '#default_value' => variable_get('batire_gc_trial_tn_httpauth_pass', 'pass'),
  );
  $form['batire_gc_trial_tn_httpauth_disable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable basic-auth'),
    '#default_value' => variable_get('batire_gc_trial_tn_httpauth_disable', 0),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return system_settings_form($form);
}

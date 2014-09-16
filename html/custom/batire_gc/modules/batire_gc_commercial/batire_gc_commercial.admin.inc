<?php

/**
 * Admin settings form.
 */
function batire_gc_commercial_admin_settings_form() {
  $form = array();

  $form['batire_gc_commercial_error_message'] = array(
    '#type' => 'textarea',
    '#title' => t('No slots error message'),
    '#default_value' => BATIRE_GC_NO_SLOTS_ERROR_MESSAGE,
  );
  $form['batire_gc_commercial_allowed_urls'] = array(
    '#type' => 'textarea',
    '#title' => t('Pages allowed to GC Sales'),
    '#default_value' => BATIRE_GC_COMMERCIAL_ALLOWED_URLS,
    '#description' => t('List of URLs (each url on new line) which will be allowed to access by GC sales. Other URLs will redirect GC sales to his dashboard.'),
  );
  $form['demo_tdm'] = array(
    '#type' => 'fieldset',
    '#title' => t('Demo TdM settings'),
  );
  $form['demo_tdm']['batire_gc_commercial_demo_tdm_login'] = array(
    '#type' => 'textfield',
    '#title' => t('Demo TdM access login'),
    '#default_value' => BATIRE_GC_COMMERCIAL_DEMO_TDM_LOGIN,
  );
  $form['demo_tdm']['batire_gc_commercial_demo_tdm_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Demo TdM access password'),
    '#default_value' => BATIRE_GC_COMMERCIAL_DEMO_TDM_PASSWORD,
  );
  $form['demo_tdm']['batire_gc_commercial_demo_tdm_disable_auth'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable Demo TdM access check'),
    '#default_value' => BATIRE_GC_COMMERCIAL_DEMO_TDM_DISABLE_AUTH,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return system_settings_form($form);
}

/**
 * Add sales manager form implementation.
 */
function batire_gc_commercial_add_sales_form() {
  $form = array();

  $form['my_accounts'] = array(
    '#type' => 'fieldset',
  );
  $field_user_salut = content_fields('field_user_salut', 'batire_user_profile');
  $field_user_salut_values = content_allowed_values($field_user_salut);
  $form['my_accounts']['field_user_salut'] = array(
    '#type' => 'radios',
    '#title' => t('Civilité'),
    '#options' => $field_user_salut_values,
    '#required' => TRUE,
  );
  $form['my_accounts']['field_user_surname'] = array(
    '#type' => 'textfield',
    '#title' => t('Nom'),
    '#required' => TRUE,
  );
  $form['my_accounts']['field_user_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Prénom'),
    '#required' => TRUE,
  );
  $form['my_accounts']['field_user_promo'] = array(
    '#type' => 'textfield',
    '#title' => t('Code Privilège'),
    '#required' => TRUE,
  );

  $form['my_codes'] = array(
    '#type' => 'fieldset',
  );
  $form['my_codes']['login'] = array(
    '#type' => 'textfield',
    '#title' => t('Identifiant'),
    '#required' => TRUE
  );
  $form['my_codes']['password'] = array(
    '#type' => 'password',
    '#title' => t('Mot de passe'),
  );
  $form['my_codes']['confirm_password'] = array(
    '#type' => 'password',
    '#title' => t('Confirmation mot de passe'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Add sales manager form validation handler.
 */
function batire_gc_commercial_add_sales_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  if (user_load(array('name' => $values['login']))) {
    form_set_error('login', t('Username already taken'));
  }
  if ($values['password'] != $values['confirm_password']) {
    form_set_error('password', t('Passwords mismatch'));
  }
}

/**
 * Add sales manager form submit handler.
 */
function batire_gc_commercial_add_sales_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  $user = array(
    //'mail' => $email,
    'name' => $values['login'],
    'pass' => $values['password'],
    'status' => 1,
    'roles' => array(BATIRE_GC_GC_COMMERCIAL_ROLE_ID => BATIRE_GC_GC_COMMERCIAL_ROLE_ID),
  );
  $user = user_save('', $user);

  $profile = (object) array(
    'title' => "GC sales profile {$user->name}-{$user->uid}",
    'type' => BATIRE_USER_PROFILE,
    'uid' => $user->uid,
    'status' => 1,
    'name' => $user->name,
    'field_user_name' => array(array('value' => $values['field_user_name'])),
    'field_user_surname' => array(array('value' => $values['field_user_surname'])),
    'field_user_promo' => array(array('value' => $values['field_user_promo'])),
    'taxonomy' => array(BATIRE_GC_GC_COMMERCIAL_TERM_ID => BATIRE_GC_GC_COMMERCIAL_TERM_ID),
  );
  node_save($profile);

  drupal_set_message(t('GC sales added.'));
}

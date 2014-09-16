<?php

/**
 * Admin settings form implementation.
 */
function batire_newsletter_admin_settings_form() {
  $form = array();

  $form['batire_newsletter_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Secret key'),
    '#description' => t('Special secret key which will be used by remote applications to access newsletter generation.'),
    '#required' => TRUE,
    '#default_value' => variable_get('batire_newsletter_key', 'DEADBEEF'),
  );
  $form['batire_newsletter_period'] = array(
    '#type' => 'textfield',
    '#title' => t('Default export period'),
    '#description' => t('Number of days to take as export period for newsletter when argument is not passed explicitly in URL.'),
    '#required' => TRUE,
    '#default_value' => variable_get('batire_newsletter_period', 7),
  );
  $form['batire_newsletter_shorttext_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Shorted text length'),
    '#description' => t('Amount of symbols to leave for shorted text.'),
    '#required' => TRUE,
    '#default_value' => variable_get('batire_newsletter_shorttext_length', 150),
  );
  $form['batire_newsletter_sujet'] = array(
    '#type' => 'textfield',
    '#title' => t('Sujet'),
    '#required' => FALSE,
    '#default_value' => variable_get('batire_newsletter_sujet', NULL),
  );
  $form['batire_newsletter_export_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Export path'),
    '#required' => TRUE,
    '#default_value' => variable_get('batire_newsletter_export_path', 'newsletter/newsletter_subscribers.csv'),
  );

  return system_settings_form($form);
}

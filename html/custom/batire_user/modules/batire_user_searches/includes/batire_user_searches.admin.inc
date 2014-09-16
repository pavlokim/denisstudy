<?php

/**
 * @file
 *  batire_user_searches.admin.inc
 * User search settings for site
 */

/**
 * Implementation of admin form;
 */
function batire_user_searches_admin_form() {
  $user_search_settings = array(
    '#type' => 'fieldset',
    '#title' => t('Saved searches settings'),
    '#collapsible' => TRUE,
    '#weight' => -5
  );

  $user_search_settings['batire_user_searches_maximum_saved_searches'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum saved searches per user'),
    '#default_value' => variable_get('batire_user_searches_maximum_saved_searches', BATIRE_USER_SEARCHES_MAXIMUM_SAVED_SEARCHES),
    '#required' => TRUE
  );

  $user_search_settings['batire_user_searches_threshold_saved_searches'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of saved searches, when warning is shown to user'),
    '#default_value' => variable_get('batire_user_searches_threshold_saved_searches', BATIRE_USER_SEARCHES_THRESHOLD_SAVED_SEARCHES),
    '#required' => TRUE
  );

  $user_alert_settings = array(
    '#type' => 'fieldset',
    '#title' => t('Saved alerts settings'),
    '#collapsible' => TRUE,
    '#weight' => -5
  );

  $user_alert_settings['batire_user_searches_maximum_sent_alerts_records'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum saved sent alerts records per user'),
    '#default_value' => variable_get('batire_user_searches_maximum_sent_alerts_records', BATIRE_USER_SEARCHES_MAXIMUM_SENT_ALERTS_RECORDS),
    '#required' => TRUE
  );
  return array($user_search_settings, $user_alert_settings);
}
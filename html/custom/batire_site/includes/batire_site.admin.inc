<?php

/**
 * @file
 *
 * Admin settings for the module
 */

/**
 * Website settings form
 */
function batire_site_site_settings() {
  global $user;

  $form = array();

  if ($user->uid == 1) {
    /**
     * Disabling development settings for users
     */
    $settings = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#title' => t('Development settings'),
      '#weight' => 0
    );

    $settings['batire_site_development_disable_cache'] = array(
      '#type' => 'checkbox',
      '#title' => t('Disable custom cache'),
      '#default_value' => variable_get('batire_site_development_disable_cache', 0)
    );

    $settings['batire_site_clean_sessions'] = array(
      '#type' => 'checkbox',
      '#title' => t('Clear all user sessions on login'),
      '#default_value' => variable_get('batire_site_clean_sessions', 0)
    );

    $settings['batire_site_log_antidot'] = array(
      '#type' => 'checkbox',
      '#title' => t('Log Antidot queries'),
      '#default_value' => variable_get('batire_site_log_antidot', 0)
    );

    $settings['batire_site_process_alerts'] = array(
      '#type' => 'checkbox',
      '#title' => t('Process search and documents alerts'),
      '#default_value' => variable_get('batire_site_process_alerts', TRUE)
    );

    $settings['batire_site_generate_tdm'] = array(
      '#type' => 'checkbox',
      '#title' => t('Generate TdM after import'),
      '#default_value' => variable_get('batire_site_generate_tdm', TRUE)
    );

    $settings['batire_site_logging'] = array(
      '#type' => 'checkbox',
      '#title' => t('Activate logging of session and viewed documents'),
      '#default_value' => variable_get('batire_site_logging', TRUE)
    );

    $form['dev'] = $settings;
  }

  $settings = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#title' => t('Document settings'),
    '#weight' => -5
  );

  $settings['batire_site_title_breadcrumb_length'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Document title length in breadcrumb'),
    '#default_value' => variable_get('batire_site_title_breadcrumb_length', 240)
  );

  $settings['batire_site_document_teaser_length'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Document teaser length'),
    '#default_value' => variable_get('batire_site_document_teaser_length', 500)
  );
  $form['document'] = $settings;

  $settings = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#title' => t('Contact settings'),
    '#weight' => -5
  );

  $settings['batire_site_contact_telephone'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Contact telephone'),
    '#default_value' => variable_get('batire_site_contact_telephone', '')
  );

  $settings['batire_site_contact_email'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Contact e-mail'),
    '#default_value' => variable_get('batire_site_contact_email', '')
  );

  $settings['batire_site_ddr_contact_email'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Documents de référence Contact e-mail'),
    '#default_value' => variable_get('batire_site_ddr_contact_email', 'marie.lharidon@groupemoniteur.fr'),
  );

  $settings['batire_site_contact_url'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Contact link'),
    '#default_value' => variable_get('batire_site_contact_url', '')
  );

  $form['contact'] = $settings;

  /**
   * Maximum length of the folder name, search profile name, alert name
   */
  $settings = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#title' => t('Maximum length of the folder name, search profile name, alert name'),
    '#weight' => 3
  );

  $settings['batire_site_max_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum length of the folder name, search profile name, alert name'),
    '#default_value' => variable_get('batire_site_max_length', 35)
  );
  $form['length_folder_alert'] = $settings;

  /*
   * File settings
   */
  $settings = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#title' => t('File settings'),
    '#weight' => 0
  );

  $settings['batire_site_file_separator'] = array(
    '#type' => 'textfield',
    '#title' => t('Statisticts file separator'),
    '#default_value' => variable_get('batire_site_file_separator', ';')
  );

  $settings['batire_site_file_enclosure'] = array(
    '#type' => 'textfield',
    '#title' => t('Statistics file enclosure'),
    '#default_value' => variable_get('batire_site_file_enclosure', '"')
  );

  $settings['batire_site_format_file'] = array(
    '#title' => t('File type'),
    '#type' => 'select',
    '#options' => array('csv' => t('CSV'), 'xls' => t('Excel')),
    '#default_value' => variable_get('batire_site_format_file', 'xls'),
  );

  $form['file_settings'] = $settings;

  return system_settings_form($form);
}

/**
 * Access denied pages settings callback;
 */
function batire_site_access_denied_settings() {
  $form = array();

  $form['batire_site_access_denied_pages'] = array(
    '#type' => 'textarea',
    '#title' => t('List of pages'),
    '#description' => t('Enter list of pages, one per line. Access denied popup will not be shown on these pages'),
    '#default_value' => variable_get('batire_site_access_denied_pages', "user/register\nuser/register/free\nuser/register/activation\nuser")
  );

  return system_settings_form($form);
}

/**
 * Form for help strings
 */
function batire_site_help_settings() {
  $form = array();

  $search_home_help = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Home page: Search field'),
    '#weight' => 0
  );

  $search_home_help['batire_site_help_search_home'] = array(
    '#type' => 'textarea',
    '#required' => TRUE,
    '#title' => t('Home page: Search field'),
    '#default_value' => variable_get('batire_site_help_search_home', '')
  );
  $search_home_help['batire_site_help_search_home_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text'),
    '#default_value' => variable_get('batire_site_help_search_home_link_text', 'cliquant ici')
  );
  $search_home_help['batire_site_help_search_home_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Link'),
    '#default_value' => variable_get('batire_site_help_search_home_link', '')
  );

  $form['batire_site_search_home_help'] = $search_home_help;

  $search_result_help = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Search results page: right corner'),
    '#weight' => 1
  );

  $search_result_help['batire_site_help_search_result'] = array(
    '#type' => 'textarea',
    '#required' => TRUE,
    '#title' => t('Search results page: right corner'),
    '#default_value' => variable_get('batire_site_help_search_result', '')
  );
  $search_result_help['batire_site_help_search_result_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text'),
    '#default_value' => variable_get('batire_site_help_search_result_link_text', 'cliquant ici')
  );
  $search_result_help['batire_site_help_search_result_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Link'),
    '#default_value' => variable_get('batire_site_help_search_result_link', '')
  );

  $form['batire_site_search_result_help'] = $search_result_help;

  return system_settings_form($form);
}

/**
 * Access denied pages settings callback;
 */
function batire_site_lemoniteur_block_settings() {
  $form = array();

  $form['batire_site_lemoniteur_block_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL for RSS'),
    '#description' => t('Enter RSS URL for get the Lemoniteur.fr feeds'),
    '#default_value' => variable_get('batire_site_lemoniteur_block_url', "http://www.lemoniteur.fr/cache/X_articles_rss2_185.xml")
  );

  return system_settings_form($form);
}


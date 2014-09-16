<?php

/**
 * @file
 *  batire_search.admin.inc
 * Search settings for site
 */

/**
 * Search settings form
 *
 * @ingroup forms
 */
function batire_search_search_settings() {
  $form = array();
  $form['batire_search_id_alphabet'] = array(
    '#type' => 'textfield',
    '#title' => t('Search id alphabet'),
    '#default_value' => variable_get('batire_search_id_alphabet', BATIRE_SEARCH_ID_DEFAULT_ALPHABET)
  );
  $form['batire_search_id_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Search id length'),
    '#default_value' => variable_get('batire_search_id_length', BATIRE_SEARCH_ID_LENGTH)
  );
  $form['batire_search_count_searches_to_display'] = array(
    '#type' => 'textfield',
    '#title' => t('Quantity of results to display'),
    '#default_value' => variable_get('batire_search_count_searches_to_display', BATIRE_SEARCH_COUNT_SEARCH_TO_DISPLAY)
  );
  $form['batire_search_excluded_words'] = array(
    '#type' => 'textarea',
    '#title' => t('List of exclud words'),
    '#default_value' => variable_get('batire_search_excluded_words', BATIRE_SEARCH_EXCLUDED_WORDS),
  );

  $form['batire_search_search_links_menu'] = array(
    '#type' => 'select',
    '#title' => 'Select menu with search link',
    '#options' => menu_get_menus(),
    '#multiple' => TRUE,
    '#default_value' => variable_get('batire_search_search_links_menu', NULL),
  );
  return system_settings_form($form);
}
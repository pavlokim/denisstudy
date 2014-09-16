<?php

/**
 * @file
 *  batire_antidot_search.admin.inc
 * Antidot search settings for site
 */
/**
 * Implementation of hook_form_FORM_ID_alter().
 */
function batire_antidot_search_form_batire_antidot_settings_form_alter(&$form, &$form_state) {
  $form['search_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Propriétés du service Recherche')
  );
  $form['search_settings']['batire_antidot_search_service_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL pour le service de recherche'),
    '#default_value' => variable_get('batire_antidot_search_service_url', '')
  );
  $form['search_settings']['batire_antidot_search_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Identificateur du client'),
    '#default_value' => variable_get('batire_antidot_search_client_id', '')
  );
  $form['search_settings']['batire_antidot_search_status'] = array(
    '#type' => 'select',
    '#title' => t('Antidot status'),
    '#options' => array('rc' => t('RC'), 'stable' => t('Stable'), 'alpha' => t('Alpha'), 'beta' => t('Beta')),
    '#default_value' => variable_get('batire_antidot_search_status', 'rc')
  );
}
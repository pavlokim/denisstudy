<?php

/**
 * @file
 *
 * Admin settings for the module
 */

/**
 * Callback for admin settings
 */
function batire_svc_admin_settings() {
  $form = array();

  $form[BATIRE_SVC]['batire_svc_appelant'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Appelant ID'),
    '#default_value' => variable_get('batire_svc_appelant', 'BAT')
  );

  $form[BATIRE_SVC]['batire_svc_product'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Product ID'),
    '#default_value' => variable_get('batire_svc_product', 'BTC')
  );

  $form[BATIRE_SVC]['debug_settings'] = array(
    '#type'      => 'fieldset',
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
    '#title'     => t('Debug settings')
  );

  $form[BATIRE_SVC]['debug_settings']['batire_svc_debug'] = array(
    '#type' => 'checkbox',
    '#title' => t('Collect debug info'),
    '#default_value' => variable_get('batire_svc_debug', 0)
  );

  $form[BATIRE_SVC]['debug_settings']['batire_svc_trace'] = array(
    '#type' => 'checkbox',
    '#title' => t('Collect XML trace'),
    '#default_value' => variable_get('batire_svc_trace', 0)
  );

  $form[BATIRE_SVC]['debug_settings']['batire_svc_disable_cache'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable WSDL cache'),
    '#default_value' => variable_get('batire_svc_disable_cache', 0)
  );

  $form[BATIRE_SVC]['proxy_settings'] = array(
    '#type'      => 'fieldset',
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
    '#title'     => t('Proxy settings'),
    '#description'  => t('To enable proxy with SoapClient please specify at least proxy address')
  );

  $form[BATIRE_SVC]['proxy_settings']['batire_svc_proxy_addr'] = array(
    '#type' => 'textfield',
    '#title' => t('Proxy address'),
    '#default_value' => variable_get('batire_svc_proxy_addr', '')
  );

  $form[BATIRE_SVC]['proxy_settings']['batire_svc_proxy_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Proxy port'),
    '#default_value' => variable_get('batire_svc_proxy_port', '')
  );

  return system_settings_form($form);
}
<?php

/**
 * @file
 *  batire_user_docs_pdf.admin.inc
 * Admin settings for pdf
 */

/**
 * Pdf admin settings
 *
 * @ingroup forms
 */
function batire_user_docs_pdf_settings_form() {
  $form = array();
  $form['batire_user_docs_pdf_process_priority'] = array(
    '#title' => 'Generation process priority',
    '#description' => t('Priority value for nice (!link) function', array('!link' => l('man', 'http://linux.die.net/man/1/nice'))),
    '#type' => 'select',
    '#options' => range(0, 19),
    '#default_value' => variable_get('batire_user_docs_pdf_process_priority', 5),
  );

  $form['batire_user_docs_pdf_php'] = array(
    '#title' => 'PHP path',
    '#description' => t('Path to php'),
    '#type' => 'textfield',
    '#default_value' => variable_get('batire_user_docs_pdf_php', '/usr/bin/php'),
  );

  $form['batire_user_docs_pdf_http_login'] = array(
    '#title' => 'HTTP Auth login',
    '#description' => t('HTTP Auth login'),
    '#type' => 'textfield',
    '#default_value' => variable_get('batire_user_docs_pdf_http_login', ''),
  );

  $form['batire_user_docs_pdf_http_pass'] = array(
    '#title' => 'HTTP Auth pass',
    '#description' => t('HTTP Auth pass'),
    '#type' => 'textfield',
    '#default_value' => variable_get('batire_user_docs_pdf_http_pass', ''),
  );

  $form['batire_user_docs_pdf_pdftk_path'] = array(
    '#title' => 'PDFTK path',
    '#description' => t('Path to pdftk'),
    '#type' => 'textfield',
    '#default_value' => variable_get('batire_user_docs_pdf_pdftk_path', '/usr/bin/pdftk'),
  );

  $form['batire_user_docs_pdf_pdf2swf_path'] = array(
    '#title' => 'PDF2SWF path',
    '#description' => t('Path to pdf2swf'),
    '#type' => 'textfield',
    '#default_value' => variable_get('batire_user_docs_pdf_pdf2swf_path', '/usr/local/bin/pdf2swf'),
  );
  return system_settings_form($form);
}
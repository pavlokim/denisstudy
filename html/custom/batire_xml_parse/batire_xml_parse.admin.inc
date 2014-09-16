<?php
// $Id: batire_xml_parse.admin.inc $

/**
 * @file
 * Provides admin interface for the module
 */

/**
 * Website settings form
 */
function batire_xml_parse_settings() {

  $form = array();

  $settings = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#title' => t('XML Parse settings'),
    '#weight' => 0
  );
  
  $settings['batire_xml_parse_backup_folder'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Backup folder'),
    '#default_value' => variable_get('batire_xml_parse_backup_folder', BATIRE_XML_PARSE_DEFAULT_BACKUP_FOLDER)
  );

  $settings['batire_xml_parse_temporary_folder'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Temporary folder'),
    '#default_value' => variable_get('batire_xml_parse_backup_folder', BATIRE_XML_PARSE_DEFAULT_TEMPORARY_FOLDER)
  );

  $settings['batire_xml_parse_pack_size'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Max size of documents pack'),
    '#default_value' => variable_get('batire_xml_parse_pack_size', 500)
  );
  $settings['batire_xml_parse_logging'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Enable logging into filesystem'),
    '#description'   => t('Warning! It may increase importing time'),
    '#default_value' => variable_get('batire_xml_parse_logging', 0)
  );


  $form['batire_xml_parse_settings'] = $settings;

  return system_settings_form($form);
}
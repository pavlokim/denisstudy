<?php

/**
 * Implementation of hook_content_default_fields().
 */
function batire_products_content_default_fields() {
  $fields = array();

  // Exported field: field_codes_espaces
  $fields['batire_product_module_1_2-field_codes_espaces'] = array(
    'field_name' => 'field_codes_espaces',
    'type_name' => 'batire_product_module_1_2',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '1',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_codes_espaces][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Codes d\'espaces',
      'weight' => '44',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_product_acroche
  $fields['batire_product_module_1_2-field_product_acroche'] = array(
    'field_name' => 'field_product_acroche',
    'type_name' => 'batire_product_module_1_2',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => '256',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_product_acroche][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Accroche',
      'weight' => '37',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_product_actuality
  $fields['batire_product_module_1_2-field_product_actuality'] = array(
    'field_name' => 'field_product_actuality',
    'type_name' => 'batire_product_module_1_2',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '0|Do not include Actualité
1|Include Actualité',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Actualité',
      'weight' => '41',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_product_ct
  $fields['batire_product_module_1_2-field_product_ct'] = array(
    'field_name' => 'field_product_ct',
    'type_name' => 'batire_product_module_1_2',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '0|Do not include Complement Technique
1|Include Complement Technique',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Complement technique',
      'weight' => '42',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_product_description
  $fields['batire_product_module_1_2-field_product_description'] = array(
    'field_name' => 'field_product_description',
    'type_name' => 'batire_product_module_1_2',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_product_description][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Descriptif',
      'weight' => '38',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_product_enabled
  $fields['batire_product_module_1_2-field_product_enabled'] = array(
    'field_name' => 'field_product_enabled',
    'type_name' => 'batire_product_module_1_2',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '0|Deactivate
1|Activate',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 1,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Statut',
      'weight' => '35',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_product_tarif
  $fields['batire_product_module_1_2-field_product_tarif'] = array(
    'field_name' => 'field_product_tarif',
    'type_name' => 'batire_product_module_1_2',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_float',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_product_tarif][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Tarif HT',
      'weight' => '39',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_product_tn
  $fields['batire_product_module_1_2-field_product_tn'] = array(
    'field_name' => 'field_product_tn',
    'type_name' => 'batire_product_module_1_2',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '0|Do not include Textes Normatifs
1|Include Textes Normatifs',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Textes Normatifs',
      'weight' => '43',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_svc_code
  $fields['batire_product_module_1_2-field_svc_code'] = array(
    'field_name' => 'field_svc_code',
    'type_name' => 'batire_product_module_1_2',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '256',
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_svc_code][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Code produit SVC',
      'weight' => '40',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_codes_espaces
  $fields['batire_product_module_3-field_codes_espaces'] = array(
    'field_name' => 'field_codes_espaces',
    'type_name' => 'batire_product_module_3',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '1',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_codes_espaces][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Codes d\'espaces',
      'weight' => '48',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_product_acroche
  $fields['batire_product_module_3-field_product_acroche'] = array(
    'field_name' => 'field_product_acroche',
    'type_name' => 'batire_product_module_3',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '256',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_product_acroche][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Accroche',
      'weight' => '42',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_product_actuality
  $fields['batire_product_module_3-field_product_actuality'] = array(
    'field_name' => 'field_product_actuality',
    'type_name' => 'batire_product_module_3',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '0|Do not include Actualité
1|Include Actualité',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Actualité',
      'weight' => '46',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_product_ct
  $fields['batire_product_module_3-field_product_ct'] = array(
    'field_name' => 'field_product_ct',
    'type_name' => 'batire_product_module_3',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '0|Do not include Complement Technique
1|Include Complement Technique',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Complement technique',
      'weight' => '47',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_product_description
  $fields['batire_product_module_3-field_product_description'] = array(
    'field_name' => 'field_product_description',
    'type_name' => 'batire_product_module_3',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_product_description][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Descriptif',
      'weight' => '43',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_product_enabled
  $fields['batire_product_module_3-field_product_enabled'] = array(
    'field_name' => 'field_product_enabled',
    'type_name' => 'batire_product_module_3',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '0|Deactivate
1|Activate',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 1,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Statut',
      'weight' => '40',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_product_tarif
  $fields['batire_product_module_3-field_product_tarif'] = array(
    'field_name' => 'field_product_tarif',
    'type_name' => 'batire_product_module_3',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_float',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_product_tarif][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Tarif HT',
      'weight' => '44',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_svc_code
  $fields['batire_product_module_3-field_svc_code'] = array(
    'field_name' => 'field_svc_code',
    'type_name' => 'batire_product_module_3',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'popups' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'email' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_document' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'shared_annotation' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'searches_alerts' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '256',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_svc_code][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Code produit SVC',
      'weight' => '45',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Accroche');
  t('Actualité');
  t('Code produit SVC');
  t('Codes d\'espaces');
  t('Complement technique');
  t('Descriptif');
  t('Statut');
  t('Tarif HT');
  t('Textes Normatifs');

  return $fields;
}

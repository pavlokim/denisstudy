<?php

/**
 * Implementation of hook_content_default_fields().
 */
function batire_content_types_content_default_fields() {
  $fields = array();

  // Exported field: field_content
  $fields['batire_5_advices-field_content'] = array(
    'field_name' => 'field_content',
    'type_name' => 'batire_5_advices',
    'display_settings' => array(
      'weight' => '4',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_content][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Contenu',
      'weight' => '4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_image
  $fields['batire_5_advices-field_image'] = array(
    'field_name' => 'field_image',
    'type_name' => 'batire_5_advices',
    'display_settings' => array(
      'weight' => '3',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'batire_5advices_img_default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Image',
      'weight' => '3',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_subtitle
  $fields['batire_5_advices-field_subtitle'] = array(
    'field_name' => 'field_subtitle',
    'type_name' => 'batire_5_advices',
    'display_settings' => array(
      'weight' => '2',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_subtitle][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Subtitle',
      'weight' => '2',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_authors
  $fields['batire_actualite-field_authors'] = array(
    'field_name' => 'field_authors',
    'type_name' => 'batire_actualite',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'batire_auteur' => 'batire_auteur',
      'batire_5_advices' => 0,
      'batire_actualite' => 0,
      'batire_user_sent_alert' => 0,
      'batire_commercial_animation' => 0,
      'batire_user_annotation' => 0,
      'batire_feuillet_mobile' => 0,
      'batire_codes' => 0,
      'batire_complement_technique' => 0,
      'batire_document_reference' => 0,
      'batire_document_pratique' => 0,
      'batire_user_folder' => 0,
      'faq' => 0,
      'batire_homepage_blocks' => 0,
      'batire_livres' => 0,
      'page' => 0,
      'batire_page_not_found' => 0,
      'batire_product_module_1_2' => 0,
      'batire_product_module_3' => 0,
      'batire_user_profile' => 0,
      'batire_user_search_profile' => 0,
      'profile' => 0,
      'story' => 0,
      'batire_from_lemoniteur' => 0,
      'batire_texte_normatifs' => 0,
      'batire_texte_officiel' => 0,
      'batire_last_documents' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Auteurs(s)',
      'weight' => 0,
      'description' => '',
      'type' => 'nodereference_buttons',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_bid
  $fields['batire_actualite-field_bid'] = array(
    'field_name' => 'field_bid',
    'type_name' => 'batire_actualite',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_bid][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'BID',
      'weight' => '32',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_date_vide
  $fields['batire_actualite-field_date_vide'] = array(
    'field_name' => 'field_date_vide',
    'type_name' => 'batire_actualite',
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
    'allowed_values' => '0
1| Vide',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Date Vide',
      'weight' => '3',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_illustrators
  $fields['batire_actualite-field_illustrators'] = array(
    'field_name' => 'field_illustrators',
    'type_name' => 'batire_actualite',
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
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_illustrators][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'rows' => 5,
      'label' => 'Illustrateur(s) consulté',
      'weight' => '2',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_release_date
  $fields['batire_actualite-field_release_date'] = array(
    'field_name' => 'field_release_date',
    'type_name' => 'batire_actualite',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'feuillet_mobile_date',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date de parution',
      'weight' => '-3',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_release_num
  $fields['batire_actualite-field_release_num'] = array(
    'field_name' => 'field_release_num',
    'type_name' => 'batire_actualite',
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
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_release_num][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'N° de parution',
      'weight' => '-2',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_subtitle
  $fields['batire_actualite-field_subtitle'] = array(
    'field_name' => 'field_subtitle',
    'type_name' => 'batire_actualite',
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
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_subtitle][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Soustitre',
      'weight' => '-1',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_surtitle
  $fields['batire_actualite-field_surtitle'] = array(
    'field_name' => 'field_surtitle',
    'type_name' => 'batire_actualite',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_surtitle][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Surtitre',
      'weight' => '1',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_author_bio
  $fields['batire_auteur-field_author_bio'] = array(
    'field_name' => 'field_author_bio',
    'type_name' => 'batire_auteur',
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
          '_error_element' => 'default_value_widget][field_author_bio][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Bio',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_author_code
  $fields['batire_auteur-field_author_code'] = array(
    'field_name' => 'field_author_code',
    'type_name' => 'batire_auteur',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_author_code][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Code',
      'weight' => '-3',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_bid
  $fields['batire_codes-field_bid'] = array(
    'field_name' => 'field_bid',
    'type_name' => 'batire_codes',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_bid][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'BID',
      'weight' => '8',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_cites
  $fields['batire_codes-field_cites'] = array(
    'field_name' => 'field_cites',
    'type_name' => 'batire_codes',
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
          '_error_element' => 'default_value_widget][field_cites][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Cites',
      'weight' => '10',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_code_number
  $fields['batire_codes-field_code_number'] = array(
    'field_name' => 'field_code_number',
    'type_name' => 'batire_codes',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_code_number][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'N° d’article du code',
      'weight' => '-3',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_date_vide
  $fields['batire_codes-field_date_vide'] = array(
    'field_name' => 'field_date_vide',
    'type_name' => 'batire_codes',
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
    'allowed_values' => '0
1| Vide',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Date Vide',
      'weight' => '5',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_import_date
  $fields['batire_codes-field_import_date'] = array(
    'field_name' => 'field_import_date',
    'type_name' => 'batire_codes',
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
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
      'second' => 'second',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date de import',
      'weight' => '6',
      'description' => '',
      'type' => 'date_select',
      'module' => 'date',
    ),
  );

  // Exported field: field_juri_date
  $fields['batire_codes-field_juri_date'] = array(
    'field_name' => 'field_juri_date',
    'type_name' => 'batire_codes',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'lemoniteur_date',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date',
      'weight' => '-4',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_juri_status
  $fields['batire_codes-field_juri_status'] = array(
    'field_name' => 'field_juri_status',
    'type_name' => 'batire_codes',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_juri_status][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Statut juridique',
      'weight' => '-2',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_content
  $fields['batire_commercial_animation-field_content'] = array(
    'field_name' => 'field_content',
    'type_name' => 'batire_commercial_animation',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '1',
          '_error_element' => 'default_value_widget][field_content][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Contenu',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_authors
  $fields['batire_complement_technique-field_authors'] = array(
    'field_name' => 'field_authors',
    'type_name' => 'batire_complement_technique',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'batire_auteur' => 'batire_auteur',
      'batire_5_advices' => 0,
      'batire_actualite' => 0,
      'batire_user_sent_alert' => 0,
      'batire_commercial_animation' => 0,
      'batire_user_annotation' => 0,
      'batire_feuillet_mobile' => 0,
      'batire_codes' => 0,
      'batire_complement_technique' => 0,
      'batire_document_reference' => 0,
      'batire_document_pratique' => 0,
      'batire_user_folder' => 0,
      'faq' => 0,
      'batire_homepage_blocks' => 0,
      'batire_livres' => 0,
      'page' => 0,
      'batire_page_not_found' => 0,
      'batire_product_module_1_2' => 0,
      'batire_product_module_3' => 0,
      'batire_user_profile' => 0,
      'batire_user_search_profile' => 0,
      'profile' => 0,
      'story' => 0,
      'batire_from_lemoniteur' => 0,
      'batire_texte_normatifs' => 0,
      'batire_texte_officiel' => 0,
      'batire_last_documents' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Auteurs(s)',
      'weight' => '3',
      'description' => '',
      'type' => 'nodereference_buttons',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_bid
  $fields['batire_complement_technique-field_bid'] = array(
    'field_name' => 'field_bid',
    'type_name' => 'batire_complement_technique',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_bid][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'BID',
      'weight' => '13',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_date_vide
  $fields['batire_complement_technique-field_date_vide'] = array(
    'field_name' => 'field_date_vide',
    'type_name' => 'batire_complement_technique',
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
    'allowed_values' => '0
1| Vide',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Date Vide',
      'weight' => '11',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_illustrators
  $fields['batire_complement_technique-field_illustrators'] = array(
    'field_name' => 'field_illustrators',
    'type_name' => 'batire_complement_technique',
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
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_illustrators][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'rows' => 5,
      'label' => 'Illustrateur(s) consulté',
      'weight' => '4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_release_date
  $fields['batire_complement_technique-field_release_date'] = array(
    'field_name' => 'field_release_date',
    'type_name' => 'batire_complement_technique',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'feuillet_mobile_date',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date de parution',
      'weight' => '-2',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_release_num
  $fields['batire_complement_technique-field_release_num'] = array(
    'field_name' => 'field_release_num',
    'type_name' => 'batire_complement_technique',
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
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_release_num][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'N° de parution',
      'weight' => '-3',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_rubric
  $fields['batire_complement_technique-field_rubric'] = array(
    'field_name' => 'field_rubric',
    'type_name' => 'batire_complement_technique',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_rubric][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Rubrique',
      'weight' => '1',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_sub_rubric
  $fields['batire_complement_technique-field_sub_rubric'] = array(
    'field_name' => 'field_sub_rubric',
    'type_name' => 'batire_complement_technique',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_sub_rubric][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sous-rubrique',
      'weight' => '2',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_surtitle
  $fields['batire_complement_technique-field_surtitle'] = array(
    'field_name' => 'field_surtitle',
    'type_name' => 'batire_complement_technique',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_surtitle][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Surtitre',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_tab_category
  $fields['batire_complement_technique-field_tab_category'] = array(
    'field_name' => 'field_tab_category',
    'type_name' => 'batire_complement_technique',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_tab_category][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Onglet catégorie',
      'weight' => '-1',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_tab_reference
  $fields['batire_complement_technique-field_tab_reference'] = array(
    'field_name' => 'field_tab_reference',
    'type_name' => 'batire_complement_technique',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_tab_reference][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Onglet référence',
      'weight' => 0,
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_authors
  $fields['batire_document_pratique-field_authors'] = array(
    'field_name' => 'field_authors',
    'type_name' => 'batire_document_pratique',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'batire_auteur' => 'batire_auteur',
      'batire_5_advices' => 0,
      'batire_actualite' => 0,
      'batire_user_sent_alert' => 0,
      'batire_commercial_animation' => 0,
      'batire_user_annotation' => 0,
      'batire_feuillet_mobile' => 0,
      'batire_codes' => 0,
      'batire_complement_technique' => 0,
      'batire_document_reference' => 0,
      'batire_document_pratique' => 0,
      'batire_user_folder' => 0,
      'faq' => 0,
      'batire_homepage_blocks' => 0,
      'batire_livres' => 0,
      'page' => 0,
      'batire_page_not_found' => 0,
      'batire_product_module_1_2' => 0,
      'batire_product_module_3' => 0,
      'batire_user_profile' => 0,
      'batire_user_search_profile' => 0,
      'profile' => 0,
      'story' => 0,
      'batire_from_lemoniteur' => 0,
      'batire_texte_normatifs' => 0,
      'batire_texte_officiel' => 0,
      'batire_last_documents' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Auteurs(s)',
      'weight' => 0,
      'description' => '',
      'type' => 'nodereference_buttons',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_bid
  $fields['batire_document_pratique-field_bid'] = array(
    'field_name' => 'field_bid',
    'type_name' => 'batire_document_pratique',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_bid][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'BID',
      'weight' => '10',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_collection
  $fields['batire_document_pratique-field_collection'] = array(
    'field_name' => 'field_collection',
    'type_name' => 'batire_document_pratique',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_collection][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Collection',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_date_vide
  $fields['batire_document_pratique-field_date_vide'] = array(
    'field_name' => 'field_date_vide',
    'type_name' => 'batire_document_pratique',
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
    'allowed_values' => '0
1| Vide',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Date Vide',
      'weight' => '2',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_dp_date_pub
  $fields['batire_document_pratique-field_dp_date_pub'] = array(
    'field_name' => 'field_dp_date_pub',
    'type_name' => 'batire_document_pratique',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date de publication',
      'weight' => '-3',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_illustrators
  $fields['batire_document_pratique-field_illustrators'] = array(
    'field_name' => 'field_illustrators',
    'type_name' => 'batire_document_pratique',
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
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_illustrators][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'rows' => 5,
      'label' => 'Illustrateur(s) consulté',
      'weight' => '1',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_part_title
  $fields['batire_document_pratique-field_part_title'] = array(
    'field_name' => 'field_part_title',
    'type_name' => 'batire_document_pratique',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_part_title][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Titre de la partie',
      'weight' => '-1',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_section_title
  $fields['batire_document_pratique-field_section_title'] = array(
    'field_name' => 'field_section_title',
    'type_name' => 'batire_document_pratique',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_section_title][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Titre de la section ou de la partie',
      'weight' => '-2',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_authors
  $fields['batire_document_reference-field_authors'] = array(
    'field_name' => 'field_authors',
    'type_name' => 'batire_document_reference',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'batire_auteur' => 'batire_auteur',
      'batire_5_advices' => 0,
      'batire_actualite' => 0,
      'batire_user_sent_alert' => 0,
      'batire_commercial_animation' => 0,
      'batire_user_annotation' => 0,
      'batire_feuillet_mobile' => 0,
      'batire_codes' => 0,
      'batire_complement_technique' => 0,
      'batire_document_reference' => 0,
      'batire_document_pratique' => 0,
      'batire_user_folder' => 0,
      'faq' => 0,
      'batire_homepage_blocks' => 0,
      'batire_livres' => 0,
      'page' => 0,
      'batire_page_not_found' => 0,
      'batire_product_module_1_2' => 0,
      'batire_product_module_3' => 0,
      'batire_user_profile' => 0,
      'batire_user_search_profile' => 0,
      'profile' => 0,
      'story' => 0,
      'batire_from_lemoniteur' => 0,
      'batire_texte_normatifs' => 0,
      'batire_texte_officiel' => 0,
      'batire_last_documents' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Auteurs(s)',
      'weight' => '-1',
      'description' => '',
      'type' => 'nodereference_buttons',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_authors
  $fields['batire_feuillet_mobile-field_authors'] = array(
    'field_name' => 'field_authors',
    'type_name' => 'batire_feuillet_mobile',
    'display_settings' => array(
      'weight' => '1',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'batire_auteur' => 'batire_auteur',
      'batire_5_advices' => 0,
      'batire_actualite' => 0,
      'batire_user_sent_alert' => 0,
      'batire_commercial_animation' => 0,
      'batire_user_annotation' => 0,
      'batire_feuillet_mobile' => 0,
      'batire_codes' => 0,
      'batire_complement_technique' => 0,
      'batire_document_reference' => 0,
      'batire_document_pratique' => 0,
      'batire_user_folder' => 0,
      'faq' => 0,
      'batire_homepage_blocks' => 0,
      'batire_livres' => 0,
      'page' => 0,
      'batire_page_not_found' => 0,
      'batire_product_module_1_2' => 0,
      'batire_product_module_3' => 0,
      'batire_user_profile' => 0,
      'batire_user_search_profile' => 0,
      'profile' => 0,
      'story' => 0,
      'batire_from_lemoniteur' => 0,
      'batire_texte_normatifs' => 0,
      'batire_texte_officiel' => 0,
      'batire_last_documents' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Auteurs(s)',
      'weight' => '1',
      'description' => '',
      'type' => 'nodereference_buttons',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_bid
  $fields['batire_feuillet_mobile-field_bid'] = array(
    'field_name' => 'field_bid',
    'type_name' => 'batire_feuillet_mobile',
    'display_settings' => array(
      'weight' => '13',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_bid][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'BID',
      'weight' => '13',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_date_current
  $fields['batire_feuillet_mobile-field_date_current'] = array(
    'field_name' => 'field_date_current',
    'type_name' => 'batire_feuillet_mobile',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'feuillet_mobile_date',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date de la version en viguer',
      'weight' => '-2',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_date_update
  $fields['batire_feuillet_mobile-field_date_update'] = array(
    'field_name' => 'field_date_update',
    'type_name' => 'batire_feuillet_mobile',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'feuillet_mobile_date',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date d’actualisation',
      'weight' => '-3',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_date_vide
  $fields['batire_feuillet_mobile-field_date_vide'] = array(
    'field_name' => 'field_date_vide',
    'type_name' => 'batire_feuillet_mobile',
    'display_settings' => array(
      'weight' => '10',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
    'allowed_values' => '0
1| Vide',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Date Vide',
      'weight' => '10',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_doc_number
  $fields['batire_feuillet_mobile-field_doc_number'] = array(
    'field_name' => 'field_doc_number',
    'type_name' => 'batire_feuillet_mobile',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_doc_number][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Numérotation du document',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_editor
  $fields['batire_feuillet_mobile-field_editor'] = array(
    'field_name' => 'field_editor',
    'type_name' => 'batire_feuillet_mobile',
    'display_settings' => array(
      'weight' => '3',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_editor][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Сoordinateur éditorial',
      'weight' => '3',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_illustrators
  $fields['batire_feuillet_mobile-field_illustrators'] = array(
    'field_name' => 'field_illustrators',
    'type_name' => 'batire_feuillet_mobile',
    'display_settings' => array(
      'weight' => '2',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_illustrators][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'rows' => 5,
      'label' => 'Illustrateur(s) consulté',
      'weight' => '2',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_import_date
  $fields['batire_feuillet_mobile-field_import_date'] = array(
    'field_name' => 'field_import_date',
    'type_name' => 'batire_feuillet_mobile',
    'display_settings' => array(
      'weight' => '12',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
      'second' => 'second',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date de import',
      'weight' => '12',
      'description' => '',
      'type' => 'date_select',
      'module' => 'date',
    ),
  );

  // Exported field: field_sublayer_level_title
  $fields['batire_feuillet_mobile-field_sublayer_level_title'] = array(
    'field_name' => 'field_sublayer_level_title',
    'type_name' => 'batire_feuillet_mobile',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_sublayer_level_title][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'N° et titre de l\'intercalaire ou de la partie',
      'weight' => '-1',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_sublayer_sublevel_title
  $fields['batire_feuillet_mobile-field_sublayer_sublevel_title'] = array(
    'field_name' => 'field_sublayer_sublevel_title',
    'type_name' => 'batire_feuillet_mobile',
    'display_settings' => array(
      'weight' => 0,
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_sublayer_sublevel_title][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'N° et titre du sous-intercalaire',
      'weight' => 0,
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_lemoniteur_date
  $fields['batire_from_lemoniteur-field_lemoniteur_date'] = array(
    'field_name' => 'field_lemoniteur_date',
    'type_name' => 'batire_from_lemoniteur',
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
    'type' => 'datestamp',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date',
      'weight' => '-3',
      'description' => '',
      'type' => 'date_select',
      'module' => 'date',
    ),
  );

  // Exported field: field_lemoniteur_image
  $fields['batire_from_lemoniteur-field_lemoniteur_image'] = array(
    'field_name' => 'field_lemoniteur_image',
    'type_name' => 'batire_from_lemoniteur',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Image',
      'weight' => '-2',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_lemoniteur_link
  $fields['batire_from_lemoniteur-field_lemoniteur_link'] = array(
    'field_name' => 'field_lemoniteur_link',
    'type_name' => 'batire_from_lemoniteur',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_lemoniteur_link][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Lien',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_content
  $fields['batire_homepage_blocks-field_content'] = array(
    'field_name' => 'field_content',
    'type_name' => 'batire_homepage_blocks',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_content][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Contenu',
      'weight' => '33',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_hp_link
  $fields['batire_homepage_blocks-field_hp_link'] = array(
    'field_name' => 'field_hp_link',
    'type_name' => 'batire_homepage_blocks',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '1',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'optional',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Lien',
      'weight' => '34',
      'description' => '',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_image
  $fields['batire_homepage_blocks-field_image'] = array(
    'field_name' => 'field_image',
    'type_name' => 'batire_homepage_blocks',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'document' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'annotation' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'antidot' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Image',
      'weight' => '31',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_content
  $fields['batire_last_documents-field_content'] = array(
    'field_name' => 'field_content',
    'type_name' => 'batire_last_documents',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_content][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Contenu',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_show_to_anon
  $fields['batire_last_documents-field_show_to_anon'] = array(
    'field_name' => 'field_show_to_anon',
    'type_name' => 'batire_last_documents',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'multiple' => '1',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '1|Afficher pour les non-abonnés',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '1',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Afficher pour les non-abonnés',
      'weight' => '-3',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_veille_date
  $fields['batire_last_documents-field_veille_date'] = array(
    'field_name' => 'field_veille_date',
    'type_name' => 'batire_last_documents',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'd/m/Y - H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date',
      'weight' => '-1',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_veille_document
  $fields['batire_last_documents-field_veille_document'] = array(
    'field_name' => 'field_veille_document',
    'type_name' => 'batire_last_documents',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 'optional',
    'title' => 'required',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'title' => 'Consulter le document...',
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Document',
      'weight' => '-2',
      'description' => '',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_authors
  $fields['batire_livres-field_authors'] = array(
    'field_name' => 'field_authors',
    'type_name' => 'batire_livres',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'batire_auteur' => 'batire_auteur',
      'batire_5_advices' => 0,
      'batire_actualite' => 0,
      'batire_user_sent_alert' => 0,
      'batire_commercial_animation' => 0,
      'batire_user_annotation' => 0,
      'batire_feuillet_mobile' => 0,
      'batire_codes' => 0,
      'batire_complement_technique' => 0,
      'batire_document_reference' => 0,
      'batire_document_pratique' => 0,
      'batire_user_folder' => 0,
      'faq' => 0,
      'batire_homepage_blocks' => 0,
      'batire_livres' => 0,
      'page' => 0,
      'batire_page_not_found' => 0,
      'batire_product_module_1_2' => 0,
      'batire_product_module_3' => 0,
      'batire_user_profile' => 0,
      'batire_user_search_profile' => 0,
      'profile' => 0,
      'story' => 0,
      'batire_from_lemoniteur' => 0,
      'batire_texte_normatifs' => 0,
      'batire_texte_officiel' => 0,
      'batire_last_documents' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Auteurs(s)',
      'weight' => '2',
      'description' => '',
      'type' => 'nodereference_buttons',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_bid
  $fields['batire_livres-field_bid'] = array(
    'field_name' => 'field_bid',
    'type_name' => 'batire_livres',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_bid][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'BID',
      'weight' => '15',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_collection
  $fields['batire_livres-field_collection'] = array(
    'field_name' => 'field_collection',
    'type_name' => 'batire_livres',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_collection][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Collection',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_date_pub
  $fields['batire_livres-field_date_pub'] = array(
    'field_name' => 'field_date_pub',
    'type_name' => 'batire_livres',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'feuillet_mobile_date',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date de publication',
      'weight' => '-3',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_date_vide
  $fields['batire_livres-field_date_vide'] = array(
    'field_name' => 'field_date_vide',
    'type_name' => 'batire_livres',
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
    'allowed_values' => '0
1| Vide',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Date Vide',
      'weight' => '12',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_editor
  $fields['batire_livres-field_editor'] = array(
    'field_name' => 'field_editor',
    'type_name' => 'batire_livres',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_editor][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Сoordinateur éditorial',
      'weight' => '4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_illustrators
  $fields['batire_livres-field_illustrators'] = array(
    'field_name' => 'field_illustrators',
    'type_name' => 'batire_livres',
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
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_illustrators][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'rows' => 5,
      'label' => 'Illustrateur(s) consulté',
      'weight' => '3',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_import_date
  $fields['batire_livres-field_import_date'] = array(
    'field_name' => 'field_import_date',
    'type_name' => 'batire_livres',
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
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
      'second' => 'second',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date de import',
      'weight' => '14',
      'description' => '',
      'type' => 'date_select',
      'module' => 'date',
    ),
  );

  // Exported field: field_part_num
  $fields['batire_livres-field_part_num'] = array(
    'field_name' => 'field_part_num',
    'type_name' => 'batire_livres',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_part_num][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'N° de la partie',
      'weight' => 0,
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_part_title
  $fields['batire_livres-field_part_title'] = array(
    'field_name' => 'field_part_title',
    'type_name' => 'batire_livres',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_part_title][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Titre de la partie',
      'weight' => '1',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_resume
  $fields['batire_livres-field_resume'] = array(
    'field_name' => 'field_resume',
    'type_name' => 'batire_livres',
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
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_resume][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Résumé',
      'weight' => '5',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_section_num
  $fields['batire_livres-field_section_num'] = array(
    'field_name' => 'field_section_num',
    'type_name' => 'batire_livres',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_section_num][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'N° de la section ou de la partie',
      'weight' => '-2',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_section_title
  $fields['batire_livres-field_section_title'] = array(
    'field_name' => 'field_section_title',
    'type_name' => 'batire_livres',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_section_title][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Titre de la section ou de la partie',
      'weight' => '-1',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_afnor_link
  $fields['batire_texte_normatifs-field_afnor_link'] = array(
    'field_name' => 'field_afnor_link',
    'type_name' => 'batire_texte_normatifs',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'optional',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'title' => '',
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Mention boutique Afnor',
      'weight' => '7',
      'description' => '',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_bid
  $fields['batire_texte_normatifs-field_bid'] = array(
    'field_name' => 'field_bid',
    'type_name' => 'batire_texte_normatifs',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_bid][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'BID',
      'weight' => '18',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_cites
  $fields['batire_texte_normatifs-field_cites'] = array(
    'field_name' => 'field_cites',
    'type_name' => 'batire_texte_normatifs',
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
          '_error_element' => 'default_value_widget][field_cites][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Cites',
      'weight' => '20',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_classification_index
  $fields['batire_texte_normatifs-field_classification_index'] = array(
    'field_name' => 'field_classification_index',
    'type_name' => 'batire_texte_normatifs',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_classification_index][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Indice de classement',
      'weight' => '1',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_date_anul
  $fields['batire_texte_normatifs-field_date_anul'] = array(
    'field_name' => 'field_date_anul',
    'type_name' => 'batire_texte_normatifs',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'lemoniteur_date',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date d’annulation',
      'weight' => 0,
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_date_vide
  $fields['batire_texte_normatifs-field_date_vide'] = array(
    'field_name' => 'field_date_vide',
    'type_name' => 'batire_texte_normatifs',
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
    'allowed_values' => '0
1| Vide',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Date Vide',
      'weight' => '15',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_doc_number
  $fields['batire_texte_normatifs-field_doc_number'] = array(
    'field_name' => 'field_doc_number',
    'type_name' => 'batire_texte_normatifs',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_doc_number][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => '# de référence',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_import_date
  $fields['batire_texte_normatifs-field_import_date'] = array(
    'field_name' => 'field_import_date',
    'type_name' => 'batire_texte_normatifs',
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
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
      'second' => 'second',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date de import',
      'weight' => '17',
      'description' => '',
      'type' => 'date_select',
      'module' => 'date',
    ),
  );

  // Exported field: field_other_parts
  $fields['batire_texte_normatifs-field_other_parts'] = array(
    'field_name' => 'field_other_parts',
    'type_name' => 'batire_texte_normatifs',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
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
          '_error_element' => 'default_value_widget][field_other_parts][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => '# de référence des autres parties du texte normatif consulté',
      'weight' => '5',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_replace_class_index
  $fields['batire_texte_normatifs-field_replace_class_index'] = array(
    'field_name' => 'field_replace_class_index',
    'type_name' => 'batire_texte_normatifs',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_replace_class_index][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Indice de classement du texte normatif remplacé',
      'weight' => '4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_replace_date
  $fields['batire_texte_normatifs-field_replace_date'] = array(
    'field_name' => 'field_replace_date',
    'type_name' => 'batire_texte_normatifs',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'lemoniteur_date',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date de publication de la norme remplacée',
      'weight' => '3',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_replace_num
  $fields['batire_texte_normatifs-field_replace_num'] = array(
    'field_name' => 'field_replace_num',
    'type_name' => 'batire_texte_normatifs',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_replace_num][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => '# de référence du texte normatif remplacé',
      'weight' => '2',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_resume
  $fields['batire_texte_normatifs-field_resume'] = array(
    'field_name' => 'field_resume',
    'type_name' => 'batire_texte_normatifs',
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
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_resume][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Résumé',
      'weight' => '6',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_subtitle
  $fields['batire_texte_normatifs-field_subtitle'] = array(
    'field_name' => 'field_subtitle',
    'type_name' => 'batire_texte_normatifs',
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
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_subtitle][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Titre du document ligne 3',
      'weight' => '-2',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_surtitle
  $fields['batire_texte_normatifs-field_surtitle'] = array(
    'field_name' => 'field_surtitle',
    'type_name' => 'batire_texte_normatifs',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_surtitle][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Titre du document linge 1',
      'weight' => '-3',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_tn_date_pub
  $fields['batire_texte_normatifs-field_tn_date_pub'] = array(
    'field_name' => 'field_tn_date_pub',
    'type_name' => 'batire_texte_normatifs',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'lemoniteur_date',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date de publication',
      'weight' => '-1',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_tn_detailed
  $fields['batire_texte_normatifs-field_tn_detailed'] = array(
    'field_name' => 'field_tn_detailed',
    'type_name' => 'batire_texte_normatifs',
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
    'allowed_values' => '0
1|Oui',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Notice détailleé',
      'weight' => '8',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_bid
  $fields['batire_texte_officiel-field_bid'] = array(
    'field_name' => 'field_bid',
    'type_name' => 'batire_texte_officiel',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_bid][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'BID',
      'weight' => '13',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_cites
  $fields['batire_texte_officiel-field_cites'] = array(
    'field_name' => 'field_cites',
    'type_name' => 'batire_texte_officiel',
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
          '_error_element' => 'default_value_widget][field_cites][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Cites',
      'weight' => '14',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_date_initial
  $fields['batire_texte_officiel-field_date_initial'] = array(
    'field_name' => 'field_date_initial',
    'type_name' => 'batire_texte_officiel',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date initiale',
      'weight' => 0,
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_date_vide
  $fields['batire_texte_officiel-field_date_vide'] = array(
    'field_name' => 'field_date_vide',
    'type_name' => 'batire_texte_officiel',
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
    'allowed_values' => '0
1| Vide',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 0,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Date Vide',
      'weight' => '9',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_document_fundamental
  $fields['batire_texte_officiel-field_document_fundamental'] = array(
    'field_name' => 'field_document_fundamental',
    'type_name' => 'batire_texte_officiel',
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
    'allowed_values' => '0
1',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Texte fondamental',
      'weight' => '12',
      'description' => '',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_import_date
  $fields['batire_texte_officiel-field_import_date'] = array(
    'field_name' => 'field_import_date',
    'type_name' => 'batire_texte_officiel',
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
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
      'second' => 'second',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date de import',
      'weight' => '11',
      'description' => '',
      'type' => 'date_select',
      'module' => 'date',
    ),
  );

  // Exported field: field_jorf
  $fields['batire_texte_officiel-field_jorf'] = array(
    'field_name' => 'field_jorf',
    'type_name' => 'batire_texte_officiel',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_jorf][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Mention JORF',
      'weight' => '-1',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_juri_date
  $fields['batire_texte_officiel-field_juri_date'] = array(
    'field_name' => 'field_juri_date',
    'type_name' => 'batire_texte_officiel',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'lemoniteur_date',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date',
      'weight' => '-2',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_juri_status
  $fields['batire_texte_officiel-field_juri_status'] = array(
    'field_name' => 'field_juri_status',
    'type_name' => 'batire_texte_officiel',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_juri_status][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Statut juridique',
      'weight' => '-3',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_number_nor
  $fields['batire_texte_officiel-field_number_nor'] = array(
    'field_name' => 'field_number_nor',
    'type_name' => 'batire_texte_officiel',
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
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_number_nor][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Numero NOR',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_signatures
  $fields['batire_texte_officiel-field_signatures'] = array(
    'field_name' => 'field_signatures',
    'type_name' => 'batire_texte_officiel',
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
          '_error_element' => 'default_value_widget][field_signatures][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Signatures',
      'weight' => '2',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_visas
  $fields['batire_texte_officiel-field_visas'] = array(
    'field_name' => 'field_visas',
    'type_name' => 'batire_texte_officiel',
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
          '_error_element' => 'default_value_widget][field_visas][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Visas',
      'weight' => '1',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_annotation_doc
  $fields['batire_user_annotation-field_annotation_doc'] = array(
    'field_name' => 'field_annotation_doc',
    'type_name' => 'batire_user_annotation',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'batire_actualite' => 'batire_actualite',
      'batire_codes' => 'batire_codes',
      'batire_complement_technique' => 'batire_complement_technique',
      'batire_document_pratique' => 'batire_document_pratique',
      'batire_feuillet_mobile' => 'batire_feuillet_mobile',
      'batire_livres' => 'batire_livres',
      'batire_texte_normatifs' => 'batire_texte_normatifs',
      'batire_texte_officiel' => 'batire_texte_officiel',
      'batire_5_advices' => 0,
      'batire_user_sent_alert' => 0,
      'batire_commercial_animation' => 0,
      'batire_user_annotation' => 0,
      'batire_auteur' => 0,
      'batire_user_folder' => 0,
      'faq' => 0,
      'batire_homepage_blocks' => 0,
      'page' => 0,
      'batire_page_not_found' => 0,
      'batire_user_profile' => 0,
      'batire_user_search_profile' => 0,
      'profile' => 0,
      'story' => 0,
      'batire_from_lemoniteur' => 0,
      'batire_last_documents' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_annotation_doc][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Document',
      'weight' => '-3',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_annotation_shared
  $fields['batire_user_annotation-field_annotation_shared'] = array(
    'field_name' => 'field_annotation_shared',
    'type_name' => 'batire_user_annotation',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'multiple' => '1',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '1|Shared',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Partager',
      'weight' => '-2',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_annotation_text
  $fields['batire_user_annotation-field_annotation_text'] = array(
    'field_name' => 'field_annotation_text',
    'type_name' => 'batire_user_annotation',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_annotation_text][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Contenu',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_folder_documents
  $fields['batire_user_folder-field_folder_documents'] = array(
    'field_name' => 'field_folder_documents',
    'type_name' => 'batire_user_folder',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'doc_reference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'doc_reference',
    'active' => '1',
    'referenceable_types' => array(
      'batire_actualite' => 'batire_actualite',
      'batire_codes' => 'batire_codes',
      'batire_complement_technique' => 'batire_complement_technique',
      'batire_document_pratique' => 'batire_document_pratique',
      'batire_feuillet_mobile' => 'batire_feuillet_mobile',
      'batire_livres' => 'batire_livres',
      'batire_texte_normatifs' => 'batire_texte_normatifs',
      'batire_texte_officiel' => 'batire_texte_officiel',
      'batire_5_advices' => 0,
      'batire_user_sent_alert' => 0,
      'batire_user_annotation' => 0,
      'batire_auteur' => 0,
      'batire_user_folder' => 0,
      'faq' => 0,
      'batire_homepage_blocks' => 0,
      'page' => 0,
      'batire_page_not_found' => 0,
      'batire_user_profile' => 0,
      'batire_user_search_profile' => 0,
      'profile' => 0,
      'story' => 0,
      'batire_from_lemoniteur' => 0,
      'batire_last_documents' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_folder_documents][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Documents',
      'weight' => '-1',
      'description' => '',
      'type' => 'doc_reference_autocomplete',
      'module' => 'doc_reference',
    ),
  );

  // Exported field: field_folder_parent
  $fields['batire_user_folder-field_folder_parent'] = array(
    'field_name' => 'field_folder_parent',
    'type_name' => 'batire_user_folder',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'batire_user_folder' => 'batire_user_folder',
      'batire_5_advices' => 0,
      'batire_actualite' => 0,
      'batire_user_sent_alert' => 0,
      'batire_user_annotation' => 0,
      'batire_auteur' => 0,
      'batire_codes' => 0,
      'batire_complement_technique' => 0,
      'batire_document_pratique' => 0,
      'faq' => 0,
      'batire_feuillet_mobile' => 0,
      'batire_homepage_blocks' => 0,
      'batire_livres' => 0,
      'page' => 0,
      'batire_page_not_found' => 0,
      'batire_user_profile' => 0,
      'batire_user_search_profile' => 0,
      'profile' => 0,
      'story' => 0,
      'batire_from_lemoniteur' => 0,
      'batire_texte_normatifs' => 0,
      'batire_texte_officiel' => 0,
      'batire_last_documents' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_folder_parent][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Dossier parent',
      'weight' => 0,
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_folder_shared
  $fields['batire_user_folder-field_folder_shared'] = array(
    'field_name' => 'field_folder_shared',
    'type_name' => 'batire_user_folder',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'multiple' => '1',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '1|Partager',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Partager',
      'weight' => '-2',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_default_search
  $fields['batire_user_profile-field_default_search'] = array(
    'field_name' => 'field_default_search',
    'type_name' => 'batire_user_profile',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'batire_user_search_profile' => 'batire_user_search_profile',
      'batire_5_advices' => 0,
      'batire_actualite' => 0,
      'batire_user_sent_alert' => 0,
      'batire_commercial_animation' => 0,
      'batire_user_annotation' => 0,
      'batire_auteur' => 0,
      'batire_codes' => 0,
      'batire_complement_technique' => 0,
      'batire_document_pratique' => 0,
      'batire_user_folder' => 0,
      'faq' => 0,
      'batire_feuillet_mobile' => 0,
      'batire_homepage_blocks' => 0,
      'batire_livres' => 0,
      'page' => 0,
      'batire_page_not_found' => 0,
      'batire_user_profile' => 0,
      'profile' => 0,
      'story' => 0,
      'batire_from_lemoniteur' => 0,
      'batire_texte_normatifs' => 0,
      'batire_texte_officiel' => 0,
      'batire_last_documents' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_default_search][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Default search profile',
      'weight' => '49',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_new_docs_cnt
  $fields['batire_user_profile-field_new_docs_cnt'] = array(
    'field_name' => 'field_new_docs_cnt',
    'type_name' => 'batire_user_profile',
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
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_new_docs_cnt][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'New docs counter',
      'weight' => '51',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_new_docs_flag
  $fields['batire_user_profile-field_new_docs_flag'] = array(
    'field_name' => 'field_new_docs_flag',
    'type_name' => 'batire_user_profile',
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
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_new_docs_flag][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'New docs flag',
      'weight' => '50',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_subscribed_to_newsletter
  $fields['batire_user_profile-field_subscribed_to_newsletter'] = array(
    'field_name' => 'field_subscribed_to_newsletter',
    'type_name' => 'batire_user_profile',
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
    'allowed_values' => '0|No
1|Yes',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 1,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Subscribed to newsletter',
      'weight' => '52',
      'description' => 'Subscribed to newsletter',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_user_abon_list
  $fields['batire_user_profile-field_user_abon_list'] = array(
    'field_name' => 'field_user_abon_list',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'allowed_values' => 'Le Moniteur des travaux publics et du batiment
Lemoniteur.fr
La Gazette des communes
Lagazette.fr
La revue Contrats Publics
Une autre revue du Groupe Moniteur
Code des Marchés Publics
Droit des Marchés Publics
Réglementation des Marchés Publics
CCAG des marchés publics
Délégation de service publics
Livres des Éditions du Moniteur
Contenu en ligne Editions du Moniteur
Batiprix.com
La BOX Gazette
Autres',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Si vous ne connaissez pas votre n° d\'abonné',
      'weight' => '42',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_user_abon_num
  $fields['batire_user_profile-field_user_abon_num'] = array(
    'field_name' => 'field_user_abon_num',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_abon_num][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Je suis déja utilisateur de produits et services du Groupe Moniteur (facultatif)',
      'weight' => '43',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_activity_prv
  $fields['batire_user_profile-field_user_activity_prv'] = array(
    'field_name' => 'field_user_activity_prv',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'allowed_values' => '562023 Activités immobilières|Activités immobilières
562080 Commerce|Commerce
562449 Construction|Construction
562565 Industrie|Industrie
563755 Services: Production et distribution d\'énergie|Services: Production et distribution d\'énergie
563771 Services: Captage, traitement et distribution d\'eau|Services: Captage, traitement et distribution d\'eau
563819 Services: Assurance|Services: Assurance
563833 Services: Activités financières|Services: Activités financières
563892 Services: Activités informatiques|Services: Activités informatiques
563928 Services: Recherche et développement|Services: Recherche et développement
563934 Services fournis principalement aux entreprises|Services fournis principalement aux entreprises
564050 Services: Assainissement, voirie et gestion des déchets|Services: Assainissement, voirie et gestion des déchets
563725 Autres Services|Autres Services
563727 Agriculture/Chasse/Sylviculture|Agriculture/Chasse/Sylviculture
27392023 Hôtels et restaurants|Hôtels et restaurants
27392054 Transports terrestres|Transports terrestres
27392077 Transports par eau|Transports par eau
27392084 Transports aériens|Transports aériens
27392091 Services auxiliaires des transports|Services auxiliaires des transports
27392114 Postes et télécommunications|Postes et télécommunications
564170 Activités récréatives, culturelles et sportives|Activités récréatives, culturelles et sportives
27392165 Services personnels|Services personnels
1055 Hébergement|Hébergement
1070 Services: Activités des sièges sociaux ; conseil de gestion|Services: Activités des sièges sociaux ; conseil de gestion
1071 Activités d\'architecture et d\'ingénierie ; activités de contrôle et analyses techniques|Activités d\'architecture et d\'ingénierie ; activités de contrôle et analyses techniques
1073 Publicité et études de marché|Publicité et études de marché
561962 Activités associatives|Activités associatives
561982 Education|Education',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Activité',
      'weight' => '11',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_user_activity_pub
  $fields['batire_user_profile-field_user_activity_pub'] = array(
    'field_name' => 'field_user_activity_pub',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'allowed_values' => '564873 ADEME|ADEME
564875 ANPE|ANPE
564877 Autres agences nationales (CNFPT, ANVAR...)|Autres agences nationales (CNFPT, ANVAR...)
564879 EDF, GDF|EDF, GDF
564881 EPIC|EPIC
564883 Etablissements publics d\'aménagement|Etablissements publics d\'aménagement
564885 France Télecom, PTT|France Télecom, PTT
564887 HLM|HLM
564889 SNCF, RATP et autres régies de transport|SNCF, RATP et autres régies de transport
564893 Collège|Collège
564895 Ecole|Ecole
564897 Education nationale (CIO, Rectorats...)|Education nationale (CIO, Rectorats...)
564899 Formation continue|Formation continue
564901 Lycée|Lycée
564903 Université|Université
564907 Ambassades, organismes internationaux|Ambassades, organismes internationaux
564913 Armée, gendarmerie|Armée, gendarmerie
564915 Ministères|Ministères
564917 Sénat, parlement|Sénat, parlement
564921 Administration judiciaire (cours et tribunaux, administration pénitentiaire)|Administration judiciaire
564923 Caisse dépôt|Caisse dépôt
564925 DDE|DDE
564927 Etablissements consulaires (CCI, chambre d\'agriculture...)|Etablissements consulaires (CCI, chambre d\'agriculture...)
564929 Finances, fiscalité, Chambre régionale des comptes, Perceptions trésorerie|Finances, fiscalité, Chambre régionale des comptes…
564931 Police, protection civile, pompiers|Police, protection civile, pompiers
564933 Ports, aéroports, service de la navigation|Ports, aéroports, service de la navigation
564935 Préfecture, sous-préfecture|Préfecture, sous-préfecture
564937 Recherche|Recherche
564939 SCET|SCET
564943 CAF|CAF
564945 CPAM|CPAM
564947 CRAM|CRAM
564949 CROUS|CROUS
564951 DDAS|DDAS
564959 CH|CH
564961 CHRS|CHRS
564963 CHU|CHU
564965 Hôpitaux locaux|Hôpitaux locaux
564969 Autres (foyer)|Autres (foyer)
564971 Enfance famille en difficulté|Enfance famille en difficulté
564973 Handicapés|Handicapés
564975 Personnes agées|Personnes agées
564981 Autres centres d\'action sociale (CTAS / ASE / CLICOS / CMS)|Autres centres d\'action sociale (CTAS / ASE / CLICOS / CMS)
564983 CCAS|CCAS
564985 CIAS|CIAS
564989 Bibliothèque municipale et départementale|Bibliothèque municipale et départementale
564991 Culture : MJC, conservatoires, musées, théatres|Culture : MJC, conservatoires, musées, théatres
564993 SEM|SEM
565001 SMIS|SMIS
565005 Conseil général|Conseil général
565009 Conseil régional|Conseil régional
565013 Autres syndicats (SIVR / SICOM)|Autres syndicats (SIVR / SICOM)
565015 Communauté d\'agglomération|Communauté d\'agglomération
565017 Communauté urbaines|Communauté urbaines
565019 Communautés de communes|Communautés de communes
565021 Districts|Districts
565023 Syndicat d\'agglomération nouvelle (SAN)|Syndicat d\'agglomération nouvelle (SAN)
565027 Mairies|Mairies',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Activité',
      'weight' => '10',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_user_address_1
  $fields['batire_user_profile-field_user_address_1'] = array(
    'field_name' => 'field_user_address_1',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_address_1][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Adresse',
      'weight' => '12',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_address_2
  $fields['batire_user_profile-field_user_address_2'] = array(
    'field_name' => 'field_user_address_2',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_address_2][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Adresse 2',
      'weight' => '13',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_city
  $fields['batire_user_profile-field_user_city'] = array(
    'field_name' => 'field_user_city',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_city][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Ville',
      'weight' => '15',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_company
  $fields['batire_user_profile-field_user_company'] = array(
    'field_name' => 'field_user_company',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_company][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Raison ',
      'weight' => '9',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_country
  $fields['batire_user_profile-field_user_country'] = array(
    'field_name' => 'field_user_country',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'allowed_values' => 'France
Allemagne
Autriche
Belgique
Bulgarie
Chypre
Danemark
Espagne
Estonie
Finlande
Hongrie
Irlande
Italie
Lettonie
Lituanie
Luxembourg
Malte
Pays-bas
Pologne
Portugal
Roumanie
Slovaquie
Slovénie
Suède
Tchèque, république
Afghanistan
Afrique du sud
Åland, îles
Albanie
Algérie
Andorre
Angola
Anguilla
Antarctique
Antigua-et-barbuda
Antilles néerlandaises
Arabie saoudite
Argentine
Arménie
Aruba
Australie
Azerbaïdjan
Bahamas
Bahreïn
Bangladesh
Barbade
Bélarus
Belize
Bénin
Bermudes
Bhoutan
Bolivie, l\'état plurinational de
Bosnie-herzégovine
Botswana
Bouvet, île
Brésil
Brunéi darussalam
Burkina faso
Burundi
Caïmanes, îles
Cambodge
Cameroun
Canada
Cap-vert
Centrafricaine, république
Chili
Chine
Christmas, île
Cocos (keeling), îles
Colombie
Comores
Congo
Congo, la république démocratique du
Cook, îles
Corée, république de
Corée, république populaire démocratique de
Costa rica
Côte d\'ivoire
Croatie
Cuba
Djibouti
Dominicaine, république
Dominique
Égypte
El salvador
Émirats arabes unis
Équateur
Érythrée
États-unis
Éthiopie
Falkland, îles (malvinas)
Féroé, îles
Fidji
Gabon
Gambie
Géorgie
Géorgie du sud et les îles sandwich du sud
Ghana
Gibraltar
Grèce
Grenade
Groenland
Guadeloupe
Guam
Guatemala
Guernesey
Guinée
Guinée équatoriale
Guinée-bissau
Guyana
Guyane française
Haïti
Heard, île et mcdonald, îles
Honduras
Hong-kong
Île de man
Îles mineures éloignées des états-unis
Îles vierges britanniques
Îles vierges des états-unis
Inde
Indonésie
Iran, république islamique d\'
Iraq
Islande
Israël
Jamaïque
Japon
Jersey
Jordanie
Kazakhstan
Kenya
Kirghizistan
Kiribati
Koweït
Lao, république démocratique populaire
Lesotho
Liban
Libéria
Libyenne, jamahiriya arabe
Liechtenstein
Macao
Macédoine, l\'ex-république yougoslave de
Madagascar
Malaisie
Malawi
Maldives
Mali
Mariannes du nord, îles
Maroc
Marshall, îles
Martinique
Maurice
Mauritanie
Mayotte
Mexique
Micronésie, états fédérés de
Moldova, république de
Monaco
Mongolie
Monténégro
Montserrat
Mozambique
Myanmar
Namibie
Nauru
Népal
Nicaragua
Niger
Nigéria
Niué
Norfolk, île
Norvège
Nouvelle-calédonie
Nouvelle-zélande
Océan indien, territoire britannique de l\'
Oman
Ouganda
Ouzbékistan
Pakistan
Palaos
Palestinien occupé, territoire
Panama
Papouasie-nouvelle-guinée
Paraguay
Pérou
Philippines
Pitcairn
Polynésie française
Porto rico
Qatar
Réunion
Royaume-uni
Russie, fédération de
Rwanda
Sahara occidental
Saint-barthélemy
Saint-kitts-et-nevis
Saint-marin
Saint-martin
Saint-pierre-et-miquelon
Saint-siège (état de la cité du vatican)
Saint-vincent-et-les grenadines
Sainte-hélène, ascension et tristan da cunha
Sainte-lucie
Salomon, îles
Samoa
Samoa américaines
Sao tomé-et-principe
Sénégal
Serbie
Seychelles
Sierra leone
Singapour
Somalie
Soudan
Sri lanka
Suisse
Suriname
Svalbard et île jan mayen
Swaziland
Syrienne, république arabe
Tadjikistan
Taïwan, province de chine
Tanzanie, république-unie de
Tchad
Terres australes françaises
Thaïlande
Timor-leste
Togo
Tokelau
Tonga
Trinité-et-tobago
Tunisie
Turkménistan
Turks et caïques, îles
Turquie
Tuvalu
Ukraine
Uruguay
Vanuatu
Venezuela, république bolivarienne du
Viet nam
Wallis et futuna
Yémen
Zambie
Zimbabwe',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Pays',
      'weight' => '16',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_user_dates
  $fields['batire_user_profile-field_user_dates'] = array(
    'field_name' => 'field_user_dates',
    'type_name' => 'batire_user_profile',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'datestamp',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => 'required',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'd/m/Y - H:i:s',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date d\'effet / d\'échéance',
      'weight' => '38',
      'description' => '',
      'type' => 'date_select',
      'module' => 'date',
    ),
  );

  // Exported field: field_user_email_format
  $fields['batire_user_profile-field_user_email_format'] = array(
    'field_name' => 'field_user_email_format',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'allowed_values' => 'html
texte',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 'html',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Format de réception des e-mails',
      'weight' => '39',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_user_fax
  $fields['batire_user_profile-field_user_fax'] = array(
    'field_name' => 'field_user_fax',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_fax][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Fax',
      'weight' => '36',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_gc_stat_permissions
  $fields['batire_user_profile-field_user_gc_stat_permissions'] = array(
    'field_name' => 'field_user_gc_stat_permissions',
    'type_name' => 'batire_user_profile',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_gc_stat_permissions][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'GC Statistics permissions',
      'weight' => '53',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_last_login_date
  $fields['batire_user_profile-field_user_last_login_date'] = array(
    'field_name' => 'field_user_last_login_date',
    'type_name' => 'batire_user_profile',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'datestamp',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
      'second' => 'second',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Last login date',
      'weight' => '47',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_user_login_date
  $fields['batire_user_profile-field_user_login_date'] = array(
    'field_name' => 'field_user_login_date',
    'type_name' => 'batire_user_profile',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'datestamp',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
      'second' => 'second',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Login date',
      'weight' => '48',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_user_name
  $fields['batire_user_profile-field_user_name'] = array(
    'field_name' => 'field_user_name',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Prénom',
      'weight' => '32',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_opt_1
  $fields['batire_user_profile-field_user_opt_1'] = array(
    'field_name' => 'field_user_opt_1',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'multiple' => '1',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '1|J\'autorise le Groupe Moniteur (co-éditeur du site KHEOX), à conserver mes coordonnées afin de m\'envoyer des informations à caractère professionnel.',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '1',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'J\'autorise le Groupe Moniteur',
      'weight' => '45',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_user_opt_2
  $fields['batire_user_profile-field_user_opt_2'] = array(
    'field_name' => 'field_user_opt_2',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'multiple' => '1',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '1|J\'accepte que le Groupe Moniteur transmette à ses partenaires les données que je vous ai transmises.',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '1',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'J\'accepte que le Groupe Moniteur',
      'weight' => '46',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_user_origene
  $fields['batire_user_profile-field_user_origene'] = array(
    'field_name' => 'field_user_origene',
    'type_name' => 'batire_user_profile',
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
      'rows' => 5,
      'size' => '10',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_origene][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Type utilisateur',
      'weight' => '55',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_position
  $fields['batire_user_profile-field_user_position'] = array(
    'field_name' => 'field_user_position',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'allowed_values' => '564426 Administration générale/Direction générale|Administration générale/Direction générale
564696 Secrétaire général|Secrétaire général
564716 Directeur de cabinet|Directeur de cabinet
564718 Directeur des marchés|Directeur des marchés
564720 Responsable des marchés|Responsable des marchés
564444 Commercial, ventes|Commercial, ventes
564732 Directeur bureau d\'études|Directeur bureau d\'études
564734 Acousticien|Acousticien
564736 Architecte|Architecte
564738 Architecte intérieur, scénographe|Architecte intérieur, scénographe
564740 Cartographe, géomètre, topographe, géologue, hydrolicien|Cartographe, géomètre, topographe, géologue, hydrolicien
564742 Dessinateur, calculateur, projeteur, métreur|Dessinateur, calculateur, projeteur, métreur
564744 Economiste de la construction|Economiste de la construction
564746 Etudes de prix|Etudes de prix
564748 Expert en bâtiment|Expert en bâtiment
564750 Ingénieur méthode / ingénieur d\'études|Ingénieur méthode / ingénieur d\'études
564752 Paysagiste|Paysagiste
564754 Responsable / chargé d\'études|Responsable / chargé d\'études
564756 Urbaniste|Urbaniste
564758 Directeur prescription|Directeur prescription
628421946 Responsable maintenance|Responsable maintenance
628421947 Directeur financier|Directeur financier
564778 Avocat|Avocat
564780 Conseiller juridique|Conseiller juridique
564782 Directeur juridique|Directeur juridique
564784 Notaire|Notaire
564786 Directeur informatique|Directeur informatique
564788 Directeur des achats|Directeur des achats
564790 Responsable des achats|Responsable des achats
564792 Technicien de maintenance|Technicien de maintenance
628421948 Directeur Qualité|Directeur Qualité
628421949 Responsable hygiène et sécurité|Responsable hygiène et sécurité
564794 Directeur marketing|Directeur marketing
628421950 Directeur communication|Directeur communication
628421951 Directeur relations extérieur|Directeur relations extérieur
564808 Responsable de programmes|Responsable de programmes
564810 Responsable de projets|Responsable de projets
564812 Responsable foncier|Responsable foncier
564796 Administrateur de biens|Administrateur de biens
564798 Agent immobilier|Agent immobilier
564800 Directeur immobilier|Directeur immobilier
564802 Monteur de projets|Monteur de projets
564804 Prospecteur foncier|Prospecteur foncier
564806 Responsable d\'opérations|Responsable d\'opérations
564814 Directeur des ressources humaines|Directeur des ressources humaines
564816 Responsable du recrutement|Responsable du recrutement
628421952 Directeur formation|Directeur formation
628421953 Directeur/Responsable environnement/développement durable|Directeur/Responsable environnement/développement durable
564818 Greffiers|Greffiers
564820 Juge|Juge
564822 Directeur technique|Directeur technique
564824 Responsable technique|Responsable technique
628421954 Responsable services généraux|Responsable services généraux
628421955 Directeur opération/exploitation|Directeur opération/exploitation',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Fonction',
      'weight' => '37',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_user_posts_count
  $fields['batire_user_profile-field_user_posts_count'] = array(
    'field_name' => 'field_user_posts_count',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'allowed_values' => '1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
25+',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Nb de postes supplémentaires',
      'weight' => '44',
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_user_products
  $fields['batire_user_profile-field_user_products'] = array(
    'field_name' => 'field_user_products',
    'type_name' => 'batire_user_profile',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'batire_product_module_1_2' => 'batire_product_module_1_2',
      'batire_product_module_3' => 'batire_product_module_3',
      'batire_5_advices' => 0,
      'batire_actualite' => 0,
      'batire_user_sent_alert' => 0,
      'batire_commercial_animation' => 0,
      'batire_user_annotation' => 0,
      'batire_auteur' => 0,
      'batire_feuillet_mobile' => 0,
      'batire_codes' => 0,
      'batire_complement_technique' => 0,
      'batire_document_pratique' => 0,
      'batire_user_folder' => 0,
      'faq' => 0,
      'batire_homepage_blocks' => 0,
      'batire_livres' => 0,
      'page' => 0,
      'batire_page_not_found' => 0,
      'batire_user_profile' => 0,
      'batire_user_search_profile' => 0,
      'profile' => 0,
      'story' => 0,
      'batire_from_lemoniteur' => 0,
      'batire_texte_normatifs' => 0,
      'batire_texte_officiel' => 0,
      'batire_last_documents' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Produit',
      'weight' => '54',
      'description' => '',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_user_promo
  $fields['batire_user_profile-field_user_promo'] = array(
    'field_name' => 'field_user_promo',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_promo][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Code Privilège',
      'weight' => '40',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_salut
  $fields['batire_user_profile-field_user_salut'] = array(
    'field_name' => 'field_user_salut',
    'type_name' => 'batire_user_profile',
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
    'allowed_values' => 'Monsieur
Madame
Mademoiselle',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Civilité',
      'weight' => '31',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_user_specialty
  $fields['batire_user_profile-field_user_specialty'] = array(
    'field_name' => 'field_user_specialty',
    'type_name' => 'batire_user_profile',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_specialty][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Spécialité',
      'weight' => '38',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_statut
  $fields['batire_user_profile-field_user_statut'] = array(
    'field_name' => 'field_user_statut',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'allowed_values' => '0|Secteur privé
1|Secteur public',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Statut',
      'weight' => '8',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_user_subacc
  $fields['batire_user_profile-field_user_subacc'] = array(
    'field_name' => 'field_user_subacc',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'userreference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'userreference',
    'active' => '1',
    'referenceable_roles' => array(
      '6' => 6,
      '2' => 0,
      '8' => 0,
      '11' => 0,
      '9' => 0,
      '12' => 0,
      '5' => 0,
      '4' => 0,
    ),
    'referenceable_status' => '',
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'reverse_link' => 0,
      'default_value' => array(
        '0' => array(
          'uid' => NULL,
          '_error_element' => 'default_value_widget][field_user_subacc][0][uid][uid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Compte secondaires',
      'weight' => '41',
      'description' => '',
      'type' => 'userreference_autocomplete',
      'module' => 'userreference',
    ),
  );

  // Exported field: field_user_surname
  $fields['batire_user_profile-field_user_surname'] = array(
    'field_name' => 'field_user_surname',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_surname][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Nom',
      'weight' => '33',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_tel_1
  $fields['batire_user_profile-field_user_tel_1'] = array(
    'field_name' => 'field_user_tel_1',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_tel_1][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Téléphone',
      'weight' => '34',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_tel_2
  $fields['batire_user_profile-field_user_tel_2'] = array(
    'field_name' => 'field_user_tel_2',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_tel_2][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'autre n° (facultatif)',
      'weight' => '35',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_tva
  $fields['batire_user_profile-field_user_tva'] = array(
    'field_name' => 'field_user_tva',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_tva][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'T.V.A',
      'weight' => '17',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_user_zip
  $fields['batire_user_profile-field_user_zip'] = array(
    'field_name' => 'field_user_zip',
    'type_name' => 'batire_user_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_user_zip][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Code postal',
      'weight' => '14',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_alert_document
  $fields['batire_user_search_profile-field_alert_document'] = array(
    'field_name' => 'field_alert_document',
    'type_name' => 'batire_user_search_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'batire_actualite' => 'batire_actualite',
      'batire_codes' => 'batire_codes',
      'batire_complement_technique' => 'batire_complement_technique',
      'batire_document_pratique' => 'batire_document_pratique',
      'batire_feuillet_mobile' => 'batire_feuillet_mobile',
      'batire_livres' => 'batire_livres',
      'batire_user_search_profile' => 'batire_user_search_profile',
      'batire_texte_normatifs' => 'batire_texte_normatifs',
      'batire_texte_officiel' => 'batire_texte_officiel',
      'batire_5_advices' => 0,
      'batire_user_sent_alert' => 0,
      'batire_commercial_animation' => 0,
      'batire_user_annotation' => 0,
      'batire_auteur' => 0,
      'batire_user_folder' => 0,
      'faq' => 0,
      'batire_homepage_blocks' => 0,
      'page' => 0,
      'batire_page_not_found' => 0,
      'batire_user_profile' => 0,
      'profile' => 0,
      'story' => 0,
      'batire_from_lemoniteur' => 0,
      'batire_last_documents' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_alert_document][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Alerte document',
      'weight' => '-1',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_alert_period
  $fields['batire_user_search_profile-field_alert_period'] = array(
    'field_name' => 'field_alert_period',
    'type_name' => 'batire_user_search_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'allowed_values' => '0|Quotidienne
1|Hebdomadaire
2|Mensuelle',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Périodicité',
      'weight' => 0,
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_alert_period_month
  $fields['batire_user_search_profile-field_alert_period_month'] = array(
    'field_name' => 'field_alert_period_month',
    'type_name' => 'batire_user_search_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'allowed_values' => '0|1er du mois
1|10 du mois
2|20 du mois',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Périodicité mensuelle',
      'weight' => '2',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_alert_period_week
  $fields['batire_user_search_profile-field_alert_period_week'] = array(
    'field_name' => 'field_alert_period_week',
    'type_name' => 'batire_user_search_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'allowed_values' => '0|Lundi
1|Mardi
2|Mercredi
3|Jeudi
4|Vendredi',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Périodicité hebdomadaire',
      'weight' => '1',
      'description' => '',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_last_run
  $fields['batire_user_search_profile-field_last_run'] = array(
    'field_name' => 'field_last_run',
    'type_name' => 'batire_user_search_profile',
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
    'type' => 'datestamp',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'Y-m-d H:i:s',
      'input_format_custom' => '',
      'increment' => 1,
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Last Run Date',
      'weight' => '31',
      'description' => '',
      'type' => 'date_text',
      'module' => 'date',
    ),
  );

  // Exported field: field_profile_type
  $fields['batire_user_search_profile-field_profile_type'] = array(
    'field_name' => 'field_profile_type',
    'type_name' => 'batire_user_search_profile',
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
    'allowed_values' => '0|search
1|search alert
2|document alert',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '0',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Profile type',
      'weight' => 0,
      'description' => '',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_search_id
  $fields['batire_user_search_profile-field_search_id'] = array(
    'field_name' => 'field_search_id',
    'type_name' => 'batire_user_search_profile',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_search_id][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Search id',
      'weight' => '10',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_search_new
  $fields['batire_user_search_profile-field_search_new'] = array(
    'field_name' => 'field_search_new',
    'type_name' => 'batire_user_search_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_search_new][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Number of new items since last search',
      'weight' => '-2',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_search_total
  $fields['batire_user_search_profile-field_search_total'] = array(
    'field_name' => 'field_search_total',
    'type_name' => 'batire_user_search_profile',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
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
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_search_total][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Number of found items',
      'weight' => '-3',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_sent_alert_alert
  $fields['batire_user_sent_alert-field_sent_alert_alert'] = array(
    'field_name' => 'field_sent_alert_alert',
    'type_name' => 'batire_user_sent_alert',
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
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'batire_user_search_profile' => 'batire_user_search_profile',
      'batire_5_advices' => 0,
      'batire_actualite' => 0,
      'batire_user_sent_alert' => 0,
      'batire_commercial_animation' => 0,
      'batire_user_annotation' => 0,
      'batire_auteur' => 0,
      'batire_codes' => 0,
      'batire_complement_technique' => 0,
      'batire_document_pratique' => 0,
      'batire_user_folder' => 0,
      'faq' => 0,
      'batire_feuillet_mobile' => 0,
      'batire_homepage_blocks' => 0,
      'batire_livres' => 0,
      'page' => 0,
      'batire_page_not_found' => 0,
      'batire_user_profile' => 0,
      'profile' => 0,
      'story' => 0,
      'batire_from_lemoniteur' => 0,
      'batire_texte_normatifs' => 0,
      'batire_texte_officiel' => 0,
      'batire_last_documents' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
          '_error_element' => 'default_value_widget][field_sent_alert_alert][0][nid][nid',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Associated alert',
      'weight' => '-4',
      'description' => '',
      'type' => 'nodereference_autocomplete',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_sent_alert_new
  $fields['batire_user_sent_alert-field_sent_alert_new'] = array(
    'field_name' => 'field_sent_alert_new',
    'type_name' => 'batire_user_sent_alert',
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
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_sent_alert_new][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Number of new items since last search',
      'weight' => '-3',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_sent_alert_sid
  $fields['batire_user_sent_alert-field_sent_alert_sid'] = array(
    'field_name' => 'field_sent_alert_sid',
    'type_name' => 'batire_user_sent_alert',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_sent_alert_sid][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Search id',
      'weight' => '6',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_sent_alert_total
  $fields['batire_user_sent_alert-field_sent_alert_total'] = array(
    'field_name' => 'field_sent_alert_total',
    'type_name' => 'batire_user_sent_alert',
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
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_sent_alert_total][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Number of found items',
      'weight' => '-2',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('# de référence');
  t('# de référence des autres parties du texte normatif consulté');
  t('# de référence du texte normatif remplacé');
  t('Activité');
  t('Adresse');
  t('Adresse 2');
  t('Afficher pour les non-abonnés');
  t('Alerte document');
  t('Associated alert');
  t('Auteurs(s)');
  t('BID');
  t('Bio');
  t('Cites');
  t('Civilité');
  t('Code');
  t('Code Privilège');
  t('Code postal');
  t('Collection');
  t('Compte secondaires');
  t('Contenu');
  t('Date');
  t('Date Vide');
  t('Date d\'effet / d\'échéance');
  t('Date de import');
  t('Date de la version en viguer');
  t('Date de parution');
  t('Date de publication');
  t('Date de publication de la norme remplacée');
  t('Date d’actualisation');
  t('Date d’annulation');
  t('Date initiale');
  t('Default search profile');
  t('Document');
  t('Documents');
  t('Dossier parent');
  t('Fax');
  t('Fonction');
  t('Format de réception des e-mails');
  t('GC Statistics permissions');
  t('Illustrateur(s) consulté');
  t('Image');
  t('Indice de classement');
  t('Indice de classement du texte normatif remplacé');
  t('J\'accepte que le Groupe Moniteur');
  t('J\'autorise le Groupe Moniteur');
  t('Je suis déja utilisateur de produits et services du Groupe Moniteur (facultatif)');
  t('Last Run Date');
  t('Last login date');
  t('Lien');
  t('Login date');
  t('Mention JORF');
  t('Mention boutique Afnor');
  t('Nb de postes supplémentaires');
  t('New docs counter');
  t('New docs flag');
  t('Nom');
  t('Notice détailleé');
  t('Number of found items');
  t('Number of new items since last search');
  t('Numero NOR');
  t('Numérotation du document');
  t('N° de la partie');
  t('N° de la section ou de la partie');
  t('N° de parution');
  t('N° d’article du code');
  t('N° et titre de l\'intercalaire ou de la partie');
  t('N° et titre du sous-intercalaire');
  t('Onglet catégorie');
  t('Onglet référence');
  t('Partager');
  t('Pays');
  t('Produit');
  t('Profile type');
  t('Prénom');
  t('Périodicité');
  t('Périodicité hebdomadaire');
  t('Périodicité mensuelle');
  t('Raison ');
  t('Rubrique');
  t('Résumé');
  t('Search id');
  t('Si vous ne connaissez pas votre n° d\'abonné');
  t('Signatures');
  t('Sous-rubrique');
  t('Soustitre');
  t('Spécialité');
  t('Statut');
  t('Statut juridique');
  t('Subscribed to newsletter');
  t('Subtitle');
  t('Surtitre');
  t('T.V.A');
  t('Texte fondamental');
  t('Titre de la partie');
  t('Titre de la section ou de la partie');
  t('Titre du document ligne 3');
  t('Titre du document linge 1');
  t('Type utilisateur');
  t('Téléphone');
  t('Ville');
  t('Visas');
  t('autre n° (facultatif)');
  t('Сoordinateur éditorial');

  return $fields;
}

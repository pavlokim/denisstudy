<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function batire_content_types_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_my_company
  $groups['batire_user_profile-group_my_company'] = array(
    'group_type' => 'standard',
    'type_name' => 'batire_user_profile',
    'group_name' => 'group_my_company',
    'label' => 'Mon entreprise/Organisme',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '1',
    'fields' => array(
      '0' => 'field_user_statut',
      '1' => 'field_user_company',
      '2' => 'field_user_activity_pub',
      '3' => 'field_user_activity_prv',
      '4' => 'field_user_address_1',
      '5' => 'field_user_address_2',
      '6' => 'field_user_zip',
      '7' => 'field_user_city',
      '8' => 'field_user_country',
      '9' => 'field_user_tva',
    ),
  );

  // Exported group: group_my_details
  $groups['batire_user_profile-group_my_details'] = array(
    'group_type' => 'standard',
    'type_name' => 'batire_user_profile',
    'group_name' => 'group_my_details',
    'label' => 'Mes coordonnées',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '0',
    'fields' => array(
      '0' => 'field_user_salut',
      '1' => 'field_user_name',
      '2' => 'field_user_surname',
      '3' => 'field_user_tel_1',
      '4' => 'field_user_tel_2',
      '5' => 'field_user_fax',
      '6' => 'field_user_position',
      '7' => 'field_user_specialty',
    ),
  );

  // Exported group: group_other
  $groups['batire_user_profile-group_other'] = array(
    'group_type' => 'standard',
    'type_name' => 'batire_user_profile',
    'group_name' => 'group_other',
    'label' => 'Other system fields',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '2',
    'fields' => array(
      '0' => 'field_user_dates',
      '1' => 'field_user_email_format',
      '2' => 'field_user_promo',
      '3' => 'field_user_subacc',
      '4' => 'field_user_abon_list',
      '5' => 'field_user_abon_num',
      '6' => 'field_user_posts_count',
      '7' => 'field_user_opt_1',
      '8' => 'field_user_opt_2',
      '9' => 'field_user_last_login_date',
      '10' => 'field_user_login_date',
      '11' => 'field_default_search',
      '12' => 'field_new_docs_flag',
      '13' => 'field_new_docs_cnt',
      '14' => 'field_subscribed_to_newsletter',
      '15' => 'field_user_gc_stat_permissions',
      '16' => 'field_user_products',
      '17' => 'field_user_origene',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Mes coordonnées');
  t('Mon entreprise/Organisme');
  t('Other system fields');

  return $groups;
}

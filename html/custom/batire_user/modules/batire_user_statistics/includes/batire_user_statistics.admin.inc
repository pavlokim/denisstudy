<?php

/**
 * @file
 *  batire_user_statistics.admin.inc
 * User statistics settings for site
 */

/**
 * Show list of available statistics reports
 */
function batire_user_statistics_application_list() {
  $avail_months = batire_user_statistics_application_get_avail_months();
  if (!$avail_months) {
    return t('No statistics available');
  }
  $data = array();
  $i = 0;

  $roles = batire_user_statistics_application_get_avail_roles();
  $sql = 'SELECT COUNT(*)
    FROM (
      SELECT *, GROUP_CONCAT(ur.rid) roles FROM {users_roles} ur WHERE ur.rid IN (' . db_placeholders($roles, 'int') . ') GROUP BY uid
    ) ua
    JOIN {users} u ON u.uid = ua.uid
    WHERE u.uid NOT IN (0,1) AND u.created <= %d';

  foreach ($avail_months as $key => $date) {
    $month = (int) substr($key, 4);
    $year = (int) substr($key, 0, 4);
    $to = mktime(0, 0, 0, $month + 1, 1, $year);
    $i++;
    $args = array_merge($roles, array($to));
    $data[] = array(
      $i,
      (int) db_result(db_query($sql, $args)),
      l($date, 'admin/batire-site/users/statistics/statistics-application/get/' . $key),
      BATIRE_STATISTIC_FILE_TYPE == 'csv' ? l($date, 'admin/batire-site/users/statistics/statistics-application/get-history/' . $key) :'',
    );
  }
  $header = array(
    array('data' => '#', 'width' => 70),
    array('data' => t('# of users'), 'width' => 70),
    array('data' => t('Statistics')),
    BATIRE_STATISTIC_FILE_TYPE == 'csv' ? array('data' => t('History')) : array(),
  );
  return theme('table', $header, $data);
}
/*
 * handler of sessions logs
 */
function batire_user_statistics_application_build_session_logs_list($start_date = NULL, $end_date = NULL) {
  if (isset($start_date) && isset($end_date)) {
    drupal_add_js(drupal_get_path('module', 'batire_gc_commercial') . '/scripts/gc_users_table.js', 'module', 'footer');
    drupal_add_css(drupal_get_path('module', 'batire_gc_commercial') . '/styles/gc_users_table.css');
    $header = array(
      t('Date of creating'),
      t('Max size of session (Kb)'),
      t('User ID with the largest session'),
      t('User Name with the largest session'),
      t('The number of sessions'),
    );
    $mongo_query = array(
      'access' => array('$gte' => (int) strtotime($start_date), '$lte' => (int) strtotime($end_date)),
    );
    $mongo_result = mongodb_select(MONGODB_USER_SESSIONS_COUNTS, $mongo_query);
    $rows = array();
    foreach ($mongo_result as $record) {
      $profile = batire_user_profile_load($record['uid_max_session']);
      $user_full_name = $profile->field_user_name[0]['value'] . ' ' . $profile->field_user_surname[0]['value'];
      $rows[] = array(
        'data' => array(
          date('Y-m-d H:i:s', $record['access']),
          $record['max_session_size'],
          $record['uid_max_session'],
          $user_full_name,
          $record['sessions_count'],
        ),
        'class' => 'gc-abo-admin-row',
      );
    }

    return theme('table', $header, $rows);
  }
  return drupal_get_form('batire_user_statistics_application_build_session_logs_form');
}

/**
 * Form of building sessions logs by range
 */
function batire_user_statistics_application_build_session_logs_form() {
  $form = array();

  $form['start_date'] = array(
    '#title' => t('Select start date'),
    '#type' => 'date_popup',
    '#date_format' => 'Y-m-d H:i:s',
    '#date_year_range' => '-5:+1',
    '#default_value' => date('Y').'-'.date('m').'-1',
    '#required' => TRUE,
  );
  $form['end_date'] = array(
    '#title' => t('Select end date'),
    '#type' => 'date_popup',
    '#date_format' => 'Y-m-d H:i:s',
    '#date_year_range' => '-5:+1',
    '#default_value' => date('Y-m-d'),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Build')
  );
  return $form;
}

function batire_user_statistics_application_build_session_logs_form_submit($form, &$form_state) {
  drupal_goto('admin/batire-site/users/statistics/statistics-application/build-sessions-logs/' . $form_state['values']['start_date'] . '/' .$form_state['values']['end_date']);
}

/*
 * handler of viewed documents logs
 */
function batire_user_statistics_application_build_viewed_docs_list($start_date = NULL, $end_date = NULL) {
  if (isset($start_date) && isset($end_date)) {
    drupal_add_js(drupal_get_path('module', 'batire_gc_commercial') . '/scripts/gc_users_table.js', 'module', 'footer');
    drupal_add_css(drupal_get_path('module', 'batire_gc_commercial') . '/styles/gc_users_table.css');
    $header = array(
      t('Date of creating'),
    );
    $members_header = array(
      t('User name'),
      t('Viewed documents'),
    );
    $mongo_query = array(
      'access' => array('$gte' => (int) strtotime($start_date), '$lte' => (int) strtotime($end_date)),
    );
    $mongo_result = mongodb_select(MONGODB_USER_VIEWED_DOCUMENTS_COUNTS, $mongo_query);
    $rows = array();
    foreach ($mongo_result as $record) {
      $members_rows = array();
      foreach ($record['data'] as $member) {
          $profile = batire_user_profile_load($member['uid']);
          $user_full_name = $profile->field_user_name[0]['value'] . ' ' . $profile->field_user_surname[0]['value'];
          if ($member['uid'] == 0) {
            $user_full_name = 'anonymous';
          }
          elseif ($member['uid'] == 1) {
            $user_full_name = 'admin';
          }
          $members_rows[] = array('data' => array(
            $user_full_name,
            $member['viewed_documents_count'],
          ),
            'class' => 'gc-abo-subacc-row',
          );
      }
      $rows[] = array(
        'data' => array(
          l(date('Y-m-d H:i:s', $record['access']), 'admin/batire-site/users/statistics/statistics-application/build-viewed_docs-logs', array('attributes' => array('class' => 'gc-collapse', 'id' => 'gc-collapse-' . $record['access'])))
        ),
        'class' => 'gc-abo-admin-row'
      );
      if (!empty($members_rows)) {
        $rows[] = array('data' => array(array('data' => theme('table', $members_header, $members_rows), 'colspan' => count($header))), 'class' => 'gc-abo-subacc-toprow gc-collapsible gc-collapsible-' . $record['access']);
      }
    }
    return l('Expand all', 'admin/batire-site/users/statistics/statistics-application/build-viewed_docs-logs', array('attributes' => array('class' => 'gc-collapse-all'))) . theme('table', $header, $rows);
  }
  return drupal_get_form('batire_user_statistics_application_build_viewed_docs_form');
}

/**
 * Form of building sessions logs by range
 */
function batire_user_statistics_application_build_viewed_docs_form() {
  $form = array();

  $form['start_date'] = array(
    '#title' => t('Select start date'),
    '#type' => 'date_popup',
    '#date_format' => 'Y-m-d H:i:s',
    '#date_year_range' => '-5:+1',
    '#default_value' => date('Y').'-'.date('m').'-1',
    '#required' => TRUE,
  );
  $form['end_date'] = array(
    '#title' => t('Select end date'),
    '#type' => 'date_popup',
    '#date_format' => 'Y-m-d H:i:s',
    '#date_year_range' => '-5:+1',
    '#default_value' => date('Y-m-d'),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Build')
  );
  return $form;
}

function batire_user_statistics_application_build_viewed_docs_form_submit($form, &$form_state) {
  drupal_goto('admin/batire-site/users/statistics/statistics-application/build-viewed_docs-logs/' . $form_state['values']['start_date'] . '/' .$form_state['values']['end_date']);
}
/**
 * Rebuild form
 *
 * @ingroup forms
 * @see batire_user_statistics_application_rebuild_form_validate()
 * @see batire_user_statistics_application_rebuild_form_submit()
 */
function batire_user_statistics_application_rebuild_form() {
  $form = array();

  $months = batire_user_statistics_application_get_avail_months();
  $form['date'] = array(
    '#title' => t('Select date period'),
    '#type' => 'select',
    '#options' => $months,
    '#required' => TRUE
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Rebuild')
  );
  return $form;
}

/**
 * Rebuild form validation
 * @see batire_user_statistics_application_rebuild_form()
 */
function batire_user_statistics_application_rebuild_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  $date = $values['date'];

  $avail_months = batire_user_statistics_application_get_avail_months();
  if (!array_key_exists($date, $avail_months)) {
    form_set_error('date', t('Invalid date value'));
  }
}

/**
 * Submit for rebuild form
 * @see batire_user_statistics_application_rebuild_form()
 */
function batire_user_statistics_application_rebuild_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $date = (int) $values['date'];
  batire_user_statistics_application_create($date, TRUE, FALSE, BATIRE_STATISTIC_FILE_TYPE);
  if (BATIRE_STATISTIC_FILE_TYPE == 'csv') {
    batire_user_statistics_application_create($date, TRUE, FALSE, BATIRE_STATISTIC_FILE_TYPE, TRUE);
  }
}

/**
 * Rebuild stats by range form
 *
 * @ingroup forms
 * @see batire_user_statistics_application_build_form_validate()
 * @see batire_user_statistics_application_build_form_submit()
 */
function batire_user_statistics_application_build_range_form() {
  $form = array();

  $form['start_date'] = array(
    '#title' => t('Select start date'),
    '#type' => 'date_popup',
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-5:+1',
    '#default_value' => date('Y').'-'.date('m').'-1',
    '#required' => TRUE,
  );
  $form['end_date'] = array(
    '#title' => t('Select end date'),
    '#type' => 'date_popup',
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-5:+1',
    '#default_value' => date('Y-m-d'),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Build')
  );
  return $form;
}

/**
 * Build stats by range form validation
 * @see batire_user_statistics_application_build_form()
 */
function batire_user_statistics_application_build_range_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  $start_date = strtotime($values['start_date']);
  $end_date = strtotime($values['end_date']);
  if ($start_date >= $end_date) {
    form_set_error('start_date', t('Start date must be earlier than end date'));
    form_set_error('end_date', t('End date must be later than start date'));
  }
}

/**
 * Submit for build stats by range form
 * @see batire_user_statistics_application_rebuild_form()
 */
function batire_user_statistics_application_build_range_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $start_date = strtotime($values['start_date']);
  $end_date = strtotime($values['end_date']);
  $filepath = batire_user_statistics_application_create_period($start_date, $end_date, array(), TRUE);
  if ($filepath) {
    file_transfer($filepath, batire_site_get_file_headers('Kheox_' . date('dmy', $start_date) . '_au_' . date('dmy', $end_date)));
  }
  else {
    drupal_set_message(t('No statistics data available for given period.'));
  }
}

/**
 * Download page of guest list file
 */
function batire_user_statistics_application_guest_list() {
  return l(t('Télécharger des invitations'), 'admin/batire-site/users/statistics/statistics-application/get-guests-list');
}

/**
 * Download page of guest list file
 */
function batire_user_statistics_application_requests_list() {

  $form = drupal_get_form('batire_user_statistics_application_requests_list_form');
  return $form;
}

/**
 * Request list download file settings form
 */
function batire_user_statistics_application_requests_list_form() {
  $form = array();

  $form['batire_user_statistics_request_users_type_filter'] = array(
    '#title' => t('Select users type'),
    '#type' => 'select',
    '#options' => array(
      BATIRE_USER_REG_TYPE_PAID => t('Paid'),
      BATIRE_USER_REG_TYPE_DAD => t('Dad'),
    ),
    '#default_value' => variable_get('batire_user_statistics_request_users_type_filter', BATIRE_USER_REG_TYPE_PAID),
    '#required' => TRUE
  );

  $form['date_filter'] = array(
    '#type' => 'fieldset',
  );
  $form['date_filter']['batire_user_statistics_date_from'] = array(
    '#type' => 'date_popup',
    '#title' => t('Du'),
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-1:+1',
    '#default_value' => variable_get('batire_user_statistics_date_from', NULL),
    '#required' => TRUE
  );

  $form['date_filter']['batire_user_statistics_date_to'] = array(
    '#type' => 'date_popup',
    '#title' => t('Au'),
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-1:+1',
    '#default_value' => variable_get('batire_user_statistics_date_to', NULL),
    '#required' => TRUE
  );

  $min_date = mktime(0, 0, 0, 1, 1, 2011);
  $min_date = ceil((time() - $min_date) / (24 * 60 * 60));

  drupal_add_js(drupal_get_path('module', 'batire_user_statistics') . '/scripts/statistics.js');
  $settings = array(
    'datePopup' => array(
      'edit-batire-user-statistics-date-from-datepicker-popup-0' => array(
        'settings' => array(
          'maxDate' => '',
          'minDate' => '-' . $min_date,
        )
      ),
      'edit-batire-user-statistics-date-to-datepicker-popup-0' => array(
        'settings' => array(
          'maxDate' => '',
          'minDate' => '-' . $min_date,
        )
      )
    )
  );
  drupal_add_js($settings, 'setting');


  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Télécharger des prospects'),
  );
  $form['#submit'][] = 'batire_user_statistics_application_requests_list_form_submit';
  return system_settings_form($form);
}

function batire_user_statistics_application_settings() {
  $form = array();
  $form['file_format'] = array(
    '#type'         => 'fieldset',
    '#title'        => t('Output settings'),
    '#weight'       => 0
  );
  $options = array('xls' => 'Excel', 'csv' => 'CSV');
  $form['file_format']['batire_statistic_file_type'] = array(
    '#type' => 'radios',
    '#title' => t('Types of files'),
    '#description' => t('If checked, subsites advanced search form will be rebuilt.'),
    '#options' => $options,
    '#default_value' => BATIRE_STATISTIC_FILE_TYPE,
  );
  return system_settings_form($form);
}
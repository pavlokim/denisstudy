<?php

/**
 * @file
 * Pages callbacks for the module
 */

/**
 * Callback for log in functionality
 */
function batire_user_logout() {
  global $user;
  if (!$user->uid) {
    drupal_goto();
  }

  module_load_include('pages.inc', 'user');
  return user_logout();
}

/**
 * Login popup callback
 */
function batire_user_popup_js() {
  global $user;

  $result = array(
    'error' => FALSE,
    'data' => NULL,
  );

  if (isset($_POST) && $_POST) {
    if (isset($_POST['name']) && $_POST['name'] && isset($_POST['pass']) && $_POST['pass'] && isset($_POST['remember_me'])) {
      //Cleaning data
      $_POST['name'] = trim($_POST['name']);
      $_POST['pass'] = trim($_POST['pass']);

      $form_state['values']['name'] = $_POST['name'];
      $form_state['values']['pass'] = $_POST['pass'];
      $form_state['values']['remember_me'] = $_POST['remember_me'];

      _batire_user_user_login_validate(array(), $form_state);

      $errors = form_get_errors();
      if (isset($errors['name']) && $errors['name']) {
        $result['error'] = TRUE;
        $result['data'] = $errors['name'];
        $_SESSION['batire_user']['popup_login_form_error'] = $errors['name'];
      }
      else {
        _batire_user_user_login_submit(array(), $form_state);
        //Clean up errors
        form_get_errors();
        drupal_get_messages();
      }
    }
    if (!isset($_SERVER['HTTP_X_REQUESTED_WITH']) || $_SERVER['HTTP_X_REQUESTED_WITH'] !== 'XMLHttpRequest') {
      if(!empty($_POST['destination'])){
        $url = parse_url($_POST['destination']);
        if(is_array($url) && strlen($url['path']) > 0){
          $url['path'] = substr($url['path'],1);
          drupal_goto($url['path'], $url['query']);
        }else{
          drupal_goto('home');
        }
      }else{
        drupal_goto('home');
      }
      return TRUE;
    }
  }
  else {
    // Get popup form
    if ($user->uid > 0) {
      $result['error'] = TRUE;
      $result['data'] = t(
      'Vos identifiants ne vous donnent pas accès à !site_name.
         Nous vous invitons à nous contacter en !link.', array('!link' => batire_site_contact_link(), '!site_name' => SITE_NAME_FS)
      );
    }
    else {
      $result['data'] = theme('batire_user_popup_login_content');
    }
  }

  drupal_get_messages();
  drupal_json($result);
  return NULL;
}

/**
 * Recovery password
 */
function batire_user_recovery_password_js() {
  global $user;
  $message = array(
    'status' => 0,
    'message' => '',
    'validate' => 0,
  );
  try {
    // validate email
    $email = drupal_strtolower(batire_site_check_text($_POST['email']));

    if (!batire_site_validate_email_address($email)) {
      throw new Exception(t("L'adresse email que vous avez saisie n'est pas reconnue."), BATIRE_SITE_ERROR_USER);
    }
    //If email from pre-reg sub acc
    $maccs = db_query('SELECT * FROM {batire_user_registration_requests} WHERE mail = \'%s\' AND type = %d', $email, BATIRE_USER_REG_TYPE_SUB);
    while ($member = db_fetch_object($maccs)) {
      $member->data = unserialize($member->data);

      //Load admin user
      $auser = user_load($member->uid);

      //Send mail
      if (isset($auser->roles[BATIRE_USER_FREEACCOUNT]) || isset($auser->roles[BATIRE_USER_TRIALTNACCOUNT])) {
        $f_org_type = t('Dans le cadre de l\'offre d\'essai gratuite multiposte, vous beneficiez d\'un acces de @cnt jours au site !site_name.', array('@cnt' => BATIRE_USER_FREE_TERM, '!site_name' => SITE_NAME_UC));
      }
      else {
        $month_cnt = BATIRE_USER_PAID_TERM;
        //Abonnement stuff
        $abonnement_dates_raw = batire_svc_get_abonnement_info($auser->abo_num);

        if (!$abonnement_dates_raw['error']) {
          $abonnement_dates = _batire_svc_unpack_abonnement_info($abonnement_dates_raw['abonnement_info'], $auser->svc_login);
          if ($abonnement_dates) {
            $month_cnt = floor(($abonnement_dates['end_timestamp'] - $abonnement_dates['start_timestamp']) / 30 / 24 / 60 / 60);
          }
        }

        $org_type = $member->data->field_user_statut[0]['value'] ? t('abonnement multiposte de votre organisme') : t('abonnement multiposte de votre entreprise');
        $f_org_type = t('Dans le cadre d’un !org_type, vous bénéficiez d’un accès de @cnt mois au site !site_name.', array('!org_type' => $org_type, '@cnt' => $month_cnt, '!site_name' => SITE_NAME_UC));
      }
      $options = array(
        'module' => 'batire_user',
        'mailkey' => 'batire_user_account_create_subaccount',
        'recipient' => $email,
        'subject' => '',
        'data' => array(
          'name' => $member->data->field_user_name[0]['value'],
          'surname' => $member->data->field_user_surname[0]['value'],
          'salutation' => $member->data->field_user_salut[0]['value'],
          'org_type' => $f_org_type,
          'activate_link' => batire_user_generate_activate_sub_link($member->id),
        ),
        'plaintext' => FALSE
      );

      $send_mail = batire_site_send_mail($options);
      if (!$send_mail) {
        throw new Exception(t("Couldn't send forgot password mail to !mail", array('!mail' => $email)));
      }
    }

    //Login/pass recovery from SVC
    $svc_result = batire_svc_forgot_password($email);
    if ($svc_result['error']) {
      throw new Exception($svc_result['message'], BATIRE_SITE_ERROR_USER);
    }
    $space = '';
    if (count($svc_result['data']) == 1) {
      //Single
      $single_name = $svc_result['data'][0]['account']['name'];
      $single_surname = $svc_result['data'][0]['account']['surname'];
      switch ($svc_result['data'][0]['account']['salutation']) {
        case 'M' :
          $single_salut = 'Monsieur';
          break;
        case 'MME' :
          $single_salut = 'Madame';
          break;
        case 'MLLE' :
          $single_salut = 'Mademoiselle';
          break;
      }
      $space = ' ';
      $accounts_list = t('Identifiant : @login
                          Mot de passe : @pass
                       ', array('@login' => $svc_result['data'][0]['login'], '@pass' => $svc_result['data'][0]['pass']));
    }
    else {
      //Multi
      $accounts_list = '';
      foreach ($svc_result['data'] as $account) {
        $accounts_list .= t('Identifiant : @login
                          Mot de passe : @pass

                       ', array('@login' => $account['login'], '@pass' => $account['pass']));
      }
    }
    //Send mail
    $options = array(
      'module' => 'batire_user',
      'mailkey' => 'batire_user_account_lost_pass',
      'recipient' => $email,
      'subject' => '',
      'data' => array(
        'name' => isset($single_name) ? $single_name : '',
        'surname' => isset($single_surname) ? $single_surname : '',
        'salutation' => isset($single_salut) ? $single_salut : '',
        'space' => $space,
        'accounts_list' => $accounts_list,
      ),
      'plaintext' => FALSE
    );

    $send_mail = batire_site_send_mail($options);
    if (!$send_mail) {
      throw new Exception(t("Couldn't send forgot password mail to !mail", array('!mail' => $email)));
    }
    $message['validate'] = 1;
    $message['status'] = 1;
    $message['message'] = t("Vos codes d'accès ont été envoyés à l'adresse indiquée");

    drupal_json($message);
    return NULL;
  }
  catch (Exception $e) {
    $message['message'] = batire_site_show_message($e->getMessage(), $e->getCode());
    drupal_json($message);
    return NULL;
  }
}

/**
 * Activation abonement callback;
 */
function batire_user_abonement_activation_js() {
  global $user;

  $result = array(
    'error' => FALSE,
    'data' => NULL,
  );

  $abo = isset($_POST['abo']) ? batire_site_check_text($_POST['abo']) : '';
  $email = isset($_POST['email']) ? batire_site_check_text($_POST['email']) : '';

  if (!batire_site_validate_email_address($email)) {
    $email = '';
  }

  try {
    if (!$email) {
      throw new Exception(t('Merci de renseigner une adresse email valide'), BATIRE_SITE_ERROR_USER);
    }

    if (!$abo) {
      throw new Exception(t('Merci de renseigner un abonnement valide'), BATIRE_SITE_ERROR_USER);
    }

    $existing_user = user_load(array('abo_num' => $abo));
    if (!$existing_user) {
      $abon_validate_response = batire_svc_validate_abon_num($abo);
      if ($abon_validate_response['error']) {
        throw new Exception($abon_validate_response['error'], BATIRE_SITE_ERROR_USER);
      }
      else {
        $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation'] = array('abo' => $abo, 'email' => $email);
      }
    }
    else {
      throw new Exception(t('Ce n° d\'abonné a déjà été utilisé. Nous vous invitons à contacter l\'administrateur de votre abonnement.'), BATIRE_SITE_ERROR_USER);
    }

    if (isset($_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation_trans']) && $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation_trans']) {
      $sql = "SELECT
                id
              FROM {batire_user_registration_requests}
              WHERE
                type = %d AND
                mail = '%s'
              ORDER BY id DESC";

      $accs = db_query_range($sql, BATIRE_USER_REG_TYPE_TRANS, $email, 0, 1);

      $member = db_fetch_object($accs);
      if (!isset($member->id) || !$member->id) {
        throw new Exception('Could not find transformation request for this mail.', BATIRE_SITE_ERROR_USER);
      }
    }
  }
  catch (Exception $e) {
    $result['error'] = TRUE;
    $result['data'] = batire_site_show_message($e->getMessage(), $e->getCode());
    drupal_json($result);
    return NULL;
  }

  drupal_json($result);
  return NULL;
}

/**
 * Activation abonement step 2 callback;
 */
function batire_user_abonement_activation_s2_js() {
  global $user;

  $result = array(
    'error' => FALSE,
    'data' => NULL,
  );

  try {
    $ident        = isset($_POST['ident']) ? batire_site_check_text($_POST['ident']) : '';
    $pass         = isset($_POST['pass']) ? batire_site_check_text($_POST['pass']) : '';
    $remember_me  = isset($_POST['remember_me']) ? batire_site_check_text($_POST['remember_me']) : '';

    $sub_id    = isset($_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation_sub']['id']) ? $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation_sub']['id'] : '';
    $free_id   = isset($_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation_free']['id']) ? $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation_free']['id'] : '';
    $transform = isset($_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation_trans']) ? $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation_trans'] : FALSE;

    if ($transform) {
      //Transform account
      $result = batire_user_abonement_activation_s2_transform($ident, $pass, $remember_me);
    }
    elseif ($sub_id) {
      //Activate sub account
      $result = batire_user_abonement_activation_s2_sub($sub_id, $ident, $pass, $remember_me);
    }
    elseif ($free_id) {
      //Activate sub account
      $result = batire_user_abonement_activation_s2_free($free_id, $ident, $pass, $remember_me);
    }
    else {
      //Activate normal account
      $result = batire_user_abonement_activation_s2_normal($ident, $pass, $remember_me);
    }
  }
  catch (Exception $e) {
    $result['error'] = TRUE;
    $result['data'] = batire_site_show_message($e->getMessage(), $e->getCode());
    $result['trans'] = $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation_trans'];
    drupal_json($result);
    return NULL;
  }

  drupal_json($result);
  return NULL;
}

/**
 * Helper function for activate transformation account
 */
function batire_user_abonement_activation_s2_transform($ident, $pass, $remember_me) {
  //Account activation
  $step1 = $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation'];
  $abo   = isset($step1['abo']) ? batire_site_check_text($step1['abo']) : '';
  $email = isset($step1['email']) ? batire_site_check_text($step1['email']) : '';

  batire_user_abonement_activation_s2_validators($email, $abo, $ident, $pass);

  $abon_validate_response = batire_svc_validate_abon_num($abo);
  if ($abon_validate_response['error']) {
    throw new Exception($abon_validate_response['error'], BATIRE_SITE_ERROR_USER);
  }

  /**
   * We need to validate if given abon num is allowed to access the site
   *
   * Only for paid abonnements
   */

  if (!_batire_user_is_abbo_free($abo)) {
    $spaces_result = batire_svc_get_authorized_spaces_by_abon($abo);

    if ($spaces_result['error']) {
      throw new Exception($spaces_result['error'], BATIRE_SITE_ERROR_USER);
    }
  }
  else {
    throw new Exception('Only year abonement allowed.', BATIRE_SITE_ERROR_USER);
  }

  $login_exists = batire_svc_login_exists($ident);

  if (isset($login_exists['svc_id']) && $login_exists['svc_id']) {
    $pwd_min_length = BATIRE_ABBO_PWD_MIN_LEN_EXISTENT_USER;
  }
  else {
    $pwd_min_length = BATIRE_ABBO_PWD_MIN_LEN;
  }

  if (drupal_strlen($pass) < $pwd_min_length) {
    throw new Exception(t('Minimal password length is @cnt chars.', array('@cnt' => $pwd_min_length)), BATIRE_SITE_ERROR_USER);
  }

  //Abonnement stuff
  $abonnement_dates_raw = batire_svc_get_abonnement_info($abo);

  if ($abonnement_dates_raw['error']) {
    throw new Exception(t(
        'An error occured while retreiving information for abon !abon. Error: %error',
        array(
          '!abon'   => $abo,
          '%error'  => $abonnement_dates_raw['error']
        )),
      BATIRE_SITE_ERROR_SYSTEM
    );
  }

  $abonnement_dates = _batire_svc_unpack_abonnement_info($abonnement_dates_raw['abonnement_info'], $ident);
  if (!$abonnement_dates) {
    throw new Exception(t(
        'An error occured while parsing information for abon !abon. Error: %error',
        array(
          '!abon'   => $abo,
          '%error'  => 'Abonnement not found'
        )),
      BATIRE_SITE_ERROR_SYSTEM
    );
  }

  //Load data from prereg table
  $sql = "SELECT
                id, mail, data
              FROM {batire_user_registration_requests}
              WHERE
                type = %d AND
                mail = '%s'
              ORDER BY id DESC";

  $accs = db_query_range($sql, BATIRE_USER_REG_TYPE_TRANS, $email, 0, 1);

  $member = db_fetch_object($accs);
  if (!isset($member->id) || !$member->id) {
    throw new Exception(t('Unknown user, firebug hacking attempt.'), BATIRE_SITE_ERROR_SYSTEM);
  }

  $member->data = unserialize($member->data);

  //Login exists
  //Account activation if user exists in SVC
  if (isset($login_exists['login'])) {
    //pass match
    if ($pass != $login_exists['pass']) {
      throw new Exception(
        t('Vous êtes déjà inscrit à un service du Groupe Moniteur : merci de saisir les codes d\'accès de votre compte actuel. Sinon, l\'identifiant que vous avez saisi existe déjà : veuillez en choisir un autre.')
        , BATIRE_SITE_ERROR_USER
      );
    }

    $svc_abon_results = batire_svc_get_user_abonnements($login_exists['svc_id']);

    if (!$svc_abon_results['error']) {
      $svc_list_of_abonnements = _batire_svc_unpack_abonnements($svc_abon_results['abonnements']);
      //Have same BATIRE abon? if no - add it to SVC else - error
      if (in_array($abo, $svc_list_of_abonnements)) {
        throw new Exception(t('Ce compte est déjà inscrit au site !site_name.', array('!site_name' => SITE_NAME_UC)), BATIRE_SITE_ERROR_USER);
      }

      $svc_batire_active_abonnements = _batire_svc_unpack_active_batire_abonnements($svc_abon_results['abonnements'], TRUE);
      //Have any active non free BATIRE abon? if no - add it to SVC else - error
      if (count($svc_batire_active_abonnements)) {
        throw new Exception(t('Vous êtes déjà inscrit à un service du Groupe Moniteur ? Si oui, merci de saisir les codes d\'accès de votre compte actuel. Sinon, l\'identifiant que vous avez saisi existe déjà : veuillez en choisir un autre.'), BATIRE_SITE_ERROR_USER);
      }

      //Remove all subaccs if it is, remove parent account, unsubscribe abonements
      $old_user = user_load(array('name' => $member->data->svc_id));
      batire_user_delete_user_delete($old_user->uid, FALSE, TRUE, TRUE);

      //Update data in SVC
      //Now we need to update user data in SVC
      $salut = _batire_user_salut_convert($member->data->field_user_salut[0]['value']);
      $svc_values = array(
        'name' => $ident,
        'pass' => $pass,
        'mail' => $email,
        'field_abon_salutation' => array(array('value' => $salut)),
        'field_abon_country' => $member->data->field_user_country,
        'field_abon_company_name' => $member->data->field_user_company,
        'field_abon_function' => $member->data->field_user_position,
        'field_abon_specialty' => $member->data->field_user_specialty,
        'field_abon_tel_1' => $member->data->field_user_tel_1,
        'field_abon_tel_2' => $member->data->field_user_tel_2,
        'field_abon_fax' => $member->data->field_user_fax,
        'field_abon_address_1' => $member->data->field_user_address_1,
        'field_abon_address_2' => $member->data->field_user_address_2,
        'field_abon_post_code' => $member->data->field_user_zip,
        'field_abon_city' => $member->data->field_user_city,
        'field_abon_name' => $member->data->field_user_name,
        'field_abon_surname' => $member->data->field_user_surname,
        'field_opt_1' => $member->data->field_user_opt_1,
        'field_opt_2' => $member->data->field_user_opt_2,
      );
      $response = batire_svc_modify_user_data($login_exists['svc_id'], '', $svc_values);

      if ($response['error']) {
        throw new Exception(t('Une erreur s\'est produite.
                                Nous vous invitons à nous signaler cette anomalie en !link.', array('!link' => batire_site_contact_link())),
          BATIRE_SITE_ERROR_USER
        );
      }

      //Add new abonement
      batire_svc_add_abonnement_number($abo, $login_exists['svc_id'], '');
      $svc_id = $login_exists['svc_id'];
    }
  }
  else {
    //Remove all subaccs if it is, remove parent account, unsubscribe abonements
    $old_user = user_load(array('name' => $member->data->svc_id));
    batire_user_delete_user_delete($old_user->uid, FALSE, TRUE, TRUE);

    //Account activation if user doesn't exists in SVC
    //Create account in SVC based on pre-reg data
    //Salutation
    $salut = _batire_user_salut_convert($member->data->field_user_salut[0]['value']);

    $values = array(
      'field_abon_company_name' => $member->data->field_user_company,
      'field_abon_function' => $member->data->field_user_position,
      'field_abon_specialty' => $member->data->field_user_specialty,
      'field_abon_fax' => $member->data->field_user_fax,
      'field_abon_tel_2' => $member->data->field_user_tel_2,
      'field_abon_tel_1' => $member->data->field_user_tel_1,
      'field_abon_address_1' => $member->data->field_user_address_1,
      'field_abon_address_2' => $member->data->field_user_address_2,
      'field_abon_post_code' => $member->data->field_user_zip,
      'field_abon_city' => $member->data->field_user_city,
      'field_abon_salutation' => array(array('value' => $salut)),
      'field_abon_country' => $member->data->field_user_country,
      'field_opt_1' => $member->data->field_user_opt_1,
      'field_opt_2' => $member->data->field_user_opt_2,
      'field_abon_surname' => $member->data->field_user_surname,
      'field_abon_name' => $member->data->field_user_name,
      'name' => $ident,
      'mail' => $email,
      'abon_no' => $abo,
      'pass' => $pass
    );

    $response = batire_svc_register_user($values);
    if ($response['error']) {
      throw new Exception(t('Une erreur s\'est produite.
                                Nous vous invitons à nous signaler cette anomalie en !link.', array('!link' => batire_site_contact_link())),
        BATIRE_SITE_ERROR_USER
      );
    }

    //Add abbonement
    batire_svc_add_abonnement_number($abo, $response['id'], '');

    $svc_id = $response['id'];
  }

  //Get user profile
  $user_svc = batire_svc_get_user_data($svc_id);
  $user_svc = _batire_svc_unpack_profile($user_svc['data']);

  //Create drupal user
  $user_roles = array();
  //Mono or multi
  $abo_cnt = batire_svc_get_number_of_accounts_by_product($abo);
  if ($abo_cnt['count'] > 1) {
    $user_roles[BATIRE_USER_MULTIADMIN] = BATIRE_USER_MULTIADMIN;
  }
  else {
    $user_roles[BATIRE_USER_MONOPOST] = BATIRE_USER_MONOPOST;
  }
  // Is GC?
  if (batire_gc_commercial_get_sales_by_promo($member->data->field_user_promo[0]['value'])) {
    $user_roles[BATIRE_GC_GC_USER_ROLE_ID] = BATIRE_GC_GC_USER_ROLE_ID;
  }

  $mailkey = 'batire_user_account_confirm_activate';
  $user_roles[BATIRE_USER_PAIDACCOUNT] = BATIRE_USER_PAIDACCOUNT;
  $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation']['acc_type'] = 'paid';
  $abbo_dates = _batire_abonnement_create_dates(BATIRE_USER_PAIDACCOUNT, REQUEST_TIME, $abonnement_dates);

  $edit = array(
    'mail' => $email,
    'name' => $svc_id,
    'svc_login' => $ident,
    'pass' => $pass,
    'status' => 1,
    'abo_num' => $abo,
    'remember_me' => $remember_me,
    'roles' => $user_roles
  );

  $account = user_save('', $edit);

  //Create user profile
  $salut = _batire_user_salut_convert($user_svc['salutation'], TRUE);

  $account_profile = (object) array(
    'title' => _batire_user_get_user_profile_title($account),
    'type' => BATIRE_USER_PROFILE,
    'uid' => $account->uid,
    'status' => 1,
    'name' => $account->name,
    'field_user_abon_num' => array(array('value' => $abo)),
    'field_user_address_1' => array(array('value' => $user_svc['address_1'])),
    'field_user_address_2' => array(array('value' => $user_svc['address_2'])),
    'field_user_zip' => array(array('value' => $user_svc['post_code'])),
    'field_user_city' => array(array('value' => $user_svc['city'])),
    'field_user_company' => array(array('value' => $user_svc['company_name'])),
    'field_user_country' => array(array('value' => $user_svc['country'])),
    'field_user_email_format' => array(array('value' => 'html')),
    'field_user_tel_1' => array(array('value' => $user_svc['tel_1'])),
    'field_user_tel_2' => array(array('value' => $user_svc['tel_2'])),
    'field_user_fax' => array(array('value' => $user_svc['fax'])),
    'field_user_name' => array(array('value' => $user_svc['name'])),
    'field_user_surname' => array(array('value' => $user_svc['surname'])),
    'field_user_position' => array(array('value' => $user_svc['function'])),
    'field_user_specialty' => array(array('value' => $user_svc['service'])),
    'field_user_salut' => array(array('value' => $salut)),
    'field_user_dates' => $abbo_dates,
    'field_user_opt_1' => array(array('value' => $user_svc['opt_1'])),
    'field_user_opt_2' => array(array('value' => $user_svc['opt_2'])),
    'field_user_posts_count' => array(array('value' => $abo_cnt['count'])),
    'field_user_promo' => $member->data->field_user_promo,
  );

  // Assign products
  $svc_abon_results = batire_svc_get_user_abonnements($response['id']);
  if (!$svc_abon_results['error']) {
    $full_abon_list = _batire_svc_unpack_abonnements_advanced($svc_abon_results['abonnements']);
    $products = isset($full_abon_list) && count($full_abon_list) ? array_keys($full_abon_list) : NULL;
    if (isset($user_roles[BATIRE_USER_FREEACCOUNT]) || !$products) {
      $profile->field_user_products = array(array('nid' => BATIRE_BASE_PRODUCT_ID));
    }
    else {
      $available_products = batire_user_products_get_products();
      $account_profile->field_user_products = array();
      foreach ($products as $_prod) {
        $account_profile->field_user_products[] = array('nid' => $available_products[$_prod]['nid']);
      }
    }
  }

  node_save($account_profile);

  //Send mail
  $send_mail = batire_user_abonement_activation_s2_normal_mail($email, $ident, $pass, $user_svc['name'], $user_svc['surname'], $salut, $mailkey);
  if (!$send_mail) {
    throw new Exception(t('Couldn\'t send account activate confirmation email for @email.', array('@email' => $email)), BATIRE_SITE_ERROR_SYSTEM);
  }

  //Login user
  batire_user_abonement_activation_s2_login($user_svc['cpt_id'], $pass, $remember_me, $account);

  //Send URL for redirect
  return $result['data'] = url('<front>', array('absolute' => TRUE));
}

/**
 * Helper function for activate normal account
 */
function batire_user_abonement_activation_s2_normal($ident, $pass, $remember_me) {
  //Account activation
  $step1 = $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation'];
  $abo   = isset($step1['abo']) ? batire_site_check_text($step1['abo']) : '';
  $email = isset($step1['email']) ? batire_site_check_text($step1['email']) : '';

  batire_user_abonement_activation_s2_validators($email, $abo, $ident, $pass);

  $abon_validate_response = batire_svc_validate_abon_num($abo);
  if ($abon_validate_response['error']) {
    throw new Exception($abon_validate_response['error'], BATIRE_SITE_ERROR_USER);
  }

  /**
   * We need to validate if given abon num is allowed to access the site
   *
   * Only for paid abonnements
   */

  if (!_batire_user_is_abbo_free($abo)) {
    $spaces_result = batire_svc_get_authorized_spaces_by_abon($abo);

    if ($spaces_result['error']) {
      throw new Exception($spaces_result['error'], BATIRE_SITE_ERROR_USER);
    }
  }

  $login_exists = batire_svc_login_exists($ident);

  if (isset($login_exists['svc_id']) && $login_exists['svc_id']) {
    $pwd_min_length = BATIRE_ABBO_PWD_MIN_LEN_EXISTENT_USER;
  }
  else {
    $pwd_min_length = BATIRE_ABBO_PWD_MIN_LEN;
  }

  if (drupal_strlen($pass) < $pwd_min_length) {
    throw new Exception(t('Minimal password length is @cnt chars.', array('@cnt' => $pwd_min_length)), BATIRE_SITE_ERROR_USER);
  }

  //Abonnement stuff
  $abonnement_dates_raw = batire_svc_get_abonnement_info($abo);

  if ($abonnement_dates_raw['error']) {
    throw new Exception(t(
        'An error occured while retreiving information for abon !abon. Error: %error',
        array(
          '!abon'   => $abo,
          '%error'  => $abonnement_dates_raw['error']
        )),
      BATIRE_SITE_ERROR_SYSTEM
    );
  }

  $abonnement_dates = _batire_svc_unpack_abonnement_info($abonnement_dates_raw['abonnement_info'], $ident);
  if (!$abonnement_dates) {
    throw new Exception(t(
        'An error occured while parsing information for abon !abon. Error: %error',
        array(
          '!abon'   => $abo,
          '%error'  => 'Abonnement not found'
        )),
      BATIRE_SITE_ERROR_SYSTEM
    );
  }

  // Deny registration if user already in Drupal database
  $user = user_load(array('svc_login' => $ident));
  if ($user) {
    throw new Exception(t('Ce compte est déjà inscrit au site !site_name.', array('!site_name' => SITE_NAME_UC)), BATIRE_SITE_ERROR_USER);
  }

  //Login exists
  //Account activation if user exists in SVC
  if (isset($login_exists['login'])) {
    //pass match
    if ($pass != $login_exists['pass']) {
      throw new Exception(
        t('Vous êtes déjà inscrit à un service du Groupe Moniteur : merci de saisir les codes d\'accès de votre compte actuel. Sinon, l\'identifiant que vous avez saisi existe déjà : veuillez en choisir un autre.')
        , BATIRE_SITE_ERROR_USER
      );
    }
    else {
      $svc_abon_results = batire_svc_get_user_abonnements($login_exists['svc_id']);

      if (!$svc_abon_results['error']) {
        $svc_list_of_abonnements = _batire_svc_unpack_abonnements($svc_abon_results['abonnements']);
        $full_abon_list = _batire_svc_unpack_abonnements_advanced($svc_abon_results['abonnements']);
        $svc_batire_active_abonnements = _batire_svc_unpack_active_batire_abonnements($svc_abon_results['abonnements']);

        // Add abo to SVC if not used
        if (!in_array($abo, $svc_list_of_abonnements)) {
          batire_svc_add_abonnement_number($abo, $login_exists['svc_id'], '');
        }
        $user_svc = batire_svc_get_user_data('', $login_exists['login']);
        $user_svc = _batire_svc_unpack_profile($user_svc['data']);

        //Create drupal user
        $user_roles = array();
        //Mono or multi
        $abo_cnt = batire_svc_get_number_of_accounts_by_product($abo);
        if ($abo_cnt['count'] > 1) {
          $user_roles[BATIRE_USER_MULTIADMIN] = BATIRE_USER_MULTIADMIN;
        }
        else {
          $user_roles[BATIRE_USER_MONOPOST] = BATIRE_USER_MONOPOST;
        }

        //Paid or free
        $mailkey = 'batire_user_account_confirm_activate';
        if (_batire_user_is_abbo_free($abo)) {
          $mailkey = 'batire_user_account_confirm_free_trial';
          $user_roles[BATIRE_USER_FREEACCOUNT] = BATIRE_USER_FREEACCOUNT;
          $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation']['acc_type'] = 'free';
          //Store to session expire abo date
          $abbo_dates = _batire_abonnement_create_dates(BATIRE_USER_FREEACCOUNT, REQUEST_TIME);
          $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation']['free_acc_date'] = format_date($abbo_dates[0]['value2'], 'custom', 'd/m/Y');
        }
        else {
          $user_roles[BATIRE_USER_PAIDACCOUNT] = BATIRE_USER_PAIDACCOUNT;
          $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation']['acc_type'] = 'paid';
          $abbo_dates = _batire_abonnement_create_dates(BATIRE_USER_PAIDACCOUNT, REQUEST_TIME, $abonnement_dates);
        }

        $edit = array(
          'mail' => $email,
          'name' => $login_exists['svc_id'],
          'svc_login' => $ident,
          'pass' => $pass,
          'status' => 1,
          'abo_num' => $abo,
          'remember_me' => $remember_me,
          'roles' => $user_roles
        );

        $account = user_save('', $edit);

        //Create user profile
        $salut = _batire_user_salut_convert($user_svc['salutation'], TRUE);

        $account_profile = (object) array(
          'title' => _batire_user_get_user_profile_title($account),
          'type' => BATIRE_USER_PROFILE,
          'uid' => $account->uid,
          'status' => 1,
          'name' => $account->name,
          'field_user_abon_num' => array(array('value' => $abo)),
          'field_user_address_1' => array(array('value' => $user_svc['address_1'])),
          'field_user_address_2' => array(array('value' => $user_svc['address_2'])),
          'field_user_zip' => array(array('value' => $user_svc['post_code'])),
          'field_user_city' => array(array('value' => $user_svc['city'])),
          'field_user_company' => array(array('value' => $user_svc['company_name'])),
          'field_user_country' => array(array('value' => $user_svc['country'])),
          'field_user_email_format' => array(array('value' => 'html')),
          'field_user_tel_1' => array(array('value' => $user_svc['tel_1'])),
          'field_user_tel_2' => array(array('value' => $user_svc['tel_2'])),
          'field_user_fax' => array(array('value' => $user_svc['fax'])),
          'field_user_name' => array(array('value' => $user_svc['name'])),
          'field_user_surname' => array(array('value' => $user_svc['surname'])),
          'field_user_position' => array(array('value' => $user_svc['function'])),
          'field_user_specialty' => array(array('value' => $user_svc['service'])),
          'field_user_salut' => array(array('value' => $salut)),
          'field_user_dates' => $abbo_dates,
          'field_user_opt_1' => array(array('value' => $user_svc['opt_1'])),
          'field_user_opt_2' => array(array('value' => $user_svc['opt_2'])),
          'field_user_posts_count' => array(array('value' => $abo_cnt['count'])),
        );

        // Assign products
        $products = isset($full_abon_list) && count($full_abon_list) ? array_keys($full_abon_list) : NULL;
        if (isset($user_roles[BATIRE_USER_FREEACCOUNT]) || !$products) {
          $profile->field_user_products = array(array('nid' => BATIRE_BASE_PRODUCT_ID));
        }
        else {
          $available_products = batire_user_products_get_products();
          $account_profile->field_user_products = array();
          foreach ($products as $_prod) {
            $account_profile->field_user_products[] = array('nid' => $available_products[$_prod]['nid']);
          }
        }

        node_save($account_profile);

        //Send mail
        $send_mail = batire_user_abonement_activation_s2_normal_mail($email, $ident, $pass, $user_svc['name'], $user_svc['surname'], $salut, $mailkey);
        if (!$send_mail) {
          throw new Exception(t('Couldn\'t send account activate confirmation email for @email.', array('@email' => $email)), BATIRE_SITE_ERROR_SYSTEM);
        }

        //Login user
        batire_user_abonement_activation_s2_login($user_svc['cpt_id'], $pass, $remember_me, $account);

        //Send URL for redirect
        return $result['data'] = url('<front>', array('absolute' => TRUE));
      }
    }
  }
  else {
    //Account activation if user doesn't exists in SVC
    //Get last data from pre-reg table by email
    $sql = "SELECT
                id, mail, data
              FROM {batire_user_registration_requests}
              WHERE
                type != %d AND
                mail = '%s'
              ORDER BY id DESC";

    $accs = db_query_range($sql, BATIRE_USER_REG_TYPE_SUB, $email, 0, 1);

    $member = db_fetch_object($accs);
    if (!isset($member->id) || !$member->id) {
      $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation'] = array('abo' => $abo, 'email' => $email, 'ident' => $ident);
      $result['redir'] = TRUE;
      $result['data'] = url('user/register/activation');
      return $result;
    }

    $member->data = unserialize($member->data);
    //Create account in SVC based on pre-reg data
    //Salutation
    $salut = _batire_user_salut_convert($member->data->field_user_salut[0]['value']);

    $values = array(
      'field_abon_company_name' => $member->data->field_user_company,
      'field_abon_function' => $member->data->field_user_position,
      'field_abon_specialty' => $member->data->field_user_specialty,
      'field_abon_fax' => $member->data->field_user_fax,
      'field_abon_tel_2' => $member->data->field_user_tel_2,
      'field_abon_tel_1' => $member->data->field_user_tel_1,
      'field_abon_address_1' => $member->data->field_user_address_1,
      'field_abon_address_2' => $member->data->field_user_address_2,
      'field_abon_post_code' => $member->data->field_user_zip,
      'field_abon_city' => $member->data->field_user_city,
      'field_abon_salutation' => array(array('value' => $salut)),
      'field_abon_country' => $member->data->field_user_country,
      'field_opt_1' => $member->data->field_user_opt_1,
      'field_opt_2' => $member->data->field_user_opt_2,
      'field_abon_surname' => $member->data->field_user_surname,
      'field_abon_name' => $member->data->field_user_name,
      'name' => $ident,
      'mail' => $email,
      'abon_no' => $abo,
      'pass' => $pass
    );

    $response = batire_svc_register_user($values);
    if ($response['error']) {
      throw new Exception(t('Une erreur s\'est produite.
                                Nous vous invitons à nous signaler cette anomalie en !link.', array('!link' => batire_site_contact_link())),
        BATIRE_SITE_ERROR_USER
      );
    }

    //Add abbonement
    batire_svc_add_abonnement_number($abo, $response['id'], '');

    //Create Drupal account
    //Mono or multi
    $abo_cnt = batire_svc_get_number_of_accounts_by_product($abo);
    if ($abo_cnt['count'] > 1) {
      $user_roles[BATIRE_USER_MULTIADMIN] = BATIRE_USER_MULTIADMIN;
    }
    else {
      $user_roles[BATIRE_USER_MONOPOST] = BATIRE_USER_MONOPOST;
    }
    // Is GC?
    if (batire_gc_commercial_get_sales_by_promo($member->data->field_user_promo[0]['value'])) {
      $user_roles[BATIRE_GC_GC_USER_ROLE_ID] = BATIRE_GC_GC_USER_ROLE_ID;
    }

    //Paid or free
    $mailkey = 'batire_user_account_confirm_activate';
    if (_batire_user_is_abbo_free($abo)) {
      $mailkey = 'batire_user_account_confirm_free_trial';
      $user_roles[BATIRE_USER_FREEACCOUNT] = BATIRE_USER_FREEACCOUNT;
      $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation']['acc_type'] = 'free';
      //Store to session expire abo date
      $abbo_dates = _batire_abonnement_create_dates(BATIRE_USER_FREEACCOUNT, REQUEST_TIME);
      $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation']['free_acc_date'] = format_date($abbo_dates[0]['value2'], 'custom', 'd/m/Y');
    }
    else {
      $user_roles[BATIRE_USER_PAIDACCOUNT] = BATIRE_USER_PAIDACCOUNT;
      $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation']['acc_type'] = 'paid';
      $abbo_dates = _batire_abonnement_create_dates(BATIRE_USER_PAIDACCOUNT, REQUEST_TIME, $abonnement_dates);
    }

    $edit = array(
      'mail' => $email,
      'name' => $response['id'],
      'svc_login' => $ident,
      'pass' => $pass,
      'status' => 1,
      'abo_num' => $abo,
      'remember_me' => $remember_me,
      'roles' => $user_roles
    );

    $account = user_save('', $edit);

    $account_profile = (object) array(
      'title' => _batire_user_get_user_profile_title($account),
      'type' => BATIRE_USER_PROFILE,
      'uid' => $account->uid,
      'status' => 1,
      'name' => $account->name,
      'field_user_abon_num' => array(array('value' => $abo)),
      'field_user_address_1' => $member->data->field_user_address_1,
      'field_user_address_2' => $member->data->field_user_address_2,
      'field_user_zip' => $member->data->field_user_zip,
      'field_user_city' => $member->data->field_user_city,
      'field_user_company' => $member->data->field_user_company,
      'field_user_country' => $member->data->field_user_country,
      'field_user_email_format' => $member->data->field_user_email_format,
      'field_user_tel_1' => $member->data->field_user_tel_1,
      'field_user_tel_2' => $member->data->field_user_tel_2,
      'field_user_fax' => $member->data->field_user_fax,
      'field_user_name' => $member->data->field_user_name,
      'field_user_surname' => $member->data->field_user_surname,
      'field_user_position' => $member->data->field_user_position,
      'field_user_specialty' => $member->data->field_user_specialty,
      'field_user_salut' => $member->data->field_user_salut,
      'field_user_dates' => $abbo_dates,
      'field_user_opt_1' => $member->data->field_user_opt_1,
      'field_user_opt_2' => $member->data->field_user_opt_2,
      'field_user_activity_prv' => $member->data->field_user_activity_prv,
      'field_user_activity_pub' => $member->data->field_user_activity_pub,
      'field_user_posts_count' => array(array('value' => $abo_cnt['count'])),
      'field_user_statut' => $member->data->field_user_statut,
      'field_user_tva' => $member->data->field_user_tva,
      'field_user_promo' => $member->data->field_user_promo,
    );

    // Assign products
    $svc_abon_results = batire_svc_get_user_abonnements($response['id']);
    if (!$svc_abon_results['error']) {
      $full_abon_list = _batire_svc_unpack_abonnements_advanced($svc_abon_results['abonnements']);
      $products = isset($full_abon_list) && count($full_abon_list) ? array_keys($full_abon_list) : NULL;
      if (isset($user_roles[BATIRE_USER_FREEACCOUNT]) || !$products) {
        $profile->field_user_products = array(array('nid' => BATIRE_BASE_PRODUCT_ID));
      }
      else {
        $available_products = batire_user_products_get_products();
        $account_profile->field_user_products = array();
        foreach ($products as $_prod) {
          $account_profile->field_user_products[] = array('nid' => $available_products[$_prod]['nid']);
        }
      }
    }

    node_save($account_profile);

    //Send mail
    $send_mail = batire_user_abonement_activation_s2_normal_mail($email, $ident, $pass, $member->data->field_user_name[0]['value'], $member->data->field_user_surname[0]['value'], $member->data->field_user_salut[0]['value'], $mailkey);
    if (!$send_mail) {
      throw new Exception(t('Couldn\'t send account activate confirmation email for @email.', array('@email' => $email)), BATIRE_SITE_ERROR_SYSTEM);
    }

    //Login user
    batire_user_abonement_activation_s2_login($response['id'], $pass, $remember_me, $account);

    //Remove from prereg table
    db_query('DELETE FROM {batire_user_registration_requests} WHERE id = %d', $member->id);

    //Send URL for redirect
    return $result['data'] = url('<front>', array('absolute' => TRUE));
  }
}

function batire_user_abonement_activation_s2_sub($sub_id, $ident, $pass, $remember_me) {
  $accs = db_query_range("
            SELECT * FROM {batire_user_registration_requests}
            WHERE id = %d AND type = %d", $sub_id, BATIRE_USER_REG_TYPE_SUB, 0, 1
  );

  $member = db_fetch_object($accs);
  //If no data in prereg table
  if (!isset($member->id) || !$member->id) {
    throw new Exception(
      t('Ces informations ne sont pas reconnues. Pouvez-vous les vérifier et nous contacter au @phone si nécessaire', array('@phone' => variable_get('batire_site_contact_telephone', ''))),
      BATIRE_SITE_ERROR_USER
    );
  }

  $member->data = unserialize($member->data);

  $admin_account = user_load($member->uid);
  $admin_profile = batire_user_profile_load($member->uid);

  $abo          = $admin_account->abo_num;
  $email        = $member->mail;

  batire_user_abonement_activation_s2_validators($email, $abo, $ident, $pass);

  $user_svc = batire_svc_get_user_data('', $ident);

  if (!$user_svc['error']) {
    $user_svc = _batire_svc_unpack_profile($user_svc['data']);
    $pwd_min_length = BATIRE_ABBO_PWD_MIN_LEN_EXISTENT_USER;
  }
  else {
    $pwd_min_length = BATIRE_ABBO_PWD_MIN_LEN;
  }

  if (drupal_strlen($pass) < $pwd_min_length) {
    throw new Exception(t('Minimal password length is @cnt chars.', array('@cnt' => $pwd_min_length)), BATIRE_SITE_ERROR_USER);
  }

  /**
   * We need to validate if given abon num is allowed to access the site
   *
   * Only for paid abonnements
   */
  if (!_batire_user_is_abbo_free($abo)) {
    $spaces_result = batire_svc_get_authorized_spaces_by_abon($abo);

    if ($spaces_result['error']) {
      throw new Exception($spaces_result['error'], BATIRE_SITE_ERROR_USER);
    }
  }

  if (isset($user_svc['cpt_id']) && $user_svc['cpt_id']) {
    //Activate subacc if have data in SVC
    if ($user_svc['pass'] != $pass) {
      throw new Exception(t('Vous êtes déjà inscrit à un service du Groupe Moniteur : merci de saisir les codes d\'accès de votre compte actuel. Sinon, l\'identifiant que vous avez saisi existe déjà : veuillez en choisir un autre.'), BATIRE_SITE_ERROR_USER);
    }

    $svc_abon_results = batire_svc_get_user_abonnements($user_svc['cpt_id']);

    if (!$svc_abon_results['error']) {
      $svc_list_of_abonnements = _batire_svc_unpack_abonnements($svc_abon_results['abonnements']);
      //Have same BATIRE abon? if no - add it to SVC else - error
      if (in_array($abo, $svc_list_of_abonnements)) {
        throw new Exception(t('Ce compte est déjà inscrit au site !site_name.', array('!site_name' => SITE_NAME_UC)), BATIRE_SITE_ERROR_USER);
      }

      $svc_batire_active_abonnements = _batire_svc_unpack_active_batire_abonnements($svc_abon_results['abonnements']);
      //Have any active BATIRE abon? if no - add it to SVC else - error
      if (count($svc_batire_active_abonnements)) {
        throw new Exception(t('Vous êtes déjà inscrit à un service du Groupe Moniteur ? Si oui, merci de saisir les codes d\'accès de votre compte actuel. Sinon, l\'identifiant que vous avez saisi existe déjà : veuillez en choisir un autre.'), BATIRE_SITE_ERROR_USER);
      }

      batire_svc_add_abonnement_number($abo, $user_svc['cpt_id'], '');
    }
    else {
      throw new Exception($svc_abon_results['error'], BATIRE_SITE_ERROR_USER);
    }

    $svc_id = $user_svc['cpt_id'];
  }
  else {
    //Activate subacc if haven't data in SVC
    //Salutation
    $salut = _batire_user_salut_convert($member->data->field_user_salut[0]['value']);

    $values = array(
      'field_abon_company_name' => $member->data->field_user_company,
      'field_abon_function' => $member->data->field_user_position,
      'field_abon_specialty' => $member->data->field_user_specialty,
      'field_abon_fax' => $member->data->field_user_fax,
      'field_abon_tel_2' => $member->data->field_user_tel_2,
      'field_abon_tel_1' => $member->data->field_user_tel_1,
      'field_abon_address_1' => $member->data->field_user_address_1,
      'field_abon_address_2' => $member->data->field_user_address_2,
      'field_abon_post_code' => $member->data->field_user_zip,
      'field_abon_city' => $member->data->field_user_city,
      'field_abon_salutation' => array(array('value' => $salut)),
      'field_abon_country' => $member->data->field_user_country,
      'field_opt_1' => $member->data->field_user_opt_1,
      'field_opt_2' => $member->data->field_user_opt_2,
      'field_abon_surname' => $member->data->field_user_surname,
      'field_abon_name' => $member->data->field_user_name,
      'name' => $ident,
      'mail' => $email,
      'abon_no' => $abo,
      'pass' => $pass
    );

    $response = batire_svc_register_user($values);
    if ($response['error']) {
      throw new Exception(t('Une erreur s\'est produite.
                                  Nous vous invitons à nous signaler cette anomalie en !link.', array('!link' => batire_site_contact_link())
        ),
        BATIRE_SITE_ERROR_USER
      );
    }

    $svc_id = $response['id'];

    //Add abbonement
    batire_svc_add_abonnement_number($abo, $svc_id, '');
  }
  //Create Drupal account
  $user_roles[BATIRE_USER_SUBACCOUNT] = BATIRE_USER_SUBACCOUNT;

  //Paid or free
  if (_batire_user_is_abbo_free($abo)) {
    if (isset($admin_account->roles[BATIRE_USER_TRIALTNACCOUNT]) && $admin_account->roles[BATIRE_USER_TRIALTNACCOUNT]) {
      $user_roles[BATIRE_USER_TRIALTNACCOUNT] = BATIRE_USER_TRIALTNACCOUNT;
    }
    else {
      $user_roles[BATIRE_USER_FREEACCOUNT] = BATIRE_USER_FREEACCOUNT;
    }
    $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation']['acc_type'] = 'free';
    //Store to session expire abo date
    $abbo_dates = _batire_abonnement_create_dates(BATIRE_USER_FREEACCOUNT, REQUEST_TIME);
    $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation']['free_acc_date'] = format_date($abbo_dates[0]['value2'], 'custom', 'd/m/Y');
  }
  else {
    $user_roles[BATIRE_USER_PAIDACCOUNT] = BATIRE_USER_PAIDACCOUNT;
    $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation']['acc_type'] = 'paid';
  }

  $edit = array(
    'mail' => $email,
    'name' => $svc_id,
    'svc_login' => $ident,
    'pass' => $pass,
    'status' => 1,
    'abo_num' => $abo,
    'remember_me' => $remember_me,
    'roles' => $user_roles
  );

  $account = user_save('', $edit);

  $admin_profile->field_user_subacc[] = array('uid' => $account->uid);
  node_save($admin_profile);

  $account_profile = (object) array(
    'title' => _batire_user_get_user_profile_title($account),
    'type' => BATIRE_USER_PROFILE,
    'uid' => $account->uid,
    'status' => 1,
    'name' => $account->name,
    'field_user_abon_num' => array(array('value' => $abo)),
    'field_user_address_1' => $member->data->field_user_address_1,
    'field_user_address_2' => $member->data->field_user_address_2,
    'field_user_zip' => $member->data->field_user_zip,
    'field_user_city' => $member->data->field_user_city,
    'field_user_company' => $member->data->field_user_company,
    'field_user_country' => $member->data->field_user_country,
    'field_user_email_format' => $member->data->field_user_email_format,
    'field_user_tel_1' => $member->data->field_user_tel_1,
    'field_user_tel_2' => $member->data->field_user_tel_2,
    'field_user_fax' => $member->data->field_user_fax,
    'field_user_name' => $member->data->field_user_name,
    'field_user_surname' => $member->data->field_user_surname,
    'field_user_position' => $member->data->field_user_position,
    'field_user_specialty' => $member->data->field_user_specialty,
    'field_user_salut' => $member->data->field_user_salut,
    'field_user_dates' => $admin_profile->field_user_dates,
    'field_user_opt_1' => $member->data->field_user_opt_1,
    'field_user_opt_2' => $member->data->field_user_opt_2,
    'field_user_activity_prv' => $member->data->field_user_activity_prv,
    'field_user_activity_pub' => $member->data->field_user_activity_pub,
    'field_user_statut' => $member->data->field_user_statut,
    'field_user_tva' => $member->data->field_user_tva,
    'field_user_promo' => $member->data->field_user_promo,
  );

  // Assign products
  $svc_abon_results = batire_svc_get_user_abonnements($svc_id);
  if (!$svc_abon_results['error']) {
    $full_abon_list = _batire_svc_unpack_abonnements_advanced($svc_abon_results['abonnements']);
    $products = isset($full_abon_list) && count($full_abon_list) ? array_keys($full_abon_list) : NULL;
    if (isset($user_roles[BATIRE_USER_FREEACCOUNT]) || !$products) {
      $profile->field_user_products = array(array('nid' => BATIRE_BASE_PRODUCT_ID));
    }
    else {
      $available_products = batire_user_products_get_products();
      $account_profile->field_user_products = array();
      foreach ($products as $_prod) {
        $account_profile->field_user_products[] = array('nid' => $available_products[$_prod]['nid']);
      }
    }
  }

  node_save($account_profile);

  //Send mail
  $send_mail = batire_user_abonement_activation_s2_normal_mail($email, $ident, $pass, $member->data->field_user_name[0]['value'], $member->data->field_user_surname[0]['value'], $member->data->field_user_salut[0]['value'], 'batire_user_account_confirm_subaccount');
  if (!$send_mail) {
    throw new Exception(t('Couldn\'t send account activate confirmation email for @email.', array('@email' => $email)), BATIRE_SITE_ERROR_SYSTEM);
  }

  //Login user
  batire_user_abonement_activation_s2_login($svc_id, $pass, $remember_me, $account);

  //Remove from prereg table
  db_query('DELETE FROM {batire_user_registration_requests} WHERE id = %d', $member->id);

  //Send URL for redirect
  $result['data'] = url('<front>', array('absolute' => TRUE));
  return $result;
}

function batire_user_abonement_activation_s2_free($free_id, $ident, $pass, $remember_me) {
  $accs = db_query_range("
            SELECT * FROM {batire_user_registration_requests}
            WHERE id = %d AND (type = %d OR type = %d)", $free_id, BATIRE_USER_REG_TYPE_FREE, BATIRE_USER_REG_TYPE_TRIAL_TN, 0, 1
  );

  $member = db_fetch_object($accs);
  //If no data in prereg table
  if (!isset($member->id) || !$member->id) {
    throw new Exception(
      t('Ces informations ne sont pas reconnues. Pouvez-vous les vérifier et nous contacter au @phone si nécessaire', array('@phone' => variable_get('batire_site_contact_telephone', ''))),
      BATIRE_SITE_ERROR_USER
    );
  }

  $member->data = unserialize($member->data);

  $abo          = ($member->data->field_user_posts_count[0]['value'] == 5) ? BATIRE_ABBO_FREE_MULTI : BATIRE_ABBO_FREE_MONO;
  $email        = $member->mail;

  batire_user_abonement_activation_s2_validators($email, $abo, $ident, $pass);

  $user_svc = batire_svc_get_user_data('', $ident);

  if (!$user_svc['error']) {
    $user_svc = _batire_svc_unpack_profile($user_svc['data']);
    $pwd_min_length = BATIRE_ABBO_PWD_MIN_LEN_EXISTENT_USER;
  }
  else {
    $pwd_min_length = BATIRE_ABBO_PWD_MIN_LEN;
  }

  if (drupal_strlen($pass) < $pwd_min_length) {
    throw new Exception(t('Minimal password length is @cnt chars.', array('@cnt' => $pwd_min_length)), BATIRE_SITE_ERROR_USER);
  }

  if (isset($user_svc['cpt_id']) && $user_svc['cpt_id']) {
    //Activate free acc if have data in SVC
    if ($user_svc['pass'] != $pass) {
      throw new Exception(t('Vous êtes déjà inscrit à un service du Groupe Moniteur : merci de saisir les codes d\'accès de votre compte actuel. Sinon, l\'identifiant que vous avez saisi existe déjà : veuillez en choisir un autre.'), BATIRE_SITE_ERROR_USER);
    }

    $svc_abon_results = batire_svc_get_user_abonnements($user_svc['cpt_id']);

    if (!$svc_abon_results['error']) {
      $svc_list_of_abonnements = _batire_svc_unpack_abonnements($svc_abon_results['abonnements']);
      //Have same BATIRE abon? if no - add it to SVC else - error
      if (in_array($abo, $svc_list_of_abonnements)) {
        throw new Exception(t('Ce compte est déjà inscrit au site !site_name.', array('!site_name' => SITE_NAME_UC)), BATIRE_SITE_ERROR_USER);
      }

      $svc_batire_active_abonnements = _batire_svc_unpack_active_batire_abonnements($svc_abon_results['abonnements']);
      //Have any active BATIRE abon? if no - add it to SVC else - error
      if (count($svc_batire_active_abonnements)) {
        throw new Exception(t('Vous êtes déjà inscrit à un service du Groupe Moniteur ? Si oui, merci de saisir les codes d\'accès de votre compte actuel. Sinon, l\'identifiant que vous avez saisi existe déjà : veuillez en choisir un autre.'), BATIRE_SITE_ERROR_USER);
      }

      batire_svc_add_abonnement_number($abo, $user_svc['cpt_id'], '');
    }
    else {
      throw new Exception($svc_abon_results['error'], BATIRE_SITE_ERROR_USER);
    }

    $svc_id = $user_svc['cpt_id'];
  }
  else {
    //Activate free acc if haven't data in SVC
    //Salutation
    $salut = _batire_user_salut_convert($member->data->field_user_salut[0]['value']);

    $values = array(
      'field_abon_company_name' => $member->data->field_user_company,
      'field_abon_function'     => $member->data->field_user_position,
      'field_abon_specialty'    => $member->data->field_user_specialty,
      'field_abon_fax'          => $member->data->field_user_fax,
      'field_abon_tel_2'        => $member->data->field_user_tel_2,
      'field_abon_tel_1'        => $member->data->field_user_tel_1,
      'field_abon_address_1'    => $member->data->field_user_address_1,
      'field_abon_address_2'    => $member->data->field_user_address_2,
      'field_abon_post_code'    => $member->data->field_user_zip,
      'field_abon_city'         => $member->data->field_user_city,
      'field_abon_salutation'   => array(array('value' => $salut)),
      'field_abon_country'      => $member->data->field_user_country,
      'field_opt_1'             => $member->data->field_user_opt_1,
      'field_opt_2'             => $member->data->field_user_opt_2,
      'field_abon_surname'      => $member->data->field_user_surname,
      'field_abon_name'         => $member->data->field_user_name,
      'name'                    => $ident,
      'mail'                    => $email,
      'abon_no'                 => $abo,
      'pass'                    => $pass
    );

    $response = batire_svc_register_user($values);
    if ($response['error']) {
      throw new Exception(t('Une erreur s\'est produite.
                                  Nous vous invitons à nous signaler cette anomalie en !link.', array('!link' => batire_site_contact_link())
        ),
        BATIRE_SITE_ERROR_USER
      );
    }

    $svc_id = $response['id'];

    //Add abbonement
    batire_svc_add_abonnement_number($abo, $svc_id, '');
  }
  //Create Drupal account
  switch ($member->type) {
    case BATIRE_USER_REG_TYPE_FREE:
      $user_roles[BATIRE_USER_FREEACCOUNT] = BATIRE_USER_FREEACCOUNT;
      break;
    case BATIRE_USER_REG_TYPE_TRIAL_TN:
      $user_roles[BATIRE_USER_TRIALTNACCOUNT] = BATIRE_USER_TRIALTNACCOUNT;
      break;
  }

  $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation']['acc_type'] = 'free';
  //Store to session expire abo date
  $abbo_dates = _batire_abonnement_create_dates(BATIRE_USER_FREEACCOUNT, REQUEST_TIME);
  $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation']['free_acc_date'] = format_date($abbo_dates[0]['value2'], 'custom', 'd/m/Y');

  //Mono or multi
  $abo_cnt = batire_svc_get_number_of_accounts_by_product($abo);
  if ($abo_cnt['count'] > 1) {
    $user_roles[BATIRE_USER_MULTIADMIN] = BATIRE_USER_MULTIADMIN;
  }
  else {
    $user_roles[BATIRE_USER_MONOPOST] = BATIRE_USER_MONOPOST;
  }
  // Is GC?
  if (batire_gc_commercial_get_sales_by_promo($member->data->field_user_promo[0]['value'])) {
    $user_roles[BATIRE_GC_GC_USER_ROLE_ID] = BATIRE_GC_GC_USER_ROLE_ID;
  }


  $edit = array(
    'mail'        => $email,
    'name'        => $svc_id,
    'svc_login'   => $ident,
    'pass'        => $pass,
    'status'      => 1,
    'abo_num'     => $abo,
    'remember_me' => $remember_me,
    'roles'       => $user_roles
  );

  $account = user_save('', $edit);

  $account_profile = (object) array(
    'title' => _batire_user_get_user_profile_title($account),
    'type' => BATIRE_USER_PROFILE,
    'uid' => $account->uid,
    'status' => 1,
    'name' => $account->name,
    'field_user_abon_num' => array(array('value' => $abo)),
    'field_user_address_1' => $member->data->field_user_address_1,
    'field_user_address_2' => $member->data->field_user_address_2,
    'field_user_zip' => $member->data->field_user_zip,
    'field_user_city' => $member->data->field_user_city,
    'field_user_company' => $member->data->field_user_company,
    'field_user_country' => $member->data->field_user_country,
    'field_user_email_format' => $member->data->field_user_email_format,
    'field_user_tel_1' => $member->data->field_user_tel_1,
    'field_user_tel_2' => $member->data->field_user_tel_2,
    'field_user_fax' => $member->data->field_user_fax,
    'field_user_name' => $member->data->field_user_name,
    'field_user_surname' => $member->data->field_user_surname,
    'field_user_position' => $member->data->field_user_position,
    'field_user_specialty' => $member->data->field_user_specialty,
    'field_user_salut' => $member->data->field_user_salut,
    'field_user_dates' => $abbo_dates,
    'field_user_opt_1' => $member->data->field_user_opt_1,
    'field_user_opt_2' => $member->data->field_user_opt_2,
    'field_user_activity_prv' => $member->data->field_user_activity_prv,
    'field_user_activity_pub' => $member->data->field_user_activity_pub,
    'field_user_statut' => $member->data->field_user_statut,
    'field_user_tva' => $member->data->field_user_tva,
    'field_user_posts_count' => array(array('value' => $abo_cnt['count'])),
    'field_user_promo' => $member->data->field_user_promo,
    'field_user_products' => isset($user_roles[BATIRE_USER_FREEACCOUNT]) ? array(array('nid' => BATIRE_BASE_PRODUCT_ID)) : array(array('nid' => NULL)),
  );

  node_save($account_profile);

  //Send mail
  $send_mail = batire_user_abonement_activation_s2_normal_mail(
    $email,
    $ident,
    $pass,
    $member->data->field_user_name[0]['value'],
    $member->data->field_user_surname[0]['value'],
    $member->data->field_user_salut[0]['value'],
    'batire_user_account_confirm_activate_free'
  );

  if (!$send_mail) {
    throw new Exception(t('Couldn\'t send account activate confirmation email for @email.', array('@email' => $email)), BATIRE_SITE_ERROR_SYSTEM);
  }

  //Login user
  batire_user_abonement_activation_s2_login($svc_id, $pass, $remember_me, $account);

  //Remove from prereg table
  db_query('DELETE FROM {batire_user_registration_requests} WHERE id = %d', $member->id);

  //Send URL for redirect
  $result['data'] = url('<front>', array('absolute' => TRUE));
  return $result;
}

function batire_user_abonement_activation_s2_normal_mail($email, $ident, $pass, $name, $surname, $salut, $mailkey = 'batire_user_account_confirm_activate') {
  //Send mail
  $options = array(
    'module'    => 'batire_user',
    'mailkey'   => $mailkey,
    'recipient' => $email,
    'subject'   => '',
    'data'      => array(
      'name'       => $name,
      'surname'    => $surname,
      'salutation' => $salut,
      'faq_link'   => l('FAQ', 'faq', array('absolute' => TRUE)),
      'login'      => $ident,
      'password'   => $pass,
    ),
    'plaintext' => FALSE
  );

  return batire_site_send_mail($options, variable_get('site_mail', 'kheox@groupemoniteur.fr'));
}

/**
 * Helper function for log user in after activation
 * @param $svc_id
 * @param $pass
 * @param $remember_me
 * @param $account
 */
function batire_user_abonement_activation_s2_login($svc_id, $pass, $remember_me, $account) {
  global $user;
  // Name and pass keys are required.
  // The user is about to be logged in, so make sure no error was previously
  // encountered in the validation process.
  if (!empty($svc_id) && !empty($pass) && $account) {
    $auth['name'] = $svc_id;
    $auth['pass'] = $pass;
    $auth['remember_me'] = $remember_me;
    $user = $account;
    user_authenticate_finalize($auth);
  }
}

/**
 * Helper function for validators
 * @param $email
 * @param $abo
 * @param $ident
 * @param $pass
 * @throws Exception
 */
function batire_user_abonement_activation_s2_validators($email, $abo, $ident, $pass) {
  if (!batire_site_validate_email_address($email)) {
    $email = '';
  }

  if (!$email) {
    throw new Exception(t('Merci de renseigner une adresse email valide'), BATIRE_SITE_ERROR_USER);
  }

  if (!$abo) {
    throw new Exception(t('Merci de renseigner un abonnement valide'), BATIRE_SITE_ERROR_USER);
  }

  if (!$ident) {
    throw new Exception(t('Merci de renseigner un identifiant valide'), BATIRE_SITE_ERROR_USER);
  }

  if (!$pass) {
    throw new Exception(t('Merci de renseigner un mot de passe valide'), BATIRE_SITE_ERROR_USER);
  }

  if (batire_user_is_restricted_user($ident) || drupal_is_denied('mail', $email)) {
    throw new Exception(t('Vos identifiants ne vous donnent pas accès à !site_name. Vous devez d\'abord activer votre compte ou nous contacter en !link.', array('!site_name' => SITE_NAME_FS, '!link' => batire_site_contact_link())), BATIRE_SITE_ERROR_USER);
  }
}

/**
 * Callback for registration thank you page
 * @param string $section
 */
function batire_user_user_register_thankyou($section) {

  $data = array(
    'title' => '',
    'subtitle' => '',
    'content' => '',
    'br' => FALSE
  );

  switch ($section) {
    case BATIRE_USER_REG_TYPE_DAD :
      $data['title'] = t('Votre demande de démonstration personnalisée et interactive<br /> de Kheox a bien été enregistrée.');
      $data['content'] = t('Un conseiller va vous contacter dans les meilleurs délais.');
      $data['br'] = TRUE;
      break;
    case 'transform' :
    case BATIRE_USER_REG_TYPE_PAID :
      $data['title'] = t('Votre demande de devis a bien été enregistrée.');
      $data['content'] = t('Un conseiller commercial va vous contacter dans les meilleurs délais.');
      $data['br'] = TRUE;
      break;
    case BATIRE_USER_REG_TYPE_FREE :
    case BATIRE_USER_REG_TYPE_TRIAL_TN:
      $data['title'] = t('Votre inscription à l\'offre d\'essai gratuite a bien été enregistrée.');
      $data['content'] = t('Vous pouvez dès maintenant consulter !site_name et découvrir l\'ensemble<br /> de ses ressources et de ses fonctionnalités.', array('!site_name' => SITE_NAME_UC));

      //@todo - here we need to load profile, created after registration;
      //$data['date']    = format_date($_SESSION[CP_ABONNEMENT]['__user_profile']->field_abon_dates[0]['value2'], 'custom', 'd/m/Y');
      break;
    case 'subaccount' :
    case 'activation' :
      $data['title'] = t('L\'activation de votre compte !site_name a été prise en compte.', array('!site_name' => SITE_NAME_UC));
      $data['content'] = t('Vous pouvez dorénavant consulter !site_name et bénéficier de l\'ensemble de ses ressources et de ses fonctionnalités.', array('!site_name' => SITE_NAME_UC));
      break;
    default :
      return drupal_not_found();
  }

  if (in_array($section, array('free', 'activation', 'subaccount'))) {
    /**
     * Log user in
     *
     * @todo - for certain types of registration, we need to log user in instantly;
     */
  }

  return theme('batire_user_thank_you', $data);
}

/**
 * Registration page for users;
 * @param null $type
 * @return html
 */
function batire_user_user_register($type = NULL) {
  global $user;

  $type = $type ? $type : BATIRE_USER_REG_TYPE_PAID;

//  if (arg(0) == 'user' && arg(1) == 'register') {
//    if (!empty($user->uid) && ($user->uid > 0) && (($type != 'transform') || ($type == 'transform' && !_batire_user_is_free($user)))) {
//      drupal_goto(BATIRE_SITE_NOT_FOUND_URL);
//    }
//  }

  /**
   * Stopping, if wrong page given;
   */
  if (!in_array($type, array(BATIRE_USER_REG_TYPE_DAD, BATIRE_USER_REG_TYPE_FREE, BATIRE_USER_REG_TYPE_PAID, 'activation', 'transform', BATIRE_USER_REG_TYPE_TRIAL_TN))) {
    return drupal_not_found();
  }

  $node = (object) array('type' => BATIRE_USER_PROFILE, '__reg_type' => $type);

  /**
   * Setting title and subtitle of registration page
   */
  $title = _batire_user_get_registration_page_title($type);
  $subtitle = _batire_user_get_registration_page_subtitle($type);

  /**
   * Handling promo code
   */
  if (isset($_SESSION[BATIRE_USERSESSION_NAMESPACE]['__promo_code']) && $_SESSION[BATIRE_USERSESSION_NAMESPACE]['__promo_code']) {
    $node->field_user_promo[0]['value'] = $_SESSION[BATIRE_USERSESSION_NAMESPACE]['__promo_code'];
  }

  /**
   * Building registration form based on user profile node form
   */
  module_load_include('pages.inc', 'node');
  if ((string) $type == 'transform') {
    $content = drupal_get_form('batire_user_transform_abonnement_form', $node);
  }
  else {
    $content = drupal_get_form('batire_user_profile_node_form', $node);
  }

  return theme('batire_user_subscription_page', $content, $title, $subtitle, $type);
}

/**
 * Page callback for sub accounts list;
 */
function batire_user_list_accounts() {
  global $user;

  $adm_profile = batire_user_profile_load($user->uid);
  $members = mongodb_user_get_members();
  $data = array();
  $members_to_sort = array();
  $sub_cnt = $adm_profile->field_user_posts_count[0]['value'] - 1;
  $cntr = 0;

  $sorting_keys = array('surname' => t('Nom'), 'date_inscrit' => t('Inscription'), 'date_invit' => t('Invitation'), 'service' => t('Service'));
  $sorting_key = 'surname';
  $sorting_direction = 'asc';
  if (isset($_GET['sort_by']) && in_array($_GET['sort_by'], array_keys($sorting_keys))) {
    $sorting_key = $_GET['sort_by'];
  }
  if (isset($_GET['sort']) && in_array($_GET['sort'], array('asc', 'desc'))) {
    $sorting_direction = $_GET['sort'];
  }

  foreach ($members as $member) {
    if (!$member['is_admin']) {
      $member_data = db_fetch_object(db_query('SELECT created FROM {users} WHERE uid = %d', $member['uid']));
      $member['acc_type'] = 'acc';
      $member['acc_id'] = $member['uid'];
      $member['hash'] = $hash = md5($member['name'] . $member['surname'] . $member['mail']);
      $member['date'] = 'inscrit : ' . format_date($member_data->created, 'custom', 'd/m/Y');
      $member['date_inscrit'] = $member_data->created;
      $member['date_invit'] = 0;
      $members_to_sort[$hash] = $member;
    }
  }

  //Get accounts from MySQL pre-reg table
  $accs = db_query('SELECT id, mail, data, created FROM {batire_user_registration_requests} WHERE uid = %d', $user->uid);
  while ($acc = db_fetch_object($accs)) {
    $member['mail'] = $acc->mail;
    $member_data = unserialize($acc->data);
    $member['name'] = $member_data->field_user_name[0]['value'];
    $member['surname'] = $member_data->field_user_surname[0]['value'];
    $member['hash'] = $hash = md5($member['name'] . $member['surname'] . $member['mail']);
    $member['acc_type'] = 'preacc';
    $member['acc_id'] = $acc->id;
    $member['date'] = 'invit. :' . format_date($acc->created, 'custom', 'd/m/Y');
    $member['date_inscrit'] = 0;
    $member['date_invit'] = $acc->created;
    $members_to_sort[$hash] = $member;
  }

  batire_site_summary_sort_by_val($members_to_sort, $sorting_key, $sorting_direction == 'desc', $sorting_key == 'surname');

  foreach ($members_to_sort as $member) {
    $cntr++;
    $data['subs_all'][] = theme('batire_user_list_account', $member, $cntr);
  }

  foreach ($sorting_keys as $key => $title) {
    if ($sorting_key == $key) {
      if ($sorting_direction == 'asc') {
        $sorting = 'desc';
      }
      else {
        $sorting = 'asc';
      }
    }
    else {
      $sorting = 'asc';
    }
    $sorting_links[] = l($title, 'mon-compte/mon-abonnement/comptes-utilisateurs/', array('attributes' => $sorting_key == $key ? array('class' => 'active') : array(), 'query' => array('sort_by' => $key, 'sort' => $sorting, 'page' => isset($_GET['page']) ? check_plain($_GET['page']) : 0)));
  }
  $data['sorting_links'] = theme('item_list', $sorting_links);

  $vars = array(
    '!sub_cnt' => format_plural($sub_cnt, '@count compte de collaborateur', '@count comptes de collaborateurs'),
    '!phone' => variable_get('batire_site_contact_telephone', ''),
    '!email' => l(variable_get('batire_site_contact_email', 'cliquant ici'), 'mailto:' . variable_get('batire_site_contact_email', '')),
  );

  $data['text'] = t(
  "Votre formule d'abonnement vous permet de créer et d'administrer <span class=\"comptes\">!sub_cnt</span>, si vous souhaitez en augmenter le nombre, contactez notre service commercial par téléphone au <b>!phone</b> ou par email au !email", $vars
  );

  $data['excel_link'] = l(t('Export this list to excel'), 'batire_user/comptes-utilisateurs-export', array('query' => array('sort_by' => $sorting_key, 'sort' => $sorting_direction)));

  $avail_cnt = $sub_cnt - $cntr;
  $data['cnt_avail'] = 0;
  $data['cnt_current'] = $cntr;
  if ($avail_cnt > 0) {
    $data['cnt_avail'] = format_plural($avail_cnt, '@count disponible', '@count disponibles');
  }

  global $pager_page_array, $pager_total;
  $items_per_page = 30;
  $num_results = count($data['subs_all']);
  $page = isset($_GET['page']) ? check_plain($_GET['page']) : 0;
  $pager_page_array = explode(',', $page);
  $pager_total = array(ceil($num_results / $items_per_page));
  $data['pager'] = theme('pager');
  $page_start = $page * $items_per_page;
  $page_end = ($page + 1) * $items_per_page - 1;
  for ($i = $page_start; $i <= $page_end; $i++) {
    $data['subs'][] = $data['subs_all'][$i];
  }

  drupal_add_js(
  array(
    'batire_user' => array(
      "accounts_list_url" => url('js/batire_user/accounts-list'),
      "accounts_cnt" => $cntr,
      "accounts_max" => $sub_cnt
    )
  ), 'setting'
  );
  drupal_add_js(drupal_get_path('module', 'batire_user') . '/scripts/json2.js');
  drupal_add_js(drupal_get_path('module', 'batire_user') . '/scripts/batire_user.accounts_list.js');
  drupal_add_js(drupal_get_path('module', 'batire_user') . '/scripts/md5.js');

  return theme('batire_user_list_accounts', $data);
}

/**
 * Page callback for group members;
 */
function batire_user_group_members() {
  $members = mongodb_user_get_members();

  $data = array();

  foreach ($members as $member) {

    $folders_list = batire_user_docs_get_user_shared_folders_list($member['uid']);
    $member['folders_count'] = 0;
    if ($folders_list) {
      $member['folders_list'] = array();

      foreach ($folders_list as $folder) {
        $member['folders_list'][] = l($folder->title, 'mon-compte/mon-espace-partage/dossiers-partages/' . $folder->nid);
      }
      $member['folders_count'] = count($member['folders_list']);
    }

    $member['anno_count'] = mongodb_docs_count_user_annotations($member['uid'], 's');

    $data[] = theme('batire_user_group_member', $member);
  }

  return theme('batire_user_group_members', $data);
}

/**
 * Page callback for abonement date ;
 */
function batire_user_abonement_date($account) {
  $profile = batire_user_profile_load($account->uid);

  if (!empty($profile)) {
    (_batire_user_is_multipost($account) && array_key_exists(BATIRE_USER_MULTIADMIN, $account->roles)) ? $multipost = 1 : $multipost = 0;

    $list_members = array();
    $members = mongodb_user_get_members($profile->uid);

    foreach ($members as $key => $value) {
      if ($value['uid'] != $profile->uid) {
        $list_members[$key]['name'] = $value['name'];
        $list_members[$key]['surname'] = $value['surname'];
        $list_members[$key]['mail'] = l($value['mail'], 'mailto:' . $value['mail']);
      }
    }

    $start_date = format_date($profile->field_user_dates[0]['value'], 'custom', 'd/m/Y');
    $due_date = format_date($profile->field_user_dates[0]['value2'], 'custom', 'd/m/Y');

    $data = array(
      'abon_number' => $account->abo_num,
      'type_user' => _batire_user_is_multipost($account) ? t('multiposte') : t('monoposte'),
      'start_date' => $start_date,
      'due_date' => $due_date,
      'multipost' => $multipost,
      'members' => $list_members,
      'result' => batire_site_is_user_about_to_expire($account)
    );

    /*
     * Get user products titles
     */
    if(!empty($profile->field_user_products[0]['nid'])) {
      $products_list = array();
      foreach($profile->field_user_products as $product) {
        $products_list[] = node_load($product['nid'])->title;
      }
      $data['user_products'] = implode(', ', $products_list);
    }

    $vars = array(
      '!site_name' => SITE_NAME_UC,
      '!phone' => variable_get('batire_site_contact_telephone', ''),
      '!email' => l(variable_get('batire_site_contact_email', 'cliquant ici'), 'mailto:' . variable_get('batire_site_contact_email', '')),
      '!url' => batire_site_contact_link()
    );

    if (_batire_user_is_paid($account)) {
      $data['text'] = t(
      "Pour renouveler ou modifier votre abonnement, veuillez contacter un conseiller du Groupe Moniteur par téléphone au <b>!phone</b> par e-mail au !email ou en !url.", $vars
      );
    }
    else {
      $vars['!url'] = l('cliquant ici', 'user/register/transform');
      $data['text'] = t(
      "Pour transformer votre offre d'essai gratuite en abonnement à !site_name, veuillez contacter un conseiller du Groupe Moniteur par téléphone au <b>!phone</b> par email à !email ou en !url.", $vars
      );
    }
  }
  return theme('batire_user_abonement_date', $data);
}

/**
 * Page callback for group members;
 */
function batire_user_detail_abonnement($account) {
  global $user;

  /**
   * We need to load profile info from SVC;
   */
  $profile = batire_user_profile_load($user->uid, TRUE);

  $svc_data = batire_svc_get_user_data($user->name);
  if ($svc_data['error']) {
    drupal_set_message($svc_data['error'], 'error');
    $content = '';
  }
  else {
    $svc_data = _batire_svc_unpack_profile($svc_data['data']);
    $_SESSION[BATIRE_USERSESSION_NAMESPACE]['__edit_profile_svc_data'] = $svc_data;
    //Update user profile
    switch ($svc_data['salutation']) {
      case 'M' :
        $salut = 'Monsieur';
        break;
      case 'MME' :
        $salut = 'Madame';
        break;
      case 'MLLE' :
        $salut = 'Mademoiselle';
        break;
    }

    $profile->field_user_address_1 = array(array('value' => $svc_data['address_1']));
    $profile->field_user_address_2 = array(array('value' => $svc_data['address_2']));
    $profile->field_user_zip = array(array('value' => $svc_data['post_code']));
    $profile->field_user_city = array(array('value' => $svc_data['city']));
    $profile->field_user_company = array(array('value' => $svc_data['company_name']));
    $profile->field_user_country = array(array('value' => $svc_data['country']));
    $profile->field_user_tel_1 = array(array('value' => $svc_data['tel_1']));
    $profile->field_user_tel_2 = array(array('value' => $svc_data['tel_2']));
    $profile->field_user_fax = array(array('value' => $svc_data['fax']));
    $profile->field_user_name = array(array('value' => $svc_data['name']));
    $profile->field_user_surname = array(array('value' => $svc_data['surname']));
    $profile->field_user_position = array(array('value' => $svc_data['function']));
    $profile->field_user_specialty = array(array('value' => $svc_data['service']));
    $profile->field_user_salut = array(array('value' => $salut));
    $profile->field_user_opt_1 = array(array('value' => $svc_data['opt_1']));
    $profile->field_user_opt_2 = array(array('value' => $svc_data['opt_2']));

    node_save($profile);

    /**
     * Building user profile node form
     */
    $admin_form = isset($account->roles[BATIRE_USER_MULTIADMIN]) || isset($account->roles[BATIRE_USER_MONOPOST]) ? TRUE : FALSE;
    $content = drupal_get_form('batire_user_detail_abonnement_form', $admin_form);
  }

  return theme('batire_user_detail_abonnement', $content);
}

/**
 * Form for detail my abonnement page.
 *
 * @ingroup forms
 */
function batire_user_detail_abonnement_form(&$form_state, $access) {
  global $user;
  $ses_svc = _batire_site_get_session(BATIRE_USERSESSION_NAMESPACE, array());
  $pass = !empty($ses_svc['__edit_profile_svc_data']['pass']) ? $ses_svc['__edit_profile_svc_data']['pass'] : '';
  drupal_add_js(
    'function addPaswords() {
      $("input[name=password]").val("' . $pass .'");
      $("input[name=confirm_password]").val("' . $pass .'");
    }
    $(function(){
      addPaswords();
    });', 'inline'
  );

  $profile = batire_user_profile_load($user->uid);
  $form = array();
  $form['my_accounts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mes coordonnées')
  );

  $field_user_salut = content_fields('field_user_salut', 'batire_user_profile');
  $field_user_salut_values = content_allowed_values($field_user_salut);
  $form['my_accounts']['field_user_salut'] = array(
    '#type' => 'radios',
    '#title' => t('Civilité'),
    '#options' => $field_user_salut_values,
    '#required' => TRUE,
    '#access' => TRUE,
    '#default_value' => $profile->field_user_salut[0]['value']
  );
  $form['my_accounts']['field_user_surname'] = array(
    '#type' => 'textfield',
    '#title' => t('Nom'),
    '#required' => TRUE,
    '#access' => TRUE,
    '#default_value' => $profile->field_user_surname[0]['value']
  );
  $form['my_accounts']['field_user_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Prénom'),
    '#required' => TRUE,
    '#access' => TRUE,
    '#default_value' => $profile->field_user_name[0]['value']
  );
  $form['my_accounts']['field_user_email'] = array(
    '#type' => 'textfield',
    '#title' => 'Email',// This is correct, should not be wrapped with t()
    '#required' => TRUE,
    '#access' => TRUE,
    '#default_value' => $user->mail
  );
  $form['my_accounts']['field_user_tel_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Téléphone'),
    '#required' => TRUE,
    '#access' => $access,
    '#default_value' => $profile->field_user_tel_1[0]['value']
  );
  $form['my_accounts']['field_user_tel_2'] = array(
    '#type' => 'textfield',
    '#title' => t('autre n° (facultatif)'),
    '#access' => $access,
    '#default_value' => $profile->field_user_tel_2[0]['value']
  );
  $form['my_accounts']['field_user_fax'] = array(
    '#type' => 'textfield',
    '#title' => t('Fax'),
    '#description' => t('(facultatif)'),
    '#access' => $access,
    '#default_value' => $profile->field_user_fax[0]['value']
  );

  $field_user_position = content_fields('field_user_position', 'batire_user_profile');
  $field_user_position_values = array('' => t('Précisez...'));
  $field_user_position_values += content_allowed_values($field_user_position);
  $form['my_accounts']['field_user_position'] = array(
    '#type' => 'select',
    '#title' => t('Fonction'),
    '#options' => $field_user_position_values,
    '#required' => TRUE,
    '#access' => $access,
    '#default_value' => $profile->field_user_position[0]['value']
  );

  $form['my_accounts']['field_user_specialty'] = array(
    '#type' => 'textfield',
    '#title' => t('Spécialité'),
    '#required' => TRUE,
    '#access' => $access,
    '#default_value' => $profile->field_user_specialty[0]['value']
  );

  $form['my_company'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mon entreprise/organisme'),
    '#access' => $access
  );

  $field_user_statut = content_fields('field_user_statut', 'batire_user_profile');
  $field_user_statut_values = content_allowed_values($field_user_statut);
  $form['my_company']['field_user_statut'] = array(
    '#type' => 'radios',
    '#title' => t('Statut'),
    '#options' => $field_user_statut_values,
    '#required' => TRUE,
    '#access' => $access,
    '#default_value' => $profile->field_user_statut[0]['value']
  );
  $form['my_company']['field_user_company'] = array(
    '#type' => 'textfield',
    '#title' => t('Raison sociale'),
    '#required' => TRUE,
    '#access' => $access,
    '#default_value' => $profile->field_user_company[0]['value']
  );

  $field_user_activity_pub = content_fields('field_user_activity_pub', 'batire_user_profile');
  $field_user_activity_pub_values = array('' => t('Précisez...'));
  $field_user_activity_pub_values += content_allowed_values($field_user_activity_pub);
  $form['my_company']['field_user_activity_pub'] = array(
    '#type' => 'select',
    '#title' => t('Activité'),
    '#options' => $field_user_activity_pub_values,
    '#access' => $access,
    '#default_value' => $profile->field_user_activity_pub[0]['value']
  );

  $field_user_activity_prv = content_fields('field_user_activity_prv', 'batire_user_profile');
  $field_user_activity_prv_values = array('' => t('Précisez...'));
  $field_user_activity_prv_values += content_allowed_values($field_user_activity_prv);
  $form['my_company']['field_user_activity_prv'] = array(
    '#type' => 'select',
    '#title' => t('Activité'),
    '#options' => $field_user_activity_prv_values,
    '#access' => $access,
    '#default_value' => $profile->field_user_activity_prv[0]['value']
  );

  $form['my_company']['field_user_address_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Adresse'),
    '#required' => TRUE,
    '#access' => $access,
    '#default_value' => $profile->field_user_address_1[0]['value']
  );
  $form['my_company']['field_user_address_2'] = array(
    '#type' => 'textfield',
    '#access' => $access,
    '#default_value' => $profile->field_user_address_2[0]['value']
  );
  $form['my_company']['field_user_zip'] = array(
    '#type' => 'textfield',
    '#title' => t('Code postal'),
    '#required' => TRUE,
    '#access' => $access,
    '#default_value' => $profile->field_user_zip[0]['value']
  );
  $form['my_company']['field_user_city'] = array(
    '#type' => 'textfield',
    '#title' => t('Ville'),
    '#required' => TRUE,
    '#access' => $access,
    '#default_value' => $profile->field_user_city[0]['value']
  );

  $field_user_country = content_fields('field_user_country', 'batire_user_profile');
  $field_user_country_values = content_allowed_values($field_user_country);
  $form['my_company']['field_user_country'] = array(
    '#type' => 'select',
    '#title' => t('Pays'),
    '#options' => $field_user_country_values,
    '#access' => $access,
    '#default_value' => $profile->field_user_country[0]['value']
  );
  $form['my_company']['field_user_tva'] = array(
    '#type' => 'textfield',
    '#title' => t('T.V.A'),
    '#access' => $access,
    '#default_value' => $profile->field_user_tva[0]['value']
  );
  $form['my_company']['field_user_promo'] = array(
    '#type' => 'textfield',
    '#title' => t('Code Privilège'),
    '#description' => t('(facultatif)'),
    '#access' => $access,
    '#default_value' => $profile->field_user_promo[0]['value']
  );

  $form['my_codes'] = array(
    '#type' => 'fieldset',
    '#title' => t("Mes codes d'accès"),
    '#access' => TRUE
  );
  $form['my_codes']['login'] = array(
    '#type' => 'textfield',
    '#title' => t('Identifiant'),
    '#access' => TRUE,
    '#default_value' => $user->svc_login,
    '#required' => TRUE
  );
  $form['my_codes']['password'] = array(
    '#type' => 'password',
    '#title' => t('Mot de passe'),
    '#access' => TRUE
  );
  $form['my_codes']['confirm_password'] = array(
    '#type' => 'password',
    '#title' => t('Confirmation mot de passe'),
    '#access' => TRUE
  );
  $form['my_codes']['remember_me'] = array(
    '#type' => 'checkbox',
    '#title' => t("Mémoriser mes codes d'accès"),
    '#default_value' => $user->remember_me,
    '#access' => TRUE
  );

  $form['my_account_client'] = array(
    '#type' => 'fieldset',
    '#title' => t("Mon compte client"),
    '#access' => $access
  );
  $user_posts_count = $profile->field_user_posts_count[0]['value'] ? $profile->field_user_posts_count[0]['value'] : 0;
  $form['my_account_client']['number'] = array(
    '#type' => 'item',
    '#title' => t('Numéro'),
    '#value' => $user->abo_num,
    '#description' => format_plural($user_posts_count, 'Cet abonnement comprend <b>@count poste</b>', 'Cet abonnement comprend <b>@count postes</b>'),
    '#access' => $access
  );
  $form['my_account_client']['field_user_opt_1'] = array(
    '#type' => 'checkbox',
    '#title' => t("J'autorise le Groupe Moniteur (co-éditeur du site !site_name), à conserver mes coordonnées afin de m'envoyer des informations à caractère professionnel.", array('!site_name' => SITE_NAME_UC)),
    '#access' => $access,
    '#default_value' => $profile->field_user_opt_1[0]['value']
  );
  $form['my_account_client']['field_user_opt_2'] = array(
    '#type' => 'checkbox',
    '#title' => t("J'accepte que le Groupe Moniteur transmette à ses partenaires les données que je vous ai transmises."),
    '#access' => $access,
    '#default_value' => $profile->field_user_opt_2[0]['value']
  );
  $field_user_email_format = content_fields('field_user_email_format', 'batire_user_profile');
  $field_user_email_format_values = content_allowed_values($field_user_email_format);
  $form['my_account_client']['field_user_email_format'] = array(
    '#type' => 'radios',
    '#title' => t('Format de réception des e-mails') . " :",
    '#options' => $field_user_email_format_values,
    '#access' => $access,
    '#default_value' => $profile->field_user_email_format[0]['value']
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Valider'),
    '#attributes' => array('class' => 'batire-user-detail-abonnement-submit')
  );
  $form['#theme'] = 'batire_user_detail_abonnement_form';
  return $form;
}

/**
 * Form for detail my abonnement page.
 *
 * @ingroup forms
 */
function batire_user_transform_abonnement_form(&$form_state, $access) {
  global $user;
  $profile = batire_user_profile_load($user->uid);
  $form = array();

  $form['group_my_details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mes coordonnées')
  );

  $field_user_salut = content_fields('field_user_salut', 'batire_user_profile');
  $field_user_salut_values = content_allowed_values($field_user_salut);
  $form['group_my_details']['field_user_salut'] = array(
    '#type' => 'radios',
    '#title' => t('Civilité'),
    '#options' => $field_user_salut_values,
    '#required' => TRUE,
    '#access' => TRUE,
    '#default_value' => $profile->field_user_salut[0]['value']
  );
  $form['group_my_details']['field_user_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Prénom'),
    '#required' => TRUE,
    '#access' => TRUE,
    '#default_value' => $profile->field_user_name[0]['value']
  );
  $form['group_my_details']['field_user_surname'] = array(
    '#type' => 'textfield',
    '#title' => t('Nom'),
    '#required' => TRUE,
    '#access' => TRUE,
    '#default_value' => $profile->field_user_surname[0]['value']
  );
  $form['mail'] = array(
    '#type' => 'textfield',
    '#title' => 'Email', // This is correct, should not be wrapped with t()
    '#maxlength' => EMAIL_MAX_LENGTH,
    '#default_value' => $user->mail
  );
  $form['group_my_details']['field_user_tel_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Téléphone'),
    '#required' => TRUE,
    '#access' => $access,
    '#default_value' => $profile->field_user_tel_1[0]['value']
  );

  $field_user_position = content_fields('field_user_position', 'batire_user_profile');
  $field_user_position_values = array('' => t('Précisez...'));
  $field_user_position_values += content_allowed_values($field_user_position);
  $form['group_my_details']['field_user_position'] = array(
    '#type' => 'select',
    '#title' => t('Fonction'),
    '#options' => $field_user_position_values,
    '#required' => TRUE,
    '#access' => $access,
    '#name' => 'field_user_position[value]',
    '#default_value' => $profile->field_user_position[0]['value']
  );

  $form['group_my_details']['field_user_specialty'] = array(
    '#type' => 'textfield',
    '#title' => t('Spécialité'),
    '#required' => TRUE,
    '#access' => $access,
    '#default_value' => $profile->field_user_specialty[0]['value']
  );

  $form['group_my_company'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mon entreprise/organisme'),
    '#access' => $access
  );

  $form['group_my_company']['field_user_company'] = array(
    '#type' => 'textfield',
    '#title' => t('Raison sociale'),
    '#required' => TRUE,
    '#access' => $access,
    '#default_value' => $profile->field_user_company[0]['value']
  );

  $form['group_my_company']['field_user_address_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Adresse'),
    '#required' => TRUE,
    '#access' => $access,
    '#default_value' => $profile->field_user_address_1[0]['value']
  );
  $form['group_my_company']['field_user_address_2'] = array(
    '#type' => 'textfield',
    '#access' => $access,
    '#default_value' => $profile->field_user_address_2[0]['value']
  );
  $form['group_my_company']['field_user_zip'] = array(
    '#type' => 'textfield',
    '#title' => t('Code postal'),
    '#required' => TRUE,
    '#access' => $access,
    '#default_value' => $profile->field_user_zip[0]['value']
  );
  $form['group_my_company']['field_user_city'] = array(
    '#type' => 'textfield',
    '#title' => t('Ville'),
    '#required' => TRUE,
    '#access' => $access,
    '#default_value' => $profile->field_user_city[0]['value']
  );

  $field_user_country = content_fields('field_user_country', 'batire_user_profile');
  $field_user_country_values = content_allowed_values($field_user_country);
  $form['group_my_company']['field_user_country'] = array(
    '#type' => 'select',
    '#title' => t('Pays'),
    '#options' => $field_user_country_values,
    '#access' => $access,
    '#name' => 'field_user_country[value]',
    '#default_value' => $profile->field_user_country[0]['value']
  );
  $form['group_other'] = array(
    '#type' => 'fieldset',
    '#title' => t("Abonnement multiposte"),
    '#access' => $access
  );
  $form['group_other']['field_user_promo'] = array(
    '#type' => 'textfield',
    '#title' => t('Code Privilège'),
    '#description' => t('(facultatif)'),
    '#access' => $access,
    '#name' => 'field_user_promo',
    '#default_value' => $profile->field_user_promo[0]['value']
  );
  $field_user_posts_count = content_fields('field_user_posts_count', 'batire_user_profile');
  $field_user_posts_count_values = array('' => t('Nombre de postes'));
  $field_user_posts_count_values += content_allowed_values($field_user_posts_count);
  $form['group_other']['field_user_posts_count'] = array(
    '#type' => 'select',
    '#title' => t('Je suis déja utilisateur de produits et services du Groupe Moniteur (facultatif)'),
    '#options' => $field_user_posts_count_values,
    '#access' => $access,
    '#name' => 'field_user_posts_count[value]',
    '#default_value' => $profile->field_user_posts_count[0]['value']
  );

  $form['group_other']['field_user_opt_1'] = array(
    '#type' => 'checkboxes',
    '#options' => array(1 => t("J'autorise le Groupe Moniteur (co-éditeur du site !site_name), à conserver mes coordonnées afin de m'envoyer des informations à caractère professionnel.", array('!site_name' => SITE_NAME_UC))),
    '#access' => $access,
    '#name' => 'field_user_opt_1[value]',
    '#default_value' => array($profile->field_user_opt_1[0]['value'])
  );
  $form['group_other']['field_user_opt_2'] = array(
    '#type' => 'checkboxes',
    '#options' => array(1 => t("J'accepte que le Groupe Moniteur transmette à ses partenaires les données que je vous ai transmises.")),
    '#access' => $access,
    '#default_value' => array($profile->field_user_opt_2[0]['value'])
  );
  $field_user_email_format = content_fields('field_user_email_format', 'batire_user_profile');
  $field_user_email_format_values = content_allowed_values($field_user_email_format);
  $form['group_other']['field_user_email_format'] = array(
    '#type' => 'radios',
    '#title' => t('Format de réception des e-mails') . " :",
    '#options' => $field_user_email_format_values,
    '#access' => $access,
    '#default_value' => $profile->field_user_email_format[0]['value']
  );

  $form['when_to_call'] = array(
    '#type' => 'textarea',
    '#resizable' => FALSE,
    '#attributes' => array(
      'title' => t('Exemple : jeudi 7 avril de 14h à 16h30...')
    ),
    '#title' => t('Un conseiller va vous contacter pour vous proposer un devis personnalisé a !site_name', array('!site_name' => SITE_NAME_UC)) . ' :',
    '#description' => t('Vous pouvez nous préciser vos disponibilités en nous indiquant un ou plusieurs créneaux horaires propices à cette prise de contact')
  );

  $form['registration_type'] = array(
    '#type' => 'hidden',
    '#default_value' => 'transform'
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Valider'),
    '#attributes' => array('class' => 'user-register-form-submit')
  );

  $form['#validate'] = array('batire_user_transform_validate');
  $form['#submit'] = array('batire_user_transform_submit');

  $form['#theme'] = 'batire_user_transform_abonnement_form';

  return $form;
}

/**
 * Callback for products offre
 */
function batire_user_products_page() {
  $content['form'] = drupal_get_form('batire_user_products_form');

  return theme('batire_user_products_page', $content);
}

/**
 * Callback for activate link
 */
function batire_user_register_activate($section = '') {
  global $user;

  $front_page = 'http://' . $_SERVER['HTTP_HOST'];

  /**
   * Logging user out, if logged in
   */
  if ($user->uid) {
    _batire_user_drupal_logout();
  }

  if ($section == 'transform') {
    $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation_trans'] = TRUE;
    setcookie('acc_activate', '1', NULL, '/'); //@todo need to repalce it
    _batire_site_set_cookie('acc_activate', '1');

    drupal_goto($front_page);
  }

  if (isset($_GET['id'])) {
    $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation_sub']['id'] = batire_site_check_text($_GET['id']);
    setcookie('acc_activate_sub', '1', NULL, '/'); //@todo need to repalce it
    _batire_site_set_cookie('acc_activate_sub', '1');
  }
  elseif (isset($_GET['fid'])) {
    $_SESSION[BATIRE_USERSESSION_NAMESPACE]['activation_free']['id'] = batire_site_check_text($_GET['fid']);
    setcookie('acc_activate_free', '1', NULL, '/'); //@todo need to repalce it
    _batire_site_set_cookie('acc_activate_free', '1');
  }
  else {
    setcookie('acc_activate', '1', NULL, '/'); //@todo need to repalce it
    _batire_site_set_cookie('acc_activate', '1');
  }

  drupal_goto($front_page);
}

/**
 * Mon compte Comptes utilisateurs export menu callback
 */
function batire_user_comptes_utilisateurs_export() {
  global $user;

  $members = mongodb_user_get_members();
  $data = array();

  $sorting_keys = array('surname', 'date_inscrit', 'date_invit', 'service');
  $sorting_key = 'surname';
  $sorting_direction = 'asc';
  if (isset($_GET['sort_by']) && in_array($_GET['sort_by'], $sorting_keys)) {
    $sorting_key = $_GET['sort_by'];
  }
  if (isset($_GET['sort']) && in_array($_GET['sort'], array('asc', 'desc'))) {
    $sorting_direction = $_GET['sort'];
  }

  foreach ($members as $member) {
    if (!$member['is_admin']) {
      $member_data = db_fetch_object(db_query('SELECT created FROM {users} WHERE uid = %d', $member['uid']));
      $data_item = array();
      $data_item['name'] = $member['name'];
      $data_item['surname'] = $member['surname'];
      $data_item['email'] = $member['mail'];
      $hash = md5($data_item['name'] . $data_item['surname'] . $data_item['email']);
      $data_item['date_invit'] = '';
      $data_item['date_inscrit'] = format_date($member_data->created, 'custom', 'd/m/Y');
      $data[$hash] = $data_item;
    }
  }

  //Get accounts from MySQL pre-reg table
  $accs = db_query('SELECT id, mail, data, created FROM {batire_user_registration_requests} WHERE uid = %d', $user->uid);
  while ($acc = db_fetch_object($accs)) {
    $member_data = unserialize($acc->data);
    $data_item = array();
    $data_item['name'] = $member_data->field_user_name[0]['value'];
    $data_item['surname'] = $member_data->field_user_surname[0]['value'];
    $data_item['email'] = $acc->mail;
    $hash = md5($data_item['name'] . $data_item['surname'] . $data_item['email']);
    $data_item['date_invit'] = format_date($acc->created, 'custom', 'd/m/Y');
    $data_item['date_inscrit'] = '';
    $data[$hash] = $data_item;
  }

  batire_site_summary_sort_by_val($data, $sorting_key, $sorting_direction == 'desc', $sorting_key == 'surname');

  $map = array(
    'map' => array(
      'A' => 'name',
      'B' => 'surname',
      'C' => 'email',
      'D' => 'date_invit',
      'E' => 'date_inscrit',
    ),
    'header' => array(
      'A' => t('Prenom'),
      'B' => t('Nom'),
      'C' => t('Email'),
      'D' => t('Date invitation'),
      'E' => t('Date inscription'),
    ),
  );


  $filepath = batire_site_generate_excel_file(batire_site_get_file_path('comptes_utilisateurs', array('uid' => $user->uid)), $map['map'], array_values($data), $map['header']);
  if ($filepath) {
    file_transfer($filepath, batire_site_get_file_headers('comptes_utilisateurs_' . $user->uid));
  }
  else {
    return t('Data not found');
  }
}

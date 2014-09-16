<?php

/**
 * @file
 * Helpers for the module
 */

/**
 * Makes a log out from drupal.
 *
 * For internal purposes.
 */
function _batire_user_drupal_logout() {
  global $user;
  /**
   * We need to log user out
   */
  watchdog('user', 'Session closed for %name.', array('%name' => $user->name));

  // Destroy the current session:
  session_destroy();

  // Fix for http://bugs.php.net/bug.php?id=32330
  session_set_save_handler('sess_open', 'sess_close', 'sess_read', 'sess_write', 'sess_destroy_sid', 'sess_gc');

  // Only variables can be passed by reference workaround.
  $null = NULL;
  user_module_invoke('logout', $null, $user);

  // Load the anonymous user
  $user = drupal_anonymous_user();
}

/**
 * Deletes all user sessions upon new login;
 */
function _batire_user_drop_all_user_sessions($uid) {
  db_query('DELETE FROM {sessions} WHERE uid = %d', $uid);
  if (function_exists('sess_destroy_uid')) {
    sess_destroy_uid($uid);
  }
}

/**
 * Loads user profile node
 * @param null $uid
 */
function batire_user_profile_load($uid = NULL, $reset = FALSE) {
  if (is_null($uid)) {
    global $user;
    $uid = $user->uid;
  }

  return content_profile_load(BATIRE_USER_PROFILE, $uid, '', $reset);
}

/**
 * Recovery password for selected email
 * @param type $email
 * @return array
 */
function _batire_user_forgot_password($email) {
  $result = array(
    'error' => FALSE,
    'message' => '',
  );
  try {
    $email = drupal_strtolower(batire_site_check_text($email));
    if (!batire_site_validate_email_address($email)) {
      throw new Exception(t('L\'adresse email que vous avez saisie n\'est pas reconnue.'));
    }
    /**
     * @todo need add query to db
     * We need to see if user is not activated subaccount, and if so - we
     * need to send him a link with activation.
     *
     * Otherwise - we need to send password recovery email.
     */
    // ....

    $svc_result = batire_svc_forgot_password($email);
    if ($svc_result['error']) {
      throw new Exception($svc_result['error']);
    }
    // Single entry found;
    if (count($svc_result['data']) == 1) {
      $abo_raw = $svc_result['data'][0]['account'];
      $abo_raw['logins_and_passwords'] = array($svc_result['data'][0]);
      $abo_raw['spacechar'] = TRUE;
      $data = (object) array(
        'data' => array(
          'abonement' => (object) $abo_raw
        ),
        'recepients' => array(
          $abo_raw['mail']
        ),
      );
      // send password recovery email
      // @todo need to send an email, old ready data in variable $data
      $send_mail = TRUE; // result of sending email
    }
    else {
      // Multiple entries found
      $email_data = array();
      foreach ($svc_result['data'] as $account) {
        $email_data[] = $account;
      }
      $data = (object) array(
        'data' => array(
          'abonement' => (object) array('logins_and_passwords' => $email_data)
        ),
        'recepients' => array(
          $account['account']['mail']
        ),
      );
      // send password recovery email
      // @todo need to send an email, old ready data in variable $data
      $send_mail = TRUE;
    }
    if (!$send_mail) {
      throw new Exception(
      t('Une erreur s\'est produite: impossible d\'envoyer les codes d\'accès.
       Nous vous invitons à recommencer ou à nous signaler cette anomalie en !link.', array('!link' => _cp_site_contact_link()))
      );
    }
    $result['message'] = t('Vos codes d\'accès ont bien été envoyés.');
  }
  catch (Exception $e) {
    $result['error'] = TRUE;
    $result['message'] = $e->getMessage();
  }
  return $result;
}

/**
 * Registration page title constructor
 * @param string $type
 *   Type of registration page
 */
function _batire_user_get_registration_page_title($type = NULL) {
  switch ($type) {
    case BATIRE_USER_REG_TYPE_DAD :
      return t('Demande de démonstration personnalisée');
    case BATIRE_USER_REG_TYPE_FREE :
    case BATIRE_USER_REG_TYPE_TRIAL_TN :
      return t('Inscription à l\'offre d\'essai gratuite');
    case 'activation':
      return t('Activation du compte');
    case BATIRE_USER_REG_TYPE_PAID :
    default :
      return t('Demande de devis personnalisé');
  }
}

/**
 * Registration page subtitle constructor
 * @param string $type
 *   Type of registration page
 */
function _batire_user_get_registration_page_subtitle($type = NULL) {
  switch ($type) {
    case 'activation':
     return t('Complétez si nécessaire les informations ci-dessous, puis validez le formulaire. !br Votre abonnement prendra effet immédiatement.', array('!br' => '<br>'));
    case BATIRE_USER_REG_TYPE_DAD :
      return t('Je souhaite une démonstration personnalisée et demande à être contacté par un conseiller');
    case BATIRE_USER_REG_TYPE_PAID :
      return t('Je souhaite un devis personnalisé !br et demande à être contacté par un conseiller', array('!br' => '<br>'));
  }
}

function _batire_user_salut_convert($salut, $flip = FALSE) {
  $salutations = array(
    'Monsieur' => 'M',
    'Madame' => 'MME',
    'Mademoiselle' => 'MLLE'
  );

  if ($flip) {
    $salutations = array_flip($salutations);
  }
  return isset($salutations[$salut]) ? $salutations[$salut] : '';
}

/**
 * Get name of registration role
 * @param $roles List of roles
 * @return Role name
 */
function _batire_user_get_registration_role($roles = array()) {
  global $user;
  if (!$roles) {
    $roles = array_keys($user->roles);
  }
  $user_roles = array(
    BATIRE_USER_PAIDACCOUNT => 'paid',
    BATIRE_USER_FREEACCOUNT => 'free',
    BATIRE_USER_MONTHACCOUNT => 'month',
    BATIRE_USER_TRIALTNACCOUNT => 'trialtn',
  );
  if (!empty($roles)) {
    foreach ($roles as $role) {
      if (array_key_exists($role, $user_roles)) {
        return _batire_user_get_registration_roles_name($user_roles[$role]);
      }
    }
  }
  return '';
}

/**
 * Get human readable roles
 * @param $role Type of role
 * @return Array | String List of roles OR
 */
function _batire_user_get_registration_roles_name($role = NULL) {
  $roles = array(
    'free' => t('Offre d’essai gratuite'),
    'paid' => t('Abonnement payant'),
    'month' => t('Offre Découverte'),
    'trialtn' => t('Offre d’essai gratuite avec TN'),
  );
  if ($role) {
    return $roles[$role];
  }
  return $roles;
}
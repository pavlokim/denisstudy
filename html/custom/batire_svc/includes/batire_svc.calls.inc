<?php

/**
 * @file
 * SVC calls for the module
 */

/**
 * Generic method to perform SVC calls
 * @param string $method
 *   Method to call
 * @param array $params
 *   Array of params
 */
function _batire_svc_call($method, $params = array()) {
  $client = _batire_svc_get_soap();
  $result = array(
    'error' => '',
    'data' => NULL
  );
  try {
    if (!$client) {
      throw new Exception(t('Couldn\'t connect to SVC.'), BATIRE_SITE_ERROR_SYSTEM);
    }
    $params['appelant'] = BATIRE_SVC_APPELANT_ID;
    $result['data'] = @$client->{$method}($params);
  }
  catch (Exception $e) {
    $result['error'] = batire_site_show_message($e->getMessage(), $e->getCode());
  }

  /**
   * We need to log debug information
   */
  _batire_svc_log($method, $params, $result['data'], $client);
  return $result;
}

/**
 * Login|Password recovery;
 */
function batire_svc_forgot_password($email) {
  $result = array(
    'error' => FALSE,
    'data' => array()
  );
  try {
    $search_result = batire_svc_search_by_email($email, 1000, 'OUBLI_MDP2');
    if ($search_result['data']) {
      $accounts = $search_result['data'];
      if (is_array($accounts) && count($accounts)) {
        foreach ($accounts as $account) {
          $profile = batire_svc_get_user_data($account['svc_id'], '', 'C');
          if (!$profile['error']) {
            $profile = _batire_svc_unpack_profile($profile['data']);
            $result['data'][] = array(
              'login' => $profile['login'],
              'pass' => $profile['pass'],
              'account' => $account
            );
          }
          else {
            throw new Exception(t('L\'adresse email que vous avez saisie n\'est pas reconnue.'), BATIRE_SITE_ERROR_USER);
          }
        }
      }
      else {
        throw new Exception(t('L\'adresse email que vous avez saisie n\'est pas reconnue.'), BATIRE_SITE_ERROR_USER);
      }
    }
    else {
      throw new Exception(t('L\'adresse email que vous avez saisie n\'est pas reconnue.'), BATIRE_SITE_ERROR_USER);
    }
  }
  catch (Exception $e) {
    $result['error'] = TRUE;
    $result['message'] = batire_site_show_message($e->getMessage(), $e->getCode());
  }
  return $result;
}

/**
 * Validates email using ChercherComptes method;
 */
function batire_svc_search_by_email($email, $limit = 1, $type = 'EMAIL') {
  $data = "<PARAMS><EMAIL>{$email}</EMAIL></PARAMS>";

  $result = batire_svc_account_search($data, $type, 0, $limit);

  if (isset($result['data']) && $result['data']) {
    return array(
      'data' => _batire_svc_unpack_search_results($result['data'])
    );
  }
  else {
    return $result;
  }
}

/**
 * Performs search for accounts;
 */
function batire_svc_account_search($data, $type = '', $from = 0, $limit = 1) {
  $result = array(
    'error' => FALSE,
    'code' => 0
  );
  try {
    $params = array(
      'xmlParam' => $data,
      'format' => 'XML',
      'from' => $from,
      'kind' => $type,
      'nbRows' => $limit,
      'xmlOptions' => ''
    );
    $code = 0;
    $response = _batire_svc_call('ChercherComptes', $params);
    if ($response['error']) {
      throw new Exception($response['error'], $code);
    }

    $data = &$response['data']->ChercherComptesResult;
    if ($data->Return != 1) {
      throw new Exception(t('ChercherComptes::Unknown error'), BATIRE_SVC_SEARCH_ERROR);
    }
    else {
      if (!$data->NbComptesTotal) {
        throw new Exception(t('Search returned no results'), BATIRE_SVC_SEARCH_NO_RESULT);
      }
      else {
        $result['data'] = $data->XmlComptes;
      }
    }
  }
  catch (Exception $e) {
    $result['error'] = $e->getMessage();
    $result['code'] = $e->getCode();
  }
  return $result;
}

/**
 * Get account data method.
 * Params:
 *  AS_APPELANT = Code du site (ex : ‘ROI’),
 *  AS_LOGIN = code d’accès ou NULL si AS_IDABONNE renseigné,
 *  AS_IDCOMPTE  = identifiant du compte utilisateur ou NULL si AS_LOGIN renseigné,
 *  AS_KIND = Type d’information demandé (ex : ‘CSPTX’ ou ‘CSP’ ou ‘*’ etc.) (cf. syntaxe et signification ci-dessous),
 *  AS_FORMAT = Chaine vide ou NULL (non utilisé dans cette version)
 * Response:
 *  OS_COMPTE = Chaîne XML contenant les informations générales du compte utilisateur (cf. schéma et exemple en annexe),
 *  OS_SIGNALETIQUE = Chaine XML contenant les informations de signalétique du compte utilisateur (cf. schéma et exemple en annexe),
 *  OS_PREFERENCES = Chaine XML contenant les préférences de l’utilisateur (accepte ou non informations commerciales, etc.) (cf. schéma et exemple en annexe),
 *  OS_SUIVI = Chaine XML contenant des informations de suivi du compte utilisateur (cf. schéma et exemple en annexe),
 *  OS_COMPLEMENT = Chaine XML contenant des informations complémentaire (cf. schéma et exemple en annexe) Non utilisé ROI
 *  OS_RESULT = 1 : OK, 2 : Compte utilisateur inconnu
 */
function batire_svc_get_user_data($svc_id = '', $login = '', $info_type = '*') {
  $result = array(
    'error' => '',
    'data'  => NULL
  );
  try {
    $params = array(
      'login'    => $login,
      'idCompte' => $svc_id,
      'kind'     => $info_type,
      'format'   => ''
    );
    $response = _batire_svc_call('LireCompte', $params);
    if ($response['error']) {
      throw new Exception(t('Votre identifiant ne vous permet pas d\'accéder au site'), BATIRE_SITE_ERROR_USER);
    }
    switch ($response['data']->LireCompteResult->Return) {
      case 1 :
        $result['data'] = $response['data']->LireCompteResult;
        break;
      case 2 :
        throw new Exception(t('Compte utilisateur inconnu'), BATIRE_SITE_ERROR_USER);
        break;
      default:
        throw new Exception(t('LireCompte::Unknown error'), BATIRE_SITE_ERROR_USER);
        break;
    }
  }
  catch (Exception $e) {
    $result['error'] = batire_site_show_message($e->getMessage(), $e->getCode());
  }
  return $result;
}

/**
 * Adds an abonnement number to account
 */
function batire_svc_add_abonnement_number($abon_no, $svc_id = '', $login = '') {
  $result = array('error' => FALSE);

  if (!$svc_id && !$login) {
    $result['error'] = t('Une erreur s\'est produite: nous vous invitons à recommencer ou à nous
                          signaler cette anomalie en !link', array('!link' => batire_site_contact_link())
    );
  }
  else {
    $params = array(
      'login' => $login,
      'idCompte' => $svc_id,
      'noAbonne' => $abon_no,
      'origine' => BATIRE_SVC_APPELANT_ID,
      'xmlOptions' => ''
    );

    $response = _batire_svc_call('AjouterNoAbonne', $params);

    if ($response['error']) {
      $result['error'] = $response['error'];
    }
    else {
      $error = 'AjouterNoAbonne::Unknown error';
      switch ($response['data']->AjouterNoAbonneResult) {
        case 0 :
          $error = 'Abonné non trouvé';
          break;
        case 1 :
          $error = FALSE;
          break;
        case 3 :
          $error = 'Compte utilisateur non trouvé';
          break;
        case 8 :
          $error = 'Numéro d\'abonné non renseigné';
          break;
        case 9 :
          $error = 'Non elligible';
          break;
      }

      if ($error) {
        $result['error'] = t($error);
      }
    }
  }

  return $result;
}

/**
 * Removes abonnement number from account
 */
function batire_svc_remove_abonnement_number($svc_id = '', $login = '', $abon_no) {
  $result = array('error' => FALSE);

  if (!$svc_id && !$login) {
    $result['error'] = t('Une erreur s\'est produite: nous vous invitons à recommencer ou à nous
                          signaler cette anomalie en !link', array('!link' => batire_site_contact_link())
    );
  }
  else {
    $params = array(
      'login' => $login,
      'idCompte' => $svc_id,
      'noAbonne' => $abon_no,
      'origine' => BATIRE_SVC_APPELANT_ID,
      'xmlOptions' => ''
    );

    $response = _batire_svc_call('SupprimerNoAbonne', $params);

    if ($response['error']) {
      $result['error'] = $response['error'];
    }
    else {
      $error = 'SupprimerNoAbonne::Unknown error';
      switch ($response['data']->SupprimerNoAbonneResult) {
        case 0 :
          $error = 'Abonné non trouvé';
          break;
        case 1 :
          $error = FALSE;
          break;
        case 3 :
          $error = 'Compte utilisateur non trouvé';
          break;
        case 8 :
          $error = 'Numéro d\'abonné non renseigné';
          break;
        case 9 :
          $error = 'Non elligible';
          break;
      }

      if ($error) {
        $result['error'] = t($error);
      }
    }
  }

  return $result;
}

/**
 * Verifies if for given email was assigned given abon no..
 * @param $email
 * @param $abon_no
 */
function batire_svc_verify_email_and_abon($email, $abon_no) {
  $result = array('error' => FALSE);

  $response = batire_svc_search_by_email($email);
  if ($response['error']) {
    $result['error'] = t('Your email has not been found');
  }
  else {
    /**
     * User is registered with SVC, now we need to check abonnement
     */
    $response = array_shift($response['data']);
    $response = batire_svc_get_user_data($response['svc_id']);

    if ($response['error']) {
      $result['error'] = $response['error'];
    }
    else {
      $abon_validation_response = batire_svc_validate_abon_num($abon_no);
      if ($abon_validation_response['error']) {
        $result['error'] = $abon_validation_response['error'];
      }
      else {
        /**
         * Here we need to check if abonnement number is payant
         */
        if (_batire_user_is_abbo_free($abon_no)) {
          $result['error'] = t('This abonnement number is for free offer');
        }
      }
    }
  }
  return $result;
}

/**
 * Gets number of allowed subaccounts per abonement
 */
function batire_svc_get_number_of_accounts_by_product($abon_no) {
  $result = array('error' => FALSE, 'count' => 0);

  $params = array(
    'noAbonne' => $abon_no,
    'idAbonne' => '',
    'codeProduitSVC' => BATIRE_SVC_PRODUCT_ID
  );

  $response = _batire_svc_call('LireNbExemplairesAbonneParProduit', $params);

  if ($response['error']) {
    $result['error'] = t('Votre identifiant ne vous permet pas d\'accéder au site');
  }
  elseif ($response['data']->LireNbExemplairesAbonneParProduitResult->Return != 1) {
    $result['error'] = t('Ces identifiants ne vous donnent pas accès à Kheox');
  }
  else {
    if ($response['data']->LireNbExemplairesAbonneParProduitResult->NbExemplaires) {
      $result['count'] = $response['data']->LireNbExemplairesAbonneParProduitResult->NbExemplaires;
    }
    else {
      $result['count'] = 1;
    }
    //Additionaly we should check nbex of each product and set max value
    $abonnement_info_raw = batire_svc_get_abonnement_info((string)$abon_no);
    if (!$abonnement_info_raw['error']) {
      $xmlDoc = simplexml_load_string($abonnement_info_raw['abonnement_info']);
      foreach ($xmlDoc->ABONNE->ABONNEMENT as $abonnement) {
        $nbex[] = (int)$abonnement->NBEX;
      }
      !empty($nbex) ? $result['count'] = max($nbex) : '';
    }
  }

  return $result;
}

/**
 * Get user abonnement by product id
 * @param string $svc_id
 * @param string $login
 * @return array
 */
function batire_svc_get_user_abonnement_by_product($svc_id = '', $login = '') {
  $result = array('error' => FALSE, 'abonnement' => '');

  try {
    $params = array(
      'login'            => $login,
      'idCompte'         => $svc_id,
      'format'           => '',
      'categorieProduit' => '',
      'codeProduit'      => BATIRE_SVC_PRODUCT_ID,
      'etat'             => ''

    );

    $response = _batire_svc_call('LireCompteAbonnementsPour', $params);

    if ($response['error']) {
      throw new Exception($response['error'], BATIRE_SITE_ERROR_USER);
    }

    switch ($response['data']->LireCompteAbonnementsPourResult->Return) {
      case 1 :
        $abonnement = _batire_svc_parse_user_abonnement($response['data']->LireCompteAbonnementsPourResult->XmlAbonnes);
        if (!$abonnement) {
          throw new Exception(t('Votre identifiant ne vous permet pas d\'accéder au site'), BATIRE_SITE_ERROR_USER);
        }

        $result['abonnement'] = $abonnement;
        break;
      default:
        throw new Exception(t('Error getting abonnement by product'), BATIRE_SITE_ERROR_SYSTEM);
    }
  }
  catch (Exception $e) {
    $result['error'] = batire_site_show_message($e->getMessage(), $e->getCode());
  }

  return $result;
}

/**
 * Gets list of user abonnements;
 */
function batire_svc_get_user_abonnements($svc_id = '', $login = '') {
  $result = array('error' => FALSE, 'abonnements' => array());

  $params = array(
    'login' => $login,
    'idCompte' => $svc_id,
    'format' => '*'
  );

  $response = _batire_svc_call('LireCompteAbonnes', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
    return $result;
  }

  $error = 'LireCompteAbonnes::Unknown error';

  switch ($response['data']->LireCompteAbonnesResult->Return) {
    case 0 :
      $error = 'Error getting abonnement list';
      break;
    case 1 :
      $error = FALSE;
      break;
  }

  if ($error) {
    $result['error'] = t($error);
  }

  $result['abonnements'] = $response['data']->LireCompteAbonnesResult->XmlAbonnes;

  return $result;
}

/**
 * Permet de récupérer la liste des abonnements liés à un numéro d'abonné.
 *
 * @param $abon_num
 * @param bool $format
 * Format / contenu attendu (valeurs possibles : "V1", "ABONNE_SEUL", "ABONNE_ABONNEMENT", "ABONNE_ABONNEMENT_COMP", "EXTRAIT")
 */
function batire_svc_get_abonnement_info($abon_num, $format = FALSE) {
  $result = array('error' => FALSE, 'abonnement_info' => array());

  $params = array(
    'noAbonne'  => $abon_num,
    'idAbonne'  => '',
    'format'    => $format ? $format : 'ABONNE_ABONNEMENT_COMP'
  );

  $response = _batire_svc_call('LireAbonneAbonnements', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
    return $result;
  }

  if (1 == $response['data']->LireAbonneAbonnementsResult->Return) {
    $result['abonnement_info'] = $response['data']->LireAbonneAbonnementsResult->XmlAbonnes;
  }
  else {
    $result['error'] = t('Votre identifiant ne vous permet pas d\'accéder au site');
  }

  return $result;
}

/**
 * Is user authorized to access given space method.
 * Params:
 *  AS_APPELANT = Code du site (ex : ‘ROI’),
 *  AS_LOGIN = code d’accès ou NULL si AS_IDABONNE renseigné,
 *  AS_IDCOMPTE  = identifiant du compte utilisateur ou NULL si AS_LOGIN renseigné,
 *  AS_CODEESPACE = Code du space pour lequel on souhaite lister les espaces réservés,
 * Response:
 * @todo - to be clarified
 */
function batire_svc_is_authorised_for($svc_id, $login, $space_code) {
  $result = array('error' => FALSE);

  $params = array(
    'login' => $login,
    'idCompte' => $svc_id,
    'codeEspace' => $space_code
  );

  $response = _batire_svc_call('EstAutorisePour', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
    return $result;
  }

  $error = 'EstAutorisePour::Unknown error';

  switch ($response['data']->EstAutorisePourResult) {
    case 0 :
      $error = 'You are not authorized to access this page';
      break;
    case 1 :
      $error = FALSE;
      break;
    case 2 :
      $error = 'Identifiant ou mot de passe non reconnu';
      break;
  }

  if ($error) {
    $result['error'] = t($error);
  }

  return $result;
}

/**
 * Getter authorized spaces for user.
 * Params:
 *  AS_APPELANT = Code du site (ex : ‘ROI’),
 *  AS_LOGIN = code d’accès ou NULL si AS_IDABONNE renseigné,
 *  AS_IDCOMPTE  = identifiant du compte utilisateur ou NULL si AS_LOGIN renseigné,
 *  AS_CODESITE = Code du site pour lequel on souhaite lister les espaces réservés (ex : ‘ROI’),
 * Response:
 *  OS_RESULT = liste des espaces autorisés auxquels le compte utilisateur à droit.
 *              Format = chaine de caractère contenant la liste des codes espaces séparés par des virgules s’il y en a plusieurs ou chaine vide s’il n’y en a aucun,
 *              Ex : ‘MOL01,MOL02’
 *              Ex pour ROI : ‘ROI01’
 */
function batire_svc_get_authorized_spaces($svc_id = '', $login = '', $code_site = NULL) {
  $result = array('error' => FALSE);

  $code_site = $code_site ? $code_site : BATIRE_SVC_APPELANT_ID;

  $params = array(
    'login'    => $login,
    'idCompte' => $svc_id,
    'codeSite' => $code_site
  );

  $response = _batire_svc_call('ListeEspacesAutorises', $params);

  if ($response['error']) {
    $result['error'] = t('Votre abonnement ne vous permet pas de profiter de ce service.');
  }
  else {
    $data = @explode('|', $response['data']->ListeEspacesAutorisesResult);
    if (!_batire_svc_validate_spaces($data, BATIRE_SVC_PRODUCT_ID)) {
      $result['error'] = t('Votre abonnement ne vous permet pas de profiter de ce service.');
    }
  }

  return $result;
}

/**
 * Getter authorized spaces for user by abonement.
 * Params:
 *  AS_APPELANT = Code du site (ex : ‘ROI’),
 *  AS_NUMABONNE = numéro d’abonné saisi par l’utilisateur
 *  AS_IDABONNE = NULL
 *  AS_CODESITE = Code du site pour lequel on souhaite lister les espaces réservés (ex : ‘ROI’),
 * Response:
 *  i.OS_RESULT = liste des espaces autorisés auxquels le numéro d’abonné donne droit. Format = chaine de caractère contenant la liste des codes espaces séparés par des virgules s’il y en a plusieurs ou chaine vide s’il n’y en a aucun,
 *    1.Ex : ‘MOL01,MOL02’
 *    2.Ex pour ROI : ‘ROI01’
 */
function batire_svc_get_authorized_spaces_by_abon($abon_no, $code_site = NULL) {
  $result = array('error' => FALSE);

  $code_site = $code_site ? $code_site : BATIRE_SVC_APPELANT_ID;

  $params = array(
    'noAbonne' => $abon_no,
    'idAbonne' => '',
    'codeSite' => $code_site
  );

  $response = _batire_svc_call('ListeEspacesAutorisesAbonne', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
  }
  else {
    $data = @explode('|', $response['data']->ListeEspacesAutorisesAbonneResult);
    if (!_batire_svc_validate_spaces($data, BATIRE_SVC_PRODUCT_ID)) {
      $result['error'] = t('Votre numéro d\'abonné ne lui donne pas le
                            droit d\'accéder au site');
    }
  }

  return $result;
}

/**
 * User registration method.
 * Params:
 *  AS_APPELANT = Code du site (ex : ‘ROI’),
 *  AS_LOGIN = Code d’accès choisi par l’utilisateur,
 *  AS_NOABONNE = Numéro d’abonné saisi par l’utilisateur,
 *  AS_PASSWORD = Mot de passe choisi par l’utilisateur,
 *  AS_EMAIL = Email saisi par l’utilisateur,
 *  AS_ORIGINE = Chaine vide ou NULL (non utilisé dans ce cas),
 *  AS_IDEXTERNE = Chaine vide ou NULL (non utilisée dans ce cas),
 *  AS_OPTIONS = Chaine vide ou NULL (non utilisé dans cette version),
 *  AS_KIND = Type d’information fournis (ex : ‘CSPTX’ ou ‘CSP’, etc.) (cf. syntaxe et signification ci-dessous),
 *  AS_FORMAT = Chaine vide ou NULL (non utilisé dans ce cas),
 *  AS_COMPTE = Chaîne XML contenant les informations générales du compte utilisateur (cf. schéma et exemple en annexe),
 *  AS_SIGNALETIQUE = Chaine XML contenant les informations de signalétique du compte utilisateur (cf. schéma et exemple en annexe),
 *  AS_PREFERENCES = Chaine XML contenant les préférences de l’utilisateur (accepte ou non informations commerciales, etc.) (cf. schéma et exemple en annexe),
 *  AS_SUIVI = Chaine vide,
 *  AS_COMPLEMENT = Chaine XML contenant des informations complémentaire ou chaîne vide
 * Response:
 *  OS_IDCOMPTE = Identifiant unique du compte utilisateur créé au sein du SVC ou NULL,
 *  OS_RESULT = 1 : OK, 2 : Code d’accès existe déjà, 3 : une des données obligatoire est manquante (email, civilité, nom, prénom, raison sociale, code postal, ville)
 */
function batire_svc_register_user($info) {
  $result = array('error' => FALSE, 'id' => 0);

  $params = array(
    'login' => $info['name'],
    'password' => $info['pass'],
    'noAbonne' => $info['abon_no'],
    'email' => $info['mail'],
    'origine' => BATIRE_SVC_APPELANT_ID,
    'idExterne' => '',
    'xmlOptions' => '',
    'kind' => '*',
    'format' => '',
    'xmlCompte' => _batire_svc_build_compte($info),
    'xmlSignaletique' => _batire_svc_build_signaletique($info),
    'xmlPreferences' => _batire_svc_build_preferences($info),
    'xmlSuivi' => '',
    'xmlComplement' => '' //@todo: figure out what is it for ?
  );

  $response = _batire_svc_call('InscrireComplet', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
    return $result;
  }

  $error = 'InscrireComplet::Unknown error';

  switch ($response['data']->InscrireCompletResult->Return) {
    case 1 :
      $error = FALSE;
      break;
    case 2 :
      $error = 'Le code d\'accès existe déjà';
      break;
    case 3 :
      $error = 'Une des données obligatoire est manquante (email, civilité, nom, prénom, raison sociale, code postal, ville)';
      break;
    case 4 :
      $error = 'Mot de passe incorrect';
      break;
    case 5 :
      $error = 'Email incorrect';
      break;
  }

  if ($error) {
    $result['error'] = t($error);
  }
  else {
    $result['id'] = $response['data']->InscrireCompletResult->IdCompte;
  }

  return $result;
}

/**
 * Inscription simple d'un nouveau compte utilisateur
 */
function batire_svc_register_user_simple($info) {
  $result = array('error' => FALSE, 'id' => 0);

  $params = array(
    'login' => $info['name'],
    'password' => $info['pass'],
    'noAbonne' => $info['abon_no'],
    'email' => $info['mail'],
    'origine' => BATIRE_SVC_APPELANT_ID,
    'idExterne' => ''
  );

  $response = _batire_svc_call('InscrireSimple', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
    return $result;
  }

  $error = 'InscrireSimple::Unknown error';

  switch ($response['data']->InscrireSimpleResult->Return) {
    case 1 :
      $error = FALSE;
      break;
    case 2 :
      $error = 'Le code d\'accès existe déjà';
      break;
    case 3 :
      $error = 'Une des données obligatoire est manquante (email, civilité, nom, prénom, raison sociale, code postal, ville)';
      break;
    case 4 :
      $error = 'Mot de passe incorrect';
      break;
    case 5 :
      $error = 'Email incorrect';
      break;
  }

  if ($error) {
    $result['error'] = t($error);
  }
  else {
    $result['id'] = $response['data']->InscrireSimpleResult->IdCompte;
  }

  return $result;
}

/**
 * Access codes validation method.
 * Params:
 *  AS_APPELANT = Code du site (ex : ‘ROI’),
 *  AS_LOGIN = code d’accès choisi par l’utilisateur,
 *  AS_PASSWORD = mot de passe choisi par l’utilisateur,
 *  AS_EMAIL = adresse email saisie par l’utilisateur
 * Response:
 *  OS_RESULT = 1 : OK, 2 : Le code d’accès existe déjà, 3 : Le code d’accès n’est pas correct (moins de 4 caractères),
 *              4 : Le mot de passe n’est pas correct (moins de 4 caractères, 5 : email incorrect
 */
function batire_svc_validate_access_codes($login, $password, $email) {
  $result = array('error' => array('element' => NULL, 'message' => '', 'code' => 0));

  $params = array(
    'login' => $login,
    'password' => $password,
    'email' => $email
  );

  $response = _batire_svc_call('VerifValiditeInfosAcces', $params);

  if ($response['error']) {
    $result['error']['element'] = 'form';
    $result['error']['message'] = $response['error'];
    return $result;
  }

  $error = 'VerifValiditeInfosAcces::Unknown error';

  switch ($response['data']->VerifValiditeInfosAccesResult) {
    case 1 :
      $error = FALSE;
      break;
    case 2 :
      $error = 'Le code d\'accès existe déjà';
      $result['error']['element'] = 'name';
      break;
    case 3 :
      $error = 'Le code d\'accès n\'est pas correct (moins de 4 caractères)';
      $result['error']['element'] = 'name';
      break;
    case 4 :
      $error = 'Le mot de passe n\'est pas correct (moins de 4 caractères)';
      $result['error']['element'] = 'pass';
      break;
    case 5 :
      $error = 'Email incorrect';
      $result['error']['element'] = 'mail';
      break;
  }

  if ($error) {
    $result['error']['code'] = $response['data']->VerifValiditeInfosAccesResult;
    $result['error']['message'] = t($error);
  }

  return $result;
}

/**
 * Abonnement validation method.
 * Params:
 *  AS_APPELANT = Code du site (ex : ‘ROI’)
 *  AS_NOABONNE = numéro d’abonné saisi par l’utilisateur
 * Response:
 *  OS_EXISTE = 1 si le numéro d’abonné existe, 0 sinon,
 *  OS_CODEVALIDITE =  1 si le numéro d’abonné est actif, 9 s’il est inactif,
 *  OS_NBCOMPTES = pour information, nombre de comptes utilisateur déjà attaché à ce numéro d’abonné,
 *  OS_RESULT = ne pas exploiter dans ce cas
 */
function batire_svc_validate_abon_num($abon_id) {
  $result = array('error' => FALSE, 'data' => NULL);
  $params = array('noAbonne' => $abon_id);

  $response = _batire_svc_call('VerifValiditeNoAbonne', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
    return $result;
  }
  $res = $response['data']->VerifValiditeNoAbonneResult;

  if (!($res->Existe == 1 && $res->CodeValidite == 1)) {
    $result['error'] = t(
      'Vos identifiants ne vous donnent pas accès à !site_name.
      Nous vous invitons à nous contacter en !link.', array('!site_name' => SITE_NAME_FS, '!link' => batire_site_contact_link())
    );
  }
  else {
    unset($res->Existe);
    unset($res->CodeValidite);
    $result['data'] = $res;
  }

  return $result;
}

/**
 * Mise à jour des informations simples du compte utilisateur (login, mot de passe, email)
 * @param int $svc_id
 *   Id of the user in SVC
 * @param array $data
 *   'login' - new login, if changed
 *   'pass'  - new password, if changed
 *   'email' - new email, if changed
 */
function batire_svc_modify_user_access_data($svc_id, $data) {
  $result = array('error' => FALSE);

  $params = array(
    'login' => '',
    'idCompte' => $svc_id,
    'newLogin' => $data['login'],
    'newPassword' => $data['password'],
    'email' => $data['field_user_email']
  );

  $response = _batire_svc_call('MajCompteSimple', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
    return $result;
  }

  $error = t(
  'Une erreur s\'est produite: nous vous invitons à recommencer ou à nous
     signaler cette anomalie en !link', array('!link' => batire_site_contact_link())
  );

  switch ($response['data']->MajCompteSimpleResult) {
    case 1 :
      $error = FALSE;
      break;
    case 2 :
      $error = t('Une des données obligatoire est manquante (email, civilité, nom, prénom, raison sociale, code postal, ville)');
      break;
  }

  if ($error) {
    $result['error'] = $error;
  }

  return $result;
}

/**
 * Modify account data method.
 * Params:
 *  AS_APPELANT = Code du site (ex : ‘ROI’),
 *  AS_LOGIN = code d’accès ou NULL si AS_IDABONNE renseigné,
 *  AS_IDCOMPTE  = identifiant du compte utilisateur ou NULL si AS_LOGIN renseigné,
 *  AS_KIND = Type d’information fournis (ex : ‘CSPTX’ ou ‘CSP’, etc.) (cf. syntaxe et signification ci-dessous),
 *  AS_FORMAT = Chaine vide (non utilisé dans ce cas),
 *  AS_COMPTE = Chaîne XML contenant les informations générales du compte utilisateur (cf. schéma et exemple en annexe),
 *  AS_SIGNALETIQUE = Chaine XML contenant les informations de signalétique du compte utilisateur (cf. schéma et exemple en annexe),
 *  AS_PREFERENCES = Chaine XML contenant les préférences de l’utilisateur (accepte ou non informations commerciales, etc.) (cf. schéma et exemple en annexe),
 *  AS_SUIVI = Chaine vide,
 *  AS_COMPLEMENT = Chaine XML contenant des informations complémentaire ou chaîne vide
 * Response:
 *   OS_RESULT = 1 : OK, 3 : une des données obligatoire est manquante (email, civilité, nom, prénom, raison sociale, code postal, ville)
 */
function batire_svc_modify_user_data($svc_id, $login, $info, $info_type = '*') {
  $result = array('error' => FALSE);

  /**
   * @todo - field TVA is not being sent to SVC.
   */
  $params = array(
    'login' => $login,
    'idCompte' => $svc_id,
    'kind' => $info_type,
    'format' => '',
    'xmlCompte' => _batire_svc_build_compte($info, $svc_id),
    'xmlSignaletique' => _batire_svc_build_signaletique($info),
    'xmlPreferences' => _batire_svc_build_preferences($info),
    'xmlSuivi' => '',
    'xmlComplement' => '' // @todo - figure out what is it for ?
  );

  $response = _batire_svc_call('MajCompte', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
    return $result;
  }

  $error = 'MajCompte::Unknown error';

  switch ($response['data']->MajCompteResult) {
    case 1 :
      $error = FALSE;
      break;
    case 3 :
      $error = 'Une des données obligatoire est manquante (email, civilité, nom, prénom, raison sociale, code postal, ville)';
      break;
  }

  if ($error) {
    $result['error'] = t($error);
  }

  return $result;
}

/**
 * User authentication method.
 * Params:
 *  AS_APPELANT = code du site (ex : ‘ROI’),
 *  AS_LOGIN = code d’accès,
 *  AS_PASSWORD = mot de passe
 * Response:
 *  OS_VALIDITE = 1 : Authentification OK, 2 : Code d’accès inconnu, 3 : Mot de passe inconnu,
 *  OS_IDCOMPTE = Identifiant du compte au sein du SVC,
 *  OS_ETAT = Etat du compte utilisateur,
 *  OS_STATUT = Statut du compte utilisateur,
 *  OS_CONFORMITE = Conformité des données du compte utilisateur
 */
function batire_svc_authentificate($login, $password) {
  $result = array(
    'error' => array('element' => NULL, 'message' => ''),
    'id' => 0
  );

  $params = array(
    'login' => $login,
    'password' => $password
  );
  $response = _batire_svc_call('Authentifier', $params);

  if ($response['error']) {
    $result['error']['message'] = t('Identifiant ou mot de passe non reconnu.');
    return $result;
  }

  $error = t('Identifiant ou mot de passe non reconnu.');

  switch ($response['data']->AuthentifierResult->Validite) {
    case 1 :
      $error = FALSE;
      break;
    case 2 :
      $error = 'Code d\'accès inconnu';
      break;
    case 3 :
      $error = 'Mot de passe inconnu';
      break;
  }

  if ($error) {
    $result['error']['message'] = t($error);
  }
  else {
    $result['id'] = $response['data']->AuthentifierResult->IdCompte;
  }

  return $result;
}

/**
 * Checks existence of login in SVC;
 */
function batire_svc_login_exists($login) {
  static $logins;

  if (!isset($logins[$login])) {
    $data = batire_svc_get_user_data('', $login, 'C');
    if (!$data['error'] && isset($data['data'])) {
      $data = _batire_svc_unpack_profile($data['data']);
      $logins[$login] = isset($data['cpt_id']) ?
      array('login' => $data['login'], 'pass' => $data['pass'], 'svc_id' => $data['cpt_id']) :
      array();
    }
    else {
      $logins[$login] = array();
    }
  }

  return $logins[$login];
}

/**
 * Returns list of logins and passwords associated with passed email.
 */
function batire_svc_get_logins_passwords_list($email, &$error = '') {
  $result = batire_svc_search_by_email($email, 1000, 'OUBLI_MDP2');

  $email_data = array();

  if (!$result['error']) {
    foreach ($result['data'] as $found_account) {
      $found_profile = batire_svc_get_user_data($found_account['svc_id'], '', 'C');
      if (!$found_profile['error']) {
        $found_profile = _batire_svc_unpack_profile($found_profile['data']);
        $email_data[] = array(
          'login' => $found_profile['login'],
          'pass' => $found_profile['pass']
        );
      }
    }
  }
  else {
    $error = $result['error'];
  }

  return $email_data;
}

function batire_svc_insert_mapping($site, $map_code, $cpt_id, $login = '', $map_type = 'IP') {
  $result = array('error' => FALSE);

  $params = array(
    'codeSite' => $site,
    'typeMapping' => $map_type,
    'mapCode' => $map_code,
    'login' => $login,
    'idCompte' => $cpt_id,
  );
  $response = _batire_svc_call('InsertMapping', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
    return $result;
  }

  switch ($response['data']->InsertMappingResult) {
    case 1:
      $error = FALSE;
      break;
    case 2:
      $error = 'User account not found';
      break;
    case 4:
      $error = 'Record already exists';
      break;
  }

  if ($error) {
    $result['error'] = t($error);
  }

  return $result;
}

function batire_svc_update_mapping($site, $map_code, $cpt_id, $login ='', $map_type = 'IP') {
  $result = array('error' => FALSE);

  $params = array(
    'codeSite' => $site,
    'typeMapping' => $map_type,
    'mapCode' => $map_code,
    'login' => $login,
    'idCompte' => $cpt_id,
  );
  $response = _batire_svc_call('UpdateMapping', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
    return $result;
  }

  switch ($response['data']->UpdateMappingResult) {
    case 1:
      $error = FALSE;
      break;
    case 2:
      $error = 'User account not found';
      break;
    case 3:
      $error = 'Record not found';
      break;
  }

  if ($error) {
    $result['error'] = t($error);
  }

  return $result;
}

function batire_svc_delete_mapping($site, $map_code, $map_type = 'IP') {
  $result = array('error' => FALSE);

  $params = array(
    'codeSite' => $site,
    'typeMapping' => $map_type,
    'mapCode' => $map_code,
  );
  $response = _batire_svc_call('DeleteMapping', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
    return $result;
  }

  switch ($response['data']->DeleteMappingResult) {
    case 1:
      $error = FALSE;
      break;
    case 3:
      $error = 'Record not found';
      break;
  }

  if ($error) {
    $result['error'] = t($error);
  }

  return $result;
}

function batire_svc_get_svc_id_by_mapping($site, $map_code, $map_type = 'IP') {
  $result = array('error' => FALSE);

  $params = array(
    'codeSite' => $site,
    'typeMapping' => $map_type,
    'mapCode' => $map_code,
  );
  $response = _batire_svc_call('LireCompteIdPourMapping', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
    return $result;
  }

  switch ($response['data']->LireCompteIdPourMappingResult) {
    case 1:
      $error = FALSE;
      break;
    case 3:
      $error = 'Record not found';
      break;
  }

  if ($error) {
    $result['error'] = t($error);
  }
  else {
    $result['svc_id'] = $response['data']->LireCompteIdPourMappingResult->IdCompte;
  }

  return $result;
}

function batire_svc_get_user_mapping($site, $cpt_id, $login = '', $map_type = 'IP') {
  $result = array('error' => FALSE);

  $params = array(
    'login' => $login,
    'idCompte' => $cpt_id,
    'codeSite' => $site,
    'typeMapping' => $map_type,
  );
  $response = _batire_svc_call('LireCompteMapping', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
    return $result;
  }

  switch ($response['data']->LireCompteMappingResult->Return) {
    case 1:
      $error = FALSE;
      break;
    default:
      $error = 'Error retrieving user mappings';
      break;
  }

  if ($error) {
    $result['error'] = t($error);
  }
  else {
    $result['mappings'] = $response['data']->LireCompteMappingResult->XmlMapping;
  }

  return $result;
}

function batire_svc_get_site_mapping($site, $map_type = 'IP') {
  $result = array('error' => FALSE);

  $params = array(
    'codeSite' => $site,
    'typeMapping' => $map_type,
  );
  $response = _batire_svc_call('LireSiteMapping', $params);

  if ($response['error']) {
    $result['error'] = $response['error'];
    return $result;
  }

  switch ($response['data']->LireSiteMappingResult->Return) {
    case 1:
      $error = FALSE;
      break;
    default:
      $error = 'Error retrieving site mappings';
      break;
  }

  if ($error) {
    $result['error'] = t($error);
  }
  else {
    $result['mappings'] = $response['data']->LireSiteMappingResult->XmlMapping;
  }

  return $result;
}

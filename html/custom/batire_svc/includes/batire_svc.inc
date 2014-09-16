<?php
/**
 * @file
 * Helpers for the module
 */



/***************** OLD CODE *****************************/

/**
 * Converts profile data from XML to array
 * @param $profile - an array of XML
 * @todo DOMDocument vs simplexml
 */
function _batire_svc_unpack_profile($xml_profile) {
  $profile = array();
  $xml_doc = new DOMDocument();
  if ($xml_profile->XmlCompte) {
    /**
     * Loading data from profile;
     */
    $mappings = array(
      'login'       => 'CPT_LOGIN',
      'pass'        => 'CPT_PASSWORD',
      'mail'        => 'CPT_EMAIL',
      'abon_no'     => 'CPT_NOABO',
      'user_status' => 'CPT_ETAT',  //@todo - what is it for ?
      'user_statut' => 'CPT_STATUT', //@todo - what is it for ?
      'compliance'  => 'CPT_CONF',
      'cpt_id'      => 'CPT_ID'
    );

    $xml_doc->loadXML($xml_profile->XmlCompte);
    foreach ($mappings as $key => $tag) {
      $item = $xml_doc->getElementsByTagName($tag)->item(0);
      $profile[$key] = $item->nodeValue;
    }
  }

  if ($xml_profile->XmlPreferences) {
    /**
     * Loading data from preferences;
     */
    $mappings = array(
      'opt_1'     => 'CPT_ACCINFCOM',
      'opt_2'     => 'CPT_ACCINFPRT',
      'language'  => 'CPT_LANG'
    );
    $xml_doc->loadXML($xml_profile->XmlPreferences);
    foreach ($mappings as $key => $tag) {
      $item = $xml_doc->getElementsByTagName($tag)->item(0);
      $profile[$key] = $item->nodeValue;
    }
  }

  if ($xml_profile->XmlSignaletique) {
    /**
     * Loading data from information;
     */
    $mappings = array(
      'company_name'  => 'SCO_RS',
      'salutation'    => 'SCO_CIVCOD',
      'function'      => 'SCO_FONCTION',
      'service'       => 'SCO_SERVICE',
      'fax'           => 'SCO_FAX',
      'tel_2'         => 'SCO_MOBILE',
      'surname'       => 'SCO_NOM',
      'name'          => 'SCO_PRENOM',
      'tel_1'         => 'SCO_TEL',
      'address_1'     => 'SCO_VOLET3',
      'address_2'     => 'SCO_VOLET5',
      'post_code'     => 'SCO_CP',
      'city'          => 'SCO_VILLE',
      'country'       => 'SCO_PAYS'
    );
    $xml_doc->loadXML($xml_profile->XmlSignaletique);
    foreach ($mappings as $key => $tag) {
      $item = $xml_doc->getElementsByTagName($tag)->item(0);
      $profile[$key] = $item->nodeValue;
    }
//    $profile['salutation']  = _cp_abonnement_format_civility(
//      $profile['salutation'],
//      TRUE
//    );
    $profile['country']     = _batire_svc_format_country(
      $profile['country'],
      TRUE
    );
  }

  if ($xml_profile->XmlSuivi) {
    /**
     * Loading data from other;
     */
    $mappings = array(
      'created'     => 'CPT_DATCRE',
      'changed'     => 'CPT_DATMAJ',
      'created_at'  => 'CPT_ORICRE',
      'changed_at'  => 'CPT_ORIMAJ',
      'cpt_flag'    => 'CPT_FLAG',
      'test_acc'    => 'CPT_TEST',
      'mod_id'      => 'CPT_IDMDF',
      'sco_flag'    => 'SCO_FLAG'
    );
    $xml_doc->loadXML($xml_profile->XmlSuivi);
    foreach ($mappings as $key => $tag) {
      $item = $xml_doc->getElementsByTagName($tag)->item(0);
      $profile[$key] = $item->nodeValue;
    }
    $created = explode('/', $profile['created']);
    $profile['created'] = mktime(0, 0, 0, $created[1], $created[0], $created[2]);

    $changed = explode('/', $profile['changed']);
    $profile['changed'] = mktime(0, 0, 0, $changed[1], $changed[0], $changed[2]);
  }

  return $profile;
}

/**
 * Converts search results data from XML to array
 * @param $profile - an array of XML
 * @todo DOMDocument vs simplexml
 */
function _batire_svc_unpack_search_results($xml_results) {
  $results = array();
  $xml_doc = new DOMDocument();

  $xml_doc->loadXML($xml_results);

  $comptes = $xml_doc->getElementsByTagName('COMPTE');

  $mappings = array(
    'svc_id'      => 'CID',
    'login'       => 'LOGIN',
    'mail'        => 'EMAIL',
    'company'     => 'CRS',
    'salutation'  => 'CCIV',
    'post_code'   => 'CCP',
    'city'        => 'CVIL',
    'surname'     => 'CNOM',
    'name'        => 'CPRE'
  );

  foreach ($comptes as $compte) {
    $result = array();

    foreach ($mappings as $field => $tag) {
      $item = $compte->getElementsByTagName($tag)->item(0);
      $result[$field] = $item->nodeValue;
    }
//    $result['salutation'] = _cp_abonnement_format_civility($result['salutation'], TRUE);

    $results[] = $result;
  }

  return $results;
}

/**
 * Helper for abonnements list unpacking
 * @param $abon_xml
 */
function _batire_svc_unpack_abonnements($abon_xml) {
  $results = array();

  $xml_doc = new DOMDocument();

  $xml_doc->loadXML($abon_xml);

  $abonnes = $xml_doc->getElementsByTagName('ABONNE');

  foreach ($abonnes as $abonne) {
    $item = $abonne->getElementsByTagName('NO')->item(0);
    $results[] = $item->nodeValue;
  }

  return $results;
}

/**
 * Helper for abonnements list unpacking
 * @param $abon_xml
 */
function _batire_svc_unpack_abonnements_advanced($abon_xml) {
  $results = array('paid' => array(), 'free' => array());

  $xmlDoc = new DOMDocument();

  $xmlDoc->loadXML($abon_xml);

  $abonnes   = $xmlDoc->getElementsByTagName('ABONNE');

  $pro_codes = batire_user_products_get_products('svc_code');
  $pro_codes[] = 'BTC';

  foreach ($abonnes as $abonne) {
    $etat = $abonne->getElementsByTagName('ETAT')->item(0)->nodeValue;
    if (in_array($etat, array(1,11))) {
      $pro_code = $abonne->getElementsByTagName('PRO_CODE')->item(0)->nodeValue;
      if (in_array($pro_code, $pro_codes)) {
        $num = $abonne->getElementsByTagName('NO')->item(0)->nodeValue;
        $type = 'paid';
        if (_batire_user_is_abbo_free(array_shift(explode('-', $num)))) {
          $type = 'free';
        }

        $results[$type][$pro_code][$abonne->getElementsByTagName('NBEX')->item(0)->nodeValue] = $num;

      }
    }
  }

  if (count($results['paid'])) {
    $results = $results['paid'];
  }
  else {
    $results = $results['free'];
  }

  if (count($results)) {
    foreach ($results as &$abonnements) {
      ksort($abonnements);
      $abon = end($abonnements);
      $abonnements = $abon;
    }
  }

  return $results;
}

/**
 * Helper for abonnements list unpacking
 * @param $abon_xml
 */
function _batire_svc_unpack_active_batire_abonnements($abon_xml, $non_free = FALSE) {
  $results = array();

  $xml_doc = new DOMDocument();

  $xml_doc->loadXML($abon_xml);

  $abonnes = $xml_doc->getElementsByTagName('ABONNE');

  $pro_codes = batire_user_products_get_products('svc_code');
  $pro_codes[] = 'BTC';

  foreach ($abonnes as $abonne) {
    $etat_item     = $abonne->getElementsByTagName('ETAT')->item(0);
    $pro_code_item = $abonne->getElementsByTagName('PRO_CODE')->item(0);
    $etat          = $etat_item->nodeValue;
    $pro_code      = $pro_code_item->nodeValue;
    if ((($etat == 1) || ($etat == 11)) && in_array($pro_code, $pro_codes)) {
      $item = $abonne->getElementsByTagName('NO')->item(0);
      if ($non_free) {
        $abbo_num = $item->nodeValue;
        $abo = explode('-', $abbo_num);
        if (!_batire_user_is_abbo_free($abo[0])) {
          $results[] = $abbo_num;
        }
      }
      else {
        $results[] = $item->nodeValue;
      }
    }
  }

  return $results;
}

/**
 * returns user abonnement from raw data;
 * @param $abon_xml
 */
function _batire_svc_parse_user_abonnement($abon_xml) {
  $xmlDoc = simplexml_load_string($abon_xml);

  $pro_codes = batire_user_products_get_products('svc_code');
  $pro_codes[] = 'BTC';

  foreach ($xmlDoc->ABONNE as $abonne) {
    /**
     * ETAT = 1 || 11 - that's enough to decide that user can login.
     * This is true for paid users;
     */
    $etat = (string)$abonne->ETAT;

    if (in_array((string)$abonne->PRO_CODE, $pro_codes) && in_array($etat, array(11, 1))) {
      $abo = (string)$abonne->NO;

      $abo = explode('-', $abo);
      if (is_array($abo)) {
        return array_shift($abo);
      }
    }
  }

  return FALSE;
}
/**
 * Helper for abonnement info unpacking
 * @param $abon_xml
 */
function _batire_svc_unpack_abonnement_info($abon_xml, $login = '') {
  $result = array();

  $xmlDoc = simplexml_load_string($abon_xml);

  $abonnements = array();

  if ($xmlDoc->ABONNE->ABONNEMENT[0]) {
    $abon_obj = $xmlDoc->ABONNE->ABONNEMENT;
  }
  else {
    $abon_obj = $xmlDoc->ABONNE;
  }

  $pro_codes = batire_user_products_get_products('svc_code');
  $pro_codes[] = 'BTC';

  foreach ($abon_obj as $abonne) {
    /**
     * ETAT = 1 || 11 - that's enough to decide that user can login.
     * This is true for paid users;
     */
    $etat = (string)$abonne->ETAT;
    if (in_array((string)$abonne->PRO_CODE, $pro_codes) && in_array($etat, array(11, 1))) {
      $abonnements[(int)$abonne->NBEX] = $abonne;
    }
  }

  if (count($abonnements)) {
    ksort($abonnements);
    $abonne = end($abonnements);
      /**
       * Now we need to try to parse dates, that are abonnement is valid for;
       *
       * 2 possible formats are exist:
       * -- New format: Statut:E;N¿ Commande:1291768;Dates:20120315-20120515;Nos:2012000025-2012000027
       * -- Old format: Statut:ACT-ACT ;Date Commande:20120125;Dates:0-0;Nos:1-12;Edition:
       */

    $raw_data = (string)$abonne->COMP;
    $data = explode(';', $raw_data);
    if (is_array($data)) {
      $data = array_map('trim', $data);

      $date_filled = FALSE;

      foreach ($data as $property_raw) {
        $property = explode(':', $property_raw);
        if (is_array($property)) {
          $property = array_map('trim', $property);

          switch ($property[0]) {
            case 'Dates' :
              /**
               * This is a new format: Dates:YYYYMMDD-YYYYMMDD
               * We need to skip old format;
               */
              if ($property[1] == '0-0') {
                break;
              }
              $date_filled = TRUE;

              $dates = explode('-', $property[1]);
              if (is_array($dates) && count($dates) == 2) {

                $result['start_date'] = array(
                  'day'   => drupal_substr($dates[0], 6, 2),
                  'month' => drupal_substr($dates[0], 4, 2),
                  'year'  => drupal_substr($dates[0], 0, 4),
                );

                $result['end_date'] = array(
                  'day'   => drupal_substr($dates[1], 6, 2),
                  'month' => drupal_substr($dates[1], 4, 2),
                  'year'  => drupal_substr($dates[1], 0, 4),
                );

                $result['start_timestamp']  = mktime(0, 0, 0, $result['start_date']['month'], $result['start_date']['day'], $result['start_date']['year']);
                $result['end_timestamp']    = mktime(23, 59, 59, $result['end_date']['month'], $result['end_date']['day'], $result['end_date']['year']);
              }
              break;
            case 'Date Commande' :
              if ($date_filled) {
                break;
              }
              $result['start_timestamp'] = strtotime($property[1]);

              $array = explode('-', date('d-m-Y', $result['start_timestamp']));
              $result['start_date'] = array(
                'day'   => $array[0],
                'month' => $array[1],
                'year'  => $array[2],
              );
              break;
            case 'Nos' :
              if ($date_filled) {
                break;
              }
              $months_raw = explode('-', $property[1]);
              if (is_array($months_raw) && 2 == count($months_raw)) {
                $result['months_count']  = $months_raw[1] - $months_raw[0];
                $result['end_timestamp'] = $result['start_timestamp'] + ($result['months_count'] + 1) * 30 * 24 * 60 * 60;

                $array = explode('-', date('d-m-Y', $result['end_timestamp']));
                $result['end_date'] = array(
                  'day'   => $array[0],
                  'month' => $array[1],
                  'year'  => $array[2],
                );
              }
              break;
          }
        }
      }
    }

    /**
     * If no dates next logic should be:
     * 1) Have user in Drupal? If yes - get dates form user profile.
     * 2) Otherwise set date from - NOW, date to - NOW + 1 year
     */
    if (!count($result)) {
      $is_user = user_load(array('svc_login' => $login));
      if (isset($is_user->uid) && $is_user->uid > 0) {
        $profile = batire_user_profile_load($is_user->uid);
        $result  = array();
        $result['start_timestamp'] = $profile->field_user_dates[0]['value'];
        $result['end_timestamp']   = $profile->field_user_dates[0]['value2'];
      }
      else {
        $result['start_timestamp'] = REQUEST_TIME;
        $result['end_timestamp']   = REQUEST_TIME + 365 * 24 * 60 * 60;
      }

      $array = explode('-', date('d-m-Y', $result['start_timestamp']));
      $result['start_date'] = array(
        'day'   => $array[0],
        'month' => $array[1],
        'year'  => $array[2],
      );

      $array = explode('-', date('d-m-Y', $result['end_timestamp']));
      $result['end_date'] = array(
        'day'   => $array[0],
        'month' => $array[1],
        'year'  => $array[2],
      );
    }
  }

  return $result;
}

/**
 * Helper for abonnements list unpacking
 * @param $abon_xml
 */
function _batire_svc_unpack_mapping($mapping_xml) {
  $results = array();

  $xml_doc = new DOMDocument();

  $xml_doc->loadXML($mapping_xml);

  $mappings = $xml_doc->getElementsByTagName('MAPPING');

  foreach ($mappings as $mapping) {
    $map_code = $mapping->getElementsByTagName('MAP_CODE')->item(0)->nodeValue;
    $site = $mapping->getElementsByTagName('SITE')->item(0)->nodeValue;
    $cpt_id = $mapping->getElementsByTagName('CPT_ID')->item(0)->nodeValue;
    $results[] = array(
      'map_code' => $map_code,
      'site' => $site,
      'cpt_id' => $cpt_id,
    );
  }

  return $results;
}

/**
 * Helper for building "compte" XML
 */
function _batire_svc_build_compte($info, $svc_id = 0) {
  $compte = '<Compte>';

  $compte .= $svc_id        ? "<CPT_ID>$svc_id</CPT_ID>" : '';
  $compte .= $info['name']  ? "<CPT_LOGIN>{$info['name']}</CPT_LOGIN>" : '';
  $compte .= $info['pass']  ? "<CPT_PASSWORD>{$info['pass']}</CPT_PASSWORD>" : '';
  $compte .= $info['mail']  ? "<CPT_EMAIL>{$info['mail']}</CPT_EMAIL>" : '';

  if (isset($info['change_abon_no'])) {
    $compte .= "<CPT_NOABO>{$info['change_abon_no']}</CPT_NOABO>";
  }

  /**
   * @todo - waiting for clarification
   */
  $compte .= '<CPT_ETAT>1</CPT_ETAT><CPT_STATUT>1</CPT_STATUT>';

  $compte .= '</Compte>';

  return $compte;
//      <CPT_CAT>{$info['']}</CPT_CAT>
//      <CPT_CONF>{$info['']}</CPT_CONF>
//      <CPT_LOGIN_EXT></CPT_LOGIN_EXT>
}

/**
 * Helper for building "signaletique" XML
 */
function _batire_svc_build_signaletique($info) {

  $civ = $country = '';

  if (isset($info['field_abon_salutation'][0]['value'])) {
    $civ = $info['field_abon_salutation'][0]['value'];
  }

  if (isset($info['field_abon_country'][0]['value'])) {
    $country = _batire_svc_format_country($info['field_abon_country'][0]['value']);
  }

  $sig = '<Signaletique>';

  $sig .= $civ ? "<SCO_CIVCOD>$civ</SCO_CIVCOD>" : '';
  $sig .= $country ? "<SCO_PAYS>$country</SCO_PAYS>" : '';
  $sig .= $info['mail'] ? "<SCO_EMAIL>{$info['mail']}</SCO_EMAIL>" : '';

  $fields = array(
    'company_name' => array(
      'tag' => 'SCO_RS',
      'limit' => 100,
    ),
    'function' => array(
      'tag' => 'SCO_FONCTION',
      'limit' => 80,
    ),
    'specialty' => array(
      'tag' => 'SCO_SERVICE',
      'limit' => 80,
    ),
    'fax' => array(
      'tag' => 'SCO_FAX',
      'limit' => 32,
    ),
    'tel_2' => array(
      'tag' => 'SCO_MOBILE',
      'limit' => 32,
    ),
    'name' => array(
      'tag' => 'SCO_PRENOM',
      'limit' => 60,
    ),
    'surname' => array(
      'tag' => 'SCO_NOM',
      'limit' => 80,
    ),
    'tel_1' => array(
      'tag' => 'SCO_TEL',
      'limit' => 32,
    ),
    'address_1' => array(
      'tag' => 'SCO_VOLET3',
      'limit' => 50,
    ),
    'address_2' => array(
      'tag' => 'SCO_VOLET5',
      'limit' => 50,
    ),
    'post_code' => array(
      'tag' => 'SCO_CP',
      'limit' =>  20,
    ),
    'city' => array(
      'tag' => 'SCO_VILLE',
      'limit' => 50,
    ),
  );

  foreach ($fields as $field => $tag) {
    if (isset($info['field_abon_'. $field][0]['value']) && $info['field_abon_'. $field][0]['value']) {
      $info['field_abon_'. $field][0]['value'] = substr($info['field_abon_'. $field][0]['value'], 0, $tag['limit']);
      $sig .= "<{$tag['tag']}>{$info['field_abon_'. $field][0]['value']}</{$tag['tag']}>";
    };
  }

  $sig .= '</Signaletique>';
  return $sig;
}

/**
 * Helper for building "preferences" XML
 */
function _batire_svc_build_preferences($info) {
  if (isset($info['field_opt_1'][0]['value']) && $info['field_opt_1'][0]['value']) {
    $opt_1 = $info['field_opt_1'][0]['value']  ? $info['field_opt_1'][0]['value'] : 0;
  }

  if (isset($info['field_opt_2'][0]['value']) && $info['field_opt_2'][0]['value']) {
    $opt_2 = $info['field_opt_2'][0]['value']  ? $info['field_opt_2'][0]['value'] : 0;
  }

  $pref = '<Preferences>';

  $pref .= isset($opt_1) ? "<CPT_ACCINFCOM>$opt_1</CPT_ACCINFCOM>" : '<CPT_ACCINFCOM>0</CPT_ACCINFCOM>';
  $pref .= isset($opt_2) ? "<CPT_ACCINFPRT>$opt_2</CPT_ACCINFPRT>" : '<CPT_ACCINFPRT>0</CPT_ACCINFPRT>';

  $pref .= '</Preferences>';
  return $pref;
}

/**
 * Formats country field to be used for SVC
 */
function _batire_svc_format_country($country, $flip = FALSE) {
  $countries = mongodb_site_get_country_list($flip, FALSE);
  return (isset($countries[$country]->code)) ? $countries[$country]->code : '';
}





/**
 * Validates if $space is inside array of $spaces;
 *
 * Since Spaces could be: BTC01|BTC02|BTC03 then we need to look sor strpos
 */
function _batire_svc_validate_spaces($spaces, $space) {
  if (!$spaces) {
    return FALSE;
  }

  foreach ($spaces as $_space) {
    if (0 === strpos($_space, $space)) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * Logs trace results in watchdog, if tracing is enabled;
 * @param $client
 */
function _batire_svc_log($method, $params, $data, $client) {

  if (BATIRE_SVC_DEBUG) {
    $params = array(
      '!method'   => $method,
      '!params'   => print_r($params, TRUE),
      '!response' => print_r($data, TRUE)
    );

    $message = 'SVC call <b>!method</b>. Params: <pre>!params</pre>. Response: <pre>!response</pre>.';

    if (BATIRE_SVC_TRACE && $client) {
      $params['!xml_request']   = $client->__getLastRequest();
      $params['!xml_response']  = $client->__getLastResponse();

      $message .= ' Trace: Request: <pre>!xml_request</pre>. Response: <pre>!xml_response</pre>.';
    }

    watchdog(BATIRE_SVC_LOG, $message, $params, WATCHDOG_DEBUG);
  }
}

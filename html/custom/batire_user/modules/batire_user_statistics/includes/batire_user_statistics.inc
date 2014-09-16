<?php

/**
 * @file
 *  batire_user_statistics.inc
 * Additional functions for statistics
 */

/**
 * Get user statistics guest list map
 * @return array
 */
function batire_user_statistics_application_guest_list_get_map() {
  return array(
    'A' => 'login',
    'B' => 'company_name',
    'C' => 'surname',
    'D' => 'mail',
    'E' => 'number_position_entered',
    'F' => 'number_invitation_sent_cs',
    'G' => 'number_cs_created',
    'H' => 'effective_date',
    'I' => 'due_date',
  );
}

/**
 * Get header for guest list report
 * @return Array List of column names
 */
function _batire_user_statistics_application_guest_list_get_file_header() {
  return array(
    'A' => 'Login', // login
    'B' => t('Raison sociale'), // company nam
    'C' => t('Nom'), // surname
    'D' => 'Email', // email, without t()
    'E' => t('Nb de postes souscrits'), // number of position entered
    'F' => t('Nb d’invitations CS envoyées'), // number of invitation sent cs
    'G' => t('Nb de CS créés'), // number of cs created
    'H' => t('Date d’effet'), // effective date
    'I' => t('Date d’échéance'), // due date
  );
}

/**
 * Get list of all statistics fields being exported at the moment.
 */
function _batire_user_statistics_application_get_fields_mapping() {
  $fields = array();
  $fields += array(
    'abo_num' => t('N° d\'abonné'),
    'login' => t('Login'),
    'surname' => t('Nom'),
    'name' => t('Prénom'),
    'company_name' => t('Raison sociale'),
    'industry' => t('Secteur d’activité'),
    'activite' => t('Activite'),
    'function' => t('Function'),
    'service' => t('Service'),
    'abon_type' => t('Type d’abonnement'),
    'role' => t('Role'),
    'grand_compte' => t('GC'),
    'last_login' => t('Date dernière connexion'),
    'products' => t('Produits'),
  );
  $fields += _batire_user_statistics_application_get_mongo_fields();
  $fields += array(
    'doc_registered' => t('Documents enregistrés'), // number of registered documents
    'doc_shared' => t('Documents partagés'), // number of shared documents
    'annotations_created' => t('Annotations créées'), // number of created annotations
    'saved_searches' => t('Recherches enregistrées'), // number of registered searches
    'registered_alerts' => t('Alertes enregistrées'), // number of registered alerts
    'default_search' => t('Profil de référence enregistré'), // does user have default search
    'folders_created' => t('Dossiers créés'), // number of created folders
    'folders_shared' => t('Dossiers partagés'), // number of shared folders
    'ips' => t('Adresses IP'), // ip addresses used to access site
    'origene' => t('Type utilisateur'),
  );
  return $fields;
}

/**
 * Get list of statistics fields stored in mongodb.
 */
function _batire_user_statistics_application_get_mongo_fields() {
  $fields = array(
    'logins' => t('Connexions'), // number of logins
    'views' => t('TOTAL des documents consultés'), // number of documents views
    'to_views' => t('T.O. (total des documents consultés)'), // number of TO documents views
    'codes_views' => t('Codes (total des documents consultés)'), // number of Codes documents views
  );
  // codes types
  $codes = taxonomy_get_tree(BATIRE_SITE_VID_CODES);
  foreach ($codes as $term) {
    $fields["codes_{$term->tid}_views"] = t("Codes - {$term->name}");
  }
  $fields += array(
    'tn_views' => t('Textes normatifs (total des documents consultés)'), // number of TN documents views
    'livres_views' => t('Livres (total des documents consultés)'), // number of Livres documents views
  );
  // livres types
  $livres = taxonomy_get_tree(BATIRE_SITE_VID_LIVRES);
  foreach ($livres as $term) {
    $fields["livres_{$term->tid}_views"] = t("Livres - {$term->name}");
  }
  $fields += array(
    'fm_views' => t('FM (total des documents consultés)'), // number of FM documents views
  );
  // FM types
  $livres = taxonomy_get_tree(BATIRE_SITE_VID_FM);
  foreach ($livres as $term) {
    $fields["fm_{$term->tid}_views"] = t("FM - {$term->name}");
  }
  $fields += array(
    'ct_views' => t('Complément technique (total des documents consultés)'), // number of CT documents views
    'actu_views' => t('Actualité (total des documents consultés)'), // number of Actu documents views
    'downloads' => t('Téléchargements'), // number of downloads
    'prints' => t('Impressions'), // number of prints
    'search_prints' => t('Listes de résultats imprimées'), // number of printed search result lists
  );
  return $fields;
}

function _batire_user_statistics_application_num_to_alpha($number) {
  for($alpha = ''; $number >= 0; $number = intval($number / 26) - 1) {
    $alpha = chr($number % 26 + 0x41) . $alpha;
  }
  return $alpha;
}

/**
 * Get map for user statistics
 * @return Array List of keys
 */
function _batire_user_statistics_application_get_map($filter_fields = FALSE) {
  global $user;
  $fields = _batire_user_statistics_application_get_fields_mapping();
  if ($filter_fields && !isset($user->roles[BATIRE_GC_GC_COMMERCIAL_ROLE_ID])) {
    $default_fields = _batire_user_statistics_application_get_default_fields();
    $user_profile = batire_user_profile_load($uid);
    $allowed_fields = !empty($user_profile->field_user_gc_stat_permissions[0]['value']) ? unserialize($user_profile->field_user_gc_stat_permissions[0]['value']) : array();
    if (!empty($allowed_fields)) {
      foreach ($fields as $key => $field) {
        if (!(in_array($key, $default_fields) || $allowed_fields[$key])) {
          unset($fields[$key]);
        }
      }
    }
  }
  $map = array();
  $i = 0;
  foreach ($fields as $key => $field) {
    $alpha = _batire_user_statistics_application_num_to_alpha($i);
    $map['map'][$alpha] = $key;
    $map['header'][$alpha] = $field;
    $i++;
  }
  return $map;
}

/**
 * Get fields included to report by default
 * @return Array List of column ids
 */
function _batire_user_statistics_application_get_default_fields() {
  return array(
    'login',
    'surname',
    'name',
    'company_name',
    'industry',
    'activite',
    'function',
    'service',
    'abon_type',
    'role',
    'grand_compte',
    'last_login',
    'number_logins',
  );
}

/**
 * Get map for request list statistics
 * @return Array List of keys
 */
function _batire_user_statistics_application_request_list_get_map() {
  return array(
    'A' => 'salut',
    'B' => 'surname',
    'C' => 'name',
    'D' => 'mail',
    'E' => 'tel_1',
//    'F' => 'tel_2',
//    'G' => 'fax',
    'F' => 'promo',
    'G' => 'position',
    'H' => 'specialty',
//    'J' => 'statut',
    'I' => 'company_name',
    'J' => 'address_1',
    'K' => 'address_2',
    'L' => 'zip',
    'M' => 'city',
    'N' => 'country',
//    'Q' => 'tva',
//    'R' => 'abon_num',
//    'S' => 'abon_list',
    'O' => 'prospect_type',
    'P' => 'posts_count',
    'Q' => 'when_to_call',
    'R' => 'created_date'
  );
}

/**
 * Get header for request list report
 * @return Array List of column names
 */
function _batire_user_statistics_application_request_list_get_file_header() {
  return array(
    'A' => t('Civilité'),
    'B' => t('Nom'),
    'C' => t('Prénom'),
    'D' => 'Email',
    'E' => t('Téléphone'),
//    'F' => t('Autre téléphone'),
//    'G' => t('Fax'),
    'F' => t('Code privilège'),
    'G' => t('Fonction'),
    'H' => t('Spécialité'),
//    'J' => t('Statut'),
    'I' => t('Raison sociale'),
    'J' => t('Adresse 1'),
    'K' => t('Adresse 2'),
    'L' => t('Code postal'),
    'M' => t('Ville'),
    'N' => t('Pays'),
//    'Q' => t('N° TVA'),
//    'R' => t('N° d’abonné'),
//    'S' => t('Abonnements existants'),
    'O' => t('Type de prospect'),
    'P' => t('Nb de postes souhaité'),
    'Q' => t('Disponibilités'),
    'R' => t('Date'),
  );
}

function _batire_user_statistics_application_history_get_map() {
  return array(
    'map' => array(
      'A' => 'nom',
      'B' => 'abo_num',
      'C' => 'login',
      'D' => 'sources',
      'E' => 'titre_support',
      'F' => 'date_publication',
      'G' => 'date_consult',
      'H' => 'reference',
      'I' => 'titre_document',
      'J' => 'origene',
    ),
    'header' => array(
      'A' => t('Nom'),
      'B' => t('N° d\'abonné'),
      'C' => t('Login'),
      'D' => t('Sources'),
      'E' => t('Titre support'),
      'F' => t('Date de publication'),
      'G' => t('Date de consultation'),
      'H' => t('n° of references'),
      'I' => t('Titre de document'),
      'J' => t('Type utilisateur'),
    ),
  );
}

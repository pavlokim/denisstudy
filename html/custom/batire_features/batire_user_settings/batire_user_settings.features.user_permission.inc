<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function batire_user_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: access ckeditor
  $permissions['access ckeditor'] = array(
    'name' => 'access ckeditor',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: access content
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      '0' => 'abonnement découverte',
      '1' => 'abonnement gratuit',
      '2' => 'abonnement payante',
      '3' => 'administrateur mono-poste',
      '4' => 'administrateur multi-poste',
      '5' => 'anonymous user',
      '6' => 'authenticated user',
      '7' => 'compte secondaire',
      '8' => 'webmaster',
    ),
  );

  // Exported permission: access devel information
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: access system content
  $permissions['access system content'] = array(
    'name' => 'access system content',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: access user docs
  $permissions['access user docs'] = array(
    'name' => 'access user docs',
    'roles' => array(
      '0' => 'abonnement découverte',
      '1' => 'abonnement gratuit',
      '2' => 'abonnement payante',
      '3' => 'administrateur mono-poste',
      '4' => 'administrateur multi-poste',
      '5' => 'authenticated user',
      '6' => 'compte secondaire',
    ),
  );

  // Exported permission: access usersession
  $permissions['access usersession'] = array(
    'name' => 'access usersession',
    'roles' => array(
      '0' => 'abonnement découverte',
      '1' => 'abonnement gratuit',
      '2' => 'abonnement payante',
      '3' => 'administrateur mono-poste',
      '4' => 'administrateur multi-poste',
      '5' => 'authenticated user',
      '6' => 'compte secondaire',
    ),
  );

  // Exported permission: administer batire configuration
  $permissions['administer batire configuration'] = array(
    'name' => 'administer batire configuration',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: administer faq
  $permissions['administer faq'] = array(
    'name' => 'administer faq',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: administer faq order
  $permissions['administer faq order'] = array(
    'name' => 'administer faq order',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: administer mail templates
  $permissions['administer mail templates'] = array(
    'name' => 'administer mail templates',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: administer nodes
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: create batire_user_annotation content
  $permissions['create batire_user_annotation content'] = array(
    'name' => 'create batire_user_annotation content',
    'roles' => array(),
  );

  // Exported permission: create batire_user_folder content
  $permissions['create batire_user_folder content'] = array(
    'name' => 'create batire_user_folder content',
    'roles' => array(),
  );

  // Exported permission: create faq
  $permissions['create faq'] = array(
    'name' => 'create faq',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: delete any batire_user_annotation content
  $permissions['delete any batire_user_annotation content'] = array(
    'name' => 'delete any batire_user_annotation content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete any batire_user_folder content
  $permissions['delete any batire_user_folder content'] = array(
    'name' => 'delete any batire_user_folder content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete any batire_user_profile content
  $permissions['delete any batire_user_profile content'] = array(
    'name' => 'delete any batire_user_profile content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete any batire_user_search_profile content
  $permissions['delete any batire_user_search_profile content'] = array(
    'name' => 'delete any batire_user_search_profile content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete any batire_user_sent_alert content
  $permissions['delete any batire_user_sent_alert content'] = array(
    'name' => 'delete any batire_user_sent_alert content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete faq content
  $permissions['delete faq content'] = array(
    'name' => 'delete faq content',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: delete own batire_user_annotation content
  $permissions['delete own batire_user_annotation content'] = array(
    'name' => 'delete own batire_user_annotation content',
    'roles' => array(
      '0' => 'abonnement découverte',
      '1' => 'abonnement gratuit',
      '2' => 'abonnement payante',
      '3' => 'administrateur mono-poste',
      '4' => 'administrateur multi-poste',
      '5' => 'authenticated user',
      '6' => 'compte secondaire',
    ),
  );

  // Exported permission: delete own batire_user_folder content
  $permissions['delete own batire_user_folder content'] = array(
    'name' => 'delete own batire_user_folder content',
    'roles' => array(
      '0' => 'abonnement découverte',
      '1' => 'abonnement gratuit',
      '2' => 'abonnement payante',
      '3' => 'administrateur mono-poste',
      '4' => 'administrateur multi-poste',
      '5' => 'authenticated user',
      '6' => 'compte secondaire',
    ),
  );

  // Exported permission: delete own batire_user_profile content
  $permissions['delete own batire_user_profile content'] = array(
    'name' => 'delete own batire_user_profile content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete own batire_user_search_profile content
  $permissions['delete own batire_user_search_profile content'] = array(
    'name' => 'delete own batire_user_search_profile content',
    'roles' => array(
      '0' => 'abonnement découverte',
      '1' => 'abonnement gratuit',
      '2' => 'abonnement payante',
      '3' => 'administrateur mono-poste',
      '4' => 'administrateur multi-poste',
      '5' => 'authenticated user',
      '6' => 'compte secondaire',
    ),
  );

  // Exported permission: delete own batire_user_sent_alert content
  $permissions['delete own batire_user_sent_alert content'] = array(
    'name' => 'delete own batire_user_sent_alert content',
    'roles' => array(
      '0' => 'abonnement découverte',
      '1' => 'abonnement gratuit',
      '2' => 'abonnement payante',
      '3' => 'administrateur mono-poste',
      '4' => 'administrateur multi-poste',
      '5' => 'authenticated user',
      '6' => 'compte secondaire',
    ),
  );

  // Exported permission: delete own faq content
  $permissions['delete own faq content'] = array(
    'name' => 'delete own faq content',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: edit faq
  $permissions['edit faq'] = array(
    'name' => 'edit faq',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: edit mimemail user settings
  $permissions['edit mimemail user settings'] = array(
    'name' => 'edit mimemail user settings',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: edit own batire_user_annotation content
  $permissions['edit own batire_user_annotation content'] = array(
    'name' => 'edit own batire_user_annotation content',
    'roles' => array(
      '0' => 'abonnement découverte',
      '1' => 'abonnement gratuit',
      '2' => 'abonnement payante',
      '3' => 'administrateur mono-poste',
      '4' => 'administrateur multi-poste',
      '5' => 'authenticated user',
      '6' => 'compte secondaire',
      '7' => 'webmaster',
    ),
  );

  // Exported permission: edit own batire_user_folder content
  $permissions['edit own batire_user_folder content'] = array(
    'name' => 'edit own batire_user_folder content',
    'roles' => array(
      '0' => 'abonnement découverte',
      '1' => 'abonnement gratuit',
      '2' => 'abonnement payante',
      '3' => 'administrateur mono-poste',
      '4' => 'administrateur multi-poste',
      '5' => 'authenticated user',
      '6' => 'compte secondaire',
      '7' => 'webmaster',
    ),
  );

  // Exported permission: edit own faq
  $permissions['edit own faq'] = array(
    'name' => 'edit own faq',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: translate interface
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      '0' => 'webmaster',
    ),
  );

  // Exported permission: view faq page
  $permissions['view faq page'] = array(
    'name' => 'view faq page',
    'roles' => array(
      '0' => 'abonnement découverte',
      '1' => 'abonnement gratuit',
      '2' => 'abonnement payante',
      '3' => 'administrateur mono-poste',
      '4' => 'administrateur multi-poste',
      '5' => 'anonymous user',
      '6' => 'authenticated user',
      '7' => 'compte secondaire',
      '8' => 'webmaster',
    ),
  );

  // Exported permission: view imagecache batire_5advices_img
  $permissions['view imagecache batire_5advices_img'] = array(
    'name' => 'view imagecache batire_5advices_img',
    'roles' => array(
      '0' => 'abonnement découverte',
      '1' => 'abonnement gratuit',
      '2' => 'abonnement payante',
      '3' => 'administrateur mono-poste',
      '4' => 'administrateur multi-poste',
      '5' => 'anonymous user',
      '6' => 'authenticated user',
      '7' => 'compte secondaire',
      '8' => 'webmaster',
    ),
  );

  // Exported permission: view imagecache batire_hp_block_img
  $permissions['view imagecache batire_hp_block_img'] = array(
    'name' => 'view imagecache batire_hp_block_img',
    'roles' => array(
      '0' => 'abonnement découverte',
      '1' => 'abonnement gratuit',
      '2' => 'abonnement payante',
      '3' => 'administrateur mono-poste',
      '4' => 'administrateur multi-poste',
      '5' => 'anonymous user',
      '6' => 'authenticated user',
      '7' => 'compte secondaire',
      '8' => 'webmaster',
    ),
  );

  // Exported permission: view imagecache batire_lemoniteur_img
  $permissions['view imagecache batire_lemoniteur_img'] = array(
    'name' => 'view imagecache batire_lemoniteur_img',
    'roles' => array(
      '0' => 'abonnement découverte',
      '1' => 'abonnement gratuit',
      '2' => 'abonnement payante',
      '3' => 'administrateur mono-poste',
      '4' => 'administrateur multi-poste',
      '5' => 'anonymous user',
      '6' => 'authenticated user',
      '7' => 'compte secondaire',
      '8' => 'webmaster',
    ),
  );

  return $permissions;
}

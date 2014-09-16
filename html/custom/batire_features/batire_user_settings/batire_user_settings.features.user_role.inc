<?php

/**
 * Implementation of hook_user_default_roles().
 */
function batire_user_settings_user_default_roles() {
  $roles = array();

  // Exported role: abonnement découverte
  $roles['abonnement découverte'] = array(
    'name' => 'abonnement découverte',
  );

  // Exported role: abonnement gratuit
  $roles['abonnement gratuit'] = array(
    'name' => 'abonnement gratuit',
  );

  // Exported role: abonnement payante
  $roles['abonnement payante'] = array(
    'name' => 'abonnement payante',
  );

  // Exported role: administrateur mono-poste
  $roles['administrateur mono-poste'] = array(
    'name' => 'administrateur mono-poste',
  );

  // Exported role: administrateur multi-poste
  $roles['administrateur multi-poste'] = array(
    'name' => 'administrateur multi-poste',
  );

  // Exported role: anonymous user
  $roles['anonymous user'] = array(
    'name' => 'anonymous user',
  );

  // Exported role: authenticated user
  $roles['authenticated user'] = array(
    'name' => 'authenticated user',
  );

  // Exported role: compte secondaire
  $roles['compte secondaire'] = array(
    'name' => 'compte secondaire',
  );

  // Exported role: webmaster
  $roles['webmaster'] = array(
    'name' => 'webmaster',
  );

  return $roles;
}

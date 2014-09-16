<?php

/**
 * @file
 * Create menu for user on page "Mon compte"
 */

/**
 * Implementation of hook_contant_type_ctools_content_types().
 */
function batire_site_batire_site_my_account_menu_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Batire mon compte menu'),
    'description' => t('Menu for page mon compte'),
    'icon' => '',
    'category' => t('Batire'),
    'defaults' => array(),
  );
}

/**
 * Implementation of hook_content_type_content_type_render().
 */
function batire_site_batire_site_my_account_menu_content_type_render($subtype, $conf, $panel_args, $context) {
  // Make a new empty "block" which will be a Pane you can add to your Panel.
  $block = new stdClass();
  $block->content = theme('batire_site_my_account_menu', batire_site_batire_site_my_account_menu_build_menu());
  return $block;
}

/**
 * Build list of menu
 * @return array List of menu
 */
function batire_site_batire_site_my_account_menu_build_menu() {
  global $user;
  $items = array();
  // section My Documents
  $items['my_documents'] = array(
    'title' => t('Mes documents'),
    'items' => array(
      'mon-compte/mes-documents' => array(
        'title' => t('Mes documents'),
        'quantity' => batire_user_docs_get_user_mydocs_cnt($user->uid),
        'q_class' => 'batire-my-documents-quantity',
        'attributes' => array(
          'build_title' => TRUE,
          'class' => 'batire-my-documents-link'
        ),
        'access' => TRUE
      ),
      'mon-compte/mes-dossiers' => array(
        'title' => t('Mes dossiers'),
        'quantity' => batire_user_docs_get_user_myfolders_cnt($user->uid),
        'q_class' => 'batire-my-folders-quantity',
        'attributes' => array(
          'build_title' => TRUE,
          'class' => 'batire-my-folders-link'
        ),
        'access' => TRUE
      ),
      'mon-compte/mes-annotations' => array(
        'title' => t('Mes annotations'),
        'quantity' => batire_user_docs_get_user_myannos_cnt($user->uid),
        'q_class' => 'batire-my-annotations-quantity',
        'attributes' => array(
          'build_title' => TRUE,
          'class' => 'batire-my-annotations-link'
        ),
        'access' => TRUE
      ),
      'mon-compte/mon-espace-partage/documents-partages' => array(
        'title' => t('Documents partagés'),
        'quantity' => mongodb_user_count_docs($user->uid, 's'),
        'q_class' => 'batire-shared-documents-quantity',
        'attributes' => array(
          'build_title' => TRUE,
          'class' => 'batire-shared-documents-link'
        ),
        'access' => _batire_user_is_multipost($user)
      ),
      'mon-compte/mon-espace-partage/dossiers-partages' => array(
        'title' => t('Dossiers partagés'),
        'quantity' => mongodb_user_count_folders($user->uid, 's'),
        'q_class' => 'batire-shared-folders-quantity',
        'attributes' => array(
          'build_title' => TRUE,
          'class' => 'batire-shared-folders-link'
        ),
        'access' => _batire_user_is_multipost($user)
      ),
      'mon-compte/mon-espace-partage/annotations-partages' => array(
        'title' => t('Annotations partagées'),
        'quantity' => mongodb_docs_count_user_annotations($user->uid, 's'),
        'q_class' => 'batire-shared-annotations-quantity',
        'attributes' => array(
          'build_title' => TRUE,
          'class' => 'batire-shared-annotations-link'
        ),
        'access' => _batire_user_is_multipost($user)
      )
    )
  );
  // section My Searches
  $items['my_searches'] = array(
    'title' => t('Mes recherches/alertes'),
    'items' => array(
      'mon-compte/mes-recherches/mes-profils-enregistres' => array(
        'title' => t('Mes profils enregistrés'),
        'quantity' => batire_user_docs_get_user_searches_cnt($user->uid),
        'q_class' => 'batire-my-searches-quantity',
        'attributes' => array(
          'build_title' => TRUE,
          'class' => 'batire-my-searches-link'
        ),
        'access' => TRUE
      ),

      'mon-compte/mes-recherches/mes-alertes-recues' => array(
        'title' => t('Mes dernières alertes reçues'),
        'quantity' => batire_user_docs_get_user_myalert_cnt($user->uid),
        'q_class' => 'batire-my-searches-alerts-quantity',
        'attributes' => array(
          'build_title' => TRUE,
          'class' => 'batire-my-searches-alerts-link'
        ),
        'access' => TRUE
      ),
    )
  );
  // section My Abonnement
  $items['my_abonnement'] = array(
    'title' => t('Mon abonnement'),
    'title_suffix' => isset($user->roles[BATIRE_USER_MULTIADMIN]) ? t('administrateur') : '',
    'items' => array(
      'mon-compte/mon-abonnement/detail-de-mon-abonnement' => array(
        'title' => t('Détail de mon abonnement'),
        'attributes' => array(
          'build_title' => TRUE,
          'class' => 'batire-my-abonnement-details-link'
        ),
        'access' => TRUE
      ),
      'mon-compte/mon-abonnement/comptes-utilisateurs' => array(
        'title' => t('Comptes utilisateurs'),
        'quantity' => _batire_user_accounts_list_cnt(),
        'q_class' => 'batire-my-abonnement-users-quantity',
        'attributes' => array(
          'build_title' => TRUE,
          'class' => 'batire-my-abonnement-users-link'
        ),
        'access' => isset($user->roles[BATIRE_USER_MULTIADMIN]) ? TRUE : FALSE
      ),
      'mon-compte/mon-abonnement/invite-link' => array(
        'title' => t('Lien d\'invitation'),
        'attributes' => array(
          'build_title' => TRUE,
          'class' => 'batire-my-abonnement-invite-link',
        ),
        'access' => batire_gc_commercial_is_gc_user(),
      ),
      'mon-compte/mon-abonnement/statistiques' => array(
        'title' => t('Statistiques'),
        'attributes' => array(
          'build_title' => TRUE,
          'class' => 'batire-my-abonnement-statistics',
        ),
        'access' => batire_gc_commercial_can_export_statistics(),
      ),
      'mon-compte/mon-abonnement/membres-du-groupe' => array(
        'title' => t('Membres du groupe'),
        'attributes' => array(
          'build_title' => TRUE,
          'class' => 'batire-my-abonnement-groups-link'
        ),
        'access' => _batire_user_is_multipost($user)
      ),
      'mon-compte/mon-abonnement/date-echeance' => array(
        'title' => t('Date d\'échéance'),
        'attributes' => array(
          'build_title' => TRUE,
          'class' => 'batire-my-abonnement-date-link'
        ),
        'access' => TRUE
      ),
    ),
  );

  $url = $_GET['q'];
  $active_class = ' active';
  if (preg_match('/^mon-compte\/mes-documents\/+/', $url)) {
    $items['my_documents']['items']['mon-compte/mes-documents']['attributes']['class'] .= $active_class;
  }

  if (preg_match('/^mon-compte\/mes-dossiers\/+/', $url)) {
    $items['my_documents']['items']['mon-compte/mes-dossiers']['attributes']['class'] .= $active_class;
  }

  if (preg_match('/^mon-compte\/mes-annotations\/+/', $url)) {
    $items['my_documents']['items']['mon-compte/mes-annotations']['attributes']['class'] .= $active_class;
  }

  if (preg_match('/^mon-compte\/mon-espace-partage\/documents-partages\/+/', $url)) {
    $items['my_documents']['items']['mon-compte/mon-espace-partage/documents-partages']['attributes']['class'] .= $active_class;
  }

  if (preg_match('/^mon-compte\/mon-espace-partage\/dossiers-partages\/+/', $url)) {
    $items['my_documents']['items']['mon-compte/mon-espace-partage/dossiers-partages']['attributes']['class'] .= $active_class;
  }

  if (preg_match('/^mon-compte\/mon-espace-partage\/annotations-partages\/+/', $url)) {
    $items['my_documents']['items']['mon-compte/mon-espace-partage/annotations-partages']['attributes']['class'] .= $active_class;
  }

  if (preg_match('/^mon-compte\/mes-recherches\/mes-profils-enregistres\/+/', $url)) {
    $items['my_searches']['items']['mon-compte/mes-recherches/mes-profils-enregistres']['attributes']['class'] .= $active_class;
  }

  if (preg_match('/^mon-compte\/mes-recherches\/mes-alertes-recues\/+/', $url)) {
    $items['my_searches']['items']['mon-compte/mes-recherches/mes-alertes-recues']['attributes']['class'] .= $active_class;
  }

  if (batire_site_is_user_about_to_expire($user)) {
    $items['my_abonnement']['items']['mon-compte/mon-abonnement/date-echeance']['title_prefix'] = "<span class='alert'>";
    $items['my_abonnement']['items']['mon-compte/mon-abonnement/date-echeance']['title_suffix'] = "</span>";
  }

  // check access to see this item
  foreach ($items as &$item) {
    foreach ($item['items'] as $subkey => $subitem) {
      if (!$subitem['access']) {
        unset($item['items'][$subkey]);
      }
    }
  }

  // Invoke hook_batire_site_user_account_menu_alter() to allow all modules to alter the menu items.
  drupal_alter('batire_site_user_account_menu', $items);

  return $items;
}
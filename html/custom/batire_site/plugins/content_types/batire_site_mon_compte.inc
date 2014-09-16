<?php

/**
 * @file
 * Mon compte page
 */

/**
 * Implementation of hook_contant_type_ctools_content_types().
 */
function batire_site_batire_site_mon_compte_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Batire mon compte'),
    'description' => t('Content for page mon compte'),
    'icon' => '',
    'category' => t('Batire'),
    'defaults' => array(),
  );
}

/**
 * Implementation of hook_content_type_content_type_render().
 */
function batire_site_batire_site_mon_compte_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $view_name = BATIRE_SITE_MON_COMPTE_VIEWS_NAME;
  // Make a new empty "block" which will be a Pane you can add to your Panel.
  $arg = batire_site_batire_site_my_account_get_key_from_url();
  $display = '';
  $args = array();
  $args2 = arg(2);
  $args3 = arg(3);
  $args4 = arg(4);
  $args5 = arg(5);

  $block = new stdClass();
  $block->content = '';
  try {
    switch ($arg) {
      case 'my_documents':
        $display = 'my_documents';
        if (!empty($args2)) {
          $args[] = batire_site_convert_arg_to_type($args2);
        }
        break;

      case 'my_folders':
        // check if exist correct folder id in url
        $fid = batire_site_batire_site_my_account_get_folder_id();
        if (empty($fid) || !is_numeric($fid) || !_batire_user_is_owner_folder($fid)) {
          $fid = batire_site_batire_site_my_account_get_folder_id('p', TRUE);
        }
        // if arg is not correct or empty redirect to correct url
        if ((empty($args2) || $args2 != $fid) && $fid != 0) {
          drupal_goto('mon-compte/mes-dossiers/' . $fid);
        }
        $display = 'my_folders';
        $args[] = $fid;
        if (!empty($args2) && !is_numeric($args2)) {
          $args[] = batire_site_convert_arg_to_type($args2);
        }
        elseif (!empty($args3)) {
          $args[] = batire_site_convert_arg_to_type($args3);
        }
        drupal_add_js(
        array(
          'batire_user_docs' => array(
            'my_account_folders_widget' => 'all',
            'my_account_count_folders' => mongodb_user_count_folders($user->uid),
            'my_account_current_folder' => $args[0],
            'my_account_folders_page_type' => 'p'
          ),
        ), 'setting'
        );
        break;

      case 'my_annotations':
        $display = 'my_annotations';
        if (!empty($args2)) {
          $args[] = batire_site_convert_arg_to_type($args2);
        }
        break;

      case 'shared_folders':
        if (!_batire_user_is_multipost($user)) {
          throw new Exception('not found');
        }
        // check if exist correct folder id in url
        $fid = batire_site_batire_site_my_account_get_folder_id('s');
        //@todo need to add check if user can see this folder id
        if (empty($fid) || !is_numeric($fid)) {
          $fid = batire_site_batire_site_my_account_get_folder_id('s', TRUE);
        }
        // if arg is not correct or empty redirect to correct url
        if ((empty($args3) || $args3 != $fid) && $fid != 0) {
          drupal_goto('mon-compte/mon-espace-partage/dossiers-partages/' . $fid);
        }
        $display = 'shared_folders';
        $args[] = $fid;
        if (!empty($args4) && !is_numeric($args4)) {
          $args[] = batire_site_convert_arg_to_type($args4);
        }
        if (!empty($args5)) {
          $args[] = $args5;
        }

        drupal_add_js(
        array(
          'batire_user_docs' => array(
            'my_account_folders_widget' => 's',
            'my_account_count_folders' => mongodb_user_count_folders($user->uid, 's'),
            'my_account_current_folder' => $args[0],
            'my_account_folders_page_type' => 's'
          ),
        ), 'setting'
        );
        break;

      case 'shared_documents':
        if (!_batire_user_is_multipost($user)) {
          throw new Exception('not found');
        }
        $display = 'shared_documents';
        $args[] = batire_site_batire_site_my_account_get_group_members_arg();
        if (!empty($args3)) {
          $args[] = batire_site_convert_arg_to_type($args3);
        }
        if (!empty($args4)) {
          $args[] = $args4;
        }
        break;

      case 'shared_annotations':
        if (!_batire_user_is_multipost($user)) {
          throw new Exception('not found');
        }
        $display = 'shared_annotations';
        $args[] = batire_site_batire_site_my_account_get_group_members_arg();
        if (!empty($args3)) {
          $args[] = batire_site_convert_arg_to_type($args3);
        }
        if (!empty($args4)) {
          $args[] = $args4;
        }
        break;

      case 'my_profile':
        $display = 'my_profile';
        $view_name = BATIRE_SITE_USER_SEARCHES_VIEWS_NAME;
        break;
      case 'my_sent_alerts':
        $display = 'my_sent_alerts';
        $view_name = BATIRE_SITE_USER_SEARCHES_VIEWS_NAME;
        if (!empty($args3)) {
          $args[] = $args3;
        }
        if (isset($args4)) {
          switch ($args4) {
            case 'quotidienne':
              $args[] = 0;
              break;
            case 'hebdomadaire':
              $args[] = 1;
              break;
            case 'mensuelle':
              $args[] = 2;
              break;
          }
        }
        break;

      case 'my_abonnement':
        $block->title = t('Détail de mon abonnement');
        module_load_include('pages.inc', 'batire_user', 'includes/batire_user');
        $block->content = batire_user_detail_abonnement($user);
        break;

      case 'list_accounts':
        if (!isset($user->roles[BATIRE_USER_MULTIADMIN])) {
          throw new Exception('not found');
        }
        $block->title = t('Comptes utilisateurs');
        module_load_include('pages.inc', 'batire_user', 'includes/batire_user');
        $block->content = batire_user_list_accounts();
        break;

      case 'group_members' :
        if (!_batire_user_is_multipost($user)) {
          throw new Exception('not found');
        }
        $block->title = t('Membres du groupe');
        module_load_include('pages.inc', 'batire_user', 'includes/batire_user');
        $block->content = batire_user_group_members();
        break;

      case 'abonement_date':
        $block->title = t("Date d'échéance");
        module_load_include('pages.inc', 'batire_user', 'includes/batire_user');
        $block->content = batire_user_abonement_date($user);
        break;

      default:
        throw new Exception('not found');
    }
    if (!$block->content) {
      $view = views_get_view($view_name);
      if (!$view || !$view->access($display)) {
        throw new Exception('not found');
      }
      $block->content = $view->preview($display, $args);
    }
  }
  catch (Exception $e) {
    drupal_goto(BATIRE_SITE_NOT_FOUND_URL);
  }

  return $block;
}

/**
 * Get folder id from url(arg(2)), or if it is empty get from db
 */
function batire_site_batire_site_my_account_get_folder_id($type = 'p', $skip_args = FALSE) {
  $arg2 = arg(2);
  $arg3 = arg(3);
  $folder_id = 0;
  switch ($type) {
    case 'p':
      if (!empty($arg2) && is_numeric($arg2) && !$skip_args) {
        $folder_id = $arg2;
      }
      else {
        $folders = batire_user_docs_get_myfolders();
        if (is_array($folders)) {
          $keys = array_keys($folders);
          array_multisort($keys, $folders);
          // get first not shared folders
          foreach ($folders as $folder) {
            if (!$folder['shared']) {
              if (isset($folder['nid']) && is_numeric($folder['nid'])) {
                $folder_id = $folder['nid'];
                break;
              }
            }
          }
          // if folder id is empty, but exist shared folder
          if (!$folder_id) {
            foreach ($folders as $folder) {
              if (isset($folder['nid']) && is_numeric($folder['nid'])) {
                $folder_id = $folder['nid'];
                break;
              }
            }
          }
        }
      }
      break;

    case 's':
      if (!empty($arg3) && is_numeric($arg3) && !$skip_args) {
        $folder_id = $arg3;
      }
      else {
        $folders = batire_user_docs_get_folders('s');
        if (is_array($folders)) {
          $keys = array_keys($folders);
          array_multisort($keys, $folders);
          foreach ($folders as $folder) {
            if ($folder['shared']) {
              if (isset($folder['nid']) && is_numeric($folder['nid'])) {
                $folder_id = $folder['nid'];
                break;
              }
            }
          }
        }
      }
      break;
  }
  return $folder_id;
}

/**
 * Get key from url
 * @return string
 */
function batire_site_batire_site_my_account_get_key_from_url() {
  $arg0 = arg(0);

  if ($arg0 == 'mon-compte') {
    $arg1 = arg(1);
    $arg2 = arg(2);

    switch ($arg1) {
      case 'mes-documents':
        return 'my_documents';
        break;

      case 'mes-dossiers':
        return 'my_folders';
        break;

      case 'mes-annotations':
        return 'my_annotations';
        break;

      case 'mon-espace-partage':
        switch ($arg2) {
          case 'documents-partages':
            return 'shared_documents';
            break;

          case 'dossiers-partages':
            return 'shared_folders';
            break;

          case 'annotations-partages':
            return 'shared_annotations';
            break;
        }
        break;

      case 'mes-recherches':
        if (!$arg2) {
          drupal_goto('mon-compte/mes-recherches/mes-profils-enregistres');
        }
        switch ($arg2) {
          case 'mes-profils-enregistres':
            return 'my_profile';
            break;
          case 'mes-alertes-recues':
            return 'my_sent_alerts';
            break;
        }
        break;
      case 'mon-abonnement':
        if (!$arg2) {
          drupal_goto('mon-compte/mon-abonnement/detail-de-mon-abonnement');
        }
        switch ($arg2) {
          case 'detail-de-mon-abonnement':
            return 'my_abonnement';
            break;

          case 'comptes-utilisateurs':
            return 'list_accounts';

          case 'membres-du-groupe' :
            return 'group_members';

          case 'date-echeance':
            return 'abonement_date';
        }
        break;
    }
  }
  return 'not found';
}

/**
 * Get list of group members uids for views argument
 */
function batire_site_batire_site_my_account_get_group_members_arg() {
  $members = mongodb_user_get_members();
  $group_members = array();
  foreach ($members as $member) {
    $group_members[] = $member['uid'];
  }
  return implode(',', $group_members);
}
<?php

/**
 * @file
 * User annotations related functionality
 */

/**
 * Callback function to supply a list of content types.
 */
function batire_user_docs_batire_user_docs_annotations_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Batire annotations'),
    'description' => t('Annotations for docs page'),
    'icon' => '',
    'category' => t('Batire'),
    'defaults' => array(),
  );
}

/**
 * Output function for the 'batire_site_annotations' content type.
 */
function batire_user_docs_batire_user_docs_annotations_content_type_render($subtype, $conf, $panel_args, $context) {
  // Make a new empty "block" which will be a Pane you can add to your Panel.
  global $user;

  $profile = mongodb_user_get_user($user->uid);
  $multipost = FALSE;
  if (is_array($profile['roles']) && (array_key_exists(BATIRE_USER_SUBACCOUNT, $profile['roles']) || array_key_exists(BATIRE_USER_MULTIADMIN, $profile['roles']))) {
    $multipost = TRUE;
  }

  $block = new stdClass();

  $nid = $panel_args[0];
  $personel_cnt = 0;
  $shared_cnt = 0;
  $shared_list = NULL;

  $personel_cnt = mongodb_docs_count_annotations($user->uid, $nid, $type = 'p');
  $personel_list = views_embed_view('batire_user_docs_annotations', 'block_1', $nid, $user->uid);

  if ($multipost) {
    $members = mongodb_user_get_members($user->uid);
    foreach ($members as $member) {
      $m_uids[] = $member['uid'];
    }
    if (!empty($m_uids) && is_array($m_uids)) {
      $uids = implode('+', $m_uids);
    }
    else {
      $uids = $user->uid;
    }
    $shared_cnt = mongodb_docs_count_annotations($user->uid, $nid, $type = 's');
    $shared_list = views_embed_view('batire_user_docs_annotations', 'block_2', $nid, $uids); // get group uids
  }

  $total_cnt = $personel_cnt + $shared_cnt;

  drupal_add_js(
  array(
    'batire_user_docs' => array(
      "annotations_url" => url('js/batire_user_docs/annotation'),
      "annotations_did" => $nid
    )
  ), 'setting'
  );
  drupal_add_js(drupal_get_path('module', 'batire_user_docs') . '/scripts/batire_user_docs.annotations.js');

  $block->content = theme('batire_user_docs_annotations', $total_cnt, $personel_list, $shared_list, $multipost);

  return $block;
}
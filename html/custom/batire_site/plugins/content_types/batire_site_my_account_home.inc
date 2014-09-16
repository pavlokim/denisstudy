<?php

/**
 * @file
 *  batire_site_my_account_home.inc
 * Create block "My account" for homepage
 */

/**
 * Implementation of hook_contant_type_ctools_content_types().
 */
function batire_site_batire_site_my_account_home_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Batire mon compte homepage block'),
    'description' => t('Block mon compte for for homepage'),
    'icon' => '',
    'category' => t('Batire'),
    'defaults' => array(),
  );
}

/**
 * Implementation of hook_content_type_content_type_render().
 */
function batire_site_batire_site_my_account_home_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->content = theme('batire_site_my_account_home_block', batire_site_batire_site_my_account_home_build_block());
  return $block;
}

/**
 * Build list of block
 * @return array
 */
function batire_site_batire_site_my_account_home_build_block() {
  global $user;
  $profile = batire_user_profile_load($user->uid);
  $items = array();
  $data = array();
  $items['my_documents'] = array(
    'url' => 'mon-compte/mes-documents',
    'title' => t('Mes documents classés'),
    'quantity' => batire_user_docs_get_user_mydocs_cnt($user->uid),
    'content' => batire_site_my_account_home_block_get_last_docs(),
  );

  if (_batire_user_is_multipost($user)) {
    $items['shared_documents'] = array(
      'url' => 'mon-compte/mon-espace-partage/documents-partages',
      'title' => t('Mes documents partagés'),
      'quantity' => batire_user_docs_get_user_mydocs_cnt($user->uid, 's'),
      'content' => batire_site_my_account_home_block_get_last_docs('s'),
    );
    if (!$items['shared_documents']['content']) {
      $items['shared_documents']['empty'] = TRUE;
      $items['shared_documents']['content'] = t('Aucun document partagé');
    }
  }


  $items['my_annotations'] = array(
    'url' => 'mon-compte/mes-annotations',
    'title' => t('Mes annotations'),
    'quantity' => batire_user_docs_get_user_myannos_cnt($user->uid),
    'content' => batire_site_my_account_home_block_get_last_anno(),
  );

  $items['search_results'] = array(
    'url' => 'mon-compte/mes-recherches/mes-profils-enregistres',
    'title' => t('Mes profils de recherche'),
    'quantity' => batire_user_docs_get_user_searches_cnt($user->uid, 0),
    'content' => batire_site_my_account_home_block_get_last_searches(),
  );

  if (!$items['my_documents']['content']) {
    $items['my_documents']['empty'] = TRUE;
    $items['my_documents']['content'] = t('Aucun document classé');
  }

  if (!$items['my_annotations']['content']) {
    $items['my_annotations']['empty'] = TRUE;
    $items['my_annotations']['content'] = t('Aucune annotation enregistrée');
  }

  if (!($items['search_results']['content'])) {
    $items['search_results']['empty'] = TRUE;
    $items['search_results']['content'] = t('Aucune recherche enregistrée');
  }

  if ($profile) {
    if (isset($profile->field_default_search[0]['nid']) && $profile->field_default_search[0]['nid']) {
      $data['default_profile'] = 1;
    }
    else {
      $data['default_profile'] = 0;
    }
  }
  else {
    $data['default_profile'] = 0;
  }

  $data['login_date'] = mongodb_user_get_user_last_login('d/m/Y', $user->uid);
  $data['login_date2'] = '';
  //Check for new docs
  if ($profile->field_new_docs_flag[0]['value'] && $data['login_date']) {
    $new_search = array();
    $data['login_date2'] = mongodb_user_get_user_last_login('Y-m-d', $user->uid);
    $last_login_str = '"' . $data['login_date2'] . '"';

    //Have default search profile
    if (isset($profile->field_default_search[0]['nid']) && $profile->field_default_search[0]['nid']) {
      $search = mongodb_search_get_search_data_by_nid($profile->field_default_search[0]['nid']);
      $new_search = array('types' => $search['data']['types'], 'trades' => $search['data']['trades'], 'themes' => $search['data']['themes']);
    }

    $new_search['custom_filter'] = '(dateCreation>' . $last_login_str . ')or(dateMaj>' . $last_login_str . ')';
    $request = batire_search_map_request(
    $new_search, NULL, 'relevant', 'desc', 0, 0
    );
    $new_docs = batire_antidot_search_run($request, 0);

    //Save 0 flag and new docs counter
    $profile->field_new_docs_flag[0]['value'] = 0;
    $profile->field_new_docs_cnt[0]['value'] = $new_docs->total_cnt;
    node_save($profile);
  }

  $data['doc_quantity'] = !empty($profile->field_new_docs_cnt[0]['value']) ? $profile->field_new_docs_cnt[0]['value'] : 0;
  $data['section'] = $items;

  return $data;
}

/**
 * Get last 5 user documents
 */
function batire_site_my_account_home_block_get_last_docs($key = NULL) {
  global $user;

  $sql = "SELECT cffd.field_folder_documents_nid, cffd.field_folder_documents_added,
          n2.type, n2.title
          FROM {content_field_folder_documents} AS cffd
          LEFT JOIN {node} AS n1 ON cffd.vid = n1.vid
          LEFT JOIN {node} as n2 ON n2.nid = cffd.field_folder_documents_nid ";
  if ($key == 's') {
    $sql .= " LEFT JOIN {content_field_folder_shared} ON content_field_folder_shared.vid = n1.vid
              WHERE field_folder_shared_value = 1 AND ";
  }
  else {
    $sql .= " WHERE ";
  }
  $sql .= " n1.uid = %d AND n2.status = 1
           GROUP BY cffd.field_folder_documents_nid
           ORDER BY cffd.field_folder_documents_added DESC";

  $document_info_q = db_query_range($sql, $user->uid, 0, 5);

  $links = array();

  while ($document = db_fetch_object($document_info_q)) {
    if ($document->title) {
      $title = batire_site_truncate_utf8($document->title, 25, FALSE, TRUE);

      $links[] = l($title, 'node/' . $document->field_folder_documents_nid, array(
        'attributes' => array(
          'class' => $document->type . ' theme-item'))) . ' ' .
      format_date($document->field_folder_documents_added, 'custom', 'd/m/y');
    }
  }
  if (!$links) {
    return FALSE;
  }
  return theme('item_list', $links);
}

/**
 * Get last 3 user annotation
 */
function batire_site_my_account_home_block_get_last_anno() {
  global $user;

  $sql = "SELECT
          node.type, ctbua.field_annotation_text_value, node.uid, node.created, node.nid, ctbua.field_annotation_doc_nid
          FROM node node
          LEFT JOIN content_type_batire_user_annotation ctbua ON ctbua.vid = node.vid
	        LEFT JOIN node n1 ON n1.nid = ctbua.field_annotation_doc_nid
          LEFT JOIN content_field_annotation_shared cfas ON cfas.vid = node.vid
          WHERE node.type = 'batire_user_annotation'
          AND n1.status = 1 AND node.uid = %d
          ORDER BY node.created DESC";

  $anno_info_q = db_query_range($sql, $user->uid, 0, 3);
  $links = array();

  while ($annotation = db_fetch_object($anno_info_q)) {
    $body = batire_site_truncate_utf8(html_entity_decode($annotation->field_annotation_text_value, ENT_QUOTES), 25, FALSE, TRUE);

    $links[] = l($body, 'node/' . $annotation->field_annotation_doc_nid, array(
      'fragment' => 'annotation-' . $annotation->nid,
      'attributes' => array(
        'class' => 'batire_texte_normatifs theme-item'))) . ' ' .
    format_date($annotation->created, 'custom', 'd/m/y');
  }
  if (!$links) {
    return FALSE;
  }
  return theme('item_list', $links);
}

/**
 * Get last 3 user search
 */
function batire_site_my_account_home_block_get_last_searches() {
  global $user;

  $sql = "SELECT
          node.type, node.title, node.created, node.uid, node.nid, ctbusp.`field_search_id_value`
          FROM {node} node
          LEFT JOIN {content_type_batire_user_search_profile} AS ctbusp ON ctbusp.vid = node.vid
          WHERE type = 'batire_user_search_profile' AND status = 1 AND uid = %d AND field_profile_type_value = 0
          ORDER BY node.created DESC";

  $user_search_q = db_query_range($sql, $user->uid, 0, 3);
  $links = array();

  while ($search = db_fetch_object($user_search_q)) {
    $body = batire_site_truncate_utf8($search->title, 25, FALSE, TRUE);

    $links[] = l($body, 'recherche-avancee/resultats/' . $search->field_search_id_value, array(
      'attributes' => array(
        'class' => 'batire_texte_normatifs theme-item'))) . ' ' .
    format_date($search->created, 'custom', 'd/m/y');
  }
  if (!$links) {
    return FALSE;
  }

  return theme('item_list', $links);
}
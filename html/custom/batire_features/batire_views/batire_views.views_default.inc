<?php

/**
 * Implementation of hook_views_default_views().
 */
function batire_views_views_default_views() {
  $views = array();

  // Exported view: batire_admin_content
  $view = new view;
  $view->name = 'batire_admin_content';
  $view->description = '';
  $view->tag = 'Batire';
  $view->base_table = 'node';
  $view->human_name = 'Batire content list';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Default */
  $handler = $view->new_display('default', 'Default', 'default');
  $handler->display->display_options['title'] = 'Contenu';
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => 4,
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 20;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'bulk';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'timestamp' => 'title',
    'type' => 'type',
    'name' => 'name',
    'status' => 'status',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '&nbsp;',
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['style_options']['operations'] = array(
    'pathauto_node_update_alias_multiple-0d56f9c10fbb36ec3264abea71b6f416' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
    'node_publish_action' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
    'node_unpublish_action' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
    'views_bulk_operations_delete_node_action' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
  );
  $handler->display->display_options['style_options']['execution_type'] = '1';
  $handler->display->display_options['style_options']['display_type'] = '0';
  $handler->display->display_options['style_options']['display_result'] = 1;
  $handler->display->display_options['style_options']['merge_single_action'] = 0;
  /* Texte de page vide: Global : Zone de texte */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['label'] = '';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = 'Aucun élément ne satisfait les filtres sélectionnés. Essayez de les changer pour obtenir plus de résultats.';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Champ: Nœud : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Champ: Nœud : Présente des contenus nouveaux */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history_user';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Nouveau ?';
  $handler->display->display_options['fields']['timestamp']['link_to_node'] = 0;
  $handler->display->display_options['fields']['timestamp']['comments'] = 0;
  /* Champ: Nœud : Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  /* Champ: Utilisateur : Nom */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Auteur';
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  /* Champ: Nœud : Publié */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Champ: Nœud : Lien de modification */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Modifier';
  /* Critère de tri: Nœud : Date de mise à jour */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filtrer: Nœud : Titre */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Le titre contient';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['optional'] = 1;
  $handler->display->display_options['filters']['title']['case'] = 0;
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['single'] = 0;
  $handler->display->display_options['filters']['type']['expose']['reduce'] = 0;
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Publié';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/batire-site/content';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Contenu';
  $handler->display->display_options['menu']['description'] = 'Afficher/Trier/Filtrer le contenu';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['batire_admin_content'] = array(
    t('Default'),
    t('Contenu'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('Aucun élément ne satisfait les filtres sélectionnés. Essayez de les changer pour obtenir plus de résultats.'),
    t('Titre'),
    t('Nouveau ?'),
    t('Type'),
    t('Auteur'),
    t('Publié'),
    t('Modifier'),
    t('Le titre contient'),
    t('Page'),
  );

  $views[$view->name] = $view;

  // Exported view: batire_admin_users
  $view = new view;
  $view->name = 'batire_admin_users';
  $view->description = '';
  $view->tag = 'Batire';
  $view->base_table = 'users';
  $view->human_name = 'Batire users list';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Default */
  $handler = $view->new_display('default', 'Default', 'default');
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access users list';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '50, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'bulk';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_user_surname_value' => 'field_user_surname_value',
    'field_user_name_value' => 'field_user_name_value',
    'mail' => 'mail',
    'field_user_login_date_value' => 'field_user_login_date_value',
    'name' => 'name',
    'svc_login' => 'svc_login',
    'field_subscribed_to_newsletter_value' => 'field_subscribed_to_newsletter_value',
    'status' => 'status',
    'tid_1' => 'tid_1',
    'tid' => 'tid',
    'abo_num' => 'abo_num',
    'field_user_dates_value' => 'field_user_dates_value',
    'field_user_dates_value2' => 'field_user_dates_value2',
    'modify_free' => 'modify_free',
    'grand_user' => 'grand_user',
  );
  $handler->display->display_options['style_options']['default'] = 'field_user_dates_value';
  $handler->display->display_options['style_options']['info'] = array(
    'field_user_surname_value' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_user_name_value' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_user_login_date_value' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'svc_login' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_subscribed_to_newsletter_value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'tid_1' => array(
      'align' => '',
      'separator' => '',
    ),
    'tid' => array(
      'align' => '',
      'separator' => '',
    ),
    'abo_num' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_user_dates_value' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'field_user_dates_value2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'modify_free' => array(
      'align' => '',
      'separator' => '',
    ),
    'grand_user' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['style_options']['operations'] = array(
    'batire_webmaster_user_operations_export_users' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
    'batire_newsletter_subscribe_user_operation' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
    'batire_user_delete_delete_user_operation' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
    'batire_newsletter_unsubscribe_user_operation' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
  );
  $handler->display->display_options['style_options']['execution_type'] = '1';
  $handler->display->display_options['style_options']['display_type'] = '0';
  $handler->display->display_options['style_options']['display_result'] = 1;
  $handler->display->display_options['style_options']['merge_single_action'] = 1;
  /* Relation: Nœud : Contenu de profil */
  $handler->display->display_options['relationships']['content_profile_rel']['id'] = 'content_profile_rel';
  $handler->display->display_options['relationships']['content_profile_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['content_profile_rel']['field'] = 'content_profile_rel';
  $handler->display->display_options['relationships']['content_profile_rel']['required'] = 0;
  $handler->display->display_options['relationships']['content_profile_rel']['type'] = 'batire_user_profile';
  /* Champ: Contenu : Nom (field_user_surname) */
  $handler->display->display_options['fields']['field_user_surname_value']['id'] = 'field_user_surname_value';
  $handler->display->display_options['fields']['field_user_surname_value']['table'] = 'node_data_field_user_surname';
  $handler->display->display_options['fields']['field_user_surname_value']['field'] = 'field_user_surname_value';
  $handler->display->display_options['fields']['field_user_surname_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_user_surname_value']['label'] = 'Nom';
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_surname_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_surname_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_surname_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_surname_value']['link_to_node'] = 0;
  /* Champ: Contenu : Prénom (field_user_name) */
  $handler->display->display_options['fields']['field_user_name_value']['id'] = 'field_user_name_value';
  $handler->display->display_options['fields']['field_user_name_value']['table'] = 'node_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name_value']['field'] = 'field_user_name_value';
  $handler->display->display_options['fields']['field_user_name_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_user_name_value']['label'] = 'Prénom';
  $handler->display->display_options['fields']['field_user_name_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_name_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_name_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_name_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name_value']['link_to_node'] = 0;
  /* Champ: Utilisateur : Courriel */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'Adresse électronique';
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['external'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['mail']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['mail']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['html'] = 0;
  $handler->display->display_options['fields']['mail']['element_type'] = '0';
  $handler->display->display_options['fields']['mail']['element_label_type'] = '0';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['mail']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['mail']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['mail']['hide_empty'] = 0;
  $handler->display->display_options['fields']['mail']['empty_zero'] = 0;
  $handler->display->display_options['fields']['mail']['hide_alter_empty'] = 1;
  /* Champ: Contenu : Login date (field_user_login_date) */
  $handler->display->display_options['fields']['field_user_login_date_value']['id'] = 'field_user_login_date_value';
  $handler->display->display_options['fields']['field_user_login_date_value']['table'] = 'node_data_field_user_login_date';
  $handler->display->display_options['fields']['field_user_login_date_value']['field'] = 'field_user_login_date_value';
  $handler->display->display_options['fields']['field_user_login_date_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_user_login_date_value']['label'] = 'Dernier accès';
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_login_date_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_login_date_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_login_date_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_login_date_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['label_type'] = 'custom';
  $handler->display->display_options['fields']['field_user_login_date_value']['format'] = 'short';
  /* Champ: Utilisateur : Nom */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Login Drupal';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 0;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Champ: Utilisateur : SVC Login */
  $handler->display->display_options['fields']['svc_login']['id'] = 'svc_login';
  $handler->display->display_options['fields']['svc_login']['table'] = 'users';
  $handler->display->display_options['fields']['svc_login']['field'] = 'svc_login';
  $handler->display->display_options['fields']['svc_login']['label'] = 'Login SVC';
  $handler->display->display_options['fields']['svc_login']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['external'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['svc_login']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['svc_login']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['html'] = 0;
  $handler->display->display_options['fields']['svc_login']['element_type'] = '0';
  $handler->display->display_options['fields']['svc_login']['element_label_type'] = '0';
  $handler->display->display_options['fields']['svc_login']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['svc_login']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['svc_login']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['svc_login']['hide_empty'] = 0;
  $handler->display->display_options['fields']['svc_login']['empty_zero'] = 0;
  $handler->display->display_options['fields']['svc_login']['hide_alter_empty'] = 1;
  /* Champ: Batire User : User password */
  $handler->display->display_options['fields']['password']['id'] = 'password';
  $handler->display->display_options['fields']['password']['table'] = 'batire_user';
  $handler->display->display_options['fields']['password']['field'] = 'password';
  $handler->display->display_options['fields']['password']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['password']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['password']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['password']['alter']['external'] = 0;
  $handler->display->display_options['fields']['password']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['password']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['password']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['password']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['password']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['password']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['password']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['password']['alter']['html'] = 0;
  $handler->display->display_options['fields']['password']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['password']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['password']['hide_empty'] = 0;
  $handler->display->display_options['fields']['password']['empty_zero'] = 0;
  $handler->display->display_options['fields']['password']['hide_alter_empty'] = 1;
  /* Champ: Contenu : Subscribed to newsletter (field_subscribed_to_newsletter) */
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['id'] = 'field_subscribed_to_newsletter_value';
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['table'] = 'node_data_field_subscribed_to_newsletter';
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['field'] = 'field_subscribed_to_newsletter_value';
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['label'] = 'Newsletter status';
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['multiple']['group'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['multiple']['multiple_reversed'] = 0;
  /* Champ: Utilisateur : Actif */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_type'] = '0';
  $handler->display->display_options['fields']['status']['element_label_type'] = '0';
  $handler->display->display_options['fields']['status']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['status']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['status']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Champ: Rôles */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'term_node';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['tid_1']['ui_name'] = 'Rôles';
  $handler->display->display_options['fields']['tid_1']['label'] = 'Rôles';
  $handler->display->display_options['fields']['tid_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid_1']['element_type'] = '0';
  $handler->display->display_options['fields']['tid_1']['element_label_type'] = '0';
  $handler->display->display_options['fields']['tid_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['tid_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['tid_1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['tid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['tid_1']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['tid_1']['limit'] = 1;
  $handler->display->display_options['fields']['tid_1']['vids'] = array(
    14 => 14,
    1 => 0,
    7 => 0,
    10 => 0,
    4 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    3 => 0,
  );
  /* Champ: Offre */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'term_node';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['tid']['ui_name'] = 'Offre';
  $handler->display->display_options['fields']['tid']['label'] = 'Offre';
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid']['element_type'] = '0';
  $handler->display->display_options['fields']['tid']['element_label_type'] = '0';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['tid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['tid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['tid']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['tid']['limit'] = 1;
  $handler->display->display_options['fields']['tid']['vids'] = array(
    13 => 13,
    1 => 0,
    7 => 0,
    10 => 0,
    4 => 0,
    11 => 0,
    12 => 0,
    8 => 0,
    14 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    3 => 0,
  );
  /* Champ: Utilisateur : Abonnement */
  $handler->display->display_options['fields']['abo_num']['id'] = 'abo_num';
  $handler->display->display_options['fields']['abo_num']['table'] = 'users';
  $handler->display->display_options['fields']['abo_num']['field'] = 'abo_num';
  $handler->display->display_options['fields']['abo_num']['label'] = 'Numéro d’abonné';
  $handler->display->display_options['fields']['abo_num']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['external'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['abo_num']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['abo_num']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['html'] = 0;
  $handler->display->display_options['fields']['abo_num']['element_type'] = '0';
  $handler->display->display_options['fields']['abo_num']['element_label_type'] = '0';
  $handler->display->display_options['fields']['abo_num']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['abo_num']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['abo_num']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['abo_num']['hide_empty'] = 0;
  $handler->display->display_options['fields']['abo_num']['empty_zero'] = 0;
  $handler->display->display_options['fields']['abo_num']['hide_alter_empty'] = 1;
  /* Champ: Date d&#039;effet */
  $handler->display->display_options['fields']['field_user_dates_value']['id'] = 'field_user_dates_value';
  $handler->display->display_options['fields']['field_user_dates_value']['table'] = 'node_data_field_user_dates';
  $handler->display->display_options['fields']['field_user_dates_value']['field'] = 'field_user_dates_value';
  $handler->display->display_options['fields']['field_user_dates_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_user_dates_value']['ui_name'] = 'Date d\'effet';
  $handler->display->display_options['fields']['field_user_dates_value']['label'] = 'Date d\'effet';
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_dates_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_dates_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_dates_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_dates_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['label_type'] = 'custom';
  $handler->display->display_options['fields']['field_user_dates_value']['fromto']['fromto'] = 'value';
  /* Champ: Contenu : Date d&#039;effet / d&#039;échéance (field_user_dates) - Date de fin */
  $handler->display->display_options['fields']['field_user_dates_value2']['id'] = 'field_user_dates_value2';
  $handler->display->display_options['fields']['field_user_dates_value2']['table'] = 'node_data_field_user_dates';
  $handler->display->display_options['fields']['field_user_dates_value2']['field'] = 'field_user_dates_value2';
  $handler->display->display_options['fields']['field_user_dates_value2']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_user_dates_value2']['label'] = 'Date d\'échéance';
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_dates_value2']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_dates_value2']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_dates_value2']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_dates_value2']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['label_type'] = 'custom';
  $handler->display->display_options['fields']['field_user_dates_value2']['fromto']['fromto'] = 'value2';
  /* Champ: Contenu : Code Privilège (field_user_promo) */
  $handler->display->display_options['fields']['field_user_promo_value']['id'] = 'field_user_promo_value';
  $handler->display->display_options['fields']['field_user_promo_value']['table'] = 'node_data_field_user_promo';
  $handler->display->display_options['fields']['field_user_promo_value']['field'] = 'field_user_promo_value';
  $handler->display->display_options['fields']['field_user_promo_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_user_promo_value']['label'] = 'Code Privilège';
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_user_promo_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_promo_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_promo_value']['link_to_node'] = 0;
  /* Champ: Utilisateur : Modify free user term */
  $handler->display->display_options['fields']['modify_free']['id'] = 'modify_free';
  $handler->display->display_options['fields']['modify_free']['table'] = 'users';
  $handler->display->display_options['fields']['modify_free']['field'] = 'modify_free';
  $handler->display->display_options['fields']['modify_free']['label'] = 'Modifier la durée d’essai';
  $handler->display->display_options['fields']['modify_free']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['external'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['modify_free']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['modify_free']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['html'] = 0;
  $handler->display->display_options['fields']['modify_free']['element_type'] = '0';
  $handler->display->display_options['fields']['modify_free']['element_label_type'] = '0';
  $handler->display->display_options['fields']['modify_free']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['modify_free']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['modify_free']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['modify_free']['hide_empty'] = 0;
  $handler->display->display_options['fields']['modify_free']['empty_zero'] = 0;
  $handler->display->display_options['fields']['modify_free']['hide_alter_empty'] = 0;
  /* Champ: Grand compte */
  $handler->display->display_options['fields']['grand_user']['id'] = 'grand_user';
  $handler->display->display_options['fields']['grand_user']['table'] = 'users';
  $handler->display->display_options['fields']['grand_user']['field'] = 'grand_user';
  $handler->display->display_options['fields']['grand_user']['ui_name'] = 'Grand compte';
  $handler->display->display_options['fields']['grand_user']['label'] = 'Grand compte';
  $handler->display->display_options['fields']['grand_user']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['external'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['grand_user']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['grand_user']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['html'] = 0;
  $handler->display->display_options['fields']['grand_user']['element_type'] = '0';
  $handler->display->display_options['fields']['grand_user']['element_label_type'] = '0';
  $handler->display->display_options['fields']['grand_user']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['grand_user']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['grand_user']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['grand_user']['hide_empty'] = 0;
  $handler->display->display_options['fields']['grand_user']['empty_zero'] = 0;
  $handler->display->display_options['fields']['grand_user']['hide_alter_empty'] = 0;
  /* Champ: Batire User : Abo admin */
  $handler->display->display_options['fields']['abo_admin']['id'] = 'abo_admin';
  $handler->display->display_options['fields']['abo_admin']['table'] = 'batire_user';
  $handler->display->display_options['fields']['abo_admin']['field'] = 'abo_admin';
  $handler->display->display_options['fields']['abo_admin']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['external'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['abo_admin']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['abo_admin']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['html'] = 0;
  $handler->display->display_options['fields']['abo_admin']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['abo_admin']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['abo_admin']['hide_empty'] = 0;
  $handler->display->display_options['fields']['abo_admin']['empty_zero'] = 0;
  $handler->display->display_options['fields']['abo_admin']['hide_alter_empty'] = 1;
  /* Champ: Batire GC Statistics : Access to statistics */
  $handler->display->display_options['fields']['password_1']['id'] = 'password_1';
  $handler->display->display_options['fields']['password_1']['table'] = 'batire_gc_statistics';
  $handler->display->display_options['fields']['password_1']['field'] = 'password';
  $handler->display->display_options['fields']['password_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['password_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['password_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['password_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['password_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['password_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['password_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['password_1']['hide_alter_empty'] = 1;
  /* Champ: Batire User : User products */
  $handler->display->display_options['fields']['products']['id'] = 'products';
  $handler->display->display_options['fields']['products']['table'] = 'batire_user';
  $handler->display->display_options['fields']['products']['field'] = 'products';
  $handler->display->display_options['fields']['products']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['products']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['products']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['products']['alter']['external'] = 0;
  $handler->display->display_options['fields']['products']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['products']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['products']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['products']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['products']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['products']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['products']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['products']['alter']['html'] = 0;
  $handler->display->display_options['fields']['products']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['products']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['products']['hide_empty'] = 0;
  $handler->display->display_options['fields']['products']['empty_zero'] = 0;
  $handler->display->display_options['fields']['products']['hide_alter_empty'] = 1;
  /* Champ: Contenu : Type utilisateur (field_user_origene) */
  $handler->display->display_options['fields']['field_user_origene_value']['id'] = 'field_user_origene_value';
  $handler->display->display_options['fields']['field_user_origene_value']['table'] = 'node_data_field_user_origene';
  $handler->display->display_options['fields']['field_user_origene_value']['field'] = 'field_user_origene_value';
  $handler->display->display_options['fields']['field_user_origene_value']['relationship'] = 'content_profile_rel';
  /* Critère de tri: Contenu : Date d&#039;effet / d&#039;échéance (field_user_dates) - Date de début */
  $handler->display->display_options['sorts']['field_user_dates_value']['id'] = 'field_user_dates_value';
  $handler->display->display_options['sorts']['field_user_dates_value']['table'] = 'node_data_field_user_dates';
  $handler->display->display_options['sorts']['field_user_dates_value']['field'] = 'field_user_dates_value';
  $handler->display->display_options['sorts']['field_user_dates_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['sorts']['field_user_dates_value']['order'] = 'DESC';
  /* Filtrer: Utilisateur : Nom */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid']['value'] = array(
    0 => 0,
  );
  $handler->display->display_options['filters']['uid']['expose']['operator'] = FALSE;
  /* Filtrer: Utilisateur : Nom */
  $handler->display->display_options['filters']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['filters']['uid_1']['table'] = 'users';
  $handler->display->display_options['filters']['uid_1']['field'] = 'uid';
  $handler->display->display_options['filters']['uid_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid_1']['value'] = array(
    0 => '1',
  );
  /* Filtrer: Contenu : Nom (field_user_surname) */
  $handler->display->display_options['filters']['field_user_surname_value']['id'] = 'field_user_surname_value';
  $handler->display->display_options['filters']['field_user_surname_value']['table'] = 'node_data_field_user_surname';
  $handler->display->display_options['filters']['field_user_surname_value']['field'] = 'field_user_surname_value';
  $handler->display->display_options['filters']['field_user_surname_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['field_user_surname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_surname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_surname_value']['expose']['operator'] = 'field_user_surname_value_op';
  $handler->display->display_options['filters']['field_user_surname_value']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['field_user_surname_value']['expose']['label'] = 'Nom';
  $handler->display->display_options['filters']['field_user_surname_value']['expose']['identifier'] = 'field_user_surname_value';
  $handler->display->display_options['filters']['field_user_surname_value']['expose']['optional'] = TRUE;
  $handler->display->display_options['filters']['field_user_surname_value']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['field_user_surname_value']['case'] = 1;
  /* Filtrer: Adresse électronique */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['ui_name'] = 'Adresse électronique';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'Adresse électronique';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['optional'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['mail']['case'] = 1;
  /* Filtrer: Raison sociale */
  $handler->display->display_options['filters']['field_user_company_value']['id'] = 'field_user_company_value';
  $handler->display->display_options['filters']['field_user_company_value']['table'] = 'node_data_field_user_company';
  $handler->display->display_options['filters']['field_user_company_value']['field'] = 'field_user_company_value';
  $handler->display->display_options['filters']['field_user_company_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['field_user_company_value']['ui_name'] = 'Raison sociale';
  $handler->display->display_options['filters']['field_user_company_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_company_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_company_value']['expose']['operator'] = 'field_user_company_value_op';
  $handler->display->display_options['filters']['field_user_company_value']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['field_user_company_value']['expose']['label'] = 'Raison sociale';
  $handler->display->display_options['filters']['field_user_company_value']['expose']['identifier'] = 'field_user_company_value';
  $handler->display->display_options['filters']['field_user_company_value']['expose']['optional'] = TRUE;
  $handler->display->display_options['filters']['field_user_company_value']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['field_user_company_value']['case'] = 1;
  /* Filtrer: Utilisateur : Abonnement */
  $handler->display->display_options['filters']['abo_num']['id'] = 'abo_num';
  $handler->display->display_options['filters']['abo_num']['table'] = 'users';
  $handler->display->display_options['filters']['abo_num']['field'] = 'abo_num';
  $handler->display->display_options['filters']['abo_num']['exposed'] = TRUE;
  $handler->display->display_options['filters']['abo_num']['expose']['operator'] = 'abo_num_op';
  $handler->display->display_options['filters']['abo_num']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['abo_num']['expose']['label'] = 'Numéro d’abonné';
  $handler->display->display_options['filters']['abo_num']['expose']['identifier'] = 'abo_num';
  $handler->display->display_options['filters']['abo_num']['expose']['single'] = TRUE;
  /* Filtrer: Type d’abonnement */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'term_node';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['tid']['ui_name'] = 'Type d’abonnement';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Type d’abonnement';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vid'] = '13';
  $handler->display->display_options['filters']['tid']['error_message'] = 0;
  /* Filtrer: From */
  $handler->display->display_options['filters']['field_user_dates_value']['id'] = 'field_user_dates_value';
  $handler->display->display_options['filters']['field_user_dates_value']['table'] = 'node_data_field_user_dates';
  $handler->display->display_options['filters']['field_user_dates_value']['field'] = 'field_user_dates_value';
  $handler->display->display_options['filters']['field_user_dates_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['field_user_dates_value']['ui_name'] = 'From';
  $handler->display->display_options['filters']['field_user_dates_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_user_dates_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_dates_value']['expose']['operator'] = 'field_user_dates_value_op';
  $handler->display->display_options['filters']['field_user_dates_value']['expose']['limit_operators'] = 0;
  $handler->display->display_options['filters']['field_user_dates_value']['expose']['label'] = 'Date d\'effet';
  $handler->display->display_options['filters']['field_user_dates_value']['expose']['use_operator'] = 1;
  $handler->display->display_options['filters']['field_user_dates_value']['expose']['identifier'] = 'field_user_dates_value';
  $handler->display->display_options['filters']['field_user_dates_value']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['field_user_dates_value']['allow_null'] = 1;
  $handler->display->display_options['filters']['field_user_dates_value']['date_fields'] = array(
    'node_data_field_user_dates.field_user_dates_value' => 'node_data_field_user_dates.field_user_dates_value',
  );
  $handler->display->display_options['filters']['field_user_dates_value']['date_method'] = 'AND';
  $handler->display->display_options['filters']['field_user_dates_value']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_user_dates_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_user_dates_value']['default_date'] = '';
  $handler->display->display_options['filters']['field_user_dates_value']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_user_dates_value']['year_range'] = '-3:+3';
  /* Filtrer: To */
  $handler->display->display_options['filters']['field_user_dates_value2']['id'] = 'field_user_dates_value2';
  $handler->display->display_options['filters']['field_user_dates_value2']['table'] = 'node_data_field_user_dates';
  $handler->display->display_options['filters']['field_user_dates_value2']['field'] = 'field_user_dates_value2';
  $handler->display->display_options['filters']['field_user_dates_value2']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['field_user_dates_value2']['ui_name'] = 'To';
  $handler->display->display_options['filters']['field_user_dates_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_user_dates_value2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_dates_value2']['expose']['operator'] = 'field_user_dates_value2_op';
  $handler->display->display_options['filters']['field_user_dates_value2']['expose']['limit_operators'] = 0;
  $handler->display->display_options['filters']['field_user_dates_value2']['expose']['label'] = 'Date d\'échéance';
  $handler->display->display_options['filters']['field_user_dates_value2']['expose']['use_operator'] = 1;
  $handler->display->display_options['filters']['field_user_dates_value2']['expose']['identifier'] = 'field_user_dates_value2';
  $handler->display->display_options['filters']['field_user_dates_value2']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['field_user_dates_value2']['allow_null'] = 1;
  $handler->display->display_options['filters']['field_user_dates_value2']['date_fields'] = array(
    'node_data_field_user_dates.field_user_dates_value2' => 'node_data_field_user_dates.field_user_dates_value2',
  );
  $handler->display->display_options['filters']['field_user_dates_value2']['date_method'] = 'AND';
  $handler->display->display_options['filters']['field_user_dates_value2']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_user_dates_value2']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_user_dates_value2']['default_date'] = '';
  $handler->display->display_options['filters']['field_user_dates_value2']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_user_dates_value2']['year_range'] = '-3:+3';
  /* Filtrer: Rôle */
  $handler->display->display_options['filters']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['table'] = 'term_node';
  $handler->display->display_options['filters']['tid_1']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_1']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['tid_1']['ui_name'] = 'Rôle';
  $handler->display->display_options['filters']['tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['tid_1']['expose']['label'] = 'Rôle';
  $handler->display->display_options['filters']['tid_1']['expose']['identifier'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid_1']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['tid_1']['vid'] = '14';
  $handler->display->display_options['filters']['tid_1']['error_message'] = 0;
  /* Filtrer: Utilisateur : SVC Login */
  $handler->display->display_options['filters']['svc_login']['id'] = 'svc_login';
  $handler->display->display_options['filters']['svc_login']['table'] = 'users';
  $handler->display->display_options['filters']['svc_login']['field'] = 'svc_login';
  $handler->display->display_options['filters']['svc_login']['exposed'] = TRUE;
  $handler->display->display_options['filters']['svc_login']['expose']['operator'] = 'svc_login_op';
  $handler->display->display_options['filters']['svc_login']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['svc_login']['expose']['label'] = 'SVC Login';
  $handler->display->display_options['filters']['svc_login']['expose']['identifier'] = 'svc_login';
  $handler->display->display_options['filters']['svc_login']['expose']['single'] = TRUE;
  /* Filtrer: Contenu : Subscribed to newsletter (field_subscribed_to_newsletter) - Valeurs autorisées */
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['id'] = 'field_subscribed_to_newsletter_value_many_to_one';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['table'] = 'node_data_field_subscribed_to_newsletter';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['field'] = 'field_subscribed_to_newsletter_value_many_to_one';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['operator'] = 'and';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['expose']['operator'] = 'field_subscribed_to_newsletter_value_many_to_one_op';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['expose']['label'] = 'Subscribed to newsletter';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['expose']['identifier'] = 'field_subscribed_to_newsletter_value_many_to_one';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['reduce_duplicates'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu : Nom (field_user_surname) */
  $handler->display->display_options['fields']['field_user_surname_value']['id'] = 'field_user_surname_value';
  $handler->display->display_options['fields']['field_user_surname_value']['table'] = 'node_data_field_user_surname';
  $handler->display->display_options['fields']['field_user_surname_value']['field'] = 'field_user_surname_value';
  $handler->display->display_options['fields']['field_user_surname_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_user_surname_value']['label'] = 'Nom';
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_surname_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_surname_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_surname_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_surname_value']['link_to_node'] = 0;
  /* Champ: Contenu : Prénom (field_user_name) */
  $handler->display->display_options['fields']['field_user_name_value']['id'] = 'field_user_name_value';
  $handler->display->display_options['fields']['field_user_name_value']['table'] = 'node_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name_value']['field'] = 'field_user_name_value';
  $handler->display->display_options['fields']['field_user_name_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_user_name_value']['label'] = 'Prénom';
  $handler->display->display_options['fields']['field_user_name_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_name_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_name_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_name_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_name_value']['link_to_node'] = 0;
  /* Champ: Utilisateur : Courriel */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'Adresse électronique';
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['external'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['mail']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['mail']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['html'] = 0;
  $handler->display->display_options['fields']['mail']['element_type'] = '0';
  $handler->display->display_options['fields']['mail']['element_label_type'] = '0';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['mail']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['mail']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['mail']['hide_empty'] = 0;
  $handler->display->display_options['fields']['mail']['empty_zero'] = 0;
  $handler->display->display_options['fields']['mail']['hide_alter_empty'] = 1;
  /* Champ: Contenu : Login date (field_user_login_date) */
  $handler->display->display_options['fields']['field_user_login_date_value']['id'] = 'field_user_login_date_value';
  $handler->display->display_options['fields']['field_user_login_date_value']['table'] = 'node_data_field_user_login_date';
  $handler->display->display_options['fields']['field_user_login_date_value']['field'] = 'field_user_login_date_value';
  $handler->display->display_options['fields']['field_user_login_date_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_user_login_date_value']['label'] = 'Dernier accès';
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_login_date_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_login_date_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_login_date_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_login_date_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_user_login_date_value']['label_type'] = 'custom';
  $handler->display->display_options['fields']['field_user_login_date_value']['format'] = 'short';
  /* Champ: Utilisateur : Nom */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Login Drupal';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 0;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Champ: Utilisateur : SVC Login */
  $handler->display->display_options['fields']['svc_login']['id'] = 'svc_login';
  $handler->display->display_options['fields']['svc_login']['table'] = 'users';
  $handler->display->display_options['fields']['svc_login']['field'] = 'svc_login';
  $handler->display->display_options['fields']['svc_login']['label'] = 'Login SVC';
  $handler->display->display_options['fields']['svc_login']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['external'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['svc_login']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['svc_login']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['svc_login']['alter']['html'] = 0;
  $handler->display->display_options['fields']['svc_login']['element_type'] = '0';
  $handler->display->display_options['fields']['svc_login']['element_label_type'] = '0';
  $handler->display->display_options['fields']['svc_login']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['svc_login']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['svc_login']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['svc_login']['hide_empty'] = 0;
  $handler->display->display_options['fields']['svc_login']['empty_zero'] = 0;
  $handler->display->display_options['fields']['svc_login']['hide_alter_empty'] = 1;
  /* Champ: Batire User : User password */
  $handler->display->display_options['fields']['password']['id'] = 'password';
  $handler->display->display_options['fields']['password']['table'] = 'batire_user';
  $handler->display->display_options['fields']['password']['field'] = 'password';
  $handler->display->display_options['fields']['password']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['password']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['password']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['password']['alter']['external'] = 0;
  $handler->display->display_options['fields']['password']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['password']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['password']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['password']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['password']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['password']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['password']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['password']['alter']['html'] = 0;
  $handler->display->display_options['fields']['password']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['password']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['password']['hide_empty'] = 0;
  $handler->display->display_options['fields']['password']['empty_zero'] = 0;
  $handler->display->display_options['fields']['password']['hide_alter_empty'] = 1;
  /* Champ: Contenu : Subscribed to newsletter (field_subscribed_to_newsletter) */
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['id'] = 'field_subscribed_to_newsletter_value';
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['table'] = 'node_data_field_subscribed_to_newsletter';
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['field'] = 'field_subscribed_to_newsletter_value';
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['label'] = 'Newsletter status';
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['multiple']['group'] = 0;
  $handler->display->display_options['fields']['field_subscribed_to_newsletter_value']['multiple']['multiple_reversed'] = 0;
  /* Champ: Utilisateur : Actif */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_type'] = '0';
  $handler->display->display_options['fields']['status']['element_label_type'] = '0';
  $handler->display->display_options['fields']['status']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['status']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['status']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Champ: Rôles */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'term_node';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['tid_1']['ui_name'] = 'Rôles';
  $handler->display->display_options['fields']['tid_1']['label'] = 'Rôles';
  $handler->display->display_options['fields']['tid_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid_1']['element_type'] = '0';
  $handler->display->display_options['fields']['tid_1']['element_label_type'] = '0';
  $handler->display->display_options['fields']['tid_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['tid_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['tid_1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['tid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['tid_1']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['tid_1']['limit'] = 1;
  $handler->display->display_options['fields']['tid_1']['vids'] = array(
    14 => 14,
    1 => 0,
    7 => 0,
    10 => 0,
    4 => 0,
    11 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    3 => 0,
  );
  /* Champ: Offre */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'term_node';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['tid']['ui_name'] = 'Offre';
  $handler->display->display_options['fields']['tid']['label'] = 'Offre';
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid']['element_type'] = '0';
  $handler->display->display_options['fields']['tid']['element_label_type'] = '0';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['tid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['tid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['tid']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['tid']['limit'] = 1;
  $handler->display->display_options['fields']['tid']['vids'] = array(
    13 => 13,
    1 => 0,
    7 => 0,
    10 => 0,
    4 => 0,
    11 => 0,
    12 => 0,
    8 => 0,
    14 => 0,
    5 => 0,
    9 => 0,
    6 => 0,
    3 => 0,
  );
  /* Champ: Utilisateur : Abonnement */
  $handler->display->display_options['fields']['abo_num']['id'] = 'abo_num';
  $handler->display->display_options['fields']['abo_num']['table'] = 'users';
  $handler->display->display_options['fields']['abo_num']['field'] = 'abo_num';
  $handler->display->display_options['fields']['abo_num']['label'] = 'Numéro d’abonné';
  $handler->display->display_options['fields']['abo_num']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['external'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['abo_num']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['abo_num']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['abo_num']['alter']['html'] = 0;
  $handler->display->display_options['fields']['abo_num']['element_type'] = '0';
  $handler->display->display_options['fields']['abo_num']['element_label_type'] = '0';
  $handler->display->display_options['fields']['abo_num']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['abo_num']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['abo_num']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['abo_num']['hide_empty'] = 0;
  $handler->display->display_options['fields']['abo_num']['empty_zero'] = 0;
  $handler->display->display_options['fields']['abo_num']['hide_alter_empty'] = 1;
  /* Champ: Date d&#039;effet */
  $handler->display->display_options['fields']['field_user_dates_value']['id'] = 'field_user_dates_value';
  $handler->display->display_options['fields']['field_user_dates_value']['table'] = 'node_data_field_user_dates';
  $handler->display->display_options['fields']['field_user_dates_value']['field'] = 'field_user_dates_value';
  $handler->display->display_options['fields']['field_user_dates_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_user_dates_value']['ui_name'] = 'Date d\'effet';
  $handler->display->display_options['fields']['field_user_dates_value']['label'] = 'Date d\'effet';
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_dates_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_dates_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_dates_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_dates_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value']['label_type'] = 'custom';
  $handler->display->display_options['fields']['field_user_dates_value']['fromto']['fromto'] = 'value';
  /* Champ: Contenu : Date d&#039;effet / d&#039;échéance (field_user_dates) - Date de fin */
  $handler->display->display_options['fields']['field_user_dates_value2']['id'] = 'field_user_dates_value2';
  $handler->display->display_options['fields']['field_user_dates_value2']['table'] = 'node_data_field_user_dates';
  $handler->display->display_options['fields']['field_user_dates_value2']['field'] = 'field_user_dates_value2';
  $handler->display->display_options['fields']['field_user_dates_value2']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_user_dates_value2']['label'] = 'Date d\'échéance';
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_dates_value2']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_dates_value2']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_dates_value2']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_dates_value2']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_user_dates_value2']['label_type'] = 'custom';
  $handler->display->display_options['fields']['field_user_dates_value2']['fromto']['fromto'] = 'value2';
  /* Champ: Contenu : Code Privilège (field_user_promo) */
  $handler->display->display_options['fields']['field_user_promo_value']['id'] = 'field_user_promo_value';
  $handler->display->display_options['fields']['field_user_promo_value']['table'] = 'node_data_field_user_promo';
  $handler->display->display_options['fields']['field_user_promo_value']['field'] = 'field_user_promo_value';
  $handler->display->display_options['fields']['field_user_promo_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_user_promo_value']['label'] = 'Code Privilège';
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_user_promo_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_promo_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_promo_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_promo_value']['link_to_node'] = 0;
  /* Champ: Utilisateur : Modify free user term */
  $handler->display->display_options['fields']['modify_free']['id'] = 'modify_free';
  $handler->display->display_options['fields']['modify_free']['table'] = 'users';
  $handler->display->display_options['fields']['modify_free']['field'] = 'modify_free';
  $handler->display->display_options['fields']['modify_free']['label'] = 'Modifier la durée d’essai';
  $handler->display->display_options['fields']['modify_free']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['external'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['modify_free']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['modify_free']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['modify_free']['alter']['html'] = 0;
  $handler->display->display_options['fields']['modify_free']['element_type'] = '0';
  $handler->display->display_options['fields']['modify_free']['element_label_type'] = '0';
  $handler->display->display_options['fields']['modify_free']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['modify_free']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['modify_free']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['modify_free']['hide_empty'] = 0;
  $handler->display->display_options['fields']['modify_free']['empty_zero'] = 0;
  $handler->display->display_options['fields']['modify_free']['hide_alter_empty'] = 0;
  /* Champ: Grand compte */
  $handler->display->display_options['fields']['grand_user']['id'] = 'grand_user';
  $handler->display->display_options['fields']['grand_user']['table'] = 'users';
  $handler->display->display_options['fields']['grand_user']['field'] = 'grand_user';
  $handler->display->display_options['fields']['grand_user']['ui_name'] = 'Grand compte';
  $handler->display->display_options['fields']['grand_user']['label'] = 'Grand compte';
  $handler->display->display_options['fields']['grand_user']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['external'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['grand_user']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['grand_user']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['grand_user']['alter']['html'] = 0;
  $handler->display->display_options['fields']['grand_user']['element_type'] = '0';
  $handler->display->display_options['fields']['grand_user']['element_label_type'] = '0';
  $handler->display->display_options['fields']['grand_user']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['grand_user']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['grand_user']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['grand_user']['hide_empty'] = 0;
  $handler->display->display_options['fields']['grand_user']['empty_zero'] = 0;
  $handler->display->display_options['fields']['grand_user']['hide_alter_empty'] = 0;
  /* Champ: Batire User : Abo admin */
  $handler->display->display_options['fields']['abo_admin']['id'] = 'abo_admin';
  $handler->display->display_options['fields']['abo_admin']['table'] = 'batire_user';
  $handler->display->display_options['fields']['abo_admin']['field'] = 'abo_admin';
  $handler->display->display_options['fields']['abo_admin']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['external'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['abo_admin']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['abo_admin']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['abo_admin']['alter']['html'] = 0;
  $handler->display->display_options['fields']['abo_admin']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['abo_admin']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['abo_admin']['hide_empty'] = 0;
  $handler->display->display_options['fields']['abo_admin']['empty_zero'] = 0;
  $handler->display->display_options['fields']['abo_admin']['hide_alter_empty'] = 1;
  /* Champ: Batire GC Statistics : Access to statistics */
  $handler->display->display_options['fields']['password_1']['id'] = 'password_1';
  $handler->display->display_options['fields']['password_1']['table'] = 'batire_gc_statistics';
  $handler->display->display_options['fields']['password_1']['field'] = 'password';
  $handler->display->display_options['fields']['password_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['password_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['password_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['password_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['password_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['password_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['password_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['password_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['password_1']['hide_alter_empty'] = 1;
  /* Champ: Batire User : User products */
  $handler->display->display_options['fields']['products']['id'] = 'products';
  $handler->display->display_options['fields']['products']['table'] = 'batire_user';
  $handler->display->display_options['fields']['products']['field'] = 'products';
  $handler->display->display_options['fields']['products']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['products']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['products']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['products']['alter']['external'] = 0;
  $handler->display->display_options['fields']['products']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['products']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['products']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['products']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['products']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['products']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['products']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['products']['alter']['html'] = 0;
  $handler->display->display_options['fields']['products']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['products']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['products']['hide_empty'] = 0;
  $handler->display->display_options['fields']['products']['empty_zero'] = 0;
  $handler->display->display_options['fields']['products']['hide_alter_empty'] = 1;
  /* Champ: Contenu : Type utilisateur (field_user_origene) */
  $handler->display->display_options['fields']['field_user_origene_value']['id'] = 'field_user_origene_value';
  $handler->display->display_options['fields']['field_user_origene_value']['table'] = 'node_data_field_user_origene';
  $handler->display->display_options['fields']['field_user_origene_value']['field'] = 'field_user_origene_value';
  $handler->display->display_options['fields']['field_user_origene_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Utilisateur : Nom */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid']['value'] = array(
    0 => 0,
    1 => '1',
    2 => '4',
  );
  $handler->display->display_options['filters']['uid']['expose']['operator'] = FALSE;
  /* Filtrer: Contenu : Nom (field_user_surname) */
  $handler->display->display_options['filters']['field_user_surname_value']['id'] = 'field_user_surname_value';
  $handler->display->display_options['filters']['field_user_surname_value']['table'] = 'node_data_field_user_surname';
  $handler->display->display_options['filters']['field_user_surname_value']['field'] = 'field_user_surname_value';
  $handler->display->display_options['filters']['field_user_surname_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['field_user_surname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_surname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_surname_value']['expose']['operator'] = 'field_user_surname_value_op';
  $handler->display->display_options['filters']['field_user_surname_value']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['field_user_surname_value']['expose']['label'] = 'Nom';
  $handler->display->display_options['filters']['field_user_surname_value']['expose']['identifier'] = 'field_user_surname_value';
  $handler->display->display_options['filters']['field_user_surname_value']['expose']['optional'] = TRUE;
  $handler->display->display_options['filters']['field_user_surname_value']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['field_user_surname_value']['case'] = 1;
  /* Filtrer: Adresse électronique */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['ui_name'] = 'Adresse électronique';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'Adresse électronique';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['optional'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['mail']['case'] = 1;
  /* Filtrer: Raison sociale */
  $handler->display->display_options['filters']['field_user_company_value']['id'] = 'field_user_company_value';
  $handler->display->display_options['filters']['field_user_company_value']['table'] = 'node_data_field_user_company';
  $handler->display->display_options['filters']['field_user_company_value']['field'] = 'field_user_company_value';
  $handler->display->display_options['filters']['field_user_company_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['field_user_company_value']['ui_name'] = 'Raison sociale';
  $handler->display->display_options['filters']['field_user_company_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_company_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_company_value']['expose']['operator'] = 'field_user_company_value_op';
  $handler->display->display_options['filters']['field_user_company_value']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['field_user_company_value']['expose']['label'] = 'Raison sociale';
  $handler->display->display_options['filters']['field_user_company_value']['expose']['identifier'] = 'field_user_company_value';
  $handler->display->display_options['filters']['field_user_company_value']['expose']['optional'] = TRUE;
  $handler->display->display_options['filters']['field_user_company_value']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['field_user_company_value']['case'] = 1;
  /* Filtrer: Utilisateur : Abonnement */
  $handler->display->display_options['filters']['abo_num']['id'] = 'abo_num';
  $handler->display->display_options['filters']['abo_num']['table'] = 'users';
  $handler->display->display_options['filters']['abo_num']['field'] = 'abo_num';
  $handler->display->display_options['filters']['abo_num']['exposed'] = TRUE;
  $handler->display->display_options['filters']['abo_num']['expose']['operator'] = 'abo_num_op';
  $handler->display->display_options['filters']['abo_num']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['abo_num']['expose']['label'] = 'Numéro d’abonné';
  $handler->display->display_options['filters']['abo_num']['expose']['identifier'] = 'abo_num';
  $handler->display->display_options['filters']['abo_num']['expose']['single'] = TRUE;
  /* Filtrer: Type d’abonnement */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'term_node';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['tid']['ui_name'] = 'Type d’abonnement';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Type d’abonnement';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vid'] = '13';
  $handler->display->display_options['filters']['tid']['error_message'] = 0;
  /* Filtrer: From */
  $handler->display->display_options['filters']['field_user_dates_value']['id'] = 'field_user_dates_value';
  $handler->display->display_options['filters']['field_user_dates_value']['table'] = 'node_data_field_user_dates';
  $handler->display->display_options['filters']['field_user_dates_value']['field'] = 'field_user_dates_value';
  $handler->display->display_options['filters']['field_user_dates_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['field_user_dates_value']['ui_name'] = 'From';
  $handler->display->display_options['filters']['field_user_dates_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_user_dates_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_dates_value']['expose']['operator'] = 'field_user_dates_value_op';
  $handler->display->display_options['filters']['field_user_dates_value']['expose']['limit_operators'] = 0;
  $handler->display->display_options['filters']['field_user_dates_value']['expose']['label'] = 'Date d\'effet';
  $handler->display->display_options['filters']['field_user_dates_value']['expose']['use_operator'] = 1;
  $handler->display->display_options['filters']['field_user_dates_value']['expose']['identifier'] = 'field_user_dates_value';
  $handler->display->display_options['filters']['field_user_dates_value']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['field_user_dates_value']['allow_null'] = 1;
  $handler->display->display_options['filters']['field_user_dates_value']['date_fields'] = array(
    'node_data_field_user_dates.field_user_dates_value' => 'node_data_field_user_dates.field_user_dates_value',
  );
  $handler->display->display_options['filters']['field_user_dates_value']['date_method'] = 'AND';
  $handler->display->display_options['filters']['field_user_dates_value']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_user_dates_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_user_dates_value']['default_date'] = '';
  $handler->display->display_options['filters']['field_user_dates_value']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_user_dates_value']['year_range'] = '-3:+3';
  /* Filtrer: To */
  $handler->display->display_options['filters']['field_user_dates_value2']['id'] = 'field_user_dates_value2';
  $handler->display->display_options['filters']['field_user_dates_value2']['table'] = 'node_data_field_user_dates';
  $handler->display->display_options['filters']['field_user_dates_value2']['field'] = 'field_user_dates_value2';
  $handler->display->display_options['filters']['field_user_dates_value2']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['field_user_dates_value2']['ui_name'] = 'To';
  $handler->display->display_options['filters']['field_user_dates_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_user_dates_value2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_dates_value2']['expose']['operator'] = 'field_user_dates_value2_op';
  $handler->display->display_options['filters']['field_user_dates_value2']['expose']['limit_operators'] = 0;
  $handler->display->display_options['filters']['field_user_dates_value2']['expose']['label'] = 'Date d\'échéance';
  $handler->display->display_options['filters']['field_user_dates_value2']['expose']['use_operator'] = 1;
  $handler->display->display_options['filters']['field_user_dates_value2']['expose']['identifier'] = 'field_user_dates_value2';
  $handler->display->display_options['filters']['field_user_dates_value2']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['field_user_dates_value2']['allow_null'] = 1;
  $handler->display->display_options['filters']['field_user_dates_value2']['date_fields'] = array(
    'node_data_field_user_dates.field_user_dates_value2' => 'node_data_field_user_dates.field_user_dates_value2',
  );
  $handler->display->display_options['filters']['field_user_dates_value2']['date_method'] = 'AND';
  $handler->display->display_options['filters']['field_user_dates_value2']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_user_dates_value2']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_user_dates_value2']['default_date'] = '';
  $handler->display->display_options['filters']['field_user_dates_value2']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_user_dates_value2']['year_range'] = '-3:+3';
  /* Filtrer: Rôle */
  $handler->display->display_options['filters']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['table'] = 'term_node';
  $handler->display->display_options['filters']['tid_1']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_1']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['tid_1']['ui_name'] = 'Rôle';
  $handler->display->display_options['filters']['tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['tid_1']['expose']['label'] = 'Rôle';
  $handler->display->display_options['filters']['tid_1']['expose']['identifier'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['tid_1']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['tid_1']['vid'] = '14';
  $handler->display->display_options['filters']['tid_1']['error_message'] = 0;
  /* Filtrer: Utilisateur : SVC Login */
  $handler->display->display_options['filters']['svc_login']['id'] = 'svc_login';
  $handler->display->display_options['filters']['svc_login']['table'] = 'users';
  $handler->display->display_options['filters']['svc_login']['field'] = 'svc_login';
  $handler->display->display_options['filters']['svc_login']['exposed'] = TRUE;
  $handler->display->display_options['filters']['svc_login']['expose']['operator'] = 'svc_login_op';
  $handler->display->display_options['filters']['svc_login']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['svc_login']['expose']['label'] = 'SVC Login';
  $handler->display->display_options['filters']['svc_login']['expose']['identifier'] = 'svc_login';
  $handler->display->display_options['filters']['svc_login']['expose']['single'] = TRUE;
  /* Filtrer: Contenu : Subscribed to newsletter (field_subscribed_to_newsletter) - Valeurs autorisées */
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['id'] = 'field_subscribed_to_newsletter_value_many_to_one';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['table'] = 'node_data_field_subscribed_to_newsletter';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['field'] = 'field_subscribed_to_newsletter_value_many_to_one';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['expose']['operator'] = 'field_subscribed_to_newsletter_value_many_to_one_op';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['expose']['label'] = 'Subscribed to newsletter';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['expose']['identifier'] = 'field_subscribed_to_newsletter_value_many_to_one';
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_subscribed_to_newsletter_value_many_to_one']['reduce_duplicates'] = 0;
  /* Filtrer: Contenu : Type utilisateur (field_user_origene) */
  $handler->display->display_options['filters']['field_user_origene_value']['id'] = 'field_user_origene_value';
  $handler->display->display_options['filters']['field_user_origene_value']['table'] = 'node_data_field_user_origene';
  $handler->display->display_options['filters']['field_user_origene_value']['field'] = 'field_user_origene_value';
  $handler->display->display_options['filters']['field_user_origene_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['filters']['field_user_origene_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_origene_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_origene_value']['expose']['operator'] = 'field_user_origene_value_op';
  $handler->display->display_options['filters']['field_user_origene_value']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['field_user_origene_value']['expose']['label'] = 'Type utilisateur';
  $handler->display->display_options['filters']['field_user_origene_value']['expose']['identifier'] = 'field_user_origene_value';
  $handler->display->display_options['filters']['field_user_origene_value']['expose']['optional'] = TRUE;
  $handler->display->display_options['filters']['field_user_origene_value']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['field_user_origene_value']['case'] = 1;
  $handler->display->display_options['path'] = 'admin/batire-site/users';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Utilisateurs';
  $handler->display->display_options['menu']['description'] = 'Afficher/Trier/Filtrer les utilisateurs';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['batire_admin_users'] = array(
    t('Default'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('Contenu de profil'),
    t('Nom'),
    t('Prénom'),
    t('Adresse électronique'),
    t('Dernier accès'),
    t('Login Drupal'),
    t('Login SVC'),
    t('User password'),
    t('Newsletter status'),
    t('Actif'),
    t('Rôles'),
    t('Offre'),
    t('Numéro d’abonné'),
    t('Date d\'effet'),
    t('Date d\'échéance'),
    t('Code Privilège'),
    t('Modifier la durée d’essai'),
    t('Grand compte'),
    t('Abo admin'),
    t('Access to statistics'),
    t('User products'),
    t('Raison sociale'),
    t('Type d’abonnement'),
    t('Rôle'),
    t('SVC Login'),
    t('Subscribed to newsletter'),
    t('Page'),
    t('Type utilisateur'),
  );

  $views[$view->name] = $view;

  // Exported view: batire_faq_management
  $view = new view;
  $view->name = 'batire_faq_management';
  $view->description = 'FAQ management';
  $view->tag = 'Batire';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'FAQ list';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => 4,
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'bulk';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'status' => 'status',
    'changed' => 'changed',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['style_options']['execution_type'] = '2';
  $handler->display->display_options['style_options']['display_type'] = '0';
  $handler->display->display_options['style_options']['display_result'] = 1;
  $handler->display->display_options['style_options']['merge_single_action'] = 1;
  /* Champ: Nœud : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Champ: Nœud : Publié */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Champ: Nœud : Date de mise à jour */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  /* Champ: Nœud : Lien de modification */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Modifier';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  /* Critère de tri: Nœud : Date de publication */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Publié';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember'] = 1;
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faq' => 'faq',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['type']['expose']['single'] = 0;
  $handler->display->display_options['filters']['type']['expose']['reduce'] = 0;
  /* Filtrer: Taxonomie : Terme */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Categorie';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['optional'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['name']['case'] = 1;
  /* Filtrer: Taxonomie : Vocabulaire */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/batire-site/manage/faq/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'FAQ list';
  $handler->display->display_options['menu']['description'] = 'View, edit, and delete your faq content.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['batire_faq_management'] = array(
    t('Defaults'),
    t('FAQ list'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('Titre'),
    t('Publié'),
    t('Date de mise à jour'),
    t('Modifier'),
    t('Type'),
    t('Categorie'),
    t('Page'),
  );

  $views[$view->name] = $view;

  // Exported view: batire_homebage_blocks
  $view = new view;
  $view->name = 'batire_homebage_blocks';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'Batire homepage blocks';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Champ: Nœud : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Champ: Contenu : Contenu (field_content) */
  $handler->display->display_options['fields']['field_content_value']['id'] = 'field_content_value';
  $handler->display->display_options['fields']['field_content_value']['table'] = 'node_data_field_content';
  $handler->display->display_options['fields']['field_content_value']['field'] = 'field_content_value';
  $handler->display->display_options['fields']['field_content_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_content_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_content_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_content_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_content_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_content_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_content_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_content_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_content_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_content_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_content_value']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_content_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_content_value']['label_type'] = 'none';
  /* Champ: Contenu : Image (field_image) */
  $handler->display->display_options['fields']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['table'] = 'node_data_field_image';
  $handler->display->display_options['fields']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image_fid']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_image_fid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_image_fid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_image_fid']['format'] = 'batire_hp_block_img_default';
  /* Champ: Contenu : Lien (field_hp_link) */
  $handler->display->display_options['fields']['field_hp_link_url']['id'] = 'field_hp_link_url';
  $handler->display->display_options['fields']['field_hp_link_url']['table'] = 'node_data_field_hp_link';
  $handler->display->display_options['fields']['field_hp_link_url']['field'] = 'field_hp_link_url';
  $handler->display->display_options['fields']['field_hp_link_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_hp_link_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_hp_link_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['element_type'] = '0';
  $handler->display->display_options['fields']['field_hp_link_url']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_hp_link_url']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_hp_link_url']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_hp_link_url']['format'] = 'plain';
  /* Champ: Contenu : Lien (field_hp_link) */
  $handler->display->display_options['fields']['field_hp_link_url_1']['id'] = 'field_hp_link_url_1';
  $handler->display->display_options['fields']['field_hp_link_url_1']['table'] = 'node_data_field_hp_link';
  $handler->display->display_options['fields']['field_hp_link_url_1']['field'] = 'field_hp_link_url';
  $handler->display->display_options['fields']['field_hp_link_url_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_hp_link_url_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_hp_link_url_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['element_type'] = '0';
  $handler->display->display_options['fields']['field_hp_link_url_1']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_hp_link_url_1']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_hp_link_url_1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_hp_link_url_1']['label_type'] = 'none';
  /* Champ: Nœud : Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Critère de tri: Nœud : Date de mise à jour */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_homepage_blocks' => 'batire_homepage_blocks',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'Voir les volets';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'bulk';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'status' => 'status',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['style_options']['operations'] = array(
    'views_bulk_operations_delete_node_action' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
    'node_mass_update-9c585624b9b3af0b4687d5f97f35e047' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
    'node_mass_update-0ccad85c1ebe4c9ceada1aa64293b080' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
  );
  $handler->display->display_options['style_options']['execution_type'] = '1';
  $handler->display->display_options['style_options']['display_type'] = '0';
  $handler->display->display_options['style_options']['display_result'] = 1;
  $handler->display->display_options['style_options']['merge_single_action'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Nœud : Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Champ: Nœud : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Champ: Nœud : Publié */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Champ: Nœud : Lien de modification */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Modifier';
  /* Champ: Nœud : Lien de suppression */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['delete_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delete_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Supprimer';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_homepage_blocks' => 'batire_homepage_blocks',
  );
  $handler->display->display_options['path'] = 'admin/batire-site/settings/content-settings/sites_moniteur';
  $translatables['batire_homebage_blocks'] = array(
    t('Defaults'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Titre'),
    t('Nid'),
    t('Content pane'),
    t('Voir les volets'),
    t('Page'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('Publié'),
    t('Lien de modification'),
    t('Modifier'),
    t('Lien de suppression'),
    t('Supprimer'),
  );

  $views[$view->name] = $view;

  // Exported view: batire_last_docs_view
  $view = new view;
  $view->name = 'batire_last_docs_view';
  $view->description = '';
  $view->tag = 'Batire';
  $view->base_table = 'node';
  $view->human_name = 'Veille réglementaire et normative';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Champ: Nœud : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Champ: Contenu : Contenu (field_content) */
  $handler->display->display_options['fields']['field_content_value']['id'] = 'field_content_value';
  $handler->display->display_options['fields']['field_content_value']['table'] = 'node_data_field_content';
  $handler->display->display_options['fields']['field_content_value']['field'] = 'field_content_value';
  $handler->display->display_options['fields']['field_content_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_content_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_content_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_content_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_content_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_content_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_content_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_content_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_content_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_content_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_content_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_content_value']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_content_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_content_value']['label_type'] = 'none';
  /* Champ: Contenu : Date (field_veille_date) */
  $handler->display->display_options['fields']['field_veille_date_value']['id'] = 'field_veille_date_value';
  $handler->display->display_options['fields']['field_veille_date_value']['table'] = 'node_data_field_veille_date';
  $handler->display->display_options['fields']['field_veille_date_value']['field'] = 'field_veille_date_value';
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_veille_date_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_veille_date_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_veille_date_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_veille_date_value']['format'] = 'lemoniteur_date';
  /* Champ: Contenu : Document (field_veille_document) */
  $handler->display->display_options['fields']['field_veille_document_url']['id'] = 'field_veille_document_url';
  $handler->display->display_options['fields']['field_veille_document_url']['table'] = 'node_data_field_veille_document';
  $handler->display->display_options['fields']['field_veille_document_url']['field'] = 'field_veille_document_url';
  $handler->display->display_options['fields']['field_veille_document_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_veille_document_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_veille_document_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['element_type'] = '0';
  $handler->display->display_options['fields']['field_veille_document_url']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_veille_document_url']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_veille_document_url']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_veille_document_url']['label_type'] = 'none';
  /* Champ: Taxonomie : Terme */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  /* Champ: Contenu : Afficher pour les non-abonnés (field_show_to_anon) */
  $handler->display->display_options['fields']['field_show_to_anon_value']['id'] = 'field_show_to_anon_value';
  $handler->display->display_options['fields']['field_show_to_anon_value']['table'] = 'node_data_field_show_to_anon';
  $handler->display->display_options['fields']['field_show_to_anon_value']['field'] = 'field_show_to_anon_value';
  /* Champ: Contenu : Date (field_veille_date) */
  $handler->display->display_options['fields']['field_veille_date_value_1']['id'] = 'field_veille_date_value_1';
  $handler->display->display_options['fields']['field_veille_date_value_1']['table'] = 'node_data_field_veille_date';
  $handler->display->display_options['fields']['field_veille_date_value_1']['field'] = 'field_veille_date_value';
  /* Critère de tri: Nœud : Date de publication */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_last_documents' => 'batire_last_documents',
  );
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Date de mise à jour */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = '>=';
  $handler->display->display_options['filters']['changed']['value']['value'] = '-6 months';
  $handler->display->display_options['filters']['changed']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['changed']['allow_null'] = 1;

  /* Display: Batire last docs anonymous */
  $handler = $view->new_display('panel_pane', 'Batire last docs anonymous', 'panel_pane_1');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Contenu : Afficher pour les non-abonnés (field_show_to_anon) */
  $handler->display->display_options['filters']['field_show_to_anon_value']['id'] = 'field_show_to_anon_value';
  $handler->display->display_options['filters']['field_show_to_anon_value']['table'] = 'node_data_field_show_to_anon';
  $handler->display->display_options['filters']['field_show_to_anon_value']['field'] = 'field_show_to_anon_value';
  $handler->display->display_options['filters']['field_show_to_anon_value']['value']['value'] = '1';
  $handler->display->display_options['filters']['field_show_to_anon_value']['allow_null'] = 1;
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_last_documents' => 'batire_last_documents',
  );
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Date de mise à jour */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = '>=';
  $handler->display->display_options['filters']['changed']['value']['value'] = '-6 months';
  $handler->display->display_options['filters']['changed']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['changed']['allow_null'] = 1;
  $handler->display->display_options['pane_category']['name'] = 'Voir les volets';

  /* Display: Batire last docs authorized */
  $handler = $view->new_display('panel_pane', 'Batire last docs authorized', 'panel_pane_2');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => 2,
  );
  $handler->display->display_options['pane_category']['name'] = 'Voir les volets';

  /* Display: Batire last docs page anonymous */
  $handler = $view->new_display('block', 'Batire last docs page anonymous', 'block_1');
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time_get';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full_limit';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'items_per_page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10,30,50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '';
  $handler->display->display_options['pager']['options']['expose']['offset'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'offset';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_limit_to'] = '50';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Contenu : Afficher pour les non-abonnés (field_show_to_anon) */
  $handler->display->display_options['filters']['field_show_to_anon_value']['id'] = 'field_show_to_anon_value';
  $handler->display->display_options['filters']['field_show_to_anon_value']['table'] = 'node_data_field_show_to_anon';
  $handler->display->display_options['filters']['field_show_to_anon_value']['field'] = 'field_show_to_anon_value';
  $handler->display->display_options['filters']['field_show_to_anon_value']['value']['value'] = '1';
  $handler->display->display_options['filters']['field_show_to_anon_value']['allow_null'] = 1;
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_last_documents' => 'batire_last_documents',
  );
  /* Filtrer: Nœud : Date de mise à jour */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = '>=';
  $handler->display->display_options['filters']['changed']['value']['value'] = '-6 months';
  $handler->display->display_options['filters']['changed']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['changed']['allow_null'] = 1;

  /* Display: Batire last docs page authorized */
  $handler = $view->new_display('block', 'Batire last docs page authorized', 'block_2');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => 2,
  );
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time_get';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full_limit';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'items_per_page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10,30,50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '';
  $handler->display->display_options['pager']['options']['expose']['offset'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_limit_to'] = '50';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'bulk';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_veille_date_value' => 'field_veille_date_value',
    'name' => 'name',
    'title' => 'title',
    'field_show_to_anon_value' => 'field_show_to_anon_value',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_veille_date_value' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'field_show_to_anon_value' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['style_options']['operations'] = array(
    'views_bulk_operations_delete_node_action' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
    'node_mass_update-9c585624b9b3af0b4687d5f97f35e047' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
    'node_mass_update-0ccad85c1ebe4c9ceada1aa64293b080' => array(
      'selected' => TRUE,
      'skip_confirmation' => 0,
    ),
  );
  $handler->display->display_options['style_options']['execution_type'] = '1';
  $handler->display->display_options['style_options']['display_type'] = '0';
  $handler->display->display_options['style_options']['display_result'] = 1;
  $handler->display->display_options['style_options']['merge_single_action'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu : Date (field_veille_date) */
  $handler->display->display_options['fields']['field_veille_date_value']['id'] = 'field_veille_date_value';
  $handler->display->display_options['fields']['field_veille_date_value']['table'] = 'node_data_field_veille_date';
  $handler->display->display_options['fields']['field_veille_date_value']['field'] = 'field_veille_date_value';
  $handler->display->display_options['fields']['field_veille_date_value']['label'] = 'Date';
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['element_label_class'] = 'Date';
  $handler->display->display_options['fields']['field_veille_date_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_veille_date_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_veille_date_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_veille_date_value']['format'] = 'lemoniteur_date';
  /* Champ: Taxonomie : Terme */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Thématique';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = 0;
  $handler->display->display_options['fields']['name']['convert_spaces'] = 0;
  /* Champ: Nœud : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Champ: Contenu : Afficher pour les non-abonnés (field_show_to_anon) */
  $handler->display->display_options['fields']['field_show_to_anon_value']['id'] = 'field_show_to_anon_value';
  $handler->display->display_options['fields']['field_show_to_anon_value']['table'] = 'node_data_field_show_to_anon';
  $handler->display->display_options['fields']['field_show_to_anon_value']['field'] = 'field_show_to_anon_value';
  $handler->display->display_options['fields']['field_show_to_anon_value']['label'] = 'Réservé aux abonnés';
  $handler->display->display_options['fields']['field_show_to_anon_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_show_to_anon_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_show_to_anon_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_show_to_anon_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_show_to_anon_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_show_to_anon_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_show_to_anon_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_show_to_anon_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_show_to_anon_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_show_to_anon_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_show_to_anon_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_show_to_anon_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_show_to_anon_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_show_to_anon_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_show_to_anon_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_show_to_anon_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_show_to_anon_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_show_to_anon_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_show_to_anon_value']['label_type'] = 'custom';
  $handler->display->display_options['fields']['field_show_to_anon_value']['multiple']['group'] = 0;
  $handler->display->display_options['fields']['field_show_to_anon_value']['multiple']['multiple_reversed'] = 0;
  /* Champ: Nœud : Lien de modification */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Modifier';
  /* Champ: Nœud : Lien de suppression */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['delete_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['delete_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['delete_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['delete_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['delete_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['delete_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['delete_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['delete_node']['text'] = 'Supprimer';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_last_documents' => 'batire_last_documents',
  );
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Date de mise à jour */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'node';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = '>=';
  $handler->display->display_options['filters']['changed']['value']['value'] = '-6 months';
  $handler->display->display_options['filters']['changed']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['changed']['allow_null'] = 1;
  /* Filtrer: Contenu : Date (field_veille_date) */
  $handler->display->display_options['filters']['field_veille_date_value']['id'] = 'field_veille_date_value';
  $handler->display->display_options['filters']['field_veille_date_value']['table'] = 'node_data_field_veille_date';
  $handler->display->display_options['filters']['field_veille_date_value']['field'] = 'field_veille_date_value';
  $handler->display->display_options['filters']['field_veille_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_veille_date_value']['expose']['operator'] = 'field_veille_date_value_op';
  $handler->display->display_options['filters']['field_veille_date_value']['expose']['limit_operators'] = 0;
  $handler->display->display_options['filters']['field_veille_date_value']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['field_veille_date_value']['expose']['use_operator'] = 1;
  $handler->display->display_options['filters']['field_veille_date_value']['expose']['identifier'] = 'field_veille_date_value';
  $handler->display->display_options['filters']['field_veille_date_value']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['field_veille_date_value']['allow_null'] = 1;
  $handler->display->display_options['filters']['field_veille_date_value']['date_fields'] = array(
    'node_data_field_veille_date.field_veille_date_value' => 'node_data_field_veille_date.field_veille_date_value',
  );
  $handler->display->display_options['filters']['field_veille_date_value']['date_method'] = 'OR';
  $handler->display->display_options['filters']['field_veille_date_value']['granularity'] = 'day';
  $handler->display->display_options['filters']['field_veille_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_veille_date_value']['default_date'] = '';
  $handler->display->display_options['filters']['field_veille_date_value']['default_to_date'] = '';
  $handler->display->display_options['filters']['field_veille_date_value']['year_range'] = '-3:+3';
  $handler->display->display_options['path'] = 'admin/batire-site/settings/content-settings/info_veille/list_infos_veilles';
  $translatables['batire_last_docs_view'] = array(
    t('Defaults'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Titre'),
    t('Terme'),
    t('Batire last docs anonymous'),
    t('Voir les volets'),
    t('Batire last docs authorized'),
    t('Batire last docs page anonymous'),
    t('items_per_page'),
    t('offset'),
    t('Batire last docs page authorized'),
    t('Décalage'),
    t('Page'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Date'),
    t('Thématique'),
    t('Réservé aux abonnés'),
    t('Lien de modification'),
    t('Modifier'),
    t('Lien de suppression'),
    t('Supprimer'),
  );

  $views[$view->name] = $view;

  // Exported view: batire_lemoniteur_view
  $view = new view;
  $view->name = 'batire_lemoniteur_view';
  $view->description = '';
  $view->tag = 'Batire';
  $view->base_table = 'node';
  $view->human_name = 'Batire LeMoniteur view';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Champ: Nœud : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Champ: Contenu : Date (field_lemoniteur_date) */
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['id'] = 'field_lemoniteur_date_value';
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['table'] = 'node_data_field_lemoniteur_date';
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['field'] = 'field_lemoniteur_date_value';
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_lemoniteur_date_value']['format'] = 'lemoniteur_date';
  /* Champ: Contenu : Lien (field_lemoniteur_link) */
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['id'] = 'field_lemoniteur_link_value';
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['table'] = 'node_data_field_lemoniteur_link';
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['field'] = 'field_lemoniteur_link_value';
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_link_value']['label_type'] = 'none';
  /* Champ: Contenu : Image (field_lemoniteur_image) */
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['id'] = 'field_lemoniteur_image_fid';
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['table'] = 'node_data_field_lemoniteur_image';
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['field'] = 'field_lemoniteur_image_fid';
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['element_type'] = '0';
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_lemoniteur_image_fid']['format'] = 'batire_lemoniteur_img_default';
  /* Critère de tri: Contenu : Date (field_lemoniteur_date) */
  $handler->display->display_options['sorts']['field_lemoniteur_date_value']['id'] = 'field_lemoniteur_date_value';
  $handler->display->display_options['sorts']['field_lemoniteur_date_value']['table'] = 'node_data_field_lemoniteur_date';
  $handler->display->display_options['sorts']['field_lemoniteur_date_value']['field'] = 'field_lemoniteur_date_value';
  $handler->display->display_options['sorts']['field_lemoniteur_date_value']['order'] = 'DESC';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_from_lemoniteur' => 'batire_from_lemoniteur',
  );
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Lemoniteur main pane */
  $handler = $view->new_display('panel_pane', 'Lemoniteur main pane', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'Voir les volets';
  $translatables['batire_lemoniteur_view'] = array(
    t('Defaults'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Titre'),
    t('Lemoniteur main pane'),
    t('Voir les volets'),
  );

  $views[$view->name] = $view;

  // Exported view: batire_list_page_titles
  $view = new view;
  $view->name = 'batire_list_page_titles';
  $view->description = 'List all Nodes with their Page Titles';
  $view->tag = 'Batire';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Page Title List';
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer page titles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'page_title' => 'page_title',
    'edit_node' => 'edit_node',
    'view_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'nid';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'title' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'page_title' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'edit_node' => array(
      'separator' => ' | ',
    ),
    'view_node' => array(
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Entête: Global : Zone de texte */
  $handler->display->display_options['header']['text']['id'] = 'area';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['label'] = '';
  $handler->display->display_options['header']['text']['empty'] = FALSE;
  $handler->display->display_options['header']['text']['content'] = 'Listed below are all the nodes on the site with their Page Title (if set).';
  $handler->display->display_options['header']['text']['format'] = '1';
  /* Texte de page vide: Global : Zone de texte */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['label'] = '';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = 'There is no content to list';
  $handler->display->display_options['empty']['text']['format'] = '1';
  /* Champ: Nœud : Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Champ: Nœud : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Champ: Page Title : Titre */
  $handler->display->display_options['fields']['page_title']['id'] = 'page_title';
  $handler->display->display_options['fields']['page_title']['table'] = 'page_title';
  $handler->display->display_options['fields']['page_title']['field'] = 'page_title';
  $handler->display->display_options['fields']['page_title']['label'] = 'Page Title';
  $handler->display->display_options['fields']['page_title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['page_title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['page_title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['page_title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['page_title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['page_title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['page_title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['page_title']['empty'] = '<em>&ndash; none &ndash;</em>';
  $handler->display->display_options['fields']['page_title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['page_title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['page_title']['link_to_node'] = 0;
  $handler->display->display_options['fields']['page_title']['use_node_title'] = 0;
  /* Champ: Nœud : Lien de modification */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Modifier';
  /* Champ: Nœud : Lien */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['text'] = 'Voir';
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Publié';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Node Type';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['single'] = 0;
  $handler->display->display_options['filters']['type']['expose']['reduce'] = 0;
  /* Filtrer: Page Title : Titre */
  $handler->display->display_options['filters']['page_title']['id'] = 'page_title';
  $handler->display->display_options['filters']['page_title']['table'] = 'page_title';
  $handler->display->display_options['filters']['page_title']['field'] = 'page_title';
  $handler->display->display_options['filters']['page_title']['operator'] = 'contains';
  $handler->display->display_options['filters']['page_title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['page_title']['expose']['operator'] = 'page_title_op';
  $handler->display->display_options['filters']['page_title']['expose']['label'] = 'Page Title';
  $handler->display->display_options['filters']['page_title']['expose']['use_operator'] = 1;
  $handler->display->display_options['filters']['page_title']['expose']['identifier'] = 'page_title';
  $handler->display->display_options['filters']['page_title']['expose']['optional'] = 1;
  $handler->display->display_options['filters']['page_title']['case'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/reports/page-title';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Page Title List';
  $handler->display->display_options['menu']['description'] = 'List all nodes with their Page Titles';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'navigation';
  $translatables['batire_list_page_titles'] = array(
    t('Defaults'),
    t('Page Title List'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('Listed below are all the nodes on the site with their Page Title (if set).'),
    t('There is no content to list'),
    t('Nid'),
    t('Titre'),
    t('Page Title'),
    t('<em>&ndash; none &ndash;</em>'),
    t('Actions'),
    t('Modifier'),
    t('Voir'),
    t('Publié'),
    t('Node Type'),
    t('Page'),
  );

  $views[$view->name] = $view;

  // Exported view: batire_mon_compte
  $view = new view;
  $view->name = 'batire_mon_compte';
  $view->description = 'Batire mon compte';
  $view->tag = 'Batire';
  $view->base_table = 'node';
  $view->human_name = 'Batire mon compte';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user docs';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Relation: Nœud : Referrers */
  $handler->display->display_options['relationships']['nodereferer_referers']['id'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['table'] = 'node';
  $handler->display->display_options['relationships']['nodereferer_referers']['field'] = 'nodereferer_referers';
  /* Critère de tri: Nœud : Titre */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Critère de tri: Nœud : Date de mise à jour */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  /* Argument: Nœud : Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  /* Argument: Nœud : Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Utilisateur : Actuel */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';

  /* Display: Mes documents */
  $handler = $view->new_display('panel_pane', 'Mes documents', 'my_documents');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mes documents';
  $handler->display->display_options['display_description'] = 'Mes documents';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['build_mode'] = 'document';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nœud : Referrers */
  $handler->display->display_options['relationships']['nodereferer_referers']['id'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['table'] = 'node';
  $handler->display->display_options['relationships']['nodereferer_referers']['field'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['label'] = 'Field folder documents';
  $handler->display->display_options['relationships']['nodereferer_referers']['required'] = 0;
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_delta'] = '-1';
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_field'] = 'field_folder_documents';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Critère de tri: Batire User Docs : Date vide */
  $handler->display->display_options['sorts']['date_empty']['id'] = 'date_empty';
  $handler->display->display_options['sorts']['date_empty']['table'] = 'batire_user_docs';
  $handler->display->display_options['sorts']['date_empty']['field'] = 'date_empty';
  /* Critère de tri: Batire User Docs : Date d'enregistrement */
  $handler->display->display_options['sorts']['date_added']['id'] = 'date_added';
  $handler->display->display_options['sorts']['date_added']['table'] = 'batire_user_docs';
  $handler->display->display_options['sorts']['date_added']['field'] = 'date_added';
  $handler->display->display_options['sorts']['date_added']['group_type'] = 'max';
  $handler->display->display_options['sorts']['date_added']['order'] = 'DESC';
  $handler->display->display_options['sorts']['date_added']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['date_added']['expose']['label'] = 'Date d\'enregistrement';
  /* Critère de tri: Nœud : Date de mise à jour */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Date de mise à jour';
  $handler->display->display_options['sorts']['changed']['granularity'] = 'day';
  /* Critère de tri: Nœud : Titre */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Nœud : Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['default_argument_skip_url'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_actualite' => 'batire_actualite',
    'batire_feuillet_mobile' => 'batire_feuillet_mobile',
    'batire_codes' => 'batire_codes',
    'batire_complement_technique' => 'batire_complement_technique',
    'batire_livres' => 'batire_livres',
    'batire_texte_normatifs' => 'batire_texte_normatifs',
    'batire_texte_officiel' => 'batire_texte_officiel',
  );
  /* Filtrer: Utilisateur : Actuel */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['pane_category']['name'] = 'Voir les volets';

  /* Display: Mes dossiers */
  $handler = $view->new_display('panel_pane', 'Mes dossiers', 'my_folders');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mes dossiers';
  $handler->display->display_options['display_description'] = 'Mes dossiers';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['build_mode'] = 'document';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nœud : Referrers */
  $handler->display->display_options['relationships']['nodereferer_referers']['id'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['table'] = 'node';
  $handler->display->display_options['relationships']['nodereferer_referers']['field'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['required'] = 0;
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_delta'] = '-1';
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_field'] = 'field_folder_documents';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Critère de tri: Batire User Docs : Date vide */
  $handler->display->display_options['sorts']['date_empty']['id'] = 'date_empty';
  $handler->display->display_options['sorts']['date_empty']['table'] = 'batire_user_docs';
  $handler->display->display_options['sorts']['date_empty']['field'] = 'date_empty';
  /* Critère de tri: Batire User Docs : Date d'enregistrement */
  $handler->display->display_options['sorts']['date_added']['id'] = 'date_added';
  $handler->display->display_options['sorts']['date_added']['table'] = 'batire_user_docs';
  $handler->display->display_options['sorts']['date_added']['field'] = 'date_added';
  $handler->display->display_options['sorts']['date_added']['order'] = 'DESC';
  $handler->display->display_options['sorts']['date_added']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['date_added']['expose']['label'] = 'Batire User Docs: Date d\'enregistrement';
  /* Critère de tri: Nœud : Date de mise à jour */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Node: Updated date';
  $handler->display->display_options['sorts']['changed']['granularity'] = 'day';
  /* Critère de tri: Nœud : Titre */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Nœud : Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Argument: Nœud : Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['default_argument_skip_url'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_actualite' => 'batire_actualite',
    'batire_feuillet_mobile' => 'batire_feuillet_mobile',
    'batire_codes' => 'batire_codes',
    'batire_complement_technique' => 'batire_complement_technique',
    'batire_livres' => 'batire_livres',
    'batire_texte_normatifs' => 'batire_texte_normatifs',
    'batire_texte_officiel' => 'batire_texte_officiel',
  );
  /* Filtrer: Utilisateur : Actuel */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['pane_category']['name'] = 'Voir les volets';

  /* Display: Mes annotations */
  $handler = $view->new_display('panel_pane', 'Mes annotations', 'my_annotations');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mes documents';
  $handler->display->display_options['display_description'] = 'Mes documents';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['build_mode'] = 'annotation';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nœud : Referrers */
  $handler->display->display_options['relationships']['nodereferer_referers']['id'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['table'] = 'node';
  $handler->display->display_options['relationships']['nodereferer_referers']['field'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['label'] = 'Field annotation doc';
  $handler->display->display_options['relationships']['nodereferer_referers']['required'] = 1;
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_delta'] = '-1';
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_field'] = 'field_annotation_doc';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Critère de tri: Nœud : Date de publication */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['sorts']['created']['group_type'] = 'max';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'MAX(Node: Post date)';
  /* Critère de tri: Nœud : Date de mise à jour */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['sorts']['changed']['group_type'] = 'max';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Node: Updated date';
  $handler->display->display_options['sorts']['changed']['granularity'] = 'day';
  /* Critère de tri: Nœud : Titre */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Nœud : Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['default_argument_skip_url'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_actualite' => 'batire_actualite',
    'batire_feuillet_mobile' => 'batire_feuillet_mobile',
    'batire_codes' => 'batire_codes',
    'batire_complement_technique' => 'batire_complement_technique',
    'batire_livres' => 'batire_livres',
    'batire_texte_normatifs' => 'batire_texte_normatifs',
    'batire_texte_officiel' => 'batire_texte_officiel',
  );
  /* Filtrer: Utilisateur : Actuel */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['pane_category']['name'] = 'Voir les volets';

  /* Display: Dossiers partagés */
  $handler = $view->new_display('panel_pane', 'Dossiers partagés', 'shared_folders');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Dossiers partagés';
  $handler->display->display_options['display_description'] = 'Dossiers partagés';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 0;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['build_mode'] = 'shared_document';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nœud : Referrers */
  $handler->display->display_options['relationships']['nodereferer_referers']['id'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['table'] = 'node';
  $handler->display->display_options['relationships']['nodereferer_referers']['field'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['required'] = 0;
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_delta'] = '-1';
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_field'] = 'field_folder_documents';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Critère de tri: Batire User Docs : Date vide */
  $handler->display->display_options['sorts']['date_empty']['id'] = 'date_empty';
  $handler->display->display_options['sorts']['date_empty']['table'] = 'batire_user_docs';
  $handler->display->display_options['sorts']['date_empty']['field'] = 'date_empty';
  /* Critère de tri: Batire User Docs : Date d'enregistrement */
  $handler->display->display_options['sorts']['date_added']['id'] = 'date_added';
  $handler->display->display_options['sorts']['date_added']['table'] = 'batire_user_docs';
  $handler->display->display_options['sorts']['date_added']['field'] = 'date_added';
  $handler->display->display_options['sorts']['date_added']['order'] = 'DESC';
  $handler->display->display_options['sorts']['date_added']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['date_added']['expose']['label'] = 'Batire User Docs: Date d\'enregistrement';
  /* Critère de tri: Nœud : Date de mise à jour */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Node: Updated date';
  /* Critère de tri: Nœud : Titre */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Nœud : Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Argument: Nœud : Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['wildcard'] = 'tous';
  $handler->display->display_options['arguments']['type']['wildcard_substitution'] = 'tous';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['default_argument_skip_url'] = 0;
  /* Argument: Utilisateur : Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['arguments']['uid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['wildcard'] = 'tous';
  $handler->display->display_options['arguments']['uid']['wildcard_substitution'] = 'tous';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_actualite' => 'batire_actualite',
    'batire_feuillet_mobile' => 'batire_feuillet_mobile',
    'batire_codes' => 'batire_codes',
    'batire_complement_technique' => 'batire_complement_technique',
    'batire_livres' => 'batire_livres',
    'batire_texte_normatifs' => 'batire_texte_normatifs',
    'batire_texte_officiel' => 'batire_texte_officiel',
  );
  $handler->display->display_options['pane_category']['name'] = 'Voir les volets';

  /* Display: Documents partagés */
  $handler = $view->new_display('panel_pane', 'Documents partagés', 'shared_documents');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Documents partagés';
  $handler->display->display_options['display_description'] = 'Documents partagés';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['build_mode'] = 'shared_document';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nœud : Referrers */
  $handler->display->display_options['relationships']['nodereferer_referers']['id'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['table'] = 'node';
  $handler->display->display_options['relationships']['nodereferer_referers']['field'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['required'] = 0;
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_delta'] = '-1';
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_field'] = 'field_folder_documents';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Critère de tri: Batire User Docs : Date vide */
  $handler->display->display_options['sorts']['date_empty']['id'] = 'date_empty';
  $handler->display->display_options['sorts']['date_empty']['table'] = 'batire_user_docs';
  $handler->display->display_options['sorts']['date_empty']['field'] = 'date_empty';
  /* Critère de tri: Batire User Docs : Date d'enregistrement */
  $handler->display->display_options['sorts']['date_added']['id'] = 'date_added';
  $handler->display->display_options['sorts']['date_added']['table'] = 'batire_user_docs';
  $handler->display->display_options['sorts']['date_added']['field'] = 'date_added';
  $handler->display->display_options['sorts']['date_added']['group_type'] = 'max';
  $handler->display->display_options['sorts']['date_added']['order'] = 'DESC';
  $handler->display->display_options['sorts']['date_added']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['date_added']['expose']['label'] = 'Batire User Docs: Date d\'enregistrement';
  /* Critère de tri: Nœud : Date de mise à jour */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'Node: Updated date';
  $handler->display->display_options['sorts']['changed']['granularity'] = 'day';
  /* Critère de tri: Nœud : Titre */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Utilisateur : Uid */
  $handler->display->display_options['arguments']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['arguments']['uid_1']['table'] = 'users';
  $handler->display->display_options['arguments']['uid_1']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid_1']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['arguments']['uid_1']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid_1']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['uid_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid_1']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid_1']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['uid_1']['not'] = 0;
  /* Argument: Nœud : Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['wildcard'] = 'tous';
  $handler->display->display_options['arguments']['type']['wildcard_substitution'] = 'tous';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['default_argument_skip_url'] = 0;
  /* Argument: Utilisateur : Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['arguments']['uid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['wildcard'] = 'tous';
  $handler->display->display_options['arguments']['uid']['wildcard_substitution'] = 'tous';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_actualite' => 'batire_actualite',
    'batire_feuillet_mobile' => 'batire_feuillet_mobile',
    'batire_codes' => 'batire_codes',
    'batire_complement_technique' => 'batire_complement_technique',
    'batire_livres' => 'batire_livres',
    'batire_texte_normatifs' => 'batire_texte_normatifs',
    'batire_texte_officiel' => 'batire_texte_officiel',
  );
  /* Filtrer: Contenu : Partager (field_folder_shared) */
  $handler->display->display_options['filters']['field_folder_shared_value']['id'] = 'field_folder_shared_value';
  $handler->display->display_options['filters']['field_folder_shared_value']['table'] = 'node_data_field_folder_shared';
  $handler->display->display_options['filters']['field_folder_shared_value']['field'] = 'field_folder_shared_value';
  $handler->display->display_options['filters']['field_folder_shared_value']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['filters']['field_folder_shared_value']['value']['value'] = '1';
  $handler->display->display_options['filters']['field_folder_shared_value']['allow_null'] = 1;
  $handler->display->display_options['pane_category']['name'] = 'Voir les volets';

  /* Display: Annotations partagés */
  $handler = $view->new_display('panel_pane', 'Annotations partagés', 'shared_annotations');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Annotations partagés';
  $handler->display->display_options['display_description'] = 'Annotations partagés';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['build_mode'] = 'shared_annotation';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nœud : Referrers */
  $handler->display->display_options['relationships']['nodereferer_referers']['id'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['table'] = 'node';
  $handler->display->display_options['relationships']['nodereferer_referers']['field'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['required'] = 0;
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_delta'] = '-1';
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_field'] = 'field_annotation_doc';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Critère de tri: Nœud : Date de publication */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['sorts']['created']['group_type'] = 'max';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'MAX(Node: Post date)';
  /* Critère de tri: Nœud : Date de mise à jour */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['sorts']['changed']['group_type'] = 'max';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['sorts']['changed']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['changed']['expose']['label'] = 'MAX(Node: Updated date)';
  /* Critère de tri: Nœud : Titre */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Utilisateur : Uid */
  $handler->display->display_options['arguments']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['arguments']['uid_1']['table'] = 'users';
  $handler->display->display_options['arguments']['uid_1']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid_1']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['arguments']['uid_1']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid_1']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['uid_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid_1']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid_1']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['uid_1']['not'] = 0;
  /* Argument: Nœud : Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['wildcard'] = 'tous';
  $handler->display->display_options['arguments']['type']['wildcard_substitution'] = 'tous';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['default_argument_skip_url'] = 0;
  /* Argument: Utilisateur : Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['arguments']['uid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['wildcard'] = 'tous';
  $handler->display->display_options['arguments']['uid']['wildcard_substitution'] = 'tous';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_actualite' => 'batire_actualite',
    'batire_user_annotation' => 'batire_user_annotation',
    'batire_feuillet_mobile' => 'batire_feuillet_mobile',
    'batire_codes' => 'batire_codes',
    'batire_complement_technique' => 'batire_complement_technique',
    'batire_livres' => 'batire_livres',
    'batire_texte_normatifs' => 'batire_texte_normatifs',
    'batire_texte_officiel' => 'batire_texte_officiel',
  );
  /* Filtrer: Contenu : Partager (field_annotation_shared) */
  $handler->display->display_options['filters']['field_annotation_shared_value']['id'] = 'field_annotation_shared_value';
  $handler->display->display_options['filters']['field_annotation_shared_value']['table'] = 'node_data_field_annotation_shared';
  $handler->display->display_options['filters']['field_annotation_shared_value']['field'] = 'field_annotation_shared_value';
  $handler->display->display_options['filters']['field_annotation_shared_value']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['filters']['field_annotation_shared_value']['value']['value'] = '1';
  $handler->display->display_options['filters']['field_annotation_shared_value']['allow_null'] = 1;
  $handler->display->display_options['pane_category']['name'] = 'Voir les volets';
  $translatables['batire_mon_compte'] = array(
    t('Defaults'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('Referencing Nodes'),
    t('Tous / Toutes'),
    t('Mes documents'),
    t('Field folder documents'),
    t('Date d\'enregistrement'),
    t('Date de mise à jour'),
    t('Voir les volets'),
    t('Mes dossiers'),
    t('Batire User Docs: Date d\'enregistrement'),
    t('Node: Updated date'),
    t('Mes annotations'),
    t('Field annotation doc'),
    t('MAX(Node: Post date)'),
    t('Dossiers partagés'),
    t('tous'),
    t('Documents partagés'),
    t('Annotations partagés'),
    t('MAX(Node: Updated date)'),
  );

  $views[$view->name] = $view;

  // Exported view: batire_user_docs_annotations
  $view = new view;
  $view->name = 'batire_user_docs_annotations';
  $view->description = '';
  $view->tag = 'Batire';
  $view->base_table = 'node';
  $view->human_name = 'Batire annotations view';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Champ: Nœud : Date de mise à jour */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_type'] = '0';
  $handler->display->display_options['fields']['changed']['element_label_type'] = '0';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['changed']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y';
  /* Champ: Contenu : Contenu (field_annotation_text) */
  $handler->display->display_options['fields']['field_annotation_text_value']['id'] = 'field_annotation_text_value';
  $handler->display->display_options['fields']['field_annotation_text_value']['table'] = 'node_data_field_annotation_text';
  $handler->display->display_options['fields']['field_annotation_text_value']['field'] = 'field_annotation_text_value';
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_annotation_text_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_annotation_text_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_annotation_text_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_annotation_text_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_annotation_text_value']['format'] = 'plain';
  /* Champ: Nœud : Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Critère de tri: Nœud : Date de mise à jour */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Argument: Contenu : Document (field_annotation_doc) */
  $handler->display->display_options['arguments']['field_annotation_doc_nid']['id'] = 'field_annotation_doc_nid';
  $handler->display->display_options['arguments']['field_annotation_doc_nid']['table'] = 'node_data_field_annotation_doc';
  $handler->display->display_options['arguments']['field_annotation_doc_nid']['field'] = 'field_annotation_doc_nid';
  $handler->display->display_options['arguments']['field_annotation_doc_nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['field_annotation_doc_nid']['default_argument_type'] = 'fixed';
  /* Argument: Utilisateur : Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_user_annotation' => 'batire_user_annotation',
  );
  /* Filtrer: Contenu : Document (field_annotation_doc) */
  $handler->display->display_options['filters']['field_annotation_doc_nid']['id'] = 'field_annotation_doc_nid';
  $handler->display->display_options['filters']['field_annotation_doc_nid']['table'] = 'node_data_field_annotation_doc';
  $handler->display->display_options['filters']['field_annotation_doc_nid']['field'] = 'field_annotation_doc_nid';
  $handler->display->display_options['filters']['field_annotation_doc_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_annotation_doc_nid']['reduce_duplicates'] = 0;
  /* Filtrer: Contenu : Partager (field_annotation_shared) */
  $handler->display->display_options['filters']['field_annotation_shared_value']['id'] = 'field_annotation_shared_value';
  $handler->display->display_options['filters']['field_annotation_shared_value']['table'] = 'node_data_field_annotation_shared';
  $handler->display->display_options['filters']['field_annotation_shared_value']['field'] = 'field_annotation_shared_value';
  $handler->display->display_options['filters']['field_annotation_shared_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_annotation_shared_value']['value']['value'] = '1';
  $handler->display->display_options['filters']['field_annotation_shared_value']['allow_null'] = 1;

  /* Display: Document personel annotations */
  $handler = $view->new_display('block', 'Document personel annotations', 'block_1');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_user_annotation' => 'batire_user_annotation',
  );
  /* Filtrer: Contenu : Document (field_annotation_doc) */
  $handler->display->display_options['filters']['field_annotation_doc_nid']['id'] = 'field_annotation_doc_nid';
  $handler->display->display_options['filters']['field_annotation_doc_nid']['table'] = 'node_data_field_annotation_doc';
  $handler->display->display_options['filters']['field_annotation_doc_nid']['field'] = 'field_annotation_doc_nid';
  $handler->display->display_options['filters']['field_annotation_doc_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_annotation_doc_nid']['reduce_duplicates'] = 0;
  /* Filtrer: Contenu : Partager (field_annotation_shared) */
  $handler->display->display_options['filters']['field_annotation_shared_value']['id'] = 'field_annotation_shared_value';
  $handler->display->display_options['filters']['field_annotation_shared_value']['table'] = 'node_data_field_annotation_shared';
  $handler->display->display_options['filters']['field_annotation_shared_value']['field'] = 'field_annotation_shared_value';
  $handler->display->display_options['filters']['field_annotation_shared_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_annotation_shared_value']['value']['value'] = '1';
  $handler->display->display_options['filters']['field_annotation_shared_value']['allow_null'] = 1;
  /* Filtrer: Utilisateur : Actuel */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: Document shared annotations */
  $handler = $view->new_display('block', 'Document shared annotations', 'block_2');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nœud : Contenu de profil */
  $handler->display->display_options['relationships']['content_profile_rel']['id'] = 'content_profile_rel';
  $handler->display->display_options['relationships']['content_profile_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['content_profile_rel']['field'] = 'content_profile_rel';
  $handler->display->display_options['relationships']['content_profile_rel']['required'] = 0;
  $handler->display->display_options['relationships']['content_profile_rel']['type'] = 'batire_user_profile';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Nœud : Date de mise à jour */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_type'] = '0';
  $handler->display->display_options['fields']['changed']['element_label_type'] = '0';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['changed']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y';
  /* Champ: Contenu : Contenu (field_annotation_text) */
  $handler->display->display_options['fields']['field_annotation_text_value']['id'] = 'field_annotation_text_value';
  $handler->display->display_options['fields']['field_annotation_text_value']['table'] = 'node_data_field_annotation_text';
  $handler->display->display_options['fields']['field_annotation_text_value']['field'] = 'field_annotation_text_value';
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_annotation_text_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_annotation_text_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_annotation_text_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_annotation_text_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_annotation_text_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_annotation_text_value']['format'] = 'plain';
  /* Champ: Nœud : Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Champ: Utilisateur : Nom */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['name']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 0;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Champ: Contenu : Nom (field_user_surname) */
  $handler->display->display_options['fields']['field_user_surname_value']['id'] = 'field_user_surname_value';
  $handler->display->display_options['fields']['field_user_surname_value']['table'] = 'node_data_field_user_surname';
  $handler->display->display_options['fields']['field_user_surname_value']['field'] = 'field_user_surname_value';
  $handler->display->display_options['fields']['field_user_surname_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_surname_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_surname_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_surname_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_user_surname_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_user_surname_value']['format'] = 'plain';
  /* Champ: Contenu : Prénom (field_user_name) */
  $handler->display->display_options['fields']['field_user_name_value']['id'] = 'field_user_name_value';
  $handler->display->display_options['fields']['field_user_name_value']['table'] = 'node_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name_value']['field'] = 'field_user_name_value';
  $handler->display->display_options['fields']['field_user_name_value']['relationship'] = 'content_profile_rel';
  $handler->display->display_options['fields']['field_user_name_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_name_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_name_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_user_name_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_user_name_value']['format'] = 'plain';
  /* Champ: Utilisateur : Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_type'] = '0';
  $handler->display->display_options['fields']['uid']['element_label_type'] = '0';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['uid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_user_annotation' => 'batire_user_annotation',
  );
  /* Filtrer: Contenu : Document (field_annotation_doc) */
  $handler->display->display_options['filters']['field_annotation_doc_nid']['id'] = 'field_annotation_doc_nid';
  $handler->display->display_options['filters']['field_annotation_doc_nid']['table'] = 'node_data_field_annotation_doc';
  $handler->display->display_options['filters']['field_annotation_doc_nid']['field'] = 'field_annotation_doc_nid';
  $handler->display->display_options['filters']['field_annotation_doc_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_annotation_doc_nid']['reduce_duplicates'] = 0;
  /* Filtrer: Contenu : Partager (field_annotation_shared) */
  $handler->display->display_options['filters']['field_annotation_shared_value']['id'] = 'field_annotation_shared_value';
  $handler->display->display_options['filters']['field_annotation_shared_value']['table'] = 'node_data_field_annotation_shared';
  $handler->display->display_options['filters']['field_annotation_shared_value']['field'] = 'field_annotation_shared_value';
  $handler->display->display_options['filters']['field_annotation_shared_value']['value']['value'] = '1';
  $handler->display->display_options['filters']['field_annotation_shared_value']['allow_null'] = 1;
  $translatables['batire_user_docs_annotations'] = array(
    t('Defaults'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Date de mise à jour'),
    t('Nid'),
    t('Tous / Toutes'),
    t('Document personel annotations'),
    t('Document shared annotations'),
    t('Contenu de profil'),
    t('Nom'),
    t('Uid'),
  );

  $views[$view->name] = $view;

  // Exported view: batire_user_searches
  $view = new view;
  $view->name = 'batire_user_searches';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'Batire user searches';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Appliquer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['build_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Champ: Nœud : Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Champ: Nœud : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Champ: Contenu : Number of found items (field_search_total) */
  $handler->display->display_options['fields']['field_search_total_value']['id'] = 'field_search_total_value';
  $handler->display->display_options['fields']['field_search_total_value']['table'] = 'node_data_field_search_total';
  $handler->display->display_options['fields']['field_search_total_value']['field'] = 'field_search_total_value';
  /* Champ: Contenu : Number of new items since last search (field_search_new) */
  $handler->display->display_options['fields']['field_search_new_value']['id'] = 'field_search_new_value';
  $handler->display->display_options['fields']['field_search_new_value']['table'] = 'node_data_field_search_new';
  $handler->display->display_options['fields']['field_search_new_value']['field'] = 'field_search_new_value';
  /* Champ: Contenu : Périodicité (field_alert_period) */
  $handler->display->display_options['fields']['field_alert_period_value']['id'] = 'field_alert_period_value';
  $handler->display->display_options['fields']['field_alert_period_value']['table'] = 'node_data_field_alert_period';
  $handler->display->display_options['fields']['field_alert_period_value']['field'] = 'field_alert_period_value';
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';

  /* Display: Mes alertes */
  $handler = $view->new_display('panel_pane', 'Mes alertes', 'my_sent_alerts');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mes dernières alertes';
  $handler->display->display_options['display_description'] = 'Mes dernieres alertes recues';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nœud : Referrers */
  $handler->display->display_options['relationships']['nodereferer_referers']['id'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['table'] = 'node';
  $handler->display->display_options['relationships']['nodereferer_referers']['field'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['required'] = 0;
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_delta'] = '-1';
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_field'] = 'field_sent_alert_alert';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Nœud : Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Champ: Nœud : Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid_1']['link_to_node'] = 0;
  /* Champ: Nœud : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Champ: Contenu : Number of found items (field_search_total) */
  $handler->display->display_options['fields']['field_search_total_value']['id'] = 'field_search_total_value';
  $handler->display->display_options['fields']['field_search_total_value']['table'] = 'node_data_field_search_total';
  $handler->display->display_options['fields']['field_search_total_value']['field'] = 'field_search_total_value';
  /* Champ: Contenu : Number of new items since last search (field_search_new) */
  $handler->display->display_options['fields']['field_search_new_value']['id'] = 'field_search_new_value';
  $handler->display->display_options['fields']['field_search_new_value']['table'] = 'node_data_field_search_new';
  $handler->display->display_options['fields']['field_search_new_value']['field'] = 'field_search_new_value';
  $handler->display->display_options['fields']['field_search_new_value']['label'] = 'Number of new items since last search';
  $handler->display->display_options['fields']['field_search_new_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_search_new_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_search_new_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_search_new_value']['link_to_node'] = 0;
  /* Champ: Contenu : Périodicité (field_alert_period) */
  $handler->display->display_options['fields']['field_alert_period_value']['id'] = 'field_alert_period_value';
  $handler->display->display_options['fields']['field_alert_period_value']['table'] = 'node_data_field_alert_period';
  $handler->display->display_options['fields']['field_alert_period_value']['field'] = 'field_alert_period_value';
  $handler->display->display_options['fields']['field_alert_period_value']['label'] = 'Périodicité';
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_alert_period_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_alert_period_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_alert_period_value']['link_to_node'] = 0;
  /* Champ: Nœud : Date de publication */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  /* Champ: Contenu : Profile type (field_profile_type) */
  $handler->display->display_options['fields']['field_profile_type_value']['id'] = 'field_profile_type_value';
  $handler->display->display_options['fields']['field_profile_type_value']['table'] = 'node_data_field_profile_type';
  $handler->display->display_options['fields']['field_profile_type_value']['field'] = 'field_profile_type_value';
  $handler->display->display_options['fields']['field_profile_type_value']['label'] = 'Profile type';
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_profile_type_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_type_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_type_value']['link_to_node'] = 0;
  /* Champ: Contenu : Number of found items (field_sent_alert_total) */
  $handler->display->display_options['fields']['field_sent_alert_total_value']['id'] = 'field_sent_alert_total_value';
  $handler->display->display_options['fields']['field_sent_alert_total_value']['table'] = 'node_data_field_sent_alert_total';
  $handler->display->display_options['fields']['field_sent_alert_total_value']['field'] = 'field_sent_alert_total_value';
  $handler->display->display_options['fields']['field_sent_alert_total_value']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['fields']['field_sent_alert_total_value']['label'] = 'Number of found items';
  $handler->display->display_options['fields']['field_sent_alert_total_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_total_value']['link_to_node'] = 0;
  /* Champ: Contenu : Number of new items since last search (field_sent_alert_new) */
  $handler->display->display_options['fields']['field_sent_alert_new_value']['id'] = 'field_sent_alert_new_value';
  $handler->display->display_options['fields']['field_sent_alert_new_value']['table'] = 'node_data_field_sent_alert_new';
  $handler->display->display_options['fields']['field_sent_alert_new_value']['field'] = 'field_sent_alert_new_value';
  $handler->display->display_options['fields']['field_sent_alert_new_value']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['fields']['field_sent_alert_new_value']['label'] = 'Number of new items since last search';
  $handler->display->display_options['fields']['field_sent_alert_new_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_new_value']['link_to_node'] = 0;
  /* Champ: Contenu : Search id (field_sent_alert_sid) */
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['id'] = 'field_sent_alert_sid_value';
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['table'] = 'node_data_field_sent_alert_sid';
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['field'] = 'field_sent_alert_sid_value';
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['label'] = 'Search id';
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_sent_alert_sid_value']['link_to_node'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Critère de tri: Nœud : Date de publication */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Node: Post date';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Argument: Nœud : Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['wildcard'] = 'tous';
  $handler->display->display_options['arguments']['nid']['wildcard_substitution'] = 'tous';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Argument: Contenu : Périodicité (field_alert_period) */
  $handler->display->display_options['arguments']['field_alert_period_value']['id'] = 'field_alert_period_value';
  $handler->display->display_options['arguments']['field_alert_period_value']['table'] = 'node_data_field_alert_period';
  $handler->display->display_options['arguments']['field_alert_period_value']['field'] = 'field_alert_period_value';
  $handler->display->display_options['arguments']['field_alert_period_value']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['field_alert_period_value']['wildcard'] = 'tous';
  $handler->display->display_options['arguments']['field_alert_period_value']['wildcard_substitution'] = 'tous';
  $handler->display->display_options['arguments']['field_alert_period_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_alert_period_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_alert_period_value']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_alert_period_value']['add_table'] = 0;
  $handler->display->display_options['arguments']['field_alert_period_value']['require_value'] = 0;
  $handler->display->display_options['arguments']['field_alert_period_value']['reduce_duplicates'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_user_sent_alert' => 'batire_user_sent_alert',
  );
  /* Filtrer: Utilisateur : Actuel */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  /* Filtrer: Contenu : Profile type (field_profile_type) - Valeurs autorisées */
  $handler->display->display_options['filters']['field_profile_type_value_many_to_one']['id'] = 'field_profile_type_value_many_to_one';
  $handler->display->display_options['filters']['field_profile_type_value_many_to_one']['table'] = 'node_data_field_profile_type';
  $handler->display->display_options['filters']['field_profile_type_value_many_to_one']['field'] = 'field_profile_type_value_many_to_one';
  $handler->display->display_options['filters']['field_profile_type_value_many_to_one']['value'] = array(
    1 => '1',
    2 => '2',
  );
  $handler->display->display_options['filters']['field_profile_type_value_many_to_one']['reduce_duplicates'] = 0;
  $handler->display->display_options['pane_category']['name'] = 'Voir les volets';

  /* Display: Mes profils de recherche  */
  $handler = $view->new_display('panel_pane', 'Mes profils de recherche ', 'my_profile');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mes profils de recherche ';
  $handler->display->display_options['display_description'] = 'Mes profils de recherche ';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nœud : Referrers */
  $handler->display->display_options['relationships']['nodereferer_referers']['id'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['table'] = 'node';
  $handler->display->display_options['relationships']['nodereferer_referers']['field'] = 'nodereferer_referers';
  $handler->display->display_options['relationships']['nodereferer_referers']['required'] = 0;
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_delta'] = '-1';
  $handler->display->display_options['relationships']['nodereferer_referers']['referrer_field'] = 'field_sent_alert_alert';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Nœud : Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Champ: Nœud : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Champ: Contenu : Alerte document (field_alert_document) */
  $handler->display->display_options['fields']['field_alert_document_nid']['id'] = 'field_alert_document_nid';
  $handler->display->display_options['fields']['field_alert_document_nid']['table'] = 'node_data_field_alert_document';
  $handler->display->display_options['fields']['field_alert_document_nid']['field'] = 'field_alert_document_nid';
  $handler->display->display_options['fields']['field_alert_document_nid']['label'] = 'Alerte document';
  $handler->display->display_options['fields']['field_alert_document_nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_alert_document_nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_alert_document_nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_alert_document_nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_alert_document_nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_alert_document_nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_alert_document_nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_alert_document_nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_alert_document_nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_alert_document_nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_alert_document_nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_alert_document_nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_alert_document_nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_alert_document_nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_alert_document_nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_alert_document_nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_alert_document_nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_alert_document_nid']['link_to_node'] = 0;
  /* Champ: Contenu : Number of found items (field_search_total) */
  $handler->display->display_options['fields']['field_search_total_value']['id'] = 'field_search_total_value';
  $handler->display->display_options['fields']['field_search_total_value']['table'] = 'node_data_field_search_total';
  $handler->display->display_options['fields']['field_search_total_value']['field'] = 'field_search_total_value';
  $handler->display->display_options['fields']['field_search_total_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_search_total_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_search_total_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_search_total_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_search_total_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_search_total_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_search_total_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_search_total_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_search_total_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_search_total_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_search_total_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_search_total_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_search_total_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_search_total_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_search_total_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_search_total_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_search_total_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_search_total_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_search_total_value']['label_type'] = 'none';
  /* Champ: Contenu : Number of new items since last search (field_search_new) */
  $handler->display->display_options['fields']['field_search_new_value']['id'] = 'field_search_new_value';
  $handler->display->display_options['fields']['field_search_new_value']['table'] = 'node_data_field_search_new';
  $handler->display->display_options['fields']['field_search_new_value']['field'] = 'field_search_new_value';
  $handler->display->display_options['fields']['field_search_new_value']['label'] = 'Number of new items since last search';
  $handler->display->display_options['fields']['field_search_new_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_search_new_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_search_new_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_search_new_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_search_new_value']['link_to_node'] = 0;
  /* Champ: Contenu : Périodicité (field_alert_period) */
  $handler->display->display_options['fields']['field_alert_period_value']['id'] = 'field_alert_period_value';
  $handler->display->display_options['fields']['field_alert_period_value']['table'] = 'node_data_field_alert_period';
  $handler->display->display_options['fields']['field_alert_period_value']['field'] = 'field_alert_period_value';
  $handler->display->display_options['fields']['field_alert_period_value']['label'] = 'Périodicité';
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_alert_period_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_alert_period_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_alert_period_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_alert_period_value']['link_to_node'] = 0;
  /* Champ: Contenu : Profile type (field_profile_type) */
  $handler->display->display_options['fields']['field_profile_type_value']['id'] = 'field_profile_type_value';
  $handler->display->display_options['fields']['field_profile_type_value']['table'] = 'node_data_field_profile_type';
  $handler->display->display_options['fields']['field_profile_type_value']['field'] = 'field_profile_type_value';
  $handler->display->display_options['fields']['field_profile_type_value']['label'] = 'Profile type';
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_profile_type_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_profile_type_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_profile_type_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_type_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_type_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_type_value']['link_to_node'] = 0;
  /* Champ: Nœud : Date de publication */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  /* Champ: Nœud : Date de publication */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'node';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['relationship'] = 'nodereferer_referers';
  $handler->display->display_options['fields']['created_1']['group_type'] = 'max';
  $handler->display->display_options['fields']['created_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created_1']['hide_alter_empty'] = 1;
  /* Champ: Contenu : Search id (field_search_id) */
  $handler->display->display_options['fields']['field_search_id_value']['id'] = 'field_search_id_value';
  $handler->display->display_options['fields']['field_search_id_value']['table'] = 'node_data_field_search_id';
  $handler->display->display_options['fields']['field_search_id_value']['field'] = 'field_search_id_value';
  $handler->display->display_options['fields']['field_search_id_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_search_id_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_search_id_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['element_type'] = '0';
  $handler->display->display_options['fields']['field_search_id_value']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_search_id_value']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_search_id_value']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_search_id_value']['link_to_node'] = 0;
  $handler->display->display_options['fields']['field_search_id_value']['label_type'] = 'none';
  $handler->display->display_options['fields']['field_search_id_value']['format'] = 'plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Critère de tri: Nœud : Date de publication */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Node: Post date';
  /* Critère de tri: Nœud : Titre */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Node: Title';
  /* Critère de tri: Batire User Searches : Number of new items since last search */
  $handler->display->display_options['sorts']['new']['id'] = 'new';
  $handler->display->display_options['sorts']['new']['table'] = 'batire_user_searches';
  $handler->display->display_options['sorts']['new']['field'] = 'new';
  $handler->display->display_options['sorts']['new']['order'] = 'DESC';
  $handler->display->display_options['sorts']['new']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['new']['expose']['label'] = 'Batire User Searches: Number of new items since last search';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtrer: Nœud : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_user_search_profile' => 'batire_user_search_profile',
  );
  /* Filtrer: Utilisateur : Actuel */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  /* Filtrer: Contenu : Profile type (field_profile_type) - Valeurs autorisées */
  $handler->display->display_options['filters']['field_profile_type_value_many_to_one']['id'] = 'field_profile_type_value_many_to_one';
  $handler->display->display_options['filters']['field_profile_type_value_many_to_one']['table'] = 'node_data_field_profile_type';
  $handler->display->display_options['filters']['field_profile_type_value_many_to_one']['field'] = 'field_profile_type_value_many_to_one';
  $handler->display->display_options['filters']['field_profile_type_value_many_to_one']['value'] = array(
    0 => '0',
    1 => '1',
    2 => '2',
  );
  $handler->display->display_options['filters']['field_profile_type_value_many_to_one']['reduce_duplicates'] = 0;
  $handler->display->display_options['pane_category']['name'] = 'Voir les volets';
  $translatables['batire_user_searches'] = array(
    t('Defaults'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('Nid'),
    t('Titre'),
    t('Mes alertes'),
    t('Mes dernières alertes'),
    t('Mes dernieres alertes recues'),
    t('Referencing Nodes'),
    t('Number of new items since last search'),
    t('Périodicité'),
    t('Date de publication'),
    t('Profile type'),
    t('Number of found items'),
    t('Search id'),
    t('Node: Post date'),
    t('tous'),
    t('Voir les volets'),
    t('Mes profils de recherche '),
    t('Alerte document'),
    t('Node: Title'),
    t('Batire User Searches: Number of new items since last search'),
  );

  $views[$view->name] = $view;

  return $views;
}

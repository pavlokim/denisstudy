<?php

/**
 * Implementation of hook_views_default_views().
 */
function batire_products_views_default_views() {
  $views = array();

  // Exported view: batire_product_list
  $view = new view;
  $view->name = 'batire_product_list';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 6;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
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
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'weight';
  $handler->display->display_options['style_options']['columns'] = array(
    'type' => 'type',
    'title' => 'title',
    'field_svc_code_value' => 'field_svc_code_value',
    'field_product_tarif_value' => 'field_product_tarif_value',
    'field_product_enabled_value' => 'field_product_enabled_value',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['style_options']['info'] = array(
    'type' => array(
      'separator' => '',
    ),
    'title' => array(
      'separator' => '',
    ),
    'field_svc_code_value' => array(
      'separator' => '',
    ),
    'field_product_tarif_value' => array(
      'separator' => '',
    ),
    'field_product_enabled_value' => array(
      'separator' => '',
    ),
    'edit_node' => array(
      'separator' => '',
    ),
    'delete_node' => array(
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  /* Champ: Nœud : Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
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
  /* Champ: Taxonomie : Tous les termes */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'term_node';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
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
  $handler->display->display_options['fields']['tid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['tid']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['tid']['limit'] = 1;
  $handler->display->display_options['fields']['tid']['vids'] = array(
    22 => 22,
    15 => 0,
    5 => 0,
    17 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    9 => 0,
    8 => 0,
    16 => 0,
    6 => 0,
    7 => 0,
    19 => 0,
    21 => 0,
    4 => 0,
    20 => 0,
    1 => 0,
    13 => 0,
    14 => 0,
    3 => 0,
  );
  /* Champ: Contenu : Code produit SVC (field_svc_code) */
  $handler->display->display_options['fields']['field_svc_code_value']['id'] = 'field_svc_code_value';
  $handler->display->display_options['fields']['field_svc_code_value']['table'] = 'node_data_field_svc_code';
  $handler->display->display_options['fields']['field_svc_code_value']['field'] = 'field_svc_code_value';
  $handler->display->display_options['fields']['field_svc_code_value']['label'] = 'Code produit SVC';
  $handler->display->display_options['fields']['field_svc_code_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_svc_code_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_svc_code_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_svc_code_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_svc_code_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_svc_code_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_svc_code_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_svc_code_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_svc_code_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_svc_code_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_svc_code_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_svc_code_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_svc_code_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_svc_code_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_svc_code_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_svc_code_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_svc_code_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_svc_code_value']['link_to_node'] = 0;
  /* Champ: Contenu : Tarif HT (field_product_tarif) */
  $handler->display->display_options['fields']['field_product_tarif_value']['id'] = 'field_product_tarif_value';
  $handler->display->display_options['fields']['field_product_tarif_value']['table'] = 'node_data_field_product_tarif';
  $handler->display->display_options['fields']['field_product_tarif_value']['field'] = 'field_product_tarif_value';
  $handler->display->display_options['fields']['field_product_tarif_value']['label'] = 'Tarif HT';
  $handler->display->display_options['fields']['field_product_tarif_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_product_tarif_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_product_tarif_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_product_tarif_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_product_tarif_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_product_tarif_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_product_tarif_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_product_tarif_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_product_tarif_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_product_tarif_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_product_tarif_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_product_tarif_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_product_tarif_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_product_tarif_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_product_tarif_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_product_tarif_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_product_tarif_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_product_tarif_value']['link_to_node'] = 0;
  /* Champ: Contenu : Statut (field_product_enabled) */
  $handler->display->display_options['fields']['field_product_enabled_value']['id'] = 'field_product_enabled_value';
  $handler->display->display_options['fields']['field_product_enabled_value']['table'] = 'node_data_field_product_enabled';
  $handler->display->display_options['fields']['field_product_enabled_value']['field'] = 'field_product_enabled_value';
  $handler->display->display_options['fields']['field_product_enabled_value']['label'] = 'Statut';
  $handler->display->display_options['fields']['field_product_enabled_value']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_product_enabled_value']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_product_enabled_value']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_product_enabled_value']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_product_enabled_value']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_product_enabled_value']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_product_enabled_value']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_product_enabled_value']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_product_enabled_value']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_product_enabled_value']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_product_enabled_value']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_product_enabled_value']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_product_enabled_value']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_product_enabled_value']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_product_enabled_value']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_product_enabled_value']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_product_enabled_value']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_product_enabled_value']['link_to_node'] = 0;
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
  /* Champ: Poids : Poids */
  $handler->display->display_options['fields']['weight']['id'] = 'weight';
  $handler->display->display_options['fields']['weight']['table'] = 'node_weight';
  $handler->display->display_options['fields']['weight']['field'] = 'weight';
  $handler->display->display_options['fields']['weight']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['external'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['weight']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['weight']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['weight']['alter']['html'] = 0;
  $handler->display->display_options['fields']['weight']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['weight']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['weight']['hide_empty'] = 0;
  $handler->display->display_options['fields']['weight']['empty_zero'] = 0;
  $handler->display->display_options['fields']['weight']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['weight']['format_plural'] = 0;
  /* Critère de tri: Poids : Poids */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'node_weight';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filtrer: Contenu : Code produit SVC (field_svc_code) */
  $handler->display->display_options['filters']['field_svc_code_value']['id'] = 'field_svc_code_value';
  $handler->display->display_options['filters']['field_svc_code_value']['table'] = 'node_data_field_svc_code';
  $handler->display->display_options['filters']['field_svc_code_value']['field'] = 'field_svc_code_value';
  $handler->display->display_options['filters']['field_svc_code_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_svc_code_value']['expose']['operator'] = 'field_svc_code_value_op';
  $handler->display->display_options['filters']['field_svc_code_value']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['field_svc_code_value']['expose']['label'] = 'Code produit SVC';
  $handler->display->display_options['filters']['field_svc_code_value']['expose']['identifier'] = 'field_svc_code_value';
  $handler->display->display_options['filters']['field_svc_code_value']['expose']['optional'] = TRUE;
  $handler->display->display_options['filters']['field_svc_code_value']['expose']['single'] = TRUE;
  $handler->display->display_options['filters']['field_svc_code_value']['case'] = 1;
  /* Filtrer: Type de Produit  */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['ui_name'] = 'Type de Produit ';
  $handler->display->display_options['filters']['type']['value'] = array(
    'batire_product_module_1_2' => 'batire_product_module_1_2',
    'batire_product_module_3' => 'batire_product_module_3',
  );
  /* Filtrer: Taxonomie : Identifiant de terme (avec profondeur) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Type de Produit ';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vid'] = '22';
  $handler->display->display_options['filters']['term_node_tid_depth']['error_message'] = 0;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '0';
  /* Filtrer: Nœud : Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'batire_product_module_1_2' => 'batire_product_module_1_2',
    'batire_product_module_3' => 'batire_product_module_3',
  );
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['limit_operators'] = array();
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Type de Module';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/batire-site/product/list';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Lister des Produits';
  $handler->display->display_options['menu']['weight'] = '0';
  $translatables['batire_product_list'] = array(
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
    t('Type'),
    t('Titre'),
    t('Tous les termes'),
    t('Code produit SVC'),
    t('Tarif HT'),
    t('Statut'),
    t('Lien de modification'),
    t('Lien de suppression'),
    t('Poids'),
    t('.'),
    t(','),
    t('Type de Produit '),
    t('Type de Module'),
    t('Page'),
  );

  $views[$view->name] = $view;

  return $views;
}

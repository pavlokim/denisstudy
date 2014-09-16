<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function batire_products_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function batire_products_node_info() {
  $items = array(
    'batire_product_module_1_2' => array(
      'name' => t('Produit (module 1-2)'),
      'module' => 'features',
      'description' => t('Content type product of mudule 1 and 2'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'batire_product_module_3' => array(
      'name' => t('Produit (module 3)'),
      'module' => 'features',
      'description' => t('Content type product of mudule 3'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function batire_products_views_api() {
  return array(
    'api' => '3.0',
  );
}

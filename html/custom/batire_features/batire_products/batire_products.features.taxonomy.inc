<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function batire_products_taxonomy_default_vocabularies() {
  return array(
    'codes_espaces' => array(
      'name' => 'Codes d\'espaces réservés',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '0',
      'tags' => '0',
      'module' => 'features_codes_espaces',
      'weight' => '0',
      'type' => NULL,
      'nodes' => array(),
    ),
    'product_types' => array(
      'name' => 'Type de produit',
      'description' => 'Type de produit',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '1',
      'multiple' => '0',
      'required' => '1',
      'tags' => '0',
      'module' => 'features_product_types',
      'weight' => '0',
      'nodes' => array(
        'batire_product_module_1_2' => 'batire_product_module_1_2',
        'batire_product_module_3' => 'batire_product_module_3',
      ),
    ),
  );
}

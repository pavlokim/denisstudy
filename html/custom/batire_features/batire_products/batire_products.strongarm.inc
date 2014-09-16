<?php

/**
 * Implementation of hook_strongarm().
 */
function batire_products_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_product_module_1_2';
  $strongarm->value = array(
    'title' => '36',
    'revision_information' => '48',
    'author' => '47',
    'options' => '49',
    'menu' => '46',
    'taxonomy' => '45',
    'path' => '50',
    'print' => '51',
  );
  $export['content_extra_weights_batire_product_module_1_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_product_module_3';
  $strongarm->value = array(
    'title' => '41',
    'revision_information' => '52',
    'author' => '51',
    'options' => '53',
    'menu' => '49',
    'taxonomy' => '50',
    'path' => '54',
    'print' => '55',
  );
  $export['content_extra_weights_batire_product_module_3'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_product_module_1_2';
  $strongarm->value = '0';
  $export['language_content_type_batire_product_module_1_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_product_module_3';
  $strongarm->value = '0';
  $export['language_content_type_batire_product_module_3'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_product_module_1_2';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_batire_product_module_1_2'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_product_module_3';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_batire_product_module_3'] = $strongarm;

  return $export;
}

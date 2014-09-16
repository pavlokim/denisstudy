<?php

function batire_site_drush_command() {
  $items['batire-site-offmod-deploy'] = array(
    'description' => 'Deploy all changes for offre modulaire.',
    'aliases' => array(
      'offmod-deploy',
    ),
  );
  return $items;
}

function drush_batire_site_offmod_deploy() {
  module_load_include('inc', 'features', 'features.export');

  // enable features
  $features = array('batire_products');
  features_install_modules($features);

  // revert features
  $revert = array('batire_content_types', 'batire_products');
  $revert = features_get_component_states($revert);
  foreach ($revert as $key => $value) {
    $revert[$key] = array_keys($value);
  }
  $revert['batire_products'][] = 'views';
  features_revert($revert);

  cache_clear_all();

  // enable modules
  $modules = array('batire_user_products');
  module_enable($modules);
  foreach ($modules as $module) {
    module_invoke($module, 'install');
  }
}

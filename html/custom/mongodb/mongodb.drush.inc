<?php

/**
 * @file
 * Provide drush integration for mongodb
 *
 * @Todo
 *  Check whether the alias argument is used.
 */
/**
 * Implementation of hook_drush_command().
 */
function mongodb_drush_command() {
//   $options['--alias'] = 'The alias defined in the variable mongodb_collections.';

  $items['mongodb-connect'] = array(
    'description' => 'A string for connecting to the mongodb.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_CONFIGURATION,
//     'options' => $options,
    'arguments' => array(
       'alias' => 'The connection',
    ),
  );

  $items['mongodb-cli'] = array(
    'description' => "Open a mongodb command-line interface using Drupal's credentials.",
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_CONFIGURATION,
//     'options' => $options,
    'examples' => array(
      '`drush mongodb-connect`' => 'Connect to the mongodb.',
    ),
    'arguments' => array(
       'alias' => 'The connection',
    ),
    'aliases' => array('mdbc'),
  );

  $items['mongodb-conf'] = array(
    'description' => 'Print mongodb connection details using print_r().',
    'arguments' => array(
      'all' => 'Show all mongodb connections, instead of just one.',
    ),
    'arguments' => array(
       'alias' => 'The connection',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_CONFIGURATION,
//     'options' => $options,
  );

  $items['mongodb-query'] = array(
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
    'description' => 'Execute a query against the site mongodb.',
    'examples' => array(
      'drush mongodb-query "db.watchdog.find().forEach(function(x){print(tojson(x))});"' => 'Get the watchdog entries.',
    ),
    'arguments' => array(
       'alias' => 'The connection',
       'query' => 'A mongodb query. Mandatory.',
    ),
//     'options' => array(
//       '--extra' => 'Add custom options to the mongodb command.',
//     ) + $options,
    'aliases' => array('mdbq'),
  );

  $items['mongodb-recreate'] = array(
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
    'description' => 'Recreate mongodb collections.',
    'examples' => array(
      'drush mongodb-recreate' => 'Recreate all collections.',
      'drush mongodb-recreate user' => 'Recreate user collection.',
      'drush mongodb-recreate docs' => 'Recreate documents collection.',
    ),
    'arguments' => array(
      'rtype' => 'Recreate type.',
    ),
  );

  // Moved here from mongodb_site.drush.inc because of http://drupal.org/node/704848
  $items['mongodb-site-regenerate-tdm'] = array(
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_DATABASE,
    'description' => 'Regenerate TdM.',
    'examples' => array(
      'drush mongodb-site-regenerate-tdm'                             => 'Regenerate all Content types.',
      'drush mongodb-site-regenerate-tdm batire_texte_officiel'       => 'Regenerate TO.',
      'drush mongodb-site-regenerate-tdm batire_feuillet_mobile'      => 'Regenerate FM.',
      'drush mongodb-site-regenerate-tdm batire_livres'               => 'Regenerate Livres.',
      'drush mongodb-site-regenerate-tdm batire_texte_normatifs'      => 'Regenerate TN.',
      'drush mongodb-site-regenerate-tdm batire_codes'                => 'Regenerate Codes.',
      'drush mongodb-site-regenerate-tdm batire_complement_technique' => 'Regenerate CT.',
      'drush mongodb-site-regenerate-tdm batire_actualite'            => 'Regenerate Actu.',
      'drush mongodb-site-regenerate-tdm batire_document_reference'  =>  'Regenerate DR',
    ),
    'arguments' => array(
      'rtype' => 'Regeneration type.'
    ),
    'aliases' => array('mdbsrt')
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 */
function mongodb_drush_help($section) {
  switch ($section) {
    case 'drush:mongodb-conf':
      return dt('Show database connection details.');

    case 'drush:mongodb-connect':
      return dt('A string which connects to the current database.');

    case 'drush:mongodb-cli':
      return dt('Quickly enter the mongodb shell.');

    // TODO
    case 'drush:mongodb-dump':
      return dt('Prints the whole database to STDOUT or save to a file.');

    case 'drush:mongodb-query':
      return dt("Usage: drush [options] mongodb-query <query>...\n<query> is a single js command. It does not print the result by default, see the example");
    case 'drush:mongodb-recreate':
      return dt('Recreate mongodb collections. Options: all(by default) - all collections, user - user collection, docs - documents collection.');

    case 'drush:mongodb-site-regenerate-tdm':
      return dt('Regenerate TdM. Options: all(by default) - all types of document, batire_texte_officiel - TO,
                 batire_feuillet_mobile - FM, batire_livres - Livres, batire_texte_normatifs - TN,
                 batire_codes - Codes, batire_complement_technique - CT, batire_actualite - Actu, batire_document_reference - DR.');
  }
}

/**
 * Drush callback; Start the mongodb shell.
 */
function drush_mongodb_cli($alias = 'default') {
  $command = _drush_mongodb_connect($alias);
  drush_print(proc_close(proc_open(escapeshellcmd($command), array(0 => STDIN, 1 => STDOUT, 2 => STDERR), $pipes)));
}

/**
 * Drush callback; Return the connect string.
 */
function drush_mongodb_connect($alias = 'default') {
  $command = _drush_mongodb_connect($alias);
  drush_print($command);
}

/**
 * Drush callback; Execute a query against a mongodb.
 */
function drush_mongodb_query($alias = 'default', $query = '') {
  $command = _drush_mongodb_connect($alias);
  $command .= " --eval '$query'";
  drush_print(escapeshellcmd($command));
  drush_print(proc_close(proc_open(escapeshellcmd($command), array(0 => STDIN, 1 => STDOUT, 2 => STDERR), $pipes)));
}

/**
 * Drush callback; Recreate mongodb collections.
 */
function drush_mongodb_recreate($rtype = 'all') {
  batire_site_mongo_recreate($rtype);
  drush_print('Collection(s) recreated.');
}

/**
 * Returns the basic shell command string.
 */
function _drush_mongodb_connect($alias) {
  $connections = variable_get('mongodb_connections', array());
  $connections += array('default' => array('host' => 'localhost', 'db' => 'drupal'));
  if (!isset($connections[$alias])) {
    $alias = 'default';
  }
  $connection = $connections[$alias];
  $host = $connection['host'];
  $db = $connection['db'];

  $query = $host;
  $query .= '/' . $db;

  $command = 'mongo '. $query;
  return $command;
}

/**
 * Drush callback; Print the config of the mongodb.
 */
function drush_mongodb_conf($alias = 'default') {
  $connections = variable_get('mongodb_connections', array());
  $connections += array('default' => array('host' => 'localhost', 'db' => 'drupal'));

  if (drush_get_option('all', FALSE)) {
    $specs = $connections;
  }
  else {
    $specs = $connections['default'];
  }
  if (!isset($specs)) {
    $specs = array();
  }

  drush_print_r($specs);
}

/**
 * Drush callback; Print the config of the mongodb.
 */
function drush_mongodb_site_regenerate_tdm($type = 'all') {
  mongodb_site_recreate_summary($type);
  drush_print_r(t('@type was regenerated successfully', array('@type' => $type)));
}

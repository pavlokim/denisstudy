<?php

/**
 * @file                                                                                                                                                                                                           
 *   Features module drush integration.                                                                                                                                                                            
 */

/**
 * Implementation of hook_drush_command().
 *
 * look drush_parse_command() for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function batire_xml_parse_drush_command() {
  $items = array();
  $items['bxp-zip-process'] = array(
    'callback' => 'drush_batire_xml_parse_zip_process',
    'aliases' => array('zip-process'),
    'description' => 'Process given zip archive with documents right now',
    'arguments' => array(
      'path' => 'Path to archive. Can be absolute or relative of drupal root.'
    ),
    'options' => array(
      'clean-first' => 'Try to clean old junk first',
      'generate-content' => 'Generate content after import',
      'show-errors' => 'Display errors'

    )
  );
  $items['bxp-zip-clean-junk'] = array(
    'callback' => 'drush_batire_xml_parse_clean_junk',
    'aliases' => array('clean-junk'),
    'description' => 'Remove junk which leave some another process zip processing job',
    'arguments' => array(
      'path' => 'Path to archive or junk folder name'
    )
  );
  $items['bxp-erase'] = array(
    'callback' => 'drush_batire_xml_parse_erase',
    'aliases' => array('nodes-erase'),
    'description' => 'Erace all nodes of selected type integrated by parser.',
    'arguments' => array(
      'type' => 'Content type'
    )
  );
  $items['bxp-generate-queued-content'] = array(
    'callback' => 'drush_batire_xml_parse_generate_queued_content',
    'description' => 'Generate queued content',
    'arguments' => array(
      'limit' => 'how many content we must generate for one time'
    )
  );
  $items['bxp-generate-content'] = array(
    'callback' => 'drush_batire_xml_parse_generate_content',
    'description' => 'Generate content for selected nodes',
    'arguments' => array(
      'nids' => 'NIDS separated by comma'
    )
  );
  $items['bxp-regenerate-content'] = array(
    'description' => 'Re-generate content for specified documents',
    'aliases' => array('regenerate-content'),
    'arguments' => array(
      'docs' => 'NIDS or BIDS separated by comma'
    )
  );
  return $items;
}


/**
 * Drush callback; Content re-generation tool.
 * $ drush regenerate-content
 */
function drush_batire_xml_parse_bxp_regenerate_content($arg_nids = NULL) {
  $generation_job_size = 250; // variable_get('batire_xml_parse_job_size', 10)*5;
  $generation_type     = 'empty';

  while (!empty($generation_type)) {
    $generation_types = array(
      'full'    => 'Full re-generation',
      'by_type' => 'Re-generate custom types',
      'by_bid'  => 'Re-generate specified bids/nids',
    );

    if (!empty($arg_nids)) {
      $generation_type = 'by_bid';
    }
    else {
      $generation_type = drush_choice($generation_types, "\nSelect re-generation type:");
    }

    switch ($generation_type) {
      case 'full':
        $types = batire_site_get_document_types_list();

        drush_print("\nNext document types will be re-generated:");
        foreach ($types as $type) {
          drush_print($type, 2);
        }

        $confirm = drush_choice(array(
            'yes' => 'Yes, re-generate this document types'),
          "\nAre you sure?");

        if ($confirm == 'yes') {
          drush_print("\nFetching nids... ", 0, NULL, FALSE);

          $stypes_sql = "'" . implode("','", batire_site_document_types_list()) . "'";
          $query  = 'SELECT nid FROM {node} WHERE type IN(' . $stypes_sql . ') AND status = 1';
          $result = db_query($query);
          $nids   = array();
          while ($node = db_fetch_object($result)) {
            $nids[] = $node->nid;
          }
          drush_print('Total: ' . count($nids));

          drush_print('Adding nodes to generation queue. Please wait... ', 0, NULL, FALSE);
          $start = (float) array_sum(explode(' ',microtime()));
          foreach ($nids as $key => $nid) {
            batire_xml_parse_queue_content($nid);
          }
          $end = (float) array_sum(explode(' ',microtime()));
          drush_print('Done, time: '. sprintf('%.4f', ($end-$start)).' seconds');

          $i = 0;
          $chunked_nids = array_chunk($nids, $generation_job_size);
          drush_print('Adding process queue jobs... ', 0, NULL, FALSE);
          foreach($chunked_nids as $chunk) {
            job_queue_add("batire_xml_parse_process_queue_content_by_nids",  'Content re-generation', array($chunk));
            $i++;
          }

          drush_print("$i jobs succesfully added\n");
          unset($nids);
        }

        break;

      case 'by_type':
        $types = batire_site_get_document_types_list();

        $options = array();
        foreach ($types as $key => $type) {
          $options[$key] = $type;
        }
        $options['delay'] = 'Add re-generation job for selected types';

        $stype  = 'empty';
        $stypes = $options2 = array();
        while (!empty($stype) && $stype != 'delay') {
          foreach ($options as $key => $option) {
            if ($key != 'delay') {
              if (in_array($key, $stypes)) {
                $options2[$key] = '[*] ' . $option;
              }
              else {
                $options2[$key] = ' [ ] ' . $option;
              }
            }
            else {
              $options2[$key] = $option;
            }
          }

          $stype = drush_choice($options2, "\nSelect types:");
          if (!empty($stype)) {
            if (in_array($stype, $stypes)) {
              foreach ($stypes as $key => $init) {
                if ($init == $stype) {
                  unset($stypes[$key]);
                }
              }
            }
            else {
              $stypes[] = $stype;
            }
          }
        }

        if (in_array('delay', $stypes)) {
          array_pop($stypes);

          if (!empty($stypes)){
            drush_print("\nFetching nids... ", 0, NULL, FALSE);
            $stypes_sql = "'" . implode("','", $stypes) . "'";
            $query  = 'SELECT nid FROM {node} WHERE type IN(' . $stypes_sql . ') AND status = 1';
            $result = db_query($query);
            $nids   = array();
            while ($node = db_fetch_object($result)) {
              $nids[] = $node->nid;
            }
            drush_print('Total: ' . count($nids));

            drush_print('Adding nodes to generation queue. Please wait... ', 0, NULL, FALSE);
            $start = (float) array_sum(explode(' ',microtime()));
            foreach ($nids as $key => $nid) {
              batire_xml_parse_queue_content($nid);
            }
            $end = (float) array_sum(explode(' ',microtime()));
            drush_print('Done, time: '. sprintf('%.4f', ($end-$start)).' seconds');

            $i = 0;
            $chunked_nids = array_chunk($nids, $generation_job_size);
            drush_print('Adding process queue jobs... ', 0, NULL, FALSE);
            foreach($chunked_nids as $chunk) {
              job_queue_add("batire_xml_parse_process_queue_content_by_nids",  'Content re-generation', array($chunk));
              $i++;
            }

            drush_print("$i job(s) succesfully added\n");
            unset($nids);
          }
          else {
            drush_print("No document types selected\n");
          }
        }

        break;

      case 'by_bid':
        if (!empty($arg_nids)) {
          $promt = $arg_nids;
          unset($arg_nids);
        }
        else {
          $promt = drush_prompt('Please enter nids/bids, separated with comma');
        }
        $promt = str_replace(' ', '', $promt);

        if (!empty($promt)) {
          $ids = explode(',', $promt);
          $nids = array();
          foreach ($ids as $id) {
            if (!empty($id)) {
              if (is_numeric($id)) {
                $nids[] = $id;
              }
              else {
                $nid = batire_hierarchy_get_by_bid($id, 'nid');
                if (!empty($nid)) {
                  $nids[] = $nid;
                }
              }
            }
          }

          if (count($nids)) {
            $stype = drush_choice(array(
                'start' => 'Start now',
                'delay' => 'Add generation job to queue'),
              'Re-generation style:');

            switch ($stype) {
              case 'start':
                drush_print("Re-generation started... ", 0, NULL, FALSE);

                foreach ($nids as $nid) {
                  batire_xml_parse_queue_content($nid);
                }

                batire_xml_parse_process_queue_content_by_nids($nids);

                drush_print("Completed.\n");
                break;
              case 'delay':
                foreach ($nids as $nid) {
                  batire_xml_parse_queue_content($nid);
                }

                $chunked_nids = array_chunk($nids, $generation_job_size);
                foreach($chunked_nids as $chunk) {
                  job_queue_add("batire_xml_parse_process_queue_content_by_nids",  'Content re-generation', array($chunk));
                }

                drush_print("Delayed job added.\n");
                break;
              default:
                drush_print("Re-regeneration canceled.\n");
                break;
            }
          }
          else {
            drush_print("No nid/bid specified.\n");
          }
        }
        else {
          drush_print("No nid/bid.\n");
        }

        break;
    }
  }
}

function drush_batire_xml_parse_erase($type) {
  global $user;
  if (!$user->uid) {
    $user = user_load(1);
  }
  $remove_empty = drush_get_option('remove-empty');
  if ($remove_empty) {
    $result = db_query("SELECT nid from {node} WHERE `type` = ''");
  } else {
    $result = db_query("SELECT nid from {node} WHERE `type` = '%s'", $type);
  }
  while ($row = db_fetch_object($result)) {
    node_delete($row->nid);
  }
}

/**
 * Process one zip file
 *
 * @param string $file_path
 */
function drush_batire_xml_parse_zip_process($file_path = NULL) {
  $zip_files = array();
  $tot_result = array();
  $verbose = _drush_batire_xml_parse_verbose_handler();
  $generate_content = drush_get_option('generate-content');
  
  if (is_file($file_path)) {
    $zip_files[] = $file_path;
  } else {
    $folder_scan = file_scan_directory($file_path, '.zip');
    if ($folder_scan) {
      // Sort files array
      ksort($folder_scan);
      foreach ($folder_scan as $zip_name) {
        if (!is_file($zip_name->filename)) {
          continue;
        }
        $zip_files[] = $zip_name->filename;
      }
    }
  }
  foreach ($zip_files as $file) {
    if (!is_readable($file)) {
      drush_set_error(DRUSH_FRAMEWORK_ERROR, "$file is not readable.");
      return FALSE;
    }
    
    if (strtolower(substr($file, -4)) != '.zip') {
      drush_set_error(DRUSH_FRAMEWORK_ERROR, "Invalid file extension, zip archives only can be accepted.");
      return FALSE;
    }
    if (drush_get_option('clean-first')) {
      drush_batire_xml_parse_clean_junk($file, FALSE);
    }
    try {
      drush_print('Start process with archive: '.$file);
      $result = batire_xml_parse_process_archive_file($file, $generate_content);
    } catch (Batire_Xml_Parse_Exception $e) {
      drush_set_error(DRUSH_FRAMEWORK_ERROR, $e->getMessage());
      return FALSE;
    }
    if (!is_array($result)) {
      drush_set_error(DRUSH_FRAMEWORK_ERROR, (string) $result);
      return FALSE;
    }
    //memory freeing
    foreach ($result as &$item) {
      $item = array("errors" => $item["errors"]);
    }
    node_load(FALSE, FALSE, TRUE);
    drupal_static('batire_xml_parse_add_new_file', NULL, TRUE);
    
    $tot_result[] = array('zip_file' => $file, 'result' => $result);
  }
  
  $tot_imported = $tot_errors = 0;
  foreach ($tot_result as $result) {
    drush_print('Archive:'.$result['zip_file']);
    $imported = $errors = 0;
    foreach ($result['result'] as $name => $item) {
      if ($item['errors']) {
        $errors++;
        if ($verbose || drush_get_option('show-errors')) {
          drush_print("Error($name): " . implode("; ", $item['errors']));
        }
      } else {
        if ($verbose) {
          drush_print("Imported: $name");
        }
        $imported++;
      }
    }
    drush_print(t('@imported files imported, @errors errors', array('@imported' => $imported, '@errors' => $errors)));
    $tot_imported += $imported;
    $tot_errors += $errors;
  }
  drush_print("\n--------------------------------------------\n");
  drush_print(t('Total imported files: @imported, @errors errors', array('@imported' => $tot_imported, '@errors' => $tot_errors)));
  
  
  return TRUE;
}

/**
 * Remove junk which leave some another process zip processing job
 *
 * @param string $file_path Path to zip file
 * @param bool $silent
 */
function drush_batire_xml_parse_clean_junk($file_path = NULL, $silent = TRUE) {
  $temporary_folder = variable_get('batire_xml_parse_temporary_folder', BATIRE_XML_PARSE_DEFAULT_TEMPORARY_FOLDER);
  if (strtolower(substr($file_path, -4)) != ".zip") {
    if (basename($file_path) != $file_path) {
      drush_set_error(DRUSH_FRAMEWORK_ERROR, t("Please read manual, unknown archive or folder id"));
      return FALSE;
    }
    $temporary_subfolder = $temporary_folder . '/' . $file_path;
    batire_site_file_unmanaged_delete_recursive($temporary_subfolder);
    if (!$silent) {
      drush_print("Done");
    }
    return TRUE;
  } else {
    $archive_id = basename($file_path, ".zip") . '-' . md5($file_path);
    return drush_batire_xml_parse_clean_junk($archive_id);
  }
}

function _drush_batire_xml_parse_verbose_handler() {
  $verbose = drush_get_option('verbose', FALSE);
  if ($verbose) {
    global $conf;
    $conf['batire_xml_parse_drush_verbose'] = TRUE;
  }
  return $verbose;
}

function drush_batire_xml_parse_generate_queued_content($limit = 100) {
  $result = batire_xml_parse_process_queue_content($limit);
  drush_print("Generated: $result[0]\n");
  if ($result[1]) {
    drush_print("Errors:");
    foreach ($result[1] as $id => $error) {
      drush_print(" $id: " . print_r($error, TRUE));
    }
  }
  return TRUE;
}

function drush_batire_xml_parse_generate_content($nids) {
  $nids = explode(',', $nids);
  foreach ($nids as $nid) {
    $data = array();
    batire_xml_parse_generate_content($nid, $data, FALSE);
    echo "$nid: " . ($data["errors"] ? print_r($data['errors'], TRUE): "Ok") . "\n";
  }
}
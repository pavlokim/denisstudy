<?php

/**
 * @file
 * Provide drush integration for Antidot export
 *
 * @Todo
 *  Check whether the alias argument is used.
 */

/**
 * Implementation of hook_drush_help().
 */
function batire_antidot_export_drush_help($section) {
  switch ($section) {
    case 'drush:antidot-export':
      return dt("Usage: drush [options] antidot-export ctype - ctype is Drupal document content type machine name");
    case 'drush:antidot-export-as-init':
      return dt("Usage: drush [options] antidot-export-as-init");
  }
}

/**
 * Implementation of hook_drush_command().
 */
function batire_antidot_export_drush_command() {
  $items['antidot-export'] = array(
    'description' => 'Antidot initial export.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_LOGIN,
    'arguments' => array(
      'ctype' => 'Export content type.',
    ),
  );

  return $items;
}

/**
 * Drush callback; Start initial import to Antidot.
 */
function drush_batire_antidot_export_antidot_export($ctype = '') {
  $export_type  = 'empty';
  while (!empty($export_type)) {
    $export_types = array(
      'as_init'  => 'Select as init',
      'full'     => 'Full re-export',
      'selected' => 'Custom re-export types',
      'by_bid'   => 'Re-export specified bids/nids',
    );

    $export_type = drush_choice($export_types, 'Select re-export type:', '!value');
    $types       = batire_site_get_document_types_list();

    switch ($export_type) {
      case 'as_init' :
        $options = array();
        $initial = variable_get('batire_antidot_export_initial', array());
        $ctype   = 'empty';
        while (!empty($ctype)) {
          foreach ($types as $key => $option) {
            $cat_name = _batire_antidot_export_get_category($key);
            if (in_array($cat_name, $initial)) {
              $options[$cat_name] = '[' . batire_antidot_export_drush_color_text('*') . '] ' . $cat_name;
            }
            else {
              $options[$cat_name] = '[ ] ' . $cat_name;
            }
          }
          $options = array_unique($options);

          $ctype = drush_choice($options, 'Select next import as initial for.', '!value');
          if (!empty($ctype)) {
            if (in_array($ctype, $initial)) {
              foreach ($initial as $key => $init) {
                if ($init == $ctype) {
                  unset($initial[$key]);
                }
              }
            }
            else {
              $initial[] = $ctype;
            }
            variable_set('batire_antidot_export_initial', $initial);
          }
        }
        module_invoke_all('flush_caches');
        drush_print('Data saved.');
        break;
      case 'full' :
        $ctypes = array();
        $initial = variable_get('batire_antidot_export_initial', array());
        foreach ($types as $key => $option) {
          $cat_name = _batire_antidot_export_get_category($key);
          if (in_array($cat_name, $initial)) {
            $ctypes[$cat_name] = '[' . batire_antidot_export_drush_color_text('full', 'red') . '] ' . $cat_name;
          }
          else {
            $ctypes[$cat_name] = '[' . batire_antidot_export_drush_color_text('diff', 'yellow') . '] ' . $cat_name;
          }
        }

        drush_print('This content type will be re-exported:');
        $ctypes = array_unique($ctypes);
        foreach ($ctypes as $ctype) {
          drush_print($ctype);
        }

        $option = array('start' => 'Start now', 'delay' => 'Delay job');

        $stype = drush_choice($option, 'Re-export style:', '!value');

        switch ($stype) {
          case 'delay':
            drush_print('Delayed job added.');
            foreach ($ctypes as $key => $job) {
              if ($key != 'delay') {
                if (in_array($key, $initial)) {
                  job_queue_add("batire_antidot_export_initial_start",  'Antidot re-export documents of type ' . $key, array($key, 0, 'drush', TRUE));
                }
                else {
                  job_queue_add("batire_antidot_export_initial_start",  'Antidot re-export documents of type ' . $key, array($key, 0, 'drush', TRUE, 'diff', 'edit'));
                }
              }
            }
            variable_set('batire_antidot_export_initial', array());
            module_invoke_all('flush_caches');
            break;
          case 'start':
            drush_print('Starting export.');
            foreach ($ctypes as $key => $job) {
              if ($key != 'start') {
                if (in_array($key, $initial)) {
                  batire_antidot_export_initial_start($key, 0, 'drush', TRUE);
                }
                else {
                  batire_antidot_export_initial_start($key, 0, 'drush', TRUE, 'diff', 'edit');
                }
              }
            }
            variable_set('batire_antidot_export_initial', array());
            module_invoke_all('flush_caches');
            break;
          default:
            drush_print('Re-export canceled.');
            break;
        }
        break;
      case 'selected' :
        $options = array();
        $initial = variable_get('batire_antidot_export_initial', array());
        foreach ($types as $key => $option) {
          $cat_name = _batire_antidot_export_get_category($key);
          if (in_array($cat_name, $initial)) {
            $options[$cat_name] = '[' . batire_antidot_export_drush_color_text('full', 'red') . '] ' . $cat_name;
          }
          else {
            $options[$cat_name] = '[' . batire_antidot_export_drush_color_text('diff', 'yellow') . '] ' . $cat_name;
          }
        }
        $options = array_unique($options);
        $options['start'] = 'Start now';
        $options['delay'] = 'Delay job';

        $stype   = 'empty';
        $stypes = $options2 = array();
        while (!empty($stype) && $stype != 'start' && $stype != 'delay') {
          foreach ($options as $key => $option) {
            if ($key != 'start' && $key != 'delay') {
              if (in_array($key, $stypes)) {
                $options2[$key] = '[' . batire_antidot_export_drush_color_text('*') . '] ' . $option;
              }
              else {
                $options2[$key] = '[ ] ' . $option;
              }
            }
            else {
              $options2[$key] = $option;
            }
          }

          $stype = drush_choice($options2, 'Select types', '!value');
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
          drush_print('Delayed job added.');
          foreach ($stypes as $job) {
            if ($job != 'delay') {
              if (in_array($job, $initial)) {
                job_queue_add("batire_antidot_export_initial_start",  'Antidot re-export documents of type ' . $job, array($job, 0, 'drush', TRUE));
              }
              else {
                job_queue_add("batire_antidot_export_initial_start",  'Antidot re-export documents of type ' . $job, array($job, 0, 'drush', TRUE, 'diff', 'edit'));
              }
            }
          }
        }
        elseif (in_array('start', $stypes)) {
          drush_print('Starting export.');
          foreach ($stypes as $job) {
            if ($job != 'start') {
              if (in_array($job, $initial)) {
                batire_antidot_export_initial_start($job, 0, 'drush', TRUE);
              }
              else {
                batire_antidot_export_initial_start($job, 0, 'drush', TRUE, 'diff', 'edit');
              }
            }
          }
        }
        else {
          drush_print('Re-export canceled.');
        }
        break;
      case 'by_bid' :
        $promt = drush_prompt('Please enter nids/bids, separated with comma');
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
            $etats = array(
              'add'    => 'Add',
              'edit'   => 'Edit',
              'delete' => 'Delete',
            );
            $etat = drush_choice($etats, 'Select etat for selected documents', '!value');

            if (!empty($etat)) {
              $stype = drush_choice(array('start' => 'Start now', 'delay' => 'Delay job'), 'Re-export style:', '!value');

              switch ($stype) {
                case 'delay':
                  drush_print('Delayed job added.');
                  job_queue_add("_batire_antidot_export_job_run",  'Antidot ' . $etat . ' documents', array($nids, $etat));
                  break;
                case 'start':
                  drush_print('Starting export.');
                  _batire_antidot_export_job_run($nids, $etat);
                  break;
                default:
                  drush_print('Re-export canceled.');
                  break;
              }
            }
            else {
              drush_print('Re-export canceled.');
            }
          }
          else {
            drush_print('No nid/bid specified.');
          }
        }
        else {
          drush_print('No nid/bid.');
        }
        break;
    }
  }
}

function batire_antidot_export_drush_color_text($text, $color = 'green') {
  switch ($color) {
    case 'green' :
      $color = "\033[32;40m\033[1m%s\033[0m";
      break;
    case 'yellow' :
      $color = "\033[33;40m\033[1m%s\033[0m";
      break;
    case 'red' :
      $color = "\033[31;40m\033[1m%s\033[0m";
      break;
  }
  return sprintf($color, $text);
}
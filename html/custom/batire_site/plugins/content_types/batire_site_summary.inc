<?php
/**
 * @file
 * Site summary functionality
 */

/**
 * Callback function to supply a list of content types.
 */
function batire_site_batire_site_summary_ctools_content_types() {
  return array(
    'single'      => TRUE,
    'title'       => t('Batire summary'),
    'description' => t('Summary for documents'),
    'icon'        => '',
    'category'    => t('Batire'),
    'defaults'    => array(),
  );
}

/**
 * Output function for the 'batire_site_summary' content type.
 */
function batire_site_batire_site_summary_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  if (!$replace_user = batire_gc_ip_replace_user()) {
    $replace_user = $user;
  }

  $block = new stdClass();

  $args = arg();
  if (isset($args[1]) && !empty($args[1])) {
    _batire_site_set_cookie('summary_last_fid', $args[1], time()+60*60*24);
    $selection = $args[1];
  }
  else {
    $selection = _batire_site_get_cookie('summary_last_fid');
  }

  $demo = isset($_GET['type']) && $_GET['type'] == 'demo';
  if ($demo) {
    $selection = '';
  }

  $sel_node = FALSE;
  $sel_tid  = '';

  if (!empty($selection)) {
    $sel_page = mongodb_page_get_page_by_bid($selection);
    $sel_nid  = $sel_page['nid'];
    $sel_node = node_load($sel_nid);
    if ($sel_node->nid) {
      if ($sel_node->type == BATIRE_SITE_CT_TN) {
        foreach ($sel_node->taxonomy as $sel_tax) {
          if ($sel_tax->vid == BATIRE_SITE_VID_NORMATIF) {
            $sel_tid = $sel_tax->tid;

            break;
          }
        }
      }
    }
  }

  $t_list = _batire_antidot_export_get_priorite('', TRUE);
  ksort($t_list);
  $t_list = array_reverse($t_list, TRUE);
  $types = array();

  drupal_add_js(
    array(
      'batire_site_summary' => array(
        'preload_url' => url('js/batire_site_summary'),
      )
    ), 'setting'
  );

  foreach ($t_list as $type) {
    $keys = array('type' => $type);
    $data = mongodb_select_one(MONGODB_SITE_SUMMARY_COLLECTION, $keys);
    if (isset($data['sub_level']) && module_exists('batire_user_products') && batire_user_products_should_filter($replace_user->uid)) {
      _batire_site_summary_filter_products($data['sub_level'], $replace_user->uid, NULL);
    }
    if (isset($data['type'])) {
      switch ($type) {
        case BATIRE_SITE_CT_TN:
          $tids = taxonomy_get_tree(BATIRE_SITE_VID_NORMATIF);
          foreach ($tids as $tid) {
            if (isset($data['sub_level'][$tid->tid]) && $data['sub_level'][$tid->tid]['cnt'] > 0) {
              if ($sel_tid == $tid->tid) {
                $render = _batire_site_render_summary_level($data['sub_level'][$tid->tid], 0, $tid->tid, TRUE, BATIRE_SITE_CT_TN . ':' . $tid->tid, FALSE, FALSE);
              }
              else {
                $render = _batire_site_render_summary_level($data['sub_level'][$tid->tid], 0, $tid->tid, FALSE, BATIRE_SITE_CT_TN . ':' . $tid->tid, FALSE, FALSE, TRUE);
              }
              if ($render['html']) {
                $types[] = $render['html'];
              }
            }
          }
          break;
        case BATIRE_SITE_CT_CODE:
          $main_tid = _batire_site_ct_tid_map($type, TRUE);
          if ($sel_node && $sel_node->type == $data['type']) {
            $render = _batire_site_render_summary_level($data, 0, $main_tid, TRUE, NULL, FALSE, FALSE, FALSE, FALSE, 1);
          }
          else {
            $render = _batire_site_render_summary_level($data, 0, $main_tid, TRUE, NULL, FALSE, FALSE, FALSE, FALSE, 1);
          }

          if ($render['html']) {
            $types[] = $render['html'];
          }
          break;
        default:
          $tid = _batire_site_ct_tid_map($type, TRUE);

          if ($sel_node && $sel_node->type == $data['type']) {
            $render = _batire_site_render_summary_level($data, 0, $tid, TRUE);
          }
          else {
            $render = _batire_site_render_summary_level($data, 0, $tid, FALSE);
          }

          if ($render['html']) {
            $types[] = $render['html'];
          }
          break;
      }
    }
  }

  $body = theme('item_list', $types, NULL, 'ul', array('class' => 'list'));

  drupal_add_js(drupal_get_path('module', 'batire_site') . '/scripts/batire_site.summary.js');

  if ($demo) {
    drupal_add_js(array('tdm' => array('demo' => TRUE)), 'setting');
    if (isset($_GET['p'])) {
      drupal_add_js(array('tdm' => array('products' => $_GET['p'])), 'setting');
    }
  }

  $form = '';
  if (module_exists('batire_user_products') && (batire_user_products_should_filter($replace_user->uid) || ($demo && !isset($_GET['p'])))) {
    $form = drupal_get_form('batire_site_summary_filter_form');
  }

  if ($replace_user->uid ==1) {
    $form = drupal_get_form('batire_site_summary_clear_cache_form');
  }

  $block->content = theme('batire_site_summary', $form, $body);

  return $block;
}

/**
 * TdM filtering form
 */
function batire_site_summary_filter_form() {
  $form = array();

  $commercial = batire_gc_commercial_is_gc_commercial();
  $demo = isset($_GET['type']) && $_GET['type'] == 'demo';

  $form['limit'] = array(
    '#type' => 'checkbox',
    '#title' => $commercial || $demo ? t('Limiter la table des matières aux contenus de produits') : t('Limiter la table des matières aux contenus de mon abonnement'),
    '#attributes' => array(
      'class' => $commercial || $demo ? 'show-products-popup' : 'reinit-tdm',
    ),
  );

  $form['#theme'] = 'batire_site_summary_filter_form';

  return $form;
}

/**
 * TdM clear cache form
 */
function batire_site_summary_clear_cache_form() {
  $form = array();

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Rebuild TDM cache'),
    '#attributes' => array (
      'class' => 'tdm-button tdm-button-blue',
    )
  );

  return $form;
}

/*
 * Implementation function of TDM cache rebuild
 * Now it's just for Codes only
 */
function batire_site_summary_clear_cache_form_submit($form, &$form_state) {
  $types = array(BATIRE_SITE_CT_CODE);
  foreach ($types as $type) {
    switch ($type) {
      case BATIRE_SITE_CT_CODE:
        cache_clear_all($type, 'cache_tdm', TRUE);
        cache_clear_all('*', 'cache_page', TRUE);
        $tids = taxonomy_get_tree(BATIRE_SITE_VID_CODES);
        foreach ($tids as $tid) {
          job_queue_add("batire_site_summary_build_job_run", 'Rebuild the TDM cache', array($type, $tid->tid, array(), TRUE));
        }
        break;
    }
  }
  return $form;
}

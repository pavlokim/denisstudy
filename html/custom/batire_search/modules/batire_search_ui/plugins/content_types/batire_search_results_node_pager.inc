<?php

/**
 * @file
 *  batire_search_results_node_pager.inc
 * Create pager for node (document)
 */

/**
 * Implementation of hook_contant_type_ctools_content_types().
 */
function batire_search_ui_batire_search_results_node_pager_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Batire search results node (document) pager'),
    'description' => t('Pager for node (document) results page'),
    'icon' => '',
    'category' => t('Batire'),
    'defaults' => array(),
  );
}

/**
 * Implementation of hook_content_type_content_type_render().
 */
function batire_search_ui_batire_search_results_node_pager_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = '';
  $args = arg();
  if ($args[0] == 'node' && is_numeric($args[1])) {
    $node = node_load($args[1]);
    if (isset($node->nid) && _batire_site_is_document($node->type)) {
      $block->content = batire_search_ui_document_pager_render($node, $args);
    }
  }
  return $block;
}

/**
 * Render document search pager
 * @param type $node
 * @return null
 */
function batire_search_ui_document_pager_render($node, $args) {
  $output = &drupal_static(__FUNCTION__, '');
  if (isset($output) && !empty($output)) {
    return $output;
  }
  if (!empty($_GET['sl'])) {
    $sid = explode('-', $_GET['sl']);
    $r_sid = (isset($sid[1])) ? $sid[1] : NULL;
    $pager = batire_search_run_search($sid[0], $r_sid);
    _batire_search_ui_document_pager_prepare($pager);
  
    if (mongodb_search_find_search_id($sid[0]) && $pager && _batire_search_ui_document_pager_is_doc_search($pager, $node->nid)) {
      // back links
      $url = 'recherche-avancee/resultats/' . $sid[0]; // back url
      $back_query = batire_search_generate_facet_query($sid[0]);
      $storage = batire_search_get_storage_data();
      $page = $storage['search_pager'];
      $links = array();

      if (!empty($sid[1]) && mongodb_search_find_search_id($sid[1])) {
        if ($page) {
          $back_query = !empty($back_query) ? $back_query . '&page=' . $page : 'page=' . $page;
        }
        $links[] = l(t('Retour à la liste des documents sélectionnés'), $url . '/' . $sid[1], array('query' => $back_query));

        drupal_add_js(array(
          'batire_search_ui' => array(
            'search_rsid' => $sid[1],
          )
        ), 'setting'
        );
      }
      $search_pp = $pager->feed == 'IMAGES' ? $storage['search_pp_images'] : $storage['search_pp'];
      if (isset($pager->total) && $pager->total > $search_pp && (!isset($sid[1]) || !mongodb_search_find_search_id($sid[1]))) {
        if ($page) {
          $back_query = !empty($back_query) ? $back_query . '&page=' . $page : 'page=' . $page;
        }
      }
      $links[] = l(t('Retour à la liste de résultats'), $url, array('query' => $back_query));
      drupal_add_js(array(
        'batire_search_ui' => array(
          'search_sl' => $_GET['sl'],
          'search_sid' => $sid[0],
        )
      ), 'setting'
      );
      $render_links = theme('item_list', $links);

      // DOCS PAGER
      $doc_list_links = array();

      $render_doc_links = NULL;

      if (isset($pager->pager_list)) {
        $next_doc = _batire_search_ui_document_pager_get_next_doc($pager, $node->nid, $page);
        $prev_doc = _batire_search_ui_document_pager_get_prev_doc($pager, $node->nid, $page);
        $request_url = $_GET;
        unset($request_url['q']);
        if(isset($request_url['page'])) {
          unset($request_url['page']);
        }

        if ($prev_doc) {
          if($prev_doc['page']) {
            $request_url['page'] = $prev_doc['page'];
          }
          $doc_list_links[] = l(t('Résultat : précédent'), 'node/' . $prev_doc['nid'], array('attributes' => array('class' => 'previous'), 'query' => $request_url));
        }
        if ($next_doc) {
          if($next_doc['page']) {
            $request_url['page'] = $next_doc['page'];
          }
          if ($prev_doc) {
            $doc_list_links[] = l(t('suivant'), 'node/' . $next_doc['nid'], array('attributes' => array('class' => 'next'), 'query' => $request_url));
          }
          else {
            $doc_list_links[] = l(t('Résultat : suivant'), 'node/' . $next_doc['nid'], array('attributes' => array('class' => 'next'), 'query' => $request_url));
          }
        }
        $render_doc_links = theme('item_list', $doc_list_links);
      }
    }
  }

  //TDM LINK
  if (batire_site_summary_in_tdm($node->page_data['bid'])) {
    $text = '';
    $render_links_tdm = '';

    switch ($node->type) {
      case BATIRE_SITE_CT_FM :
      case BATIRE_SITE_CT_LIVRE :
        $text = t('Table des matières de l\'ouvrage');
        break;
      case BATIRE_SITE_CT_TN :
        $text = t('Table des matières du texte normatif');
        break;
      case BATIRE_SITE_CT_CODE :
        $text = t('Tous les articles du code');
        break;
      case BATIRE_SITE_CT_COMP_TECH :
        $parution_num = (!empty($node->page_data['num_puration'])) ? $node->page_data['num_puration'] : 'XX';
        $text = t('Table des matières du n° !par_num de Complément technique', array('!par_num' => (int) $parution_num));
        break;
    }

    if ($text) {
      $render_links_tdm = theme('item_list', array(l($text, 'table-des-matieres/' . $node->page_data['bid'])));
    }
  }

  if (!empty($render_links) || !empty($render_doc_links) || !empty($render_links_tdm)) {
    $output = theme('batire_search_ui_document_pager_content', array('render_links' => $render_links, 'render_doc_links' => $render_doc_links, 'render_links_tdm' => $render_links_tdm));
  }

  return $output;
}


/**
 * Check if nid from search
 * @param $pager Search pager
 * @param $nid Node nid from results
 *
 * @return Boll TRUE|FALSE
 */
function _batire_search_ui_document_pager_is_doc_search($pager, $nid) {
  if (!empty($pager) && !empty($pager->pager_list)) {
    foreach ($pager->pager_list as $key => $item) {
      if (in_array($nid, $item)) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

/**
 * Get next doc for documents pager
 * @param $pager Search pager
 * @param $nid Node nid(document)
 * @param $page Curent number of page from peager
 *
 * @return Node nid
 */
function _batire_search_ui_document_pager_get_next_doc($pager, $nid, $page) {

  if (!empty($pager) && !empty($pager->pager_list[$page])) {
    $key = array_search($nid, $pager->pager_list[$page]);
    // calculate number of nid in all pager
    $number = ($page * $pager->per_page) + ($key + 1);
    $new_page = $page + 1;
    // get just next element
    if (isset($pager->pager_list[$page][$key + 1])) {
      return array(
          'nid' => $pager->pager_list[$page][$key + 1],
          'page' => $page,
        );
    }
    // get next element from next page of pager
    elseif (isset($pager->pager_list[$new_page]) && $page < $pager->count_pages) {
      $array = $pager->pager_list[$new_page];
      reset($array);
      return array(
          'nid' => $array[key($array)],
          'page' => $new_page,
        );
    }
    // run search for creating new list of search result page and get next nid
    elseif ($page < $pager->count_pages && $number != $pager->total) {
      $storage = batire_search_get_storage_data();
      $storage['search_pager'] = $new_page;
      $new_pager = batire_search_run_search($pager->sid, $pager->r_sid, $storage);
      _batire_search_ui_document_pager_prepare($new_pager);
      if (!empty($new_pager) && !empty($new_pager->pager_list[$new_page])) {
        if (isset($new_pager->pager_list[$new_page][0])) {
          return array(
            'nid' => $new_pager->pager_list[$new_page][0],
            'page' => $new_page,
          );
        }
      }
    }
  }
  return NULL;
}

/**
 * Get previos doc for documents pager
 * @param $pager Search pager
 * @param $nid Node nid(document)
 * @param $page Curent number of page from peager
 *
 * @return Node nid
 */
function _batire_search_ui_document_pager_get_prev_doc($pager, $nid, $page) {
  if (!empty($pager) && !empty($pager->pager_list[$page])) {
    $key = array_search($nid, $pager->pager_list[$page]);
    $new_page = $page - 1;
    // get just previos element
    if (isset($pager->pager_list[$page][$key - 1])) {
      return array(
          'nid' => $pager->pager_list[$page][$key - 1],
          'page' => $page,
        );
    }
    // get previos element from previos page of pager
    elseif (isset($pager->pager_list[$new_page]) && $page > 0) {
      $array = $pager->pager_list[$new_page];
      end($array);
      return array(
          'nid' => $array[key($array)],
          'page' => $new_page,
        );
    }
    // run search for creating new list of search result page and get previos nid
    elseif ($page > 0) {
      $storage = batire_search_get_storage_data();
      $storage['search_pager'] = $new_page;
      $new_pager = batire_search_run_search($pager->sid, $pager->r_sid, $storage);
      _batire_search_ui_document_pager_prepare($new_pager);
      if (!empty($new_pager) && !empty($new_pager->pager_list[$new_page])) {
        if (isset($new_pager->pager_list[$new_page]) && $new_pager->pager_list[$new_page]) {
          return array(
            'nid' => array_pop($new_pager->pager_list[$new_page]),
            'page' => $new_page,
          );
        }
      }
    }
  }
  return NULL;
}

function _batire_search_ui_document_pager_prepare(&$pager) {
  if($pager) {
    foreach ($pager->results as $item) {
      if(isset($item->reply)) {
        foreach ($item->reply as $reply) {
          $nid = (int) $reply->node->nid;
          if (!empty($nid) && is_numeric($nid)) {
            if ($reply->node->type == BATIRE_SITE_CT_TN) {
              $super_bid = batire_site_get_bid_of_first_texte_normatifs_part($reply->node->super_bid);
              if (!empty($pager->pager_list)) {
                foreach ($pager->pager_list as $key => $nodes) {
                  $num = array_search($nid, $nodes);
                  if ($num !== FALSE) {
                    $pager->pager_list[$key][$num] = $super_bid['nid'];
                    break;
                  }
                }
              }      
            }
          }
        }
      }
    }
  }
}

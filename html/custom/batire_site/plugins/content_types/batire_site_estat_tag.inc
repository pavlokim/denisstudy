<?php

/**
 * @file
 *   batire_site_estat_tag.inc
 * eStat tag integration
 * @see https://prj.adyax.com/issues/46089
 */


/**
 * Callback function to supply a list of content types.
 */
function batire_site_batire_site_estat_tag_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Batire eStat tag'),
    'description' => t('eStat tracking tag'),
    'icon' => '',
    'category' => t('Batire'),
    'defaults' => array(),
  );
}

/**
 * Output function for the 'batire_site_estat_tag' content type.
 */
function batire_site_batire_site_estat_tag_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $path = drupal_get_path_alias($_GET['q']);
  $path = explode('/', $path);
  switch ($path[0]) {
    case 'home':
      if ($user->uid != 0) {
        $niveau1 = 'HP_connect';
      }
      else {
        $niveau1 = 'HP_disconnect';
      }
      $niveau2 = '';
      break;
    case 'faq':
    case 'plan-du-site':
    case 'cgv':
      $niveau1 = 'Page_infos';
      $niveau2 = '';
      break;
    case 'client':
      if (isset($path[1]) && $path[1] == 'inscription') {
        $niveau1 = 'Devis';
        $niveau2 = '';
      }
      break;
    case 'demo';
      $niveau1 = 'Demo';;
      $niveau2 = '';
      break;
    case 'abo':
      $niveau1 = 'Landing_page';
      $niveau2 = '';
      break;
    case 'recherche-avancee':
      $niveau1 = 'Rech_avancee';
      if (isset($path[1]) && $path[1] == 'resultats') {
        $niveau1 = 'Liste_resultats';
      }
      $niveau2 = '';
      break;
    case 'table-des-matieres':
      $niveau1 = 'Table_matieres';
      $niveau2 = '';
      break;
    case 'toute-la-veille-des-6-derniers-mois':
      $niveau1 = 'Veille_6mois';
      $niveau2 = '';
      break;
    case 'node':
      $niveau1 = 'Mon_compte';
      $niveau2 = '';
      if (is_numeric($path[1])) {
        $bid = batire_hierarchy_get_by_nid($path[1], 'bid');
        if (!empty($bid)) {
          $niveau1 = 'Doc';
          $node = node_load($path[1]);
          $type = _batire_site_get_humanreadable_node_type($node);
          switch ($type) {
            case 'Textes officiels':
              $niveau2 = 'TO';
              break;
            case 'Codes':
              $niveau2 = 'Code';
              break;
            case 'Normes':
              $niveau2 = 'TN_Normes';
              break;
            case 'Textes normatifs':
              $niveau2 = 'TN_NFDTU';
              break;
            case 'Normes':
              $niveau2 = 'TN_Eurocode';
              break;
            case 'Règles de calcul':
              $niveau2 = 'TN_Calcul';
              break;
            case 'Livres':
              $niveau2 = 'Livres';
              break;
            case 'Complément technique':
              $niveau2 = 'Comp_Tech';
              break;
            case 'Actualité':
              $niveau2 = 'Actu';
              break;
            default:
              if ($node->type == 'batire_feuillet_mobile') {
                $niveau2 = 'Classeurs';
              }
              break;
          }
        }
      }
      break;
    default:
      $niveau1 = 'Mon_compte';
      $niveau2 = '';
      break;
  }
  $block = new stdClass();
  $block->content = theme('batire_site_estat_tag', $niveau1, $niveau2);
  return $block;
}

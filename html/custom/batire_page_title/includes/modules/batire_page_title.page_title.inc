<?php

/**
 * @file
 * Batire implementations of the page title hooks
 */

/**
 * Implementation of hook_page_title_settings().
 */
function batire_page_title_page_title_settings() {
  $settings = array();
  $settings['batire_page_title_suffix'] = array(
    'label' => t('Page title suffix'),
    'description' => t('This pattern will be appended to a page title for any pages'),
    'weight' => -51,
    'required' => TRUE,
    'default' => '',
  );

  $settings['batire_page_title_separator'] = array(
    'label' => t('Separator'),
    'description' => t('This pattern will be appended to a token list as [separator]'),
    'weight' => -51,
    'required' => TRUE,
    'default' => "-",
  );

  $settings['batire_page_title_regulatory_monitoring'] = array(
    'label' => t('Page de veille réglementaire'),
    'weight' => -47,
    'description' => t('This pattern will be used on page de veille réglementaire'),
    'default' => 'Vient de paraître [separator] [site-name] [separator] [page-title-suffix]'
  );

  $settings['batire_page_title_faq'] = array(
    'label' => t('FAQ'),
    'weight' => -46,
    'description' => t('This pattern will be used on faq page'),
    'default' => 'Informations [separator] [site-name] [separator] [page-title-suffix]'
  );

  $settings['batire_page_title_sitemap'] = array(
    'label' => t('Sitemap'),
    'weight' => -45,
    'description' => t('This pattern will be used on sitemap page'),
    'default' => 'Plan du site [separator] [site-name] [separator] [page-title-suffix]'
  );

  $settings['batire_page_title_condition_page'] = array(
    'label' => t('Pages Conditions Générales de vente'),
    'weight' => -44,
    'description' => t('This pattern will be used on pages Conditions Générales de vente'),
    'default' => "CGV [separator] [site-name] [separator] [page-title-suffix]",
  );

  $settings['batire_page_title_advanced_search'] = array(
    'label' => t('Advanced Search'),
    'description' => t('This pattern will be used on advanced search page'),
    'weight' => -43,
    'default' => "Recherche [separator] [site-name] [separator] [page-title-suffix]",
  );

  $settings['batire_page_title_search_results'] = array(
    'label' => t('Liste de résultats'),
    'weight' => -42,
    'description' => t('This pattern will be used on search result page'),
    'default' => "Tous les résultats [separator] [site-name] [separator] [page-title-suffix]",
  );

  $settings['batire_page_title_selection_list'] = array(
    'label' => t('Liste de sélections'),
    'weight' => -41,
    'description' => t('This pattern will be used on selections list page'),
    'default' => "Toutes les sélections [separator] [site-name] [separator] [page-title-suffix]",
  );

  $settings['batire_page_title_documents'] = array(
    'label' => t('Page document'),
    'scopes' => array('node', 'taxonomy'),
    'weight' => -40,
    'description' => t('This pattern will be used for all page documents'),
    'default' => "[node-human-type] [separator] [title] [separator] [site-name] [separator] [page-title-suffix]",
  );

  $settings['batire_page_title_mon_compte'] = array(
    'label' => t('Mon compte pages'),
    'weight' => -39,
    'description' => t('This pattern will be used for all mon compte page'),
    'default' => "Mon compte [separator] [site-name] [separator] [page-title-suffix]",
  );

  $settings['batire_page_title_table_content'] = array(
    'label' => t('Pages Table des matières'),
    'weight' => -38,
    'description' => t('This pattern will be used on table des matières page'),
    'default' => "Table des matières [separator] [site-name] [separator] [page-title-suffix]",
  );

  $settings['batire_page_title_other_pages'] = array(
    'label' => t('Other pages'),
    'weight' => -37,
    'required' => TRUE,
    'description' => t('This pattern will be used on each page without title'),
    'default' => '[site-name] [separator] [page-title-suffix]'
  );
  foreach ($settings as &$item) {
    $item['show field'] = FALSE;
    if (isset($item['scopes'])) {
      $item['scopes'] = array_merge($item['scopes'], array('global'));
    }
    else {
      $item['scopes'] = array('global');
    }
  }
  return $settings;
}

/**
 * Implementation of hook_page_title_pattern_alter().
 */
function batire_page_title_page_title_pattern_alter(&$pattern, &$types) {
  $args = arg();
  $settings = page_title_get_settings();
  if (drupal_is_front_page()) {
    $pattern = variable_get('page_title_front', $settings['page_title_front']['default']); // Get the frontpage pattern
    return;
  }
  switch ($args[0]) {
    case BATIRE_SITE_LAST_DOCS_PAGE_URL:
      $pattern = variable_get('batire_page_title_regulatory_monitoring', $settings['batire_page_title_regulatory_monitoring']['default']);
      return;

    case BATIRE_SITE_SITEMAP_URL:
      $pattern = variable_get('batire_page_title_sitemap', $settings['batire_page_title_sitemap']['default']);
      return;

    case BATIRE_SITE_FAQ_URL:
      $pattern = variable_get('batire_page_title_faq', $settings['batire_page_title_faq']['default']);
      return;

    case BATIRE_SITE_TABLES_CONTENT_URL:
      $pattern = variable_get('batire_page_title_table_content', $settings['batire_page_title_table_content']['default']);
      return;

    case 'recherche-avancee':
      $pattern = variable_get('batire_page_title_advanced_search', $settings['batire_page_title_advanced_search']['default']);
      switch ($args[1]) {
        case 'resultats':
          $pattern = variable_get('batire_page_title_search_results', $settings['batire_page_title_search_results']['default']);
          if (!empty($args[2]) && !empty($args[3]) && mongodb_search_find_search_id($args[3])) {
            $pattern = variable_get('batire_page_title_selection_list', $settings['batire_page_title_selection_list']['default']);
          }
          break;
      }
      return;

    case 'node':
      if (!empty($args[1]) && is_numeric($args[1])) {
        switch ($args[1]) {
          case BATIRE_SITE_CGV_NODE_NID:
            $pattern = variable_get('batire_page_title_condition_page', $settings['batire_page_title_condition_page']['default']);
            return;

          default:
            $node = node_load($args[1]);
            if (_batire_site_is_document($node->type)) {
              $pattern = variable_get('batire_page_title_documents', $settings['batire_page_title_documents']['default']);
              return;
            }
        }
      }
      break;

    case 'mon-compte':
      $pattern = variable_get('batire_page_title_mon_compte', $settings['batire_page_title_mon_compte']['default']);
      return;

    case 'admin':
      $pattern = '[page-title] [separator] [site-name] [separator] [page-title-suffix]';
      return;

    default:
      $pattern = variable_get('batire_page_title_other_pages', $settings['batire_page_title_other_pages']['default']);
      return;
  }
}
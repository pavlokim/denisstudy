<?php

/**
 * @file
 *   batire_site_neolan_tag.inc
 * Neolan tag integration
 * @see https://prj.adyax.com/issues/45854
 */


/**
 * Callback function to supply a list of content types.
 */
function batire_site_batire_site_neolan_tag_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Batire Neolan tag'),
    'description' => t('Neolan tracking tag'),
    'icon' => '',
    'category' => t('Batire'),
    'defaults' => array(),
  );
}

/**
 * Output function for the 'batire_site_neolan_tag' content type.
 */
function batire_site_batire_site_neolan_tag_content_type_render($subtype, $conf, $panel_args, $context) {
  $page_title = page_title_page_get_title();
  $page_title = str_replace(' ', '-', $page_title);
  setlocale(LC_ALL, "en_US.utf8");
  $page_title = iconv("utf-8", "ascii//TRANSLIT", $page_title);
  $page_title = 'BTC-' . preg_replace("/[^A-Za-z0-9-]/", '', $page_title) . '%7Cw';
  $block = new stdClass();
  $block->content = theme('batire_site_neolan_tag', $page_title);
  return $block;
}

<?php

/**
 * @file
 *  batire_site.pages.inc
 * Provide frontend pages
 */

/**
 * Create Sitemap page for site
 */
function batire_site_sitemap() {
  $tree = menu_tree_page_data(BATIRE_SITE_MENU_SITEMAP_NAME);
  return theme('batire_site_sitemap', $tree);
}
<?php
/**
 * @file
 *  batire_user_docs_handler_sort_date_empty.inc
 */

/**
 * Basic sort handler for dates empty.
 *
 * @ingroup views_sort_handlers
 */
class batire_user_docs_handler_sort_date_empty extends views_handler_sort {

  /**
   * Called to add the sort to a query.
   */
  function query() {
    $this->ensure_my_table();

    $sort_by = isset($_GET['sort_by']) && $_GET['sort_by'] ? $_GET['sort_by'] : FALSE;
    $sort_order = isset($_GET['sort_order']) && $_GET['sort_order'] ? drupal_strtolower($_GET['sort_order']) : FALSE;

    $allowed_orders = array('asc', 'desc');

    if (!in_array($sort_order, $allowed_orders)) {
      $sort_order = 'desc';
    }

    if ($sort_by == 'changed') {
      $base_table = 'node';
      $join = new views_join();
      $join->construct('content_field_date_vide', $base_table, 'vid', 'vid');
      $new = $this->query->add_relationship('content_field_date_vide', $join, $base_table);
      $this->query->add_orderby(NULL, NULL, $sort_order, "IFNULL($new.field_date_vide_value, 0)");
    }
  }

}
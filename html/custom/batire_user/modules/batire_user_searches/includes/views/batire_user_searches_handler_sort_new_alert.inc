<?php

/**
 * @file
 *  batire_user_docs_handler_sort_date_add.inc
 */

/**
 * Basic sort handler for dates.
 *
 * This handler enables granularity, which is the ability to make dates
 * equivalent based upon nearness.
 *
 * @ingroup views_sort_handlers
 */
class batire_user_searches_handler_sort_new_alert extends views_handler_sort {

  function option_definition() {
    $options = parent::option_definition();

    $options['granularity'] = array('default' => 'second');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  /**
   * Called to add the sort to a query.
   */
  function query() {
    // When a exposed sort is by default ASC or DESC, we have to check if
    // this value was modified. If not, we use the default value for this sort.
    if (!empty($this->options['exposed']) && isset($this->options['expose']['identifier']) && !empty($this->view->exposed_input[$this->options['expose']['identifier']])) {
      $sort = drupal_strtolower($this->view->exposed_input[$this->options['expose']['identifier']]);
    }
    else {
      $sort = drupal_strtolower($this->options['order']);
    }
    $this->query->add_orderby('node_data_field_alert_document', 'field_search_new_value', '= -1');
    $this->query->add_orderby('node_data_field_alert_document', 'field_search_new_value', $sort);
  }
}
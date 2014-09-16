<?php
/**
 * @file
 * Pager plugin with limits
 */

/**
 * The plugin to handle full pager with limit.
 *
 * @ingroup views_pager_plugins
 */
class batire_site_plugin_pager_full_limit extends views_plugin_pager_full {
  function option_definition() {
    $options = parent::option_definition();
    if (!is_array($options['expose'])) {
      $options['expose'] = array();

    }

    if (!is_array($options['expose']['contains'])) {
      $options['expose']['contains'] = array();
    }

    $options['expose']['contains']['items_per_page_options_limit'] = array('default' => '50');
    $options['expose']['contains']['items_per_page_options_limit_to'] = array('default' => '10');
    return $options;
  }

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['expose']['items_per_page_options_limit'] = array(
      '#type' => 'textfield',
      '#title' => t('Limit max items'),
      '#description' => t('Limit max outout items for productivity reasons'),
      '#default_value' => $this->options['expose']['items_per_page_options_limit'],
    );

    $form['expose']['items_per_page_options_limit_to'] = array(
      '#type' => 'textfield',
      '#title' => t('Limit max items to'),
      '#description' => t('Limit max output items to value'),
      '#default_value' => $this->options['expose']['items_per_page_options_limit_to'],
    );
  }

  function query() {
    if (!empty($_GET['items_per_page']) && $_GET['items_per_page'] > 0) {
      if ($_GET['items_per_page'] > $this->options['expose']['items_per_page_options_limit']) {
        $_GET['items_per_page'] = $this->options['expose']['items_per_page_options_limit_to'];
      }
    }
    parent::query();
  }

}

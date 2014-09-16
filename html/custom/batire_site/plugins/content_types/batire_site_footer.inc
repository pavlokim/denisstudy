<?php

/**
 * @file
 *  batire_site_footer.inc
 * Site footer functionality
 */

/**
 * Callback function to supply a list of content types.
 */
function batire_site_batire_site_footer_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Batire footer'),
    'description' => t('Footer of main page'),
    'icon' => '',
    'category' => t('Batire'),
    'edit form' => 'batire_site_footer_edit_form',
    'defaults' => array(),
  );
}

/**
 * Output function for the 'batire_site_footer' content type.
 */
function batire_site_batire_site_footer_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  // Make a new empty "block" which will be a Pane you can add to your Panel.
  $block = new stdClass();
  $titles = menu_get_menus();

  $title_1_left = $titles[$conf['footer_1_left']];
  $menu_1_left = menu_tree($conf['footer_1_left']);

  $menu_1_right = batire_site_footer_build_menu($conf['footer_1_right'], TRUE);

  $block->content = theme('batire_site_footer_auth', $title_1_left, $menu_1_left, $menu_1_right);
  if ($user->uid == 0) {

    $title_2_left = $titles[$conf['footer_2_left']];
    $menu_2_left = menu_tree($conf['footer_2_left']);
    $title_2_right = $titles[$conf['footer_2_right']];
    $menu_2_right = batire_site_footer_build_menu($conf['footer_2_right']);
    $title_3_left = $titles[$conf['footer_3_left']];
    $menu_3_left = menu_tree($conf['footer_3_left']);
    $title_3_right = $titles[$conf['footer_3_right']];
    $menu_3_right = batire_site_footer_build_menu($conf['footer_3_right']);

    $block->content .= theme('batire_site_footer_notauth', $title_2_left, $menu_2_left, $title_2_right, $menu_2_right);
    $block->content .= theme('batire_site_footer_notauth', $title_3_left, $menu_3_left, $title_3_right, $menu_3_right, TRUE);
  }
  return $block;
}

/**
 * Edit footer form
 *
 * @ingroup forms
 */
function batire_site_footer_edit_form(&$form, &$form_state) {
  $conf = $form_state['conf'];
  $menus_list = menu_get_menus();
  $form['footer_1_left'] = array(
    '#type' => 'select',
    '#title' => t('Config 1 row left'),
    '#description' => t('Menu for 1 row left side.'),
    '#options' => $menus_list,
    '#default_value' => !empty($conf['footer_1_left']) ? $conf['footer_1_left'] : '',
  );
  $form['footer_1_right'] = array(
    '#type' => 'select',
    '#title' => t('Config 1 row right'),
    '#description' => t('Menu for 1 row right side.'),
    '#options' => $menus_list,
    '#default_value' => !empty($conf['footer_1_right']) ? $conf['footer_1_right'] : '',
  );
  $form['footer_2_left'] = array(
    '#type' => 'select',
    '#title' => t('Config 2 row left'),
    '#description' => t('Menu for 2 row left side.'),
    '#options' => $menus_list,
    '#default_value' => !empty($conf['footer_2_left']) ? $conf['footer_2_left'] : '',
  );
  $form['footer_2_right'] = array(
    '#type' => 'select',
    '#title' => t('Config 2 row right'),
    '#description' => t('Menu for 2 row right side.'),
    '#options' => $menus_list,
    '#default_value' => !empty($conf['footer_2_right']) ? $conf['footer_2_right'] : '',
  );
  $form['footer_3_left'] = array(
    '#type' => 'select',
    '#title' => t('Config 3 row left'),
    '#description' => t('Menu for 3 row left side.'),
    '#options' => $menus_list,
    '#default_value' => !empty($conf['footer_3_left']) ? $conf['footer_3_left'] : '',
  );
  $form['footer_3_right'] = array(
    '#type' => 'select',
    '#title' => t('Config 3 row right'),
    '#description' => t('Menu for 3 row right side.'),
    '#options' => $menus_list,
    '#default_value' => !empty($conf['footer_3_right']) ? $conf['footer_3_right'] : '',
  );

  return $form;
}

/**
 * Submit function for footer edit form
 * @see batire_site_footer_edit_form()
 *
 * @ingroup forms
 */
function batire_site_footer_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Build footer menu
 */
function batire_site_footer_build_menu($menu, $auth = FALSE) {
  $menu_tree = menu_tree_all_data($menu);
  $menu_items = '';

  if ($auth) {
    foreach ($menu_tree as $item) {
      if (!$item['link']['hidden']) {
        $menu_items .= '<div class="items"><b>' . $item['link']['title'] . ' :</b> ';
        if (is_array($item['below'])) {

          $tmp = array();
          foreach ($item['below'] as $subitem) {
            $tmp[] = l($subitem['link']['title'], $subitem['link']['link_path'], array('html' => TRUE));
          }

          $menu_items .= implode(' | ', $tmp);
        }
        $menu_items .= '</div>';
      }
    }
  }
  else {
    $menu_items .= '<div class="items">';

    $tmp = array();
    foreach ($menu_tree as $item) {
      if (!$item['link']['hidden']) {
        $tmp[] = l($item['link']['title'], $item['link']['link_path'], array('html' => TRUE));
      }
    }
    $menu_items .= implode(' | ', $tmp);
    $menu_items .= '</div>';
  }
  return $menu_items;
}
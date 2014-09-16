<?php

/**
 * @file
 *   batire_site_homage_image.inc
 * Homage image
 * @see https://prj.adyax.com/issues/47782
 */


/**
 * Callback function to supply a list of content types.
 */
function batire_site_batire_site_homage_image_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Batire homepage image'),
    'description' => t('Homepage image'),
    'icon' => '',
    'category' => t('Batire'),
    'edit form' => 'batire_site_homepage_image_edit_form',
    'defaults' => array(
      'image'   => 'sites/all/themes/batire/files/exe-Btn_Appel_2.jpg'
    ),
  );
}

/**
 * Output function for the 'batire_site_homage_image' content type.
 */
function batire_site_batire_site_homage_image_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $block = new stdClass();
  $block->content = '';
  if ($user->uid == 0) {
    if (!isset($conf['image']) || !$conf['image']) {
      $conf['image'] = 'sites/all/themes/batire/files/exe-Btn_Appel_2.jpg';
    }
    $block->content = theme('image', $conf['image']) . '<br/><br/>';
  }
  return $block;
}

/**
 * Edit footer form
 *
 * @ingroup forms
 */
function batire_site_homepage_image_edit_form(&$form, &$form_state) {
  $conf = $form_state['conf'];

  $form['image'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to image'),
    '#description' => t('Relative path to www root.'),
    '#default_value' => !empty($conf['image']) ? $conf['image'] : $form_state['plugin']['defaults']['image'],
  );

  return $form;
}

/**
 * Submit function for footer edit form
 * @see batire_site_footer_edit_form()
 *
 * @ingroup forms
 */
function batire_site_homepage_image_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
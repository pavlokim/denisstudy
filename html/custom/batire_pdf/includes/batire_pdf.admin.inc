<?php

function batire_pdf_settings_form() {
  $form['batire_path_to_pdf_image_library'] = array(
    '#type' => 'textfield',
    '#title' => t('Path to library which converts pdf to images.'),
    '#default_value' => variable_get('batire_path_to_pdf_image_library', '/usr/bin/pdftoppm'),
  );
  $form['pdftoppm_type'] = array(
    '#type' => 'select',
    '#title' => t('pdftoppm version'),
    '#options' => array(
      'pdftoppm_without_png' => 'Without png convert',
      'pdftoppm_with_png' => 'With png convert (option -png)',
    ),
    '#default_value' => variable_get('pdftoppm_type', 'pdftoppm_without_png'),
  );
  $form['#after_build'] = array('_batire_pdf_build_version');

  return system_settings_form($form);
}

function _batire_pdf_build_version($form_element, $form_state) {
  // make sure path is set and valid before running after build.
  if ($path_errors = _imageapi_imagemagick_check_path($form_state['values']['batire_path_to_pdf_image_library'])) {
    // check here is primarily for pre-existing bad settings...
    // the #validate should prevent users from adding bad paths.
    $form_element['version'] = array(
      '#value' => '<p class="error">'. implode('<br />', $path_errors) .'</p>',
    );
  }
  else {
    module_load_include('inc', 'batire_pdf', 'includes/batire_pdf');
    _pdftoppm_convert_exec('-h', $output, $errors);
    $form_element['version'] = array(
      '#title' => t('Version information'),
      '#value' => '<pre>'. check_plain(trim($output)) .'</pre>',
    );
  }
  $form_element['version']['#type'] = 'item';
  $form_element['version']['#weight'] = -1;
  return $form_element;
}

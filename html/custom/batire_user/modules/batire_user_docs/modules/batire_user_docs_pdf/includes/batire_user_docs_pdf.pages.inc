<?php

/**
 * @file
 *  batire_user_docs_pdf.pages.inc
 * Functional for pages
 */

/**
 * Generate pdf footer for each page of document
 * @param $node Node(document)
 */
function batire_user_docs_pdf_generate_footer($node) {
  if (!$node || !$node->nid || !_batire_site_is_document($node->type)) {
    exit(); // This node is not a document
  }
  if (isset($_GET['user']) && is_numeric($_GET['user'])) {
    $profile = batire_user_profile_load($_GET['user']);
    $node->profile = $profile;
  }
  print theme('batire_user_docs_pdf_footer', $node);
  exit();
}

/**
 * Generate pdf refs for document
 * @param $node Node(document)
 */
function batire_user_docs_pdf_generate_refs($node) {
  if (!$node || !$node->nid || !_batire_site_is_document($node->type)) {
    exit(); // This node is not a document
  }
  $output = array();
  $options = _batire_user_docs_get_options();
  if (isset($options['re']) && $options['re']) {
    $output['re'] = batire_user_docs_print_reference($node);
  }
  if (isset($options['an']) && $options['an']) {
    $output['an'] = batire_user_docs_print_annotation($node->nid, $options['user']);
  }
  if (count($output)) {
    print theme('batire_user_docs_pdf_refs', $output);
  }
  exit();
}

/**
 * Generate pdf file for node
 * @param $node Node(document)
 */
function batire_user_docs_pdf_generate($node) {
  try {
    if (!$node || !$node->nid || !_batire_site_is_document($node->type)) {
      throw new Exception(t('Node is incorrect.'), BATIRE_SITE_ERROR_SYSTEM);
    }

    $start = _batire_user_docs_pdf_microtime_float();

    $options = _batire_user_docs_get_options();

    $pdf_directory = _batire_user_docs_pdf_get_directory($node);
    $pdf_file = _batire_user_docs_pdf_get_file_path($node, TRUE, $options);
    $filename = _batire_user_docs_pdf_get_tmp_file_name($node, $options);

    $lock_file = $pdf_directory . '/' . $filename . '.lock';
    $error_file = $pdf_directory . '/' . $filename . '.error';
    if (file_exists($pdf_file) || file_exists($error_file)) {
      throw new Exception(t('Pdf file exist or exist lock or error file.'), 0);
    }
    if (batire_user_docs_pdf_create_lock_file($lock_file)) {
      return TRUE;
    }

    register_shutdown_function('_batire_user_docs_pdf_generate_shutdown', $node);

    $pdf_script = variable_get('print_pdf_pdf_tool', FALSE);
    if (!$pdf_script) {
      throw new Exception(t('Script for creating pdf is not found.'), BATIRE_SITE_ERROR_SYSTEM);
    }
    $base_dir = _batire_user_docs_pdf_get_basedir();
    $pdf_fullpath = $base_dir . $pdf_script;
    $print_pdf_paper_size = variable_get('print_pdf_paper_size', 'A4');
    $print_pdf_page_orientation = variable_get('print_pdf_page_orientation', 'portrait');

    global $base_url;
    $base_url = (isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] == 'on' ? 'https' : 'http') . '://' . $_SERVER['HTTP_HOST'];

    $url = $base_url . '/' . BATIRE_USER_DOCS_PDF_PRINT_PDF_URL . '/' . $node->nid;
    $refs_url = NULL;
    if (count($options) && ($options['an'] || $options['re'])) {
      $refs_url = $base_url . '/' . BATIRE_USER_DOCS_PDF_PRINT_PDF_REFS_URL . '/' . $node->nid . _batire_user_docs_pdf_get_url_query($options);
    }
    $annotations = NULL;
    $reference = NULL;
    if ($options['an']) {
      $annotations = batire_user_docs_print_annotation($node->nid, $options['user']);
    }
    if ($options['re']) {
      $reference = batire_user_docs_print_reference($node);
    }

    $footer_url = $base_url . '/' . BATIRE_USER_DOCS_PDF_PRINT_PDF_FOOTER_URL . '/' . $node->nid . _batire_user_docs_pdf_get_url_query($options);

    $command = $pdf_fullpath . ' -s ' . $print_pdf_paper_size . ' -O ' . $print_pdf_page_orientation . ' ';
    $command .= '--disable-smart-shrinking -T 10 ';
    $command .= '--header-html "' . $footer_url . '"' . ' ';
    $command .= '"' . $url . '" ';
    if ($refs_url) {
      $command .= '"' . $refs_url . '" ';
    }
    $command .= $pdf_file;
    $command .= ' 2>&1';
    $output = array();
    $return_var = NULL;
    $result = exec($command, $output, $return_var);
    if ((int) $return_var == 0) {
      throw new Exception(t('Document (nid:!nid) generation time is !time. Command is - !command', array(
        '!time' => _batire_user_docs_pdf_microtime_float() - $start,
        '!nid' => $node->nid,
        '!command' => $command
      )), BATIRE_SITE_ERROR_SYSTEM);
    }
    else {
      $message = implode("\n", $output);
      $message .= "\nCommand is: " . $command;
      throw new Exception($message, BATIRE_SITE_ERROR_USER);
    }
  }
  catch (Exception $e) {
    switch ($e->getCode()) {
      case BATIRE_SITE_ERROR_SYSTEM:
        watchdog('Batire PDF', $e->getMessage());
        break;

      case BATIRE_SITE_ERROR_USER:
        file_put_contents($error_file, $e->getMessage());
        watchdog('Batire PDF EROR', $e->getMessage());
        break;
    }
    exit();
  }
}

/**
 * Prepare pdf file for downloading
 * @param $node Node(document)
 */
function batire_user_docs_pdf_download($node) {
  if (!$node || !$node->nid || !_batire_site_is_document($node->type)) {
    exit();
  }

  //get additional arguments
  $options = _batire_user_docs_get_options();
  $pdf_path = _batire_user_docs_pdf_get_file_path($node, TRUE, $options, FALSE);
  if (!file_exists($pdf_path)) {
    return false;
  }

  $name = drupal_substr(basename($node->page_data['bid']), 0, 64) . '.pdf';

  if (!empty($pdf_path) && !empty($name)) {
    if (isset($_SERVER['HTTP_USER_AGENT']) && strstr($_SERVER['HTTP_USER_AGENT'], "MSIE")) {
      header("Pragma: public");
      header("Expires: 0");
      header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
      header("Content-type: application-download");
      header("Content-Length: " . filesize($pdf_path));
      header("Content-Disposition:attachment; filename=" . $name);
      header("Content-Transfer-Encoding: binary");
    }
    else {
      header("Content-type: application/pdf");
      header("Content-Length: " . filesize($pdf_path));
      header('Content-Disposition:attachment;filename="' . $name . '"');
    }
    readfile($pdf_path);
  }
  exit();
}

/**
 * Get flash filename and start generate flash file if it is not exist
 */
function batire_user_docs_pdf_get_flash_url_js() {
  $message = array(
    'status' => 0,
    'message' => '',
    'wait' => 0
  );
  global $user;
  if (!$replace_user = batire_gc_ip_replace_user()) {
    $replace_user = $user;
  }
  try {
    $nid = (int) batire_site_check_text($_GET['nid']);

    if (substr(php_uname(), 0, 7) == "Windows") {
      throw new Exception(t('Windows is not supported'), BATIRE_SITE_ERROR_SYSTEM);
    }

    if (!$nid) {
      throw new Exception(t('Document id is empty.'), BATIRE_SITE_ERROR_SYSTEM);
    }

    $node = node_load($nid);
    if (!isset($node->nid) || !$node->nid) {
      throw new Exception(t("Document is not loaded."), BATIRE_SITE_ERROR_SYSTEM);
    }

    if ($node->type != BATIRE_SITE_CT_TN) {
      throw new Exception(t("Someone tried to generate flash pdf file for not TN document - node/!nid.", array('!nid' => $node->nid)), BATIRE_SITE_ERROR_SYSTEM);
    }
    $pdf_path = batire_user_docs_get_document_attached_pdf($node);
    $padf_filepath = _batire_user_docs_pdf_get_basedir() . $pdf_path;
    if (!$pdf_path && !file_exists($padf_filepath)) {
      throw new Exception(t("Document(:nid:!nid) doesn't have pdf file.", array('!nid' => $node->nid)), BATIRE_SITE_ERROR_SYSTEM);
    }

    if (!function_exists('_batire_user_docs_pdf_start_generating_flash')) {
      throw new Exception(t("Function _batire_user_docs_pdf_start_generating_flash is not exist."), BATIRE_SITE_ERROR_SYSTEM);
    }
    else {
      $options = array(
        'user' => $replace_user->uid
      );
      $url_flash_file = batire_user_docs_pdf_get_flash_file($node, $replace_user->uid);
      if (!$url_flash_file) {
        throw new Exception(t("Error has occured. Url to flash file is empty."), BATIRE_SITE_ERROR_SYSTEM);
      }
      $flash_file = _batire_user_docs_pdf_get_basedir() . $url_flash_file;

      $lock_file = $flash_file . '.lock';
      $error_file = $flash_file . '.error';

      if (file_exists($error_file)) {
        throw new Exception(t("Error has occured. Please investigate error file. Path is @path", array('@path' => $error_file)), BATIRE_SITE_ERROR_SYSTEM);
      }

      if (!file_exists($lock_file) && file_exists($flash_file)) {
        $message['url'] = url($url_flash_file, array('absolute' => TRUE));
      }
      else {
        if (_batire_user_docs_pdf_start_generating_flash($node, $options)) {
          $message['wait'] = 1;
        }
        else {
          throw new Exception(t("Can't generate flash file from pdf file."), BATIRE_SITE_ERROR_SYSTEM);
        }
      }
      $message['status'] = 1;
    }
  }
  catch (Exception $e) {
    drupal_set_message(batire_site_show_message($e->getMessage(), $e->getCode()), 'error');
    $message['message'] = theme('status_messages', 'error');
  }
  drupal_json($message);
  return NULL;
}

/**
 * Generate tn flash files
 * @param $node Node(document)
 */
function batire_user_docs_pdf_generate_tn_flash($node) {
  try {
    if (!$node || !$node->nid || $node->type != BATIRE_SITE_CT_TN) {
      throw new Exception(t('FLASH PDF Node is incorrect.'), BATIRE_SITE_ERROR_SYSTEM);
    }
    $start = _batire_user_docs_pdf_microtime_float();

    $base_dir = _batire_user_docs_pdf_get_basedir();

    // get options from $_GET
    $options = _batire_user_docs_get_options();
    $pdf_file = _batire_user_docs_pdf_get_file_path($node, TRUE, $options, FALSE);
    if (!$pdf_file) {
      throw new Exception(t("FLASH PDF file path is empty."), BATIRE_SITE_ERROR_SYSTEM);
    }
    $flash_file = batire_user_docs_pdf_get_flash_file($node, $options['user'], TRUE, TRUE);

    $lock_file = $flash_file . '.lock';
    $error_file = $flash_file . '.error';

    $pdf_path = batire_user_docs_get_document_attached_pdf($node);
    $padf_filepath = $base_dir . $pdf_path;

    if (!$pdf_path && !file_exists($padf_filepath)) {
      file_put_contents($error_file, time());
      throw new Exception(t("FLASH PDF Document(:nid:!nid) doesn't have pdf file.", array('!nid' => $node->nid)), BATIRE_SITE_ERROR_SYSTEM);
    }

    if (batire_user_docs_pdf_create_lock_file($lock_file)) {
      return TRUE;
    }

    if (file_exists($error_file)) {
      exit();
    }
    $pdf_script = variable_get('print_pdf_pdf_tool', FALSE);
    if (!$pdf_script) {
      file_put_contents($error_file, time());
      throw new Exception(t("FLASH PDF file path is empty."), BATIRE_SITE_ERROR_SYSTEM);
    }
    register_shutdown_function('batire_user_docs_pdf_generate_tn_flash_shutdown', $node);

    //HTTP AUTH CHEAT
    $http_auth  = '';
    $http_login =  variable_get('batire_user_docs_pdf_http_login', '');
    $http_pass  =  variable_get('batire_user_docs_pdf_http_pass', '');
    if (!empty($http_login) && !empty($http_pass)) {
      $http_auth = $http_login . ':' . $http_pass . '@';
    }
    elseif (!empty($http_login)) {
      $http_auth = $http_login . '@';
    }

    $base_url   = (isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] == 'on' ? 'https' : 'http') . '://' . $http_auth . $_SERVER['HTTP_HOST'];

    $print_pdf_paper_size = variable_get('print_pdf_paper_size', 'A4');
    $print_pdf_page_orientation = variable_get('print_pdf_page_orientation', 'portrait');
    $footer_url = url(BATIRE_USER_DOCS_PDF_PRINT_PDF_FOOTER_URL . '/' . $node->nid, array(
      'absolute' => TRUE, 'query' => $options, 'base_url' => $base_url)
    );

    $watermark_file = batire_user_docs_pdf_get_watermark_file($node, $options['user']);

    $command = $base_dir . $pdf_script . ' -s ' . $print_pdf_paper_size . ' -O ' . $print_pdf_page_orientation . ' ';
    $command .= '-T 9 "' . $footer_url . '"' . ' ';
    $command .= $watermark_file;
    $command .= ' 2>&1';
    $output = array();
    $return_var = NULL;
    exec($command, $output, $return_var);
    watchdog('Batire PDF Watermark', t('PDF Watermark has been started. Message is: (!message). Return var is: (!var), for (nid:!nid). Command is: (!command)', array(
      '!message' => implode("\n", $output),
      '!var' => $return_var,
      '!nid' => $node->nid,
      '!command' => $command,
    )));
    if ((int) $return_var != 0) {
      file_put_contents($error_file, time());
      throw new Exception(t("FLASH PDF Watermark error."), BATIRE_SITE_ERROR_SYSTEM);
    }

    $output = array();
    $return_var = NULL;
    $pdftk_script = variable_get('batire_user_docs_pdf_pdftk_path', FALSE);
    if (!$pdftk_script) {
      file_put_contents($error_file, time());
      throw new Exception(t("FLASH PDF PDFTK script is empty."), BATIRE_SITE_ERROR_SYSTEM);
    }
    $pdftk_command = $pdftk_script . ' ' . $base_dir . $pdf_path . ' multistamp ' . $watermark_file . ' output ' . $pdf_file;
    exec($pdftk_command, $output, $return_var);
    watchdog('Batire PDFTK', t('PDFTK has been started for (nid:!nid). Return var is: (!var). Command is: (!command)', array(
      '!var' => $return_var,
      '!nid' => $node->nid,
      '!command' => $pdftk_command,
    )));
    if ((int) $return_var != 0) {
      file_put_contents($error_file, time());
      throw new Exception(t("FLASH PDF PDFTK error."), BATIRE_SITE_ERROR_SYSTEM);
    }
    if (batire_user_docs_pdf_convert_pdf_to_flash($pdf_file, $flash_file)) {
      watchdog('Batire FLASH PDF', t('Flash file has been created for document (nid:!nid) generation time is (!time).', array(
        '!time' => _batire_user_docs_pdf_microtime_float() - $start,
        '!nid' => $node->nid,
      )));
    }
    else {
      file_put_contents($error_file, time());
      throw new Exception(t("Batire FLASH PDF convert process has beed finished with error."), BATIRE_SITE_ERROR_SYSTEM);
    }
  }
  catch (Exception $e) {
    switch ($e->getCode()) {
      case BATIRE_SITE_ERROR_SYSTEM:
        watchdog('FLASH PDF ERROR', $e->getMessage());
        break;
    }
  }
  exit();
}
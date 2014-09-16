<?php

/**
 * @file
 *  batire_user_docs_pdf.inc
 * Additional functions
 */
function _batire_user_docs_pdf_microtime_float() {
  list($usec, $sec) = explode(" ", microtime());
  return ((float) $usec + (float) $sec);
}

/**
 * Get file path to pdf file for node
 * @param $node Node(document)
 * @param Bool $tmp Return Real path or temp
 * @param $options List of options
 * @param Bool $delete Remove file if it iexist or not
 * @return File path to pdf file
 */
function _batire_user_docs_pdf_get_file_path($node, $tmp = TRUE, $options = array(), $delete = TRUE) {
  if ($tmp) {
    $directory = BATIRE_USER_DOCS_TMP_PDF_FOLDER;
  }
  else {
    $directory = BATIRE_USER_DOCS_PDF_FOLDER;
  }
  if (!batire_user_docs_pdf_file_prepare_directory($directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
    return FALSE;
  }
  $filename = _batire_user_docs_pdf_get_tmp_file_name($node, $options);
  $path = $directory . '/' . $filename . '.pdf';
  if (file_exists($path) && $delete) {
    $stat = stat($path);
    // @todo if an and re is false need to remove only if current day > day of created
    if (time() - $stat['mtime'] > 15) {
      file_delete($path);
    }
  }
  return $path;
}

/**
 * Get tmp filename. Filename creates from options.
 * @param $node Node(document)
 * @param $options List of options
 * @return md5 string
 */
function _batire_user_docs_pdf_get_tmp_file_name($node, $options) {
  $filename = $node->nid;
  $filename .= isset($options['an']) && $options['an'] ? 'true' : 'false';
  $filename .= isset($options['re']) && $options['re'] ? 'true' : 'false';
  $filename .= isset($options['user']) ? $options['user'] : 0;
  return md5($filename);
}

/**
 * Get Pdf file firectory, if it is not exist, directory will created.
 * @param $node Node(document)
 * @return Pdf file directory
 */
function _batire_user_docs_pdf_get_directory($node) {
  if (!$node || !$node->nid || !_batire_site_is_document($node->type)) {
    return FALSE;
  }

  $pdf_directory = BATIRE_USER_DOCS_TMP_PDF_FOLDER;
  if (!batire_user_docs_pdf_file_prepare_directory($pdf_directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
    return FALSE;
  }
  if (!is_dir($pdf_directory)) {
    return FALSE;
  }
  return $pdf_directory;
}

/**
 * Get system path to base folder of site
 */
function _batire_user_docs_pdf_get_basedir() {
  return str_replace(drupal_get_path('module', 'batire_user_docs_pdf') . '/includes', '', dirname(__FILE__));
}

/**
 * Get url for downloading pdf file
 * @param $node Node(document)
 * @return Url
 */
function _batire_user_docs_pdf_get_url($node) {
  if (!$node || !$node->nid || !_batire_site_is_document($node->type)) {
    return FALSE;
  }
  return 'document/pdf/' . $node->nid;
}

/**
 * Shutdown function for batire_user_docs_pdf_generate()
 * @param $node Node(document)
 */
function _batire_user_docs_pdf_generate_shutdown($node) {
  $last = error_get_last();
  $options = _batire_user_docs_get_options();
  $pdf_directory = _batire_user_docs_pdf_get_directory($node);
  $filename = _batire_user_docs_pdf_get_tmp_file_name($node, $options);
  $error_file = $pdf_directory . '/' . $filename . '.error';

  if (is_array($last) && in_array($last['type'], array(E_ERROR)) && function_exists('dblog_watchdog')) {
    //log error
    $message = 'PDF generation error while processing node (@nid) "@message" in @file on line @line.';
    $variables = array(
      '@message' => $last['message'],
      '@file' => $last['file'],
      '@nid' => $node->nid,
      '@line' => $last['line'],
    );
    watchdog('php_shutdown', $message, $variables, WATCHDOG_ERROR);

    //save error lock file - if it exists - generation will not start
    file_put_contents($error_file, time());
  }
  else {
    file_delete($error_file);
  }

  $lock_file = $pdf_directory . '/' . $filename . '.lock';
  if (file_exists($lock_file)) {
    file_delete($lock_file);
  }
}

/**
 * Shutdown function for batire_user_docs_pdf_generate_tn_flash()
 * @param $node Node(document)
 */
function batire_user_docs_pdf_generate_tn_flash_shutdown($node) {
  $last = error_get_last();
  $options = _batire_user_docs_get_options();

  $flash_file = batire_user_docs_pdf_get_flash_file($node, $options['user'], TRUE, TRUE);
  $lock_file = $flash_file . '.lock';
  $error_file = $flash_file . '.error';

  if (is_array($last) && in_array($last['type'], array(E_ERROR)) && function_exists('dblog_watchdog')) {
    //log error
    $message = 'PDF to FLASH generation error while processing node (@nid) "@message" in @file on line @line.';
    $variables = array(
      '@message' => $last['message'],
      '@file' => $last['file'],
      '@nid' => $node->nid,
      '@line' => $last['line'],
    );
    watchdog('php_shutdown', $message, $variables, WATCHDOG_ERROR);
    //save error lock file - if it exists - generation will not start
    file_put_contents($error_file, time());
  }
  else {
    if (file_exists($flash_file)) {
      file_delete($error_file);
    }
  }

  if (file_exists($lock_file)) {
    file_delete($lock_file);
  }
}

/**
 * Get url query by options
 * @param $options List of options
 * @return query part for link
 */
function _batire_user_docs_pdf_get_url_query($options) {
  $path = '';
  if (count($options)) {
    $query = drupal_query_string_encode($options);
    // Append the query.
    if ($query) {
      $path .= (strpos($path, '?') !== FALSE ? '&' : '?') . $query;
    }
  }
  return $path;
}

/**
 * Checks whether a directory exists and is writable.
 *
 * Furthermore, the directory can optionally be created if it does not exist,
 * and/or be set to writable if it is currently not. Directories need to have
 * execute permission to be considered a directory by FTP servers.
 *
 * @param $directory
 *   A string representing the directory path.
 * @param $mode
 *   An optional bitmask containing the actions, if any, to be carried out on
 *   the directory. Any combination of the actions FILE_CREATE_DIRECTORY and
 *   FILE_MODIFY_PERMISSIONS is allowed.

 * @return
 *   FALSE if the directory does not exist or is not writable, even after
 *   any optional actions have been carried out. Otherwise, TRUE is returned.
 */
function batire_user_docs_pdf_file_prepare_directory(&$directory, $mode = 0) {
  $directory = rtrim($directory, '/\\');
  // Check if directory exists.
  if (!is_dir($directory)) {
    if (($mode & FILE_CREATE_DIRECTORY) && @mkdir($directory, 0775, TRUE)) {
      @chmod($directory, 0775); // Necessary for non-webserver users.
    }
    else {
      return FALSE;
    }
  }

  // Check to see if the directory is writable.
  if (!is_writable($directory)) {
    if (($mode & FILE_MODIFY_PERMISSIONS) && @chmod($directory, 0775)) {
      //
    }
    else {
      return FALSE;
    }
  }

  if (!is_file("$directory/.htaccess")) {
    $htaccess_lines = "SetHandler Drupal_Security_Do_Not_Remove_See_SA_2006_006\nOptions None\nOptions +FollowSymLinks";
    if (($fp = fopen("$directory/.htaccess", 'w')) && fputs($fp, $htaccess_lines)) {
      fclose($fp);
      chmod($directory . '/.htaccess', 0664);
    }
    else {
      $variables = array('%directory' => $directory, '!htaccess' => '<br />' . nl2br(check_plain($htaccess_lines)));
    }
  }

  return TRUE;
}

/**
 * Get watermark file path or filename
 * @param $node Node(document)
 * @param $uid User uid
 * @param Bool $path Return path or only filename
 * @return full filepath or filename
 */
function batire_user_docs_pdf_get_watermark_file($node, $uid, $path = TRUE) {
  $watermark_name = md5($node->nid . date('d-m-Y', time()) . $uid) . '.pdf';
  if ($path) {
    $directory = BATIRE_USER_DOCS_TMP_PDF_FOLDER;
    if (batire_user_docs_pdf_file_prepare_directory($directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
      return BATIRE_USER_DOCS_TMP_PDF_FOLDER . '/' . $watermark_name;
    }
    else {
      return FALSE;
    }
  }
  return $watermark_name;
}

/**
 * Get flash file path or filename
 * @param $node Node(document)
 * @param $uid User uid
 * @param Bool $path Return path or only filename
 * @return full filepath or filename
 */
function batire_user_docs_pdf_get_flash_file($node, $uid, $path = TRUE, $absolute = FALSE) {
  $flash_name = md5($node->nid . date('d-m-Y', time()) . $uid) . '.swf';
  if ($path) {
    $directory = BATIRE_USER_DOCS_PDF_FLASH_FOLDER;
    if ($absolute) {
      $directory = _batire_user_docs_pdf_get_basedir() . $directory;
    }
    if (batire_user_docs_pdf_file_prepare_directory($directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
      return $directory . '/' . $flash_name;
    }
    else {
      return FALSE;
    }
  }
  return $flash_name;
}

/**
 * Create lock file
 * @param $lock_file Path to lock file
 * @return Bool TRUE|FALSE
 */
function batire_user_docs_pdf_create_lock_file($lock_file) {
  $lock_file_lifetime = 120;
  set_time_limit(120);
  //create lock file
  if (file_exists($lock_file)) {
    $time = file_get_contents($lock_file);
    if (time() - (int) $time > $lock_file_lifetime) {
      file_delete($lock_file);
    }
    else {
      return TRUE;
    }
  }
  file_put_contents($lock_file, time());
  return FALSE;
}

/**
 * Convert pdf file to flash format
 * @param $from Filepath from
 * @param $to Filepath to
 */
function batire_user_docs_pdf_convert_pdf_to_flash($from, $to) {
  $pdf2swf_script = variable_get('batire_user_docs_pdf_pdf2swf_path', FALSE);
  if (!$pdf2swf_script) {
    return FALSE;
  }
  $command = $pdf2swf_script . ' -T 9 ' . $from . ' ' . $to;
  $output = array();
  $return_var = NULL;
  exec($command, $output, $return_var);
  watchdog('Batire PDF2SWF', t('PDF2SWF has been started. Message is : (!message) . Return var is : (!var). Command is: (!command)', array(
    '!message' => implode("\n", $output),
    '!var' => $return_var,
    '!command' => $command,
  )));
  if ((int) $return_var != 0) {
    return FALSE;
  }
  return TRUE;
}
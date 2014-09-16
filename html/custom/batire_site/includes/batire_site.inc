<?php

/**
 * @file
 * Helpers for the module
 */

/**
 * Checks if custom cache is enabled
 */
function _batire_site_is_cache_enabled() {
  return!variable_get('batire_site_development_disable_cache', 0);
}

/**
 * Breadcrumb sorting
 */
function _batire_site_sort_breadcrumb($a, $b) {
  if ($a['weight'] == $b['weight']) {
    return 0;
  }
  return ($a['weight'] < $b['weight']) ? -1 : 1;
}

/**
 * Trim and encode special characters in a plain-text string for display as HTML.
 * @param $text
 *   The text to be checked or processed.
 * @return An HTML safe version of $text, or an empty string if $text is not valid UTF-8.
 * @see check_plain()
 */
function batire_site_check_text($text = '') {
  if (!empty($text)) {
    return check_plain(trim($text));
  }
  else {
    return '';
  }
}

/**
 * Check if user has access to see devel information return message,
 * otherwise show standart message for user.

 * @param $message
 *   Message for user, should has development information.
 * @return
 *   Message for user.
 * @see user_access()
 */
function batire_site_show_message($message, $code = BATIRE_SITE_ERROR_SYSTEM) {

  if (BATIRE_SITE_ERROR_SYSTEM == $code) {
    batire_site_log_watchdog($message, WATCHDOG_ERROR);

    if (user_access('access devel information')) {
      $message = t('Erreur:') . ' ' . $message;
    }
    else {
      $message = t(
      'Une erreur s\'est produite: nous vous invitons à recommencer ou à nous signaler cette anomalie en !link', array('!link' => batire_site_contact_link())
      );
    }
  }

  return $message;
}

/**
 * Save message to watchdog table.
 * @param $message
 *   Message for user, should has development information.
 * @param $message_type
 *   Type of message
 */
function batire_site_log_watchdog($message, $message_type = WATCHDOG_INFO) {
  if (variable_get('watchdog', FALSE)) {
    $mes = t('Error has occurred: Url - @current_url, @error_message', array('@current_url' => $_GET['q'], '@error_message' => $message));
    watchdog('batire_site', $mes, array(), $message_type);
  }
}

/**
 * Verify the syntax of the given e-mail address.
 *
 * Empty e-mail addresses are allowed. See RFC 2822 for details.
 *
 * @param $mail
 *   A string containing an e-mail address.
 * @return
 *   TRUE if the address is in a valid format.
 */
function batire_site_validate_email_address($mail) {
  return (bool) filter_var($mail, FILTER_VALIDATE_EMAIL);
}

/**
 * Recursively delete all files and directories in the specified filepath.
 *
 * If the specified path is a directory then the function will call itself
 * recursively to process the contents. Once the contents have been removed the
 * directory will also be removed.
 *
 * If the specified path is a file then it will be passed to
 * batire_site_file_unmanaged_delete().
 *
 * Note that this only deletes visible files with write permission.
 *
 * @param $path
 *   A string containing either an URI or a file or directory path.
 *
 * @return
 *   TRUE for success or if path does not exist, FALSE in the event of an
 *   error.
 *
 * @see batire_site_file_unmanaged_delete()
 * @see batire_site_rmdir()
 */
function batire_site_file_unmanaged_delete_recursive($path) {
  // Resolve streamwrapper URI to local path.
  if (is_dir($path)) {
    $dir = dir($path);
    while (($entry = $dir->read()) !== FALSE) {
      if ($entry == '.' || $entry == '..') {
        continue;
      }
      $entry_path = $path . '/' . $entry;
      batire_site_file_unmanaged_delete_recursive($entry_path);
    }
    $dir->close();

    return batire_site_rmdir($path);
  }
  return batire_site_file_unmanaged_delete($path);
}

/**
 * Remove a directory.
 *
 * PHP's rmdir() is broken on Windows, as it can fail to remove a directory
 * when it has a read-only flag set.
 *
 * @param $uri
 *   A URI or pathname.
 * @param $context
 *   Refer to http://php.net/manual/en/ref.stream.php
 *
 * @return
 *   Boolean TRUE on success, or FALSE on failure.
 *
 * @see rmdir()
 * @ingroup php_wrappers
 */
function batire_site_rmdir($uri, $context = NULL) {
  if ((drupal_substr(PHP_OS, 0, 3) == 'WIN')) {
    chmod($uri, 0700);
  }
  if ($context) {
    return rmdir($uri, $context);
  }
  else {
    return rmdir($uri);
  }
}

/**
 * Delete a file without calling any hooks or making any changes to the
 * database.
 *
 * This function should be used when the file to be deleted does not have an
 * entry recorded in the files table.
 *
 * @param $path
 *   A string containing a file path or (streamwrapper) URI.
 *
 * @return
 *   TRUE for success or path does not exist, or FALSE in the event of an
 *   error.
 *
 * @see batire_site_unlink()
 * @see batire_site_file_unmanaged_delete_recursive()
 */
function batire_site_file_unmanaged_delete($path) {
  if (is_dir($path)) {
    watchdog('file', '%path is a directory and cannot be removed using batire_site_file_unmanaged_delete().', array('%path' => $path), WATCHDOG_ERROR);
    return FALSE;
  }
  if (is_file($path)) {
    return batire_site_unlink($path);
  }
  // Return TRUE for non-existent file, but log that nothing was actually
  // deleted, as the current state is the intended result.
  if (!file_exists($path)) {
    watchdog('file', 'The file %path was not deleted, because it does not exist.', array('%path' => $path), WATCHDOG_NOTICE);
    return TRUE;
  }
  // We cannot handle anything other than files and directories. Log an error
  // for everything else (sockets, symbolic links, etc).
  watchdog('file', 'The file %path is not of a recognized type so it was not deleted.', array('%path' => $path), WATCHDOG_ERROR);
  return FALSE;
}

/**
 * Deletes a file.
 *
 * PHP's unlink() is broken on Windows, as it can fail to remove a file
 * when it has a read-only flag set.
 *
 * @param $uri
 *   A URI or pathname.
 * @param $context
 *   Refer to http://php.net/manual/en/ref.stream.php
 *
 * @return
 *   Boolean TRUE on success, or FALSE on failure.
 *
 * @see unlink()
 * @ingroup php_wrappers
 */
function batire_site_unlink($uri, $context = NULL) {
  if ((drupal_substr(PHP_OS, 0, 3) == 'WIN')) {
    chmod($uri, 0600);
  }
  if ($context) {
    return unlink($uri, $context);
  }
  else {
    return unlink($uri);
  }
}

/**
 * Get node for selected build mode
 * @param $nid Node nid.
 * @param $build_mode Build mode of node.
 * @return HTML of node
 */
function batire_site_get_node_in_buildmode($nid, $build_mode = 'popups') {
  $node = node_load($nid);
  $node->build_mode = $build_mode;
  return node_view($node);
}

/**
 * Send mail via module mimemail.
 *
 * @param
 *  $message_options Array should looks like:
 *   - $message_options['module']: A module name to invoke hook_mail() on
 *   - $message_options['mailkey']: A key to identify the e-mail sent. The final e-mail id for e-mail altering will be {$module}_{$key}.
 *   - $message_options['recipient']: The e-mail address or addresses where the message will be sent to.
 *   - $message_options['subject']: A subject line string.
 *   - $message_options['data']: Data for message. Example, $message_options['data']['nid'] - Id of document
 *   - $message_options['plaintext']: Whether to send the message as plaintext only or HTML. If set to 1, Yes
 *      or TRUE, then the message will be sent as plaintext.
 *   - $message_options['headers']: Optional e-mail headers in a keyed array.
 *   - $message_options['text']: Optional plaintext portion of a multipart e-mail.
 *   - $message_options['attachments']: An array of arrays which describe one or more attachments.
 *        Existing files can be added by path, dinamically-generated files
 *        can be added by content. The internal array consists of the following parts:
 *        - filepath: Relative Drupal path to an existing file (filecontent is NULL).
 *        - filecontent: The actual content of the file (filepath is NULL).
 *        - filename: The filename of the file.
 *        - filemime: The MIME type of the file.
 *        The array of arrays looks something like this:
 *        Array
 *        (
 *          [0] => Array
 *          (
 *          [filepath] => '/sites/default/files/attachment.txt'
 *          [filecontent] => 'My attachment.'
 *          [filename] => 'attachment.txt'
 *          [filemime] => 'text/plain'
 *          )
 *        )
 *   - $message_options['send']: Send the message directly.
 * @return
 *  An array containing the MIME-encoded message, including headers and body.
 */
function batire_site_send_mail($message_options = array(), $from = '') {
  global $user;

  $options = array(
    'module' => 'batire_site',
    'mailkey' => '',
    'recipient' => '',
    'subject' => '',
    'data' => array(),
    'plaintext' => NULL,
    'headers' => array(),
    'text' => NULL,
    'attachments' => array(),
    'send' => TRUE
  );

  $options = array_merge($options, $message_options);

  $message = drupal_mail(
    $options['module'],
    $options['mailkey'],
    $options['recipient'],
    user_preferred_language($user),
    array('data' => $options['data']),
    (!empty($from)) ? $from : $user->mail,
    FALSE
  );

  $headers = $message['headers'];

  if (is_array($options['headers']) && !empty($options['headers'])) {
    $headers = $options['headers'];
  }

  /**
   * Sending message
   */
  $result = mimemail(
    $message['from'],
    $message['to'],
    $message['subject'],
    $message['body'],
    $options['plaintext'],
    $headers, $options['text'],
    $options['attachments'],
    $options['mailkey'],
    $options['send']
  );

  /**
   * Optionally sending CC message, if specified
   */
  $cc = variable_get('batire_user_email_cc', '');
  if ($cc) {
    mimemail(
      $message['from'],
      $cc,
      $message['subject'],
      $message['body'],
      $options['plaintext'],
      $headers,
      $options['text'],
      $options['attachments'],
      $options['mailkey'],
      $options['send']
    );
  }

  return $result;
}

/**
 * Return result check, if date d’echeance - “WARNING BEFORE EXPIRATION, DAYS“ <= NOW
 * @global
 *  $user
 * @param
 *  $user Object of user
 * @return
 *  BOOL
 */
function batire_site_is_user_about_to_expire($user) {
  if (!$user) {
    global $user;
  }
  $profile = batire_user_profile_load($user->uid);

  return ($profile->field_user_dates[0]['value2'] - variable_get('batire_user_date_to_expiration', 0) * 86400) <= time();
}

/**
 * Truncate a UTF-8-encoded string safely to a number of characters.
 *
 * @param $string
 *   The string to truncate.
 * @param $len
 *   An upper limit on the returned string length.
 * @param $wordsafe
 *   Flag to truncate at last space within the upper limit. Defaults to FALSE.
 * @param $dots
 *   Flag to add trailing dots. Defaults to FALSE.
 * @return
 *   The truncated string.
 */
function batire_site_truncate_utf8($string, $len, $wordsafe = FALSE, $dots = FALSE) {
  if (drupal_strlen($string) <= $len) {
    return $string;
  }

  if ($wordsafe) {
    $string = drupal_substr($string, 0, $len + 1); // leave one more character
    $last_space = strrpos($string, ' ');
    if ($last_space) { // space exists AND is not on position 0
      $string = substr($string, 0, $last_space);
    }
    else {
      $string = drupal_substr($string, 0, $len);
    }
  }
  else {
    $string = drupal_substr($string, 0, $len);
  }

  $string = trim($string);
  if ($dots) {
    $string .= '...';
  }

  return $string;
}

/**
 * Set cookie value
 * @param $name Cookie name
 * @param $val Value, if value is null remove cookie
 */
function _batire_site_set_cookie($name, $val = NULL, $expire = 0) {
  if (!is_null($val)) {
    setcookie($name, $val, $expire, '/');
  }
  else {
    setcookie($name, "", -1, '/');
    unset($_COOKIE[$name]);
  }
}

/**
 * Get cookie value by name
 * @param $name Name of cookie
 * @param $default_value Return this value if name is not exist
 * @return Cookie value
 */
function _batire_site_get_cookie($name, $default_value = NULL) {
  if (isset($_COOKIE[$name])) {
    return $_COOKIE[$name];
  }
  return $default_value;
}

/**
 * Set value to session
 * @param $name Name
 * @param $val Value, if value is null remove name from session
 */
function _batire_site_set_session($name, $val = NULL) {
  if (!is_null($val)) {
    $_SESSION[$name] = $val;
  }
  else {
    unset($_SESSION[$name]);
  }
}

/**
 * Get session value by name
 * @param $name Name
 * @param $default_value Return this value if name is not exist
 * @return session value
 */
function _batire_site_get_session($name, $default_value = NULL) {
  if (isset($_SESSION[$name])) {
    return $_SESSION[$name];
  }
  return $default_value;
}

/**
 * Get variable from session
 */
function _batire_site_get_var($namespace, $key, $default_value = NULL) {
  $session = _batire_site_get_session($namespace);
  if (isset($session['var'][$key])) {
    return $session['var'][$key];
  }
  return $default_value;
}

/**
 * Set variable to session
 */
function _batire_site_set_var($namespace, $key, $value = '') {
  $session = _batire_site_get_session($namespace);
  if ($value) {
    $session['var'][$key] = $value;
  }
  else {
    unset($session['var'][$key]);
  }
  _batire_site_set_session($namespace, $session);
}

/**
 * Get PHPExcel object
 * @return PHPExcel
 */
function batire_site_get_php_excel() {
  require_once './sites/all/libraries/phpexcel/PHPExcel.php';
  // Create new PHPExcel object
  $cache_method = PHPExcel_CachedObjectStorageFactory:: cache_to_phpTemp;
  $cache_settings = array(' memoryCacheSize ' => '1MB');
  PHPExcel_Settings::setCacheStorageMethod($cache_method, $cache_settings);
  $ogj_php_excel = new PHPExcel();
  // Set properties
//  $objPHPExcel->getProperties()->setCreator("Batire Site")
//  ->setLastModifiedBy("Batire Site")
//  ->setTitle("Office XLSX Test Document")
//  ->setSubject("Office XLSX Test Document")
//  ->setDescription("Test document for Office XLSX, generated using PHP classes.")
//  ->setKeywords("office openxml php")
//  ->setCategory("Test result file");

  $ogj_php_excel->setActiveSheetIndex(0);

  return $ogj_php_excel;
}

/**
 * Generate Excel file
 * @param String $filepath Path to file
 * @param Array $map Map of rows, see example below:
 *  $map = array(
 *    'A' => 'row1',
 *    'B' => 'row2',
 *    'C' => 'row3'
 *  );
 * @param Array $data List of objects or arrays with data, see example below:
 *  $data = array(
 *    0 => array( // or can be object
 *      'row1' => 'data_row1',
 *      'row2' => 'data_row2',
 *      'row3' => 'data_row3'
 *      )
 *  );
 * @param Array $header List of titles for header in file, see example below:
 *  $header = array(
 *    'A' => t('Title1'),
 *    'B' => t('Title2'),
 *    'C' => t('Title3'),'
 *  );
 * @return String Path to file
 */
function batire_site_generate_excel_file($filepath, $map, $data, $header = array()) {
  $obj_php_excel = batire_site_get_php_excel();
  // write header
  if (!empty($header)) {
    foreach ($header as $key => $value) {
      $excel_key = $key . '1';
      $active_sheet = $obj_php_excel->getActiveSheet();
      $active_sheet->setCellValue($excel_key, $value);
      $active_sheet->getColumnDimension()->setWidth(20);
    }
  }
  // write data
  if (!empty($data) && !empty($map)) {
    for ($i = 0; $i < count($data); $i++) {
      $item = !empty($data[$i]) ? $data[$i] : NULL;
      if (is_object($item)) {
        foreach ($map as $key => $val) {
          $excel_key = $key . ($i + 2);
          $obj_php_excel->getActiveSheet()->setCellValue($excel_key, $item->$val);
        }
      }
      elseif (is_array($item)) {
        foreach ($map as $key => $val) {
          $excel_key = $key . ($i + 2);
          $obj_php_excel->getActiveSheet()->setCellValue($excel_key, $item[$val]);
        }
      }
    }
  }

  $obj_writer = PHPExcel_IOFactory::createWriter($obj_php_excel, 'Excel5');
  $obj_writer->save($filepath);
  return $filepath;
}

/**
 * Generate multisheet Excel file
 * @param String $filepath Path to file
 * @param Array $sheets Array of sheets with keys:
 * 'map': Map of rows, see example below:
 *  $map = array(
 *    'A' => 'row1',
 *    'B' => 'row2',
 *    'C' => 'row3'
 *  );
 * 'data' List of objects or arrays with data, see example below:
 *  $data = array(
 *    0 => array( // or can be object
 *      'row1' => 'data_row1',
 *      'row2' => 'data_row2',
 *      'row3' => 'data_row3'
 *      )
 *  );
 * 'header' List of titles for header in file, see example below:
 *  $header = array(
 *    'A' => t('Title1'),
 *    'B' => t('Title2'),
 *    'C' => t('Title3'),'
 *  );
 * 'title' Title of the sheet
 * @return String Path to file
 */
function batire_site_generate_multisheet_excel_file($filepath, $sheets) {
  $obj_php_excel = batire_site_get_php_excel();
  $sheet_index = 0;
  foreach ($sheets as $sheet) {
    $obj_php_excel->createSheet($sheet_index);
    $obj_php_excel->setActiveSheetIndex($sheet_index);

    $header = isset($sheet['header']) ? $sheet['header'] : array();
    $map = $sheet['map'];
    $data = $sheet['data'];
    $title = isset($sheet['title']) ? $sheet['title'] : NULL;

    if (isset($title)) {
      $obj_php_excel->getActiveSheet()->setTitle($title);
    }
    // write header
    if (!empty($header)) {
      foreach ($header as $key => $value) {
        $excel_key = $key . '1';
        $active_sheet = $obj_php_excel->getActiveSheet();
        $active_sheet->setCellValue($excel_key, $value);
        $active_sheet->getColumnDimension($key)->setAutoSize(TRUE);
      }
    }
    // write data
    if (!empty($data) && !empty($map)) {
      for ($i = 0; $i < count($data); $i++) {
        $item = !empty($data[$i]) ? $data[$i] : NULL;
        if (is_object($item)) {
          foreach ($map as $key => $val) {
            $excel_key = $key . ($i + 2);
            $obj_php_excel->getActiveSheet()->setCellValue($excel_key, $item->$val);
          }
        }
        elseif (is_array($item)) {
          foreach ($map as $key => $val) {
            $excel_key = $key . ($i + 2);
            $obj_php_excel->getActiveSheet()->setCellValue($excel_key, $item[$val]);
          }
        }
      }
    }
    $sheet_index++;
  }
  $obj_php_excel->setActiveSheetIndex(0);

  $obj_writer = PHPExcel_IOFactory::createWriter($obj_php_excel, 'Excel5');
  $obj_writer->save($filepath);
  return $filepath;
}

/**
 * Generate csv file
 * @param String $filepath Path to file
 * @param Array $map Map of rows, see example below:
 *  $map = array(
 *    'A' => 'row1',
 *    'B' => 'row2',
 *    'C' => 'row3'
 *  );
 * @param Array $data List of objects or arrays with data, see example below:
 *  $data = array(
 *    0 => array( // or can be object
 *      'row1' => 'data_row1',
 *      'row2' => 'data_row2',
 *      'row3' => 'data_row3'
 *      )
 *  );
 * @param Array $header List of titles for header in file, see example below:
 *  $header = array(
 *    'A' => t('Title1'),
 *    'B' => t('Title2'),
 *    'C' => t('Title3'),'
 *  );
 * @return String Path to file
 */
function batire_site_generate_csv_file($filepath, $map, $data, $header = array()) {
  if (!(is_array($data) && $data)) {
    return FALSE;
  }
  $fp = @fopen($filepath, 'w');
  if (!$fp) {//could not create the file
    return FALSE;
  }
  $file_separator = variable_get('batire_site_file_separator', ';');
  $file_enclosure = variable_get('batire_site_file_enclosure', '"');
  if (!empty($header)) {
    fputcsv($fp, $header, $file_separator, $file_enclosure);
  }

  // write data
  if (!empty($data) && !empty($map)) {
    for ($i = 0; $i < count($data); $i++) {
      $item = !empty($data[$i]) ? $data[$i] : NULL;
      $fields = array();
      if (is_object($item)) {
        foreach ($map as $field) {
          if ($item->$field == '') {
            $fields[] = ' ';
          }
          elseif (is_null($item->$field) || $item->$field == '0') {
            $fields[] = '0';
          }
          else {
            $fields[] = $item->$field;
          }
        }
        fputcsv($fp, $fields, $file_separator, $file_enclosure);
      }
      elseif (is_array($item)) {
        foreach ($map as $field) {
          $fields[] = $item[$field];
        }
        fputcsv($fp, $fields, $file_separator, $file_enclosure);
      }
    }
  }
  fclose($fp);

  $content = file_get_contents($filepath);
  $content = str_replace('’', "'", $content);
  $encoded = mb_convert_encoding($content, 'iso-8859-1');
  file_put_contents($filepath, $encoded);
  return $filepath;
}

/**
 * Get generate file function by file type
 * @param $file_type  File type
 * @return string  Function name
 */
function batire_site_get_generate_file_function($xls_function, $csv_function) {
  $file_type = variable_get('batire_site_format_file', 'xls');
  switch ($file_type) {
    default:
    case 'xls':
      return $xls_function;
      break;

    case 'csv':
      return $csv_function;
      break;
  }
}

/**
 * Create file path
 * @param $type Type of file statistics
 * @param $params Additional params
 * @return file path
 */
function batire_site_get_file_path($type, $params = array()) {
  $file_type = variable_get('batire_site_format_file', 'xls');
  switch ($type) {
    default:
    case 'list':
      $filepath = BATIRE_USER_STATISTICS_FILES_DIRECTORY . '/' . $params['date'] . '.' . $file_type;
      break;
    case 'list-period':
      $filepath = BATIRE_USER_STATISTICS_FILES_DIRECTORY . '/' . 'Kheox_' . $params['start_date'] . '_au_' . $params['end_date'] . '.' . $file_type;
      break;
    case 'guest_list':
      $filepath = BATIRE_USER_STATISTICS_FILES_DIRECTORY . '/guest_list.' . $file_type;
      break;
    case 'request_list':
      $filepath = BATIRE_USER_STATISTICS_FILES_DIRECTORY . '/request_list.' . $file_type;
      break;
    //@todo
    case 'export_users':
      $filepath = BATIRE_EXPORT_USERS_FILES_DIRECTORY . '/export_users_' . $params['date'] . '.' . $file_type;
      break;
    case 'comptes_utilisateurs':
      $filepath = BATIRE_EXPORT_USERS_FILES_DIRECTORY . '/comptes_utilisateurs_' . $params['uid'] . '.' . $file_type;
      break;
  }
  return $filepath;
}

/**
 * Get headers for statistics files
 * @return Array
 */
function batire_site_get_file_headers($file_name = 'statistics', $type = NULL) {
  if (isset($type)) {
    $file_type = $type;
  }
  else {
    $file_type = variable_get('batire_site_format_file', 'xls');
  }
  switch ($file_type) {
    default:
    case 'xls':
      $headers = array(
        'Content-Type: application/ms-excel',
      );
      break;

    case 'csv':
      $headers = array(
        'Content-Type: application/csv'
      );
      break;
    case 'doc':
    case 'docx':
      $headers = array(
        'Content-Type: application/msword'
      );
      break;
    case 'pdf':
      $headers = array(
        'Content-Type: application/pdf'
      );
  }
  if (isset($type)) {
    $headers[] = 'Content-disposition: attachment; filename=' . $file_name;
  }
  else {
    $headers[] = 'Content-disposition: attachment; filename=' . $file_name . '.' . $file_type;
  }
  return $headers;
}

/**
 * Get content type for TN document
 */
function batire_site_get_TN_content_type($node) {
  if (isset($node->page_data['notice_seule'])) {
    switch ($node->page_data['notice_seule']) {
      default:
      case FALSE:
        $tn_content_type = BATIRE_SITE_TN_TYPE_NORMAL;
        break;

      case TRUE: //1:
        if (!empty($node->page_data['attached'])) {
          $tn_content_type = BATIRE_SITE_TN_TYPE_PDF;
        }
        else {
          $tn_content_type = BATIRE_SITE_TN_TYPE_HP;
        }
        break;
    }
    return $tn_content_type;
  }
  return BATIRE_SITE_TN_TYPE_NORMAL;
}

/**
 * Get date in format
 */
function _batire_site_get_date_in_format($date, $format = 'F Y') {
  static $future_date = NULL;
  if (!$future_date) {
    $future_date = mktime(0, 0, 0, 1, 1, 2999);
  }
  $return_date = '';
  if (!empty($date)) {
    if (is_numeric($date) && (int) $date == $date) { // this date is timestamp
      $timestamp = $date;
    }
    else {
      $timestamp = strtotime($date);
      if ($timestamp >= $future_date) {
        return t('(date indéterminée)');
      }
    }
    $return_date = _batire_site_format_date($timestamp, 'custom', $format);
  }
  return drupal_ucfirst($return_date);
}

/**
 * This is a full copy of Drupal format_date() only without user's timezone handling. It will use server's timezone instead.
 */
function _batire_site_format_date($timestamp, $type = 'medium', $format = '', $timezone = 0, $langcode = NULL) {
  switch ($type) {
    case 'small':
      $format = variable_get('date_format_short', 'm/d/Y - H:i');
      break;
    case 'large':
      $format = variable_get('date_format_long', 'l, F j, Y - H:i');
      break;
    case 'custom':
      // No change to format.
      break;
    case 'medium':
    default:
      $format = variable_get('date_format_medium', 'D, m/d/Y - H:i');
  }

  $max = strlen($format);
  $date = '';
  for ($i = 0; $i < $max; $i++) {
    $c = $format[$i];
    if (strpos('AaDlM', $c) !== FALSE) {
      $date .= t(date($c, $timestamp), array(), $langcode);
    }
    else if ($c == 'F') {
      // Special treatment for long month names: May is both an abbreviation
      // and a full month name in English, but other languages have
      // different abbreviations.
      $date .= trim(t('!long-month-name '. date($c, $timestamp), array('!long-month-name' => ''), $langcode));
    }
    else if (strpos('BdgGhHiIjLmnsStTUwWYyz', $c) !== FALSE) {
      $date .= date($c, $timestamp);
    }
    else if ($c == 'r') {
      $date .= _batire_site_format_date($timestamp, 'custom', 'D, d M Y H:i:s O', $timezone, $langcode);
    }
    else if ($c == 'O') {
      $date .= sprintf('%s%02d%02d', ($timezone < 0 ? '-' : '+'), abs($timezone / 3600), abs($timezone % 3600) / 60);
    }
    else if ($c == 'Z') {
      $date .= $timezone;
    }
    else if ($c == '\\') {
      $date .= $format[++$i];
    }
    else {
      $date .= $c;
    }
  }

  return $date;
}

/**
 * Check is real date
 *
 * @param $date
 * @return string
 */
function _batire_site_is_real_date($date) {
  if (!empty($date)) {
    if (is_numeric($date) && (int) $date == $date) { // this date is timestamp
      $timestamp = $date;
    }
    else {
      $timestamp = strtotime($date);
    }

    if (($timestamp > REQUEST_TIME + 200 * 365 * 24 * 60 * 60) || ($timestamp < REQUEST_TIME - 700 * 365 * 24 * 60 * 60)) {
      return FALSE;
    }

    return TRUE;
  }

  return FALSE;
}

function _batire_site_prepare_consolidation_date($date, $node = null, $version = null, $article_of_toc = FALSE) {
  if ($article_of_toc) {
    $ttext = $version . ' Version de cet article consolidée au !date';
  }
  else {
    $ttext = $version . ' Version consolidée au !date';
  }

  if (isset($node->page_data['jorf_summary']) && $node->page_data['jorf_summary']) {
    $version = 'INITIAL';
  }

  //change date text according version value
  if ($version) {
    switch ($version) {
      case 'INITIAL':
        if ($date) {
          if ($article_of_toc) {
            $ttext = 'Version de cet article initiale du !date';
          }
          else {
            $ttext = 'Version initiale du !date';
          }
        }
        else {
          return '';
        }
        break;
      case 'VIGUEUR':
        if ($article_of_toc) {
          $ttext = 'Version de cet article consolidée au !date';
        }
        else {
          $ttext = 'Version consolidée au !date';
        }
        break;
      case 'VIGUEUR_DIFF':
        $date = $article_of_toc ? $node->page_data['date_debut_art'] : $node->page_data['date_debut'];

        if (!_batire_site_is_real_date($date)) {
          return '';
        }

        //we have to check the date of doc, and print no date if year is older than 10
        $year = date('Y', _batire_site_get_date_in_format($date, 'd/m/Y'));
        $current_year = date('Y');

        if ($year > $current_year + 10) {
          return t('Version à venir');
        }

        if ($date) {
          if ($article_of_toc) {
            $ttext = 'Version de cet article à venir au !date';
          }
          else {
            $ttext = 'Version à venir au !date';
          }
        }

        break;
      case 'ABROGE':
        $date = $article_of_toc ? $node->page_data['date_fin_art'] : $node->page_data['date_fin'];

        if ($date) {
          if ($article_of_toc) {
            $ttext = 'Version de cet article abrogée au !date';
          }
          else {
            $ttext = 'Version abrogée au !date';
          }
        }

        break;
      case 'ABROGE_DIFF':
        $date = $article_of_toc ? $node->page_data['date_fin_art'] : $node->page_data['date_fin'];

        if ($date) {
          if ($article_of_toc) {
            $ttext = 'Version de cet article abrogée différée au !date';
          }
          else {
            $ttext = 'Version abrogée différée au !date';
          }
        }

        break;
      case 'ANNULE':
        $date = $article_of_toc ? $node->page_data['date_fin_art'] : $node->page_data['date_fin'];

        if ($date) {
          if ($article_of_toc) {
            $ttext = 'Version de cet article annulée au !date';
          }
          else {
            $ttext = 'Version annulée au !date';
          }
        }

        break;
      case 'DISJOINT':
        $date = $article_of_toc ? $node->page_data['date_debut_art'] : $node->page_data['date_debut'];

        if ($date) {
          if ($article_of_toc) {
            $ttext = 'Version de cet article disjointe au !date';
          }
          else {
            $ttext = 'Version disjointe au !date';
          }
        }

        break;
      case 'PERIME':
        $date = $article_of_toc ? $node->page_data['date_fin_art'] : $node->page_data['date_fin'];

        if ($date) {
          if ($article_of_toc) {
            $ttext = 'Version de cet article périmée au !date';
          }
          else {
            $ttext = 'Version périmée au !date';
          }
        }

        break;
      case 'SUBSTITUE':
        $date = $article_of_toc ? $node->page_data['date_debut_art'] : $node->page_data['date_debut'];

        if ($date) {
          if ($article_of_toc) {
            $ttext = 'Version de cet article substituée au !date';
          }
          else {
            $ttext = 'Version substituée au !date';
          }
        }

        break;
      case 'MODIFIE_MORT_NE':
        if ($date) {
          if ($article_of_toc) {
            $ttext = 'Version de cet article mort-né au !date';
          }
          else {
            $ttext = 'Version mort-né au !date';
          }
        }

        break;
      case 'TRANSFERE':
        $date = $article_of_toc ? $node->page_data['date_fin_art'] : $node->page_data['date_fin'];

        if ($date) {
          if ($article_of_toc) {
            $ttext = 'Version de cet article transférée au !date';
          }
          else {
            $ttext = 'Version transférée au !date';
          }
        }

        break;
      case 'MODIFIE':
        $date = $article_of_toc ? $node->page_data['date_debut_art'] : $node->page_data['date_debut'];

        if ($date) {
          if ($article_of_toc) {
            $ttext = 'Version de cet article modifiée au !date';
          }
          else {
            $ttext = 'Version modifiée au !date';
          }
        }

        break;
    }
  }

  if (!_batire_site_is_real_date($date)) {
    return '';
  }

  $date = _batire_site_get_date_in_format($date, 'd F Y');


  if ($date) {
    return t($ttext, array('!date' => $date));
  }
  return false;
}

/**
 * Get search sub fields content
 * @param $node Node
 * @return subfield
 */
function _batire_get_doc_search_sub_fields($node) {
  switch ($node->type) {
    default:
    case BATIRE_SITE_CT_TO:
      $sub_title = '';
      break;

    case BATIRE_SITE_CT_CODE:
      $sub_title = array();
      if (!empty($node->type_source_off)) {
        $sub_title[] = '<span class="text-14">' . $node->type_source_off . '</span>';
      }
      break;

    case BATIRE_SITE_CT_FM:
      $sub_title = array();
      if (!empty($node->type_source_off)) {
        $sub_title[] = '<span class="text-14">' . $node->type_source_off . '</span>';
      }
//@todo need add field_syblayer_level_title
      if (!empty($node->doc_created)) {
        $sub_title[] = _batire_site_get_date_in_format($node->doc_created, 'F Y');
      }
      if (!empty($node->field_sublayer_level_title)) {
        $sub_title[] = $node->field_sublayer_level_title;
      }
      break;

    case BATIRE_SITE_CT_LIVRE:
      $sub_title = array();
      if (!empty($node->type_source_off)) {
        $sub_title[] = '<span class="text-14">' . $node->type_source_off . '</span>';
      }
      if (isset($node->field_section_title)) {
        $sub_title[] = $node->field_section_title;
      }
      if (isset($node->field_part_title)) {
        $sub_title[] = $node->field_part_title;
      }
//@todo need add field_section_title
//@todo need add field_part_title
      if (!empty($node->doc_created)) {
        $sub_title[] = _batire_site_get_date_in_format($node->doc_created, 'Y');
      }
      break;

    case BATIRE_SITE_CT_TN:
      $sub_title = '';
      if (!empty($node->title)) {
        $sub_title .= '<span class="text-14">' . $node->title . '</span><br />';
      }
      /*if (!empty($node->field_h1_title)) {
        $sub_title .= '<span class="text-14"><b>' . $node->field_h1_title . '</b></span>';
      }*/
      if (!empty($node->doc_created)) {
        /*if (!empty($node->field_h1_title)) {
          $sub_title .= ' - ';
        }*/
        $sub_title .= _batire_site_get_date_in_format($node->doc_created, 'F Y');
      }
//@todo temp this field is empty
      if (!empty($node->field_annuler)) {
        $sub_title .= ' - ' . t('Annulée');
      }

      break;
    case BATIRE_SITE_CT_COMP_TECH:
      $sub_title = '';
      if (!empty($node->doc_created)) {
        $sub_title[] = _batire_site_get_date_in_format($node->doc_created, 'F Y');
      }
      break;

    case BATIRE_SITE_CT_ACTUALITE:
      $sub_title = array();
      if (!empty($node->type_source_off)) {
        $sub_title[] = '<span class="text-14">' . $node->type_source_off . '</span>';
      }
      if (!empty($node->doc_created)) {
        $sub_title[] = _batire_site_get_date_in_format($node->doc_created, 'd/m/Y');
      }
      break;

    case BATIRE_SITE_CT_DOC_PRAT:
      $sub_title = array();
      break;
  }

  return is_array($sub_title) ? implode(' - ', $sub_title) : $sub_title;
}

/**
 * Create link to node for search results page
 * @param $text Text of the link
 * @param $nid Node nid
 */
function _batire_build_node_link_search($text, $nid, $sl = NULL, $attr = array(), $fragment = NULL) {
  $args = arg();
  $sl = (!empty($sl)) ? $sl : $args[2];
  $url_query = array('sl' => $sl);
  if (!empty($args[3])) {
    $url_query['sl'] .= '-' . $args[3];
  }
  if(isset($_GET['sort_by'])) {
    $url_query['sort_by'] = $_GET['sort_by'];
  }
  if(isset($_GET['sort_order'])) {
    $url_query['sort_order'] = $_GET['sort_order'];
  }
  if(isset($_GET['page'])) {
    $url_query['page'] = $_GET['page'];
  }
  $attributes = array(
    'html' => TRUE,
    'query' => $url_query,
    'attributes' => $attr,
    'fragment' => $fragment,
  );
  return theme('batire_link', $text, 'node/' . $nid, $attributes);
}
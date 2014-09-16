<?php
//pdf_to_imagefield_source_filefield
/*function batire_pdf_source_filefield($node) {
  if (isset($node->type) && $node->type == 'resource') {
    $type = content_types($node->type);
    if (isset($type['fields']['field_view_file'])) {
      $type['fields']['field_view_file']['widget']['target_imagefield'] = 'field_pdf_image';
      return $type['fields']['field_view_file'];
    }
  }
  return array();
}

function batire_pdf_node_presave(&$node) {
  $type = content_types($node->type);
  $source_filefield_def = batire_pdf_source_filefield($node);
  $source_filefield = $source_filefield_def['field_name'];
  $target_imagefield = $source_filefield_def['widget']['target_imagefield'];
  $target_imagefield_def = $type['fields'][$target_imagefield];

  // Is the source filefield full and the target image holder empty?
  if (!pdf_to_imagefield_empty_filefield($node->{$source_filefield}) && pdf_to_imagefield_empty_filefield($node->{$target_imagefield})) {

    // Select the pdf entry(s?) in the specified filefield.
    // Usually just one
    foreach ($node->{$source_filefield} as $pdf_file) {
      if ($target_imagefield_def['multiple']) {
        // Add this job to the queue;
        // Only if there is a nid to tell it (node is not new)
        if ($node->nid) {
          pdf_to_imagefield_set_batch($node, $pdf_file, $source_filefield_def);
        }
      }
      else {
        // Multiple is off, so we will only do the cover page.
        // We can do this immediately.
        // Generate the cover page as a managed image file.
        watchdog('pdf_to_imagefield', 'Generating a cover page for PDF %title .', array('%title' => $node->title), WATCHDOG_NOTICE);
        $image_file = pdf_to_imagefield_generate_page($pdf_file, $source_filefield_def, 0);

        // CCK complains a little if the new field doesn't have a data array attached.
        // Pointless, but it removes a strict warning.
        $image_file->data = array();

        // And attach to the node
        if ($image_file) {
          $node->{$target_imagefield}[0] = (array) $image_file;
          watchdog('pdf_to_imagefield', 'Attaching new file as a cover page to %title .', array('%title' => $node->title), WATCHDOG_NOTICE);
        }
      }
      // node_save will do the rest later
    }
  }
  // On the other hand, if the filefield is empty and the images full, 
  // the original has just been deleted. filefield widget does that
  // earlier - to early for me to get in on it.
  // So, delete these derived images.
  if (pdf_to_imagefield_empty_filefield($node->{$source_filefield}) && !pdf_to_imagefield_empty_filefield($node->{$target_imagefield})) {
    watchdog('pdf_to_imagefield', 'Deleting all the image fields previously attached to %title as derivatives of the deleted PDF file.', array('%title' => $node->title), WATCHDOG_NOTICE);
    foreach ($node->{$target_imagefield} as $i => $image_file ) {
      $removed_file = field_file_load($image_file['fid']);
      field_file_delete($image_file);
      unset($node->{$target_imagefield}[$i]);
    }
  }
}

function batire_pdf_node_insert(&$node) {
  $type = content_types($node->type);
  $source_filefield_def = batire_pdf_source_filefield($node);
  $source_filefield = $source_filefield_def['field_name'];
  $target_imagefield = $source_filefield_def['widget']['target_imagefield'];
  $target_imagefield_def = $type['fields'][$target_imagefield];

  // Is the source filefield full and the target image holder empty?
  if (!pdf_to_imagefield_empty_filefield($node->{$source_filefield}) && pdf_to_imagefield_empty_filefield($node->{$target_imagefield})) {
    // Select the pdf entry(s?) in the specified filefield.
    foreach ($node->{$source_filefield} as $pdf_file) {
      if ($target_imagefield_def['multiple']) {
        // Add this job to the queue. Needed to run post-save so we can tell the batch call about the nid.
        pdf_to_imagefield_set_batch($node, $pdf_file, $source_filefield_def);
      }
    }
  }
}*/

function batire_pdf_to_imagefield_pdftoppm_convert_pdf($source, $dest, $page_number = 0, $args = array()) {
  if(variable_get('pdftoppm_type', 'pdftoppm_without_png') == 'pdftoppm_with_png') {
    $command = ' -png -f ' . $page_number . ' -l ' . $page_number . ' ' . escapeshellarg($source) . ' > ' . escapeshellarg($dest);
  }
  else {
    $command = '';
    if($page_number != 'all') {
      $command = ' -f ' . $page_number . ' -l ' . $page_number;
    }
    $command .= ' ' . escapeshellarg($source) . ' ' . escapeshellarg($dest);
  }

  if (variable_get('imageapi_imagemagick_debugging', FALSE)) {
    watchdog('batire_pdf', 'batire_pdf_to_imagefield_pdftoppm_convert_pdf: $command = ' . $command);
  }
  if (0 != _pdftoppm_convert_exec($command, $output, $errors)) {
    $errors_txt = '<pre>' . (is_array($errors) ? implode("\n", $errors) : $errors) . '</pre>';
    watchdog('pdf to image: imageapi imagemagick', '!errors', array('!errors' => $errors_txt), WATCHDOG_ERROR);
    return FALSE;
  }  

  if(variable_get('pdftoppm_type', 'pdftoppm_without_png') == 'pdftoppm_with_png') {
    return file_exists($dest);
  }
  else {
    if($page_number == 'all') {
      $page_number = '000001';
    }
    return file_exists($dest . '-' . batire_pdf_to_image_leading_zeros($page_number) . '.ppm');
  }
}

function _pdftoppm_convert_exec($command_args, &$output, &$errors) {
  $convert_path = variable_get('batire_path_to_pdf_image_library', '/usr/bin/pdftoppm');
  if ($errors = _imageapi_imagemagick_check_path($convert_path)) {
    watchdog('batire_pdf_pdftoppm', '!errors', array('!errors' => implode('<br />', $errors)), WATCHDOG_ERROR);
    return FALSE;
  }

  // Specify Drupal's root as the working a working directory so that relative
  // paths are interpreted correctly.
  $drupal_path = getcwd();

  if (strstr($_SERVER['SERVER_SOFTWARE'], 'Win32') || strstr($_SERVER['SERVER_SOFTWARE'], 'IIS')) {
    // Use Window's start command to avoid the "black window" from showing up:
    // http://us3.php.net/manual/en/function.exec.php#56599
    // Use /D to run the command from PHP's current working directory so the
    // file paths don't have to be absolute.
    $convert_path = 'start "window title" /D'. escapeshellarg($drupal_path) .' /B '. escapeshellarg($convert_path);
  }

  $descriptors = array(
    0 => array('pipe', 'r'), // stdin
    1 => array('pipe', 'w'), // stdout
    2 => array('pipe', 'w')  // stderr
  );
  if ($h = proc_open($convert_path .' '. $command_args, $descriptors, $pipes, $drupal_path)) {
    $output = '';
    while (!feof($pipes[1])) {
      $output .= fgets($pipes[1]);
    }

    $errors = '';
    while (!feof($pipes[2])) {
      $errors .= fgets($pipes[2]);
    }

    fclose($pipes[0]);
    fclose($pipes[1]);
    fclose($pipes[2]);
    $return_code = proc_close($h);

    // Display debugging information to authorized users.
    if (variable_get('imageapi_imagemagick_debugging', FALSE) && user_access('administer site configuration')) {
      drupal_set_message(t('pdftoppm command: @command', array('@command' => $convert_path .' '. $command_args)));
      drupal_set_message(t('pdftoppm output: @output', array('@output' => $output)));
    }

    if (($return_code == 99 || $return_code == 1) && $command_args == '-h') {
      $output = $errors;
      // Some versions of ImageMagick return status code 1 when outputting the
      // version info. This should not be caught as an error.
    }
    else if ($return_code != 0) {
      // If ImageMagick returned a non-zero code, trigger a PHP error that will
      // be caught by Drupal's error handler, logged to the watchdog and
      // eventually displayed to the user if configured to do so.

      // If $errors is empty, only report the error code.
      if (empty($errors)) {
        trigger_error(t('pdftoppm reported error code !code.', array('!code' => $return_code)), E_USER_ERROR);
      }
      // Otherwise report the error code, and the error message.
      else {
        trigger_error(t("pdftoppm reported error code !code.\nMessage:\n!error", array('!code' => $return_code, '!error' => $errors)), E_USER_ERROR);
      }
    }

    return $return_code;
  }
  return FALSE;
}

/**
 * Generate a single page for the given pdf file-source
 *
 * @param $pdf a attached file data array
 * @return path to png file
 */
function batire_pdf_to_image_generate_page($pdf, $page_number = 0) {
  $path = str_replace('page-files', 'pdf_to_image', dirname($pdf['filepath']));
  
  $image_filename = basename($pdf['filepath']) . '-' . batire_pdf_to_image_leading_zeros($page_number + 1) . '.png';
  $image_filepath = $path . '/' . $image_filename;

  if (file_exists($image_filepath)) {
    return $image_filepath;
  }

  if (variable_get('pdftoppm_type', 'pdftoppm_without_png') == 'pdftoppm_without_png') {
    $ppm_image_filepath = $image_filepath . '-' . batire_pdf_to_image_leading_zeros($page_number + 1) . '.ppm';
    if(file_exists($ppm_image_filepath)) {
      return $ppm_image_filepath;
    }
  }
  
  if(!batire_pdf_to_image_check_directory($path)) {
    return FALSE;
  }
  
  if(batire_pdf_to_imagefield_pdftoppm_convert_pdf($pdf['filepath'], $image_filepath, $page_number + 1, array())) {
    if (variable_get('pdftoppm_type', 'pdftoppm_without_png') == 'pdftoppm_with_png') {
      return $image_filepath;
    }
    else {
      return $ppm_image_filepath;
    }
  }
  else {
    return FALSE;
  }
  // if no file, something must have failed. Too bad.
}

/**
 * @param array $pdf the cck data row being processed.
 */
function batire_pdf_to_image_generate_pages($pdf) {
  if($pdf['filemime'] != 'application/pdf' || !file_exists($pdf['filepath'])) {
    return FALSE;
  }

  $count = pdf_to_imagefield_count_pages($pdf['filepath']);
  $images = array();

  // if count succeeded (some PDFs don't work) then set the batch job page-by-page
  // so we can see the progress
  if ($count && intval($count)) {
    if (variable_get('pdftoppm_type', 'pdftoppm_without_png') == 'pdftoppm_with_png') {
      for ($page = 0; $page < $count; $page++) {
        if($image = batire_pdf_to_image_generate_page($pdf, $page)) {
          if(!filesize($image)) {
            unlink($image);
            break;
          }
          $images[] = $image;
        }
        else {
          break;
        }
      }
    }
    else {
      $path = str_replace('page-files', 'pdf_to_image', dirname($pdf['filepath']));

      $image_filename = basename($pdf['filepath']);
      $image_filepath = $path . '/' . $image_filename;

      if(batire_pdf_to_image_check_directory($path)) {
        return FALSE;
      }

      for ($page = 0; $page < $count; $page++) {
        if(file_exists($image_filepath . '-' . batire_pdf_to_image_leading_zeros($page + 1) . '.png')) {
          $images[] = $image_filepath . '-' . batire_pdf_to_image_leading_zeros($page + 1) . '.png';
        }
        else {
          $images = array();
          break;
        }
      }

      if(!$images && batire_pdf_to_imagefield_pdftoppm_convert_pdf($pdf['filepath'], $image_filepath, 'all', array())) {
        for ($page = 0; $page < $count; $page++) {
          $images[] = $image_filepath . '-' . batire_pdf_to_image_leading_zeros($page + 1) . '.ppm';
        }
      }
    }
  }
  else {
    $count = 0;
    $flag = 1;
    while ($flag) {
      if($image = batire_pdf_to_image_generate_page($pdf, $count)) {
        if(!filesize($image)) {
          $flag = 0;
          unlink($image);
        }
        else {
          $images[] = $image;
        }
      }
      else {
        $flag = 0;
      }
      $count++;
    }
  }

  if (count($images) && variable_get('pdftoppm_type', 'pdftoppm_without_png') == 'pdftoppm_without_png') {
    $images = batire_pdf_to_image_convert_ppm_to_png(basename($pdf['filepath']), $images);
  }
  
  if(count($images)) {
    return $images;
  }
  else {
    return FALSE;
  }
}

function batire_pdf_to_image_convert_ppm_to_png($pdf_name, $images) {
  $base_path = dirname($images[0]) . '/' . $pdf_name;
  $descriptors = array(
    0 => array('pipe', 'r'), // stdin
    1 => array('pipe', 'w'), // stdout
    2 => array('pipe', 'w')  // stderr
  );

  // Specify Drupal's root as the working a working directory so that relative
  // paths are interpreted correctly.
  $drupal_path = getcwd();
  $flag = TRUE;
  $mask = '00000';
  $images_count = count($images);
  
  while($flag) {
    $scene = (int)$mask * 10;
    if($scene > $images_count) {
      $flag = FALSE;
    }
    else {
      if(glob($base_path . '-' . $mask . '*.ppm')) {
        if($scene == 0) {
          $scene = 1;
        }
        $command = 'convert ' . $base_path . '-' . $mask . '*.ppm -scene ' . $scene . ' ' . $base_path . '-%06d.png';

        if ($h = proc_open($command, $descriptors, $pipes, $drupal_path)) {
          $output = '';
          while (!feof($pipes[1])) {
            $output .= fgets($pipes[1]);
          }

          $errors = '';
          while (!feof($pipes[2])) {
            $errors .= fgets($pipes[2]);
          }

          fclose($pipes[0]);
          fclose($pipes[1]);
          fclose($pipes[2]);
          $return_code = proc_close($h);

          if ($return_code != 0) {
            // If ImageMagick returned a non-zero code, trigger a PHP error that will
            // be caught by Drupal's error handler, logged to the watchdog and
            // eventually displayed to the user if configured to do so.

            $flag = FALSE;
            // If $errors is empty, only report the error code.
            if (empty($errors)) {
              trigger_error(t('ppm convert reported error code !code.', array('!code' => $return_code)), E_USER_ERROR);
            }
            // Otherwise report the error code, and the error message.
            else {
              trigger_error(t("ppm convert reported error code !code.\nMessage:\n!error", array('!code' => $return_code, '!error' => $errors)), E_USER_ERROR);
            }
          }
        }
        else {
          $flag = FALSE;
        }
      }

      $mask = str_pad((int)$mask + 1, 5, '0', STR_PAD_LEFT);
    }
  }

  $new_images = array();
  foreach ($images as $key => $image) {
    if(file_exists($base_path . '-' . batire_pdf_to_image_leading_zeros($key + 1) . '.png')) {
      $new_images[] = $base_path . '-' . batire_pdf_to_image_leading_zeros($key + 1) . '.png';
      if($image != $base_path . '-' . batire_pdf_to_image_leading_zeros($key + 1) . '.png') {
        unlink($image);
      }
    }
    else {
      return array();
    }
  }

  return $new_images;
}

function batire_pdf_to_image_leading_zeros($number) {
  return str_pad($number, 6, '0', STR_PAD_LEFT);
}

function batire_pdf_to_image_check_directory($path) {
  $dir_error = FALSE;
  $destination_path = file_directory_path() . '/pdf_to_image';
  if (!file_check_directory($destination_path)) {
    $old = umask(0);
    if(!@mkdir($destination_path, 0775, TRUE)) {
      $dir_error = TRUE;
    }
    umask($old);
  }
  if(!$dir_error) {
    if (!file_check_directory($path)) {
      $old = umask(0);
      if(!@mkdir($path, 0775, TRUE)) {
        $dir_error = TRUE;
      }
      umask($old);
    }
  }

  return $dir_error;
}

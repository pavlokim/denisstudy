<?php

/**
 * Log message
 * @param string $message
 * @param string $filename
 * @param bool $clean
 */
function batire_xml_parse_log($message, $filename, $clean = FALSE) {
  if (variable_get("batire_xml_parse_drush_verbose", FALSE)) {
    drush_print($message);
  }
  if (isset($_SESSION['batire_xml_log_enable']) && $_SESSION['batire_xml_log_enable']) {
    $log_file = variable_get('batire_xml_parse_logpath', LOG_PATH) . $filename . '.log';
    if ($clean) {
      if ($fp = @fopen($log_file, "w")) {
        fclose($fp);
      }
    }
    if (strlen($message)) {
      error_log($message, 3, $log_file);
    }
  }
}

/*
 * Convert date to timestamp
 *
 * @param string $date
 *
 * @return mixed
 */
function batire_xml_parse_convert_date($date) {
  // Replace date delimiters
  $date = str_replace('/', '-', $date);

  $regs = date_parse($date);
  // Check if date was parsed and it is not 2999 year, that means NULL
  if ($regs['error_count'] == 0 && $regs['year'] != '2999') {
    // Use standart PHP function
    $timestamp = strtotime($date);
    if ($timestamp)
      return $timestamp;
    else {
      // Format date to ISO format and use advanced convert for dates > 2038
      $date = date_pad($regs['year']) . '-' . date_pad($regs['month']) . '-' . date_pad($regs['day']) . 'T' . date_pad($regs['hour']) . ':' . date_pad($regs['minute']) . ':' . date_pad($regs['second']);
      $timestamp = date_convert($date, DATE_ISO, DATE_UNIX);
      if ($timestamp)
        return $timestamp;
    }
  }
  return '';
}


/**
 * Store attached file in specified folder
 * (function has some caching for better performance)
 *
 * @param string $filename Attached file name w/o path
 * @param string $path Source path for attached file
 * @param string $store_folder ID of page to create and separate directory for each page
 * @return array File name and path
 */
function batire_xml_parse_add_new_file($filename, $path, $store_folder) {


  $destination_path = BATIRE_XML_PARSE_ATTACHES_PATH . $store_folder;
  $destination_filename = $destination_path . '/' . basename($filename);
  $imagecache_filename = BATIRE_XML_PARSE_ATTACHES_IMAGECACHE_PATH . $store_folder . '/' . basename($filename);
  $result = array(
    'filename' => basename($filename),
    'filepath' => $destination_filename,
    'timestamp' => time()
  );
  $dir_error = FALSE;
  if (!file_check_directory($destination_path)) {
    $old = umask(0);
    if(!@mkdir($destination_path, 0775, TRUE)) {
      $dir_error = TRUE;
    }
    umask($old);
  }
  if($dir_error) {
    // Can't create dir for attached files
    $result['error'] = 'Can\'t create dir for attached files: ' . $destination_path;
    return $result;
  } else {
    if (file_exists($path . '/' . $filename)) {
      if (!@copy($path . '/' . $filename, $destination_filename)) {
        $result['error'] = 'Can\'t store file: ' . $filename;
        return $result;
      } else {
        $extensions = 'jpeg jpg gif tiff png';
        $regex = '/\.('. ereg_replace(' +', '|', preg_quote($extensions)) .')$/i';
        if (preg_match($regex, $imagecache_filename)) {
          @file_delete($imagecache_filename);
        }
      }
    } else {
        $cache = & drupal_static(__FUNCTION__, array());

        if (!array_key_exists($path, $cache)) {
          $cache[$path] = array();
          $items = file_scan_directory($path, '.*');
          foreach ($items as $key => $item) {
            $cache[$path][$item->basename] = $item;
          }
        }

        if (array_key_exists($filename, $cache[$path])) {
          if (!@copy($cache[$path][$filename]->filename, $destination_filename)) {
            $result['error'] = 'Can\'t store file: ' . $filename;
            return $result;
          }
        } else {
          $result['error'] = 'Can\'t find file: ' . $filename;
          return $result;
        }
    }

  }
  $result['filemime'] = file_get_mimetype($destination_filename);
  $result['filesize'] = filesize($destination_filename);
  return $result;
}

/**
 * Find author node by code/title
 *
 * @param string $author Code or title of author
 * @return integer|NULL Node id or NULL
 */
function batire_find_author($author)
{
  $result = db_query_range("SELECT {node}.nid, {node}.title, {content_type_batire_auteur}.field_author_code_value  FROM {node}
LEFT JOIN {content_type_batire_auteur} ON {node}.nid = {content_type_batire_auteur}.nid
WHERE {node}.type = 'batire_auteur' AND ({node}.title LIKE '%s' OR {content_type_batire_auteur}.field_author_code_value LIKE '%s')", $author, $author, 0, 1);
  $obj = db_fetch_object($result);
  return is_object($obj) ? $obj->nid : NULL;
}

/**
 * Search term by description
 *
 * @param type $descr Term description
 * @param type $vid Vocabulary id
 * @return null|int First term id or NULL
 */
function batire_get_tid_by_description($descr, $vid = NULL) {
  $result = batire_xml_parse_search_term($descr, $vid, NULL, 'description');
  return $result ? $result['tid'] : NULL;
}

/**
 * Search term by name
 *
 * @param type $name Term name
 * @param type $vid Vocabulary id
 * @return null|int First term id or NULL
 */
function batire_get_tid_by_name($name, $vid = NULL) {
  $result = batire_xml_parse_search_term($name, $vid, NULL, 'name');
  return $result ? $result['tid'] : NULL;


}

/**
 * Load taxonomy from node
 *
 * @param object $xpath
 * @return array
 */
function batire_xml_get_taxonomy($xpath) {
  module_load_include('inc', 'batire_xml_parse', 'reduce');


  $taxonomy_nodes = $xpath->query('//ns0:indexationTree | //ns1:indexationTree | //gm:indexationTree');
  $result = array();
  if (is_object($taxonomy_nodes) && $taxonomy_nodes->length > 0) {
    foreach ($taxonomy_nodes as $taxonomy_node) {
      $taxonomy_string = $taxonomy_node->nodeValue;
      $taxonomy_array = array_reverse(explode(' ', $taxonomy_string));
      foreach($taxonomy_array as $taxonomy_code) {
        $code = batire_xml_taxonomy_reduce($taxonomy_code);
        $taxonomy_tid = batire_get_tid_by_description($code);
        if ($taxonomy_tid) {
          $result[] = $taxonomy_tid;
          break;
        }
      }
    }
  }
  return $result;
}

/**
 * We just copy this function from CP
 * @param array $link
 * @return string
 */
function batire_xml_parse_normalize_link_type(&$link) {
  // Normalize links type

  // First table
  if ((drupal_strtoupper($link['type']) == 'ABROGE' && $link['sens'] == 'cible') || (drupal_strtoupper($link['type']) == 'ABROGATION' && $link['sens'] == 'source')) {
    $link['type'] = 'ABROGATION';
  } elseif ((drupal_strtoupper($link['type']) == 'CREE' && $link['sens'] == 'cible') || (drupal_strtoupper($link['type']) == 'CREATION' && $link['sens'] == 'source')) {
    $link['type'] = 'CREATION';
  } elseif ((drupal_strtoupper($link['type']) == 'MODIFIE' && $link['sens'] == 'cible') || (drupal_strtoupper($link['type']) == 'MODIFICATION' && $link['sens'] == 'source')) {
    $link['type'] = 'MODIFICATION';
  } elseif ((drupal_strtoupper($link['type']) == 'TRANSFERE' && $link['sens'] == 'cible') || (drupal_strtoupper($link['type']) == 'TRANSFERT' && $link['sens'] == 'source')) {
    $link['type'] = 'TRANSFERT';
  } elseif ((drupal_strtoupper($link['type']) == 'PERIME' && $link['sens'] == 'cible') || (drupal_strtoupper($link['type']) == 'PEREMPTION' && $link['sens'] == 'source')) {
    $link['type'] = 'PEREMPTION';
  } elseif ((drupal_strtoupper($link['type']) == 'DISJOINT' && $link['sens'] == 'cible') || (drupal_strtoupper($link['type']) == 'DISJONCTION' && $link['sens'] == 'source')) {
    $link['type'] = 'DISJONCTION';
  } elseif ((drupal_strtoupper($link['type']) == 'ANNULE' && $link['sens'] == 'cible') || (drupal_strtoupper($link['type']) == 'ANNULATION' && $link['sens'] == 'source')) {
    $link['type'] = 'ANNULATION';
  } elseif (drupal_strtoupper($link['type']) == 'CITATION' && $link['sens'] == 'cible') {
    $link['type'] = 'CITE';
  }
  // Second table
  elseif ((drupal_strtoupper($link['type']) == 'ABROGATION' && $link['sens'] == 'cible') || (drupal_strtoupper($link['type']) == 'ABROGE' && $link['sens'] == 'source')) {
    $link['type'] = 'ABROGE';
  } elseif ((drupal_strtoupper($link['type']) == 'CREATION' && $link['sens'] == 'cible') || (drupal_strtoupper($link['type']) == 'CREE' && $link['sens'] == 'source')) {
    $link['type'] = 'CREE';
  } elseif ((drupal_strtoupper($link['type']) == 'MODIFICATION' && $link['sens'] == 'cible') || (drupal_strtoupper($link['type']) == 'MODIFIE' && $link['sens'] == 'source')) {
    $link['type'] = 'MODIFIE';
  } elseif ((drupal_strtoupper($link['type']) == 'TRANSFERT' && $link['sens'] == 'cible') || (drupal_strtoupper($link['type']) == 'TRANSFERE' && $link['sens'] == 'source')) {
    $link['type'] = 'TRANSFERE';
  } elseif ((drupal_strtoupper($link['type']) == 'PEREMPTION' && $link['sens'] == 'cible') || (drupal_strtoupper($link['type']) == 'PERIME' && $link['sens'] == 'source')) {
    $link['type'] = 'PERIME';
  } elseif ((drupal_strtoupper($link['type']) == 'DISJONCTION' && $link['sens'] == 'cible') || (drupal_strtoupper($link['type']) == 'DISJOINT' && $link['sens'] == 'source')) {
    $link['type'] = 'DISJOINT';
  } elseif ((drupal_strtoupper($link['type']) == 'ANNULATION' && $link['sens'] == 'cible') || (drupal_strtoupper($link['type']) == 'ANNULE' && $link['sens'] == 'source')) {
    $link['type'] = 'PERIME';
  }
  return $link;
}


/**
 * Read links from document xml
 * @param object $xpath
 * @param string $doc_type
 * @return array
 */
function batire_xml_get_links($xpath, $doc_type) {
  $domNodeList = $xpath->query("//lien[(not(@coquillevide) or @coquillevide='false')]");
  $result = array();
  if (is_object($domNodeList) && $domNodeList->length) {
    foreach ($domNodeList as $domNode) {
      $lien_id = @$domNode->attributes->getNamedItem('id')->nodeValue;
      $lien_id_sir = @$domNode->attributes->getNamedItem('idsir')->nodeValue;
      $lien_type = @$domNode->attributes->getNamedItem('typelien')->nodeValue;
      $lien_doc_type = @$domNode->attributes->getNamedItem('naturetexte')->nodeValue;

      $lien_id = $lien_id_sir ? $lien_id_sir : $lien_id;

      if (!$lien_id)
        $lien_id = '00000000';

      if ($lien_id) {
        $type_doc = @$domNode->attributes->getNamedItem('type-doc')->nodeValue;
        if (empty($type_doc)) {
          $type_doc = batire_xml_node_value_get($xpath, '/qc:doc-root/qc:doc-meta/ns0:type-doc');
        }

        if (!empty($type_doc)) {
          switch ($type_doc) {
            case 'NORME':
              $doc_type = BATIRE_HIERARCHY_DT_TEXTE_NORMATIF;

              break;
            case 'SO':
              $lien_id = @$domNode->attributes->getNamedItem('id')->nodeValue;

              if (!empty($lien_doc_type) && $lien_doc_type == 'CODE') {
                $doc_type = BATIRE_HIERARCHY_DT_CODE;
              }
              else {
                $doc_type = BATIRE_HIERARCHY_DT_TEXTE_OFFICIEL;
              }

              break;
          }
        }

        $link = array(
            'id' => $lien_id,
            'bid' => batire_hierarchy_get_document_bid($lien_id, $doc_type),
            'title' => trim($domNode->nodeValue),
            'type' => $lien_type,
            'sens' => @$domNode->attributes->getNamedItem('sens')->nodeValue,
          );
        $result[] = batire_xml_parse_normalize_link_type( $link );
      }
    }
  }
  return $result;
}

/**
 * Internal helper, for managing cck field
 *
 * @param array $field
 * @param string $key
 * @param mixed $value
 * @return array
 */
function batire_add_cck_field_value($field, $key, $value) {

  if (is_null($field) || empty($value)) {
    return $field;
  }
  if (!is_array($field)) {
    $field = array();
  }
  foreach($field as $subfield){
    if (isset($subfield[$key]) && $subfield[$key] == $value) {
      return $field;
    }
  }
  $field[] = array($key => $value);
  return $field;
}


/**
 * Our exception
 *
 * @todo Move to another file
 */
class Batire_Xml_Parse_Exception extends Exception
{

}

/**
 * Invoke hook_batire_xml_parseapi()
 * @param string $op
 * @param array $data
 * @param mixed $dom
 * @param mixed $arg4
 * @param mixed $arg5
 * @return array
 */
function batire_xml_parse_invoke_parseapi($op, &$data, $dom = NULL, $arg4 = NULL, $arg5 = NULL) {
  $return = array();
  foreach (module_implements('batire_xml_parseapi') as $name) {
    $function = $name . '_batire_xml_parseapi';
    $result = $function($op, $data, $dom, $arg4, $arg5);
    if (isset($result) && is_array($result)) {
      $return = array_merge($return, $result);
    } elseif (isset($result)) {
      $return[] = $result;
    }
  }
  return $return;
}

/**
 * Unzip archive to specified folder
 *
 * @param string $zip path to archive
 * @param string $destination destination folder
 *
 * @return bool operation status
 *
 */
function _batire_xml_parse_unzip($zip, $destination) {
  $cmd = '`which unzip` ' . escapeshellcmd($zip) . ' -d ' . escapeshellcmd($destination);
  $output = $return = NULL;
  exec($cmd, $output, $return);
  return $return ? FALSE : TRUE;
}

/**
 * Initiate and return XPath object
 *
 * @staticvar array $cache
 * @param DOMDocument $dom DOM document
 * @param array $namespaces Namespaces mapping in form "prefix" => "URI"
 * @return DOMXPath
 */
function batire_xml_get_xpath($dom, $namespaces = NULL) {
  static $cache = array();
  if (is_null($namespaces)) {
    $namespaces = batire_xml_default_prefixes();
  }
  $key = crc32($dom->documentURI . ':' . implode($namespaces) . ':' . implode(array_keys($namespaces)));
  if (!array_key_exists($key, $cache)) {
    $xpath = new DOMXPath($dom);
    foreach ($namespaces as $name => $uri) {
      $xpath->registerNamespace($name, $uri);
    }
    $cache[$key] = $xpath;
  }
  return $cache[$key];
}

/**
 * Run xpath query and return result
 *
 * @param DOMXPath $xpath
 * @param string $query
 * @param DOMElement $dom_node Dome node for relative query
 * @return DOMNodeList
 */
function batire_xml_xpath_run_query($xpath, $query, $dom_node = NULL) {
  $errors = libxml_get_errors();
  $result =  $dom_node ? $xpath->query($query, $dom_node) : $xpath->query($query);
  if (count(libxml_get_errors()) != count($errors)) {
    return NULL;
  }
  return $result;
}

/**
 *
 * @param DOMXPath $xpath
 * @param string $attribute_name
 * @param string $xpath_query
 * @return string
 */
function batire_xml_attribute_get($xpath, $attribute_name, $xpath_query = "./", $dom_node = NULL) {
  $nodes = batire_xml_xpath_run_query($xpath, $xpath_query, $dom_node);
  if ($nodes && $nodes->length) {
    $node = $nodes->item(0);
    return $node->getAttrib($attribute_name);
  }
  return FALSE;
}

/**
 * Run xpath query and return first node value
 *
 * hint: you can use this function for attribute fecthing too, juust use query like 'node/@attr'
 *
 * @param DOMXPath $xpath
 * @param string $xpath_query
 * @param DOMElement $dom_node Dome node for relative query
 * @return string
 */
function batire_xml_node_value_get($xpath, $xpath_query, $dom_node = NULL) {

  $nodes = batire_xml_xpath_run_query($xpath, $xpath_query, $dom_node);
  if ($nodes && $nodes->length) {
    $node = $nodes->item(0);
    return $node->nodeValue;
  } elseif (is_null($nodes)) {
    return $nodes;
  }
  return FALSE;
}

/**
 * return list of default prefixes
 *
 * @return type
 */
function batire_xml_default_prefixes() {
  return array(
    'ns0' => 'http://groupemoniteur.fr/',
    'ns1' => 'http://groupemoniteur.fr/',
    'xms' => 'http://xms.4dconcept.fr/',
    'qc' => 'http://4dconcept.com/QuadroContent',
    'gm' => 'http://groupemoniteur.fr/'
  );
}

/**
 * Run xpath queries and return array with finded node values
 *
 * @param DOMXPath $xpath
 * @param array $xpath_queries Array like $key => $xpath_query
 * @param DOMElement $dom_node Dome node for relative query
 * @return array
 */
function batire_xml_multiple_node_value_get($xpath, $xpath_queries,  $dom_node = NULL) {
  $result = array();
  foreach($xpath_queries as $key => $xpath_query) {
    $result[$key] = batire_xml_node_value_get($xpath, $xpath_query, $dom_node);
  }
  return $result;
}

/**
 * Run xpath query and return XML of first node value
 *
 * @param DOMXPath $xpath
 * @param string $xpath_query
 * @param DOMElement $dom_node Dome node for relative query
 * @return string
 */
function batire_xml_node_xml_get($xpath, $xpath_query, $dom_node = NULL) {

  $nodes = batire_xml_xpath_run_query($xpath, $xpath_query, $dom_node);
  if ($nodes && $nodes->length) {
    return $xpath->document->saveXML($nodes->item(0));
  } elseif (is_null($nodes)) {
    return $nodes;
  }
  return FALSE;
}

/**
 * Run xpath query and return inner XML of first node value
 *
 * @param DOMXPath $xpath
 * @param string $xpath_query
 * @param DOMElement $dom_node Dome node for relative query
 * @param array $exclude Excludes list, in uppercase
 * @param bool $avoid_tags Remove first level tags
 * @return string
 */
function batire_xml_node_xml_inner_get($xpath, $xpath_query, $dom_node = NULL, $exclude = array(), $avoid_tags = FALSE, $with_empty = FALSE) {
  $exclude = array_map('strtoupper', $exclude);
  $nodes = batire_xml_xpath_run_query($xpath, $xpath_query, $dom_node);
  if ($nodes && $nodes->length) {
    $result = array();
    $node = $nodes->item(0);
    foreach($node->childNodes as $child) {
      if (!in_array(strtoupper($child->nodeName), $exclude) && (strlen(trim($child->nodeValue)) || $with_empty || (strtoupper($child->nodeName) == 'BR'))) {
        $result[] = ($child->nodeName != '#text' && $avoid_tags) ? implode(" \n", batire_xml_node_xml_inner_get($xpath, '.', $child)) : trim($xpath->document->saveXML($child));
      }
    }
    return $result;
  } elseif (is_null($nodes)) {
    return $nodes;
  }
  return FALSE;
}



/**
 * Add terms to vocabulary if not exists
 * @param array $raw_terms
 * @param int $vid
 * @param mixed $parent_term
 */
function batire_xml_parse_add_raw_terms($raw_terms, $vid, $parent_term = NULL) {
  $result = array();
  foreach ($raw_terms as $str_term) {
    $parts = explode(':', $str_term, 2);
    $term_name = $parts[0];
    $term_name = preg_replace('/( )+/m', ' ', $term_name); //unicode space
    $term_name = preg_replace('/\s+/m', ' ', $term_name); //only one space

    $term_name = preg_replace('/^\s+/m', '', $term_name); //ltrim
    $term_name = preg_replace('/\s+$/m', '', $term_name); //rtrim
    $term_name = str_replace('’', '\'', $term_name);


    if ($term = batire_xml_parse_search_term($term_name, $vid, $parent_term)) {
    } else {
      $term = array(
        'name' => $term_name,
        'vid' => $vid
      );
      $term['parent'] = array($parent_term);
      taxonomy_save_term($term);
    }
    if (count($parts) > 1) {
      $result = array_merge($result, batire_xml_parse_add_raw_terms(array($parts[1]), $vid, $term['tid']));
    } else {
      $result[] = $term['tid'];
    }
  }
  return $result;
}

/**
 * Search term by name, vocabulary and parent
 * @param string $name
 * @param mixed $vid
 * @param mixed $parent
 * @param string $field
 * @return mixed
 */
function batire_xml_parse_search_term($name, $vid = NULL, $parent = NULL, $field = "name") {
  if ($parent) {
    if (is_array($parent)) {
      $parent = $parent['tid'];
    }
    if ($vid) {
      $sql = "SELECT term_data.* FROM {term_data} JOIN {term_hierarchy} ON  term_hierarchy.tid = term_data.tid WHERE LOWER(term_data.$field) = LOWER('%s') AND term_data.vid = %d AND term_hierarchy.parent = %d";
      $db_result = db_query($sql, $name, $vid, $parent);
    } else {
      $sql = "SELECT term_data.* FROM {term_data} JOIN {term_hierarchy} ON  term_hierarchy.tid = term_data.tid WHERE LOWER(term_data.$field) = LOWER('%s') AND term_hierarchy.parent = %d";
      $db_result = db_query($sql, $name, $parent);
    }
  } else {
    if ($vid) {
      $sql = "SELECT term_data.* FROM {term_data} WHERE LOWER(term_data.$field) = LOWER('%s') AND term_data.vid = %d";
      $db_result = db_query($sql, $name, $vid);
    } else {
      $sql = "SELECT term_data.* FROM {term_data} WHERE LOWER(term_data.$field) = LOWER('%s')";
      $db_result = db_query($sql, $name);
    }
  }
  return db_fetch_array($db_result);
}




function batire_xml_parse_convert_datevalid($date_string) {
  //$date_obj = DateTime::createFromFormat("d/m/Y H:i:s", $date_string);
  $date_obj = _batire_xml_parse_create_from_format("%d/%m/%Y %T", $date_string);
  if (!$date_obj) {
   // $date_obj = DateTime::createFromFormat("d/m/Y H:i:s", $date_string . ' 00:00:00');
    $date_obj = _batire_xml_parse_create_from_format("%d/%m/%Y %T", $date_string . ' 00:00:00');
  }
  if ($date_obj && $date_obj->format('Y') != 2999) {
    return $date_obj->format('U');
  }
  return FALSE;
}

function _batire_xml_parse_create_from_format($strptimeFormat, $date) {
    $date = strptime($date, $strptimeFormat);
    $date['tm_year'] += 1900;
    $date['tm_mon']++;
    $timestamp = mktime($date['tm_hour'], $date['tm_min'], $date['tm_sec'], $date['tm_mon'], $date['tm_mday'], $date['tm_year']);
    return new DateTime('@'. $timestamp);
}

/*
 * Crop dates for FM, Fiche and Dico/Broches
 *
 * @param $date
 *   Date
 * @param type
 *   Type of cropping
 *
 * @return $date
 *  Cropped date
 */
function batire_xml_parse_crop_date($date, $type) {
  $date = str_replace('/', '-', $date);
  $regs = date_parse($date);
  // Check if date was parsed and it is not 2999 year, that means NULL
  if ($regs['error_count'] == 0 && $regs['year'] != '2999') {
    if ($type == 'year') $date = date_pad($regs['year']).'-01-01T00:00:00';
    elseif ($type == 'year_month') $date = date_pad($regs['year']).'-'.date_pad($regs['month']).'-01T00:00:00';
    return $date;
  } else return false;
}

function  _batire_xml_parse_xslt_get_doc_type() {
  $data = _batire_xml_parse_xslt_storage('page_data');
  $page_data = array_pop($data);
  return $page_data['doc_type'];
}

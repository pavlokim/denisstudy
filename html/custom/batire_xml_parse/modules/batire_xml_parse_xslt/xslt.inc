<?php

function _batire_xml_parse_xslt_xml_error_handler($errno, $errstr, $errfile, $errline) {
  if ($errno == E_WARNING && (substr_count($errstr, "DOMDocument::loadXML()") > 0)) {
    throw new DOMException($errstr);
  }
  else {
    return false;
  }
}

function batire_xml_parse_xslt_transform($xml, $template = 'common', $parameters = array(), $encoding = 'UTF-8') {
  static $xslTemplates = array();
  $xsl = drupal_get_path('module', 'batire_xml_parse_xslt') . '/xsl/' . $template . '.xsl';
  if (!file_exists($xsl)) {
    $xsl = drupal_get_path('module', 'batire_xml_parse_xslt') . '/xsl/common.xsl';
  }
  if (array_key_exists($xsl, $xslTemplates)) {
    $proc = $xslTemplates[$xsl];
  }
  else {
    $xslDoc = new DOMDocument();
    $xslDoc->load($xsl);
    set_error_handler('_batire_xml_parse_xslt_xml_error_handler');
    $proc = new XSLTProcessor();
    $proc->registerPHPFunctions();
    $proc->importStylesheet($xslDoc);
    $errors = libxml_get_errors();
    restore_error_handler();
    if ($errors) {
      libxml_clear_errors();
      throw new Batire_Xml_Parse_Exception("XSL related error: " . print_r($errors, TRUE));
    }
    $xslTemplates[$xsl] = $proc;
  }
  set_error_handler('_batire_xml_parse_xslt_xml_error_handler');
  $xmlDoc = new DOMDocument();
  $xmlDoc->encoding = $encoding;
  //@HACK: need review
  $xml = str_replace(array('&hyphen;', '&rsquor;', '&mldr;', '\\', '⇓'), array('-', '&rsquo;', '&hellip;', '&#92;', '&#8595;'), $xml);
  $xml = '<xml>' . $xml . '</xml>';
  $xmlDoc->loadXML($xml);
  $errors = libxml_get_errors();
  restore_error_handler();
  if ($errors) {
    libxml_clear_errors();
    throw new Batire_Xml_Parse_Exception("XML related error: " . print_r($errors, TRUE));
  }

  if (count($parameters)) {
    $proc->setParameter('', $parameters);
  }
  $result = $proc->transformToXML($xmlDoc);
  //remove parameters for cached version
  foreach (array_keys($parameters) as $name) {
    $proc->removeParameter('', $name);
  }
  $errors = libxml_get_errors();

  if ($errors) {
    libxml_clear_errors();
    throw new Batire_Xml_Parse_Exception("XSL related error: " . print_r($errors, TRUE));
  }
  return $result;
}

/** XSL related functions * */
function _batire_xml_parse_xslt_variable($name, $value = NULL) {
  static $variables = array();
  if (!is_null($value)) {
    $variables[$name] = $value;
  }
  elseif (!array_key_exists($name, $variables)) {
    $variables[$name] = NULL;
  }
  return $variables[$name];
}

/** XSL related functions * */
function _batire_xml_parse_xslt_storage($name, $value = NULL) {
  static $storage = array();
  if ($name == "ARRAY") {
    $name = $value;
    $value = array_slice(func_get_args(), 2);
  }
  elseif ($name == "RESET") {
    if ($value) {
      if (array_key_exists($value, $storage)) {
        unset($storage[$value]);
      }
    }
    else {
      $storage = array();
    }
    return;
  }
  if (!array_key_exists($name, $storage)) {
    $storage[$name] = array();
  }
  if (!is_null($value)) {
    $storage[$name][] = $value;
  }
  else {
    return $storage[$name];
  }
}

function _batire_xml_parse_xslt_xml_nivintb($nodes) {
  $output = '';
  $node = $nodes[0];
  $papa = $node->parentNode;
  $id = $papa->getAttribute('ID');
  if ($id) {
    $l = strlen($id);
    $tail_l = 1;
    $pos = stripos($id, '-N');
    if ($pos) {
      $tail_l = (int) (($l - $pos) / 2) - 2;
    }

    $output = '<div class="contenu-titre-' . $tail_l . '">' . $node->nodeValue . '</div>';
  }
  return $output;
}

function _batire_xml_parse_xslt_xml_resume($nodes = NULL) {
  static $output = array();
  if (!$nodes) {
    $out = '';
    if (count($output)) {
      $out = '<div class="contenu-resume-titre clear-block">
        <div class="i">Résumé</div>
      </div>
      <div class="contenu-resume">
        <div class="t">.</div>
        <div class="c"><p>' . implode('<br/><br/>', $output) . '</p><div class="oc"><a class="open" href="javascript: void(0);">Lire</a></div>
        </div>
        <div class="b">.</div>
      </div>';
    }
    $output = array();
    return $out;
  }
  $node = $nodes[0];
  $output[] = $node->nodeValue;

  return '';
}

function _batire_xml_parse_xslt_xml_note($nodes = NULL) {
  static $output = array();
  if (!$nodes) {
    $out = '';
    if (count($output)) {
      $out = '<div class="top-left-points"><div class="contenu-note-1">' . implode('', $output) . '</div></div>';
    }
    $output = array();
    return $out;
  }
  $node = $nodes[0];
  if (!empty($node->nodeValue)) {
    $num = count($output) + 1;
    $note = $node->nodeValue;
    $output[] = '<p>(' . $num . ') ' . $note . '</p>';
    return '<sup>(' . $num . ')</sup>';
  }
  return '';
}

function _batire_xml_parse_xslt_fm_nivid($nodes) {
  $node = $nodes[0];
  $papa = $node->parentNode;
  $id = $papa->getAttribute('ID');

  preg_match('/N([0-9]){2,}$/', $id, $output);
  if ($papa->nodeName == 'NIV1') {
    $result = substr($output[0], 1, 2);
  }
  else {
    $result = substr($output[0], 3);
  }

  return $result ? (int) $result : '';
}

function _batire_xml_parse_xslt_xml_date($lnodes, $format) {
  $lnode = $lnodes[0];
  $dateeff = array();
  $dateeff['year'] = $lnode->getAttribute('an');
  $dateeff['month'] = $lnode->getAttribute('mois');
  $dateeff['day'] = $lnode->getAttribute('jour');

  $dateeff['year'] = is_numeric($dateeff['year']) ? $dateeff['year'] : '1970';
  $dateeff['month'] = is_numeric($dateeff['month']) ? $dateeff['month'] : '01';
  $dateeff['day'] = is_numeric($dateeff['day']) ? $dateeff['day'] : '01';
  $dateeff['date'] = new DateTime($dateeff['year'] . '-' . $dateeff['month'] . '-' . $dateeff['day']);
    if (is_object($dateeff['date'])) {
      return  drupal_ucfirst(format_date($dateeff['date']->format('U'), 'custom', $format));
    } else {
     return  '';
    }

}
function _innerHTML($el) {
  $doc = new DOMDocument();
  $doc->appendChild($doc->importNode($el, TRUE));
  $html = trim($doc->saveHTML());
  $tag = $el->nodeName;
  return preg_replace('@^<' . $tag . '[^>]*>|</' . $tag . '>$@', '', $html);
}

function _batire_xml_parse_xslt_xml_link($lnodes) {
  $data = _batire_xml_parse_xslt_storage("page_data");
  $page_data = array_pop($data);

  $lnode   = $lnodes[0];
  $id      = '';
  $type    = '';
  $anchor  = '';
  $content = _innerHTML($lnode); //->nodeValue;
  switch ($lnode->nodeName) {
    case 'LIEN':
      $id = $lnode->getAttribute('TYPE'). $lnode->getAttribute('DEST');
      $anchor = $lnode->getAttribute('QUALIF');
      $type = $page_data['doc_type'];

      break;
    case 'lien_art':
    case 'lien':
      $fake = $lnode->getAttribute('coquillevide');

      if ($fake == 'true') {
        return $content;
      }

      $id_sir = $lnode->getAttribute('idsir');
      $id_legi = $lnode->getAttribute('id');

      $id = $id_sir ? $id_sir : $id_legi;

      $type_doc = $lnode->getAttribute('type-doc');
      $type_by_doc = '';

      if (!empty($type_doc)) {
        switch ($type_doc) {
          case 'NORME':
            $type_by_doc = BATIRE_HIERARCHY_DT_TEXTE_NORMATIF;

            break;
          case 'SO':
            $id           = $lnode->getAttribute('id');
            $sub_type_doc = $lnode->getAttribute('naturetexte');

            if (!empty($sub_type_doc) && $sub_type_doc == 'CODE') {
              $type_by_doc = BATIRE_HIERARCHY_DT_CODE;
            }
            else {
              $type_by_doc = BATIRE_HIERARCHY_DT_TEXTE_OFFICIEL;
            }

            break;
        }
      }

      $type = (empty($type_by_doc)) ? $page_data['doc_type'] : $type_by_doc;

      break;

    case 'LIENID':
    case 'LIENENT':
    case 'REFNOTEBP':
      $id = $lnode->getAttribute('IDREF');
      $type = $page_data['doc_type'];

      break;
    case 'WWW':
      $url = $lnode->getAttribute('Adresse');
      if (empty($url)) {
        $url = $content;
      }
      if (!preg_match('/\w+:/', $url)) {
        $url = 'http://' . $url;
      }

      if ($url) {
        return l($content, $url);
      }
      break;
  }

  $options = array('html' => TRUE);
  if (isset($anchor) && !empty($anchor)) {
    $options['fragment'] = $anchor;
  }

  if ($id && $type) {
    $bid = batire_hierarchy_get_document_bid($id, $type);
    return l($content, 'document/' . $bid, $options);
  } else {
    return l($content, 'document/UNK-' . $id, $options);
  }
}

function _batire_xml_parse_xslt_get_lien_reference($refid, $inner_content = '') {
  $data = _batire_xml_parse_xslt_storage('page_data');
  $page_data = array_pop($data);

  if (isset($page_data['liens']['lien_reference']) && !empty($page_data['liens']['lien_reference'])) {
    foreach ($page_data['liens']['lien_reference'] as $lien_reference) {
      if ($lien_reference['refid'] == $refid) {
        break;
      }
    }

    switch ($lien_reference['type']) {
      case 'ARTICLE':
        $type = 'ARTICLE';
        $result = '<![CDATA[' . l($inner_content, 'document/' . $lien_reference['bid'], array('html' => TRUE)) . ']]>';
        break;
      case 'FICHE':
        $type = 'FICHE';
        $result = _batire_xml_parse_xslt_get_image_info(NULL, FALSE, $lien_reference);
        break;
      default:
        $type = $lien_reference['type'];
        $result = $inner_content;
        break;
    }

    $xml = '<lien_reference type="' . $type . '">' . $result . '</lien_reference>';
    $doc = new DOMDocument;
    $doc->loadXml($xml);
    return $doc;
  }

  $xml = '<lien_reference type="UNKNOWN" />';
  $doc = new DOMDocument;
  $doc->loadXml($xml);
  return $doc;
}

function _batire_xml_parse_xslt_get_image_info($img, $special = FALSE, $lien_reference = FALSE) {
  if ($lien_reference) {
    $page_data = mongodb_page_get_page_by_bid($lien_reference['bid']);
  }
  else {
    $data = _batire_xml_parse_xslt_storage('page_data');
    $page_data = array_pop($data);
  }

  $print_link  = url('print-image/' . $page_data['nid'] . '/' . $img);
  $print_title = t('Imprimer l\'image');

  $src = FALSE;
  $ext = FALSE;
  $info = FALSE;
  $ext_rate = array('swf' => 0, 'gif' => 1, 'jpg' => 2);

  if (!empty($page_data['attached'])) {
    $attached = array('files' => array(), 'ids' => array(), 'ext' => array());
    foreach ($page_data['attached'] as $file) {
      if ((strpos($file['filename'], $img) === 0) or ($lien_reference && !strpos($file['filename'], '_thumb'))) {
        $file_id_ext = explode('.', end(explode('_ID', $file['filename'])));
        $key = array_search($file_id_ext[1], $attached['ext']);
        if ($key !== FALSE) {
          if ((int)$attached['ids'][$key] < (int)$file_id_ext[0]) {
            $attached['files'][$key] = $file;
            $attached['ids'][$key]   = $file_id_ext[0];
            $attached['ext'][$key]   = $file_id_ext[1];
          }
        }
        else {
          $attached['files'][] = $file;
          $attached['ids'][]   = $file_id_ext[0];
          $attached['ext'][]   = $file_id_ext[1];
        }
      }
    }
    foreach ($attached['files'] as $file) {
      $candidat_ext = strtolower(array_pop(explode(".", $file['filepath'])));
      $candidat_info = image_get_info($file['filepath']);
      if (!$src || $ext_rate[$ext] < $ext_rate[$candidat_ext] || ($ext_rate[$ext] == $ext_rate[$candidat_ext] && $candidat_info['width'] > $info['width'])) {
        $src = $file['filepath'];
        $file_name = $file['filename'];
        $ext = $candidat_ext;
        $info = $candidat_info;
      }
    }
  }
  if ($src) {
    $old_base_url = $GLOBALS['base_url'];
    $GLOBALS['base_url'] = '';
    $zoom_image_src = '';
    $html_image = '';
    $img_width = NULL;
    $img_type = "UNKNOWN";
    if ($info && $ext != 'swf') {
      init_theme();
      $img_type = 'image';
      if ($special == 'formula-artwork') {
        if (!preg_match('/FOR\d*\.(png|PNG)$/', $src)) {
          $special = FALSE;
        }
      }

      //No PNG-only filter
      if ($special == 'formula-artwork-nf') {
        $special = 'formula-artwork';
      }

      if($page_data['type'] == 'batire_texte_normatifs') {
        $ratio = 1.0 / 2.8;
        if ($info['width'] * $ratio > 662) {
          $img_width = 662;
          imagecache_generate_image('batire_document_img', $src);
          $image_src = substr(imagecache_create_url('batire_document_img', $src, NULL, FALSE), 1);
          $html_image = theme("image", $image_src);
          if ($info['width'] * $ratio > 1100) {
            imagecache_generate_image('batire_document_zoom_img', $src);
            $zoom_image_src = "<zoom_image_src>" . imagecache_create_url('batire_document_zoom_img', $src, NULL, FALSE) . "</zoom_image_src>";
          } elseif ($info['width'] * $ratio > 750) {
            imagecache_generate_image('batire_document_image_artwork', $src);
            $zoom_image_src = "<zoom_image_src>" . imagecache_create_url('batire_document_image_artwork', $src, NULL, FALSE) . "</zoom_image_src>";
          }
        } else {
          $img_width = round($info['width'] * $ratio);
          imagecache_generate_image('batire_document_image_artwork', $src);
          $html_image = theme("imagecache", 'batire_document_image_artwork', $src);
        }

        //TN Equation
        if ($special == 'formula-artwork') {
          $img_type = 'tn-equation';
        }
        if ($special == 'inline') {
              $img_width = $info['width'];
              $html_image = theme("image", $src, '', '', array('align' => 'middle'));
        }
      }
      else {
        switch ($special) {
          case 'formula-artwork':
            $ratio = 1.0 / 2.8;
            if ($info['width'] * $ratio > 662) {
              $img_width = 662;
              imagecache_generate_image('batire_document_img', $src);
              $image_src = substr(imagecache_create_url('batire_document_img', $src, NULL, FALSE), 1);
              $html_image = theme("image", $image_src);
              if ($info['width'] * $ratio > 1100) {
                imagecache_generate_image('batire_document_zoom_img', $src);
                $zoom_image_src = "<zoom_image_src>" . imagecache_create_url('batire_document_zoom_img', $src, NULL, FALSE) . "</zoom_image_src>";
              } elseif ($info['width'] * $ratio > 750) {
                imagecache_generate_image('batire_document_image_artwork', $src);
                $zoom_image_src = "<zoom_image_src>" . imagecache_create_url('batire_document_image_artwork', $src, NULL, FALSE) . "</zoom_image_src>";
              }
            } else {
              imagecache_generate_image('batire_document_image_artwork', $src);
              $html_image = theme("imagecache", 'batire_document_image_artwork', $src);
            }
            break;
            case 'inline':
              $img_width = $info['width'];
              $html_image = theme("image", $src, '', '', array('align' => 'middle'));
              break;
          default:
            if ($info['width'] > 662) {
              $img_width = 662;
              imagecache_generate_image('batire_document_img', $src);
              $image_src = substr(imagecache_create_url('batire_document_img', $src, NULL, FALSE), 1);
              $html_image = theme("image", $image_src);
              if ($info['width'] > 1100) {
                imagecache_generate_image('batire_document_zoom_img', $src);
                $zoom_image_src = "<zoom_image_src>" . imagecache_create_url('batire_document_zoom_img', $src, NULL, FALSE) . "</zoom_image_src>";
              } elseif ($info['width'] > 750) {
                $zoom_image_src = "<zoom_image_src>" . base_path() . $src . "</zoom_image_src>";
              }
            } else {
              $img_width = $info['width'];
              $html_image = theme("image", $src);
            }
            break;
        }
      }
    } elseif ($ext == 'swf') {
      $img_type = 'flash';
      if ($info['width'] && $info['height'] && $info['width'] > 662) {
        $img_width = 662;
      } else {
        $img_width = $info['width'];
      }
    }
    if ($info['width'] && !$img_width) {
      $img_height = round($img_width * $info['height'] / $info['width']);
    } else {
      $img_height = '';
    }
    $GLOBALS['base_url'] = $old_base_url;
    $src = base_path() . $src;
    $xml =
      "<img>" .
      "<type>" . $img_type . "</type>" .
      "<height>" . $img_height . "</height>" .
      "<width>" . $img_width . "</width>" .
      "<img_print>" . $print_link . "</img_print>" .
      "<print_title>" . $print_title . "</print_title>" .
      "<file_name>" . $file_name . "</file_name>" .
      "<src>" . $src . "</src>" .
      "<html>" . $html_image . "</html>" .
      $zoom_image_src .
      "</img>";

    if ($lien_reference) {
      return $xml;
    }

    $doc = new DOMDocument;
    $doc->loadXml($xml);
    return $doc;
    //$file['filepath'], $title, $legend);
  }

  $xml =
    "<img>" .
    "<type>none</type>" .
    "</img>";

  if ($lien_reference) {
    return $xml;
  }

  $doc = new DOMDocument;
  $doc->loadXml($xml);
  return $doc;
}

function _batire_xml_parse_xslt_get_figure_num_from_id($figure_id, $figure_title) {
  if (($fig = strpos($figure_id, '_FIG')) && (strpos($figure_title, 'Fig.') === FALSE)) {
    preg_match('/C([0-9]){2,}_FIG/', $figure_id, $output);

    $chapter_num = (int) substr($output[0], 1, 2);
    $figure_num  = (int) substr($figure_id, $fig + 4);

    return 'Figure ' . $chapter_num . '.' . $figure_num . '. ';
  }
  return '';
}

function _batire_xml_parse_fake_colspec($num) {
  if (is_nan($num)) {
    $num = 0;
  }
  $result = array("<xml>");
  for ($i = 1; $i <= $num; $i++) {
    $result[] = '<colspec colname="' . $i . '" />';
  }
  $result[] = '</xml>';
  $doc = new DOMDocument;
  $doc->loadXml(implode('', $result));
  return $doc;
}
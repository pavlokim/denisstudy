<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function pdf_document_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function pdf_document_node_info() {
  $items = array(
    'document' => array(
      'name' => t('Document'),
      'module' => 'features',
      'description' => t('A document container, used to hold a single PDF file as a downloadable attachment, and a cover page image.
The cover page representative image will be extracted automatically if possible, or may be over-ridden with a specific image selected by the editor.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Summary'),
      'min_word_count' => '0',
      'help' => t('The summary should contain a brief overview describing the content of the document.'),
    ),
  );
  return $items;
}

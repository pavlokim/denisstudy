<?php

/**
 * Implementation of hook_strongarm().
 */
function batire_content_types_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_5_advices';
  $strongarm->value = '0';
  $export['language_content_type_batire_5_advices'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_user_sent_alert';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '2',
    'author' => '1',
    'options' => '3',
    'menu' => '0',
    'path' => '5',
    'print' => '4',
  );
  $export['content_extra_weights_batire_user_sent_alert'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_texte_officiel';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '6',
    'author' => '5',
    'options' => '7',
    'menu' => '4',
    'taxonomy' => '3',
    'path' => '8',
    'print' => '10',
  );
  $export['content_extra_weights_batire_texte_officiel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_texte_normatifs';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '12',
    'author' => '11',
    'options' => '13',
    'menu' => '10',
    'taxonomy' => '9',
    'path' => '14',
    'print' => '16',
  );
  $export['content_extra_weights_batire_texte_normatifs'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_livres';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '8',
    'author' => '9',
    'options' => '10',
    'menu' => '7',
    'taxonomy' => '6',
    'path' => '11',
    'print' => '13',
  );
  $export['content_extra_weights_batire_livres'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_feuillet_mobile';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '6',
    'author' => '8',
    'options' => '7',
    'menu' => '5',
    'taxonomy' => '4',
    'path' => '9',
    'print' => '11',
  );
  $export['content_extra_weights_batire_feuillet_mobile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_texte_officiel';
  $strongarm->value = '0';
  $export['language_content_type_batire_texte_officiel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_document_pratique';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '6',
    'author' => '5',
    'options' => '7',
    'menu' => '4',
    'taxonomy' => '3',
    'path' => '8',
    'print' => '9',
  );
  $export['content_extra_weights_batire_document_pratique'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_complement_technique';
  $strongarm->value = '0';
  $export['language_content_type_batire_complement_technique'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_actualite';
  $strongarm->value = '0';
  $export['language_content_type_batire_actualite'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_codes';
  $strongarm->value = '0';
  $export['language_content_type_batire_codes'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_auteur';
  $strongarm->value = '0';
  $export['language_content_type_batire_auteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_document_pratique';
  $strongarm->value = '0';
  $export['language_content_type_batire_document_pratique'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_complement_technique';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '7',
    'author' => '8',
    'options' => '9',
    'menu' => '6',
    'taxonomy' => '5',
    'path' => '10',
    'print' => '12',
  );
  $export['content_extra_weights_batire_complement_technique'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_user_search_profile';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '6',
    'author' => '7',
    'options' => '8',
    'menu' => '4',
    'path' => '9',
    'print' => '30',
  );
  $export['content_extra_weights_batire_user_search_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_user_annotation';
  $strongarm->value = '0';
  $export['language_content_type_batire_user_annotation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_user_folder';
  $strongarm->value = '0';
  $export['language_content_type_batire_user_folder'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_texte_officiel';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_texte_officiel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_feuillet_mobile';
  $strongarm->value = '0';
  $export['language_content_type_batire_feuillet_mobile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_user_sent_alert';
  $strongarm->value = '0';
  $export['language_content_type_batire_user_sent_alert'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_user_profile';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_user_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_user_profile';
  $strongarm->value = '0';
  $export['language_content_type_batire_user_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_batire_user_folder';
  $strongarm->value = '1';
  $export['comment_subject_field_batire_user_folder'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_batire_user_profile';
  $strongarm->value = '1';
  $export['comment_subject_field_batire_user_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_batire_user_search_profile';
  $strongarm->value = '1';
  $export['comment_subject_field_batire_user_search_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_batire_user_sent_alert';
  $strongarm->value = '1';
  $export['comment_subject_field_batire_user_sent_alert'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_homepage_blocks';
  $strongarm->value = '0';
  $export['language_content_type_batire_homepage_blocks'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_last_documents';
  $strongarm->value = '0';
  $export['language_content_type_batire_last_documents'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_livres';
  $strongarm->value = '0';
  $export['language_content_type_batire_livres'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_page_not_found';
  $strongarm->value = '0';
  $export['language_content_type_batire_page_not_found'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_texte_normatifs';
  $strongarm->value = '0';
  $export['language_content_type_batire_texte_normatifs'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_codes';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '1',
    'author' => '2',
    'options' => '3',
    'menu' => '0',
    'taxonomy' => '-1',
    'path' => '4',
    'print' => '7',
  );
  $export['content_extra_weights_batire_codes'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_from_lemoniteur';
  $strongarm->value = '0';
  $export['language_content_type_batire_from_lemoniteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_5_advices';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '-2',
    'author' => '-1',
    'options' => '0',
    'menu' => '-4',
    'path' => '1',
    'detailed_question' => '-3',
  );
  $export['content_extra_weights_batire_5_advices'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_actualite';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '8',
    'author' => '7',
    'options' => '9',
    'menu' => '5',
    'taxonomy' => '4',
    'path' => '10',
    'print' => '30',
  );
  $export['content_extra_weights_batire_actualite'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_auteur';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '20',
    'author' => '20',
    'options' => '25',
    'menu' => '-2',
    'path' => '30',
    'detailed_question' => '10',
  );
  $export['content_extra_weights_batire_auteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_from_lemoniteur';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '0',
    'author' => '1',
    'options' => '2',
    'menu' => '-1',
    'path' => '3',
    'print' => '4',
  );
  $export['content_extra_weights_batire_from_lemoniteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_homepage_blocks';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '20',
    'author' => '20',
    'options' => '25',
    'menu' => '-2',
    'path' => '30',
    'detailed_question' => '10',
  );
  $export['content_extra_weights_batire_homepage_blocks'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_last_documents';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '3',
    'author' => '4',
    'options' => '5',
    'comment_settings' => '7',
    'menu' => '1',
    'taxonomy' => '0',
    'path' => '6',
    'detailed_question' => '2',
  );
  $export['content_extra_weights_batire_last_documents'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_batire_user_search_profile';
  $strongarm->value = '3';
  $export['comment_controls_batire_user_search_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_batire_from_lemoniteur';
  $strongarm->value = '0';
  $export['comment_form_location_batire_from_lemoniteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_user_annotation';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '1',
    'author' => '2',
    'options' => '3',
    'comment_settings' => '4',
    'menu' => '-1',
    'detailed_question' => '0',
  );
  $export['content_extra_weights_batire_user_annotation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_user_folder';
  $strongarm->value = array(
    'title' => '-3',
    'revision_information' => '5',
    'author' => '4',
    'options' => '6',
    'menu' => '2',
    'path' => '7',
    'detailed_question' => '3',
  );
  $export['content_extra_weights_batire_user_folder'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_commercial_animation';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_commercial_animation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_user_profile';
  $strongarm->value = array(
    'title' => '-2',
    'revision_information' => '7',
    'author' => '6',
    'options' => '8',
    'menu' => '4',
    'taxonomy' => '-3',
    'path' => '30',
    'print' => '30',
  );
  $export['content_extra_weights_batire_user_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_batire_last_documents';
  $strongarm->value = '1';
  $export['comment_subject_field_batire_last_documents'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_batire_page_not_found';
  $strongarm->value = '1';
  $export['comment_subject_field_batire_page_not_found'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_batire_texte_officiel';
  $strongarm->value = '1';
  $export['comment_subject_field_batire_texte_officiel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_batire_user_annotation';
  $strongarm->value = '1';
  $export['comment_subject_field_batire_user_annotation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_batire_user_sent_alert';
  $strongarm->value = '1';
  $export['comment_preview_batire_user_sent_alert'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_batire_from_lemoniteur';
  $strongarm->value = '1';
  $export['comment_subject_field_batire_from_lemoniteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_batire_page_not_found';
  $strongarm->value = '0';
  $export['comment_form_location_batire_page_not_found'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_batire_texte_officiel';
  $strongarm->value = '0';
  $export['comment_form_location_batire_texte_officiel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_batire_user_annotation';
  $strongarm->value = '0';
  $export['comment_form_location_batire_user_annotation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_batire_user_folder';
  $strongarm->value = '0';
  $export['comment_form_location_batire_user_folder'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_batire_user_profile';
  $strongarm->value = '0';
  $export['comment_form_location_batire_user_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_batire_user_search_profile';
  $strongarm->value = '0';
  $export['comment_form_location_batire_user_search_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_batire_user_sent_alert';
  $strongarm->value = '0';
  $export['comment_form_location_batire_user_sent_alert'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_batire_from_lemoniteur';
  $strongarm->value = '1';
  $export['comment_preview_batire_from_lemoniteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_batire_last_documents';
  $strongarm->value = '1';
  $export['comment_preview_batire_last_documents'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_batire_page_not_found';
  $strongarm->value = '1';
  $export['comment_preview_batire_page_not_found'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_batire_texte_officiel';
  $strongarm->value = '1';
  $export['comment_preview_batire_texte_officiel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_batire_user_annotation';
  $strongarm->value = '1';
  $export['comment_preview_batire_user_annotation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_batire_user_folder';
  $strongarm->value = '1';
  $export['comment_preview_batire_user_folder'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_batire_user_profile';
  $strongarm->value = '1';
  $export['comment_preview_batire_user_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_batire_user_search_profile';
  $strongarm->value = '1';
  $export['comment_preview_batire_user_search_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_batire_last_documents';
  $strongarm->value = '0';
  $export['comment_form_location_batire_last_documents'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_batire_user_folder';
  $strongarm->value = '1';
  $export['comment_default_order_batire_user_folder'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_batire_user_profile';
  $strongarm->value = '1';
  $export['comment_default_order_batire_user_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_batire_user_search_profile';
  $strongarm->value = '1';
  $export['comment_default_order_batire_user_search_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_batire_user_sent_alert';
  $strongarm->value = '1';
  $export['comment_default_order_batire_user_sent_alert'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_batire_from_lemoniteur';
  $strongarm->value = '50';
  $export['comment_default_per_page_batire_from_lemoniteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_batire_last_documents';
  $strongarm->value = '50';
  $export['comment_default_per_page_batire_last_documents'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_batire_page_not_found';
  $strongarm->value = '50';
  $export['comment_default_per_page_batire_page_not_found'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_batire_texte_officiel';
  $strongarm->value = '50';
  $export['comment_default_per_page_batire_texte_officiel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_batire_user_annotation';
  $strongarm->value = '50';
  $export['comment_default_per_page_batire_user_annotation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_batire_user_folder';
  $strongarm->value = '50';
  $export['comment_default_per_page_batire_user_folder'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_batire_user_profile';
  $strongarm->value = '50';
  $export['comment_default_per_page_batire_user_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_batire_user_search_profile';
  $strongarm->value = '50';
  $export['comment_default_per_page_batire_user_search_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_batire_user_sent_alert';
  $strongarm->value = '50';
  $export['comment_default_per_page_batire_user_sent_alert'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_batire_from_lemoniteur';
  $strongarm->value = '4';
  $export['comment_default_mode_batire_from_lemoniteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_batire_last_documents';
  $strongarm->value = '4';
  $export['comment_default_mode_batire_last_documents'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_batire_page_not_found';
  $strongarm->value = '4';
  $export['comment_default_mode_batire_page_not_found'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_batire_texte_officiel';
  $strongarm->value = '4';
  $export['comment_default_mode_batire_texte_officiel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_batire_user_annotation';
  $strongarm->value = '4';
  $export['comment_default_mode_batire_user_annotation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_batire_user_folder';
  $strongarm->value = '4';
  $export['comment_default_mode_batire_user_folder'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_batire_user_profile';
  $strongarm->value = '4';
  $export['comment_default_mode_batire_user_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_batire_user_search_profile';
  $strongarm->value = '4';
  $export['comment_default_mode_batire_user_search_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_batire_user_sent_alert';
  $strongarm->value = '4';
  $export['comment_default_mode_batire_user_sent_alert'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_batire_from_lemoniteur';
  $strongarm->value = '1';
  $export['comment_default_order_batire_from_lemoniteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_batire_last_documents';
  $strongarm->value = '1';
  $export['comment_default_order_batire_last_documents'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_batire_page_not_found';
  $strongarm->value = '1';
  $export['comment_default_order_batire_page_not_found'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_batire_texte_officiel';
  $strongarm->value = '1';
  $export['comment_default_order_batire_texte_officiel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_batire_user_annotation';
  $strongarm->value = '1';
  $export['comment_default_order_batire_user_annotation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_batire_user_sent_alert';
  $strongarm->value = '3';
  $export['comment_controls_batire_user_sent_alert'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_commercial_animation';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '-1',
    'author' => '0',
    'options' => '1',
    'menu' => '-3',
    'path' => '2',
    'detailed_question' => '-2',
  );
  $export['content_extra_weights_batire_commercial_animation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_batire_user_profile';
  $strongarm->value = '3';
  $export['comment_controls_batire_user_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_batire_from_lemoniteur';
  $strongarm->value = 0;
  $export['comment_anonymous_batire_from_lemoniteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_batire_last_documents';
  $strongarm->value = 0;
  $export['comment_anonymous_batire_last_documents'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_batire_page_not_found';
  $strongarm->value = 0;
  $export['comment_anonymous_batire_page_not_found'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_batire_texte_officiel';
  $strongarm->value = 0;
  $export['comment_anonymous_batire_texte_officiel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_batire_user_annotation';
  $strongarm->value = 0;
  $export['comment_anonymous_batire_user_annotation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_batire_user_folder';
  $strongarm->value = 0;
  $export['comment_anonymous_batire_user_folder'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_commercial_animation';
  $strongarm->value = '0';
  $export['language_content_type_batire_commercial_animation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_batire_user_profile';
  $strongarm->value = 0;
  $export['comment_anonymous_batire_user_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_batire_user_search_profile';
  $strongarm->value = 0;
  $export['comment_anonymous_batire_user_search_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_batire_user_sent_alert';
  $strongarm->value = 0;
  $export['comment_anonymous_batire_user_sent_alert'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_batire_from_lemoniteur';
  $strongarm->value = '0';
  $export['comment_batire_from_lemoniteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_batire_last_documents';
  $strongarm->value = '0';
  $export['comment_batire_last_documents'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_batire_page_not_found';
  $strongarm->value = '0';
  $export['comment_batire_page_not_found'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_batire_texte_officiel';
  $strongarm->value = '2';
  $export['comment_batire_texte_officiel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_batire_user_annotation';
  $strongarm->value = '0';
  $export['comment_batire_user_annotation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_batire_user_folder';
  $strongarm->value = '0';
  $export['comment_batire_user_folder'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_batire_user_profile';
  $strongarm->value = '0';
  $export['comment_batire_user_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_batire_user_search_profile';
  $strongarm->value = '0';
  $export['comment_batire_user_search_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_batire_user_sent_alert';
  $strongarm->value = '0';
  $export['comment_batire_user_sent_alert'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_batire_from_lemoniteur';
  $strongarm->value = '3';
  $export['comment_controls_batire_from_lemoniteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_batire_last_documents';
  $strongarm->value = '3';
  $export['comment_controls_batire_last_documents'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_batire_page_not_found';
  $strongarm->value = '3';
  $export['comment_controls_batire_page_not_found'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_batire_texte_officiel';
  $strongarm->value = '3';
  $export['comment_controls_batire_texte_officiel'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_batire_user_annotation';
  $strongarm->value = '3';
  $export['comment_controls_batire_user_annotation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_batire_user_folder';
  $strongarm->value = '3';
  $export['comment_controls_batire_user_folder'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_5_advices';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_5_advices'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_actualite';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_actualite'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_auteur';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_auteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_codes';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_codes'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_complement_technique';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_complement_technique'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_document_pratique';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_document_pratique'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_feuillet_mobile';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_feuillet_mobile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_from_lemoniteur';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_from_lemoniteur'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_homepage_blocks';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_homepage_blocks'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_last_documents';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_last_documents'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_livres';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_livres'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_page_not_found';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_page_not_found'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_texte_normatifs';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_texte_normatifs'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_user_annotation';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_user_annotation'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_user_folder';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_user_folder'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_user_sent_alert';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_user_sent_alert'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_user_search_profile';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_batire_user_search_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_user_search_profile';
  $strongarm->value = '0';
  $export['language_content_type_batire_user_search_profile'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_batire_document_reference';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '-2',
    'revision_information' => '1',
    'author' => '0',
    'options' => '2',
    'menu' => '-3',
    'taxonomy' => '-4',
    'path' => '4',
    'print' => '3',
  );
  $export['content_extra_weights_batire_document_reference'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_batire_document_reference';
  $strongarm->value = '0';
  $export['language_content_type_batire_document_reference'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_batire_document_reference';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_batire_document_reference'] = $strongarm;

  return $export;
}

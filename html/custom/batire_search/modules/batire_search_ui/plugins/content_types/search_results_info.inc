<?php

/**
 * @file
 *  search_results_info.inc
 * Create block of search criteria
 */

/**
 * Implementation of hook_content_type_ctools_content_types().
 */
function batire_search_ui_search_results_info_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Batire search info'),
    'description' => t('Block of search info'),
    'icon' => '',
    'category' => t('Batire'),
    'defaults' => array(),
  );
}

/**
 * Implementation of hook_content_type_content_type_render().
 */
function batire_search_ui_search_results_info_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  drupal_get_messages();
  $args = arg();
  $sid = $args[2];
  $user_session = _batire_site_get_session(BATIRE_USERSESSION_NAMESPACE);
  // get count searches to display from admin settings
  $admin_search_count = variable_get('batire_search_count_searches_to_display', BATIRE_SEARCH_COUNT_SEARCH_TO_DISPLAY);
  drupal_add_js(
  array(
    'batire_search_ui' => array(
      'search_id' => $sid,
      'r_search_id' => !empty($args[3]) && mongodb_search_find_search_id($args[3]) ? $args[3] : '',
      'quantity_search_results' => $admin_search_count,
    )
  ), 'setting'
  );
  $f_sid = $sid;
  if (!empty($args[3]) && mongodb_search_find_search_id($args[3])) {
    $f_sid = $args[3];
  }
  $search_data = mongodb_search_get_search_data($f_sid);

  $refine_search = $search_data['data']['refine_search'];
  if (!empty($refine_search) && (isset($user_session['recents']['s' . $sid]) || !empty($search_data['nid']))) {
    $criteria_refining = batire_search_load_refine_criteries_as_text($f_sid, TRUE);
  }
  else {
    $criteria_refining = '';
  }

  $block = new stdClass();
  $block->content = '';
  $count_results = batire_search_get_count_results($sid); // from antidot
  $pager = _batire_site_get_var(BATIRE_SEARCH_SESSION_VIEWS_NAMESPACE, $sid, NULL);
  // build list of data
  if (!empty($pager->spell_checker)) {
    $spell_checker_link = theme('batire_link', $pager->spell_checker, 'recherche-avancee/suggestion/' . $sid, array(
      'attributes' => array('class' => 'ortho-link'),
      'query' => array('words' => $pager->spell_checker)
    ));
  }

  $data = array(
    'search_id' => $sid,
    'edit_search_url' => 'recherche-avancee/modifier-recherche/' . $sid,
    'new_search_url' => 'recherche-avancee',
    'count' => $count_results,
    'search_criteria' => batire_search_load_search_criteries($sid, TRUE),
    'criteria_refining' => $criteria_refining,
    'spell_checker_link' => !empty($spell_checker_link) ? $spell_checker_link : ''
  );
  if (!is_null($search_data['data']['image_search']) && $search_data['data']['image_search']) {
   $data['feed'] = 'IMAGES';
  }

  // show message
  if ($data['count'] > $admin_search_count) {
    $data['over_200'] = t("Seules les !num premières réponses sont affichées ci-dessous.", array('!num' => $admin_search_count)) . '<br>' . t("Nous vous invitons à filtrer votre recherche");
  }
  $count = batire_user_docs_get_user_searches_cnt($user->uid, 0);
  $threshold_search_count = BATIRE_USER_SEARCHES_THRESHOLD_SAVED_SEARCHES;

  if ($count >= $threshold_search_count) {
    $max_count_search = BATIRE_USER_SEARCHES_MAXIMUM_SAVED_SEARCHES;
    if ($count >= $max_count_search) {
      $search_alert = t("Vous avez atteint le nombre maximum autorisé de @number recherches enregistrées. Pour en mémoriser de nouvelles, vous devez d'abord en supprimer certaines", array('@number' => $max_count_search));
      drupal_set_message($search_alert, 'error');
    }
    else {
      $search_alert = t("Le nombre de recherches enregistrées est limité à @total. Vous allez bientot atteindre cette limite. Nous vous conseillons de supprimer les recherches que vous n'utilisez plus", array('@total' => $max_count_search));
      drupal_set_message($search_alert, 'error');
    }
  }
  $data['messages'] = theme('status_messages');
  // save to session
  $search = mongodb_search_get_search_data($sid);
  $session = array(
    'count' => $count_results,
    'keyword' => $search['data']['search_word'],
    'url' => 'recherche-avancee/resultats/' . $sid,
    'created' => $search['ts'],
  );
  batire_usersession_search_add($sid, $session);
  if (batire_search_ui_check_related_search_id()) {
    $refine_search = _batire_site_get_var(BATIRE_SEARCH_SESSION_VIEWS_NAMESPACE, $sid . '_ref');
    $data['search_results_back_link'] = theme('batire_search_ui_results_back_link', array('search_id' => $sid, 'query' => batire_search_generate_facet_query(NULL, TRUE, $refine_search)));
  }
  $block->content = theme('batire_search_ui_search_results_info_content', $data);
  return $block;
}

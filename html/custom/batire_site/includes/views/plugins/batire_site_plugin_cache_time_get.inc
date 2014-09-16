<?php
/**
 * @file
 * Cache plugin by time
 */

/**
 * Simple caching of query results for Views displays.
 */
class batire_site_plugin_cache_time_get extends views_plugin_cache_time {
  function get_results_key() {
    global $user;

    if (!isset($this->_results_key)) {
      $cache_info = $this->view->query->get_cache_info();
      if ($cache_info === FALSE) {
        $this->_results_key = FALSE;
      }
      else {
        $key_data = array(
          'build_info' => $this->view->build_info,
          'cache_info' => $this->view->query->get_cache_info(),
          'roles' => array_keys($user->roles),
          'super-user' => $user->uid == 1, // special caching for super user.
          'language' => $GLOBALS['language'],
        );
        foreach (array('exposed_info', 'page', 'sort', 'order', 'items_per_page') as $key) {
          if (isset($_GET[$key])) {
            $key_data[$key] = $_GET[$key];
          }
        }

        $this->_results_key = $this->view->name . ':' . $this->display->id . ':results:' . md5(serialize($key_data));
      }
    }

    return $this->_results_key;
  }

  function get_output_key() {
    global $user;

    if (!isset($this->_results_key)) {
      $cache_info = $this->view->query->get_cache_info();
      if ($cache_info === FALSE) {
        $this->_results_key = FALSE;
      }
      else {
        $key_data = array(
          'build_info' => $this->view->build_info,
          'cache_info' => $this->view->query->get_cache_info(),
          'roles' => array_keys($user->roles),
          'super-user' => $user->uid == 1, // special caching for super user.
          'language' => $GLOBALS['language'],
        );
        foreach (array('exposed_info', 'page', 'sort', 'order', 'items_per_page') as $key) {
          if (isset($_GET[$key])) {
            $key_data[$key] = $_GET[$key];
          }
        }

        $this->_output_key = $this->view->name . ':' . $this->display->id . ':output:' . md5(serialize($key_data));
      }
    }

    return $this->_output_key;
  }

}

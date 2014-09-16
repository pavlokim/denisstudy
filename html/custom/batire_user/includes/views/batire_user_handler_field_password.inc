<?php

/**
 * Field handler to display user password extracted from SVC.
 */
class batire_user_handler_field_password extends views_handler_field {

  var $static;

  function query() {
    $this->field_alias = 'batire_user_password_' . $this->position;
  }

  /**
   * Enter description here...
   *
   * @param stdClass $values
   * @return string
   */
  function render($values) {
    global $user;

    $d = $this->view->display[$this->view->current_display];
    $field_handlers = $d->handler->handlers['field'];
    foreach ($field_handlers as $h) {
      // Handle grouped fields
      if (is_a($h, 'content_handler_field_multiple') && $h->defer_query) {
        // content_handler_field_multiple stores its query results in $obj->field_values
        $tmp = array();
        if (!empty($h->field_values[$values->{$h->field_alias}])) {
          foreach ($h->field_values[$values->{$h->field_alias}] as $k => $v) {
            $tmp[$k] = $v;
            // clean up a bit
            unset($tmp[$k]['#delta']);
            unset($tmp[$k]['_nid']);
          }
        }
        $values->{$h->table . '_' . $h->field} = $tmp;
      }
    }

    if ($user->uid == 1) {
      $profile = batire_svc_get_user_data($values->users_name, '', 'C');
      if (!$profile['error']) {
        $profile = _batire_svc_unpack_profile($profile['data']);
        return $profile['pass'];
      }
      else {
        return t('SVC error');
      }
    }
    else {
      return '-';
    }
  }

}

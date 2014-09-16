<?php

/**
 * Field handler to display statistics access permission.
 */
class batire_gc_statistics_handler_field_access_statistics extends views_handler_field {

  var $static;

  function query() {
    $this->field_alias = 'batire_gc_statistics_access_statistisc_' . $this->position;
  }

  /**
   * Enter description here...
   *
   * @param stdClass $values
   * @return string
   */
  function render($values) {
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

    $profile = batire_user_profile_load($values->uid);
    if (isset($profile->taxonomy[BATIRE_GC_GC_COMMERCIAL_TERM_ID]) && $profile->taxonomy[BATIRE_GC_GC_COMMERCIAL_TERM_ID]) {
      return t('Yes');
    }
    $permissions = !empty($profile->field_user_gc_stat_permissions[0]['value']) ? unserialize($profile->field_user_gc_stat_permissions[0]['value']) : array();
    if (!empty($permissions) && $permissions['allow_export_statistics']) {
      $text = t('Yes');
    }
    else {
      $text = t('No');
    }
    return l($text, '', array('attributes' => array('class' => 'permission-switch', 'id' => 'permission-switch-' . $values->uid)));
  }

}

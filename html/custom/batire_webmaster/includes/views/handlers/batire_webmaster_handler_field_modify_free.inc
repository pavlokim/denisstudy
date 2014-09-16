<?php
/**
 * @file
 * Provides link to modification of user term
 */

/**
 * A handler to provide a field that is completely custom by the administrator.
 *
 * @ingroup views_field_handlers
 */
class batire_webmaster_handler_field_modify_free extends views_handler_field_custom {
  function render($values) {
    $uid = $values->uid;
    $account = user_load($uid);

    if (_batire_user_is_paid($account)) {
      return FALSE;
    }

    if (!_batire_user_is_monopost($account) && !_batire_user_is_multipost($account, TRUE)) {
      return FALSE;
    }

    return l(t('Modifier'), 'admin/batire-site/users/'. $account->uid .'/extend-free-period');
  }
}
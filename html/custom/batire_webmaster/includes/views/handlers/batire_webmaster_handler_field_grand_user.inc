<?php
/**
 * @file
 * Provides Grand user field
 */

/**
 * A handler to provide a field that is completely custom by the administrator.
 *
 * @ingroup views_field_handlers
 */
class batire_webmaster_handler_field_grand_user extends views_handler_field_custom {
  function render($values) {
    $sql = "SELECT
              r.rid,
              r.name
            FROM {role} r
            INNER JOIN {users_roles} ur USING(rid)
            WHERE
              ur.uid = %d AND r.rid IN(%d, %d)";

    return db_result(
      db_query(
        $sql,
        $values->uid,
        BATIRE_USER_MULTIADMIN,
        BATIRE_USER_MONOPOST
      )
    ) ? t('Yes') : t('No');
  }
}
<?php

/**
 * Field handler to display user products according to Modular Offer.
 */
class batire_user_handler_field_products extends views_handler_field {

  var $static;

  function query() {
    $this->field_alias = 'batire_user_products_' . $this->position;
  }

  /**
   * Enter description here...
   *
   * @param stdClass $values
   * @return string
   */
  function render($values) {
    global $user;

    $query = "SELECT GROUP_CONCAT(DISTINCT pn.title ORDER BY pn.nid ASC SEPARATOR ', ') AS products FROM {node} n
      LEFT JOIN {content_field_user_products} cfup ON cfup.vid = n.vid
      LEFT JOIN {node} pn ON pn.nid = cfup.field_user_products_nid
      WHERE n.type = 'batire_user_profile' AND n.uid = %d";
    $result = db_query($query, $values->uid);
    $products = db_fetch_object($result);

    if ($products) {
      return $products->products;
    }
    return $values->uid;
  }

}

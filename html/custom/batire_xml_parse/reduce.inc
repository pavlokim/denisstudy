<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


function batire_xml_taxonomy_reduce($code) {
  static $reduce = array(50530 => 50529,
    50626 => 50605,
    50614 => 50613,
    50615 => 50611,
    5018  => 50611,
    50621 => 50619,
    50606 => 50604,
    50622 => 50604,
    50625 => 50524,
    50713 => 50712,
    50715 => 50703,
    50727 => 50707,
  );
 if (array_key_exists($code, $reduce)) {
   return $reduce[$code];
 }
 return $code;
}

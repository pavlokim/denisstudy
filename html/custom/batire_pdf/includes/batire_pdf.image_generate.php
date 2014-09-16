<?php
// Set the enviroment variable for GD
putenv('GDFONTPATH=' . realpath('../fonts'));
$font = "Arial";
$wm=ImageCreateFrompng(realpath("../../../../../..") . '/' . $_GET['image']);
imagettftext($wm, 10, 0, 50, 45, '0x000000', $font, $_GET['text']);
// Image output
ob_start("output_handler");
imagepng($wm);
ob_end_flush();
// Output handler
function output_handler($img) {
  header('Content-type: image/png');
  header('Content-Length: ' . strlen($img));
  return $img;
}
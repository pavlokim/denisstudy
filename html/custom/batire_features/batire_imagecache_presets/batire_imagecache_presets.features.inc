<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function batire_imagecache_presets_imagecache_default_presets() {
  $items = array(
    'batire_5advices_img' => array(
      'presetname' => 'batire_5advices_img',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '104',
            'height' => '',
            'upscale' => 0,
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_crop',
          'data' => array(
            'width' => '104',
            'height' => '105',
            'xoffset' => '0',
            'yoffset' => '0',
          ),
        ),
      ),
    ),
    'batire_document_image_artwork' => array(
      'presetname' => 'batire_document_image_artwork',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '35.7142857%',
            'height' => '',
            'upscale' => 1,
          ),
        ),
      ),
    ),
    'batire_document_img' => array(
      'presetname' => 'batire_document_img',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '662',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'batire_document_zoom_img' => array(
      'presetname' => 'batire_document_zoom_img',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '1100',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'batire_hp_block_img' => array(
      'presetname' => 'batire_hp_block_img',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_resize',
          'data' => array(
            'width' => '86',
            'height' => '60',
          ),
        ),
      ),
    ),
    'batire_image_result_popup_image' => array(
      'presetname' => 'batire_image_result_popup_image',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '388px',
            'height' => '400',
          ),
        ),
      ),
    ),
    'batire_image_result_vignette' => array(
      'presetname' => 'batire_image_result_vignette',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '185',
            'height' => '171',
          ),
        ),
      ),
    ),
    'batire_lemoniteur_img' => array(
      'presetname' => 'batire_lemoniteur_img',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_resize',
          'data' => array(
            'width' => '152',
            'height' => '86',
          ),
        ),
      ),
    ),
  );
  return $items;
}

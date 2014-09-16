<?php
/**
 * @file
 *  document-image.tpl.php
 * Create html for images
 */
?>
<table class="image-table">
  <tr>
    <td>
      <?php if (!$title && !$legend): ?>
        <div class="document-image-no-info">
        <?php endif; ?>
        <div class="document-image">
          <?php if ($info['swf']): ?>

            <div class="image" style="width:<?php print $info['width']; ?>px">
              <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=8" width="<?php print $info['width']; ?>" height="<?php print $info['height']; ?>"> 
                <param name="movie"  
                       value="<?php echo $src; ?>" /> 
                <embed src="<?php echo $src; ?>" width="<?php print $info['width']; ?>" height="<?php print $info['height']; ?>" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer"> 
                </embed> 
              </object> 
            </div>
          <?php else: ?>
            <div class="image" style="width:<?php print $info['width']; ?>px">
              <?php print $image; ?>
            </div>
            <?php if ($zoom_image_src): ?>
              <div class="zoom">
                <a class="fancybox-zoom" href="<?php print $zoom_image_src; ?>"></a>
              </div>
              <div class="print">
                <a href="print-image/nid/img-name" class="tooltip" title="<?php print t('Imprimer l\'image'); ?>"></a>
              </div>
            <?php endif; ?>
          <?php endif; ?>
        </div>
        <?php if ($title || $legend): ?>
          <div class="document-image-info">
            <p><?php print $title; ?></p>
            <?php print $legend; ?>
          </div>
        <?php endif; ?>
        <?php if (!$title && !$legend): ?>
        </div>
      <?php endif; ?>
    </td>
  </tr>
</table>
<br/>
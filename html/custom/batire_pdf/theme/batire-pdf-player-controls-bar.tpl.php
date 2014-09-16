<div class="royalSlider-controls-bar">
  <div class="zoomer">
    <div class="zoomer-inner">
      <div class="slider"></div>
      <div class="amount">
        <span class="percentage">0</span>%
      </div>
      <div class="search-ico"></div>
    </div>
  </div>
  <div class="pagination">
    <div class="royalSlider-items-count"><?php print t('Page'); ?> <input class="current" value="0" /> / <span class="all">--</span></div>
    <a class="next-page"></a>
    <a class="prev-page"></a>
  </div>
  <?php if($full) : ?>
  <div class="pdf-wrapp-link">
    <a class="rsFullscreenBtnBody"></a>
    <div class="pdf-tooltip">
      <span><span><?php print t('Quitter'); ?></span></span>
    </div>
  </div>
  <?php else : ?>
  <div class="pdf-wrapp-link">
    <a class="royal-gallery-open" id="royal-gallery-open-<?php print $parameters['nid']; ?>"></a>
    <div class="pdf-tooltip">
      <span><span><?php print t('Plein écran'); ?></span></span>
    </div>
  </div>
  <?php endif; ?>
  <div class="pdf-wrapp-link">
    <a class="print-all"></a>
    <div class="pdf-tooltip">
      <span><span><?php print t('Imprimer le document'); ?></span></span>
    </div>
  </div>
  <div class="pdf-wrapp-link">
    <a class="print"></a>
    <div class="pdf-tooltip">
      <span><span><?php print t('Imprimer la page'); ?></span></span>
    </div>
  </div>
  <div class="pdf-wrapp-link">
    <a class="pdf-full-page"></a>
    <div class="pdf-tooltip">
      <span><span><?php print t('Page entière'); ?></span></span>
    </div>
  </div>
  <div class="pdf-wrapp-link">
    <a class="pdf-large-page"></a>
    <div class="pdf-tooltip">
      <span><span><?php print t('Pleine largeur'); ?></span></span>
    </div>
  </div>
  <div class="pagination-scrollbar">
    <div class="royalSliderScroll"></div>
  </div>
</div>
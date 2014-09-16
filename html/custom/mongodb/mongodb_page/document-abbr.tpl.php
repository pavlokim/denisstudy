<a class="glossaire-tooltip" title="<?php print !$definition ? t('Definition missed') : check_plain($definition); ?>">
  <?php if (!$definition) : ?><span class="error"><?php endif; ?><?php print $title; ?><?php if (!$definition) : ?></span><?php endif; ?>
</a>
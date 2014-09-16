Drupal.behaviors.BatireNewsletter = function(context) {
  if (Drupal.settings.batire_newsletter.itemToOpen > 0) {
    var item_container = $('.view-batire-last-docs-view .views-row-' + Drupal.settings.batire_newsletter.itemToOpen, context);
    if(item_container.length) {
      var html_container = $('html, body');
      setTimeout(function() {
        $('.action-readmore-link a', item_container).click();
        html_container.scrollTop(item_container.offset().top);
      }, 500);
    }
  }
};

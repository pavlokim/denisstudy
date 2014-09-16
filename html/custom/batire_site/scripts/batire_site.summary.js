Drupal.behaviors.BatireSiteSummaryInit = function(context) {
  //sommaireList('div.batire-sommaire-block');

  $('#batire-site-summary-filter-form #edit-limit.reinit-tdm').click(function() {
    sommaireListReinit('div.batire-sommaire-block');
  });
  $('#batire-site-summary-filter-form #edit-limit.show-products-popup').click(function() {
    if (!$('#batire-site-summary-filter-form #edit-limit.show-products-popup').attr('checked')) {
      Drupal.BatireCommon.ShowPopup(Drupal.settings.batire_site.popups_url, 'summary_products', {}, sommaireProductsSubmit);
    }
  });

  var fid = batire_get_cookie('summary_last_fid');
  $(context).each(function(){
      var $this = $(this);
      var listLinks = $('a', $this);
      listLinks.removeClass('active');
  });

  if (fid) {
    link = $('#' + fid);
    if (link.attr('id')) {
      while (!link.hasClass('main')) {
        theme = link.parents('ul');
        theme.addClass('open');
        link = $('a:first', theme.parents('li'));
        link.addClass('active');
      }

      page_scroll = $('#' + fid).closest('ul');
      setTimeout(function(){
        Drupal.BatireCommon.scrollTo(page_scroll, true);
      }, 200);
    }

    if (!$('#' + fid).hasClass('active')) {
      $('#' + fid).addClass('active');
    }
  }
};
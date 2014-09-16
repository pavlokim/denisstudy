Drupal.behaviors.BatireStatisticsRange = function(context) {
  $('.batire-my-abonnement-statistics').click(function (event) {
    Drupal.BatireCommon.ShowPopup(Drupal.settings.batire_site.popups_url, 'statistics-period', {}, statisticsPeriodSubmit);
    return false;
  });
};

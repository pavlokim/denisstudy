Drupal.behaviors.BatireGcInviteLink = function(context) {
  $('.batire-my-abonnement-invite-link').click(function (event) {
    Drupal.BatireCommon.ShowPopup(Drupal.settings.batire_site.popups_url, 'invite-link', {}, inviteLinkSubmit);
    return false;
  });
};

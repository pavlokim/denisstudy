/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
Drupal.settings.ub_submitted = false;
Drupal.behaviors.gc_users = function(context) {
  $(document).ready(function(){
  if (Drupal.settings.batire_dynamic_login.ajaxUrl && !Drupal.settings.ub_submitted) {
    var oldForm = $('.batire-user-form').html();
    if (oldForm.indexOf('messages error') == -1) {
      $.get(
        Drupal.settings.batire_dynamic_login.ajaxUrl,
        function(data) {
            var data = JSON.parse(data);
            if (data.form) {
              $('.batire-user-form').html(data.form);
              Drupal.settings.ub_submitted = true;
              Drupal.attachBehaviors($('.batire-user-form'));
            }
            else if (data.gc_user_header_block) {
              $('.batire-user-form').html(data.gc_user_header_block);
              gcIpShowLoginPopup();
            }
        }
      );
    }
  }
  if ($('#user-login-form').length > 0) {
    $('#user-login-form').attr('action', window.location.href);
    $('#user-login-form #edit-destination', context).val(window.location.href);
  }
});
}


/* Login Popup link for GC users */
gcIpShowLoginPopup = function() {
  $('.login-popup-link').click(function() {
    /*Drupal.BatireCommon.ShowPopup(
      Drupal.settings.batire_site.popup_login_url,
      'login_form',
      {},
      function() {
        formWatermarkInit();
        LoginFormAction();
        loginPopupAutocompleteInit();
      }
    );*/
      Drupal.BatireCommon.ShowPopup(
        Drupal.settings.batire_dynamic_login.popup_login_url,
        'login_form',
        {},
        function () {
          formWatermarkInit();
          GCLoginFormAction();
          loginPopupAutocompleteInit();
        }
      );
  });

}

function GCLoginFormAction() {
  $('#login-form').attr('action', Drupal.settings.batire_site.popupUrl);
  $('#login-form #edit-destination').val(window.location.href);
  $('#login-form').bind('submit', function(){
    if (!$.trim($('#popup-login').val()) || !$.trim($('#popup-pass').val())) {
      batire_popup_show_message(Drupal.t('Identifiant ou mot de passe non reconnu.'));
      return false;
    }
  });
}

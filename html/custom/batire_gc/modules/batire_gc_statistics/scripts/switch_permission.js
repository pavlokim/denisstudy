Drupal.behaviors.BatireStatisticsPermissionSwitch = function(context) {
  $('.permission-switch').click(function (e) {
    var $this = $(this);
    var uid = $this.attr('id');
    uid = uid.split('-');
    $.post(
      Drupal.settings.batire_gc_statistics.switch_permission_url,
      {
        uid: uid[2]
      },
      function(response) {
        if(!response.error) {
          $this.text(response.data);
        } else {
          return false;
        }
      },
      'json'
    );
    return false;
  });
};

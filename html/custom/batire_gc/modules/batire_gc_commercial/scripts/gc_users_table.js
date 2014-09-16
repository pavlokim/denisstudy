Drupal.behaviors.BatireGcUsersTable = function(context) {
  $('.gc-manage-collapse').click(function(event) {
    var id = $(this).attr('id');
    id = id.replace('gc-manage-collapse-', '');
    $('.gc-admin-collapsible-' + id).toggle();
    return false;
  });
  $('.gc-collapse').click(function(event) {
    var id = $(this).attr('id');
    id = id.replace('gc-collapse-', '');
    $('.gc-collapsible-' + id).toggle();
    $('.gc-member-collapsible-' + id).toggle();
    return false;
  });
  $('.gc-collapse-all').click(function(event) {
    $('.gc-collapsible').toggle();
    $('.gc-member-collapsible').toggle();
    $('.gc-admin-collapsible').toggle();
    if ($(this).html() == Drupal.t('Expand all')) {
      $(this).html('Collapse all');
    }
    else {
      $(this).html('Expand all');
    }
    return false;
  });
};

$(function(){
  var $selectors = [
    'a.path-admin-build-menu-customize-secondary-links', 
    'a.path-admin-build-menu-customize-primary-links', 
    'a.path-admin-build-menu-customize-devel', 
    'a.path-admin-build-menu-customize-admin', 
    'a.path-admin-build-menu-customize-admin_menu', 
    'a.path-admin-build-menu-customize-navigation'
  ];

  $($selectors.join(', '))
    .parent('li')
    .hide();
});
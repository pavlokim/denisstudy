Drupal.BatireUserSession = Drupal.BatireUserSession || {};

Drupal.BatireUserSession.pages = {
  all      : 1,
  docs     : 1,
  searches : 1
};

Drupal.BatireUserSession.pagesLoaded = {
  all      : 0,
  docs     : 0,
  searches : 0
};

Drupal.BatireUserSession.pageLoadInProgress = false;

Drupal.behaviors.BatireUserSessionInit = function(context) {
  var type = '';
  if ($('#batire-user-session-docs').attr('id')) {
    type = 'docs';
  }

  if ($('#batire-user-session-searches').attr('id') && type == '') {
    type = 'searches';
  }

  if (type != '') {
    Drupal.BatireUserSession.GetRecentItems(type, 0);
  }
  
  Drupal.BatireUserSession.AttachTabs();
};

Drupal.BatireUserSession.AttachTabs = function() {
  var tabs = ['searches', 'docs', 'all'];

  for (var i in tabs) {
    $('#batire-user-session-' + tabs[i]).bind('click', function() {
      var tab = this.id.split('-').reverse()[0];
      return Drupal.BatireUserSession.GetRecentItems(tab, 0);
    });
  }
};

Drupal.BatireUserSession.AttachPager = function(tab) {
  var dir  = ['next', 'prev'];

  for (var i in dir) {
    if ('prev' == dir[i]) {
      $('#batire-user-session-' + tab + '-' + dir[i]).live('click', function(){
        Drupal.BatireUserSession.GetRecentItems(tab, -1, true);
        return false;
      });
    }
    else {
      $('#batire-user-session-' + tab + '-' + dir[i]).live('click', function(){
        Drupal.BatireUserSession.GetRecentItems(tab, 1, true);
        return false;
      });
    }
  }
  return false;
};

Drupal.BatireUserSession.GetRecentItems = function(item, page, force) {

  if (Drupal.BatireUserSession.pageLoadInProgress) {
    return false;
  }

  Drupal.BatireUserSession.pageLoadInProgress = true;

  force = force ? force : false;

  var goto_page = Drupal.BatireUserSession.pages[item] + page;

  if (goto_page <= 0) {
    goto_page = 1;
  }

  if (!force && Drupal.BatireUserSession.pagesLoaded[item]) {
    Drupal.BatireUserSession.updateTabs('#block-user-session', item);

    Drupal.BatireUserSession.pages[item] = goto_page;

    Drupal.BatireUserSession.pageLoadInProgress = false;

    return false;
  }

  $.getJSON(
    Drupal.settings.batire_usersession.info_load_url + '/' + item,

    {
      page: goto_page
    },

    function(response) {
      $('#session-' + item).html(response.data);

      Drupal.BatireUserSession.updateTabs('#block-user-session', item);

      Drupal.BatireUserSession.pagesLoaded[item] = 1;

      Drupal.BatireUserSession.AttachPager(item);
      Drupal.BatireUserSession.pages[item] = goto_page;

      Drupal.BatireUserSession.pageLoadInProgress = false;
    }
  );
 
  return false;
};

Drupal.BatireUserSession.updateTabs = function(element, item) {
  var $container = $(element);

  $('li a', $container).removeClass('active');
  $('#batire-user-session-' + item).addClass('active');

  $('div.content', $container).addClass('content-hide');
  $('#session-' + item).removeClass('content-hide');
};

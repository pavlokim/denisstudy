Drupal.BatireUserAccountList = Drupal.BatireUserAccountList || {};

Drupal.BatireUserAccountList.pageLoadInProgress = false;
Drupal.BatireUserAccountList.fieldsHash = '';

Drupal.behaviors.BatireUserAccountList = function(context) {
  Drupal.BatireUserAccountList.AttachDelete();
  Drupal.BatireUserAccountList.AttachAdd();
  Drupal.BatireUserAccountList.AttachSubmit();
  Drupal.BatireUserAccountList.AttachCancel();
  Drupal.BatireUserAccountList.AttachEnter();
  Drupal.BatireUserAccountList.CheckFields();

  //Messages trick
  var messages = $('#accounts-list-messages');
  var messages_html = messages.html();
  messages.remove();
  var inner = $('#batire-main-inner');
  inner.children(':first-child').before(messages_html);
};

Drupal.BatireUserAccountList.AttachDelete = function() {
  $('div.batire-action-items li a.rm').not('.del-processed').addClass('del-processed').each(function(){
    $(this)
      .bind('click', function() {
        var nid = this.id.split('-').reverse()[0];
        var type = this.id.split('-').reverse()[1];
        var hash = this.id.split('-').reverse()[2];
        return Drupal.BatireUserAccountList.RemoveAccountRequest(type, nid, hash);
      })
  })
};

Drupal.BatireUserAccountList.RemoveAccountRequest = function(type, nid, hash) {
  //Clean errors
  Drupal.BatireUserAccountList.CleanErrors();

  popupConfirmCall(Drupal.t('Confirmation'), Drupal.t('Êtes-vous sûr de vouloir supprimer ce compte secondaire ?'), function(ret) {
    if(ret) {
      if (Drupal.BatireUserAccountList.pageLoadInProgress) {
        return false;
      }

      Drupal.BatireUserAccountList.pageLoadInProgress = true;

      switch(type) {
        case 'acc' :
          $.post(
            Drupal.settings.batire_user.accounts_list_url + '/del',

            {
              type: type,
              nid:  nid
            },

            function(response) {
              if (!response.error) {
                $('#' + hash + '-acc-' + nid).remove();
                Drupal.settings.batire_user.accounts_cnt--;
                //Counters
                $('span.batire-my-abonnement-users-quantity').html('(' + Drupal.settings.batire_user.accounts_cnt + ')');
                $('div.block-title span').html('(' + Drupal.settings.batire_user.accounts_cnt + ')');
                $('span.batire-shared-documents-quantity').html('(' + response.data['docs'] + ')');
                $('div.block-title span').html('(' + Drupal.settings.batire_user.accounts_cnt + ')');
                $('span.batire-shared-folders-quantity').html('(' + response.data['folders'] + ')');
                $('div.block-title span').html('(' + Drupal.settings.batire_user.accounts_cnt + ')');
                $('span.batire-shared-annotations-quantity').html('(' + response.data['annos'] + ')');
                $('div.block-title span').html('(' + Drupal.settings.batire_user.accounts_cnt + ')');

                //@todo: update docs, folders, annos counters
                Drupal.BatireUserAccountList.CheckFields();
                Drupal.BatireUserAccountList.RecountAccounts();
              }
              else {
                var row = $('#' + hash + '-acc-' + nid);
                $('a.form-tooltip', row).attr('title', Drupal.t('Vous ne disposez pas des droits d\'administration de cet abonnement.'));
                row.not('.item-error').addClass('item-error');
                tooltips('.form-tooltip', true, false, false);
              }
              Drupal.BatireUserAccountList.pageLoadInProgress = false;
            },
            'json'
          );
          break;
        case 'preacc' :
          $.post(
            Drupal.settings.batire_user.accounts_list_url + '/del',

            {
              type: type,
              nid:  nid
            },

            function(response) {
              if (!response.error) {
                $('#' + hash + '-preacc-' + nid).remove();
                Drupal.settings.batire_user.accounts_cnt--;
                //Counter
                $('span.batire-my-abonnement-users-quantity').html('(' + Drupal.settings.batire_user.accounts_cnt + ')');
                $('div.block-title span').html('(' + Drupal.settings.batire_user.accounts_cnt + ')');
                Drupal.BatireUserAccountList.CheckFields();
                Drupal.BatireUserAccountList.RecountAccounts();
              }
              else {
                var row = $('#' + hash + '-preacc-' + nid);
                $('a.form-tooltip', row).attr('title', Drupal.t('Vous ne disposez pas des droits d\'administration de cet abonnement.'));
                row.not('.item-error').addClass('item-error');
                tooltips('.form-tooltip', true, false, false);
              }
              Drupal.BatireUserAccountList.pageLoadInProgress = false;
            },
            'json'
          );
          break;
        case 'newacc' :
          $('#newacc-' + nid).remove();
          Drupal.settings.batire_user.accounts_cnt--;
          Drupal.BatireUserAccountList.pageLoadInProgress = false;
          //Counter
          Drupal.BatireUserAccountList.RecountAccounts();
          break;
      }
    }
  });
  return false;
}

Drupal.BatireUserAccountList.AttachAdd = function() {
  $('#add-account')
    .bind('click', function() {
      //Clean errors
      Drupal.BatireUserAccountList.CleanErrors();

      if (Drupal.BatireUserAccountList.pageLoadInProgress) {
        return false;
      }

      if (Drupal.settings.batire_user.accounts_cnt >= Drupal.settings.batire_user.accounts_max) {
        return false;
      }

      Drupal.BatireUserAccountList.pageLoadInProgress = true;
      $('div.block-ajouter span.block-addnew').not('.block-addnew-loading').addClass('block-addnew-loading');
      $.getJSON(
        Drupal.settings.batire_user.accounts_list_url + '/new',
        {
          cnt: Drupal.settings.batire_user.accounts_cnt + 1
        },
        function(response) {
          if (!response.error) {
            Drupal.settings.batire_user.accounts_cnt++;
            var $last;
            $('div.block-compte-sutilisate div.block-form div.block-ajouter').each(function(){
                $last = $(this);
              }
            );
            //Display new
            $(response.data).insertBefore($last);
            formWatermark('div.form-item input');
            tooltips('.tooltip', false, false, false);
            //Attach delete button
            Drupal.BatireUserAccountList.AttachDelete();
            //Update counter
            var cnt_left = Drupal.settings.batire_user.accounts_max - Drupal.settings.batire_user.accounts_cnt;
            if (cnt_left > 0) {
              $('#left-cnt').text(Drupal.formatPlural(cnt_left, '@count disponible', '@count disponibles'));
            }
            else {
              $('div.block-ajouter').not('.show-hide-block-non').addClass('show-hide-block-non');
            }
          }
          Drupal.BatireUserAccountList.pageLoadInProgress = false;
          $('div.block-ajouter span.block-addnew').removeClass('block-addnew-loading');
        }
      );
      return false;
    });
};

Drupal.BatireUserAccountList.AttachCancel = function() {
  $('#accounts-list-cancel')
    .bind('click', function() {
      if (Drupal.BatireUserAccountList.pageLoadInProgress) {
        return false;
      }

      popupConfirmCall(Drupal.t('Confirmation'), Drupal.t('Voulez-vous annuler les modifications ?'), function(ret) {
        if(ret) {
          location.reload(true);
        }
      });
    });
};

Drupal.BatireUserAccountList.AttachSubmit = function() {
  $('#accounts-list-submit')
    .bind('click', function() {
      if (Drupal.BatireUserAccountList.pageLoadInProgress) {
        return false;
      }

      //Clean message
      Drupal.BatireUserAccountList.CleanErrors();

      //Check for changes
      var s_accs = Drupal.BatireUserAccountList.GetFields();
      var hash = hex_md5(s_accs);
      if (hash == Drupal.BatireUserAccountList.fieldsHash) {
        Drupal.BatireUserAccountList.ShowMessage('error', 'Vous devez créer au moins un utilisateur.');
        return false;
      }

      //Check for errors
      if (Drupal.BatireUserAccountList.CheckErr()) {
        return false;
      }

      Drupal.BatireUserAccountList.pageLoadInProgress = true;

      $.post(
        Drupal.settings.batire_user.accounts_list_url + '/update',

        {
          accs: s_accs
        },

        function(response) {
          if (!response.error) {
            Drupal.BatireUserAccountList.ShowMessage('info', 'Les comptes secondaires ont été créés avec succès.');
            Drupal.BatireUserAccountList.fieldsHash = hash;
            //Update counters
            $('span.batire-my-abonnement-users-quantity').html('(' + Drupal.settings.batire_user.accounts_cnt + ')');
            $('div.block-title span').html('(' + Drupal.settings.batire_user.accounts_cnt + ')');

            if (response.data != null) {
              //Cleanup new rows to replace
              $('div.block-compte-sutilisate div.block-form div.new-item').each(function(){
                $(this).remove();
              });
              //Insert updated
              var $last;
              $('div.block-compte-sutilisate div.block-form div.block-ajouter').each(function(){
                  $last = $(this);
                }
              );
              //Display new
              $(response.data).insertBefore($last);
              Drupal.BatireUserAccountList.RecountAccounts();
              formWatermark('div.form-item input');
              tooltips('.tooltip', false, false, false);
              //Attach delete button
              Drupal.BatireUserAccountList.AttachDelete();
            }
          }
          else {
            Drupal.BatireUserAccountList.ShowMessage('error', 'Vous ne disposez pas des droits d\'administration de cet abonnement.');
          }
          Drupal.BatireUserAccountList.pageLoadInProgress = false;
        },
        'json'
      );
    });
}

Drupal.BatireUserAccountList.RecountAccounts = function() {
  var cnt_left = Drupal.settings.batire_user.accounts_max - Drupal.settings.batire_user.accounts_cnt;
  if (cnt_left > 0) {
    $('#left-cnt').text(Drupal.formatPlural(cnt_left, '@count disponible', '@count disponibles'));
    $('div.block-ajouter').removeClass('show-hide-block-non');
  }
  else {
    $('div.block-ajouter').not('.show-hide-block-non').addClass('show-hide-block-non');
  }

  var cntr = 1;
  $('div.block-compte-sutilisate div.block-form div.item').each(function(){
      var $this = $(this);
      $('.number', $this).html(cntr);
      cntr++;
    }
  );
}

Drupal.BatireUserAccountList.CheckFields = function() {
  Drupal.BatireUserAccountList.fieldsHash = hex_md5(Drupal.BatireUserAccountList.GetFields());
}

Drupal.BatireUserAccountList.GetFields = function() {
  //Add data to array
  var accs = {
    acc    : {},
    preacc : {},
    newacc : {}
  };

  $('div.block-compte-sutilisate div.block-form div.item').each(function(){
      var $this = $(this);

      var nid      = 'a' + this.id.split('-').reverse()[0];
      var type     = this.id.split('-').reverse()[1];
      var name     = $.trim($('input[name="name"]', $this).val());
      var surname  = $.trim($('input[name="surname"]', $this).val());
      var mail     = $.trim($('input[name="mail"]', $this).val());
      var new_hash = hex_md5(name + surname + mail);
      var old_hash = this.id.split('-').reverse()[2];
      var changed  = (new_hash != old_hash) ? 1 : 0;

      var item = {
        name    : name,
        surname : surname,
        mail    : mail,
        changed : changed
      };

      accs[type][nid] = item;
    }
  );

  return JSON.stringify(accs, '', 2);
}

Drupal.BatireUserAccountList.CheckErr = function() {
  var err = false;
  $('div.block-compte-sutilisate div.block-form div.item').each(function(){
    var $this = $(this);
    $this.removeClass('item-error');
    var name    = $.trim($('input[name="name"]', $this).val());
    var surname = $.trim($('input[name="surname"]', $this).val());
    var mail    = $.trim($('input[name="mail"]', $this).val());

    if (!name || !surname || !mail || !validateEmail(mail)) {
      err = true;
      $('a.form-tooltip', $this).attr('title', Drupal.t('Merci de renseigner ces champs'));
      $this.not('.item-error').addClass('item-error');
      tooltips('.form-tooltip', true, false, false);
    }
  });
  return err;
}

Drupal.BatireUserAccountList.ShowMessage = function(type, text) {
  var messages = $('#accounts-list-messages-inner');
  messages.removeClass('error');
  if (type == 'error') {
    messages.not('.error').addClass('error');
  }
  $('div.messages-content, messages').html(Drupal.t(text));
  messages.removeClass('show-hide-block-non');
}

Drupal.BatireUserAccountList.CleanErrors = function() {
  $('div.block-compte-sutilisate div.block-form div.item').each(function(){
    var $this = $(this);
    $this.removeClass('item-error');
  });

  $('div.messages').not('.show-hide-block-non').addClass('show-hide-block-non');
}

Drupal.BatireUserAccountList.AttachEnter = function() {
  $('div.block-compte-sutilisate div.block-form').keypress(function(e){
    if (e.which == 13) {
      $("#accounts-list-submit").trigger('click');
    }
    else {
      return true;
    }
  });
}
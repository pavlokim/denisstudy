Drupal.BatireUserDocsAnnotations = Drupal.BatireUserDocsAnnotations || {};

Drupal.BatireUserDocsAnnotations.formMode      = "add";
Drupal.BatireUserDocsAnnotations.editNid       = "0";
Drupal.BatireUserDocsAnnotations.callClassify  = "0";
Drupal.BatireUserDocsAnnotations.canSelectType = false;

Drupal.BatireUserDocsAnnotations.pageLoadInProgress = false;

Drupal.behaviors.BatireUserDocsAnnotationsInit = function(context) {
  Drupal.BatireUserDocsAnnotations.AttachManipulators();
  Drupal.BatireUserDocsAnnotations.AttachSubmit();
  Drupal.BatireUserDocsAnnotations.AttachCancel();
  Drupal.BatireUserDocsAnnotations.canSelectType = !$('#annotation-type-selector').hasClass('show-hide-block-non');
};

Drupal.BatireUserDocsAnnotations.AttachManipulators = function() {
  $('div.batire-action-items li a.mdf-cm').each(function(){
    $(this).bind('click', function() {
      var nid = this.id.split('-').reverse()[0];
      return Drupal.BatireUserDocsAnnotations.EditNote(nid);
    })
  })

  $('div.batire-action-items li a.rm-cm').each(function(){
    $(this).bind('click', function() {
      var nid = this.id.split('-').reverse()[0];
      return Drupal.BatireUserDocsAnnotations.RemoveNoteRequest(nid);
    })
  })
  tooltips('.tooltip', false);
};

Drupal.BatireUserDocsAnnotations.AttachCancel = function() {
  $('#annotation-cancel').bind('click', function() {
    $('div.form-item textarea').val("");
    if (Drupal.BatireUserDocsAnnotations.canSelectType) {
      $('#annotation-type-selector').removeClass('show-hide-block-non');
    }
    $('#batire_note_add').removeClass('show-hide-block-non');
    $('#batire_note_edit').not('.show-hide-block-non').addClass('show-hide-block-non');
    $('#annotation-cancel').not('.show-hide-block-non').addClass('show-hide-block-non');
    Drupal.BatireUserDocsAnnotations.formMode = "add";
    return false;
  });
};

Drupal.BatireUserDocsAnnotations.AttachSubmit = function() {
  $('#batire-add-annotation-form', $('.batire-comment-form')).bind('submit', function() {
    if (Drupal.BatireUserDocsAnnotations.pageLoadInProgress) {
      return false;
    }
    $('div.button-form-submit').not('.button-form-submit-loading').addClass('button-form-submit-loading');
    Drupal.BatireUserDocsAnnotations.pageLoadInProgress = true;

    var text = $.trim($('div.form-item textarea').val());
    if (text) {
      var doc_id = Drupal.settings.batire_user_docs.annotations_did;

      if (Drupal.BatireUserDocsAnnotations.formMode == "add") {
        var personel  = $('#type-personnelle')[0] ? $('#type-personnelle').attr('checked') : true;
        var note_type = 'personel';
        if (!personel) {
          note_type = 'shared';
        }

        $.post(
          Drupal.settings.batire_user_docs.annotations_url + '/add',
          {
            text: text,
            type: note_type,
            did: doc_id
          },

          function(response) {
            if (!response.error) {
              var c = 'div#comments-action-list-personnelles';
              if (response.type == "shared") {
                c = 'div#comments-action-list-partagees';
              }
              Drupal.BatireUserDocsAnnotations.AddNote(c, response.data);
              Drupal.BatireUserDocsAnnotations.RecountNotes();
              $('#annotation-cancel').trigger('click');
            }
            else {
              Drupal.BatireUserDocsAnnotations.callClassify = response.data;
              $('#ab-classify').trigger('click');
            }
            $('div.button-form-submit').removeClass('button-form-submit-loading');
            Drupal.BatireUserDocsAnnotations.pageLoadInProgress = false;
          },
          'json');
      }
      else {
        $.post(
          Drupal.settings.batire_user_docs.annotations_url + '/modify',
          {
            text: text,
            nid: Drupal.BatireUserDocsAnnotations.editNid
          },

          function(response) {
            if (!response.error) {
              var c = 'div#comments-action-list-personnelles';
              if (response.type == "shared") {
                c = 'div#comments-action-list-partagees';
              }
              $('#annotation-' + Drupal.BatireUserDocsAnnotations.editNid).parent().remove();
              Drupal.BatireUserDocsAnnotations.AddNote(c, response.data);
              Drupal.BatireUserDocsAnnotations.RecountNotes();
              $('#annotation-cancel').trigger('click');
            }
            $('div.button-form-submit').removeClass('button-form-submit-loading');
            Drupal.BatireUserDocsAnnotations.pageLoadInProgress = false;
          },
          'json');
      }
    }
    else {
      popupInfoCall(Drupal.t('Confirmation'), Drupal.t('Please, enter annotation text.'));
      $('div.button-form-submit').removeClass('button-form-submit-loading');
    }
    Drupal.BatireUserDocsAnnotations.pageLoadInProgress = false;
    return false;
  });
}

Drupal.BatireUserDocsAnnotations.EditNote = function(nid) {
  Drupal.BatireUserDocsAnnotations.formMode = "edit";
  Drupal.BatireUserDocsAnnotations.editNid  = nid;
  $('#annotation-type-selector').not('.show-hide-block-non').addClass('show-hide-block-non');
  $('#batire_note_add').not('.show-hide-block-non').addClass('show-hide-block-non');
  $('#batire_note_edit').removeClass('show-hide-block-non');
  $('#annotation-cancel').removeClass('show-hide-block-non');
  var text = $.trim($('#annotation-' + nid).text());
  var $textarea = $('div.form-item textarea');
  $textarea.val(text);
  Drupal.BatireCommon.scrollTo($('#annotation-type-selector').parent(), true);
  $textarea[0].focus();
  return false;
};

Drupal.BatireUserDocsAnnotations.RemoveNote = function(nid) {
  if (Drupal.BatireUserDocsAnnotations.pageLoadInProgress) {
    return false;
  }

  $('div.button-form-submit').not('.button-form-submit-loading').addClass('button-form-submit-loading');
  Drupal.BatireUserDocsAnnotations.pageLoadInProgress = true;

  $.post(
    Drupal.settings.batire_user_docs.annotations_url + '/del',
    {
      nid: nid
    },
    function(response) {
      if (!response.error) {
        $('#annotation-' + nid).parent().remove();
        Drupal.BatireUserDocsAnnotations.RecountNotes();
      }
      $('div.button-form-submit').removeClass('button-form-submit-loading');
      Drupal.BatireUserDocsAnnotations.pageLoadInProgress = false;
    },
    'json');
  return false;
};

Drupal.BatireUserDocsAnnotations.CountNotes = function(c) {
  var list        = $('div.item-list', $(c)).find('li');
  var actionList  = $('div.batire-action-items, div.block-pager-links', $(c)).find('li');
  var lists       = list.not(actionList);
  return lists.length;
}

Drupal.BatireUserDocsAnnotations.RecountNotes = function() {
  commentFormListFlase('div#comments-action-list-personnelles', 5, 'Toutes les notes personnelles', 'Fermer');
  commentFormListFlase('div#comments-action-list-partagees', 5, 'Toutes les notes partagées', 'Fermer');

  var cnt_personel = Drupal.BatireUserDocsAnnotations.CountNotes('div#comments-action-list-personnelles');
  var cnt_partage  = Drupal.BatireUserDocsAnnotations.CountNotes('div#comments-action-list-partagees');
  var cnt_total    = cnt_personel + cnt_partage;

  $('div#comments-action-list-personnelles').find('h5').html(Drupal.formatPlural(cnt_personel, Drupal.t('Note personnelle'), Drupal.t('Notes personnelles')) + ' (' + cnt_personel + ')');
  $('div#comments-action-list-partagees').find('h5').html(Drupal.formatPlural(cnt_partage, Drupal.t('Note partagée'), Drupal.t('Notes partagées')) + ' (' + cnt_partage + ')');
  $('div.block-bg h4 span').html(Drupal.t('Mes annotations') + ' (' + cnt_total + ')');

  if (cnt_personel == 0) {
    $('div#comments-action-list-personnelles').not('.show-hide-block-non').addClass('show-hide-block-non');
  }
  else {
    $('div#comments-action-list-personnelles').removeClass('show-hide-block-non');
  }
  if (cnt_partage == 0) {
    $('div#comments-action-list-partagees').not('.show-hide-block-non').addClass('show-hide-block-non');
  }
  else {
    $('div#comments-action-list-partagees').removeClass('show-hide-block-non');
  }
  batireDocumentInfobar();
}

Drupal.BatireUserDocsAnnotations.AddNote = function(c, txt) {
  if (!$.trim($(c + ' div.item-list').html()))
  {
    $(c).html($(c).html() + '<div class="item-list"><ul></ul></div>');
  }
  $(c + ' div.item-list ul').html(txt + $(c + ' div.item-list ul').html());
  Drupal.BatireUserDocsAnnotations.AttachManipulators();
  $(c + ' div.item-list ul').children()[0].scrollIntoView();
}

Drupal.BatireUserDocsAnnotations.RemoveNoteRequest = function(nid) {
  popupConfirmCall(Drupal.t('Confirmation'), Drupal.t('Êtes-vous sûr de vouloir supprimer cette annotation ?'), function(ret) {
    if(ret) {
      Drupal.BatireUserDocsAnnotations.RemoveNote(nid);
    }
  });
  return false;
}
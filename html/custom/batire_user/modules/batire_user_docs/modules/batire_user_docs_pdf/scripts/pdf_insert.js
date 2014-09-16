/**
 * @file
 * Inserting SWF file of PDF Viewer.
 *
 */

/**
 * Setting Viewer parameters and embed swf into page.
 */
Drupal.BatireUserDocsPdfView = Drupal.BatireUserDocsPdfView || {};
Drupal.BatireUserDocsPdfView.pdf_viewer_class = '.pdf-viewer';
Drupal.BatireUserDocsPdfView.flash_viewer_id = '#flash-viewer';

Drupal.behaviors.BatireUserDocsPdfView = function(context) {
  if (Drupal.settings.batire_user_docs_pdf && Drupal.settings.batire_user_docs_pdf.pdf_file_path) {
    Drupal.BatireUserDocsPdfView.addPdfViewer();
  }
  else {
    Drupal.BatireUserDocsPdfView.createFlashFromPdf();
  }
}

Drupal.BatireUserDocsPdfView.addPdfViewer = function() {
  // Setting parameters/
  var swfVersionStr = "9.0.124";
  var xiSwfUrlStr = "";
  var flashvars = {};
  flashvars.url = Drupal.settings.batire_user_docs_pdf.pdf_file_path;
  //flashvars.defaultScaleMode = 'fillScreen';

  var params = {};
  params.quality = "high";
  params.bgcolor = "#f0f0f0";
  params.play = "true";
  params.loop = "true";
  params.wmode = "transparent";
  params.scale = "noscale";
  params.menu = "true";
  params.devicefont = "false";
  params.salign = "lt";
  params.allowscriptaccess = "sameDomain";
  params.allowFullScreen = "true";
  var attributes = {};
  attributes.id = "viewer";
  attributes.name = "viewer";
  attributes.align = "middle";

  // Setting SWF File directory, name and size.
  swfobject.embedSWF(
    Drupal.settings.batire_user_docs_pdf.viewerpath, "flashContent",
    Drupal.settings.batire_user_docs_pdf.width, Drupal.settings.batire_user_docs_pdf.height,
    swfVersionStr, xiSwfUrlStr,
    flashvars, params, attributes);
}

/**
 * Process of downloading pdf file
 */
Drupal.BatireUserDocsPdfView.createFlashFromPdf = function() {
  $(Drupal.BatireUserDocsPdfView.pdf_viewer_class).css({
    'height': Drupal.settings.batire_user_docs_pdf.height,
    'width': Drupal.settings.batire_user_docs_pdf.width
  });
  sommaireAddLoader($(Drupal.BatireUserDocsPdfView.pdf_viewer_class));

  if($(Drupal.BatireUserDocsPdfView.pdf_viewer_class).hasClass('processed')) {
    return false;
  }
  $(Drupal.BatireUserDocsPdfView.pdf_viewer_class).addClass('processed');
  //  return false;

  var options = {
    nid  : Drupal.settings.batire_user_docs.nid
  };

  $.get(
    Drupal.settings.batire_user_docs_pdf.download_flash_pdf_url,
    options,
    function(response) {
      if (response.status == 1) {
        if (response.wait && response.wait == 1) {
          // Send ajax query and get info about generated swf file
          var interval = setInterval(function() {
            $.get(
              Drupal.settings.batire_user_docs_pdf.download_flash_pdf_url,
              options,
              function(response) {
                if (response.status == 1) {
                  if (response.wait !== 1) {
                    clearInterval(interval);
                    Drupal.settings.batire_user_docs_pdf.pdf_file_path = response.url;
                    Drupal.BatireUserDocsPdfView.addPdfViewer();
                    $('.block-overlay').animate({
                      opacity:0
                    }, 500).remove();
                  }
                }
                else {
                  clearInterval(interval);
                  Drupal.BatireUserDocsPdfView.clearShowMessage(response.message);
                }
              },'json'
              );
          }, 3000);
        }
        else {
          Drupal.settings.batire_user_docs_pdf.pdf_file_path = response.url;
          Drupal.BatireUserDocsPdfView.addPdfViewer();
          $('.block-overlay').animate({
            opacity:0
          }, 500).remove();
        }
      }
      else {
        Drupal.BatireUserDocsPdfView.clearShowMessage(response.message);
      }
    }, 'json'
    );
  return false;
}

Drupal.BatireUserDocsPdfView.clearShowMessage = function(message) {
  $('.block-overlay').animate({
    opacity:0
  }, 500).remove();
  $(Drupal.BatireUserDocsPdfView.pdf_viewer_class).attr('style', '');
  $(Drupal.BatireUserDocsPdfView.pdf_viewer_class).removeClass('processed');
  $(Drupal.BatireUserDocsPdfView.flash_viewer_id).html(message);
}
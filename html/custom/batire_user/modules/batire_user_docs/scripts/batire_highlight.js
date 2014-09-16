Drupal.behaviors.batire_highlight = function(context) {
  $(document).keydown(function(e) {
    if(e.ctrlKey && e.keyCode == 70) {
      var searchInput = $('#edit-page-search');
      searchInput.focus();
      highlightScroll($('.document-content-body'), 10);
      return false;
    }
  });

  $('#edit-page-search', context).keydown(function(e) {
    if(e.keyCode == 13) {
      return false;
    }
  });

  $('#edit-page-search', context).bind('keyup change', function(ev) {
    // pull in the new value
    var searchTerm = $(this).val();

    // remove any old highlighted terms
    $('.document-content-body').removeHighlight("highlight-on-page");
    $('#edit-page-search-wrapper').removeClass('no-found');

    // disable highlighting if empty
    if (searchTerm.length >= 3) {
      // highlight the new term
      $('.document-content-body').highlight(searchTerm, false, "highlight-on-page");
      var highlights = $(".highlight-on-page");
      
      if(highlights.length == 0) {
        $('#edit-page-search-wrapper').addClass('no-found');
      }
      else {
        highlights.each(function(i, e) {
          $(this).attr('highlightnumber', i);
        });

        highlightScroll(highlights);
      }
    }
  });
  
  $('.search-on-page-prev', context).bind('click', function(){
    var currentHighlight = getCurrentHighlight();
    if(currentHighlight !== false) {
      var count = $(".highlight-on-page").length - 1;
      var prev = true;
      var scrollTop = $(window).scrollTop();
      var windowHeight = $(window).height();
      if(count == currentHighlight) {
        var el = $(".highlight-on-page[highlightnumber=" + currentHighlight + "]");
        var offset = el.offset();
        if(!((scrollTop + windowHeight / 2 - 5) <= offset.top && (el.height() + offset.top) < (scrollTop + windowHeight))) {
          prev = false;
        }
      }
      if(prev) {
        var lich = 1;
        var currTop = $(".highlight-on-page[highlightnumber=" + currentHighlight + "]").offset().top;
        var stop = true;
        while(stop) {
          if($(".highlight-on-page[highlightnumber=" + (currentHighlight - lich) + "]").length) {
            if(currTop == $(".highlight-on-page[highlightnumber=" + (currentHighlight - lich) + "]").offset().top) {
              lich = lich + 1;
            }
            else {
              stop = false;
            }
          }
          else {
            lich = 0;
            stop = false;
          }
        }
        currentHighlight = currentHighlight - lich;
      }

      if(Math.round(scrollTop + windowHeight / 2 - 5) != $(".highlight-on-page[highlightnumber=" + currentHighlight + "]").offset().top) {
        highlightScroll($(".highlight-on-page[highlightnumber=" + currentHighlight + "]"));
      }
    }

    return false;
  });

  $('.search-on-page-next', context).bind('click', function(){
    var currentHighlight = getCurrentHighlight();
    if(currentHighlight !== false) {
      var next = true;
      var scrollTop = $(window).scrollTop();
      var windowHeight = $(window).height();
      if(currentHighlight == 0) {
        var el = $(".highlight-on-page[highlightnumber=" + currentHighlight + "]");
        var offset = el.offset();
        if(!((scrollTop + windowHeight / 2 - 5) <= offset.top && (el.height() + offset.top) < (scrollTop + windowHeight))) {
          next = false;
        }
      }
      if(next) {
        var lich = 1;
        var currTop = $(".highlight-on-page[highlightnumber=" + currentHighlight + "]").offset().top;
        var stop = true;
        while(stop) {
          if($(".highlight-on-page[highlightnumber=" + (currentHighlight + lich) + "]").length) {
            if(currTop == $(".highlight-on-page[highlightnumber=" + (currentHighlight + lich) + "]").offset().top) {
              lich = lich + 1;
            }
            else {
              stop = false;
            }
          }
          else {
            lich = 0;
            stop = false;
          }
        }
        currentHighlight = currentHighlight + lich;
      }

      if(Math.round(scrollTop + windowHeight / 2 - 5) != $(".highlight-on-page[highlightnumber=" + currentHighlight + "]").offset().top) {
        highlightScroll($(".highlight-on-page[highlightnumber=" + currentHighlight + "]"));
      }
    }

    return false;
  });
};

highlightScroll = function(element, top) {
  top = top || $(window).height() / 2 - 5;
  var targetOffset = element.offset().top - top;
  $('html,body').animate({
    scrollTop: targetOffset
  }, 500);
}

inWindow = function(s){
  var scrollTop = $(window).scrollTop();
  var windowHeight = $(window).height();
  var currentEls = $(s);
  var result = [];
  currentEls.each(function(){
    var el = $(this);
    var offset = el.offset();
    if((scrollTop + windowHeight / 2 - 5) <= offset.top && (el.height() + offset.top) < (scrollTop + windowHeight))
      result.push(this);
  });
  if(result.length == 0) {
    currentEls.each(function(){
      var el = $(this);
      var offset = el.offset();
      if((scrollTop + windowHeight) <= offset.top)
        result.push(this);
    });
  }
  if(result.length == 0) {
    $(s + ':last').each(function(){
      result.push(this);
    });
  }
  return $(result);
}

getCurrentHighlight = function() {
  var highlight = inWindow(".highlight-on-page");
  if(highlight.length) {
    return parseInt(highlight.attr('highlightnumber'));
  }
  else {
    return false;
  }
}
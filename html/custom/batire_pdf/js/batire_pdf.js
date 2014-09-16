var batire_pdf = batire_pdf || {};
var stopInterval = null;
var percent = 120;
var currentPercentPage = false;
var currentPercentFull = false;

Drupal.behaviors.batire_pdf = function(context) {
  batire_pdf.pdfMini($(context));
  batire_pdf.pdf($(context));

  $('.pdf-wrapp-link a', context).hover(function () {
    $(this).parent('.pdf-wrapp-link').toggleClass("show-tooltip");
  });
};
  
batire_pdf.pdf = function (context) {
  // Check whether we are inside iframe and set the timer to hide PDF player controls

  if(document!=parent.document){

    var $parentDoc = $(parent.document);

    $.idleTimer('destroy');

    // Idle state implementation for PDF player
    $.idleTimer(1000);

    $(document).bind("idle.idleTimer", function(){
      $parentDoc.find("body").addClass('body-idle');
      $("body").addClass('body-idle');
    });

    $(document).bind("active.idleTimer", function(){
      $parentDoc.find("body").removeClass('body-idle');
      $("body").removeClass('body-idle');
    });

  }

  //Checking for max possible width and height, browser size without scrollbars
  batire_pdf.disableScroll();
  var $resWidth = parent.document.body.clientWidth;
  var $resHeight = parent.document.body.clientHeight;
  batire_pdf.enableScroll();

  //Executing the player
  if ($.browser.safari) {

    context.find(".zoom-pane img").load(function(){
      batire_pdf.pdf.player(context, ".zoom-pane img", $resWidth, $resHeight);
    });

  }
  else if($.browser.msie){

    context.find(".zoom-pane img").each(function() {
      var $img = $(this);
      $img.load(function(){
        batire_pdf.pdf.player(context, ".zoom-pane img", $resWidth, $resHeight);
      });
      $img.attr("src", $img.attr("src"));
    });
  }
  else{
    context.find(".zoom-pane img").load(function(){
      batire_pdf.pdf.player(context, ".zoom-pane img", $resWidth, $resHeight);
    });
  }

  $('body').append('<div class="royalsSlidersWrappers"></div>');
  $('body').append('<div class="royalsSlidersWrappersButton"></div>');
  $('.player-button-gallery').each(function(){
    var playerButtonGallery = $(this),
    buttonGalleryOpen = playerButtonGallery.find('.royal-gallery-open'),
    royalSliderWrapper = playerButtonGallery.find('.royalSliderWrapper');

    if(royalSliderWrapper.length){
      var royalSliderWrapperClone = royalSliderWrapper.clone(true);
      royalSliderWrapper.remove();
      royalSliderWrapperClone.appendTo('.royalsSlidersWrappers');
    };

    buttonGalleryOpen.bind('click', function(){
      $('.royalsSlidersWrappers').before('<div class="overlay-royalSlider"></div>');

      if (typeof royalSliderWrapperClone !=="undefined" && royalSliderWrapperClone.length){
        // Safari scrolltop issue fix
        if(navigator.userAgent.indexOf('Safari') != -1 && navigator.userAgent.indexOf('Chrome') == -1){
          batire_pdf.disableScroll();
        }

        if(!royalSliderWrapperClone.find('.royalSlider').hasClass('.rsDefault')){
          var royalSlider = royalSliderWrapperClone.find('.royalSlider'),
          royalSliderItemsCount = royalSlider.next('.royalSlider-controls-bar').find('.royalSlider-items-count'),
          royalSliderItemsCountCurrent = royalSliderItemsCount.find('.current'),
          royalSliderItemsCountAll = royalSliderItemsCount.find('.all');

          royalSlider.royalSlider({
            controlNavigation: false,
            autoScaleSlider: true,
            fullscreen: {
              enabled: true,
              nativeFS: false,
              keyboardNav: false
            },
            autoScaleSliderWidth: 960,
            autoScaleSliderHeight: 600,
            loop: false,
            sliderDrag: false,
            imageScaleMode: 'fit-if-smaller',
            navigateByClick: false,
            numImagesToPreload: 3,
            arrowsNavAutoHide: true,
            arrowsNavHideOnTouch: true,
            keyboardNavEnabled: false,
            fadeinLoadedSlide: true,
            globalCaption: false,
            globalCaptionInside: false,
            imgHeight: 50,
            thumbs: {
              appendSpan: true,
              firstMargin: true,
              paddingBottom: 0
            }
          });
          
          royalSlider.data('royalSlider').ev.on('rsBeforeAnimStart', function(){
            royalSliderItemsCountCurrent.val(royalSlider.data('royalSlider').currSlideId + 1);
            batire_pdf.curentInputSliderWidth(royalSliderItemsCountCurrent);

            batire_pdf.resizeImageInSlide(royalSlider, '.royalSliderWrapper', 2147483647);
            
            batire_pdf.fullScroll(royalSlider);

            autoHideControlsElements(royalSlider.data('royalSlider').currSlide.content);
          });

          royalSlider.data('royalSlider').ev.on('rsEnterFullscreen', function(){
            royalSlider.data("royalSlider").goTo($(".pdf-slider .royalSlider-items-count .current").val() - 1);
            $('body').addClass('royalSliderFullscreen');
            royalSlider.closest('.royalSliderWrapper').addClass('royalSliderWrapperFullscreen');

            royalSliderItemsCountAll.text(royalSlider.data('royalSlider').numSlides);
            royalSliderItemsCountCurrent.val(royalSlider.data('royalSlider').currSlideId + 1);
            batire_pdf.curentInputSliderWidth(royalSliderItemsCountCurrent);

            batire_pdf.resizeImageInSlide(royalSlider, '.royalSliderWrapper', 2147483647);

            batire_pdf.curentInputSlider(royalSlider, royalSliderItemsCountCurrent);
          });

          royalSlider.data('royalSlider').ev.on('rsExitFullscreen', function(){
            var royalSliderPage = $(".royalSliderPage").data("royalSlider");
            royalSliderPage.goTo(royalSlider.data('royalSlider').currSlideId);
            
            setTimeout(function() {
              batire_pdf.niceScrollPane(royalSliderPage.currSlide.content, 500);
            }, 1000);

            // Safari scrolltop issue fix
            if(navigator.userAgent.indexOf('Safari') != -1 && navigator.userAgent.indexOf('Chrome') == -1){
              batire_pdf.enableScroll();
            }

            $('body').removeClass('royalSliderFullscreen');
            royalSlider.closest('.royalSliderWrapper').removeClass('royalSliderWrapperFullscreen');

            $('.royalSliderWrapperFullscreen').css({
              opacity: 0
            });
            $('.overlay-royalSlider').animate({
              opacity: 0
            }, 1000, function(){
              $(this).remove();
              $('.royalSliderWrapper').css({
                opacity: 1
              });
            });
          });

          $('.rsFullscreenBtnBody', context).bind('click', function(){
            $('.royalSliderWrapperFullscreen').css({
              opacity: 0
            });
            $('.overlay-royalSlider').animate({
              opacity: 0
            }, 1000, function(){
              $(this).remove();
              $('.royalSliderWrapper').css({
                opacity: 1
              });
            });
            $('.royalSliderWrapperFullscreen').find('.royalSlider').data('royalSlider').exitFullscreen();
            return false;
          });

          royalSlider.data('royalSlider').ev.on('rsBeforeSizeSet', function(){
            batire_pdf.resizeImageInSlide(royalSlider, '.royalSliderWrapper', 2147483647);
          });

          royalSlider.data('royalSlider').ev.on('rsAfterContentSet', function() {
            batire_pdf.resizeImageInSlide(royalSlider, '.royalSliderWrapper', 2147483647);

            autoHideControlsElements(royalSlider.data('royalSlider').currSlide.content);
          });

          var $clearHideEvent = null;
          function autoHideControlsElements($imgElement){
         /*   clearTimeout($clearHideEvent);
            $clearHideEvent = null;
            $imgElement.closest('.royalSliderWrapper').find('.royalSlider-controls-bar').stop().animate({
              opacity: 1
            }, 100);

            if($clearHideEvent == null){
              $clearHideEvent = setTimeout(function(){
                $imgElement.closest('.royalSliderWrapper').find('.royalSlider-controls-bar').stop().animate({
                  opacity: 0
                }, 100);
              }, 1000);
            };*/
          };
          
          $('.rsContainer').bind('mousemove', function(){
            autoHideControlsElements(royalSlider.data('royalSlider').currSlide.content);
          });
          
          $('.royalSlider-controls-bar, .royalsSlidersWrappersButton')
          .bind('mouseover', function(){
            clearTimeout($clearHideEvent);
            $clearHideEvent = null;
          })
          .bind('mouseout', function(){
            autoHideControlsElements(royalSlider.data('royalSlider').currSlide.content);
          });

          if(!royalSlider.next('.royalSlider-controls-bar').find('.next-page').hasClass('bind')){
            royalSlider.next('.royalSlider-controls-bar').find('.next-page').addClass('bind');
            royalSlider.next('.royalSlider-controls-bar').find('.next-page').bind('click', function(){
              royalSlider.data('royalSlider')._c2.trigger('click');
              return false;
            });
          };
          if(!royalSlider.next('.royalSlider-controls-bar').find('.prev-page').hasClass('bind')){
            royalSlider.next('.royalSlider-controls-bar').find('.prev-page').addClass('bind');
            royalSlider.next('.royalSlider-controls-bar').find('.prev-page').bind('click', function(){
              royalSlider.data('royalSlider')._b2.trigger('click');
              return false;
            });
          };
         
          $(".royalsSlidersWrappers .print", context).bind('click', function(){
            batire_pdf.printExternal(".royalSlider");
            return false;
          });
          
          $(".royalsSlidersWrappers .print-all", context).bind('click', function(){
            batire_pdf.printExternalAll(".royalSlider");
            return false;
          });

          $(".royalsSlidersWrappers .pdf-large-page", context).bind('click', function(){
            batire_pdf.largePage(".royalSlider", '.royalSliderWrapper', 2147483647);
            return false;
          });

          $(".royalsSlidersWrappers .pdf-full-page", context).bind('click', function(){
            batire_pdf.fullPage(".royalSlider", '.royalSliderWrapper', 2147483647);
            return false;
          });

          if(!royalSlider.next('.royalSlider-controls-bar').find('.infos').hasClass('bind')){
            royalSlider.next('.royalSlider-controls-bar').find('.infos').bind('click', function(){
              royalSlider.next().next('.player-info-popup').css('visibility', 'visible');
              // Reinitialize the fancy scroll of info block
              var element = royalSlider.next().next('.player-info-popup').find('.scroll-pane').not('.cigale-scroll-reinitialized');
              if (element.length) {
                // Recalculate height of scroll-pane depending on title length (one line title - scroll-pane enlarge height)
                var titleHeight = element.siblings('h2.title').height();
                if (titleHeight + 'px' == element.siblings('h2.title').css('line-height')) {
                  element.addClass('scroll-pane-257');
                  element.height('257px');
                }
                element.addClass('cigale-scroll-reinitialized').jScrollPane({
                  verticalDragMinHeight: 59,
                  verticalDragMaxHeight: 59,
                  autoReinitialise: true
                });
                var api = element.data('jsp');
                api.reinitialise();
              }
              $('.rsFullscreenBtnBody').addClass('rsFullscreenBtnBodyHidden');
              $(this).addClass('bind');
            });
          };
          if(!royalSlider.next().next('.player-info-popup').find('.close-player-info-popup').hasClass('bind')){
            royalSlider.next().next('.player-info-popup').find('.close-player-info-popup').bind('click', function(){
              royalSlider.next().next('.player-info-popup').css('visibility', 'hidden');
              $('.rsFullscreenBtnBody').removeClass('rsFullscreenBtnBodyHidden');
              $(this).addClass('bind');
            });
          };
          
          batire_pdf.fullScroll(royalSlider);
        };

        royalSlider.data('royalSlider').enterFullscreen();
      };
      return false;
    });
  });
}

batire_pdf.pdf.player = function(context, el, $resWidth, $resHeight){
  //Applying necessary CSS for jScrollPane plugin, depending on the browser size
  context.find('html, body').css('overflow', 'hidden');
  context.find('.lightbox-wrap').css('overflow', 'hidden');
  context.find('html,'+
    'body,'+
    '.lightbox-wrap,'+
    '.lightbox-wrap .player-info-popup,'+
    '.lightbox-pdf,'+
    '.lightbox-pdf .zoom-pane,'+
    '.lightbox-pdf table,'+
    '.lightbox-pdf table tr td').css({
    'width': $resWidth, 
    'height': $resHeight
  });
  context.find('.lightbox-pdf table').css({
    'min-width': $resWidth, 
    'min-height': $resHeight
  });

  // Adjusting the sizes of the jspCaps elements to make fixed size scrollbars, adding CSS before jScrollPane initialization
  var $verticalScrollPadd = Math.floor(($resHeight - 643) / 2);
  var $horizontalScrollPadd = Math.floor(($resWidth - 978) / 2);
  $("head").append('<style type="text/css" charset="utf-8">'+
    '.lightbox-pdf .zoom-pane .jspContainer .jspVerticalBar .jspCap{height: '+ $verticalScrollPadd +'px;}'+
    '.lightbox-pdf .zoom-pane .jspContainer .jspHorizontalBar .jspCap{width: '+ $horizontalScrollPadd +'px;}'+
    '</style>');

  /*
  *  Variables set: image file width and height, maximum zoom scale, initial width in the player,
  *  step for zoom, initial zoom level in the player, initial height in the player.
  */
  var $imageWidth = context.find(el).width();
  var $imageHeight = context.find(el).height();
  var $maxScale = $imageWidth * 1.2;
  var $initialWidth = 700;
  var $zoomStep = ($maxScale - $initialWidth) / 10;
  var $initialZoom = $initialWidth / $imageWidth;
  var $initialHeight = Math.floor($imageHeight * $initialZoom);

  // Setting initial image width in the player
  context.find(el).width($initialWidth);

  // Applying styled scrollbars using jScrollPane
  var $pane = context.find(el).parents(".zoom-pane");
  $pane.jScrollPane({
    autoReinitialise: true,
    verticalDragMinHeight: 299,
    verticalDragMaxHeight: 299,
    horizontalDragMinWidth: 299,
    horizontalDragMaxWidth: 299
  });
  var $api = $pane.data('jsp');
  $(el, context).show();

  // Counting percentage to display near the slider
  var $percent = Math.floor($initialWidth / $imageWidth * 100);
  context.find(el).parents(".lightbox-pdf").find(".percentage").html($percent);

  // Applying slider
  context.find(el).parents(".lightbox-pdf").find(".slider").slider({
    min: 0,
    value: $initialWidth,
    max: $maxScale,
    step: $zoomStep,
    slide: function(event, ui) {
      var $percent = Math.floor(ui.value / $imageWidth * 100);
      context.find(el).parents(".lightbox-pdf").find(".percentage").html($percent);
      $(el).width(ui.value);
      $api.reinitialise();
    }
  });

  // Infos popup added
  context.find(el).parents(".lightbox-wrap").find(".close-player-info-popup").click(function(){
    $(parent.document).find("#fancybox-title").show();
    context.find(".light0box-pdf, .caption").fadeIn(150);
    $(this).parents('.player-info-popup').css("visibility", "hidden");
  });

  context.find(el).parents(".lightbox-wrap").find(".infos").click(function(){
    $(parent.document).find("#fancybox-title").hide();
    context.find(".lightbox-pdf, .caption").hide();
    context.find(el).parents(".lightbox-wrap").find(".player-info-popup").css("visibility", "visible");
  });
}

batire_pdf.disableScroll = function(){
  // lock scroll position, but retain settings for later
  var scrollPosition = [
  self.pageXOffset || document.documentElement.scrollLeft || document.body.scrollLeft,
  self.pageYOffset || document.documentElement.scrollTop  || document.body.scrollTop
  ];
  var html = jQuery('html'); // it would make more sense to apply this to body, but IE7 won't have that
  html.data('scroll-position', scrollPosition);
  html.data('previous-overflow', html.css('overflow'));
  html.css('overflow', 'hidden');
  window.scrollTo(scrollPosition[0], scrollPosition[1]);
};

batire_pdf.enableScroll = function(){
  // un-lock scroll position
  var html = jQuery('html');
  var scrollPosition = html.data('scroll-position');
  html.css('overflow', html.data('previous-overflow'));
  $('html').css('overflow', 'auto');
  window.scrollTo(scrollPosition[0], scrollPosition[1]);
};

batire_pdf.pdfMini = function(context){
  $('.royalSliderPage', context).each(function() {
    var royalSlider = $(this),
    royalSliderItemsCount = royalSlider.prev('.royalSlider-controls-bar').find('.royalSlider-items-count'),
    royalSliderItemsCountCurrent = royalSliderItemsCount.find('.current'),
    royalSliderItemsCountAll = royalSliderItemsCount.find('.all');

    royalSlider.royalSlider({
      controlNavigation: false,
      autoScaleSlider: true,
      autoScaleSliderWidth: 662,
      autoScaleSliderHeight: 520,
      loop: false,
      sliderDrag: false,
      imageScaleMode: 'fit-if-smaller',
      navigateByClick: false,
      numImagesToPreload: 3,
      arrowsNavAutoHide: true,
      arrowsNavHideOnTouch: true,
      keyboardNavEnabled: false,
      fadeinLoadedSlide: true,
      globalCaption: false,
      globalCaptionInside: false,
      imgHeight: 50,
      thumbs: {
        appendSpan: true,
        firstMargin: true,
        paddingBottom: 0
      }
    });

    royalSliderItemsCountAll.text(royalSlider.data('royalSlider').numSlides);
    royalSliderItemsCountCurrent.val(royalSlider.data('royalSlider').currSlideId + 1);

    if(!royalSlider.prev('.royalSlider-controls-bar').find('.next-page').hasClass('bind')){
      royalSlider.prev('.royalSlider-controls-bar').find('.next-page').addClass('bind');
      royalSlider.prev('.royalSlider-controls-bar').find('.next-page').bind('click', function(){
        batire_pdf.hideScrollPane();
        royalSlider.data('royalSlider')._c2.trigger('click');
        return false;
      });
    };
    if(!royalSlider.prev('.royalSlider-controls-bar').find('.prev-page').hasClass('bind')){
      royalSlider.prev('.royalSlider-controls-bar').find('.prev-page').addClass('bind');
      royalSlider.prev('.royalSlider-controls-bar').find('.prev-page').bind('click', function(){
        batire_pdf.hideScrollPane();
        royalSlider.data('royalSlider')._b2.trigger('click');
        return false;
      });
    };
    
    $(".pdf-slider .print", context).bind('click', function(){
      batire_pdf.printExternal(".royalSliderPage");
      return false;
    });
    
    $(".pdf-slider .print-all", context).bind('click', function(){
      batire_pdf.printExternalAll(".royalSliderPage");
      return false;
    });

    $(".pdf-slider .pdf-large-page", context).bind('click', function(){
      batire_pdf.largePage(".royalSliderPage", '.pdf-slider', 500);
      return false;
    });

    $(".pdf-slider .pdf-full-page", context).bind('click', function(){
      batire_pdf.fullPage(".royalSliderPage", '.pdf-slider', 500);
      return false;
    });

    royalSlider.data('royalSlider').ev.on('rsBeforeAnimStart', function(){
      royalSliderItemsCountCurrent.val(royalSlider.data('royalSlider').currSlideId + 1);
      batire_pdf.curentInputSliderWidth(royalSliderItemsCountCurrent);
      batire_pdf.resizeImageInSlide(royalSlider, '.pdf-slider', 500);
      batire_pdf.fullScroll(royalSlider);
    });

    batire_pdf.curentInputSlider(royalSlider, royalSliderItemsCountCurrent);
 
    royalSlider.data('royalSlider').ev.on('rsBeforeSizeSet', function(){
      batire_pdf.resizeImageInSlide(royalSlider, '.pdf-slider', 500);
    });

    royalSlider.data('royalSlider').ev.on('rsAfterContentSet', function() {
      batire_pdf.resizeImageInSlide(royalSlider, '.pdf-slider', 500);
    });
    
    batire_pdf.fullScroll(royalSlider);
  });
}

batire_pdf.curentInputSlider = function(royalSlider, royalSliderItemsCountCurrent){
  batire_pdf.curentInputSliderWidth(royalSliderItemsCountCurrent);

  royalSliderItemsCountCurrent.keydown(function(event) {
    var oldVal = this.value;
    var $elem = $(this);
    setTimeout(function(){
      if($elem.val() > royalSlider.data('royalSlider').numSlides) {
        if(oldVal && oldVal <= royalSlider.data('royalSlider').numSlides) {
          $elem.val(oldVal);
        }
        else {
          $elem.val(royalSlider.data('royalSlider').currSlideId + 1);
        }
      }
      batire_pdf.curentInputSliderWidth($elem);
    }, 0);
    
    if(event.keyCode == 13) {
      if($(this).val()) {
        royalSlider.data("royalSlider").goTo($(this).val() - 1);
      }
    }
    else if(event.keyCode == 46 || event.keyCode == 8 || event.keyCode == 9 || event.keyCode == 27 ||
      // Ctrl+A
      (event.keyCode == 65 && event.ctrlKey === true) || 
      // home, end, left, right
      (event.keyCode >= 35 && event.keyCode <= 39)) {
        return;
    }
    else {
      if((event.keyCode < 48 || event.keyCode > 57) && (event.keyCode < 96 || event.keyCode > 105 )) {
        event.preventDefault();
      }          
    }
  });

  royalSliderItemsCountCurrent.change(function(event) {
    var slide = $(this).val();
    if(slide && slide <= royalSlider.data('royalSlider').numSlides) {
      royalSlider.data("royalSlider").goTo(slide - 1);
    }
    else {
      royalSliderItemsCountCurrent.val(royalSlider.data('royalSlider').currSlideId + 1);
    }
    batire_pdf.curentInputSliderWidth(royalSliderItemsCountCurrent);
  });
}

batire_pdf.curentInputSliderWidth = function(elem) {
  var val = elem.val();
  if(val.length) {
    elem.width(val.length * 8);
  }
  else {
    elem.width(8);
  }
}

batire_pdf.resizeImageInSlide = function(royalSlider, selector, zIndex){
  setTimeout(function(){
    var img = royalSlider.data('royalSlider').currSlide.content;
    img.each(function(){
      var $zoomImage = $(this),
          $zoomImageWidth = $zoomImage.width(),
          $zoomImageHeight = $zoomImage.height();

      $zoomImage.css({
        width: 'auto',
        height: 'auto'
      });
      var $zoomImageWidthActual = $zoomImage.width();
      
      if(selector == '.pdf-slider') {
        if(currentPercentPage) {
          $zoomImage.css({
            width: $zoomImageWidthActual * currentPercentPage / 100
          });
          $imagePercents = currentPercentPage;
        }
        else {
          $zoomImage.css({
            width: $zoomImageWidth,
            height: $zoomImageHeight
          });

          var $imagePercents = Math.floor($zoomImage.width() * 100 / $zoomImageWidthActual);
          currentPercentPage = $imagePercents;
        }
      }
      else {
        if(currentPercentFull) {
          $zoomImage.css({
            width: $zoomImageWidthActual * currentPercentFull / 100
          });
          $imagePercents = currentPercentFull;
          if($imagePercents == 0) {
            alert(1);
          }
        }        
        else {
          $zoomImage.css({
            width: $zoomImageWidth,
            height: $zoomImageHeight
          });

          var $imagePercents = Math.floor($zoomImage.width() * 100 / $zoomImageWidthActual);
          currentPercentFull = $imagePercents;
        }
      }
    
      
      if($imagePercents){
        $zoomImage.closest(selector).find('.royalSlider-controls-bar').find('.percentage').html($imagePercents);
      }else{
        $zoomImage.closest(selector).find('.royalSlider-controls-bar').find('.percentage').html('0');
      };

      var zoomSlider = $zoomImage.closest(selector).find('.royalSlider-controls-bar').find('.slider');
      zoomSlider.slider({
        min: 0,
        max: percent,
        value: $imagePercents,
        step: 10,
        slide: function(event, ui) {
          var $imageElement = royalSlider.data('royalSlider').currSlide.content,
          $percentWidth = Math.floor(ui.value * $zoomImageWidthActual / 100),
          $percent = Math.floor($percentWidth * 100 / $zoomImageWidthActual);
          if(selector == '.pdf-slider') {
            currentPercentPage = $percent;
          }
          else {
            currentPercentFull = $percent;
          }
          $zoomImage.closest(selector).find('.royalSlider-controls-bar').find('.percentage').html($percent);
          $imageElement.width($percentWidth);
          batire_pdf.niceScrollPane($zoomImage, zIndex);
        }
      });
      zoomSlider.find('a').removeAttr('href');
      zoomSlider.find('.ui-slider-handle').unbind('keydown');
    });  
    batire_pdf.niceScrollPane(img, zIndex);
  }, 0);
}
    
batire_pdf.niceScrollPane = function(img, zIndex){
  var $this = img.parent();
  var scroll = $this.getNiceScroll();
  if(scroll.length == 0) {
    batire_pdf.hideScrollPane();
    $this.niceScroll({
      cursorcolor: '#409AEB',
      cursorwidth: 20,
      cursorminheight: 290,
      cursorborderradius: 0,
      cursorborder: 0,
      zindex: zIndex
    });
    scroll = $this.getNiceScroll();
  }

  batire_pdf.hideScrollPane();
  scroll.onResize();
  
  if(scroll.length > 0) {
    setTimeout(function(){
      batire_pdf.hideScrollPane();
      scroll = $this.getNiceScroll();
      scroll.each(function(){
        console.log(this);
        if(this.visibility) {
          if(this.rail.visibility) {
            $("#" + this.id).css({'z-index': zIndex, 'display': 'block'});
          }
          if(this.railh.visibility) {
            $("#" + this.id + "-hr").css({'z-index': zIndex, 'display': 'block'});
          }
        }
      });
    }, 1200);
  }
}

batire_pdf.hideScrollPane = function() {
  $("div.ascrailScroll, div.ascrailScroll-hr").css({'z-index': -1, 'opacity' : 0, 'display': 'none'});
}

var count = printCount = 0;

batire_pdf.printExternal = function(selector) {
  var royalSliderPage = $(selector).data("royalSlider");
  var div = $('<div />'); 
  var img = $('<img />', {
    'src': royalSliderPage.currSlide.content.attr("src"),
    'style': 'page-break-after:avoid; width:100%;'
  });
  div.append(img);
  
  printCount = 1;
  batire_pdf.print(div);
}

batire_pdf.printExternalAll = function(selector) {
  var royalSliderPage = $(selector).data("royalSlider");

  var div = $('<div />');
  jQuery.each(royalSliderPage.slides, function(){
    var img = $('<img />', {
      'src': this.images[0],
      'style': 'page-break-after:auto; width:100%;'
    });
    div.append(img);
  });
  
  printCount = royalSliderPage.slides.length;  
  batire_pdf.print(div);
}

batire_pdf.print = function(content) {
  var WinPrint = window.open('', '', 'width=800,height=650,scrollbars=1,menuBar=1');
  count = 0;

  WinPrint.document.write(content.html());
  $(WinPrint.document).find('img').each(function(){
    $(this).load(function(){
      count = count + 1;
      if(count == printCount) {
        WinPrint.print();
        WinPrint.close();
      }
    });
  });
  WinPrint.document.close();
  WinPrint.focus();
}

batire_pdf.largePage = function(selector, parentSelector, zIndex) {
  var royalSlider = $(selector);
  var img = royalSlider.data('royalSlider').currSlide.content;
  var width = $(parentSelector).find('.rsOverflow').width();
  var height = $(parentSelector).find('.rsOverflow').height() - 6;

  img.css({
    width: 'auto',
    height: 'auto'
  });
      
  var originalWidth = img.width();

  if(originalWidth*percent/100 < width) {
    img.width(originalWidth*percent/100);
  }
  else {
    img.width(width);
  }

  if(parentSelector == '.pdf-slider') {
    currentPercentPage = Math.floor(img.width() * 100 / originalWidth);
  }
  else {
    currentPercentFull = Math.floor(img.width() * 100 / originalWidth);
  }

  batire_pdf.resizeImageInSlide(royalSlider, parentSelector, zIndex);
}

batire_pdf.fullPage = function(selector, parentSelector, zIndex) {
  var royalSlider = $(selector);
  var img = royalSlider.data('royalSlider').currSlide.content;
  var width = $(parentSelector).find('.rsOverflow').width();
  var height = $(parentSelector).find('.rsOverflow').height() - 6;

  img.css({
    width: 'auto',
    height: 'auto'
  });
      
  var originalWidth = img.width();
  var originalHeight = img.height();
  
  if(width/originalWidth < height/originalHeight) {
    img.width(width);
  }
  else {
    img.width(originalWidth*height/originalHeight);
  }
  
  if(parentSelector == '.pdf-slider') {
    currentPercentPage = Math.floor(img.width() * 100 / originalWidth);
  }
  else {
    currentPercentFull = Math.floor(img.width() * 100 / originalWidth);
  }
  
  batire_pdf.resizeImageInSlide(royalSlider, parentSelector, zIndex);
}

batire_pdf.fullScroll = function(royalSlider) {
  var scroll = royalSlider.prev('.royalSlider-controls-bar').find('.royalSliderScroll');
  if(scroll.length == 0) {
    scroll = royalSlider.next('.royalSlider-controls-bar').find('.royalSliderScroll');
  }
  scroll.slider({
    min: 0,
    max: royalSlider.data('royalSlider').numSlides,
    value: royalSlider.data('royalSlider').currSlideId,
    step: 1,
    slide: function(event, ui) {
      royalSlider.data("royalSlider").goTo(ui.value);
    }
  });
  scroll.find('a').removeAttr('href');
}

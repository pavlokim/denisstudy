// $, Theme and Drupal Namespaces.

var vlm = vlm || {};
var Drupal = Drupal || {};
Drupal.settings = Drupal.settings || {};
Drupal.settings.theme = Drupal.settings.theme || {};

// If Drupal is not available - we are in slice environment.
if (!Drupal.t) {

  // Prepare behavior root.
  Drupal.behaviors = {};

  // Implement drupal translate.
  Drupal.t = function (text) {
    return text;
  };

  // Act as drupal behavior.
  $(document).ready(function () {
    Drupal.behaviors.vlm.attach(jQuery(document), {});
  });

  Drupal.behaviors.vlm = {
    attach: function(context, settings) {
      vlm.launch(context, settings);
    }
  };
}
else{

  /**
   * Theme behavior.
   * Register our theme behavior so it can act on DOM.
   */
  Drupal.behaviors.vlm = {
    attach: function(context, settings) {
      vlm.launch($(context), settings);
    }
  };

}
/**
 * Attach handler.
 * Will be called on any DOM changes triggered by Drupal system.
 */
vlm.launch = function (context, settings) {
  vlm.sliderInit(context);
  vlm.rollSections(context);
  vlm.hiddenInfo(context);
  vlm.hiddenInfoRegions(context);
  vlm.browserCheck(context);
  vlm.formComboboxesInit(context);
  vlm.formCheckboxesInit(context);
  vlm.vieweShadow(context);
  vlm.datepicker(context);
  vlm.linkBoxHeight(context);
  vlm.hiddenInfoGlossary(context);
  vlm.popupInits(context);
  vlm.tabsInit(context);
  vlm.formStyleIe(context);
  vlm.tableColWidth(context);
};

/*chrome*/
vlm.browserCheck = function(context) {
  if (navigator.userAgent.toLowerCase().indexOf('chrome') > -1) {
    context.find('body, html').addClass('page-chrome');
  }

  if(jQuery.browser.msie && parseInt(jQuery.browser.version)<=8) {
    context.find('body, html').addClass('page-ie');
  }
};

/*slider init*/
vlm.sliderInit = function(context){
  var $slider = context.find('.block-slider');

  if(!$slider.length){ return false; }

  $slider.flexslider({
    animation: "slide",
    pauseOnHover: true,
    pauseOnAction: false,
    controlNav: true
  });
};

/*accordion*/
vlm.rollSections = function(context){
  var $rollSection = context.find('.roll-section');
  if(!$rollSection.length){ return false; }

  var elements = $rollSection.find('.title');
  elements.each(function(){
    var element = $(this),
        hiddenText = element.closest('.roll-section').find('.content');

    if(hiddenText.length){
      element.bind('click', function(){
        if(hiddenText.hasClass('open')){
          element.removeClass('active');

          hiddenText.slideUp(300, function(){
            hiddenText.removeClass('open');
          });
        }else{
          element.addClass('active');
          //$('.area_auto_size').css({height: 'auto'});
          hiddenText.slideDown(300, function(){
            hiddenText.addClass('open');
          });
          //$('.area_auto_size').trigger('autosize.resize');
        };
        return false;
      });
    }
  });
};

/*hidden info block*/
vlm.hiddenInfo = function(context){
  var $hiddenBlock = context.find('.block-event .block-info-more');

  if(!$hiddenBlock.length){ return false; }

  var $clickArea = context.find('.block-event'),
      thisHeight = context.find('.block-events').height();

  $clickArea.each(function(){
    var $this = $(this),
        $clickBlock = $this.find('.event-area'),
        $hiddenInfo = $this.find('.block-info-more'),
        hiddenInfoHeight = $hiddenInfo.height(),
        $btnClose = $this.find('.btn-close');

    if($hiddenInfo.length){
      $clickBlock.bind('click', function(){
        if(!$hiddenInfo.hasClass('open')){
          //$hiddenBlock.fadeOut(300);
          //$hiddenBlock.removeClass('open');
          //$hiddenBlock.removeClass('onplace');

          if(thisHeight < hiddenInfoHeight){
            $this.addClass('height-changed');
            $this.animate({height: hiddenInfoHeight}, 300);
            setTimeout(function(){
              $hiddenInfo.addClass('open');
              $hiddenInfo.addClass('onplace');
              $hiddenInfo.fadeIn(300);
            }, 300);
          }else{
            $hiddenInfo.addClass('open');
            $hiddenInfo.addClass('onplace');
            $hiddenInfo.fadeIn(300);
          }
        }/*else{
          $hiddenInfo.fadeOut(300);
          $hiddenInfo.removeClass('open');

          setTimeout(function(){
            $hiddenInfo.removeClass('onplace');

            if($this.hasClass('height-changed')){
              $this.animate({height: thisHeight});
            }
          }, 300);
        }*/
      });

      $btnClose.bind('click', function(){
        $hiddenInfo.fadeOut(300);
        $hiddenInfo.removeClass('open');

        setTimeout(function(){
          $hiddenInfo.removeClass('onplace');

          if($this.hasClass('height-changed')){
            $this.animate({height: thisHeight - 40});
            $this.removeClass('height-changed');
          }
        }, 300);
      });
    }
  });
};

vlm.hiddenInfoRegions = function(context){
    var $hiddenBlock = context.find('.block-region .block-info-more');

    if(!$hiddenBlock.length){ return false; }

    var $clickArea = context.find('.more-info');

    $clickArea.each(function(){
      var $this = $(this),
          //$clickBlock = $this.find('.event-area'),
          $hiddenInfo = $this.parent().find('.block-info-more'),
          hiddenInfoHeight = $hiddenInfo.height(),
          $btnClose = $hiddenInfo.find('.btn-close'),
          $parentContainer = $this.closest('.block-region'),
          thisHeight = $parentContainer.height();

      if($hiddenInfo.length){
        $this.bind('click', function(){
          if(!$hiddenInfo.hasClass('open')){
            //$hiddenBlock.fadeOut(300);
            //$hiddenBlock.removeClass('open');
            //$hiddenBlock.removeClass('onplace');

            if(thisHeight < hiddenInfoHeight){
              $parentContainer.addClass('height-changed');
              $parentContainer.animate({height: hiddenInfoHeight}, 300);
              setTimeout(function(){
                $hiddenInfo.addClass('open');
                $hiddenInfo.addClass('onplace');
                $hiddenInfo.fadeIn(300);
              }, 300);
            }else{
              $hiddenInfo.addClass('open');
              $hiddenInfo.addClass('onplace');
              $hiddenInfo.fadeIn(300);
            }
          }/*else{
            $hiddenInfo.fadeOut(300);
            $hiddenInfo.removeClass('open');

            setTimeout(function(){
              $hiddenInfo.removeClass('onplace');

              if($this.hasClass('height-changed')){
                $this.animate({height: thisHeight});
              }
            }, 300);
          }*/

          return false;
        });

        $btnClose.bind('click', function(){
          $hiddenInfo.fadeOut(300);
          $hiddenInfo.removeClass('open');

          setTimeout(function(){
            $hiddenInfo.removeClass('onplace');

            if($parentContainer.hasClass('height-changed')){
              $parentContainer.animate({height: thisHeight});
              $parentContainer.removeClass('height-changed');
            }
          }, 300);
        });
      }
    });
};

/*hidden block for Glossary*/
vlm.hiddenInfoGlossary = function(context){
  var $hiddenBlock = context.find('.words-section li .block-info-more');

  if(!$hiddenBlock.length){ return false; }

  var $clickArea = context.find('.more-info'),
      //$section = context.find('.section-line'),
      thisHeight = context.find('.section-line').height();

  $clickArea.each(function(){
    var $this = $(this),
        $hiddenInfo = $this.parent().find('.block-info-more'),
        hiddenInfoHeight = $hiddenInfo.height(),
        $sectionLine = $this.closest('.section-line'),
        $btnClose = $hiddenInfo.find('.btn-close');

    var $hiddenBlocks = $sectionLine.find('.block-info-more');

    if($hiddenInfo.length){
      $this.bind('click', function(){
        if(!$hiddenInfo.hasClass('open')){
          $hiddenBlocks.fadeOut(300);
          $hiddenBlocks.removeClass('open');

          setTimeout(function(){
            $hiddenBlocks.removeClass('onplace');
          }, 300);

         $(this).closest('.section-line').find('.more-info').removeClass('active');

          $(this).addClass('active');
          $sectionLine.addClass('height-changed');
          $sectionLine.animate({height: hiddenInfoHeight + thisHeight + 35}, 300);
          setTimeout(function(){
            $hiddenInfo.addClass('open');
            $hiddenInfo.addClass('onplace');
            $hiddenInfo.fadeIn(300);
          }, 300);
        }else{
          $(this).removeClass('active');
          $hiddenInfo.fadeOut(300);
          $hiddenInfo.removeClass('open');

          setTimeout(function(){
            $hiddenInfo.removeClass('onplace');

            if($sectionLine.hasClass('height-changed')){
              $sectionLine.animate({height: thisHeight});
              $sectionLine.removeClass('height-changed');
            }
          }, 300);
        }

        return false;
      });

      $btnClose.bind('click', function(){
        $this.removeClass('active');
        $hiddenInfo.fadeOut(300);
        $hiddenInfo.removeClass('open');

        setTimeout(function(){
          $hiddenInfo.removeClass('onplace');

          if($sectionLine.hasClass('height-changed')){
            $sectionLine.animate({height: thisHeight});
            $sectionLine.removeClass('height-changed');
          }
        }, 300);
      });
    }
  });
};

/*comboboxes*/
vlm.formComboboxes = function(context, c, w, h, listClass){
  var itemWidth = parseInt(context.find(c).width());
  var itemHeight = parseInt(context.find(c).height());

  var defaultOptions = {
    width: itemWidth,
    height: itemHeight,
    listMaxHeight: true,
    forceScroll: true,
    showSpeed: 0,
    hideSpeed: 0
  };
  var defaultClasses = {
    list: 'list'
  };

  var notselectors = [
    '.combobox-processed'
  ];
  setTimeout(function(){
    context.find(c).not(notselectors.join(', ')).each(function(){
      var $this = jQuery(this);
      $this.combobox(jQuery.extend({}, defaultOptions, {
        width: w,
        height: h
      }),jQuery.extend({}, defaultClasses, {
        list: listClass
      })).addClass('combobox-processed');
    });
  }, 0);
};

vlm.formComboboxesInit = function(context){
  vlm.formComboboxes(context, '.block-filters .select-100 select', 705, 42, 'list combo-form-type-select');
  vlm.formComboboxes(context, '.block-filters .top-section select', 155, 42, 'list combo-form-type-select');
  vlm.formComboboxes(context, '.block-filters .select-big select', 238, 42, 'list combo-form-type-select');
  vlm.formComboboxes(context, '.block-filters select', 163, 42, 'list combo-form-type-select');
  vlm.formComboboxes(context, '.form-section-wrapper .right-column select', 275, 33, 'list combo-form-section-select');
  vlm.formComboboxes(context, '.form-section-wrapper .block-members select', 138, 33, 'list combo-form-section-select');
  vlm.formComboboxes(context, '.form-section-wrapper select', 315, 33, 'list combo-form-section-select');
};

/* checkbox elements */
vlm.formCheckboxes = function (context, c){
  var notselectors = [
  '.checkbox-processed'
  ];
  setTimeout(function(){
    jQuery(c).not(notselectors.join(', ')).checkbox().addClass('checkbox-processed');
  }, 0);
};
vlm.formCheckboxesInit = function (context){
  vlm.formCheckboxes(context, '.block-form input:radio');
  vlm.formCheckboxes(context, '.payment-section input:radio');
  vlm.formCheckboxes(context, '.block-form input:checkbox');
};

/*views shadow*/
vlm.vieweShadow = function(context){
  var $viewsBlockShadow = context.find('.block-view .bg-block');

  if(!$viewsBlockShadow.length){ return false; }

  var $viewsBlock = context.find('.block-section .block-view');

  $viewsBlock.each(function(){
    var $this = $(this),
        $shadow = $this.find('.bg-block');

    if(jQuery.browser.msie && parseInt(jQuery.browser.version)<=8){
      $this.bind('mouseenter', function(){
        $shadow.addClass('show');
      });
      $this.bind('mouseleave', function(){
        $shadow.removeClass('show');
      });
    }else{
      $this.bind('mouseenter', function(){
        $shadow.fadeIn(300, function(){
          $shadow.addClass('show');
        });
      });
      $this.bind('mouseleave', function(){
        $shadow.fadeOut(300, function(){
          $shadow.removeClass('show');
        });
      });
    }
  });
};

/*datepicker*/
vlm.datepicker = function(context){
    var $datePicker = context.find('#datepicker');

    if(!$datePicker.length){ return false; }

    $datePicker.datepicker({
        showOtherMonths: true
    });
};

/*height for links*/
vlm.linkBoxHeight = function(context) {
  var $linkBox = context.find('.block-links-box .link-box'),
      $blockInfo =  context.find('.right-section .block-info');

  if($linkBox.length){
    $linkBox.each(function(){
      var $this = $(this);

      if($this.height() > 20){
        $this.addClass('link-several-lines');
      }
    });
  }

  if($blockInfo.length){
    $blockInfo.each(function(){
      var $this = $(this),
          $text = $this.find('.text');

      if($text.height() > 30){
        $this.addClass('link-several-lines');
      }
    });
  }
};

/*popups*/
vlm.popupInits = function (context){
  var $popup = context.find('.fancybox-popup');
  if(!$popup.length){ return false; }

  /*Cart popup*/
  $popup.fancybox({
    padding: 0,
    autoSize: false,
    fitToView: false,
    width: 369,
    height: 'auto',
    openEffect : 'fade',
    closeEffect : 'fade',
    openSpeed: 300,
    closeSpeed: 0,
    autoResize: false,
    type: 'ajax',
    helpers: {
      overlay : {
        opacity : 0.50,
        speedIn : 300,
      	speedOut : 0
      }
    },
    afterLoad : function(){
      setTimeout(function(){
        jQuery('.close-btn').click(function(){jQuery.fancybox.close();});
      },0);
    }
  });
};

/*tabs*/
vlm.tabsInit = function (context) {
  var $blockTabs = context.find('.block-tabs');

  if(!$blockTabs.length){ return false; }

   var $footer = context.find('#footer');

  $blockTabs.each(function(){
    var $blockTabs = $(this);
    var $tabList = $('.tabs-list a', $blockTabs),
        $tabLi = $('.tabs-list li', $blockTabs),
        $mapMarker = $('.imagemap-mark');

    if($mapMarker.length){
      $tabLi.each(function(){
        var $this = $(this),
            $thisLink = $this.find('a'),
            $thisIndex = $this.index();

        $thisLink.data('tabMapMark', $mapMarker.eq($thisIndex));
      });
    }

    $tabList.bind('click', function() {
      var $this = $(this),
          href = $this.attr('href'),
          $tabElements = $('.tab-content .content', $blockTabs);

      if($mapMarker.length){
        if($mapMarker.hasClass('show')){
          $mapMarker.addClass('hidden').removeClass('visible');
          $this.data('tabMapMark').removeClass('hidden').addClass('visible');
        }
      }

      //var id = href.split('--')[0];
      //var index = $('.tabs-list a', $blockTabs).index($this);

      if(!($this.hasClass('active'))){
        $tabList.removeClass('active');
        $this.addClass('active');
        $tabElements.removeClass('active');
        $(href).addClass('active');
      }

      if($this.hasClass('with-footer-bg')){
        $footer.addClass('footer_bg');
      }else{
        $footer.removeClass('footer_bg');
      }

      return false;
    });
  });
};

vlm.formStyleIe = function(context) {
  if(context.find('body').hasClass('page-ie')){
    var $formsWrapper = context.find('.form-section-wrapper');

    if(!$formsWrapper.length){ return false; }

    var $formText = $formsWrapper.find('.form-text'),
        $formTextArea = $formsWrapper.find('.form-textarea');

    $formText.each(function(){
      var $this = $(this);

      $this.wrap('<div class="form-text-wrap"><div class="form-text-wrap-inner"></div></div>');
    });

    $formTextArea.each(function(){
      var $this = $(this);

      $this.wrap('<div class="form-textarea-wrap"><div class="form-textarea-wrap-inner"></div></div>');
    });
  }
};

vlm.tableColWidth = function(context){
  var $table = context.find('.left-section table');

  if(!$table.length){ return false; }

  $table.each(function(){
    var $this = $(this),
        $colunsLenght = $this.find('th').length;

    $this.addClass('table-' + $colunsLenght);
  });
};
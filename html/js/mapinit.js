var glob =
{
    body           : null,
    mapmark        : null,
    mimagemap_cont : null,
    mimagemap_options:
    {
        SELECTOR : '.mimagemap img',
        STROKE_HOV_WIDTH: 1,
        STROKE_HOV_COLOR: '#FFFFFF',
        STROKE_SEL_WIDTH: 1,
        STROKE_SEL_COLOR: '#FFFFFF',
        STROKE_SEL_HOV_COLOR: '#FFFFFF',
        STROKE_SEL_HOV_WIDTH: 1,
        FILL_HOV_CLR: '#91BA3A',
        FILL_SEL_CLR: '#91BA3A',
        FILL_SEL_HOV_CLR: '#91BA3A',
        ATTR_AREA_ID: 'data-id'
    }
};



(function($){

    $(document).ready
    (
	    function()
	    {
        if(!jQuery('.mimagemap').length){ return false; }

        if(jQuery.browser.msie && parseInt(jQuery.browser.version)<=8) {
          glob.mimagemap_options.FILL_DEF_CLR = "#008E7F";
        }

            glob.body     = $( 'body' );
            glob.mimagemap_cont = $('.mimagemap');

            new MImageMap( glob.mimagemap_options );
            window.mimagemap.Skin( glob.mimagemap_options.SELECTOR );

            //var image = $( glob.mimagemap_options.SELECTOR )[0];

            for(i=0; i<$(glob.mimagemap_cont).length; i++){
              var image = $( '.mimagemap .map'+ (i+1) )[0];
              var wrapper = $(image).closest('.mimagemap');
              var markClass = wrapper.find('img').attr('usemap').substring(1)

              var $mapmark  = $( '<div class="imagemap-mark' + ' ' + markClass + '"  />' );

              wrapper.data('mapmark', $mapmark);

              wrapper.data('mapmark').appendTo('body');

              image.obj_mimagemap.del_on_area_enter_before = map_del_on_area_enter_before;
              image.obj_mimagemap.del_on_area_leave_before = map_del_on_area_leave_before;
              image.obj_mimagemap.del_on_area_click_before = map_del_on_area_click_before;
            }

            /*var image1 = $( '.map1' )[0];

            var image2 = $( '.map2' )[0];

            image.obj_mimagemap.del_on_area_enter_before = map_del_on_area_enter_before;
            image.obj_mimagemap.del_on_area_leave_before = map_del_on_area_leave_before;
            image.obj_mimagemap.del_on_area_click_before = map_del_on_area_click_before;

            image2.obj_mimagemap.del_on_area_enter_before = map_del_on_area_enter_before;
            image2.obj_mimagemap.del_on_area_leave_before = map_del_on_area_leave_before;
            image2.obj_mimagemap.del_on_area_click_before = map_del_on_area_click_before;*/

            map_events();
	    }
    );

})(jQuery);

function map_events(area){
  var $mimapWrap = $('.block-map');

  $mimapWrap.each(function(){
    var $this = $(this);

    var link_list = $this.find('.regions li');
    var img = $this.find('.mimagemap img');
    var area_list = $this.find( 'map[name=' + img.attr('usemap').substring(1) + '] area' );

    link_list.bind('mouseenter', function(){
      var $this = $(this);
      var area_id = $this.attr('rel');
      var area = area_list.filter( '[data-id=' + area_id + ']' )[0];

      if(!$this.hasClass('active')){
        window.mimagemap.SetAreaState( area, window.mimagemap.states.HOVERED );
      }
    });

    link_list.bind('mouseleave', function(){
      var $this = $(this);
      var area_id = $this.attr('rel');
      var area = area_list.filter( '[data-id=' + area_id + ']' )[0];

      if(!$this.hasClass('active')){
        window.mimagemap.SetAreaState( area, window.mimagemap.states.DEFAULT );
      }
    });

    link_list.bind('click', function(){
      var $this = $(this);
      var area_id = $this.attr('rel');
      var area = area_list.filter( '[data-id=' + area_id + ']' )[0];
      link_list.removeClass('active');

      markShow(area);

      $this.addClass('active');
      window.mimagemap.SetMapState( area.obj_mimagemap, window.mimagemap.states.DEFAULT );
      window.mimagemap.SetAreaState( area, window.mimagemap.states.SELECTED );
    });
  });

};

function map_del_on_area_enter_before( area )
{
  var link_list = $('.regions li');

  var area_id = area.attributes['data-id'].value;
  var _link   = link_list.filter('[rel=' + area_id + ']');
      _link.addClass('hover');
};

function map_del_on_area_leave_before( area )
{
  var link_list = $('.regions li');

  area.attributes['data-id'].value;
  link_list.removeClass('hover');
};

function map_del_on_area_click_before( area )
{

  markShow(area);

  var link_list = $(area).closest('.block-map').find('.regions li');

  link_list.removeClass('active');

  var area_id = area.attributes['data-id'].value;
  var _link   = link_list.filter('[rel=' + area_id + ']');
      _link.addClass('active');
  window.mimagemap.SetMapState( area.obj_mimagemap, window.mimagemap.states.DEFAULT );
};

function markShow(area){
  var _left, _top, _width, _height;
  var mapmark = $(area).closest('.mimagemap').data('mapmark');
  var markClass = $(area).closest('.mimagemap').find('img').attr('usemap').substring(1);

  if(!mapmark.hasClass(markClass)){
    mapmark.addClass(markClass);
  }

  mapmark.addClass('show');

  _width = area.obj_mimagemap_rectw/2;
  _height = area.obj_mimagemap_recth/2;
  _left = area.obj_mimagemap_rectx + jQuery(area).closest('.mimagemap').offset().left + _width - 13;
  _top  = area.obj_mimagemap_rect_minxy[1] + jQuery(area).closest('.mimagemap').offset().top + _height - 25;

  mapmark.css({ 'left' : _left, 'top' : _top });
};
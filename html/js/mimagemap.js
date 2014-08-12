/***
MImageMap
Version: 1.0beta (08.10.2013)

Copyright 2013-2014 Rogachov Viktor

https://github.com/viktorcpp/
https://github.com/viktorcpp/mimage-map

A jQuery plugin to enhance image maps.
***/

function MImageMap( options )
{
    var _self            = this;
        _self.events     = { CLICK : 'click', MOUSEOVER : 'mouseover', MOUSEOUT : 'mouseout', MOUSEENTER : 'mouseenter', MOUSELEAVE : 'mouseleave', MOUSEMOVE : 'mousemove' };
        _self.states     = { DEFAULT : 'DEFAULT', SELECTED : 'SELECTED', DISABLED : 'DISABLED', DISABLED_HOVERED : 'DISABLED_HOVERED', HOVERED : 'HOVERED', SELECTED_HOVERED : 'SELECTED_HOVERED' };
        _self.image_list = $();
        _self.head       = $( 'head' );
        _self.body       = $( document.body );
        _self.html       = $( 'html' );
        _self.html_body  = $( 'html, body' );
        _self.document   = $( document );
        _self.window     = $( window );
        _self.has_canvas = null;
        _self.options    =
	    {
		    SELECTOR             : 'img:not(.MImageMap-processed)',

            CLS_IMG_MAIN         : 'image-main', /// img with usemap=""
            CLS_IMG_FAKE         : 'image-fake', /// new generated image for background default view
            CLS_PROCESSED        : 'MImageMap-processed',

            /// stroke styles
            STROKE_HOV_COLOR     : '#000', /// hovered  state
            STROKE_HOV_WIDTH     : 1,      /// hovered  state
            STROKE_DIS_COLOR     : '#fff', /// disabled state
            STROKE_DIS_WIDTH     : 0,      /// disabled state
            STROKE_DIS_HOV_COLOR : '#ccc', /// disabled+hovered state
            STROKE_DIS_HOV_WIDTH : 0,      /// disabled+hovered state
            STROKE_SEL_COLOR     : '#fff', /// selected state
            STROKE_SEL_WIDTH     : 0,      /// selected state
            STROKE_SEL_HOV_COLOR : '#fff', /// selected+hovered state
            STROKE_SEL_HOV_WIDTH : 0,      /// selected+hovered state
            STROKE_DEF_COLOR     : 0,      /// default state
            STROKE_DEF_WIDTH     : 0,      /// default state

            FILL_DEF_CLR         : '#0', /// default  state fill
            FILL_HOV_CLR         : '#fff', /// hovered  state fill
            FILL_DIS_CLR         : '#ccc', /// disabled state fill
            FILL_DIS_HOV_CLR     : '#fff', /// disabled state fill
            FILL_SEL_CLR         : '#0f0', /// selected state fill
            FILL_SEL_HOV_CLR     : '#f00', /// selected+hovered state fill

            ATTR_AREA_ID         : 'data-id'
	    };

    window.mimagemap = _self;



    _self._Init = function( options )
    {
        _self.has_canvas = _self.HasCanvas();

        if( typeof options == "object" )
		    for( i in options )
			    _self.options[i] = options[i];

    } /// _self.Init()



    _self._Skin = function( selector )
    {
        var _selector   = !selector ? _self.options.SELECTOR : selector,
            _new_images = $( _selector );

        if( _new_images.length < 1 ) return;

        _self.image_list = _self.image_list.add( _new_images );

        for( var x = 0; x < _new_images.length; x++ )
        {
            var _img_curr  = _new_images.eq(x),
                _img_map   = $( 'map[name=' + _img_curr.attr('usemap').substring(1) + ']' ),
                _area_list = $( 'area', _img_map ),
                _canvas    = $('<canvas />'),
                _img_fake  = _img_curr.clone();

                _img_curr.addClass( _self.options.CLS_PROCESSED );

                if( _self.has_canvas )
                {
                    _canvas.attr({ 'width' : _img_curr.attr('width'), 'height' : _img_curr.attr('height') });
                }
                else
                {
                    _img_curr.attr('hidefocus', 'true');
                    _canvas.css({ 'width' : _img_curr.attr('width'), 'height' : _img_curr.attr('height') });
                }

                _canvas.insertAfter( _img_curr );
                _img_curr.addClass( _self.options.CLS_IMG_MAIN );
                _img_fake.removeClass( _self.options.CLS_IMG_MAIN );
                _img_fake.addClass( _self.options.CLS_IMG_FAKE );
                _img_fake.insertAfter( _canvas );

            var _obj                 = new MImageMapItem();
                _obj.jqo_image       = _img_curr;
                _obj.jqo_image_fake  = _img_fake;
                _obj.jqo_map         = _img_map;
                _obj.jqo_area_list   = _area_list;
                _obj.canvas          = _self.has_canvas ? _canvas[0]                   : _canvas;
                _obj.canvas_context  = _self.has_canvas ? _obj.canvas.getContext('2d') : _canvas;
                _obj.jqo_canvas      = _canvas;
                _obj.region_state    = _self.states.DEFAULT;
                _obj.jqo_image_fake  = _img_fake;
                _obj.image_real_size = { w:_obj.jqo_image.attr('width'), h:_obj.jqo_image.attr('height') };

            _obj.jqo_image[0].obj_mimagemap = _obj;
            _obj.jqo_area_list.each
            (
                function()
                {
                    this.obj_mimagemap            = _obj;
                    this.obj_mimagemap_coords_or  = this.coords.replace(' ', '').replace('\n', '');
                    this.obj_mimagemap_coords     = this.obj_mimagemap_coords_or.split(',');
                    this.obj_mimagemap_state      = _self.states.DEFAULT;
                    this.obj_mimagemap_rect_minxy = [0,0];

                    for( var x = 0; x < this.obj_mimagemap_coords.length; x++ )
                    {
                        this.obj_mimagemap_coords[x] = parseInt( this.obj_mimagemap_coords[x] );
                    }

                    _self._CalcShapeRect( this );
                }
            );

            _img_curr.css({ 'opacity' : 0 });

            _area_list.on( _self.events.MOUSEENTER, _self._OnAreaEnter      );
            _area_list.on( _self.events.MOUSELEAVE, _self._OnAreaLeave      );
            _area_list.on( _self.events.CLICK,      _self._OnAreaClick      );
            _img_curr .on( _self.events.MOUSEENTER, _self._OnImageEnter     );
            _img_curr .on( _self.events.MOUSELEAVE, _self._OnImageLeave     );

            _self._UpdateView( _obj );

        } /// FOR

    } /// _self._Skin



    _self._CalcShapeRect = function( area )
    {
        switch( area.shape.toLowerCase() )
        {
        case 'poly':
            area.obj_mimagemap_rectx      = _self._Util_GetMinX ( area.obj_mimagemap_coords );
            area.obj_mimagemap_rectw      = _self._Util_GetMaxX ( area.obj_mimagemap_coords ) - area.obj_mimagemap_rectx;
            area.obj_mimagemap_recty      = _self._Util_GetMinY ( area.obj_mimagemap_coords );
            area.obj_mimagemap_recth      = _self._Util_GetMaxY ( area.obj_mimagemap_coords ) - area.obj_mimagemap_recty;
            area.obj_mimagemap_rect_minxy = _self._Util_GetMinXY( area.obj_mimagemap_coords );
            break;

        case 'rect':
            area.obj_mimagemap_rectx      = area.obj_mimagemap_coords[0];
            area.obj_mimagemap_rectw      = area.obj_mimagemap_coords[2] - area.obj_mimagemap_coords[0];
            area.obj_mimagemap_recty      = area.obj_mimagemap_coords[1];
            area.obj_mimagemap_recth      = area.obj_mimagemap_coords[3] - area.obj_mimagemap_coords[1];
            area.obj_mimagemap_rect_minxy = [ area.obj_mimagemap_rectx + area.obj_mimagemap_rectw/2, area.obj_mimagemap_recty ];
            break;

        case 'circ':
        case 'circle':
            area.obj_mimagemap_rectx      = area.obj_mimagemap_coords[0] - area.obj_mimagemap_coords[2];
            area.obj_mimagemap_rectw      = area.obj_mimagemap_coords[2] * 2;
            area.obj_mimagemap_recty      = area.obj_mimagemap_coords[1] - area.obj_mimagemap_coords[2];
            area.obj_mimagemap_recth      = area.obj_mimagemap_coords[2] * 2;
            area.obj_mimagemap_rect_minxy = [ area.obj_mimagemap_rectx + area.obj_mimagemap_coords[2], area.obj_mimagemap_recty ];
            break;
        }

    } /// _self._CalcShapeRect



    /// call after makeing all operations
    /// simple update view part of map
    _self._UpdateView = function( obj )
    {
        var _obj = obj;

        _self._ClearCanvas( _obj );

        for( var x = 0; x < _obj.jqo_area_list.length; x++ )
        {
            var _region         = _obj.jqo_area_list.eq(x)[0],
                _region_coords  = _region.obj_mimagemap_coords,
                _region_context = _obj.canvas_context,
                _region_state   = _region.obj_mimagemap_state,
                _fill_style     = _self.options.FILL_HOV_CLR,
                _stroke_width   = _self.options.STROKE_HOV_WIDTH,
                _stroke_style   = _self.options.STROKE_HOV_COLOR;

            switch( _region_state )
            {
            case _self.states.DEFAULT:
                _fill_style   = _self.options.FILL_DEF_CLR;
                _stroke_width = _self.options.STROKE_DEF_COLOR;
                _stroke_style = _self.options.STROKE_DEF_WIDTH;
                break;

            case _self.states.HOVERED:
                _fill_style   = _self.options.FILL_HOV_CLR;
                _stroke_width = _self.options.STROKE_HOV_WIDTH;
                _stroke_style = _self.options.STROKE_HOV_COLOR;
                break;

            case _self.states.SELECTED:
                _fill_style   = _self.options.FILL_SEL_CLR;
                _stroke_width = _self.options.STROKE_SEL_WIDTH;
                _stroke_style = _self.options.STROKE_SEL_COLOR;
                break;

            case _self.states.SELECTED_HOVERED:
                _fill_style   = _self.options.FILL_SEL_HOV_CLR;
                _stroke_width = _self.options.STROKE_SEL_HOV_WIDTH;
                _stroke_style = _self.options.STROKE_SEL_HOV_COLOR;
                break;

            case _self.states.DISABLED:
                _fill_style   = _self.options.FILL_DIS_CLR;
                _stroke_width = _self.options.STROKE_DIS_WIDTH;
                _stroke_style = _self.options.STROKE_DIS_COLOR;
                break;

            case _self.states.DISABLED_HOVERED:
                _fill_style   = _self.options.FILL_DIS_HOV_CLR;
                _stroke_width = _self.options.STROKE_DIS_HOV_WIDTH;
                _stroke_style = _self.options.STROKE_DIS_HOV_COLOR;
                break;

            } /// switch states

            _region.obj_imagemap_fill_color = _fill_style;

            if( !_self.has_canvas )
                _region.obj_imagemap_stroke_width = _stroke_width == 1 ? 0.6 : _stroke_width;
            else
                _region.obj_imagemap_stroke_width = _stroke_width;

            _region.obj_imagemap_stroke_color = _stroke_style;

            _self._RenderShape( _region );

        } /// for

    } /// _self._UpdateView



    _self._ClearCanvas = function( obj )
    {
        var _obj = obj;
        if( _self.has_canvas )
            _obj.canvas_context.clearRect( 0, 0, _obj.canvas.width, _obj.canvas.height );
        else
            _obj.canvas.html('');

    } /// _self._ClearCanvas



    /// main shape render function
    _self._RenderShape = function( _region )
    {
        if( _self.has_canvas )
            _self._RenderShapeCanvas( _region );
        else
            _self._RenderShapeVML( _region );

    } /// _self._RenderShape



    /// canvas render helper
    _self._RenderShapeCanvas = function( _region )
    {
        var _obj     = _region.obj_mimagemap;
        var _coords  = _region.obj_mimagemap_coords;
        var _context = _obj.canvas_context;

        _context.beginPath();

        switch( _region.shape )
        {
        case 'poly':

            _context.moveTo( _coords[0], _coords[1] );

            for( var x = 2; x < _coords.length; x+=2 )
                _context.lineTo( _coords[x], _coords[x+1] );

            _context.lineTo( _coords[0], _coords[1] );

            break;

        case 'rect':
            _context.rect( _coords[0], _coords[1], _coords[2]-_coords[0], _coords[3]-_coords[1] );
            break;

        case 'circ':
        case 'circle':
            _context.arc( _coords[0], _coords[1], _coords[2], 0, 2 * Math.PI, false );
            break;
        }

        _context.closePath();

        if( _region.obj_imagemap_stroke_width > 0 )
        {
            _context.lineWidth   = _region.obj_imagemap_stroke_width;
            _context.strokeStyle = _region.obj_imagemap_stroke_color;
            _context.stroke();
        }

        if( _region.obj_imagemap_fill_color.length > 3 )
        {
            _context.fillStyle = _region.obj_imagemap_fill_color;
            _context.fill();
        }

    } /// _self._RenderShape



    /// IE VML render helper
    /// _region - <area />
    _self._RenderShapeVML = function( _region )
    {
        var _obj            = _region.obj_mimagemap,
            _coords         = _region.obj_mimagemap_coords,
            _context        = _obj.canvas,
            _context_width  = _context.width(),
            _context_height = _context.height(),
            _shape          = '';

        switch( _region.shape.toLowerCase() )
        {
        case 'poly':
            _shape   = '<v:shape ';
            if( _region.obj_imagemap_stroke_width > 0 )
            {
                _shape  += 'stroked="true" ';
                _shape  += 'strokecolor="' + _region.obj_imagemap_stroke_color + '" ';
            }
            else
            {
                _shape  += 'stroked="false" ';
            }
            if( _region.obj_imagemap_fill_color.length > 3 )
            {
                _shape  += 'fillcolor="'   + _region.obj_imagemap_fill_color + '" ';
            }
            _shape  += 'coordorigin="0 0" ';
            _shape  += 'coordsize="' + _context_width + ' ' + _context_height + '" ';
            _shape  += 'path="m ' + _coords[0] + ' ' + _coords[1] + ' l ' + _coords.slice(2).join(',') + ' x e" ';
            _shape  += 'style="width:' + _context_width + 'px;height:' + _context_height + 'px;zoom:1;margin:0;padding:0;position:absolute;left:0;top:0;display:block"';
            _shape  += '><v:shadow on="true" offset="5pt,5pt" color="blue"/></v:shape>';
            break;

        case 'rect':
            _shape  = '<v:rect ';
            if( _region.obj_imagemap_stroke_width > 0 )
            {
                _shape  += 'stroked="true" ';
                _shape  += 'strokecolor="' + _region.obj_imagemap_stroke_color + '" ';
            }
            else
            {
                _shape  += 'stroked="false" ';
            }
            if( _region.obj_imagemap_fill_color.length > 3 )
            {
                _shape  += 'fillcolor="'   + _region.obj_imagemap_fill_color + '" ';
            }
            _shape += 'style="left:' + _coords[0] + 'px;top:'+ _coords[1] +'px;width:' + (_coords[2]-_coords[0]) + 'px;height:' + (_coords[3]-_coords[1]) + 'px;zoom:1;margin:0;padding:0;position:absolute;display:block" >';
            _shape += '</v:rect>';
            break;

        case 'circ':
        case 'circle':
            _shape  = '<v:oval ';
            if( _region.obj_imagemap_stroke_width > 0 )
            {
                _shape  += 'stroked="true" ';
                _shape  += 'strokecolor="' + _region.obj_imagemap_stroke_color + '" ';
            }
            else
            {
                _shape  += 'stroked="false" ';
            }
            if( _region.obj_imagemap_fill_color.length > 3 )
            {
                _shape  += 'fillcolor="'   + _region.obj_imagemap_fill_color + '" ';
            }
            _shape += 'style="left:' + (_coords[0]-_coords[2]) + 'px;top:'+ (_coords[1]-_coords[2]) +'px;width:' + (_coords[2]*2) + 'px;height:' + (_coords[2]*2) + 'px;zoom:1;margin:0;padding:0;position:absolute;display:block" >';
            _shape += '</v:oval>';
            break;
        }

        _shape = $( _shape );

        _context.append( _shape );

    } /// _self._RenderShapeVML



    /// left X coord for area
    _self._Util_GetMinX = function( coords )
    {
        var _out = 999999;

        for( var x = 0; x < coords.length; x+=2 )
            _out = Math.min( _out, coords[x] );

        return parseInt( _out );

    } /// _self._Util_GetMinX



    /// right X coord for area
    _self._Util_GetMaxX = function( coords )
    {
        var _out = -999999;

        for( var x = 0; x < coords.length; x+=2 )
            _out = Math.max( _out, coords[x] );

        return parseInt( _out );

    } /// _self._Util_GetMaxX



    /// top Y coord for area
    _self._Util_GetMinY = function( coords )
    {
        var _out = 999999;

        for( var x = 1; x < coords.length; x+=2 )
            _out = Math.min( _out, coords[x] );

        return parseInt( _out );

    } /// _self._Util_GetMinY



    /// bottom Y coord for area
    _self._Util_GetMaxY = function( coords )
    {
        var _out = -999999;

        for( var x = 1; x < coords.length; x+=2 )
            _out = Math.max( _out, coords[x] );

        return parseInt( _out );

    } /// _self._Util_GetMaxY



    /// returns coords for highest dot in area
    _self._Util_GetMinXY = function( coords )
    {
        var _ret = { x:-1, y:999999 };
        for( var x = 1; x < coords.length; x+=2 )
		{
            if( coords[x] < _ret.y )
            {
                _ret.y = coords[x];
                _ret.x = coords[x-1];
            }
		}

        _ret.x = parseInt( _ret.x );
        _ret.y = parseInt( _ret.y );

        return [ _ret.x, _ret.y ];

    } /// _self._Util_GetMaxXY



    /// area click handler, yep!
    _self._OnAreaClick = function(e)
    {
        e.preventDefault();

        if( this.obj_mimagemap_state == _self.states.DISABLED || this.obj_mimagemap_state == _self.states.DISABLED_HOVERED ) return;

        /// delegate
        this.obj_mimagemap.del_on_area_click_before( this );

        this.obj_mimagemap_state = this.obj_mimagemap_state == _self.states.SELECTED_HOVERED ? _self.states.HOVERED : _self.states.SELECTED_HOVERED;

        /// delegate
        this.obj_mimagemap.del_on_area_click_after( this );

        _self._UpdateView( this.obj_mimagemap );

    } /// _self._OnAreaClick



    /// area mouse enter handler
    _self._OnAreaEnter = function(e)
    {
        e.preventDefault();

        /// delegate
        this.obj_mimagemap.del_on_area_enter_before( this );

        /// switch area state
        switch( this.obj_mimagemap_state )
        {
        case _self.states.DEFAULT:
            this.obj_mimagemap_state = _self.states.HOVERED;
            break;

        case _self.states.SELECTED:
            this.obj_mimagemap_state = _self.states.SELECTED_HOVERED;
            break;

        case _self.states.DISABLED:
            this.obj_mimagemap_state = _self.states.DISABLED_HOVERED;
            break;
        }

        /// delegate
        this.obj_mimagemap.del_on_area_enter_after( this );

        _self._UpdateView( this.obj_mimagemap );

    } /// _self._OnAreaEnter



    /// area mouse exit handler
    _self._OnAreaLeave = function(e)
    {
        e.preventDefault();

        /// delegate
        this.obj_mimagemap.del_on_area_leave_before( this );

        /// switch area state
        switch( this.obj_mimagemap_state )
        {
        case _self.states.HOVERED:
            this.obj_mimagemap_state = _self.states.DEFAULT;
            break;

        case _self.states.SELECTED_HOVERED:
            this.obj_mimagemap_state = _self.states.SELECTED;
            break;

        case _self.states.DISABLED_HOVERED:
            this.obj_mimagemap_state = _self.states.DISABLED;
            break;
        }

        /// delegate
        this.obj_mimagemap.del_on_area_leave_after( this );

        _self._UpdateView( this.obj_mimagemap );

    } /// _self._OnAreaLeave



    /// main image mouse enter handler
    _self._OnImageEnter = function(e)
    {
        e.preventDefault();

        /// delegate
        this.obj_mimagemap.del_on_map_enter_before( this );

        /// magic

        /// delegate
        this.obj_mimagemap.del_on_map_enter_after( this );

    } /// _self._OnImageEnter



    /// main image mouse exit handler
    _self._OnImageLeave = function(e)
    {
        e.preventDefault();

        /// delegate
        this.obj_mimagemap.del_on_map_leave_before( this );

        /// magic

        /// delegate
        this.obj_mimagemap.del_on_map_leave_after( this );

    } /// _self._OnImageLeave



    /*///    PUBLIC    ///*/



    _self.Skin = function( selector )
    {
        var _images = $( selector ).filter( ':not(.' + _self.options.CLS_PROCESSED + ')' );
        _self._Skin( _images );

    } /// _self.Skin



    /// resize full map and recalculate areas
    _self.Resize = function( image, w )
    {
        /// handler
        image.obj_mimagemap.del_on_map_resize_before();

        /// full of magic
        var _obj   = $(image)[0].obj_mimagemap;
        var _ratio = w/_obj.image_real_size.w;

        _obj.jqo_image     .removeAttr('height');
        _obj.jqo_image_fake.removeAttr('height');

        _obj.jqo_image     [0].width  = w;
        _obj.jqo_image_fake[0].width  = w;

        if( _self.has_canvas )
        {
            _obj.jqo_canvas[0].width  = w;
            _obj.jqo_canvas[0].height = Math.round( _obj.image_real_size.h*_ratio );
        }
        else
        {
            _obj.jqo_canvas.css({ 'width' : w, 'height' : Math.round( _obj.image_real_size.h*_ratio ) });
        }

        _obj.jqo_area_list.each
        (
            function()
            {
                this.obj_mimagemap_coords = this.obj_mimagemap_coords_or.split(',');

                var _area_coords     = this.obj_mimagemap_coords,
                    _area_coords_new = [];

                for( var x = 0; x < _area_coords.length; x++ )
                {
                    _area_coords_new[x] = Math.round( _area_coords[x]*_ratio );
                }

                this.coords               = _area_coords_new;
                this.obj_mimagemap_coords = _area_coords_new;

                _self._CalcShapeRect( this );
            }
        );

        /// handler
        image.obj_mimagemap.del_on_map_resize_after();

        _self._UpdateView( _obj );

    } /// _self.Resize



    /// set state for single area
    _self.SetAreaState = function( area, state )
    {
        /// filter area by selector and change it state
        area.obj_mimagemap_state = state;

        /// update view part
        _self._UpdateView( area.obj_mimagemap );

    } /// _self.SetAreaState



    /// set state for area list
    _self.SetAreaStateList = function( obj, area_list, state )
    {
        var _obj      = obj,
            _selector = '';

        /// build attr-based selector
        for( var x = 0; x < area_list.length; x++ )
        {
            /// [data-id=area_name],[data-id=area_name],...,[data-id=area_name]
            _selector += '[' + _self.options.ATTR_AREA_ID + '=\'' + area_list[x] + '\']';
            _selector += x == area_list.length-1 ? '' : ',';
        }

        /// filter area by selector and change it state
        _obj.jqo_area_list.filter(_selector).each( function(){ this.obj_mimagemap_state = state; } );

        /// update view part
        _self._UpdateView( _obj );

    } /// _self.SetAreaStateList



    /// set state for all areas in map
    _self.SetMapState = function( obj, state )
    {
        /// set state for ALL area in map
        obj.jqo_area_list.each( function(){ this.obj_mimagemap_state = state; } );

        /// update view based on new area states
        _self._UpdateView( obj );

    } /// _self.SetMapState



    /// test canvas support - true/false
    _self.HasCanvas = function()
    {
        return document.createElement( 'canvas' ).getContext ? true : false;

    } /// _self.HasCanvas



    _self._Init( options );
}



/// objects connector
/// access obj_mimagemap
function MImageMapItem()
{
    var _self                 = this;
        _self.jqo_image       = null; /// <img />
        _self.jqo_map         = null; /// <map />
        _self.jqo_area_list   = null; /// <area /> list
        _self.canvas          = null; /// <canvas />
        _self.jqo_canvas      = null; /// $('canvas')
        _self.canvas_context  = null; /// canvas context or <canvas /> in IE
        _self.jqo_image_fake  = null; /// $('img') for background
        _self.image_real_size = { w:0, h:0 };

    _self.del_on_area_enter_before = function( area ){  };
    _self.del_on_area_enter_after  = function( area ){  };
    _self.del_on_area_leave_before = function( area ){  };
    _self.del_on_area_leave_after  = function( area ){  };
    _self.del_on_area_click_before = function( area ){  };
    _self.del_on_area_click_after  = function( area ){  };
    _self.del_on_map_enter_before  = function( area ){  };
    _self.del_on_map_enter_after   = function( area ){  };
    _self.del_on_map_leave_before  = function( area ){  };
    _self.del_on_map_leave_after   = function( area ){  };
    _self.del_on_map_resize_before = function( area ){  };
    _self.del_on_map_resize_after  = function( area ){  };

} /// MImageMapItem



/// enabling VML in IE, lol
try{
if( /MSIE/.test(navigator.userAgent) && !window.opera )
{
    document.namespaces.add( 'v', "urn:schemas-microsoft-com:vml" );

    var styles = document.createStyleSheet();
    var shapes = [ 'shape', 'rect', 'oval', 'circ', 'fill', 'stroke', 'imagedata', 'group', 'textbox' ];

    for( var x = 0; x < shapes.length; x++ )
    {
        styles.addRule('v\\:' + shapes[x], "behavior:url(#default#VML);display:block;antialias:true");
    }
}
}catch(e){}
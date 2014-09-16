= PDF To ImageField =

The PDF To ImageField module provides automatic conversion of 
uploaded PDF files to images. 
It can be used either to create a snapshot of the front page,
or to generate a gallery of images from each page in the document.

The module is implemented as CCK widget for FileField where PDFs are uploaded to.
It places generated images into a CCK ImageField on the same content type.

@author Updated by dman 2011
@author Original module by Peritus 2010

== Requirements ==

  CCK, Filefield, Imagefield modules.
  ImageAPI + Imagemagick
  Imagemagick support on your server.

== Installation ==

Once the module is enabled, check your site status at /admin/reports/status
You should see a message that will tell you if your system is ready to run.
If not, you need to check the requirements, and the ImageMagick settings
at admin/settings/imageapi.
See the ImageAPI project docs for troubleshooting that.

If ImageMagick appears to be available but still does not convert PDFs, it 
could be it wasn't installed with 'Ghostscript' libraries or other required 
dependencies. You'l have to go to the ImageMagick forums for help with that.

== Configuration ==

- First, add an imagefield on your chosen content type. This is where the 
  generated images wil be stored.
- Set the allowed fields to 1 if you just want a cover page, or 'unlimited' 
  if you want all pages to be generated.
- Next add a filefield to your chosen content type and choose 
  'pdf_to_imagefield' as the renderer.
- When configuring this field, you will be required to link the uploaded file
  field with the target image field.
- You can add imagecache handling to the imagefield rendering as normal to 
  adjust the size of the results and how they display on the page.


== Processing ==

Processing of PDF may take some time.
Larger documents use the 'batch' process to generate each page.

== Use of ImageMagick ==

Actual processing is perfomed using ImageAPI's ImageMagick toolkit.
GD is not supported.

=== Dev notes ===

The only candidate function from ImageAPI which may perform PDF to image 
convertion is _imageapi_imagemagick_convert(). Unfortunately, it can't pass 
arguments to 'convert' tool of ImageMagick *before* source file specification, 
which is needed to change default density of 100x100dpi. 
On this reason, a custom functionis included in the module's source:

function pdf_to_imagefield_convert_pdf($source, $dest, $args = array(), $extra = array()) {
  . . .
}

== Quickstart ==

There is a drush make file and a 'Features' demo example you can use to help set
up and try this functionality immediately.

=== Use drush make to fetch all required modules ===

- If you have "drush" and "drush make" :
- Change to a working directory you want to install a new site into.
- Get the stub makefile from http://drupalcode.org/project/pdf_to_imagefield.git/blob_plain/refs/heads/6.x-2.x:/pdf_to_imagefield_demo.make.stub
- Run
    drush make --working-copy pdf_to_imagefield.make.stub
  This will download all the dependencies required to run pdf_to_imagefield 
  and the demo feature pdf_document.
- Install the Drupal site and configure the database as usual.

=== Use the Feature to auto-configure a content type ==

- Enable the "PDF Document" feature through modulw admin, or via
    drush en pdf_document
- Check your site status at /admin/reports/status to ensure ImageMagick works.
- A new content type will be available at /node/add/document
  Adding a PDF file to it should create an image when the node is saved
   (not on preview)
   

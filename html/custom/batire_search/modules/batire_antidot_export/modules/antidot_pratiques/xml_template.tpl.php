<?php
/**
 * @file
 *  xml_template.tpl.php
 */
?>
<?php print '<?xml version="1.0" encoding="UTF-8"?>
'; ?>
<fiche>
  <id><?php print $data->cpid; ?></id>
  <url><?php print $data->url; ?></url>
  <etat><?php print $data->state; ?></etat>
  <?php if ($data->type_source) : ?>
    <typeSource id="<?php print $data->type_source['id']; ?>" priorite="<?php print $data->type_source['priorite']; ?>"><?php print $data->type_source['name']; ?></typeSource>
  <?php else : ?>
    <?php print _batire_antidot_export_xml_tag('typeSource'); ?>
  <?php endif; ?>
  <?php if ($data->type_source_off) : ?>
    <source id="<?php print $data->type_source_off['id']; ?>" priorite="<?php print $data->type_source_off['priorite']; ?>"><?php print $data->type_source_off['name']; ?></source>
  <?php else : ?>
    <?php print _batire_antidot_export_xml_tag('source'); ?>
  <?php endif; ?>
  <destination isInBatir="1" isInMJCP="0"/>
  <indexation>
    <?php if ($data->batiment) : ?>
      <typeBatiment id="<?php print $data->batiment['id']; ?>" priorite="<?php print $data->batiment['priorite']; ?>"><?php print $data->batiment['name']; ?></typeBatiment>
    <?php else : ?>
      <?php print _batire_antidot_export_xml_tag('typeBatiment'); ?>
    <?php endif; ?>
    <?php if ($data->batiment_sub) : ?>
      <sousTypeBatiment id="<?php print $data->batiment_sub['id']; ?>" priorite="<?php print $data->batiment_sub['priorite']; ?>"><?php print $data->batiment_sub['name']; ?></sousTypeBatiment>
    <?php else : ?>
      <?php print _batire_antidot_export_xml_tag('sousTypeBatiment'); ?>
    <?php endif; ?>
    <?php if ($data->corps) : ?>
      <corpsEtat id="<?php print $data->corps['id']; ?>" priorite="<?php print $data->corps['priorite']; ?>"><?php print $data->corps['name']; ?></corpsEtat>
    <?php else : ?>
      <?php print _batire_antidot_export_xml_tag('corpsEtat'); ?>
    <?php endif; ?>
    <?php if ($data->corps_sub) : ?>
      <sousCorpsEtat id="<?php print $data->corps_sub['id']; ?>" priorite="<?php print $data->corps_sub['priorite']; ?>"><?php print $data->corps_sub['name']; ?></sousCorpsEtat>
    <?php else : ?>
      <?php print _batire_antidot_export_xml_tag('sousCorpsEtat'); ?>
    <?php endif; ?>
    <?php if ($data->themes) : ?>
      <theme id="<?php print $data->themes['id']; ?>" priorite="<?php print $data->themes['priorite']; ?>"><?php print $data->themes['name']; ?></theme>
    <?php else : ?>
      <?php print _batire_antidot_export_xml_tag('theme'); ?>
    <?php endif; ?>
    <?php if ($data->themes_sub) : ?>
      <sousTheme id="<?php print $data->themes_sub['id']; ?>" priorite="<?php print $data->themes_sub['priorite']; ?>"><?php print $data->themes_sub['name']; ?></sousTheme>
    <?php else : ?>
      <?php print _batire_antidot_export_xml_tag('sousTheme'); ?>
    <?php endif; ?>
  </indexation>
  <documentFondamental>0</documentFondamental>
  <?php if ($data->date) : ?>
    <date><?php print $data->date; ?></date>
  <?php else : ?>
    <?php print _batire_antidot_export_xml_tag('date'); ?>
  <?php endif; ?>
  <numeroRef>20061334</numeroRef>
  <position><?php print $data->position; ?></position>
  <titre><?php print $data->title; ?></titre>
  <?php print _batire_antidot_export_xml_tag('contenu', $data->content); ?>
  <?php print _batire_antidot_export_xml_tag('editeurs', $data->editorial); ?>
  <?php print _batire_antidot_export_xml_tag('ficheMedia', $data->fichemedia); ?>
  <derniere><?php print $data->latest; ?></derniere>
  <version><?php print $data->version; ?></version>
  <drupal>
    <dateCreation><?php print $data->dateCreation; ?></dateCreation>
    <dateMaj><?php print $data->dateMaj; ?></dateMaj>
  </drupal>
</fiche>
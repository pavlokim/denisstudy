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
    <?php if (count($data->batiments)) : ?>
      <?php foreach ($data->batiments as $batiment) : ?>
        <type_arbo>
          <?php if (isset($batiment['batiment']['id'])) : ?>
            <typeBatiment id="<?php print $batiment['batiment']['id']; ?>" priorite="<?php print $batiment['batiment']['priorite']; ?>"><?php print $batiment['batiment']['name']; ?></typeBatiment>
          <?php else : ?>
            <?php print _batire_antidot_export_xml_tag('typeBatiment'); ?>
          <?php endif; ?>
          <?php if (isset($batiment['batiment_sub']['id'])) : ?>
            <sousTypeBatiment id="<?php print $batiment['batiment_sub']['id']; ?>" priorite="<?php print $batiment['batiment_sub']['priorite']; ?>"><?php print $batiment['batiment_sub']['name']; ?></sousTypeBatiment>
          <?php else : ?>
            <?php print _batire_antidot_export_xml_tag('sousTypeBatiment'); ?>
          <?php endif; ?>
        </type_arbo>
      <?php endforeach; ?>
    <?php else : ?>
      <type_arbo>
        <?php print _batire_antidot_export_xml_tag('typeBatiment'); ?>
        <?php print _batire_antidot_export_xml_tag('sousTypeBatiment'); ?>
      </type_arbo>
    <?php endif; ?>
    <?php if (count($data->corps)) : ?>
      <?php foreach ($data->corps as $corps) : ?>
        <corps_arbo>
          <?php if (isset($corps['corps']['id'])) : ?>
            <corpsEtat id="<?php print $corps['corps']['id']; ?>" priorite="<?php print $corps['corps']['priorite']; ?>"><?php print $corps['corps']['name']; ?></corpsEtat>
          <?php else : ?>
            <?php print _batire_antidot_export_xml_tag('corpsEtat'); ?>
          <?php endif; ?>
          <?php if (isset($corps['corps_sub']['id'])) : ?>
            <sousCorpsEtat id="<?php print $corps['corps_sub']['id']; ?>" priorite="<?php print $corps['corps_sub']['priorite']; ?>"><?php print $corps['corps_sub']['name']; ?></sousCorpsEtat>
          <?php else : ?>
            <?php print _batire_antidot_export_xml_tag('sousCorpsEtat'); ?>
          <?php endif; ?>
        </corps_arbo>
      <?php endforeach; ?>
    <?php else : ?>
      <corps_arbo>
        <?php print _batire_antidot_export_xml_tag('corpsEtat'); ?>
        <?php print _batire_antidot_export_xml_tag('sousCorpsEtat'); ?>
      </corps_arbo>
    <?php endif; ?>
    <?php if (count($data->themes)) : ?>
      <?php foreach ($data->themes as $themes) : ?>
        <theme_arbo>
          <?php if (isset($themes['themes']['id'])) : ?>
            <theme id="<?php print $themes['themes']['id']; ?>" priorite="<?php print $themes['themes']['priorite']; ?>"><?php print $themes['themes']['name']; ?></theme>
          <?php else : ?>
            <?php print _batire_antidot_export_xml_tag('theme'); ?>
          <?php endif; ?>
          <?php if (isset($themes['themes_sub']['id'])) : ?>
            <sousTheme id="<?php print $themes['themes_sub']['id']; ?>" priorite="<?php print $themes['themes_sub']['priorite']; ?>"><?php print $themes['themes_sub']['name']; ?></sousTheme>
          <?php else : ?>
            <?php print _batire_antidot_export_xml_tag('sousTheme'); ?>
          <?php endif; ?>
        </theme_arbo>
      <?php endforeach; ?>
    <?php else : ?>
      <theme_arbo>
        <?php print _batire_antidot_export_xml_tag('theme'); ?>
        <?php print _batire_antidot_export_xml_tag('sousTheme'); ?>
      </theme_arbo>
    <?php endif; ?>
  </indexation>
  <documentFondamental>0</documentFondamental>
  <numeroRef><?php print $data->numero_ref; ?></numeroRef>
  <position><?php print $data->position; ?></position>
  <titre><?php print $data->title; ?></titre>
  <?php print _batire_antidot_export_xml_tag('contenu', $data->content); ?>
  <?php if ($data->date) : ?>
    <date><?php print $data->date; ?></date>
  <?php else : ?>
    <?php print _batire_antidot_export_xml_tag('date'); ?>
  <?php endif; ?>
  <?php if ($data->niveau) : ?>
    <niveau><?php print $data->niveau; ?></niveau>
  <?php endif; ?>
  <?php if ($data->sous_niveau) : ?>
    <sousNiveau><?php print $data->sous_niveau; ?></sousNiveau>
  <?php endif; ?>
  <?php if ($data->rubrique) : ?>
    <rubrique><?php print $data->rubrique; ?></rubrique>
  <?php endif; ?>
  <?php if ($data->collection) : ?>
    <collection cpid="<?php print $data->collection['cpid']; ?>"><?php print $data->collection['name']; ?></collection>
  <?php endif; ?>
  <?php if ($data->collection_ord) : ?>
    <collectionOrdre><?php print $data->collection_ord; ?></collectionOrdre>
  <?php endif; ?>
  <?php print _batire_antidot_export_xml_tag('editeurs', $data->editorial); ?>
  <?php if ($data->words_num) : ?>
    <nombreMots><?php print $data->words_num; ?></nombreMots>
  <?php endif; ?>
  <derniere><?php print $data->latest; ?></derniere>
  <version><?php print $data->version; ?></version>
  <?php if ($data->date_archive) : ?>
    <dateArchive><?php print $data->date_archive; ?></dateArchive>
  <?php else : ?>
    <?php print _batire_antidot_export_xml_tag('dateArchive'); ?>
  <?php endif; ?>
  <ante><?php print $data->version_ante; ?></ante>
  <drupal>
    <dateCreation><?php print $data->dateCreation; ?></dateCreation>
    <dateMaj><?php print $data->dateMaj; ?></dateMaj>
  </drupal>
</fiche>
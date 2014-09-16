<?xml version="1.0" encoding="UTF-8"?>
  <xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:php="http://php.net/xsl" exclude-result-prefixes="php m" xmlns:m="http://www.w3.org/1998/Math/MathML">
  <xsl:output method="html" indent="no" encoding="UTF-8" omit-xml-declaration="yes"/>
  <xsl:variable name="space" select="' '" />
  <xsl:template match="/">
    <xsl:apply-templates>
      <xsl:with-param name="titleLevel" select="1" />
    </xsl:apply-templates>
    <xsl:call-template name="footnote"/>
  </xsl:template>



<!-- Top body tag -->
  <xsl:template match="/xml/*">
    <xsl:call-template name="anchor"/>
    <xsl:apply-templates/>
  </xsl:template>

<!-- /Top body tag -->

<!-- Special elements -->

<xsl:template match="SIGNET">
  <xsl:call-template name="anchor"/>
  <xsl:apply-templates/>
</xsl:template>

<xsl:variable name="TYPE-CT" select="boolean('ancestor::FICHE-DETAIL or ancestor::FICHE-DROIT or ancestor::FICHE-ARTICLE or ancestor::FICHE-DESORDRE or ancestor::FICHE-INCENDIE or ancestor::FICHE-NORME or ancestor::FICHE-EQUIPEMENT')"/>
<xsl:template match="OUVRAGE">
  <xsl:choose>
    <xsl:when test="$TYPE-CT">
      <div class="document-content-text document-content-text-borders">
        <span class="notice-text notice-text-blue-2">
          <xsl:text>Ouvrage</xsl:text>
        </span>
        <br/><br/>
        <xsl:apply-templates />
      </div>
    </xsl:when>
    <xsl:otherwise>
      <div class="document-content-title-2">
        <xsl:text>Ouvrage</xsl:text>
      </div>
      <br/>
      <xsl:apply-templates />
    </xsl:otherwise>
  </xsl:choose>
  <xsl:call-template name="auto_br"/>
</xsl:template>

<xsl:template match="SURTITRE">
  <xsl:choose>
    <xsl:when test="$TYPE-CT"></xsl:when>
    <xsl:otherwise><xsl:apply-templates/></xsl:otherwise> <!-- @todo is this necessary for other document types? -->
  </xsl:choose>
</xsl:template>

<xsl:template match="AUTEURCOMPLET">
  <div class="auteur">
    <xsl:apply-templates/>
  </div>
</xsl:template>

<xsl:template match="AUTEUR">
  <xsl:apply-templates/>
  <br/>
</xsl:template>

<xsl:template match="DESORDRE">
  <div class="document-content-title-2">
  <xsl:text>Désordre</xsl:text>
  </div>
  <br/>
  <xsl:apply-templates />
  <xsl:call-template name="auto_br"/>
</xsl:template>

<xsl:template match="SOLUTION">
  <div class="document-content-title-2">
  <xsl:text>Solution</xsl:text>
  </div>
  <br/>
  <xsl:apply-templates />
  <xsl:call-template name="auto_br"/>
</xsl:template>

  <xsl:template match="FICHE-INCENDIE/ANOMALIE | FICHE-INCENDIE/REGLE | FICHE-DESORDRE/DIAGNOSTIQUE | FICHE-DESORDRE/SOLUTION">
    <div class="document-content-text">
      <span class="notice-text notice-text-2">
        <xsl:choose>
          <xsl:when test="name() = 'ANOMALIE'"><xsl:text>Anomalies détectées</xsl:text></xsl:when>
          <xsl:when test="name() = 'REGLE'"><xsl:text>Règles à appliquer</xsl:text></xsl:when>
          <xsl:when test="name() = 'DIAGNOSTIQUE'"><xsl:text>Diagnostic</xsl:text></xsl:when>
          <xsl:when test="name() = 'SOLUTION'"><xsl:text>Solutions</xsl:text></xsl:when>
        </xsl:choose>
      </span>
    </div>
    <br/><br/>
    <xsl:apply-templates>
      <xsl:with-param name="titleLevel" select="3"/>
      <xsl:with-param name="disable_title_auto_br" select="1"/>
    </xsl:apply-templates>
    <xsl:call-template name="auto_br"/>
  </xsl:template>

  <xsl:template match="tab">
    <xsl:text>&#160;&#160;&#160;</xsl:text>
  </xsl:template>

  <xsl:template match="TITRE/BR">
    <xsl:text> </xsl:text>
  </xsl:template>

 <!-- <xsl:template match="TITRE/*">
    <xsl:value-of select="normalize-space(.)"/>
    <xsl:apply-templates select=".." />
  </xsl:template>
-->


  <xsl:template match="ENTREDAC">
    <xsl:apply-templates />
    <xsl:call-template name="auto_br"/>
  </xsl:template>

  <xsl:template match="FIGURE/TITRE | FIGURECMT/TITRE">
    <xsl:apply-templates />
  </xsl:template>

  <xsl:template match="NOTE/PARA | tabnote/para">
    <xsl:param name="para_prefix" />
    <span class="document-notes">
      <xsl:value-of select="$para_prefix"/>
      <xsl:apply-templates />
    </span>
    <xsl:call-template name="auto_br"/>
  </xsl:template>

  <xsl:template match="LEGENDE/PARA">
    <xsl:apply-templates />
    <xsl:call-template name="auto_br"/>
  </xsl:template>

  <xsl:template match="QUESTION">
    <b>
      <xsl:apply-templates>
        <xsl:with-param name="disable_auto_br" select="1"/>
      </xsl:apply-templates>
    </b>
  </xsl:template>

  <xsl:template match="QR | REPMIN | JURISP">
    <xsl:apply-templates />
    <xsl:call-template name="auto_br"/>
  </xsl:template>

  <xsl:template match="QR/SOURCE | REPMIN/SOURCE | JURISP/SOURCE">
    <xsl:apply-templates />
    <xsl:call-template name="auto_br"/>
  </xsl:template>

  <xsl:template match="TXTOFF/TITRE | TXTOFF/PARA">
    <xsl:if test="preceding-sibling::*">
      <br/>
    </xsl:if>
    <xsl:apply-templates />
    <xsl:call-template name="auto_br"/>
  </xsl:template>

  <xsl:template match="text()">
    <xsl:value-of select="." />
  </xsl:template>

  <xsl:template match="rlentry">
    <xsl:value-of select="@gtext"/>
    <xsl:text> </xsl:text>
    <xsl:apply-templates />
    <xsl:call-template name="auto_br"/>
  </xsl:template>

  <xsl:template match="concept1">
    <b>
    <xsl:value-of select="@gtext"/>
    <xsl:text> </xsl:text>
    </b>
    <xsl:apply-templates />
    <xsl:call-template name="auto_br"/>
  </xsl:template>

  <xsl:template match="termdef">
    <b>
    <xsl:apply-templates />
    </b>
  </xsl:template>


 <xsl:template match="TXTFINTRO">
   <xsl:apply-templates />
   <xsl:call-template name="auto_br" />
 </xsl:template>

  <xsl:template match="m:math">
  </xsl:template>

  <xsl:template match="fignote">
    <div class="document-image-info document-image-info-line">
      <xsl:choose>
      <xsl:when test="string(.)='Légende'">
      <b>
        <xsl:text>Légende</xsl:text>
      </b>

      </xsl:when>
      <xsl:otherwise>
    <xsl:apply-templates />
    </xsl:otherwise>
    </xsl:choose>
    </div>
  </xsl:template>

  <xsl:template match="label">
    <xsl:apply-templates />
    <xsl:text> </xsl:text>
  </xsl:template>


  <!-- Multifigure -->


  <xsl:template match="figrp">
     <xsl:apply-templates select="fig" />
     <xsl:apply-templates select="multi_fignote"/>
    <xsl:call-template name="auto_br"/>
    <div class="document-content-text-notes">
      <p align="center">
        <xsl:text>Figure </xsl:text>
    <xsl:value-of select="@gtext"/>
     <xsl:text> </xsl:text>
    <xsl:apply-templates select="multi_figtit" />
    </p>
    </div>
    <br />
  </xsl:template>

  <xsl:template match="fig">
    <div class="image-block">
      <xsl:apply-templates />
    </div>
  </xsl:template>

  <xsl:template match="multi_figtit[name(..)='figrp']" mode="at-the-end">
    <xsl:apply-templates />
  </xsl:template>

  <xsl:template match="multi_figtit[parent::fig]">
    <div class="document-image-info">
      <p align="center">
        <b>
          <xsl:text>Figure </xsl:text>
          <xsl:if test="ancestor::figrp[1]">
            <xsl:value-of select="ancestor::figrp[1]/@gtext"/>
          </xsl:if>
          <xsl:value-of select="../@gtext"/>
          <xsl:text> </xsl:text>
          <xsl:apply-templates />
        </b>
      </p>
    </div>
  </xsl:template>

  <!-- /Multifigure -->

  <!-- Prebody document -->
  <!--
  <prebody-generalites>
    <prebody-description>
      <prebody-reference>...</prebody-reference>
      <prebody-dateeff>...</prebody-dateeff>
      <prebody-indice>...</prebody-indice>
      <prebody-codesics>[codesics]</prebody-codesics>
      <prebody-titre2>[titre2fr]</prebody-titre2>
      <prebody-titre3>[titre3fr]</prebody-titre3>
      <prebody-titreen>[titreen]</prebody-titreen>
      <prebody-titrege>[titrege]</prebody-titrege>
    </prebody-description>
    <prebody-statut>[statut]</prebody-statut>
    <prebody-corres>[corres]</prebody-corres>
    <prebody-descripteurs>[descripteurs]</prebody-descripteurs>
    <prebody-modifications>[modifications]</prebody-modifications>
    <prebody-corrections>[corrections]</prebody-corrections>
    <prebody-commission>[commission]</prebody-commission>
    <prebody-avtpropnat>[avtpropnat]</prebody-avtpropnat>
    <prebody-ptitreen>[ptitreen]</prebody-ptitreen>
    <prebody-avtpropen>[avtpropnat]</prebody-avtpropen>
  </prebody-generalites> -->

  <xsl:template match="prebody-generalites">
    <div class="document-content-title-1">
       <xsl:text>Généralités</xsl:text>
    </div>
    <br />
    <xsl:apply-templates/>
  </xsl:template>

  <xsl:template match="prebody-description">
    <div class="document-content-title-theme"><span>Description</span></div>
     <br />
    <div class="document-content-text">
      <xsl:apply-templates/>
    </div>
    <br />
  </xsl:template>

  <xsl:template match="prebody-reference">
    <xsl:text>Référence: </xsl:text>
    <xsl:apply-templates/>
    <br />
  </xsl:template>

  <xsl:template match="prebody-dateeff">
    <xsl:text>Date d'effet: </xsl:text>
    <xsl:apply-templates/>
    <br />
  </xsl:template>

  <xsl:template match="prebody-indice">
    <xsl:text>Indice de classement: </xsl:text>
    <xsl:apply-templates/>
    <br />
  </xsl:template>

  <xsl:template match="prebody-codesics">
    <xsl:text>Code ICS: </xsl:text>
    <xsl:apply-templates/>
    <br />
  </xsl:template>

   <xsl:template match="prebody-titre2">
    <xsl:text>Titre 2: </xsl:text>
    <xsl:apply-templates/>
    <br />
  </xsl:template>

  <xsl:template match="prebody-titre3">
    <xsl:text>Titre 3: </xsl:text>
    <xsl:apply-templates/>
    <br />
  </xsl:template>

  <xsl:template match="prebody-titreen">
    <xsl:text>E: </xsl:text>
    <xsl:apply-templates/>
    <br />
  </xsl:template>

  <xsl:template match="prebody-titrege">
    <xsl:text>D: </xsl:text>
    <xsl:apply-templates/>
    <br />
  </xsl:template>


  <xsl:template match="prebody-statut">
    <div class="document-content-title-3">Statut</div>
    <div class="document-content-text">
      <xsl:apply-templates/>
    </div>
    <br />
  </xsl:template>

  <xsl:template match="prebody-corres">
    <div class="document-content-title-3">Correspondance</div>
    <div class="document-content-text">
      <xsl:apply-templates/>
    </div>
    <br />
  </xsl:template>

  <xsl:template match="prebody-descripteurs">
    <div class="document-content-title-3">Descripteurs</div>
    <div class="document-content-text document-list document-list-content document-list-content-1">
      <ul>
      <xsl:apply-templates/>
      </ul>
    </div>
    <br />
  </xsl:template>

  <xsl:template match="descripteur[ancestor::prebody-descripteurs]">
    <li>
      <xsl:apply-templates/>
    </li>
  </xsl:template>

  <xsl:template match="prebody-modifications">
    <div class="document-content-title-3">Modifications</div>
    <div class="document-content-text">
      <xsl:apply-templates/>
    </div>
    <br />
  </xsl:template>

  <xsl:template match="prebody-corrections">
    <div class="document-content-title-3">Corrections</div>
    <div class="document-content-text">
      <xsl:apply-templates/>
    </div>
    <br />
  </xsl:template>

  <xsl:template match="prebody-commission">
    <div class="document-content-title-3">Commission</div>
    <div class="document-content-text">
      <xsl:apply-templates/>
    </div>
    <br />
  </xsl:template>

  <xsl:template match="prebody-avtpropnat">
    <div class="document-content-title-3">Avant-propos national</div>
    <div class="document-content-text">
      <xsl:apply-templates/>
    </div>
    <br />
  </xsl:template>


  <xsl:template match="prebody-ptitreen">
    <div class="document-content-title-3">Description EN</div>
    <div class="document-content-text">
      <xsl:apply-templates/>
    </div>
    <br />
  </xsl:template>

  <xsl:template match="reference[ancestor::prebody-ptitreen]">
    <xsl:text>Référence: </xsl:text>
    <xsl:apply-templates/>
    <br />
  </xsl:template>

  <xsl:template match="dateeff[ancestor::prebody-ptitreen]">
    <xsl:text>Date d'effet: </xsl:text>
    <xsl:value-of select="php:function('_batire_xml_parse_xslt_xml_date', ., 'F Y')" />
    <br />
  </xsl:template>

  <xsl:template match="ics[ancestor::prebody-ptitreen]">
    <xsl:text>Ics: </xsl:text>
    <xsl:apply-templates/>
    <br />
  </xsl:template>

  <xsl:template match="remplace[ancestor::prebody-ptitreen]">
    <xsl:apply-templates/>
    <br />
  </xsl:template>

  <xsl:template match="prebody-avtpropen">
    <div class="document-content-title-3">Avant-propos</div>
    <div class="document-content-text">
      <xsl:apply-templates/>
    </div>
    <br />
  </xsl:template>

  <xsl:template match="president">
    <div class="document-content-text">
    <xsl:text>Président: </xsl:text>
    <xsl:apply-templates/>
    </div>

  </xsl:template>

  <xsl:template match="secretariat">
    <div class="document-content-text">
    <xsl:text>Secrétariat: </xsl:text>
    <xsl:apply-templates/>
    </div>

  </xsl:template>

  <xsl:template match="prebody-commission/titrec">
    <xsl:apply-templates/>
    <br />
  </xsl:template>

 <xsl:template match="prebody-commission/bureauc | prebody-commission/numeroc">
    <xsl:apply-templates/>
  </xsl:template>

 <xsl:template match="prebody-commission/comm/membre">
   <div class="document-content-text">
    <xsl:apply-templates/>
    </div>

 </xsl:template>

 <xsl:template match="prebody-commission/comm/membre/sexe">
   <xsl:apply-templates/>
   <xsl:text> </xsl:text>
 </xsl:template>

 <xsl:template match="prebody-commission/comm/membre/societe">
   <xsl:text> - </xsl:text>
   <xsl:apply-templates/>
 </xsl:template>

  <!-- /Prebody document -->

  <!-- Footnotes -->

  <xsl:template match="NOTEBP" priority="10">
    <xsl:variable name="notes" select="//NOTEBP" />
    <a class="more">
      <xsl:attribute name="href">
        <xsl:text>#</xsl:text>
        <xsl:value-of select="@ID|@id|@Id" />
      </xsl:attribute>
      <sup>
      <xsl:text>(</xsl:text>
      <xsl:value-of select="count($notes[@ID = current()/@ID]/preceding::NOTEBP) + 1" />
      <xsl:text>)</xsl:text>
      </sup>
    </a>

  </xsl:template>

  <xsl:template name="footnote">
    <xsl:if test="count(//NOTEBP) > 0">
      <div class="document-content-text document-content-text-notes document-content-text-notes-small">
        <xsl:for-each select="//NOTEBP">
          <a>
            <xsl:attribute name="name">
              <xsl:value-of select="@ID|@id|@Id" />
            </xsl:attribute>
          </a>
          <xsl:apply-templates select="*[position() = 1]">
            <xsl:with-param name="para_prefix">
              <xsl:text>(</xsl:text>
              <xsl:number value="position()" format="1" />
              <xsl:text>) </xsl:text>
            </xsl:with-param>
            <xsl:with-param name="disable_auto_br" select="1"/>
          </xsl:apply-templates>
          <xsl:apply-templates select="*[position() > 1]">
            <xsl:with-param name="disable_auto_br" select="1"/>
          </xsl:apply-templates>
        </xsl:for-each>
      </div>
    </xsl:if>
  </xsl:template>

 <xsl:template match="TXTNOTE/PARA | tabnote/para">
    <xsl:param name="para_prefix" />
    <xsl:param name="disable_auto_br" select="0" />
    <p>
      <xsl:value-of select="$para_prefix"/>
      <xsl:apply-templates />
    </p>
    <xsl:if test="$disable_auto_br = 0">
      <xsl:call-template name="auto_br"/>
    </xsl:if>
  </xsl:template>


  <!-- /Footnotes -->

<xsl:template match="CMT/TITRE">
  <div class="document-content-text-title-1">
    <xsl:apply-templates />
  </div>
</xsl:template>

<xsl:template match="CMT">
  <div class="document-content-text document-content-text-incises">
    <xsl:if test="not(./TITRE)">
      <div class="document-content-text-title-1">Commentaire</div>
    </xsl:if>
    <xsl:apply-templates />
  </div>
  <xsl:call-template name="auto_br" />
</xsl:template>

<xsl:template match="RMQ/TITRE">
  <div class="document-content-text-title-1">
    <xsl:apply-templates />
  </div>
</xsl:template>

<xsl:template match="RMQ">
  <div class="document-content-text document-content-text-incises">
    <xsl:apply-templates />
  </div>
</xsl:template>

<xsl:template match="PDVSOC">
  <div class="document-content-text document-content-text-incises">
    <div class="document-content-text-title-1">Point de vue Socotec</div>
    <xsl:apply-templates />
  </div>
</xsl:template>

<xsl:template match="CMTQR">
  <div class="document-content-text document-content-text-incises">
    <div class="document-content-text-title-1">Questions / Réponses</div>
    <xsl:apply-templates />
  </div>
</xsl:template>

<xsl:template match="JURISP">
  <div class="document-content-text document-content-text-incises">
    <div class="document-content-text-title-1">Jurisprudence</div>
    <xsl:apply-templates />
  </div>
</xsl:template>

<xsl:template match="REPMIN">
  <div class="document-content-text document-content-text-incises">
    <div class="document-content-text-title-1">Réponse ministérielle</div>
    <xsl:apply-templates />
  </div>
</xsl:template>

  <xsl:template match="DIAG">
    <br />
    <div class="document-content-text">
      <div class="document-content-title-1">DIAGNOSTIC</div>
      <br />
      <xsl:apply-templates />
    </div>
  </xsl:template>

  <xsl:template match="TRAIT">
    <br />
    <div class="document-content-text">
      <div class="document-content-title-1">TRAITEMENT</div>
      <br />
      <xsl:apply-templates />
    </div>
  </xsl:template>

  <xsl:template match="CSEXP">
    <br />
    <div class="document-content-text">
      <div class="document-content-title-1">CONSEIL D'EXPERT</div>
      <br />
      <xsl:apply-templates />
    </div>
  </xsl:template>
<!-- /Special elements -->


<!-- Blocks -->


  <xsl:template match="BLOC" priority="10">
    <div class="document-content-text document-content-text-incises">
      <div class="document-content-text-title-1">
        <xsl:choose>
          <xsl:when test="@Type='ENCRETENIR'">A RETENIR</xsl:when>
          <xsl:when test="@Type='ENCREPERE'">REPERE</xsl:when>
          <xsl:when test="@Type='TXTOFF'">Texte officiel</xsl:when>
          <xsl:when test="@Type='NORME'">Norme</xsl:when>
          <xsl:when test="@Type='REMARQUE'">Remarque</xsl:when>
          <xsl:when test="@Type='REMARQUES'">Remarques</xsl:when>
          <xsl:when test="@Type='BIBLIO'">Bibliographie</xsl:when>
          <xsl:when test="@Type='EXEMPLE'">Exemple</xsl:when>
          <xsl:when test="@Type='REFCE'">Référence</xsl:when>
          <xsl:when test="@Type='REFCES'">Références</xsl:when>
          <xsl:when test="@Type='DOCU'">Documentation</xsl:when>
          <xsl:when test="@Type='DTU'">DTU</xsl:when>
          <xsl:when test="@Type='REFCESOUTILS'">Références et outils</xsl:when>
          <xsl:when test="@Type='ENCADRE'"></xsl:when>
          <xsl:when test="@Type='APPLICATIONS'">Applications</xsl:when>
          <xsl:when test="@Type='APPLICATION'">Application</xsl:when>
          <xsl:when test="@Type='ARETENIR'">À retenir</xsl:when>
          <xsl:when test="@Type='ENCSAVOIR'">Le savez-vous ?</xsl:when>
          <xsl:when test="@Type='ENCMATH'">Pour les forts en maths</xsl:when>
          <xsl:when test="@Type='REMIMP'">Remarque importante</xsl:when>
          <xsl:when test="@Type='REMSIMPS'">Remarques importantes</xsl:when>
          <xsl:when test="@Type='NOTA'">Nota</xsl:when>
          <xsl:when test="@Type='EXEMPLE'">Exemple</xsl:when>
          <xsl:when test="@Type='EXEMPLES'">Exemples</xsl:when>
          <xsl:when test="@Type='IMP'">Important</xsl:when>
          <xsl:when test="@Type='RECOM'">Recommandation</xsl:when>
          <xsl:when test="@Type='TXTOFF'">Texte officiel</xsl:when>
          <xsl:when test="@Type='TXTOFFS'">Textes officiels</xsl:when>
          <xsl:when test="@Type='DOCU'">Documentation</xsl:when>
          <xsl:when test="@Type='AVERT'">Avertissement au lecteur / Avertissement</xsl:when>
          <xsl:when test="@Type='COMMENTAIRES'">Commentaires</xsl:when>
          <xsl:when test="@Type='COMMENTAIRE'">Commentaire</xsl:when>
          <xsl:when test="@Type='RAPPEL'">Rappel</xsl:when>
          <xsl:when test="@Type='INTERNET'">Site internet</xsl:when>
          <xsl:when test="@Type='NORME'">Norme</xsl:when>
          <xsl:when test="@Type='NORMES'">Normes</xsl:when>
          <xsl:when test="@Type='CONSEIL'">Conseil</xsl:when>
          <xsl:when test="@Type='CONSEILS'">Conseils</xsl:when>
          <xsl:when test="@Type='CITATION'">Citation</xsl:when>
          <xsl:when test="@Type='CITATIONS'">Citations</xsl:when>
          <xsl:when test="@Type='ETUDECAS'">Étude de cas</xsl:when>
          <xsl:when test="@Type='CONSEILP'">Conseil pratique</xsl:when>
          <xsl:when test="@Type='CONSEILPS'">Conseils pratiques</xsl:when>
          <xsl:when test="@Type='SAVOIR'">Le saviez-vous?</xsl:when>
          <xsl:otherwise>Observation</xsl:otherwise>
        </xsl:choose>
      </div>
      <xsl:if test="TITRE">
        <xsl:apply-templates select="TITRE">
          <xsl:with-param name="titleLevel" select="4"/>
        </xsl:apply-templates>
      </xsl:if>
      <xsl:apply-templates select="TEXTEBLOC/* | ENTBLOC/TEXTEBLOC/*">
        <xsl:with-param name="titleLevel" select="3"/>
      </xsl:apply-templates>
    </div>
    <xsl:call-template name="auto_br"/>
  </xsl:template>


  <xsl:variable name="doc_type" select="php:function('_batire_xml_parse_xslt_get_doc_type')" />
  <xsl:template match="TXTOFF">
    <xsl:param name="titleLevel" select="1"/>
    <xsl:choose>
      <xsl:when test="$doc_type='FM'">
        <div class="document-content-text document-content-text-incises">
          <xsl:if test="TITRE">
            <div class="document-content-text-title-1">
              <xsl:value-of select="TITRE"/>
            </div>
            <xsl:apply-templates select="*[not(name()='TITRE')]" />
          </xsl:if>
        </div>
      </xsl:when>
      <xsl:otherwise>
        <div class="document-content-text">
          <xsl:if test="@align">
            <xsl:attribute name="align">
              <xsl:value-of select="@align" />
            </xsl:attribute>
          </xsl:if>
          <xsl:for-each select="*">
            <xsl:apply-templates select=".">
              <xsl:with-param name="titleLevel" select="$titleLevel" />
            </xsl:apply-templates>
          </xsl:for-each>
        </div>
        <xsl:call-template name="auto_br"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>


  <xsl:template match="tp/contenu">
    <div class="document-content-text document-content-text-notes document-content-text-notes-small">
      <xsl:apply-templates />
    </div>
  </xsl:template>

  <xsl:template match="tp/contenu/para">
    <p>
      <xsl:apply-templates />
    </p>
  </xsl:template>

  <xsl:template match="PARA | p | para | bl | ENTCHRONO">
    <xsl:param name="para_prefix" />
    <xsl:param name="disable_auto_br" select="0" />
    <div class="document-content-text">
      <xsl:attribute name="class">
        <xsl:text>document-content-text</xsl:text>
        <xsl:if test="@align|@Align and parent::*[name() != 'ENTRY']">
          <xsl:text> </xsl:text>
          <xsl:text>document-text-</xsl:text>
          <xsl:value-of select="string(@align|@Align)"/>
        </xsl:if>
      </xsl:attribute>
      <xsl:variable name="current_id" select="generate-id(.)"/>
      <xsl:choose>
        <xsl:when test="parent::*[@gtext and generate-id(*[position() = 1]) = $current_id and name() != 'li' and name() != 'LI']">
          <b>
            <br />
            <xsl:value-of select="parent::*/@gtext"/>
            <xsl:text> </xsl:text>
          </b>
        </xsl:when>
        <xsl:when  test="parent::*/parent::*/parent::*[@gtext and generate-id(./*[position() = 1]/*[position() = 1]/*[position() = 1]) = $current_id and name() != 'figrp' and name() != 'fig']" >
          <b>
            <br />
            <xsl:value-of select="parent::*/parent::*/parent::*/@gtext" />
            <xsl:text> </xsl:text>
          </b>
        </xsl:when>
      </xsl:choose>
      <!-- <xsl:if test="substring(parent::ARTOFF/@ID, 1, 3) = 'SIN' and not(preceding-sibling::TITRE) and not(preceding-sibling::PARA)">
        <span class="document-content-title-10">
          <xsl:choose>
            <xsl:when test="parent::ARTOFF[@Type='annexe']"><xsl:text>Annexe </xsl:text></xsl:when>
            <xsl:otherwise><xsl:text>Art. </xsl:text></xsl:otherwise>
          </xsl:choose>
          <xsl:apply-templates mode="no_following_title" select="preceding-sibling::NUMERO"/>
          <xsl:text> - </xsl:text>
        </span>
      </xsl:if> -->
      <xsl:if test="$para_prefix">
        <b>
          <xsl:value-of select="$para_prefix"/>
        </b>
      </xsl:if>
      <xsl:apply-templates/>
    </div>
    <xsl:if test="substring(parent::ARTOFF/@ID, 1, 3) = 'SIN' and not(preceding-sibling::TITRE) and not(following-sibling::PARA)">
      <br/>
    </xsl:if>
    <xsl:if test="$disable_auto_br = 0">
      <xsl:call-template name="auto_br"/>
    </xsl:if>
  </xsl:template>

  <xsl:template match="nota/contenu">
    <div class="document-content-text document-content-text-incises">
      <div class="document-content-text-title-1">Nota</div>
      <xsl:apply-templates/>
    </div>
    <br/>
  </xsl:template>

    <xsl:template match="OBSERVATION">
      <xsl:param name="titleLevel" select="1" />
      <div class="document-content-text document-content-text-incises">
        <xsl:if test="@Type">
          <div class="document-content-text-title-1 uppercased-text">
            <xsl:choose>
              <xsl:when test="@Type='Imp'">Important</xsl:when>
              <xsl:when test="@Type='Rem'">Remarque</xsl:when>
              <xsl:when test="@Type='Rems' or @Type='rems'">Remarques</xsl:when>
              <xsl:when test="@Type='RemPre'">Remarque préliminaire</xsl:when>
              <xsl:when test="@Type='RemsPres'">Remarques préliminaires</xsl:when>
              <xsl:when test="@Type='Com'">Commentaire</xsl:when>
              <xsl:when test="@Type='Coms'">Commentaires</xsl:when>
              <xsl:when test="@Type='Reg'">Réglementation</xsl:when>
              <xsl:when test="@Type='Doc'">Documentation</xsl:when>
              <xsl:when test="@Type='Site'">Site internet</xsl:when>
              <xsl:when test="@Type='Sites'">Sites internet</xsl:when>
              <xsl:when test="@Type='Exem'">Exemple</xsl:when>
              <xsl:when test="@Type='Exems'">Exemples</xsl:when>
              <xsl:when test="@Type='ConsP'">Conseil pratique</xsl:when>
              <xsl:when test="@Type='ConsPs'">Conseils pratiques</xsl:when>
              <xsl:when test="@Type='Recom'">Recommandation</xsl:when>
              <xsl:when test="@Type='Recoms'">Recommandations</xsl:when>
              <xsl:when test="@Type='Interv'">Intervenants</xsl:when>
              <xsl:when test="@Type='Ref' or @Type='Refce' or @Type='Refde'">Référence</xsl:when>
              <xsl:when test="@Type='Refs' or @Type='Refces'">Références</xsl:when>
              <xsl:when test="@Type='Txtoff'">Texte officiel</xsl:when>
              <xsl:when test="@Type='Txtoffs'">Texte officiels</xsl:when>
              <xsl:when test="@Type='Savoir'">Pour en savoir plus</xsl:when>
              <xsl:when test="@Type='Important'">Important</xsl:when>
              <xsl:when test="@Type='Essentiel'">L’essentiel</xsl:when>
              <xsl:otherwise>Unknown observation type: <xsl:value-of select="@Type"/></xsl:otherwise>
            </xsl:choose>
          </div>
        </xsl:if>
        <xsl:apply-templates>
          <xsl:with-param name="titleLevel" select="2" />
        </xsl:apply-templates>
      </div>
      <xsl:call-template name="auto_br"/>
    </xsl:template>



    <xsl:template  match="NOTE | tabnote">
      <xsl:call-template name="anchor" />
      <div class="document-image-no-zoom">
        <div>
          <xsl:attribute name="class">
            <xsl:text>document-image-info</xsl:text>
            <xsl:choose>
            <xsl:when test="name() = 'tabnote' and tab/@align">
              <xsl:text> document-text-</xsl:text>
              <xsl:value-of select="tab/@align"/>
            </xsl:when>
            <xsl:otherwise>
              <xsl:text> document-text-left</xsl:text>
            </xsl:otherwise>
            </xsl:choose>
          </xsl:attribute>
          <xsl:apply-templates />
        </div>
      </div>
    </xsl:template>

    <xsl:template match="REFART">
      <xsl:if test="not(ancestor::FICHE-DETAIL) and not(ancestor::FICHE-DROIT) and not(ancestor::FICHE-ARTICLE) and not(ancestor::FICHE-DESORDRE) and not(ancestor::FICHE-INCENDIE) and not(ancestor::FICHE-NORME) and not(ancestor::FICHE-EQUIPEMENT)">
        <span class="notice-text">
          <xsl:apply-templates />
        </span>
        <br/>
        <br/><!-- we need here two times because inline span used -->
      </xsl:if>
    </xsl:template>

<xsl:template match="ENTBIB">
  <div class="document-content-text">
    <xsl:apply-templates />
  </div>
  <xsl:call-template name="auto_br"/>
</xsl:template>

<xsl:template match="textblock/note">
  <xsl:choose>
    <xsl:when test="ancestor::fig">
      <div class="document-image-info">
      <xsl:text>NOTE </xsl:text>
      <xsl:apply-templates />
      </div>
    </xsl:when>
    <xsl:otherwise>
  <div class="document-content-text">
    <div class="note">
    <xsl:text>NOTE </xsl:text>
    <xsl:apply-templates />
    </div>
  </div>
  </xsl:otherwise>
  </xsl:choose>
</xsl:template>


  <!-- Just containers -->
  <xsl:template match="INTRO | NIV1 | NIV2 | NIV3 | NIV4 | NIV5 | NIV6 | NIV7 | PUCENOIRE | PUCEBLANCHE | TXTFM | multi_textblock | textblock |  TEXTEB | *[TITRE and name() != 'TXTOFF' and name() != 'TABLEAU' and name() != 'ENTCHRONO' and name() != 'p' and name() != 'RMQ' and name() != 'CMT'] | *[multi_ht] | CHAPEAU | TXTCD | FICHEREF">
    <xsl:param name="disable_title_auto_br" select="0"/>
    <xsl:param name="titleLevel" select="0"/>
    <xsl:param name="titlePrefix"/>
    <xsl:param name="para_prefix" />
    <xsl:call-template name="anchor"/>
    <xsl:apply-templates>
      <xsl:with-param name="disable_title_auto_br" select="$disable_title_auto_br" />
      <xsl:with-param name="titleLevel">
        <xsl:choose>
          <xsl:when test="$TYPE-CT and (name() = 'NIV1' or name() ='NIV2' or name() ='NIV3' or name() ='NIV4')">
            <xsl:value-of select="substring(name(),string-length(name()))"/>
          </xsl:when>
          <xsl:when test="$TYPE-CT and name() ='NIV5'">
            <xsl:text>6</xsl:text>
          </xsl:when>
          <xsl:when test="name() = 'NIVSYNT'">
            <xsl:value-of select="substring(@Style, 4, 1)"/>
          </xsl:when>
          <xsl:otherwise>
            <xsl:value-of select="$titleLevel + 1"/>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:with-param>
      <xsl:with-param name="titlePrefix">
        <xsl:choose>
          <xsl:when test="../CARTOUCHE">
            <xsl:if test="not(substring(parent::*/@ID, 1, 3) = 'SIN')">
              <xsl:value-of select="../CARTOUCHE/NUMERO"/>
              <xsl:text>.</xsl:text>
              <xsl:value-of select="count(preceding-sibling::*[name() = name(current())]) + 1"/>
            </xsl:if>
          </xsl:when>
          <xsl:when test="name() = 'NIV1' or name() = 'NIV2' or name() = 'NIV3' or name() = 'NIV4' or name() = 'NIV5' or name() = 'NIV6' or name() = 'NIV7'">
            <xsl:if test="$titlePrefix != ''">
              <xsl:value-of select="$titlePrefix"/>
              <xsl:text>.</xsl:text>
            </xsl:if>
            <xsl:value-of select="count(preceding-sibling::*[name() = name(current())]) + 1"/>
          </xsl:when>
          <xsl:otherwise>
            <xsl:if test="substring(parent::*/@ID, 1, 3) = 'SIN' and not(descendant::NIVSYNT)">
              <xsl:value-of select="$titlePrefix" />
            </xsl:if>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:with-param>
    </xsl:apply-templates>
    <xsl:call-template name="auto_br"/>
    <xsl:if test="name() = 'FICHEREF'">
      <xsl:call-template name="auto_br"/>
    </xsl:if>
  </xsl:template>

  <xsl:template match="NIVINTRO/TXTINTRO">
    <xsl:apply-templates/>
    <xsl:if test="following-sibling::NIVINTRO">
      <xsl:call-template name="auto_br"/>
    </xsl:if>
  </xsl:template>

  <xsl:template match="LOCALISATION">
    <xsl:choose>
      <xsl:when test="substring(parent::*/@ID, 1, 3) = 'SIN'">
        <div class="document-content-title-2 notice-text">
          <xsl:apply-templates />
        </div><br/>
      </xsl:when>
      <xsl:otherwise>
        <div class="document-content-text">
          <xsl:apply-templates />
        </div>
      </xsl:otherwise>
    </xsl:choose>
    <xsl:call-template name="auto_br"/>
  </xsl:template>


  <xsl:template match="NUMERO">
    <xsl:choose>
      <xsl:when test="substring(parent::ARTOFF/@ID, 1, 3) = 'SIN' and not(following-sibling::TITRE)">
        <span class="document-content-title-10">
          <xsl:choose>
            <xsl:when test="parent::ARTOFF[@Type='annexe']"><xsl:text>Annexe </xsl:text></xsl:when>
            <xsl:otherwise><xsl:text>Art. </xsl:text></xsl:otherwise>
          </xsl:choose>
          <xsl:apply-templates />
        </span>
      </xsl:when>
      <xsl:when test="substring(parent::ARTICLE/@ID, 1, 3) = 'SIN'">
        <div class="document-content-text">
          <span class="notice-text notice-text-blue">
            <xsl:text>Art. </xsl:text>
            <xsl:apply-templates />
          </span>
        </div>
        <xsl:call-template name="auto_br"/>
      </xsl:when>
      <xsl:otherwise>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="NUMERO" mode="no_following_title">
    <xsl:if test="substring(parent::ARTOFF/@ID, 1, 3) = 'SIN' and not(following-sibling::TITRE)">
      <xsl:apply-templates />
    </xsl:if>
  </xsl:template>

  <xsl:template match="NUMERO" mode="for_sin">
    <xsl:if test="substring(parent::ARTOFF/@ID, 1, 3) = 'SIN'">
      <xsl:apply-templates />
    </xsl:if>
  </xsl:template>

  <xsl:template match="MTYPE">
    <div class="notice-alert-text">
      <xsl:apply-templates />
    </div>
    <br/>
  </xsl:template>

  <xsl:template match="CARTOUCHEFG">
    <div class="document-content-title-5 uppercased-text">
      <xsl:apply-templates select="PARTIEFGREF | PARTIEFGTITRE"/>
    </div>
    <br/>
    <div class="document-content-title-4 uppercased-text">
      <xsl:apply-templates select="SOUSPARTIEFGREF | SOUSPARTIEFGTITRE"/>
    </div>
    <br/>
    <div class="document-content-title-1 uppercased-text">
      <xsl:apply-templates select="FICHEFGREF | FICHEFGTITRE"/>
    </div>
    <br/>
  </xsl:template>

  <xsl:template match="PARTIEFGREF | SOUSPARTIEFGREF">
    <xsl:apply-templates/>
    <xsl:text> </xsl:text>
  </xsl:template>

  <xsl:template match="PARTIEFGTITRE | SOUSPARTIEFGTITRE | FICHEFGTITRE">
    <xsl:apply-templates/>
  </xsl:template>

  <xsl:template match="FICHEFGREF">
    <span class="notice-text notice-text-blue">
      <xsl:apply-templates/>
    </span>
    <xsl:text> </xsl:text>
  </xsl:template>

  <xsl:template match="DETAILFIG | TERME">
    <xsl:if test="@Numero">
      <b>(<xsl:value-of select="@Numero"/>) </b>
    </xsl:if>
    <xsl:apply-templates/>
    <br/>
  </xsl:template>

  <xsl:template match="ARTOFF">
    <a>
      <xsl:attribute name="name">
        <xsl:value-of select="@ID"/>
      </xsl:attribute>
    </a>
    <xsl:apply-templates/>
  </xsl:template>

  <!-- /Just containers -->

  <!-- TN blocks -->

  <!-- /TN Blocks -->

<!-- /Blocks -->


<!-- Headers -->

  <xsl:template match="NIVINTB/TITRE">
    <xsl:param name="titleLevel" select="2"/>
    <xsl:param name="titlePrefix"/>
    <xsl:if test="$titleLevel = 1">
      <br/>
    </xsl:if>
    <div>
      <xsl:attribute name="class">
        <xsl:choose>
          <xsl:when test="name() = 'titre2fr'">
            <xsl:value-of select="concat('document-content-title-', $titleLevel + 1)"/>
          </xsl:when>
          <xsl:otherwise>
            <xsl:value-of select="concat('document-content-title-', $titleLevel)"/>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:attribute>
      <a>
      <xsl:attribute name="name">
        <xsl:value-of select="ancestor::NIVINTB[0]/@ID"/>
      </xsl:attribute>
      </a>
      <xsl:if test="php:function('_batire_xml_parse_xslt_get_livre_type_ud') != 'FICHEB'">
        <xsl:if test="count(ancestor::NIVINTB[@ID]) &lt; 3">
          <xsl:value-of select="ancestor::*/@pretitle"/>
          <xsl:for-each select="parent::NIVINTB/@ID">
            <xsl:choose>
              <xsl:when test="substring-after(.,'-N') = ''">
                <xsl:call-template name="parse-title-number">
                  <xsl:with-param name="data" select="substring(substring-after(.,'N'),3)"/>
                </xsl:call-template>
              </xsl:when>
              <xsl:otherwise>
                <xsl:call-template name="parse-title-number">
                  <xsl:with-param name="data" select="substring(substring-after(.,'-N'),3)"/>
                </xsl:call-template>
              </xsl:otherwise>
            </xsl:choose>
          </xsl:for-each>
          <xsl:text> </xsl:text>
        </xsl:if>
      </xsl:if>
      <xsl:apply-templates />
    </div>
    <xsl:call-template name="auto_br"/>
  </xsl:template>


    <xsl:template match="TITRE | multi_ht | tableau/titre | table/tabtit | titre1fr | titre2fr">
      <xsl:param name="disable_title_auto_br" select="0"/>
      <xsl:param name="titleLevel" select="2"/>
      <xsl:param name="titlePrefix"/>
      <xsl:if test="$titleLevel = 1">
        <br/>
      </xsl:if>
      <div>
        <xsl:attribute name="class">
          <xsl:choose>
            <xsl:when test="name() = 'titre2fr'"><xsl:value-of select="concat('document-content-title-', $titleLevel + 1)"/></xsl:when>
            <xsl:when test="substring(parent::ARTOFF/@ID, 1, 3) = 'SIN' and preceding-sibling::NUMERO[1]">
              <xsl:text>document-content-title-10</xsl:text>
            </xsl:when>
            <xsl:when test="parent::NIVFART[@Style = 'fart1']"><xsl:text>document-content-title-10 notice-text</xsl:text></xsl:when>
            <xsl:otherwise><xsl:value-of select="concat('document-content-title-', $titleLevel)"/></xsl:otherwise>
          </xsl:choose>
        </xsl:attribute>
        <xsl:choose>
          <xsl:when test="name() = 'multi_ht'">
            <xsl:value-of select="../@gtext" disable-output-escaping="yes"/>
            <xsl:value-of select="$space"/>
            <xsl:apply-templates />
          </xsl:when>
          <xsl:when test="name() = 'tabtit'">
            <xsl:text>Tableau </xsl:text>
            <xsl:value-of select="../@gtext" disable-output-escaping="yes"/>
            <xsl:value-of select="$space"/>
            <xsl:text>–</xsl:text>
            <xsl:value-of select="$space"/>
            <xsl:value-of select="."/>
          </xsl:when>
          <xsl:otherwise>
            <!-- removing by client`s request: https://prj.adyax.com/issues/36726#change-211917
            <xsl:if test="$titlePrefix">
              <xsl:value-of select="$titlePrefix"/>
              <xsl:value-of select="$space"/>
            </xsl:if>-->
            <xsl:choose>
              <xsl:when test="substring(ancestor::*/@ID, 1, 3) = 'NRK' or substring(ancestor::*/@ID, 1, 3) = 'BON'">
                <xsl:choose>
                  <xsl:when test="parent::NIV1">
                    <xsl:if test="../../CARTOUCHE">
                      <xsl:value-of select="../../CARTOUCHE/NUMERO"/>
                      <xsl:text>.</xsl:text>
                    </xsl:if>
                    <xsl:value-of select="php:function('_batire_xml_parse_xslt_fm_nivid', .)"/>
                    <xsl:text> </xsl:text>
                  </xsl:when>
                  <xsl:when test="parent::NIV2">
                    <xsl:value-of select="php:function('_batire_xml_parse_xslt_fm_nivid', .)"/>
                    <xsl:text>. </xsl:text>
                  </xsl:when>
                </xsl:choose>
              </xsl:when>
              <xsl:when test="substring(ancestor::*/@ID, 1, 3) = 'VER' or (substring(ancestor::*/@ID, 1, 3) = 'SOC' and not(//FICHEPATHO))">
                <xsl:if test="parent::NIV1">
                  <xsl:value-of select="php:function('_batire_xml_parse_xslt_fm_nivid', .)"/>
                  <xsl:text>. </xsl:text>
                </xsl:if>
              </xsl:when>
              <xsl:when test="substring(parent::ARTOFF/@ID, 1, 3) = 'SIN'">
                <xsl:value-of select="php:function('_batire_xml_parse_xslt_storage', 'RESET', 'sub_type')" />
                <xsl:choose>
                  <xsl:when test="parent::ARTOFF[@Type='annexe']"><xsl:text>Annexe </xsl:text></xsl:when>
                  <xsl:otherwise><xsl:text>Art. </xsl:text></xsl:otherwise>
                </xsl:choose>
                <xsl:apply-templates mode="for_sin" select="parent::ARTOFF/NUMERO" />
                <xsl:text> - </xsl:text>
              </xsl:when>
              <xsl:when test="$TYPE-CT and not(parent::NIV4) and not(parent::NIV5)">
                <xsl:if test="$titlePrefix">
                  <xsl:value-of select="$titlePrefix"/>
                  <xsl:if test="parent::NIV1">
                    <xsl:text>.</xsl:text>
                  </xsl:if>
                  <xsl:value-of select="$space"/>
                </xsl:if>
              </xsl:when>
            </xsl:choose>
            <xsl:apply-templates />
          </xsl:otherwise>
        </xsl:choose>
      </div>
      <xsl:if test="parent::NIVFART[@Style = 'fart1']">
        <br/>
      </xsl:if>
      <xsl:if test="$disable_title_auto_br = 0">
        <xsl:call-template name="auto_br"/>
      </xsl:if>
    </xsl:template>

  <xsl:template match="contenu1/intertitre[@niveau] | contenu2/intertitre[@niveau]">
    <div>
      <xsl:attribute name="class">
        <xsl:value-of select="concat('document-content-title-', @niveau)"/>
      </xsl:attribute>
      <xsl:value-of select="." disable-output-escaping="yes"/>
    </div>
    <xsl:call-template name="auto_br"/>
  </xsl:template>


  <xsl:template match="encadre">
    <br />
    <div class="document-wrapper-block">
      <div class="block-bg">
        <div class="block-bg">
          <xsl:apply-templates />
        </div>
      </div>
    </div>
  </xsl:template>

  <xsl:template match="ddr_reference_block">
    <br />
      <div class="document-wrapper-block">
        <div class="block-bg">
          <div class="block-bg">
              <xsl:call-template name="ddr_list"/>
          </div>
        </div>
      </div>
  </xsl:template>

  <xsl:template name="ddr_list">
    <div class="ddr-list">
        <ul>
        <xsl:for-each select="//ddr_reference_block/ul/li">
          <li>
              <xsl:apply-templates />
          </li>
        </xsl:for-each>
      </ul>
    </div>
      <span class="ddr-signaler-link">
        <a class="ddr-signaler-link-popup">
          <xsl:value-of select="//ddr_signaler_link"/>
        </a>
      </span>
  </xsl:template>

  <xsl:template match="encadre/titre">
    <div class="document-content-title-2">
      <xsl:value-of select="." disable-output-escaping="yes"/>
    </div>
    <xsl:call-template name="auto_br"/>
  </xsl:template>


<!-- /Headers -->

<!-- Lists -->
  <xsl:template match="LIST[@Type]|LIST[@TYPE]|LISTE[@Type]|LISTE[@TYPE]|list[@type]|ul|UL">
    <xsl:param name="disable_auto_br" select="0" />
    <div class="document-list document-list-content document-list-content-1">
      <xsl:attribute name="class">
        <xsl:text>document-list document-list-content </xsl:text>
        <xsl:choose>
          <xsl:when test="@Type = 'carre' or @TYPE = 'carre' or @Type='carr&#xE9;' or @TYPE='carr&#xE9;'">document-list-content-7</xsl:when>
          <xsl:when test="@Type = 'titret' or @TYPE = 'titret' or @Type = 'tiret' or @type = 'tiret' or @TYPE = 'tiret' or @format='emdash'">document-list-content-4</xsl:when>
          <xsl:when test="@Type = 'tiretc' or @TYPE = 'tiretc'">document-list-content-9</xsl:when>
          <xsl:when test="@Type = 'numpar' or @TYPE = 'numpar' or @Type='nump' or @TYPE='nump'"></xsl:when>
          <xsl:when test="@type = 'numpar'">document-list-content-10</xsl:when>
          <xsl:otherwise>document-list-content-1</xsl:otherwise>
        </xsl:choose>
      </xsl:attribute>
      <xsl:choose>
        <xsl:when test="@Type = 'numpar' or @TYPE = 'numpar' or @Type='nump' or @TYPE='nump'">
          <xsl:for-each select="ITEM|IT|it|EL|LIST|LISTE">
            <xsl:choose>
              <xsl:when test="name() = 'LIST'">
                <xsl:apply-templates select=".">
                  <xsl:with-param name="disable_auto_br" select="1"/>
                </xsl:apply-templates>
              </xsl:when>
              <xsl:otherwise>
                <div class="document-content-text">
                  <xsl:text> </xsl:text>
                  <xsl:apply-templates select="PARA[1]">
                    <xsl:with-param name="para_prefix">
                      <xsl:choose>
                        <xsl:when test="@Numero">
                          <xsl:value-of select="@Numero"/>)
                        </xsl:when>
                        <xsl:otherwise>
                          <xsl:value-of select="position()"/>)
                        </xsl:otherwise>
                      </xsl:choose>
                    </xsl:with-param>
                  </xsl:apply-templates>
                  <!-- <xsl:apply-templates select="PARA[position() != 1]" /> -->
                  <!-- <xsl:apply-templates select="*[not(name()='PARA')]" /> -->
                  <xsl:apply-templates select="*[position() != 1]" />
                </div>
              </xsl:otherwise>
            </xsl:choose>
          </xsl:for-each>
        </xsl:when>
        <xsl:when test="@Type = 'numpoint' or @TYPE = 'numpoint' or @Type='numd' or @TYPE='numd'">
          <ol>
            <xsl:for-each select="ITEM|IT|it|EL|LIST[not(@Type)]|LISTE|LI|li">
              <li>
                <xsl:apply-templates />
                <xsl:if test="name(following-sibling::*[1]) = 'LIST'">
                  <xsl:apply-templates select="following-sibling::*[1]"/>
                </xsl:if>
              </li>
            </xsl:for-each>
          </ol>
        </xsl:when>
        <xsl:when test="@type = 'numpar'"> <!-- when type in lowercase, see task #89122 -->
          <ul>
            <xsl:for-each select="IT|it">
              <li>
                <xsl:value-of select="@numero"/>)
                <xsl:apply-templates />
                <xsl:if test="name(following-sibling::*[1]) = 'LIST'">
                  <xsl:apply-templates select="following-sibling::*[1]"/>
                </xsl:if>
                  </li>
            </xsl:for-each>
          </ul>
          <br />
        </xsl:when>
        <xsl:otherwise>
          <ul>
            <xsl:for-each select="ITEM|IT|it|EL|LIST[not(@Type)]|LISTE|LI|li">
              <li>
                <xsl:apply-templates />
                <xsl:if test="name(following-sibling::*[1]) = 'LIST'">
                  <xsl:apply-templates select="following-sibling::*[1]"/>
                </xsl:if>
              </li>
            </xsl:for-each>
          </ul>
          <br />
        </xsl:otherwise>
      </xsl:choose>
    </div>
    <xsl:if test="$disable_auto_br = 0">
      <xsl:call-template name="auto_br"/>
    </xsl:if>
  </xsl:template>

    <xsl:template match="ol|OL">
    <div class="document-list document-list-content">
      <ol>
        <xsl:attribute name="type">
          <xsl:choose>
            <xsl:when test="@format = 'alpha' or (li[1][@gtext = 'a'] or LI[1][@gtext = 'a'])">a</xsl:when>
            <xsl:otherwise>1</xsl:otherwise>
          </xsl:choose>
        </xsl:attribute>
        <xsl:for-each select="LI|li">
          <li>
            <xsl:apply-templates />
          </li>
        </xsl:for-each>
      </ol>
    </div>
  </xsl:template>

<!-- /Lists -->

<!-- Attaches -->
  <xsl:template match="EQN[@IMG]">
    <xsl:value-of select="php:function('_batire_xml_parse_xslt_storage', 'ARRAY', 'images', 'figure', string(@ID|@id|@Id), string(TITRE | @Numero), string(LEGENDE))" />
    <xsl:call-template name="anchor"/>
    <xsl:call-template name="show_picture_inline" >
      <xsl:with-param name="special" >inline</xsl:with-param>
    </xsl:call-template>
  </xsl:template>
 
 <xsl:template match="SUB" mode="serialize">
    <xsl:text>&lt;</xsl:text><xsl:value-of select="name(.)"/>
    <xsl:text>&gt;</xsl:text>
    <xsl:apply-templates mode="serialize"/>
    <xsl:text>&lt;/</xsl:text><xsl:value-of select="name(.)"/>
    <xsl:text>&gt;</xsl:text>
  </xsl:template>
   
  <xsl:template match="text()" mode="serialize">
    <xsl:value-of select="."/>
  </xsl:template>

 <xsl:template match="figure |FIGURE[@type='illustration' or @type='photo'] | FIGURECMT[@type='illustration' or @type='photo']">
   <div class="image-block">
    <xsl:value-of select="php:function('_batire_xml_parse_xslt_storage', 'ARRAY', 'images', 'figure', string(@ID|@id|@Id), string(TITRE | @Numero), string(LEGENDE))" />
    <xsl:call-template name="anchor"/>

    <xsl:choose>
      <xsl:when test="LEGENDE | TITRE | @Numero | SOURCE">
        <xsl:call-template name="show_picture"/>
        <xsl:variable name="titre_html">
          <xsl:apply-templates select="TITRE/node()" mode="serialize"/>
        </xsl:variable>
        <div class="document-image-info">
        <p>
          <xsl:choose>
            <xsl:when test="TITRE and not(@Numero)">
              <xsl:value-of select="php:function('_batire_xml_parse_xslt_get_figure_num_from_id', string(@ID), string($titre_html))"/>
              <xsl:copy-of select="TITRE/node()" />
            </xsl:when>
            <xsl:when test="TITRE">
              <xsl:copy-of select="TITRE/node()"/>
            </xsl:when>
            <xsl:otherwise>
              <xsl:value-of select="@NUMERO"/>
            </xsl:otherwise>
          </xsl:choose>
        </p>
        <xsl:apply-templates select="LEGENDE"/>
        <xsl:if test="SOURCE">
        <i>
        <xsl:apply-templates select="SOURCE"/>
        </i>
        </xsl:if>
      </div>
      </xsl:when>
      <xsl:otherwise>
        <div class="document-image-no-info">
          <xsl:call-template name="show_picture"/>
        </div>
      </xsl:otherwise>
    </xsl:choose>
  <br/>
  <xsl:call-template name="auto_br"/>
  </div>
  </xsl:template>


  <xsl:template match="artwork">
    <xsl:variable name="figure_title">
      <xsl:choose>
        <xsl:when test="ancestor::figrp/@gtext | ancestor::fig/@gtext | ancestor::fig/multi_figtit/figtit">
      <xsl:value-of select="ancestor::figrp/@gtext" />
      <xsl:text> </xsl:text>
      <xsl:value-of select="ancestor::fig/@gtext" />
      <xsl:text>) </xsl:text>
      <xsl:value-of select="ancestor::fig/multi_figtit/figtit" />
      </xsl:when>
      <xsl:otherwise></xsl:otherwise>
      </xsl:choose>
    </xsl:variable>
    <xsl:value-of select="php:function('_batire_xml_parse_xslt_storage', 'ARRAY', 'images', 'artwork', string(@name), string($figure_title))" />
    <a>
      <xsl:attribute name="name">
        <xsl:value-of select="@name"/>
      </xsl:attribute>
    </a>
    <div class="document-image-no-info">
      <xsl:call-template name="show_picture">
        <xsl:with-param name="special">
          <xsl:choose>
            <xsl:when test="name(..) = 'dformula' or name(..) = 'formula'">formula-artwork</xsl:when>
          </xsl:choose>
        </xsl:with-param>
      </xsl:call-template>
    </div>
    <xsl:call-template name="auto_br"/>
  </xsl:template>

  <xsl:template match="fmeq">
    <xsl:value-of select="php:function('_batire_xml_parse_xslt_storage', 'ARRAY', 'images', 'artwork', string(@entity))" />
    <a>
      <xsl:attribute name="name">
        <xsl:value-of select="@entity"/>
      </xsl:attribute>
    </a>
    <div class="document-image-no-info">
      <xsl:call-template name="show_picture">
        <xsl:with-param name="special">formula-artwork-nf</xsl:with-param>
      </xsl:call-template>
    </div>
    <xsl:call-template name="auto_br"/>
  </xsl:template>

  <xsl:template match="lien_objet_metier">
    <xsl:call-template name="actualite_lien_reference"/>
  </xsl:template>
<!-- /Attaches -->

<!-- Abbreviations -->
    <xsl:template match="LIENNOTION[@Type = 'abr' or @Type = 'sig']">
      <batire_abbr>
        <title>
          <xsl:value-of select="."/>
        </title>
        <id>
          <xsl:value-of select="string(@IDREF|@idref)"/>
        </id>
      </batire_abbr>
    </xsl:template>

    <xsl:template match="ENTSIG|ENTABR">
      <div class="bibliogaphie-block">
        <xsl:call-template name="anchor"/>
        <xsl:value-of select="SIG|ABR"/>
        <span>
          <xsl:apply-templates select="DEFINITION"/>
        </span>
      </div>
    </xsl:template>


<!-- /Abbreviations -->

<!-- LINKS -->

  <xsl:template match="LIENID">
    <a>
      <xsl:attribute name="href">#<xsl:value-of select="@IDREF"/></xsl:attribute>
      <xsl:apply-templates select="*|text()"/>
    </a>
  </xsl:template>


  <xsl:template match="lienent[@idref]|LIENENT[@IDREF]|LIEN|lien|WWW">
    <xsl:value-of select="php:function('_batire_xml_parse_xslt_xml_link', .)" disable-output-escaping="yes"/>
  </xsl:template>



<!-- /LINKS -->

<!-- Tables -->


  <xsl:template match="TABLEAU[@IMG and not(@IMG='')] | tableu[@IMG and not(@IMG='')]">
    <xsl:call-template name="anchor"/>
    <xsl:choose>
      <xsl:when test="LEGENDE and TITRE">
        <xsl:call-template name="show_picture"/>
        <div class="document-image-info">
          <p>
            <xsl:value-of select="TITRE"/>
          </p>
          <xsl:apply-templates select="LEGENDE"/>
        </div>
      </xsl:when>
      <xsl:otherwise>
        <xsl:call-template name="show_picture"/>
        <!-- a temporary solution below -->
        <xsl:if test="not(ancestor::FICHECMT)">
          <br/>
          <br/>
          <xsl:apply-templates>
            <xsl:with-param name="titleLevel" select="6"/>
          </xsl:apply-templates>
        </xsl:if>
        <xsl:if test="ancestor::FICHECMT">
          <xsl:apply-templates select="TITRE">
            <xsl:with-param name="titleLevel" select="6"/>
          </xsl:apply-templates>
          <xsl:call-template name="auto_br"/>
        </xsl:if>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>


  <xsl:template match="TABLEAU | tableau">
    <xsl:param name="titleLevel" select="1"/>
    <xsl:value-of select="php:function('_batire_xml_parse_xslt_storage', 'ARRAY', 'tables', string(@id|@ID|@Id), string(TITRE | titre | tabtit))" />

    <xsl:call-template name="anchor"/>
    <xsl:apply-templates select="TITRE | titre | tabtit">
      <xsl:with-param name="titleLevel" select="6"/>
    </xsl:apply-templates>

    <div class="document-table-wrapper">
      <div class="document-table-arrow document-table-arrow-top"></div>
      <div class="document-table-arrow document-table-arrow-middle"></div>
      <div class="document-table-arrow document-table-arrow-bottom"></div>
      <div class="document-table-position">
        <xsl:apply-templates select="TABLE | table"  mode="tableau-table"/>
      </div>
    </div>
    <br/>
    <xsl:call-template name="auto_br"/>
  </xsl:template>

  <xsl:template match="TABLE | table"  mode="tableau-table">
    <table class="document-table">
      <xsl:if test="@frame = 'none' and not(@tabstyle = 'eqn')">
        <xsl:attribute name="class">
          <xsl:text>document-table document-table-space</xsl:text>
        </xsl:attribute>
      </xsl:if>
      <xsl:if test="@tabstyle = 'eqn'">
        <xsl:attribute name="class">
          <xsl:text>document-table document-table-equation</xsl:text>
        </xsl:attribute>
      </xsl:if>

      <xsl:variable name="colspec" select="TGROUP/COLSPEC | tgroup/colspec"/>
      <xsl:variable name="spanspec" select="TGROUP/SPANSPEC | tgroup/spanspec"/>

      <xsl:apply-templates select="descendant::THEAD | descendant::thead">
        <xsl:with-param name="colspec" select="$colspec"/>
        <xsl:with-param name="spanspec" select="$spanspec"/>
      </xsl:apply-templates>
      <xsl:apply-templates select="descendant::TBODY | descendant::tbody">
        <xsl:with-param name="colspec" select="$colspec"/>
        <xsl:with-param name="spanspec" select="$spanspec"/>
      </xsl:apply-templates>
      <xsl:apply-templates select="descendant::TFOOT | descendant::tfoot">
        <xsl:with-param name="colspec" select="$colspec"/>
        <xsl:with-param name="spanspec" select="$spanspec"/>
      </xsl:apply-templates>

      <xsl:if test="not(TFOOT | tfoot) and (../NOTE | ../note | descendant::ROW/ENTRY/NOTE)">
        <tr class="tfoot">
          <td align="left" class="left">
            <xsl:attribute name="colspan">
              <xsl:value-of select="count(TGROUP/COLSPEC | tgroup/colspec)"/>
            </xsl:attribute>
            <xsl:apply-templates select="../NOTE | ../note | descendant::ROW/ENTRY/NOTE"/>
          </td>
        </tr>
      </xsl:if>
    </table>
    <xsl:call-template name="auto_br"/>
  </xsl:template>

    <!-- simple table, without TABLEAU parent -->
  <xsl:template match="table">
    <xsl:param name="gid" select="generate-id()" />
    <xsl:param name="titleLevel" select="1"/>
    <xsl:value-of select="php:function('_batire_xml_parse_xslt_storage', 'ARRAY', 'tables', string($gid), string(tabtit))" />
    <a>
      <xsl:attribute name="name">
        <xsl:value-of select="$gid"/>
      </xsl:attribute>
    </a>
    <xsl:apply-templates select="tabtit">
      <xsl:with-param name="titleLevel" select="6"/>
    </xsl:apply-templates>
    <div class="document-table-wrapper">
      <div class="document-table-arrow document-table-arrow-top"></div>
      <div class="document-table-arrow document-table-arrow-middle"></div>
      <div class="document-table-arrow document-table-arrow-bottom"></div>
      <div class="document-table-position">
        <xsl:choose>
          <xsl:when test="tbody/artwork"><xsl:apply-templates select="tbody/artwork"/></xsl:when>
          <xsl:otherwise>
            <table class="document-table">
              <xsl:variable name="colspec" select="php:function('_batire_xml_parse_fake_colspec', number(@cols))/xml/*[not(current()/TGROUP/COLSPEC | current()/tgroup/colspec)]"/>
              <xsl:apply-templates select="THEAD | thead">
                <xsl:with-param name="colspec" select="$colspec"/>
              </xsl:apply-templates>
              <xsl:apply-templates select="TBODY | tbody">
                <xsl:with-param name="colspec" select="$colspec"/>
              </xsl:apply-templates>
              <xsl:apply-templates select="TFOOT | tfoot">
                <xsl:with-param name="colspec" select="$colspec"/>
              </xsl:apply-templates>
            </table>
          </xsl:otherwise>
        </xsl:choose>
      </div>
    </div>
    <xsl:call-template name="auto_br"/>
  </xsl:template>

  <xsl:template match="table[child::tr[child::td]]" priority="10">
    <div class="document-table-wrapper">
      <div class="document-table-arrow document-table-arrow-top"></div>
      <div class="document-table-arrow document-table-arrow-middle"></div>
      <div class="document-table-arrow document-table-arrow-bottom"></div>
      <div class="document-table-position">
        <table class="document-table">
          <xsl:apply-templates/>
        </table>
      </div>
    </div>
  </xsl:template>
  <xsl:template match="tr" priority="10">
    <tr>
      <xsl:apply-templates/>
    </tr>
  </xsl:template>
  <xsl:template match="td" priority="10">
    <td align="left" class="left">
      <xsl:apply-templates/>
    </td>
  </xsl:template>

  <xsl:template match="THEAD | thead">
      <xsl:param name="colspec"/>
      <xsl:param name="spanspec"/>
      <xsl:apply-templates >
        <xsl:with-param name="colspec" select="$colspec"/>
        <xsl:with-param name="spanspec" select="$spanspec"/>
      </xsl:apply-templates>
    </xsl:template>


    <xsl:template match="TFOOT | tfoot">
      <xsl:param name="colspec"/>
      <xsl:param name="spanspec"/>
        <xsl:apply-templates select="../TBODY/ROW[ENTRY/NOTE] | ../tbody/row[entry/note] | ../tbody/row[entry/tabnote]">
          <xsl:with-param name="colspec" select="$colspec"/>
          <xsl:with-param name="spanspec" select="$spanspec"/>
        </xsl:apply-templates>
        <xsl:apply-templates >
          <xsl:with-param name="colspec" select="$colspec"/>
          <xsl:with-param name="spanspec" select="$spanspec"/>
        </xsl:apply-templates>
        <xsl:if test="../../../NOTE | ../../../note">
              <tr class="tfoot">
                <td align="left" class="left">
                  <xsl:attribute name="colspan">
                    <xsl:value-of select="count(../COLSPEC | ../colspec)"/>
                  </xsl:attribute>
                  <xsl:apply-templates select="../../../NOTE | ../../../note"/>
                </td>
              </tr>
        </xsl:if>
    </xsl:template>

    <xsl:template match="TBODY | tbody">
      <xsl:param name="colspec"/>
      <xsl:param name="spanspec"/>
      <xsl:apply-templates select="ROW[not(ENTRY/NOTE)] | row[not(entry/note)]">
        <xsl:with-param name="colspec" select="$colspec"/>
        <xsl:with-param name="spanspec" select="$spanspec"/>
      </xsl:apply-templates>
    </xsl:template>

    <xsl:template match="THEAD/ROW | thead/row | TBODY/ROW | tbody/row | TFOOT/ROW | tfoot/row">
      <xsl:param name="colspec"/>
      <xsl:param name="spanspec"/>
      <tr>
        <xsl:if test="parent::TFOOT or parent::tfoot">
          <xsl:attribute name="class">tfoot</xsl:attribute>
        </xsl:if>
        <xsl:if test="@valign">
          <xsl:attribute name="valign">
            <xsl:value-of select="@valign"/>
          </xsl:attribute>
        </xsl:if>
        <xsl:apply-templates select="*">
          <xsl:with-param name="colspec" select="$colspec"/>
          <xsl:with-param name="spanspec" select="$spanspec"/>
        </xsl:apply-templates>
      </tr>
    </xsl:template>

    <xsl:template match="THEAD/ROW/ENTRY | thead/row/entry | TBODY/ROW/ENTRY | tbody/row/entry | TFOOT/ROW/ENTRY | tfoot/row/entry">
      <xsl:param name="colspec"/>
      <xsl:param name="spanspec"/>
      <xsl:variable name="col_multi">
        <xsl:choose>
          <xsl:when test="ancestor::TABLE[@tabstyle = 'eqn']">
            <xsl:text>4</xsl:text>
          </xsl:when>
          <xsl:when test="$doc_type = 'FM'">
            <xsl:text>5</xsl:text>
          </xsl:when>
          <xsl:otherwise>
            <xsl:text>1.5</xsl:text>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:variable>
      <xsl:variable name="rows_count">
        <xsl:value-of select="count(../../ROW)" />
      </xsl:variable>
      <xsl:variable name="current_row">
        <xsl:value-of select="count(../preceding-sibling::*) + 1" />
      </xsl:variable>
      <xsl:variable name="more_rows">
        <xsl:choose>
          <xsl:when test="string(number(@morerows))='NaN'">0</xsl:when>
          <xsl:otherwise>
            <xsl:value-of select="@morerows" />
          </xsl:otherwise>
        </xsl:choose>
      </xsl:variable>
      <td>
        <xsl:if test="count($colspec) and $colspec[@colname = current()/@colname]/@colwidth">
          <xsl:attribute name="width">
            <xsl:value-of select="number(substring-before($colspec[@colname = current()/@colname]/@colwidth, '*'))*$col_multi" />
            <!-- <xml:text>%</xml:text> -->
          </xsl:attribute>
        </xsl:if>
        <xsl:if test="@valign">
          <xsl:attribute name="valign">
            <xsl:value-of select="@valign"/>
          </xsl:attribute>
        </xsl:if>
        <xsl:if test="@align or ((not(@rowsep) or @rowsep = 1) and ($rows_count &gt; $more_rows + $current_row))">
          <xsl:attribute name="align">
            <xsl:value-of select="@align"/>
          </xsl:attribute>
          <xsl:attribute name="class">
            <xsl:if test="@align">
              <xsl:value-of select="@align"/>
            </xsl:if>
            <xsl:if test="@align and ((not(@rowsep) or @rowsep = 1) and ($rows_count &gt; $more_rows + $current_row))">
              <xsl:text> </xsl:text>
            </xsl:if>
            <xsl:if test="(not(@rowsep) or @rowsep = 1) and ($rows_count &gt; $more_rows + $current_row)">
              <xsl:text>rowsep</xsl:text>
            </xsl:if>
          </xsl:attribute>
        </xsl:if>
        <xsl:if test="@morerows">
          <xsl:attribute name="rowspan">
            <xsl:value-of select="@morerows + 1"/>
          </xsl:attribute>
        </xsl:if>
        <xsl:if test="@namest">
          <xsl:attribute name="colspan">
            <xsl:choose>
              <xsl:when test="$colspec">
                <xsl:value-of select="count($colspec[@colname = current()/@nameend]/preceding-sibling::*) - count($colspec[@colname = current()/@namest]/preceding-sibling::*) + 1" />
              </xsl:when>
              <xsl:otherwise>
                <xsl:value-of select="number(substring-after(@nameend, 'col')) - number(substring-after(@namest, 'col')) + 1"/>
              </xsl:otherwise>
            </xsl:choose>
          </xsl:attribute>
        </xsl:if>
        <xsl:if test="@spanname">
          <xsl:attribute name="colspan">
            <xsl:value-of select="count($colspec[@colname = $spanspec[@spanname = current()/@spanname]/@nameend]/preceding-sibling::*) - count($colspec[@colname = $spanspec[@spanname = current()/@spanname]/@namest]/preceding-sibling::*) + 1" />
          </xsl:attribute>
        </xsl:if>
        <xsl:choose>
        <xsl:when test="ancestor::thead | ancestor::THEAD">
          <b>
            <xsl:apply-templates />
          </b>
        </xsl:when>
        <xsl:when test="(ancestor::tbody | ancestor::TBODY) and not(../../../THEAD) and not(../../../thead) and not(../preceding-sibling::*[1]) and $doc_type='FM' and ancestor::TABLE[@tabstyle != 'eqn']">
          <b>
            <xsl:apply-templates />
          </b>
        </xsl:when>
        <xsl:otherwise>
          <xsl:apply-templates />
        </xsl:otherwise>
        </xsl:choose>
      </td>
    </xsl:template>

    <xsl:template match="TABLE//REFNOTE | table//refnote">
      <xsl:param name="all_notes" select="ancestor::TABLEAU/NOTE | ancestor::tableau/note"/>
      <xsl:param name="note" select="$all_notes[@ID = current()/@IDREF]"/>
      <a>
        <xsl:attribute name="href">
          <xsl:text>#</xsl:text>
          <xsl:value-of select="@IDREF"/>
        </xsl:attribute>
        <sup>
          <xsl:text>(</xsl:text>
          <xsl:variable name="ref_note">
            <xsl:value-of select="substring(number(substring-after(@IDREF, concat(ancestor::TABLEAU[1]/@ID, 'N'))), 1, 1)"/>
          </xsl:variable>
          <xsl:choose>
            <xsl:when test="$ref_note != 'N'">
              <xsl:value-of select="$ref_note" />
            </xsl:when>
            <xsl:otherwise>
              <xsl:value-of select="substring(number(substring-after(@IDREF, concat(ancestor::TABLEAU[1]/@ID, 'NT'))), 1, 1)" />
            </xsl:otherwise>
          </xsl:choose>
          <xsl:text>)</xsl:text>
        </sup>
      </a>
    </xsl:template>

    <xsl:template  match="TABLEAU/NOTE | tableau/note | table/note | ROW/ENTRY/NOTE">
      <xsl:call-template name="anchor"/>
      <xsl:for-each select="*">
        <xsl:apply-templates select="current()">
          <xsl:with-param name="para_prefix">
            <xsl:if test="position() = 1">
              <xsl:value-of select="count(../preceding-sibling::NOTE | ../preceding-sibling::note) + 1"/>
              <xsl:text>) </xsl:text>
            </xsl:if>
          </xsl:with-param>
        </xsl:apply-templates>
      </xsl:for-each>
    </xsl:template>
<!-- /Tables -->

<!-- Additional templates -->

<!-- /Additional templates -->

<!-- Special empty nodes -->
  <xsl:template match="CARTOUCHE" priority="10">
    <xsl:call-template name="anchor"/>
    <xsl:choose>
      <xsl:when test="ancestor::*[name()='FICHESYNT']">
        <div class="document-text-special">
          <xsl:value-of select="THEME" />
          <xsl:call-template name="auto_br"/>
          <xsl:text>SYNTHESE - </xsl:text>
          <xsl:value-of select="BATIMENT" />
          <xsl:call-template name="auto_br"/>
          <xsl:value-of select="REFERENCE/TITRE" />
          <xsl:call-template name="auto_br"/>
        </div>
        <br/>
      </xsl:when>
      <xsl:when test="ancestor::*[name()='FICHEART']">
        <div class="document-text-special">
          <xsl:value-of select="THEME" />
          <xsl:call-template name="auto_br"/>
          <xsl:text>Article(s) </xsl:text>
          <xsl:value-of select="NUMARTDEB" />
          <xsl:if test="NUMARTFIN">
            <xsl:text> à </xsl:text>
            <xsl:value-of select="NUMARTFIN" />
          </xsl:if>
          <xsl:text> - </xsl:text>
          <xsl:value-of select="BATIMENT" />
          <xsl:call-template name="auto_br"/>
          <xsl:value-of select="REFERENCE/TITRE" />
          <xsl:call-template name="auto_br"/>
        </div>
        <br/>
      </xsl:when>
      <xsl:when test="ancestor::*[name()='FICHECMT' or name()='FICHEOFF' or name()='FICHESPE' or name()='FICHESIN']">
        <div class="document-text-special">
          <xsl:value-of select="THEME" />
          <xsl:call-template name="auto_br"/>
          <xsl:value-of select="BATIMENT" />
          <xsl:call-template name="auto_br"/>
          <xsl:value-of select="REFERENCE/TITRE" />
          <xsl:call-template name="auto_br"/>
        </div>
        <br/>
      </xsl:when>
      <xsl:otherwise>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="FICHEB" priority="10">
    <xsl:choose>
      <xsl:when test="./THEME and ./CONTEXTE">
        <div class="batire-document-name-title">
          <xsl:value-of select="./THEME"/>
        </div>
        <br/>
        <xsl:apply-templates select="./CONTEXTE"/>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-templates />
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="prebody/profile | ptitrefr/reference">
  </xsl:template>

<!-- /Special empty nodes -->


<!-- Inline formatting -->

  <xsl:template match="a|A"><a>
    <xsl:for-each select="@*">
      <xsl:attribute name="{name()}" >
        <xsl:value-of select="."/>
      </xsl:attribute>
    </xsl:for-each>
    <xsl:value-of select="."/>
  </a></xsl:template>

    <xsl:template match="B | b | hp[@format='bold']">
      <b>
        <xsl:apply-templates />
      </b>
      <xsl:text> </xsl:text>
    </xsl:template>

    <xsl:template match="I | i | hp[@format='italic']">
      <i>
        <xsl:apply-templates />
      </i>
    </xsl:template>

    <xsl:template match="hp[@format='none']">
      <br/>
        <xsl:apply-templates />
    </xsl:template>

    <xsl:template match="BR | br">
      <br />
    </xsl:template>

    <xsl:template match="SL | sl">
      <u>
        <xsl:apply-templates/>
      </u>
    </xsl:template>

    <xsl:template match="SUP | sup">
      <sup>
        <xsl:apply-templates/>
      </sup>
    </xsl:template>

    <xsl:template match="SUB | sub">
      <sub>
        <xsl:apply-templates/>
      </sub>
    </xsl:template>

    <xsl:template match="BI | bi">
      <b>
        <i>
          <xsl:apply-templates/>
        </i>
      </b>
      <xsl:text> </xsl:text>
    </xsl:template>

    <xsl:template match="hr">
      <hr/>
      <xsl:value-of select="." disable-output-escaping="yes"/>
      <hr/>
      <hr/>
    </xsl:template>

  <xsl:template match="manfmt[@font='Symbol']">
    <xsl:choose>
    <xsl:when test="string(.) = 'Š'">
      <xsl:text>≥</xsl:text>
    </xsl:when>
    <xsl:when test="string(.) = '£'">
      <xsl:text>≤</xsl:text>
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="string(.)" />
    </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="TEXTEPAPIER">
    <xsl:text> </xsl:text>
    <xsl:apply-templates/>
  </xsl:template>

<!-- /Inline formatting -->

<!-- named templates -->

  <xsl:template name="actualite_lien_reference">
    <xsl:param name="special"/>
    <xsl:variable name="lien_reference" select="php:function('_batire_xml_parse_xslt_get_lien_reference', number(@refid), string(.))"/>
    <xsl:choose>
      <xsl:when test="$lien_reference/lien_reference/@type = 'FICHE'">
        <xsl:if test="string($lien_reference/lien_reference/img/type)='image'">
          <div class="image-block">
            <a>
              <xsl:attribute name="name">
                  <xsl:value-of select="$lien_reference/lien_reference/img/file_name"/>
              </xsl:attribute>
            </a>
            <div class="document-image">
              <div class="image">
                <xsl:copy-of select="$lien_reference/lien_reference/img/html/*"/>
              </div>
              <xsl:if test="$lien_reference/lien_reference/img/zoom_image_src">
                <div class="zoom">
                  <a class="fancybox-zoom">
                    <xsl:attribute name="href">
                      <xsl:value-of select="$lien_reference/lien_reference/img/zoom_image_src"/>
                    </xsl:attribute>
                  </a>
                </div>
              </xsl:if>
            </div>
            <xsl:if test="$lien_reference/lien_reference/img/zoom_image_src">
              <div class="document-image-info"></div>
              <xsl:call-template name="auto_br"/>
            </xsl:if>
          </div>
        </xsl:if>
      </xsl:when>
      <xsl:when test="$lien_reference/lien_reference/@type = 'ARTICLE'">
        <xsl:value-of select="$lien_reference/lien_reference" disable-output-escaping="yes"/>
      </xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="$lien_reference/lien_reference"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

<xsl:template name="show_picture_inline">
  <xsl:param name="special"/>
  <xsl:variable name="image" select="php:function('_batire_xml_parse_xslt_get_image_info', string(@IMG | @name), $special)"/>
  <xsl:choose>
      <xsl:when test="string($image/img/type)='flash'">
          <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=8" >
            <xsl:attribute name="width">
              <xsl:value-of select="$image/img/width"/>
            </xsl:attribute>
            <xsl:attribute name="height">
              <xsl:if test="not(string-length($image/img/height))">
                <xsl:text>100%</xsl:text>
              </xsl:if>
              <xsl:value-of select="$image/img/height"/>
            </xsl:attribute>
            <xsl:attribute name="align">
              <xsl:text>middle</xsl:text>
            </xsl:attribute>
            <param name="movie">
              <xsl:attribute name="value">
                <xsl:value-of select="$image/img/src"/>
              </xsl:attribute>
            </param>
            <param name="wmode">
              <xsl:attribute name="value">
                <xsl:text>transparent</xsl:text>
                </xsl:attribute>
            </param>
            <embed type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer">
              <xsl:attribute name="width">
                <xsl:value-of select="$image/img/width"/>
              </xsl:attribute>
              <xsl:attribute name="height">
                <xsl:if test="not(string-length($image/img/height))">
                  <xsl:text>100%</xsl:text>
                </xsl:if>
                <xsl:value-of select="$image/img/height"/>
              </xsl:attribute>
              <xsl:attribute name="src">
                <xsl:value-of select="$image/img/src"/>
              </xsl:attribute>
              <param name="wmode">
                <xsl:attribute name="value">
                  <xsl:text>transparent</xsl:text>
                </xsl:attribute>
              </param>
            </embed>
          </object>
     </xsl:when>
      <xsl:when test="string($image/img/type)='image'">
          <xsl:copy-of select="$image/img/html/*"/>
       </xsl:when>
      <xsl:otherwise>
          <xsl:value-of select="@IMG"/>
      </xsl:otherwise>
    </xsl:choose>
</xsl:template>


  <xsl:template name="show_picture">
    <xsl:param name="special"/>
    <xsl:variable name="image" select="php:function('_batire_xml_parse_xslt_get_image_info', string(@IMG | @img |@name | @entity), $special)"/>
     <xsl:choose>
      <xsl:when test="string($image/img/type)='flash'">
        <div class="document-image">
        <div class="image">
          <xsl:attribute name="style">
            <xsl:text>width:</xsl:text>
            <xsl:value-of select="$image/img/width"/>
            <xsl:text>px</xsl:text>
          </xsl:attribute>
          <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=8" >
            <xsl:attribute name="width">
              <xsl:value-of select="$image/img/width"/>
            </xsl:attribute>
            <xsl:attribute name="height">
              <xsl:if test="not(string-length($image/img/height))">
                <xsl:text>100%</xsl:text>
              </xsl:if>
              <xsl:value-of select="$image/img/height"/>
            </xsl:attribute>
            <param name="movie">
              <xsl:attribute name="value">
                <xsl:value-of select="$image/img/src"/>
              </xsl:attribute>
            </param>
            <param name="wmode">
              <xsl:attribute name="value">
                <xsl:text>transparent</xsl:text>
                </xsl:attribute>
            </param>
            <embed type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer">
              <xsl:attribute name="width">
                <xsl:value-of select="$image/img/width"/>
              </xsl:attribute>
              <xsl:attribute name="height">
                <xsl:if test="not(string-length($image/img/height))">
                  <xsl:text>100%</xsl:text>
                </xsl:if>
                <xsl:value-of select="$image/img/height"/>
              </xsl:attribute>
              <xsl:attribute name="src">
                <xsl:value-of select="$image/img/src"/>
              </xsl:attribute>
              <param name="wmode">
                <xsl:attribute name="value">
                  <xsl:text>transparent</xsl:text>
                </xsl:attribute>
              </param>
            </embed>
          </object>
        </div>
        </div>
      </xsl:when>
      <xsl:when test="string($image/img/type)='image'">
        <div class="document-image">
        <div class="image">
          <xsl:copy-of select="$image/img/html/*"/>
        </div>
        <xsl:if test="$image/img/zoom_image_src">
          <div class="zoom">
            <a class="fancybox-zoom">
              <xsl:attribute name="href">
                <xsl:value-of select="$image/img/zoom_image_src"/>
              </xsl:attribute>
            </a>
          </div>
          <div class="print">
            <a class="tooltip">
              <xsl:attribute name="title">
                <xsl:value-of select="$image/img/print_title"/>
              </xsl:attribute>
              <xsl:attribute name="href">
                <xsl:value-of select="$image/img/img_print"/>
              </xsl:attribute>
            </a>
          </div>
        </xsl:if>
        </div>
      </xsl:when>
      <xsl:when test="string($image/img/type)='tn-equation'">
        <div class="document-image">
        <div class="image">
            <xsl:attribute name="style">
                <xsl:text>width:</xsl:text>
                <xsl:value-of select="$image/img/width"/>
                <xsl:text>px</xsl:text>
            </xsl:attribute>
            <br/>
            <xsl:copy-of select="$image/img/html/*"/>
        </div>
        <xsl:if test="$image/img/zoom_image_src">
          <div class="zoom">
            <a class="fancybox-zoom">
              <xsl:attribute name="href">
                <xsl:value-of select="$image/img/zoom_image_src"/>
              </xsl:attribute>
            </a>
          </div>
        </xsl:if>
        </div>
      </xsl:when>
      <xsl:otherwise>
        <!--<div class="error">NO PICTURE
          <xsl:value-of select="@IMG"/>
        </div>-->
          <div class="empty-picture">[image en cours de publication ou de republication]</div>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

    <xsl:template name="anchor">
      <xsl:if test="string(@id) or string(@Id) or string(@ID)">
        <a>
          <xsl:attribute name="name">
            <xsl:value-of select="@ID|@id|@Id" />
          </xsl:attribute>
        </a>
      </xsl:if>
    </xsl:template>

    <xsl:template name="auto_br">
      <xsl:if test="following-sibling::* and (name() = 'REFART' or (name(following-sibling::*[position() = 1]) != 'LIST' and name(following-sibling::*[position() = 1]) != 'LISTE') and (name(following-sibling::*[1]) != 'FICHENUM'))">
        <br/>
      </xsl:if>
    </xsl:template>

    <xsl:template name="parse-title-number">
      <xsl:param name="data"/>
      <xsl:if test="string-length($data) > 1">
        <xsl:text>.</xsl:text>
        <xsl:choose>
          <xsl:when test="substring($data,1,1) = '0'">
            <xsl:value-of select="substring($data,2,1)"/>
          </xsl:when>
          <xsl:otherwise>
            <xsl:value-of select="substring($data,1,2)"/>
          </xsl:otherwise>
        </xsl:choose>
        <xsl:call-template name="parse-title-number">
          <xsl:with-param name="data" select="substring($data,3)"/>
        </xsl:call-template>
      </xsl:if>
    </xsl:template>

<!-- /named templates -->
  </xsl:stylesheet>
<?php
  /**
   * @file
   * Template for commercials email;
   */
?>
<strong>Coordonnées</strong>

Civilité : <?php print $field_user_salut; ?>

Nom : <?php print $field_user_surname; ?>

Prénom : <?php print $field_user_name; ?>

Email : <?php print $mail; ?>

Téléphone 1 : <?php print $field_user_tel_1; ?>

Fonction : <?php print $field_user_position; ?>

Spécialité : <?php print $field_user_specialty; ?>

<strong>Entreprise/Organisme</strong>

Raison sociale : <?php print $field_user_company; ?>

Adresse 1 : <?php print $field_user_address_1; ?>

Adresse 2 : <?php print $field_user_address_2; ?>

Code postal : <?php print $field_user_zip; ?>

Ville : <?php print $field_user_city; ?>

Pays : <?php print $field_user_country; ?>


Identifiant : <?php print $user_login; ?>

Mot de passe : <?php print $user_pass; ?>


Nb de postes souhaités : <?php print $subacc_num; ?>

<?php if (count($subaccs)) : ?>
  <?php foreach ($subaccs as $key => $subacc) : ?>
    <?php $cnt = $key + 1; ?>
    Poste <?php print $cnt; ?> : <?php print $subacc['name']; ?> <?php print $subacc['surname']; ?> <?php print $subacc['mail']; ?>

  <?php endforeach; ?>
<?php endif; ?>

<br /><strong>Relation commerciales</strong>

Code promotion : <?php print $field_user_promo; ?>

Réception email : <?php print $field_user_email_format; ?>

Usage de mes coordonnées par le Moniteur : <?php print $field_user_opt_1; ?>

Transmission de mes coordonnées aux partenaires du GM : <?php print $field_user_opt_2; ?>
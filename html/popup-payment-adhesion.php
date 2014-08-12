<?php
$ajax = isset($_SERVER['HTTP_X_REQUESTED_WITH']) && $_SERVER['HTTP_X_REQUESTED_WITH'] == 'XMLHttpRequest' ? true : false;
?>
<?php if (!$ajax) { ?>
<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8" />
<title>Vaincre la Mucoviscidose</title>
<?php include 'templates/files/styles.php' ?>
</head>
<body>
<?php } ?>
  <div class="popup-wrapper">
    <div class="bg-block bg-block-tl"></div>
    <div class="bg-block bg-block-top"></div>
    <div class="bg-block bg-block-tr"></div>
    <div class="bg-block bg-block-right"></div>
    <div class="bg-block bg-block-br"></div>
    <div class="bg-block bg-block-bottom"></div>
    <div class="bg-block bg-block-bl"></div>
    <div class="bg-block bg-block-left"></div>
    <div class="content">
      <h2>paiement <strong>sécurisé</strong></h2>
      <p>En cliquant sur «Accédez à la platforme de paiement sécurisé», vous allez être redirigé sur le site de notre banque pour effectuer votre paiement en toute sécurisé.</p>
      <div class="block">
        <div class="total">
          <p>Montant de l'adhésion</p>
          <span>75&euro;</span>
        </div>
        <div class="button">
          <a href="#" class="green-btn"><span>Accédez à la plateforme de paiment sécurisé</span></a>
        </div>
        <div class="button">
          <a href="#" class="gray-btn close-btn"><span>Retour</span></a>
        </div>
        <div class="enddiv"></div>
      </div>
    </div>
  </div>
<?php if (!$ajax) { ?>
</body>
</html>
<?php } ?>
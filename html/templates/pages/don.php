<a href="popup-payment-secure.php" class="fancybox-popup" style="position: absolute; top: -9999px; left: -9999px;">popup</a>
<div class="left-section">
  <?php include 'templates/breadcrumbs/breadcrumb_don.php' ?>
  <div class="main-title">
    <h1>je fais <strong>un don</strong></h1>
  </div>
  <div class="form-section-wrapper">
    <div class="inner">
      <div class="form-section">
        <h2>1. Mon don</h2>
        <div class="block-form">
          <h3>Je donne une fois</h3>
          <div class="form-item">
            <div class="form-item form-type-radio">
              <input id="radio-1" class="form-radio" type="radio" value="" name="name" />
              <label for="radio-1">20&euro;</label>
            </div>
            <div class="form-item form-type-radio">
              <input id="radio-2" class="form-radio" type="radio" value="" name="name" />
              <label for="radio-2">40&euro;</label>
            </div>
            <div class="form-item form-type-radio">
              <input id="radio-3" class="form-radio" type="radio" value="" name="name" />
              <label for="radio-3">60&euro;</label>
            </div>
            <div class="form-item form-type-radio">
              <input id="radio-4" class="form-radio" type="radio" value="" name="name" />
              <label for="radio-4">100&euro;</label>
            </div>
          </div>
          <div class="form-item form-type-textfield-small form-text-static-val">
            <label>ou montant libre</label>
            <div class="form-item">
              <input class="form-text" type="text"  name="text" />
              <span class="static-value">&euro;</span>
            </div>
          </div>
          <div class="separator"><span>Ou</span></div>
          <h3>Je donne chaque mois</h3>
          <a href="#" class="return-btn">
            Remplissez le formulaire et renvoyez-le.
          </a>
          <div class="block-soit">
            <div class="top-section">
              <p>Soit 6,60 &euro;</p>
              <span>après déduction fiscale</span>
            </div>
            <div class="bottom-section">
              <p>Je recevrai un reçu fiscal qui me permettra de réduire mes impôts de 66% du montant de mon don, dans la limite de 20% de mes revenus</p>
            </div>
          </div>
        </div>
      </div>
      <div class="form-section form-section-right">
        <h2>2. Mes coordonnées</h2>
        <div class="block-form">
          <div class="form-item radio-inline">
            <label>Civilité*</label>
            <div class="form-item form-type-radio">
              <input id="radio-5" class="form-radio" type="radio" value="" name="civilité" />
              <label for="radio-5">Mme</label>
            </div>
            <div class="form-item form-type-radio">
              <input id="radio-6" class="form-radio" type="radio" value="" name="civilité" />
              <label for="radio-6">Mlle</label>
            </div>
            <div class="form-item form-type-radio">
              <input id="radio-7" class="form-radio" type="radio" value="" name="civilité" />
              <label for="radio-7">Mr</label>
            </div>
          </div>
          <div class="form-item-line">
            <div class="form-item">
              <label>Nom*</label>
              <input class="form-text" type="text"  name="text" />
            </div>
            <div class="form-item">
              <label>Prénom*</label>
              <input class="form-text" type="text"  name="text" />
            </div>
          </div>
          <div class="form-item-line">
            <div class="form-item">
              <label>Immeuble, lotissement</label>
              <input class="form-text" type="text"  name="text" />
            </div>
            <div class="form-item">
              <label>Voie (rue, avenue...)*</label>
              <input class="form-text" type="text"  name="text" />
            </div>
          </div>
          <div class="form-item-line">
            <div class="form-item">
              <label>Lieu dit*</label>
              <input class="form-text" type="text"  name="text" />
            </div>
            <div class="form-item">
              <label>Code postal*</label>
              <input class="form-text" type="text"  name="text" />
            </div>
          </div>
          <div class="form-item-line">
            <div class="form-item">
              <label>Ville*</label>
              <input class="form-text" type="text"  name="text" />
            </div>
            <div class="form-item">
              <label>Pays*</label>
              <input class="form-text" type="text"  name="text" />
            </div>
          </div>
          <div class="form-item-line last">
            <div class="form-item">
              <label>Email*</label>
              <input class="form-text" type="text"  name="text" />
            </div>
            <div class="form-item">
              <label>Téléphone*</label>
              <input class="form-text" type="text"  name="text" />
            </div>
          </div>
          <div class="form-item form-type-checkbox">
            <input id='accept' class="form-checkbox" type="checkbox" value="" name="j'accepte" />
            <label class="option" for="accept">J'accepte que mes coordonnées soient échangées avec d'autres associations</label>
          </div>
        </div>
        <div class="form-description">
          <p>* Champs obligatoires (ces informations sont indispensables pour bénéficier de votre réduction fiscale)</p>
        </div>
      </div>
    </div>
  </div>
  <div class="payment-section">
    <div class="title-line">
      <h2><span>3. paiement</span></h2>
    </div>
    <div class="form-item">
      <label>Séléctionnez votre moyen de paiement</label>
      <div class="form-item form-type-radio pay-card">
        <input id="payment-1" class="form-radio" type="radio" value="" name="payment" />
        <label for="payment-1"><span></span>Je souhaite payer par <strong>carte bancaire</strong></label>
      </div>
      <div class="form-item form-type-radio pay-check">
        <input id="payment-2" class="form-radio" type="radio" value="" name="payment" />
        <label for="payment-2"><span></span>Je souhaite payer par <strong>chèque</strong></label>
      </div>
      <div class="form-item form-type-radio pay-prelevement last">
        <input id="payment-3" class="form-radio" type="radio" value="" name="payment" />
        <label for="payment-3"><span></span>Je souhaite mettre en place <strong>un prélèvement</strong></label>
      </div>
      <div class="form-item">
        <input type="submit" class="form-submit" value="Je confirme mon adhésion" name="submit" />
      </div>
    </div>
  </div>
  <div class="block-c3">
    <div class="block">
      <h2>Pourquoi donner ?</h2>
      <p>This is Photoshop's version  of Lorem Ipsum. Proin gravida nibh vel velit auctor aliquet. Aenean sollicitudin, lorem quis bibendum auctor, nisi elit consequat ipsum, nec sagittis sem nibh id elit. Duis sed odio sit amet nibh vulputate cursus a sit amet mauris. Morbi accumsan ipsum velit. Nam nec tellus a odio tincidunt auctor a ornare odio. Sed non  mauris vitae erat consequat auctor eu in elit. </p>
    </div>
    <div class="block">
      <h2>Respect de votre vie privée</h2>
      <p>This is Photoshop's version  of Lorem Ipsum. Proin gravida nibh vel velit auctor aliquet. Aenean sollicitudin, lorem quis bibendum auctor, nisi elit consequat ipsum, nec sagittis sem nibh id elit. Duis sed odio sit amet nibh vulputate cursus a sit amet mauris. Morbi accumsan ipsum velit. Nam nec tellus a odio tincidunt auctor a ornare odio. Sed non  mauris vitae erat consequat auctor eu in elit. </p>
    </div>
    <div class="block last">
      <h2>Donner en toute sécurité</h2>
      <img src="files/don_pic.jpg" alt="image" />
      <p>This is Photoshop's version  of Lorem Ipsum. Proin gravida nibh vel velit auctor aliquet. Aenean sollicitudin, lorem quis bibendum auctor, nisi elit consequat ipsum, nec sagittis sem nibh id elit. Duis sed odio sit amet nibh vulputate cursus a sit amet mauris. Morbi accumsan ipsum velit.</p>
    </div>
  </div>
  <div class="enddiv"></div>
</div>
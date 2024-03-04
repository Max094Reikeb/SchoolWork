<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Simulateur de crédit</title>
    <meta charset="utf-8"/>
    <link rel="stylesheet" type="text/css" href="style.css">
    <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no"/>
</head>
<body>
<fieldset>
    <legend>Saisissez les informations du prêt :</legend>
    <form method="POST">
        <label for="capital">Capital emprunté :</label>
        <input type="number" name="capital" id="capital" required> €<br><br>

        <label for="nombreAnnee">Durée de l'emprunt (en années) :</label>
        <input type="number" name="nombreAnnee" id="nombreAnnee" required> ans<br><br>

        <label for="tauxAssurance">Taux annuel de l'assurance :</label>
        <input type="number" step="0.01" name="tauxAssurance" id="tauxAssurance" required> %<br><br>

        <label for="tauxInteretDepart">Taux d'intérêt hors assurance de départ :</label>
        <input type="number" step="0.01" name="tauxInteretDepart" id="tauxInteretDepart" required> %<br><br>

        <label for="tauxInteretFin">Taux d'intérêt hors assurance final :</label>
        <input type="number" step="0.01" name="tauxInteretFin" id="tauxInteretFin" required> %<br><br>

        <label for="pas">Pas de progression du taux :</label>
        <input type="number" step="0.1" name="pas" id="pas" required> %<br><br>

        <input type="submit" value="Calculer">
    </form>
</fieldset>
<br>
<h2>Résultat de la simulation</h2>
<?php
// Récupération des données du formulaire
$capital = $_POST["capital"] ?? 0;
$nombreAnnee = $_POST["nombreAnnee"] ?? 0;
$tauxAssurance = $_POST["tauxAssurance"] ?? 0;
$tauxInteretDepart = $_POST["tauxInteretDepart"] ?? 0;
$tauxInteretFin = $_POST["tauxInteretFin"] ?? 0;
$pas = $_POST['pas'] ?? 0;

// Calculs
$tauxAssuranceMensuel = ($tauxAssurance / 100) / 12;
$nombreMois = $nombreAnnee * 12;

?>
<!-- Affichage de la table -->
<table border='1'>
    <thead>
    <tr>
        <th>Taux d'intérêt %</th>
        <th>Mensualité avec assurance €</th>
        <th>Assurance €</th>
        <th>Coût total du crédit €</th>
        <th>Coût total en %</th>
    </tr>
    </thead>
    <tbody>
    <?php
    for ($tauxInteret = $tauxInteretDepart; $tauxInteret <= $tauxInteretFin; $tauxInteret += $pas) {

        $tauxMensuel = ($tauxInteret / 100) / 12; // Calcul du taux mensuel
        $coutAssuranceMensuel = $capital * $tauxAssuranceMensuel; // Calcul du coût mensuel de l'assurance
        // Calcul de la mensualité (hors assurance)
        $mensualite = $capital * $tauxMensuel * (pow(1 + $tauxMensuel, $nombreMois) / (pow(1 + $tauxMensuel, $nombreMois) - 1));
        $coutMensuel = $mensualite + $coutAssuranceMensuel; // Calcul de la mensualité (avec assurance)
        $coutTotal = ($mensualite * $nombreMois) - $capital; // Calculer le coût total du crédit
        $coutTotalPourcent = ($coutTotal / $capital) * 100; // Calculer le coût total du crédit en pourcentage

        echo "<tr>";
        echo "<td>" . round($tauxInteret, 2) . " %</td>";
        echo "<td>" . round($coutMensuel, 2) . " €</td>";
        echo "<td>" . round($coutAssuranceMensuel, 2) . " €</td>";
        echo "<td>" . round($coutTotal, 2) . " €</td>";
        echo "<td>" . round($coutTotalPourcent, 2) . " %</td>";
        echo "</tr>";
    }
    ?>
    </tbody>
</table>
</body>
</html>

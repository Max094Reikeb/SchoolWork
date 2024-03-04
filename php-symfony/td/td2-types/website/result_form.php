<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Formulaire de saisie de personnes</title>
    <meta charset="utf-8"/>
    <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no"/>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>
<?php
// Initialisation des variables de session : personnes saisies et autres
session_start();
if (!isset($_SESSION['people'])) {
    $_SESSION['people'] = array();
}
if (!isset($_SESSION['id'])) {
    $_SESSION['id'] = 0;
}
if (!isset($_SESSION['validForm'])) {
    $_SESSION['validForm'] = false;
}

// Affichage de la table finale
if (count($_SESSION['people']) > 0) {
    ?>
    <h2>Tableau des personnes</h2>
    <table border="1" style="text-align: center">
        <thead>
        <tr>
            <td>ID</td>
            <th>Nom</th>
            <th>Prénom</th>
            <th>Age</th>
        </tr>
        </thead>
        <tbody>
        <?php
        foreach ($_SESSION['people'] as $person) {
            echo "<tr>";
            echo "<td>" . $person['id'] . "</td>";
            echo "<td>" . $person['name'] . "</td>";
            echo "<td>" . $person['surname'] . "</td>";
            echo "<td>" . $person['age'] . "</td>";
            echo "</tr>";
        }
        ?>
        </tbody>
    </table>
    <?php
}
?>
    <br>
    <form method="POST" action="index.php">
        <input type="submit" name="restart" value="Recommencer une saisie">
    </form>
<?php
// On recommence une saisie
if (isset($_POST['restart'])) {
    session_unset();
    unset($_SESSION['people']);
    unset($_SESSION['id']);
    unset($_SESSION['validForm']);
}
?>
<br>
<fieldset>
    <legend>Saisissez le nom du fichier de sauvegarde : </legend>
    <form method="POST" action="web_save.php">
        <label for="file_name">Nom du fichier :</label>
        <input type="text" id="file_name" name="file_name"><br><br>

        <input type="submit" name="validate" id="validate" value="Sauvegarder">
    </form>
</fieldset>
</body>
</html>

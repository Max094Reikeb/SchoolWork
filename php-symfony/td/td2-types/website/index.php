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
?>
<fieldset>
    <legend>Saisissez les données d'une nouvelle personne :</legend>
    <form id="new-person" method="POST">

        <label for="name">Nom :</label>
        <input type="text" id="name" name="name"><br><br>

        <label for="surname">Prénom :</label>
        <input type="text" id="surname" name="surname"><br><br>

        <label for="age">Age :</label>
        <input type="number" id="age" name="age"><br><br>

        <input type="submit" name="validate" id="validate" value="Valider">
    </form>
    <form method="POST" action="result_form.php">
        <input type="submit" name="finish" value="Terminer la saisie">
    </form>
</fieldset>
<br>
<?php
// Récupération des données saisies dans le formulaire
$name = $_POST["name"] ?? "";
$surname = $_POST["surname"] ?? "";
$age = $_POST["age"] ?? 0;
$id = $_SESSION["id"];
if ($name != "" && $surname != "" && $age != "") {
    // Ajout de la personne dans le tableau
    $_SESSION['people'][] = array("id" => $id, "name" => $name, "surname" => $surname, "age" => $age);
    $_SESSION['validForm'] = true;
} else {
    $_SESSION['validForm'] = false;
}

// Affichage de la table de la dernière personne ajoutée
if (count($_SESSION['people']) > 0) {
    if ($_SESSION['validForm']) {
        ?>
        <h2>Dernière personne saisie</h2>
        <table border="1" style="text-align: center">
            <thead>
            <tr>
                <th>Nom</th>
                <th>Prénom</th>
                <th>Age</th>
            </tr>
            </thead>
            <tbody>
            <?php
            echo "<tr>";
            echo "<td>" . $name . "</td>";
            echo "<td>" . $surname . "</td>";
            echo "<td>" . $age . "</td>";
            echo "</tr>";
            ?>
            </tbody>
        </table>
        <?php
        $_SESSION['id']++;
    } else { // Affichage des messages d'erreur
        echo "<form>";
        echo "<fieldset>";
        echo "<legend>Valeurs à renseigner : </legend>";
        if ($name == "") {
            echo "<label>La champ Nom est vide</label>";
            echo "<br>";
        }
        if ($surname == "") {
            echo "<label>Le champ Prénom est vide</label>";
            echo "<br>";
        }
        if ($age == "") {
            echo "<label>Le champ Âge est vide</label>";
            echo "<br>";
        }
        if (gettype($age) != "integer") {
            echo "<label>Le champ Âge est invalide</label>";
            echo "<br>";
        }
        echo "</fieldset>";
        echo "</form>";
    }
}
?>
</body>
</html>

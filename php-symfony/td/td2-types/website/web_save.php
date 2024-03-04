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
// Initialisation des variables de session : personnes saisies
session_start();
if (!isset($_SESSION['people'])) {
    $_SESSION['people'] = array();
}

// We save the datas to the selected file and check if there are any errors
$file_path = "Sauvegardes/";
$file_name = $_POST['file_name'] . ".txt";
$data = "";
$saved_people = 0;
foreach ($_SESSION['people'] as $person) {
    $data .= $person['id'] . $person['name'] . $person['surname'] . $person['age'] . "\n";
    $saved_people++;
}
$file = @fopen($file_path . $file_name, "w");
if ($file) {
    if (fwrite($file, $data)) {
        fclose($file);
    } else {
        fclose($file);
        $message = "erreur du fichier " . $file_path . $file_name . " en écriture !";
        $code_message = "fwrite(" . $file_path . $file_name . ") : failed to write : permission denied";
        $error_line = 27;
        $error_type = 2;
    }
} else {
    $message = "erreur du fichier " . $file_path . $file_name . " en accès !";
    $code_message = "fopen(" . $file_path . $file_name . ") : failed to access : file doesn't exist";
    $error_line = 25;
    $error_type = 1;
}
?>

<fieldset>
    <?php
    if (isset($message)) {
        echo "<legend>Erreur : </legend>";
    } else {
        echo "<legend>Message : </legend>";
    }
    ?>
    <form method="POST" action="">
        <?php
        if (isset($message)) {
            echo "<label><b>Sauvegarde impossible :</b> " . $message . "</label><br><br>";
            echo "<label><b>Type de l'erreur :</b> " . $error_type . "</label><br>";
            echo "<label><b>Message : </b> " . $code_message . "</label><br>";
            echo "<label><b>Répertoire de sauvegarde : </b>" . getcwd() . "/" . $file_path . "</label><br><br>";
            echo "<label><b>Programme PHP : </b>" . getcwd() . "/web_save.php</label><br>";
            echo "<label><b>A la ligne : </b>" . $error_line . "</label>";
        } else {
            echo "<label>Sauvegarde dans le fichier <b>" . $file_path . $file_name . "</b></label>";
        }
        ?>
    </form>
</fieldset>
<br>
<?php
if (!isset($message)) {
    if (count($_SESSION['people']) > 0) {
        ?>
        <h2>Tableau des personnes sauvegardées</h2>
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
        <br>
        <?php
        echo "Nombre de personnes sauvegardées : " . $saved_people;
    }
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
</body>
</html>

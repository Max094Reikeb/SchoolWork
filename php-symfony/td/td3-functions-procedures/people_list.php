<?php

// Définition des variables globales
$people = array();
$num_people = 0;

// Affichage du menu et de la sélection
while (true) {
    echo "-1- Saisie d’une liste de personnes\n";
    echo "-2- Affichage de toutes les personnes\n";
    echo "-3- Sauvegarde dans un fichier\n";
    echo "-4- Chargement d’un fichier\n";
    echo "-0- Quitter\n";
    echo "Choix (1,2,3,...) : ";

    $choice = trim(fgets(STDIN));

    switch ($choice) {
        case 1:
            enter_people();
            break;
        case 2:
            show_people();
            break;
        case 3:
            save_file();
            break;
        case 4:
            load_file();
            break;
        case 0:
            exit();
        default:
            echo "Choix invalide, essayez à nouveau.\n";
            break;
    }
}

// Fonction pour entrer une liste de personnes
function enter_people() {
    global $people, $num_people;
    $people = array();
    $num_people = 0;

    $ids = array();
    foreach ($people as $person) {
        $ids[] = $person['id'];
    }

    while (true) {
        echo "Entrez un ID, un nom, un prénom et un âge (ex : 1;Dupont;Jean;28) : ";
        $line = trim(fgets(STDIN));
        if ($line == "") {
            break;
        }
        $fields = explode(";", $line);
        $id = trim($fields[0]);
        $name = trim($fields[1]);
        $first_name = trim($fields[2]);
        $age = trim($fields[3]);

        // Vérification de l'unicité de l'ID
        if (in_array($id, $ids) || !is_numeric($id)) {
            echo "Erreur: identifiant non valide\n";
            continue;
        }
        $ids[] = $id;

        // Conversion de l'ID et de l'âge en entiers
        $id = intval($id);
        $age = intval($age);

        // Vérification que les valeurs entrées sont non-nulles et numériques
        if ($name === "" || $first_name === "" || !is_numeric($age) || !is_numeric($id)) {
            echo "Erreur: données non valides\n";
            continue;
        }

        // Création de la personne
        $person = array("id" => $id, "name" => normalize_name($name), "first_name" => normalize_name($first_name), "age" => $age);

        // Ajout de la personne à la liste
        $people[] = $person;
        $num_people++;
    }

    // Triage et suppression des duplicatas
    usort($people, function($a, $b) {
        return strcasecmp($a['name'], $b['name']);
    });
    $people = array_map("unserialize", array_unique(array_map("serialize", $people)));
    $num_people = count($people);
}

// Fonction de normalisation pour les noms et prénoms
function normalize_name($name) {
    // Conversion en majuscules
    $name = strtoupper($name);

    // Remplacement des accents par des lettres normales
    $name = strtr($name, "ÀÁÂÃÄÅàáâãäåÒÓÔÕÖØòóôõöøÈÉÊËèéêëÌÍÎÏìíîïÙÚÛÜùúûüÿÑñ", "AAAAAAaaaaaaOOOOOOooooooEEEEeeeeIIIIiiiiUUUUuuuuyNn");

    // Suppression des charactères non alphabetiques et des espaces multiples
    $name = preg_replace('/[^a-zA-Z ]/', '', $name);
    $name = preg_replace('/\s+/', ' ', $name);

    // Remplacement des espaces avec des tirets
    $name = str_replace(' ', '-', $name);

    return $name;
}

// Fonction pour afficher les personnes
function show_people() {
    global $people, $num_people;
    echo "-------------------------------------------------------------\n";
    echo "Numéro :  ID  Nom                           Prénom                       Age\n";
    echo "-------------------------------------------------------------\n";

    $people = array_values($people);
    usort($people, function($a, $b) {
        return $a['id'] - $b['id'];
    });

    foreach ($people as $i => $person) {
        $num = str_pad($i, 7, " ", STR_PAD_LEFT);
        $id = str_pad($person['id'], 5, " ", STR_PAD_LEFT);
        $name = str_pad($person['name'], 30, " ");
        $first_name = str_pad($person['first_name'], 30, " ");
        $age = str_pad($person['age'], 5, " ", STR_PAD_LEFT);
        echo "$num:  $id  $name $first_name $age\n";
    }
    echo "-------------------------------------------------------------\n";
}

// Fonction de sauvegarde des personnes dans un fichier
function save_file() {
    global $people, $num_people;
    echo "Nom du fichier de sauvegarde: ";
    $filename = trim(fgets(STDIN));
    $fp = fopen($filename, "w");
    $saved = 0;
    foreach ($people as $person) {
        fwrite($fp, $person['id'] . ";" . $person['name'] . ";" . $person['first_name'] . ";" . $person['age'] . "\n");
        $saved++;
    }
    fclose($fp);
    echo $saved . " personne(s) sauvegardées dans le fichier " . $filename . "\n";
}

// Fonction de restauration de personnes depuis un fichier
function load_file() {
    global $people, $num_people;
    echo "Nom du fichier à charger: ";
    $filename = trim(fgets(STDIN));
    $people = array();
    $num_people = 0;
    $fp = fopen($filename, "r");
    while ($line = fgets($fp)) {
        $fields = explode(";", $line);
        $id = trim($fields[0]);
        $name = trim($fields[1]);
        $first_name = trim($fields[2]);
        $age = trim($fields[3]);
        $person = array("id" => $id, "name" => $name, "first_name" => $first_name, "age" => $age);
        $people[] = $person;
        $num_people++;
    }
    fclose($fp);

    // Triage et suppression des duplicatas
    usort($people, function($a, $b) {
        return strcasecmp($a['name'], $b['name']);
    });
    $people = array_map("unserialize", array_unique(array_map("serialize", $people)));
    $num_people = count($people);

    echo $num_people . " personne(s) lu(es)\n";
}

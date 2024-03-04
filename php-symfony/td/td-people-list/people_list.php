<?php

// Définition de la classe Personne
class Personne
{
    public $id;
    public $name;
    public $first_name;
    public $age;

    function __construct($id, $name, $first_name, $age)
    {
        $this->id = $id;
        $this->name = $name;
        $this->first_name = $first_name;
        $this->age = $age;
    }

    function display($number)
    {
        $num = str_pad($number, 7, " ", STR_PAD_LEFT);
        $show_id = str_pad($this->id, 5, " ", STR_PAD_LEFT);
        $show_name = str_pad($this->name, 30, " ");
        $show_first_name = str_pad($this->first_name, 30, " ");
        $show_age = str_pad($this->age, 5, " ", STR_PAD_LEFT);
        echo "$num:  $show_id  $show_name $show_first_name $show_age\n";
    }
}

// Définition de la classe LPers
class LPers
{

    // Définition des variables globales
    public $people = array();
    public $num_people = 0;

    // Fonction pour entrer une liste de personnes
    function enter_people()
    {
        $ids = array();
        foreach ($this->people as $person) {
            $ids[] = $person->id;
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

            // Création de la personne et ajout à la liste
            $new_person = new Personne($id, $this->normalize_name($name), $this->normalize_name($first_name), $age);
            $this->people[] = $new_person;
            $this->num_people++;
        }

        // Triage et suppression des duplicatas
        usort($this->people, function ($a, $b) {
            return strcasecmp($a->name, $b->name);
        });
        $this->people = array_map("unserialize", array_unique(array_map("serialize", $this->people)));
        $this->num_people = count($this->people);
    }

    // Fonction de normalisation pour les noms et prénoms
    function normalize_name($name)
    {
        // Conversion en majuscule
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
    function show_people()
    {
        echo "-------------------------------------------------------------\n";
        echo "Numéro :  ID  Nom                           Prénom                       Age\n";
        echo "-------------------------------------------------------------\n";

        $people = array_values($this->people);
        usort($people, function ($a, $b) {
            return $a->id - $b->id;
        });

        foreach ($people as $i => $person) {
            $person->display($i);
        }
        echo "-------------------------------------------------------------\n";
    }

    // Fonction de sauvegarde des personnes dans un fichier
    function save_file()
    {
        echo "Nom du fichier de sauvegarde: ";
        $filename = trim(fgets(STDIN));
        $fp = fopen($filename, "w");
        $saved = 0;
        foreach ($this->people as $person) {
            fwrite($fp, $person->id . ";" . $person->name . ";" . $person->first_name . ";" . $person->age . "\n");
            $saved++;
        }
        fclose($fp);
        echo $saved . " personne(s) sauvegardées dans le fichier " . $filename . "\n";
    }

    // Fonction de restauration de personnes depuis un fichier
    function load_file()
    {
        echo "Nom du fichier à charger: ";
        $filename = trim(fgets(STDIN));
        $this->people = array();
        $this->num_people = 0;
        $fp = fopen($filename, "r");
        while ($line = fgets($fp)) {
            $fields = explode(";", $line);
            $id = trim($fields[0]);
            $name = trim($fields[1]);
            $first_name = trim($fields[2]);
            $age = trim($fields[3]);
            $new_person = new Personne($id, $name, $first_name, $age);
            $this->people[] = $new_person;
            $this->num_people++;
        }
        fclose($fp);

        // Triage et suppression des duplicatas
        usort($this->people, function ($a, $b) {
            return strcasecmp($a->name, $b->name);
        });
        $this->people = array_map("unserialize", array_unique(array_map("serialize", $this->people)));
        $this->num_people = count($this->people);

        echo $this->num_people . " personne(s) lu(es)\n";
    }

    function searchPerson()
    {
        echo "Entrez le nom de la personne à rechercher: ";
        $name_search = trim(fgets(STDIN));
        foreach ($this->people as $person) {
            if ($person->name == $name_search) {
                echo "-------------------------------------------------------------\n";
                echo "Numéro :  ID  Nom                           Prénom                       Age\n";
                echo "-------------------------------------------------------------\n";
                $person->display("1");
                echo "-------------------------------------------------------------\n";
                return;
            }
        }
        echo "Aucune personne n'a été trouvée avec le nom entré !";
    }

    function deletePerson()
    {
        echo "Entrez l'ID de la personne que vous voulez supprimer: ";
        $id_delete = trim(fgets(STDIN));
        foreach ($this->people as $key => $person) {
            if ($person->id == $id_delete) {
                unset($this->people[$key]);
                echo "La personne vient d'être supprimée !\n";
                return;
            }
        }
        echo "Il n'existe pas de personne avec l'ID . $id_delete . !";
    }

    function modifyPerson()
    {
        echo "Entrez l'ID de la personne que vous souhaitez modifier: ";
        $id = trim(fgets(STDIN));
        foreach ($this->people as $person) {
            if ($person->id == $id) {
                echo "Entrez le nouveau nom, prénom et âge (ex : Dupont;Jean;28) : ";
                $line = trim(fgets(STDIN));
                $fields = explode(";", $line);
                $new_name = trim($fields[0]);
                $new_first_name = trim($fields[1]);
                $new_age = trim($fields[2]);

                // Conversion du nouvel âge en entier
                $new_age = intval($new_age);

                // Vérification des valeurs entrées
                if ($new_name === "" || $new_first_name === "" || !is_numeric($new_age)) {
                    echo "Erreur: données non valides\n";
                    continue;
                }

                // Modification de la personne
                $person->name = $new_name;
                $person->first_name = $new_first_name;
                $person->age = $new_age;

                // Triage et suppression des duplicatas
                usort($this->people, function ($a, $b) {
                    return strcasecmp($a->name, $b->name);
                });
                $this->people = array_map("unserialize", array_unique(array_map("serialize", $this->people)));

                echo "Personne modifiée !";
                return;
            }
        }
        echo "Il n'existe pas de personne avec l'ID . $id . !";
    }

    function researchPeople()
    {
        $found_people = array();
        echo "Entrez le champ recherché ('id', 'nom', 'prenom' ou 'age'): ";
        $field = trim(fgets(STDIN));
        echo "Entez la valeur à chercher: ";
        $value = trim(fgets(STDIN));
        if ($field != "id" && $field != "nom" && $field != "prenom" && $field != "age") {
            echo "Erreur: le champ que vous avez entré n'est pas correct ! Les champs autorisés sont : 'id', 'nom', 'prenom' et 'age' !\n";
            return;
        }
        foreach ($this->people as $person) {
            switch ($field) {
                case 'id':
                    if ($person->id == $value) {
                        $found_people[] = $person;
                    }
                    break;
                case 'nom':
                    if ($person->name == $value) {
                        $found_people[] = $person;
                    }
                    break;
                case 'prenom':
                    if ($person->first_name == $value) {
                        $found_people[] = $person;
                    }
                    break;
                case 'age':
                    if ($person->age == $value) {
                        $found_people[] = $person;
                    }
                    break;
            }
        }
        if (empty($found_people)) {
            echo "Aucune personne n'a été trouvée avec le champ . $field . = . $value . !\n";
        } else {
            echo "-------------------------------------------------------------\n";
            echo "Numéro :  ID  Nom                           Prénom                       Age\n";
            echo "-------------------------------------------------------------\n";

            $show_people = array_values($found_people);
            usort($show_people, function ($a, $b) {
                return $a->id - $b->id;
            });

            foreach ($show_people as $i => $person) {
                $person->display($i);
            }
            echo "-------------------------------------------------------------\n";
        }
    }
}

$lpers = new LPers();

// Affichage du menu et de la sélection
while (true) {
    echo "-1- Saisie d’une liste de personnes\n";
    echo "-2- Affichage de toutes les personnes\n";
    echo "-3- Sauvegarde dans un fichier\n";
    echo "-4- Chargement d’un fichier\n";
    echo "-5- Recherche de personnes, d’après le nom\n";
    echo "-6- Suppression d’une personne\n";
    echo "-7- Modification d’une personne\n";
    echo "-8- Recherche de personnes, d’après un champ\n";
    echo "-0- Quitter\n";
    echo "Choix (1,2,3,...) : ";

    $choice = trim(fgets(STDIN));

    switch ($choice) {
        case 1:
            $lpers->enter_people();
            break;
        case 2:
            $lpers->show_people();
            break;
        case 3:
            $lpers->save_file();
            break;
        case 4:
            $lpers->load_file();
            break;
        case 5:
            $lpers->searchPerson();
            break;
        case 6:
            $lpers->deletePerson();
            break;
        case 7:
            $lpers->modifyPerson();
            break;
        case 8:
            $lpers->researchPeople();
            break;
        case 0:
            exit();
        default:
            echo "Choix invalide, essayez à nouveau.\n";
            break;
    }
}

<?php

// Fonction pour permettre l'entrée utilisateur
function readUserEntry(string $prompt = null): string {
    if (! empty($prompt)) {
        printf($prompt);
    }
    return trim(fgets(STDIN));
}

// Demander les informations de base de l'emprunt à l'utilisateur
$capital = readUserEntry("Capital: ");
$nombreAnnee = readUserEntry("Nombre d'années: ");
$tauxAssurance = readUserEntry("Taux annuel de l'assurance: ");
$tauxInteretDebut = readUserEntry("Taux annuel de l'assurance le plus bas: ");
$tauxInteretFin = readUserEntry("Taux annuel de l'assurance le plus haut: ");

// Convertissement des taux d'intérêt
$tauxAssuranceMensuel = ($tauxAssurance / 100) / 12;

// Calcul du nombre de mois
$nombreMois = $nombreAnnee * 12;

// Simulation des mensualités pour chaque taux d'intérêt
for ($tauxInteret = $tauxInteretDebut; $tauxInteret <= $tauxInteretFin; $tauxInteret += 0.1) {

    // Calcul du taux mensuel
    $tauxMensuel = ($tauxInteret / 100) / 12;
    // Calcul du coût mensuel de l'assurance
    $coutAssuranceMensuel = $capital * $tauxAssuranceMensuel;
    // Calcul de la mensualité (hors assurance)
    $mensualite = $capital * $tauxMensuel * (pow(1 + $tauxMensuel, $nombreMois) / (pow(1 + $tauxMensuel, $nombreMois) - 1));
    // Calcul de la mensualité (avec assurance)
    $coutMensuel = $mensualite + $coutAssuranceMensuel;
    // Calculer le coût total du crédit
    $coutTotal = ($mensualite * $nombreMois) - $capital;
    // Calculer le coût total du crédit en pourcentage
    $coutTotalPourcent = ($coutTotal / $capital) * 100;

    // Affichage des résultats
    echo "Pour un taux d'intérêt mensuel de " . $tauxInteret . " :\n";
    echo "Mensualité (sans assurance) : " . $mensualite . "€\n";
    echo "Mensualité (avec assurance) : " . $coutMensuel . "€\n";
    echo "Coût mensuel de l'assurance : " . $coutAssuranceMensuel . "€\n";
    echo "Coût total du crédit : " . $coutTotal . " (" . $coutTotalPourcent . "%)\n\n";
}

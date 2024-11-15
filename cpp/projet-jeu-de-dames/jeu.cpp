#include "jeu.h"
#include <iostream>
#include <cstdlib>

Jeu::Jeu() : joueur1("Joueur 1", true), joueur2("Joueur 2", false), plateau(&joueur1, &joueur2), joueurCourant(&joueur1) {
    plateau.initialiser();
}

void Jeu::demarrer() {
    while (!verifierFinDePartie()) {
        // On efface la console pour améliorer l'affichage
        clearConsole();

        afficherEtat();
        std::cout << (joueurCourant->estBlanc() ? "Tour du joueur blanc" : "Tour du joueur noir") << std::endl;

        if (!joueurCourant->jouer(plateau)) {
            continue; // Redemande au joueur de jouer en cas de suggestion ou mouvement invalide
        }

        joueurCourant = (joueurCourant == &joueur1) ? &joueur2 : &joueur1;
    }
    std::cout << "Fin de la partie !" << std::endl;
    afficherEtat();
}

void Jeu::clearConsole() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls"); // Commande pour Windows
#else
    system("clear"); // Commande pour Unix/Linux/Mac
#endif
}

bool Jeu::verifierFinDePartie() const {
    // Vérifie si un des joueurs n'a plus de pièces ou plus de mouvements valides
    bool joueur1AucunMouvement = !joueur1.aDesMouvementsValides(plateau);
    bool joueur2AucunMouvement = !joueur2.aDesMouvementsValides(plateau);

    if (joueur1AucunMouvement || joueur2AucunMouvement) {
        std::cout << "Victoire de " << (joueur1AucunMouvement ? joueur2.getNom() : joueur1.getNom()) << "!" << std::endl;
        return true;
    }

    return false;
}

void Jeu::afficherEtat() const {
    plateau.afficher();
}

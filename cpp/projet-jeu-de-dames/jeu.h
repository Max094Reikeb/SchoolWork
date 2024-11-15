#ifndef JEU_H
#define JEU_H

#include "plateau.h"
#include "joueur.h"

class Jeu {
public:
    Jeu();
    void demarrer();
    static void clearConsole();
    bool verifierFinDePartie() const;
    void afficherEtat() const;

private:
    Joueur joueur1;
    Joueur joueur2;
    Plateau plateau;
    Joueur* joueurCourant;
};

#endif

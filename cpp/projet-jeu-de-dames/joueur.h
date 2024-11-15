#ifndef JOUEUR_H
#define JOUEUR_H

#include "position.h"
#include <string>

class Plateau;

class Joueur {
public:
    Joueur(const std::string& nom, bool blanc);
    const std::string& getNom() const { return nom; }
    bool estBlanc() const { return blanc; }

    bool jouer(Plateau& plateau);
    bool aDesMouvementsValides(const Plateau& plateau) const;

private:
    std::string nom;
    bool blanc;
};

#endif

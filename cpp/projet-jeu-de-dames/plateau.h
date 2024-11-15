#ifndef PLATEAU_H
#define PLATEAU_H

#include <vector>
#include "piece.h"
#include "position.h"

class Joueur;

struct Mouvement {
    Position depart;
    Position arrivee;
};

class Plateau {
public:
    Plateau(Joueur* j1, Joueur* j2);
    ~Plateau();

    void initialiser();
    void afficher() const;
    Piece* getPiece(const Position& pos) const;
    bool deplacerPiece(Position depart, Position arrivee);

    Joueur* getJoueur1() const { return joueur1; }
    Joueur* getJoueur2() const { return joueur2; }

    std::vector<Mouvement> genererMouvements(bool joueurBlanc) const;

private:
    std::vector<std::vector<Piece*>> grille;
    Joueur* joueur1;
    Joueur* joueur2;

    bool positionValide(Position pos) const;
    void viderPlateau();
    bool captureDisponible(bool joueurBlanc) const;
};

#endif

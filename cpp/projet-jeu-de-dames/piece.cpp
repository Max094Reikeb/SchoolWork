#include "piece.h"
#include "plateau.h"
#include <cmath>
#include <iostream>

bool Pion::mouvementValide(Position depart, Position arrivee, const Plateau& plateau) const {
    int direction = blanche ? -1 : 1;
    int dx = arrivee.getX() - depart.getX();
    int dy = arrivee.getY() - depart.getY();

    // Logique sur le mouvement simple en diagonale
    if (dy == direction && std::abs(dx) == 1) {
        return true;
    }
    if (roi) {
        // Logique pour les mouvements du roi (diagonale dans les deux sens)
        return std::abs(dx) == std::abs(dy);
    }

    // Vérification pour un mouvement de capture
    if (dy == 2 * direction && std::abs(dx) == 2) {
        // Calculer la position de la pièce entre la position de départ et d'arrivée
        Position positionIntermediaire(depart.getX() + dx / 2, depart.getY() + dy / 2);
        Piece* pieceIntermediaire = plateau.getPiece(positionIntermediaire);

        // La pièce doit être adverse pour que la capture soit valide
        if (pieceIntermediaire != nullptr && pieceIntermediaire->estBlanche() != blanche) {
            return true;
        }
    }
    return false;
}

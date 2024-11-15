#ifndef PIECE_H
#define PIECE_H

#include "position.h"

class Plateau;

class Piece {
public:
    virtual bool mouvementValide(Position depart, Position arrivee, const Plateau& plateau) const = 0;
    bool estRoi() const { return roi; }
    bool estBlanche() const { return blanche; }
    void promouvoir() { roi = true; }
    virtual ~Piece() {}

protected:
    bool blanche;
    bool roi;
};

class Pion : public Piece {
public:
    Pion(bool isWhite) { blanche = isWhite; roi = false; }
    bool mouvementValide(Position depart, Position arrivee, const Plateau& plateau) const override;
};

#endif

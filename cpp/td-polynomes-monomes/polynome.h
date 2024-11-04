#ifndef POLYNOME_H
#define POLYNOME_H

#include "monome.h"
#include <list>

class Polynome {
private:
    std::list<Monome> monomes;

public:
    Polynome();

    void ajouterMonome(const Monome& m);
    bool estVide() const;
    void supprimerMonome(int degre);
    Monome* trouverMonome(int degre);
    void afficher() const;

    static double maxCoefficient(const Polynome& p);
    static double sommeCoefficients(const Polynome& p);
    static Polynome additionner(const Polynome& p1, const Polynome& p2);
    static Polynome derivee(const Polynome& p);
};

#endif

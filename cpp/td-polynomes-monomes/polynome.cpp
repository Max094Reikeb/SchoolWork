#include "polynome.h"
#include <iostream>
#include <algorithm>
using namespace std;

Polynome::Polynome() {}

void Polynome::ajouterMonome(const Monome& m) {
    auto it = monomes.begin();
    while (it != monomes.end() && it->getDegre() < m.getDegre()) {
        ++it;
    }
    monomes.insert(it, m);
}

bool Polynome::estVide() const {
    return monomes.empty();
}

void Polynome::supprimerMonome(int degre) {
    monomes.remove_if([degre](const Monome& m) { return m.getDegre() == degre; });
}

Monome* Polynome::trouverMonome(int degre) {
    for (auto& m : monomes) {
        if (m.getDegre() == degre) {
            return &m;
        }
    }
    return nullptr;
}

void Polynome::afficher() const {
    for (const auto& m : monomes) {
        cout << "Degré: " << m.getDegre() << ", Coefficient: " << m.getCoefficient() << endl;
    }
}

double Polynome::maxCoefficient(const Polynome& p) {
    double maxCoef = 0;
    for (const auto& m : p.monomes) {
        maxCoef = max(maxCoef, m.getCoefficient());
    }
    return maxCoef;
}

double Polynome::sommeCoefficients(const Polynome& p) {
    double somme = 0;
    for (const auto& m : p.monomes) {
        somme += m.getCoefficient();
    }
    return somme;
}

Polynome Polynome::additionner(const Polynome& p1, const Polynome& p2) {
    Polynome resultat = p1;
    for (const auto& m : p2.monomes) {
        resultat.ajouterMonome(m);
    }
    return resultat;
}

Polynome Polynome::derivee(const Polynome& p) {
    Polynome derivee;
    for (const auto& m : p.monomes) {
        if (m.getDegre() > 0) {
            derivee.ajouterMonome(Monome(m.getDegre() - 1, m.getCoefficient() * m.getDegre()));
        }
    }
    return derivee;
}

#include "monome.h"

Monome::Monome(int degre, double coefficient) : degre(degre), coefficient(coefficient) {}

int Monome::getDegre() const {
    return degre;
}

double Monome::getCoefficient() const {
    return coefficient;
}

void Monome::setDegre(int degre) {
    this->degre = degre;
}

void Monome::setCoefficient(double coefficient) {
    this->coefficient = coefficient;
}

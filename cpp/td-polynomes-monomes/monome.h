#ifndef MONOME_H
#define MONOME_H

class Monome {
private:
    int degre;
    double coefficient;

public:
    Monome(int degre = 0, double coefficient = 0.0);

    int getDegre() const;
    double getCoefficient() const;

    void setDegre(int degre);
    void setCoefficient(double coefficient);
};

#endif

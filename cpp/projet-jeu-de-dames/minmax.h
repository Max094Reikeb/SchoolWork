#ifndef MINIMAX_H
#define MINIMAX_H

#include "plateau.h"
#include "joueur.h"
#include <vector>

struct Node {
    Plateau p;
    std::vector<Node*> fils;

    Node(const Plateau& plateau, bool joueurBlanc);

    ~Node();

    void genererFils(bool joueurBlanc);
};

int eval(const Plateau& p);
bool isLeaf(const Node& n);
int minmax(Node& n, Plateau* p, Joueur* joueur, int profondeur);

#endif

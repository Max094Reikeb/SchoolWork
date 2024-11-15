#include "minmax.h"
#include <iostream>
#include <algorithm>

using namespace std;

Node::Node(const Plateau& plateau, bool joueurBlanc) : p(plateau) {
    genererFils(joueurBlanc);
}

Node::~Node() {
    for (Node* filsNode: fils) {
        delete filsNode;
    }
}

void Node::genererFils(bool joueurBlanc) {
    std::vector<Mouvement> mouvements = p.genererMouvements(joueurBlanc);

    for (const auto& mouvement : mouvements) {
        Plateau nouveauPlateau = p; // Copie le plateau actuel
        if (nouveauPlateau.deplacerPiece(mouvement.depart, mouvement.arrivee)) {
            fils.push_back(new Node(nouveauPlateau, !joueurBlanc)); // Crée un noeud pour l'état futur
        }
    }
}

int eval(const Plateau& p, bool joueurBlanc) {
    int score = 0;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            Position pos(x, y);
            Piece* piece = p.getPiece(pos);

            if (piece != nullptr) {
                int valeurPiece = piece->estRoi() ? 5 : 1;

                // On change le multiplier selon le joueur
                int multiplier = joueurBlanc ? 1 : -1;
                score += piece->estBlanche() ? (multiplier * valeurPiece) : (-multiplier * valeurPiece);
            }
        }
    }
    return score;
}

bool isLeaf(const Node& n) {
    return !n.p.getJoueur1()->aDesMouvementsValides(n.p) || !n.p.getJoueur2()->aDesMouvementsValides(n.p);
}

int minmax(Node& n, Plateau* p, Joueur* joueur, int profondeur) {
    std::cout << "Appel minmax avec profondeur : " << profondeur << std::endl;
    // if (profondeur == 0 || isLeaf(n)) {
    if (profondeur == 0 || n.fils.empty()) {
        return eval(n.p, joueur->estBlanc());
    } else {
        if (joueur->estBlanc()) {
            int maxEval = -100000;
            for (auto node : n.fils) {
                int eval = minmax(*node, p, n.p.getJoueur2(), profondeur - 1);
                if (eval > maxEval) {
                    maxEval = eval;
                    *p = node->p;
                }
            }
            return maxEval;
        } else {
            int minEval = 100000;
            for (auto node : n.fils) {
                int eval = minmax(*node, p, n.p.getJoueur1(), profondeur - 1);
                if (eval < minEval) {
                    minEval = eval;
                    *p = node->p;
                }
            }
            return minEval;
        }
    }
}

#include "plateau.h"
#include "piece.h"
#include <iostream>
#include <cmath>
#include <vector>

Plateau::Plateau(Joueur* j1, Joueur* j2) : grille(10, std::vector<Piece*>(10, nullptr)), joueur1(j1), joueur2(j2) {
    initialiser();
}

Plateau::~Plateau() {
    viderPlateau();
}

void Plateau::viderPlateau() {
    for (auto& row : grille) {
        for (auto& piece : row) {
            if (piece != nullptr) {
                // Si on laisse la ligne ci-dessous, on obtient l'erreur 'EXC_BAD_ACCESS'
                // delete piece;
                piece = nullptr;
            }
        }
    }
}

void Plateau::initialiser() {
    for (int y = 0; y < 4; ++y) {
        for (int x = (y % 2 == 0 ? 1 : 0); x < 10; x += 2) {
            grille[y][x] = new Pion(false); // Pions noirs
        }
    }

    for (int y = 6; y < 10; ++y) {
        for (int x = (y % 2 == 0 ? 1 : 0); x < 10; x += 2) {
            grille[y][x] = new Pion(true); // Pions blancs
        }
    }
}

Piece* Plateau::getPiece(const Position& pos) const {
    return positionValide(pos) ? grille[pos.getY()][pos.getX()] : nullptr;
}

bool Plateau::positionValide(Position pos) const {
    return pos.getX() >= 0 && pos.getX() < 10 && pos.getY() >= 0 && pos.getY() < 10;
}

void Plateau::afficher() const {
    std::cout << "  A B C D E F G H I J" << std::endl;

    for (int y = 0; y < 10; ++y) {
        if (y == 10) {
            std::cout << " ";
        }
        std::cout << 10 - y << " ";

        for (int x = 0; x < 10; ++x) {
            Piece* piece = grille[y][x];
            if (piece == nullptr) {
                std::cout << ". ";
            } else if (piece->estBlanche()) {
                std::cout << (piece->estRoi() ? "W " : "w ");
            } else {
                std::cout << (piece->estRoi() ? "B " : "b ");
            }
        }
        if (y == 10) {
            std::cout << " ";
        }
        std::cout << 10 - y << std::endl;
    }
    std::cout << "  A B C D E F G H I J" << std::endl;
}

bool Plateau::captureDisponible(bool joueurBlanc) const {
    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            Position depart(x, y);
            Piece* piece = getPiece(depart);
            if (piece != nullptr && piece->estBlanche() == joueurBlanc) {
                // Vérifie les mouvements de capture (saut de deux cases en diagonale)
                for (int dx = -2; dx <= 2; dx += 4) {
                    for (int dy = -2; dy <= 2; dy += 4) {
                        Position arrivee(depart.getX() + dx, depart.getY() + dy);
                        if (positionValide(arrivee) && piece->mouvementValide(depart, arrivee, *this)) {
                            Position posCapture((depart.getX() + arrivee.getX()) / 2, (depart.getY() + arrivee.getY()) / 2);
                            Piece* pieceCapture = getPiece(posCapture);
                            // Vérifie si la case intermédiaire contient une pièce adverse pour la capture, et que la case d'arrivée est libre
                            if (pieceCapture != nullptr && pieceCapture->estBlanche() != joueurBlanc && getPiece(arrivee) == nullptr) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Plateau::deplacerPiece(Position depart, Position arrivee) {
    if (!positionValide(depart) || !positionValide(arrivee)) return false;

    Piece* piece = getPiece(depart);
    if (piece == nullptr || !piece->mouvementValide(depart, arrivee, *this)) return false;

    // Vérifie si une capture est disponible pour le joueur
    bool joueurBlanc = piece->estBlanche();
    std::vector<Mouvement> captures = genererMouvements(joueurBlanc);
    if (!captures.empty()) {
        bool captureEffectuee = false;
        for (const auto& mouvement : captures) {
            if (mouvement.depart == depart && mouvement.arrivee == arrivee) {
                captureEffectuee = true;
                break;
            }
        }
        if (!captureEffectuee) {
            std::cout << "Une capture est obligatoire. Veuillez effectuer une capture." << std::endl;
            return false;
        }
    }

    // Capture de la pièce adverse
    int dx = arrivee.getX() - depart.getX();
    int dy = arrivee.getY() - depart.getY();
    if (abs(dx) == 2 && abs(dy) == 2) {
        Position posCapture((depart.getX() + arrivee.getX()) / 2, (depart.getY() + arrivee.getY()) / 2);
        delete grille[posCapture.getY()][posCapture.getX()];
        grille[posCapture.getY()][posCapture.getX()] = nullptr;
    }

    // Déplacement de la pièce
    grille[arrivee.getY()][arrivee.getX()] = piece;
    grille[depart.getY()][depart.getX()] = nullptr;

    // Promotion en roi
    if ((piece->estBlanche() && arrivee.getY() == 0) || (!piece->estBlanche() && arrivee.getY() == 9)) {
        piece->promouvoir();
    }
    return true;
}

std::vector<Mouvement> Plateau::genererMouvements(bool joueurBlanc) const {
    std::vector<Mouvement> mouvements;
    std::vector<Mouvement> captures;

    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            Position depart(x, y);
            Piece *piece = getPiece(depart);
            int direction = joueurBlanc ? -1 : 1;

            if (piece != nullptr && piece->estBlanche() == joueurBlanc) {
                // Générer les mouvements de capture
                for (int dx = -2; dx <= 2; dx += 4) {
                    Position capture(depart.getX() + dx, depart.getY() + direction);
                    Position intermediaire(depart.getX() + dx / 2, depart.getY() + direction / 2);

                    if (positionValide(capture) && positionValide(intermediaire)) {
                        Piece* pieceAdverse = getPiece(intermediaire);
                        if (pieceAdverse != nullptr && pieceAdverse->estBlanche() != joueurBlanc && getPiece(capture) == nullptr) {
                            if (piece->mouvementValide(depart, capture, *this)) {
                                captures.push_back({depart, capture});
                            }
                        }
                    }
                }

                // Générer les mouvements normaux uniquement si aucune capture
                if (captures.empty()) {
                    for (int dx = -1; dx <= 1; dx += 2) {
                        Position arrivee(depart.getX() + dx, depart.getY() + direction);
                        if (positionValide(arrivee) && getPiece(arrivee) == nullptr) {
                            if (piece->mouvementValide(depart, arrivee, *this)) {
                                mouvements.push_back({depart, arrivee});
                            }
                        }
                    }
                }
            }
        }
    }

    // Retourne d'abord les captures, ensuite les mouvements si aucune
    return !captures.empty() ? captures : mouvements;
}

#include "joueur.h"
#include "plateau.h"
#include "position.h"
#include "minmax.h"
#include <iostream>
#include <algorithm>
#include <vector>

Joueur::Joueur(const std::string& nom, bool blanc) : nom(nom), blanc(blanc) {}

bool Joueur::jouer(Plateau& plateau) {
    std::string entree;

    // On lit l'entrée du joueur
    std::cout << ">> minmax-X : suggère un coup avec une profondeur de noeuds X" << std::endl;
    std::cout << ">> axby : joue un coup de AX vers BY" << std::endl;
    std::cout << ">> ";
    std::cin >> entree;

    // On vérifie que l'entrée corresponde au format minmax
    if (entree.rfind("minmax-", 0) == 0) {
        int profondeur = std::stoi(entree.substr(7));

        Plateau plateauDeSuggestion = plateau;
        Node racine(plateau, blanc);
        int score = minmax(racine, &plateauDeSuggestion, this, profondeur);

        // On trouve le coup suggéré en comparant les différences entre les plateaux
        Position suggestionDepart, suggestionArrivee;
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                Position pos(x, y);
                Piece* origine = plateau.getPiece(pos);
                Piece* suggestion = plateauDeSuggestion.getPiece(pos);

                if (origine != suggestion) {
                    if (origine != nullptr && suggestion == nullptr) {
                        suggestionDepart = pos;
                    } else if (origine == nullptr && suggestion != nullptr) {
                        suggestionArrivee = pos;
                    }
                }
            }
        }

        // On affiche le mouvement suggéré
        std::cout << "Mouvement suggéré : "
                  << static_cast<char>('A' + suggestionDepart.getX())
                  << 10 - suggestionDepart.getY()
                  << static_cast<char>('A' + suggestionArrivee.getX())
                  << 10 - suggestionArrivee.getY()
                  << std::endl;

        // On pause
        std::cout << "Pressez n'importe quelle touche pour continuer..." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // On vide le tampon d'entrée
        std::cin.get(); // On attend une entrée

        return false; // Redemande au joueur d'entrer son coup après la suggestion
    }

    // On vérifie si l'entrée est un coup valide (ex: A1A1)
    if (entree.length() != 4) {
        std::cout << "Format de coup invalide." << std::endl;
        return false;
    }

    // Conversion de la saisie en positions de départ et d'arrivée
    int xDepart = std::toupper(entree[0]) - 'A';
    int yDepart = 10 - std::stoi(entree.substr(1, entree[1] == '1' && entree[2] == '0' ? 2 : 1));
    int xArrivee = std::toupper(entree[entree[1] == '1' && entree[2] == '0' ? 3 : 2]) - 'A';
    int yArrivee = 10 - std::stoi(entree.substr(entree[1] == '1' && entree[2] == '0' ? 4 : 3));

    // Vérification des limites du plateau
    if (xDepart < 0 || xDepart >= 10 || yDepart < 0 || yDepart >= 10 ||
        xArrivee < 0 || xArrivee >= 10 || yArrivee < 0 || yArrivee >= 10) {
        std::cout << "Coordonnées en dehors des limites du plateau." << std::endl;
        return false;
    }

    Position depart(xDepart, yDepart);
    Position arrivee(xArrivee, yArrivee);

    // On tente le coup
    if (!plateau.deplacerPiece(depart, arrivee)) {
        std::cout << "Mouvement invalide. Réessayez." << std::endl;
        return false;
    }
    return true;
}

bool Joueur::aDesMouvementsValides(const Plateau& plateau) const {
    // Génère tous les mouvements possibles pour le joueur actuel
    auto mouvements = plateau.genererMouvements(blanc);
    return !mouvements.empty();
}

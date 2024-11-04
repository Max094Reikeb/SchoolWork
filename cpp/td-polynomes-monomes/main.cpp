#include "polynome.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    cout << "Appuyez sur n'importe quelle touche pour continuer...";
    cin.ignore();
    cin.get();
    clearConsole();
}

int main() {
    Polynome p;
    bool polynomeCree = false;
    int choix, degre;
    double coefficient;

    do {
        clearConsole();
        cout << "[===[MENU D'ACTIONS]===]" << endl;
        cout << "1. Créer un polynôme vide" << endl;
        cout << "2. Ajouter un monôme" << endl;
        cout << "3. Supprimer un monôme" << endl;
        cout << "4. Afficher le polynôme" << endl;
        cout << "5. Calculer la somme de deux polynômes" << endl;
        cout << "6. Calculer la derivée d'un polynôme" << endl;
        cout << "0. Quitter" << endl;
        cout << ">> Votre choix: ";
        cin >> choix;
        cin.ignore();

        switch (choix) {
            case 1:
                p = Polynome();
                polynomeCree = true;
                cout << "Polynôme vide créé." << endl;
                pause();
                break;
            case 2:
                if (polynomeCree) {
                    cout << "Entrez le degré: ";
                    cin >> degre;
                    cout << "Entrez le coefficient: ";
                    cin >> coefficient;
                    p.ajouterMonome(Monome(degre, coefficient));
                } else {
                    cout << "Erreur : créez d'abord un polynôme ! (option 1)" << endl;
                }
                pause();
                break;
            case 3:
                if (polynomeCree) {
                    cout << "Entrez le degré du monôme à supprimer: ";
                    cin >> degre;
                    p.supprimerMonome(degre);
                } else {
                    cout << "Erreur : créez d'abord un polynôme ! (option 1)" << endl;
                }
                pause();
                break;
            case 4:
                if (polynomeCree) {
                    p.afficher();
                } else {
                    cout << "Erreur : créez d'abord un polynôme ! (option 1)" << endl;
                }
                pause();
                break;
            case 5: {
                if (polynomeCree) {
                    Polynome p2;
                    cout << "Ajoutez des monômes pour le second polynôme (degré négatif pour arrêter):" << endl;
                    while (true) {
                        cout << "Entrez le degré: ";
                        cin >> degre;
                        if (degre < 0) break;
                        cout << "Entrez le coefficient: ";
                        cin >> coefficient;
                        p2.ajouterMonome(Monome(degre, coefficient));
                    }
                    Polynome resultat = Polynome::additionner(p, p2);
                    cout << "Somme des polynômes:" << endl;
                    resultat.afficher();
                } else {
                    cout << "Erreur : créez d'abord un polynôme ! (option 1)" << endl;
                }
                pause();
                break;
            }
            case 6: {
                if (polynomeCree) {
                    Polynome derivee = Polynome::derivee(p);
                    cout << "Derivée du polynôme:" << endl;
                    derivee.afficher();
                } else {
                    cout << "Erreur : créez d'abord un polynôme ! (option 1)" << endl;
                }
                pause();
                break;
            }
        }
    } while (choix != 0);
    return 0;
}

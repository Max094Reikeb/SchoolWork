#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

class Etudiant{
    public:
    int id;
    string nom;
    string prenom;
    string dateNaissance;
    int filliere;

    void set(int i, string n, string p, string d, int f) {
        id = i;
        nom = n;
        prenom = p;
        dateNaissance = d;
        filliere = f;
    }

    void print() {
        cout << "ID: " << id << ", nom: " << nom << ", prénom: " << prenom << ", date de naissance: " << dateNaissance << ", fillière: " << filliere << endl;
    }
};

int moyenne(int tab[], int length) {
    int somme = 0;
    for (int i = 0; i < length - 1; i++ ) {
        somme = somme + tab[i];
    }
    return somme / length;
}

int main() {
    // On génère un tableau de 30 étudiants
    Etudiant etu[30];
    for(int i=0; i<30; i++) {
        etu[i].set(i, "SURNAME", "Name", "14-10-2024", 3);
    }

    // On génère 30 notes aléatoires dans un fichier
    ofstream MonFichier("notes.txt");
    for(int i=0; i<30; i++) {
        MonFichier << rand() % 20 << endl;
    }
    MonFichier.close();

    // Lire le fichier et faire un tableau des notes
    int notes[30];
    int j = 0;
    string ligne;
    ifstream MyFile("notes.txt");
    if (MyFile.is_open()) {
        while (getline(MyFile,ligne)) {
            notes[j] = atoi(ligne.c_str());
            j++;
        }
        MyFile.close();
    } else {
        cout << "Unable to open file";
    }

    // Obtenir la moyenne des notes
    int moy = moyenne(notes, 30);
    cout << "La moyenne des notes est: " << moy << endl;

    return 0;
}

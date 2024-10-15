#include <iostream>
using namespace std;

class Etudiant{
    public:
    int id;
    string nom;
    void set(int i, string s) {
        id = i;
        nom = s;
    }

    void print() {
        cout << "Nom: " << nom << ", id: " << id << endl;
    }
};

int main() {
    Etudiant e1, e2;
    e1.set(102, "Ali");
    e2.set(103, "Georges");
    e1.print();
    return 0;
}

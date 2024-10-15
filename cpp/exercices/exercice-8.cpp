#include <iostream>
using namespace std;

int getSomme(const int myTab[], int length, int i = 0, int s = 0) {
    if (i == length) {
        return s;
    }
    s += myTab[i];
    return getSomme(myTab, length, i + 1, s);
}

int main() {
    int LENGTH = 15;
    int myTab[LENGTH];
    for(int i=0; i<LENGTH; i++) {
        myTab[i] = rand() % 20;
        cout << myTab[i] << endl;
    }
    int somme = getSomme(myTab, LENGTH);
    cout << "La somme des nombres du tableau est: " << somme << endl;
    return 0;
}

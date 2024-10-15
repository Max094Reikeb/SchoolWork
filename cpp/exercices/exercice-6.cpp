#include <iostream>
using namespace std;

int main() {
    int DIM = 5;
    int a, b;
    a = 2;
    b = 5;
    int *pa, *pb;
    pa = &a;
    pb = &b;
    int montab[DIM];

    // 1. Afficher les valeurs de a et b
    cout << "a = " << a << " et b = " << b << endl;

    // 2. Afficher les adresses de a et b en n'utilisant que pa et pb
    cout << "l'adresse de a est: " << pa << " et l'adresse de pb est: " << pb << endl;

    // 3. Afficher les valeurs de a et b en n'utilisant que pa et pb
    cout << "a = " << *pa << " et b = " << *pb << endl;

    return 0;
}

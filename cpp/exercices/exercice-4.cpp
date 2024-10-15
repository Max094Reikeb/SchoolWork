#include <iostream>
using namespace std;

bool isPrime(int number) {
    if (number <= 1) { return false; }

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) { return false; }
    }

    return true;
}

bool isPerfect(int number) {
    if (number == 1) { return true; }
    if (isPrime(number)) { return false; }

    int somme = 0;
    for(int i = 1; i < number; i++) {
        if (number % i == 0) {
            somme += i;
        }
    }

    return somme == number;
}

int main() {
    int number;
    cout << "Entrez un nombre : ";
    cin >> number;
    if (isPerfect(number)) {
        cout << "Le nombre que vous avez entré est parfait !" << endl;
    } else {
        cout << "Le nombre que vous avez entré n'est pas un nombre parfait." << endl;
    }
    return 0;
}

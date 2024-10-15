#include <iostream>
using namespace std;

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

bool whilePrime(int number) {
    if (number <= 1) {
        return false;
    }

    int i = 2;
    while(i * i <= number && number % i == 0) {
        i++;
    }
    return i * i == number;
}

int main() {
    int number;
    cout << "Entrez un nombre : ";
    cin >> number;
    if (isPrime(number)) {
        cout << "Le nombre que vous avez entré est premier !" << endl;
    } else {
        cout << "Le nombre que vous avez entré n'est pas un nombre premier." << endl;
    }
    return 0;
}

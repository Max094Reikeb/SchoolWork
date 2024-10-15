#include <iostream>
using namespace std;

int myAdd(int a, int b) {
    return a+b;
}

int mySub(int a, int b) {
    return a-b;
}

int myMult(int a, int b) {
    return a*b;
}

int myDiv(int a, int b) {
    return a/b;
}

int main() {
    int a,b;
    cout << "Entrez le premier nombre (a): ";
    cin >> a;
    cout << "Entrez le deuxième nombre (b): ";
    cin >> b;
    int sum = myAdd(a, b);
    int sub = mySub(a, b);
    int mult = myMult(a, b);
    int div = myDiv(a, b);
    cout << "Résultats :" << endl;
    cout << "a + b = " << sum << endl;
    cout << "a - b = " << sub << endl;
    cout << "a * b = " << mult << endl;
    cout << "a / b = " << div << endl;
    return 0;
}

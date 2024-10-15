#include <iostream>
using namespace std;

int main() {
    int j,m,a;
    cout << "Entrez votre jour de naissance (01 - 31): ";
    cin >> j;
    cout << "Entrez votre mois de naissance (01 - 12): ";
    cin >> m;
    cout << "Entrez votre année de naissance (1900 - 2024): ";
    cin >> a;
    printf("Votre date de naissance est : %02d/%02d/%d\n", j, m, a);
    return 0;
}

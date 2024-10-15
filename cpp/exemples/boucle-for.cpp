#include <iostream>
using namespace std;

int main() {
    int a=5, b=0;
    for (int i=0; i<a;i++) {
        b=b+(i*2);
    }
    cout << "la valeur de b est " << b;
    return 0;
}

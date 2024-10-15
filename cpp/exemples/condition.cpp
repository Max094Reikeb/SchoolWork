#include <iostream>
using namespace std;

int main() {
    int a=5, b=2;
    if (a < b) {
        cout << a << " est plus petit que " << b;
    } else if (b < a) {
        cout << b << " est plus petit que " << a;
    } else {
        cout << a << " est égal à " << b;
    }
    return 0;
}

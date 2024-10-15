#include <iostream>
using namespace std;

int myAdd(int a, int b) {
    return a+b;
}

int main() {
    int a=5, b=2;
    int c = myAdd(a, b);
    int d = myAdd(4, 7);
    cout << "somme 1 = " << c << " some 2 = " << d;
    return 0;
}

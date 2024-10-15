#include <iostream>
using namespace std;

int main() {
    int a=5, b=2;
    int c;
    while(a >= b) {
        a = a-1;
    }
    cout << "b: " << b << " est plus grand que a: " << a;
    return 0;
}

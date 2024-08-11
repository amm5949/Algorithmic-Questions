#include <iostream>
using namespace std;

int gcd_recursive(int x, int y) {
    if (y == 0) {
        return x;
    }
    else {
        return gcd_recursive(y, x % y);
    }
}

int main () {
    int x, y;
    cin >> x >> y;
    int gcd = gcd_recursive(x, y);
    if (gcd < 0) {
        gcd = gcd * (-1);
    }
    cout << gcd << endl;
    return 0;
}
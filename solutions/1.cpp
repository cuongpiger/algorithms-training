#include <iostream>
using namespace std;

inline int sumDigits(int n, int b) {
    int a = 0, s = 0;

    do {
        s += n % b;
        n /= b;
    } while (n != 0);

    return s;
}

int GCD(int a, int b) { 
    return !b ? a : GCD(b, a % b); 
}


int main() {
    int x;
    int num = 0;
    
    cin >> x;

    for (int i = 2; i < x; ++i) {
        num += sumDigits(x, i);
    }

    int gcd = GCD(num, x - 2);
    cout << (num / gcd) << "/" << ((x - 2) / gcd);

    return 0;
}
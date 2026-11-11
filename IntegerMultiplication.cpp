#include <iostream>
#include <algorithm>
using namespace std;

int digitCount(long long x) {
    int d = 0;
    do {
        d++;
        x /= 10;
    } while (x > 0);
    return d;
}

long long power10(int k) {
    long long p = 1;
    while (k--) p *= 10;
    return p;
}

long long karatsuba(long long x, long long y) {
    if (x < 10 || y < 10)
        return x * y;

    int n = max(digitCount(x), digitCount(y));
    int half = n / 2;
    long long p = power10(half);

    long long a = x / p, b = x % p;   // x = a * 10^half + b
    long long c = y / p, d = y % p;   // y = c * 10^half + d

    long long z0 = karatsuba(b, d);
    long long z2 = karatsuba(a, c);
    long long z1 = karatsuba(a + b, c + d) - z2 - z0;

    return z2 * p * p + z1 * p + z0;
}

int main() {
    long long x, y;
    cout << "Enter the first integer: ";
    cin >> x;
    cout << "Enter the second integer: ";
    cin >> y;

    if (x < 0 || y < 0) {
        cout << "Please enter non-negative integers.\n";
        return 0;
    }

    cout << "\nProduct (Karatsuba): " << karatsuba(x, y) << "\n";
    cout << "Product (check):     " << x * y << "\n";
    return 0;
}
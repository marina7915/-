#include <iostream>
using namespace std;

long long fib(int n) {
    long long a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        long long t = a + b;
        a = b;
        b = t;
    }
    return a;
}

long long fact(int n) {
    long long r = 1;
    for (int i = 2; i <= n; ++i) r *= i;
    return r;
}

void divisors(int n) {
    int i = 1;
    for (; i * i <= n; ++i)          // малые делители
        if (n % i == 0) cout << i << ' ';
    for (--i; i >= 1; --i)           // парные большие делители
        if (n % i == 0 && i != n / i) cout << n / i << ' ';
}

int main() {
    int n;
    cout << "Введите число: ";
    cin >> n;

    cout << "Фибоначчи: " << fib(n) << '\n';
    cout << "Факториал: " << fact(n) << '\n';
    cout << "Делители: ";
    divisors(n);
    return 0;
}
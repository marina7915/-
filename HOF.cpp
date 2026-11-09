#include <iostream>
using namespace std;

double itemCost(double price, int qty) {
    return price * qty;
}

double total(int n, double (*cost)(double, int)) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        double price;
        int qty;
        cout << "Позиция " << i + 1 << ": введите цену и количество: ";
        cin >> price >> qty;
        sum += cost(price, qty);
    }
    return sum;
}

int main() {
    int n;
    cout << "Сколько позиций: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Введите положительное количество позиций.\n";
        return 1;
    }
    cout << "Итого: " << total(n, itemCost);
    return 0;
}
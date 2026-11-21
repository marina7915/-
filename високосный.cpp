#include <iostream>
using namespace std;

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    int year;
    cout << "Введите год: ";
    cin >> year;

    if (isLeap(year)) {
        cout << "Високосный";
    } else {
        cout << "Не високосный";
    }

    return 0;
}
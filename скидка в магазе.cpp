#include <iostream>
using namespace std;

int main() {
    int age, stock;
    double sum;
    bool promo, blocked, marked;

    cin >> age >> sum >> promo >> blocked >> marked >> stock;

    if (blocked) {
        cout << "Аккаунт заблокирован";
    } else if (age < 18 && marked) {
        cout << "Отказ: возрастное ограничение";
    } else if (stock <= 0) {
        cout << "Отказ: нет товара на складе";
    } else {
        int d = 0;
        if (sum >= 10000) d = 15;
        else if (sum >= 5000 && promo) d = 10;

        cout << "Заказ оформлен. Скидка: " << d << "%\n";
        cout << "К оплате: " << sum * (100 - d) / 100;
    }
    return 0;
}
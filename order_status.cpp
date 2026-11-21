#include <iostream>
using namespace std;

struct Order {
    int id;
    double total;
    int status;
};

bool canChangeStatus(int from, int to) {
    if (from == 1 && (to == 2 || to == 5))
        return true;
    else if (from == 2 && (to == 3 || to == 5))
        return true;
    else if (from == 3 && to == 4)
        return true;
    else
        return false;
}

bool changeStatus(Order& order, int newStatus) {
    if (canChangeStatus(order.status, newStatus)) {
        order.status = newStatus;
        return true;
    } else {
        return false;
    }
}

const char* statusName(int status) {
    if (status == 1) return "создан";
    else if (status == 2) return "оплачен";
    else if (status == 3) return "отправлен";
    else if (status == 4) return "доставлен";
    else if (status == 5) return "отменён";
    else return "неизвестен";
}

int main() {
    Order order = {1001, 2500.0, 1};

    cout << "Заказ №" << order.id
         << ", сумма: " << order.total << '\n';

    int steps[] = {2, 3, 4};

    for (int i = 0; i < 3; i++) {
        if (changeStatus(order, steps[i])) {
            cout << "Статус изменён: "
                 << statusName(order.status) << '\n';
        } else {
            cout << "Переход запрещён\n";
        }
    }

    if (!changeStatus(order, 5)) {
        cout << "Нельзя изменить статус завершённого заказа\n";
    }

    return 0;
}
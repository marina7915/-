#include <cstdint>
#include <iostream>

enum class Status : std::uint8_t {
    Created,
    Paid,
    Shipped,
    Delivered,
    Cancelled
};

struct Order {
    std::uint32_t id;
    double total;
    Status status;
};

bool canChangeStatus(Status from, Status to) {
    switch (from) {
        case Status::Created:
            return to == Status::Paid || to == Status::Cancelled;
        case Status::Paid:
            return to == Status::Shipped || to == Status::Cancelled;
        case Status::Shipped:
            return to == Status::Delivered;
        case Status::Delivered:
        case Status::Cancelled:
            return false;
    }
    return false;
}

bool changeStatus(Order& order, Status newStatus) {
    if (!canChangeStatus(order.status, newStatus)) {
        return false;
    }

    order.status = newStatus;
    return true;
}

const char* statusName(Status status) {
    switch (status) {
        case Status::Created:   return "создан";
        case Status::Paid:      return "оплачен";
        case Status::Shipped:   return "отправлен";
        case Status::Delivered: return "доставлен";
        case Status::Cancelled: return "отменён";
    }
    return "неизвестен";
}

int main() {
    Order order{1001, 2500.0, Status::Created};

    std::cout << "Заказ №" << order.id << ", сумма: " << order.total << '\n';

    const Status steps[] = {
        Status::Paid,
        Status::Shipped,
        Status::Delivered
    };

    for (Status nextStatus : steps) {
        if (changeStatus(order, nextStatus)) {
            std::cout << "Статус изменён: " << statusName(order.status) << '\n';
        } else {
            std::cout << "Переход запрещён\n";
        }
    }

    if (!changeStatus(order, Status::Cancelled)) {
        std::cout << "Нельзя изменить статус завершённого заказа\n";
    }

    return 0;
}

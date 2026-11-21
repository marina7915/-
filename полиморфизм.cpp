#include <iostream>
using namespace std;

class Transport {
public:
    virtual ~Transport() = default;
    virtual double travelTime(double distance) const = 0;
    virtual void printInfo() const = 0;
};

class Car : public Transport {
private:
    double speed;

public:
    explicit Car(double carSpeed) : speed(carSpeed) {}

    double travelTime(double distance) const override {
        return distance / speed;
    }

    void printInfo() const override {
        cout << "Автомобиль, скорость: " << speed << " км/ч";
    }
};

class Bicycle : public Transport {
private:
    double speed;

public:
    explicit Bicycle(double bicycleSpeed) : speed(bicycleSpeed) {}

    double travelTime(double distance) const override {
        return distance / speed;
    }

    void printInfo() const override {
        cout << "Велосипед, скорость: " << speed << " км/ч";
    }
};

class Plane : public Transport {
private:
    double speed;

public:
    explicit Plane(double planeSpeed) : speed(planeSpeed) {}

    double travelTime(double distance) const override {
        return distance / speed;
    }

    void printInfo() const override {
        cout << "Самолёт, скорость: " << speed << " км/ч";
    }
};

void showTravel(const Transport& transport, double distance) {
    transport.printInfo();
    cout << " -> время в пути: " << transport.travelTime(distance) << " ч\n";
}

int main() {
    Car car(90);
    Bicycle bicycle(20);
    Plane plane(800);

    showTravel(car, 180);
    showTravel(bicycle, 40);
    showTravel(plane, 1600);

    return 0;
}

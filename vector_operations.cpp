#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class Vector {
public:
    explicit Vector(std::size_t size) : values(size) {}

    std::size_t size() const {
        return values.size();
    }

    T& operator[](std::size_t index) {
        return values[index];
    }

    const T& operator[](std::size_t index) const {
        return values[index];
    }

private:
    std::vector<T> values;
};

template <typename T>
Vector<T> operator+(const Vector<T>& left, const Vector<T>& right) {
    if (left.size() != right.size()) {
        throw std::invalid_argument("Размеры векторов должны совпадать");
    }

    Vector<T> result(left.size());
    for (std::size_t i = 0; i < left.size(); ++i) {
        result[i] = left[i] + right[i];
    }
    return result;
}

template <typename T>
Vector<T> operator*(T scalar, const Vector<T>& vector) {
    Vector<T> result(vector.size());
    for (std::size_t i = 0; i < vector.size(); ++i) {
        result[i] = scalar * vector[i];
    }
    return result;
}

template <typename T>
Vector<T> operator*(const Vector<T>& vector, T scalar) {
    return scalar * vector;
}

template <typename T>
std::ostream& operator<<(std::ostream& output, const Vector<T>& vector) {
    output << "(";
    for (std::size_t i = 0; i < vector.size(); ++i) {
        if (i > 0) {
            output << ", ";
        }
        output << vector[i];
    }
    output << ")";
    return output;
}

template <typename T>
bool operator==(const Vector<T>& left, const Vector<T>& right) {
    if (left.size() != right.size()) {
        return false;
    }

    for (std::size_t i = 0; i < left.size(); ++i) {
        if (left[i] != right[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool operator!=(const Vector<T>& left, const Vector<T>& right) {
    return !(left == right);
}

template <typename T>
double norm(const Vector<T>& vector) {
    double sum = 0;
    for (std::size_t i = 0; i < vector.size(); ++i) {
        const double value = static_cast<double>(vector[i]);
        sum += value * value;
    }
    return std::sqrt(sum);
}

int main() {
    std::size_t size;
    std::cout << "Введите размер векторов: ";
    if (!(std::cin >> size)) {
        return 1;
    }

    Vector<double> first(size);
    Vector<double> second(size);

    std::cout << "Введите элементы первого вектора: ";
    for (std::size_t i = 0; i < size; ++i) {
        std::cin >> first[i];
    }

    std::cout << "Введите элементы второго вектора: ";
    for (std::size_t i = 0; i < size; ++i) {
        std::cin >> second[i];
    }

    double scalar;
    std::cout << "Введите скаляр: ";
    std::cin >> scalar;

    std::cout << "Сумма: " << first + second << '\n';
    std::cout << "Умножение на скаляр: " << scalar * first << '\n';
    std::cout << "Первый вектор: " << first << '\n';
    std::cout << "Векторы равны: " << (first == second ? "да" : "нет") << '\n';
    std::cout << "Норма первого вектора: " << norm(first) << '\n';

    return 0;
}

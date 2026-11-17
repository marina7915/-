#include <cstddef>
#include <iostream>
#include <utility>

class IntArray {
public:
    explicit IntArray(std::size_t size)
        : size_(size), data_(size == 0 ? nullptr : new int[size]{}) {}

    ~IntArray() {
        delete[] data_;
    }

    IntArray(const IntArray& other)
        : size_(other.size_), data_(size_ == 0 ? nullptr : new int[size_]) {
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    IntArray& operator=(const IntArray& other) {
        if (this != &other) {
            int* newData = other.size_ == 0 ? nullptr : new int[other.size_];
            for (std::size_t i = 0; i < other.size_; ++i) {
                newData[i] = other.data_[i];
            }

            delete[] data_;
            data_ = newData;
            size_ = other.size_;
        }
        return *this;
    }

    IntArray(IntArray&& other) noexcept
        : size_(other.size_), data_(other.data_) {
        other.size_ = 0;
        other.data_ = nullptr;
    }

 
    IntArray& operator=(IntArray&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = other.data_;
            other.size_ = 0;
            other.data_ = nullptr;
        }
        return *this;
    }

    int& operator[](std::size_t index) {
        return data_[index];
    }

    const int& operator[](std::size_t index) const {
        return data_[index];
    }

    std::size_t size() const noexcept {
        return size_;
    }

private:
    std::size_t size_;
    int* data_;
};

int main() {
    std::size_t count;
    std::cout << "Введите размер массива: ";
    if (!(std::cin >> count)) {
        return 1;
    }

    IntArray numbers(count);

    std::cout << "Введите элементы массива: ";
    for (std::size_t i = 0; i < numbers.size(); ++i) {
        if (!(std::cin >> numbers[i])) {
            return 1;
        }
    }

    std::cout << "Массив: ";
    for (std::size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << ' ';
    }
    std::cout << "\nРазмер: " << numbers.size() << '\n';

    IntArray copied(numbers); 
    IntArray moved(std::move(copied)); 

    return 0;
}

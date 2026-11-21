#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    // Создаем новый вектор только для неотрицательных чисел
    std::vector<int> filtered;
    for (int i = 0; i < n; ++i) {
        if (numbers[i] >= 0) {
            filtered.push_back(numbers[i]);
        }
    }

    // Сортировка пузырьком
    int size = filtered.size();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (filtered[j] > filtered[j + 1]) {
                int temp = filtered[j];
                filtered[j] = filtered[j + 1];
                filtered[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << filtered[i];
    }
    std::cout << '\n';

    return 0;
}

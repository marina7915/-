#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int& number : numbers) {
        std::cin >> number;
    }

    numbers.erase(
        std::remove_if(numbers.begin(), numbers.end(),
                       [](int number) { return number < 0; }),
        numbers.end());

    std::sort(numbers.begin(), numbers.end());

    for (std::size_t i = 0; i < numbers.size(); ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << numbers[i];
    }
    std::cout << '\n';

    return 0;
}

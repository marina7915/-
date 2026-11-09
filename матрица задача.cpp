#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

long long sumByRows(const vector<vector<int>>& matrix, int n) {
    long long sum = 0;

    for (int row = 0; row < n; ++row)
        for (int col = 0; col < n; ++col)
            sum += matrix[row][col];

    return sum;
}

long long sumByColumns(const vector<vector<int>>& matrix, int n) {
    long long sum = 0;

    for (int col = 0; col < n; ++col)//по столбцам
        for (int row = 0; row < n; ++row)
            sum += matrix[row][col];

    return sum;
}

int main() {
    int n;
    cout << "Введите размер матрицы n: ";

    if (!(cin >> n) || n <= 0) {
        cout << "Размер должен быть положительным числом.\n";
        return 1;
    }

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int row = 0; row < n; ++row)// по строкам
        for (int col = 0; col < n; ++col)
            matrix[row][col] = (row * n + col) % 100;

    const int repetitions = 5;
    volatile long long rowsChecksum = 0;
    volatile long long columnsChecksum = 0;

    auto start = chrono::steady_clock::now();
    for (int i = 0; i < repetitions; ++i)
        rowsChecksum = rowsChecksum + sumByRows(matrix, n);
    auto rowsTime = chrono::steady_clock::now() - start;

    start = chrono::steady_clock::now();
    for (int i = 0; i < repetitions; ++i)
        columnsChecksum = columnsChecksum + sumByColumns(matrix, n);
    auto columnsTime = chrono::steady_clock::now() - start;

    cout << fixed << setprecision(3);
    cout << "Сумма по строкам:   " << sumByRows(matrix, n) << '\n';
    cout << "Сумма по столбцам:  " << sumByColumns(matrix, n) << '\n';
    cout << "Среднее время по строкам:  "
         << chrono::duration<double, milli>(rowsTime).count() / repetitions << " мс\n";
    cout << "Среднее время по столбцам: "
         << chrono::duration<double, milli>(columnsTime).count() / repetitions << " мс\n";
}
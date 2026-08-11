#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

Matrix multiply(const Matrix &a, const Matrix &b) {
    int rowsA = a.size(), colsA = a[0].size();
    int colsB = b[0].size();

    Matrix result(rowsA, std::vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

void printMatrix(const Matrix &m) {
    for (const auto &row : m) {
        for (int val : row) std::cout << val << " ";
        std::cout << "\n";
    }
}

int main() {
    Matrix a = {{1, 2}, {3, 4}};
    Matrix b = {{5, 6}, {7, 8}};

    Matrix result = multiply(a, b);
    printMatrix(result);

    return 0;
}
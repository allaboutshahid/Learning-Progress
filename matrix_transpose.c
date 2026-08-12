#include <stdio.h>

#define ROWS 3
#define COLS 4

void transpose(int src[ROWS][COLS], int dest[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            dest[j][i] = src[i][j];
        }
    }
}

void printMatrix(int rows, int cols, int mat[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int result[COLS][ROWS];

    transpose(matrix, result);
    printMatrix(COLS, ROWS, result);

    return 0;
}
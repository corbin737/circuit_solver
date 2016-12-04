#include <stdio.h>
#include "matrix.h"

void printMatrix(int rows, int cols, const double matrix[rows][cols]) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("%.2f ", matrix[r][c]);
        }
        printf("\n");
    }
}

int main(void)
{
    double matrix[3][3] = {
        {0, 0, 0},
        {0, 1.0, 0},
        {1.0, 0, 0}
    };
    const int rows = 3;
    const int cols = 3;

    printMatrix(rows, cols, matrix);
    printf("Upper triangular...\n");
    upperTriangular(rows, cols, matrix);
    printMatrix(rows, cols, matrix);


    return 0;
}

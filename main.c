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
    double matrix[4][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
        {10.0, 11.0, 12.0}
    };
    const int rows = 4;
    const int cols = 3;

    printMatrix(rows, cols, matrix);
    printf("Row reduce...\n");
    rowReduce(rows, cols, matrix);
    printMatrix(rows, cols, matrix);


    return 0;
}

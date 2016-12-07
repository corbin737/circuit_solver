#include <assert.h>
#include <math.h>
#include "matrix.h"

const double epsilon = 0.00001;

// Swaps row i and row j
void eroType1(int rows, int cols, double matrix[rows][cols], int i, int j) {
    if (i == j) return;
    double temp;
    for (int c = 0; c < cols; c++) {
        temp = matrix[i][c];
        matrix[i][c] = matrix[j][c];
        matrix[j][c] = temp;
    }
}

// Multiplies every entry in row i by k
// k cannot equal 0
void eroType2(int rows, int cols, double matrix[rows][cols], int i, double k) {
    assert(k != 0);
    for (int c = 0; c < cols; c++)
        matrix[i][c] *= k;
}

// Adds k times row j to row i
// i cannot equal j
void eroType3(int rows, int cols, double matrix[rows][cols], int i, int j, double k) {
    assert(i != j);
    for (int c = 0; c < cols; c++)
        matrix[i][c] += k * matrix[j][c];
}

// Converts matrix into RREF form
void rowReduce(int rows, int cols, double matrix[rows][cols]) {
    int pivotRow = 0;
    for (int c = 0; c < cols; c++) {
        int r = pivotRow;
        while (r < rows && fabs(matrix[r][c]) < epsilon)
            r++;
        if (r == rows) continue;
        eroType1(rows, cols, matrix, r, pivotRow);
        eroType2(rows, cols, matrix, pivotRow, 1.0 / matrix[pivotRow][c]);
        for (r = 0; r < rows; r++) {
            if (r == pivotRow) continue;
            eroType3(rows, cols, matrix, r, pivotRow, -1.0 * matrix[r][c]);
        }
        pivotRow++;
    }
}

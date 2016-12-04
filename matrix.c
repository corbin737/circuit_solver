#include <assert.h>
#include <stdbool.h>
#include "matrix.h"

// Swaps row i and row j
void eroType1(int rows, int cols, double matrix[rows][cols], int i, int j) {
    if (i == j) return;
    int temp;
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

void upperTriangular(int rows, int cols, double matrix[rows][cols]) {
    double pivot, curr;
    // last column needs no modification
    for (int c = 0; c < cols - 1; c++) {
        pivot = matrix[c][c];
        if (pivot == 0) {
            bool foundNonZero = false;
            // here c is used as the row number of the pivot
            for (int r = c + 1; r < rows; r++) {
                if (matrix[r][c] != 0) {
                    // c is pivot row
                    eroType1(rows, cols, matrix, r, c);
                    pivot = matrix[c][c];
                    foundNonZero = true;
                }
            }
            if (!foundNonZero) continue;
        }
        for (int r = c + 1; r < rows; r++) {
            curr = matrix[r][c];
            // c is pivot row
            eroType3(rows, cols, matrix, r, c, -1.0 * curr / pivot);
        }
    }
}

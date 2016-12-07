#include <stdbool.h>
#include "matrix.h"
#include "circuit.h"

// Calculates node voltages of a given circuit
void nodeVoltages(Element circuit[], int n, int nodes, double voltages[]) {
    int vSources = 0;
    for (int i = 0; i < n; i++)
        if (circuit[i].type == VoltageSource) vSources++;

    // Matrix layout:
    /*                      v0 | v1 | v2 | ... | nodes (i0) | i1 | i2 | ... | const
     *                   --------------------------------------------------------------
     * Nodes         |
     * 0                |
     * 1                |
     * ...               |
     * nodes (s0)   |
     * s1               |
     * s2               |
     * ...               |
     * ground        |
     */
    const int dimension = nodes + vSources + 1;
    double matrix[dimension][dimension];
    for (int r = 0; r < dimension; r++)
        for (int c = 0; c < dimension; c++)
            matrix[r][c] = 0.0;

    int vSourceIndex = 0;
    for (int i = 0; i < n; i++) {
        Element e = circuit[i];
        switch (e.type) {
        case Resistor:
            matrix[e.beg][e.beg] += 1.0 / e.value;
            matrix[e.beg][e.end] += -1.0 / e.value;
            matrix[e.end][e.end] += 1.0 / e.value;
            matrix[e.end][e.beg] += -1.0 / e.value;
            break;
        case VoltageSource:
            matrix[e.beg][nodes + vSourceIndex] += 1.0;
            matrix[e.end][nodes + vSourceIndex] += -1.0;
            matrix[nodes + vSourceIndex][e.end] = 1.0;
            matrix[nodes + vSourceIndex][e.beg] = -1.0;
            matrix[nodes + vSourceIndex][dimension - 1] = e.value;
            vSourceIndex++;
            break;
        case CurrentSource:
            matrix[e.beg][dimension - 1] += -e.value;
            matrix[e.end][dimension - 1] += e.value;
            break;
        default:
            break;
        }
    }

    // Pick arbitrary ground as first node
    matrix[dimension - 1][0] = 1.0;

    rowReduce(dimension, dimension, matrix);

    for (int r = 0; r < dimension; r++) {
        for (int c = 0; c < dimension; c++)
            printf("%.2f ", matrix[r][c]);
        printf("\n");
    }

    for (int node = 0; node < nodes; node++) {
        voltages[node] = matrix[node][dimension - 1];
    }
}

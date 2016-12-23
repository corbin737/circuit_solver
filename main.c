#include <stdio.h>
#include "matrix.h"
#include "circuit.h"

int main(void)
{
    Element s0, s1, s2, s3, r0, r1, r2, r3, r4;

    s0.type = CurrentSource;
    s0.value = 1.0;
    s0.beg = 0;
    s0.end = 1;

    s1.type = CDepVoltageSource;
    s1.value = 4.0;
    s1.beg = 1;
    s1.end = 2;
    s1.dependencyIndex = 6; // R2

    s2.type = VDepCurrentSource;
    s2.value = 2.0;
    s2.beg = 3;
    s2.end = 2;
    s2.dependencyIndex = 8; // R4

    s3.type = VoltageSource;
    s3.value = 10.0;
    s3.beg = 0;
    s3.end = 4;

    r0.type = Resistor;
    r0.value = 4.0;
    r0.beg = 1;
    r0.end = 0;

    r1.type = Resistor;
    r1.value = 1.0;
    r1.beg = 2;
    r1.end = 0;

    r2.type = Resistor;
    r2.value = 4.0;
    r2.beg = 3;
    r2.end = 0;

    r3.type = Resistor;
    r3.value = 2.0;
    r3.beg = 4;
    r3.end = 3;

    r4.type = Resistor;
    r4.value = 1.0;
    r4.beg = 1;
    r4.end = 3;

    Element circuit[] = {s0, s1, s2, s3, r0, r1, r2, r3, r4};
    const int n = 9;
    const int nodes = 5;

    double voltages[n];
    nodeVoltages(circuit, n, nodes, voltages);
    for (int i = 0; i < nodes; i++) {
        printf("Node %d: %.3f\n", i, voltages[i]);
    }

    return 0;
}

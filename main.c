#include <stdio.h>
#include "matrix.h"
#include "circuit.h"

int main(void)
{
    Element s1, s2, s3, r1, r2, r3, r4, r5, r6;

    s1.beg = 0;
    s1.end = 1;
    s1.type = CurrentSource;
    s1.value = 5.0;

    s2.beg = 1;
    s2.end = 3;
    s2.type = CurrentSource;
    s2.value = 3.0;

    s3.beg = 0;
    s3.end = 4;
    s3.type = VoltageSource;
    s3.value = 12.0;

    r1.beg = 1;
    r1.end = 0;
    r1.type = Resistor;
    r1.value = 4.0;

    r2.beg = 1;
    r2.end = 2;
    r2.type = Resistor;
    r2.value = 8.0;

    r3.beg = 0;
    r3.end = 2;
    r3.type = Resistor;
    r3.value = 2.0;

    r4.beg = 2;
    r4.end = 3;
    r4.type = Resistor;
    r4.value = 4.0;

    r5.beg = 3;
    r5.end = 4;
    r5.type = Resistor;
    r5.value = 8.0;

    r6.beg = 1;
    r6.end = 3;
    r6.type = Resistor;
    r6.value = 2.0;

    Element circuit[] = {s1, s2, s3, r1, r2, r3, r4, r5, r6};
    const int n = 9;
    const int nodes = 5;
    double voltages[n];

    nodeVoltages(circuit, n, nodes, voltages);

    for (int i = 0; i < nodes; i++) {
        printf("Node %d: %.3f\n", i, voltages[i]);
    }



    return 0;
}

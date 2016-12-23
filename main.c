#include <stdio.h>
#include <string.h>
#include "matrix.h"
#include "circuit.h"

int main(void)
{
    int n;
    scanf("%d", &n);

    Element circuit[n];

    char type[5];
    double value;
    int beg, end;
    int depIndex;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &value);
        scanf("%s", type);
        if (strcmp(type, "R") == 0) {
            circuit[i].type = Resistor;
            circuit[i].dependencyIndex = -1;
        } else if (strcmp(type, "VS") == 0) {
            circuit[i].type = VoltageSource;
            circuit[i].dependencyIndex = -1;
        } else if (strcmp(type, "CS") == 0) {
            circuit[i].type = CurrentSource;
            circuit[i].dependencyIndex = -1;
        } else if (strcmp(type, "VDVS") == 0) {
            circuit[i].type = VDepVoltageSource;
            scanf(" (%d)", &depIndex);
            circuit[i].dependencyIndex = depIndex;
        } else if (strcmp(type, "CDVS") == 0) {
            circuit[i].type = CDepVoltageSource;
            scanf(" (%d)", &depIndex);
            circuit[i].dependencyIndex = depIndex;
        } else if (strcmp(type, "VDCS") == 0) {
            circuit[i].type = VDepCurrentSource;
            scanf(" (%d)", &depIndex);
            circuit[i].dependencyIndex = depIndex;
        } else if (strcmp(type, "CDCS") == 0) {
            circuit[i].type = CDepCurrentSource;
            scanf(" (%d)", &depIndex);
            circuit[i].dependencyIndex = depIndex;
        }
        scanf("%d%d", &beg, &end);
        circuit[i].value = value;
        circuit[i].beg = beg;
        circuit[i].end = end;
    }

    int nodes = 0;
    for (int i = 0; i < n; i++) {
        if (circuit[i].beg > nodes) nodes = circuit[i].beg;
        if (circuit[i].end > nodes) nodes = circuit[i].end;
    }
    // We want # of nodes, not max index
    nodes++;

    double voltages[n];
    nodeVoltages(circuit, n, nodes, voltages);
    for (int i = 0; i < nodes; i++) {
        printf("Node %d: %.3f\n", i, voltages[i]);
    }

    return 0;
}

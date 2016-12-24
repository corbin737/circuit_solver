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

    double voltages[n];
    double currents[n];
    double powers[n];
    solveCircuit(circuit, n, voltages, currents, powers);

    for (int i = 0; i < n; i++) {
        printf("%d: Vol:%.3fV, Cur:%.3fA, Pwr:%.3fW\n", i, voltages[i], currents[i], powers[i]);
    }

    return 0;
}

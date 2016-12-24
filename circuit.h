#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <stddef.h>

typedef enum {
    Resistor,
    VoltageSource,
    CurrentSource,
    VDepVoltageSource,
    CDepVoltageSource,
    VDepCurrentSource,
    CDepCurrentSource
} ElementType;

typedef struct {
    int beg, end;
    double value;
    int dependencyIndex;
    ElementType type;
} Element;

void solveCircuit(Element circuit[], int n, double voltages[], double currents[], double powers[]);
int countNodes(Element circuit[], int n);

#endif

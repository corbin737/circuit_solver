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

void nodeVoltages(Element circuit[], int n, int nodes, double voltages[]);

#endif

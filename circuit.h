#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <stddef.h>

typedef enum {
    Resistor,
    VoltageSource,
    CurrentSource
} ElementType;

typedef struct {
    int beg, end;
    double value;
    ElementType type;
} Element;

void nodeVoltages(Element circuit[], int n, int nodes, double voltages[]);

#endif

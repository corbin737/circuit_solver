# Circuit Solver
Given a standard DC circuit as input, this program computes the voltages across, currents through, and powers absorbed by each element in the circuit.

---
## Dependencies
This project uses only standard C libraries and features (from the C99 standard).

## Usage
The program takes input directly from the command line.

To input a circuit, start by labelling all nodes and counting the total number of elements. The first line of input should be the number of elements `n`. The next `n` lines of input detail the specific elements. Generally, the format is as follows:
`value specifier start_node end_node`. For dependent sources, the element on which the source depends is specified by its index (starting from zero) in the input list.

### Examples
- Resistor: For a 10ohm resistor connected from nodes 1 to 3, `10 Resistor 1 3`
- Voltage Source: For a 9volt source connected to node 2 at the negative terminal and node 5 at the positive terminal, `9 VS 2 5`
- Current Source: For a 1amp source feeding current from node 2 to node 3, `1 CS 2 3`
- Voltage Dependent Voltage Source: Suppose the source output is some multiple of the voltage across a resistor listed as the second element in the input. This voltage would be measured in the same direction as the resistor was specified: from `start_node` to `end_node`. For a source connected from node 2 to 5 that multiplies this voltage by 4, `4 VDVS (1) 2 5`. Note that the `1` refers to the second element because the list starts at 0.
- Current Dependent Voltage Source: Suppose the source output is some multiple of the current through a resistor listed as the third element in the input. This current would be measured in the same direction as the resistor was specified: from `start_node` to `end_node`. For a source connected from node 0 to 3 that multiplies this current by 0.1, `0.1 CDVS (2) 0 3`
- Voltage Dependent Current Source: Suppose the source output is some multiple of the voltage across a resistor listed as the first element in the input. For a source from node 6 to 5 that multiplies this voltage by 0.002, `0.002 VDCS (0) 6 5`
- Current Dependent Current Source: Suppose the source output is some multiple of the current through a resistor listed as the ninth element in the input. For a source from node 4 to 8 that multiplies this current by 1, `1 CDCS (8) 4 8`

Further examples can be found in [the tests file](../master/tests.txt).

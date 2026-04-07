#ifndef QUANTUM_STATE_H
#define QUANTUM_STATE_H

#include <math.h>
#include <stdint.h>

#define QUBITS_NUM 2
#define N (1 << QUBITS_NUM)
#define AMP (1.0 / sqrt(N))

typedef struct {
  double real;
  double img;
} Complex;

void initialize_qubit_cluster(Complex cluster[]);

#endif

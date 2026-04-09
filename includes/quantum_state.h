#ifndef QUANTUM_STATE_H
#define QUANTUM_STATE_H

#include <math.h>
#include <stdint.h>

#define QUBITS_NUM 2
#define N (1 << QUBITS_NUM)
#define AMP (1.0 / sqrt(N))
#define INV_SQRT2 0.7071067811865475

typedef struct {
  double real;
  double img;
} Complex;

void hadamard_gate(Complex cluster[N], int target_q);

void cz_gate(Complex cluster[N], int control_q, int target_q);

void initialize_qubit_cluster(Complex cluster[]);

void entangle_qubits(Complex cluster[]);

void print_qstates(Complex cluster[]);
#endif

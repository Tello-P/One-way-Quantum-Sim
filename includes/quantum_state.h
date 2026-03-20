#ifndef QUANTUM_STATE_H
#define QUANTUM_STATE_H

#include <stdint.h>
#include <complex.h>

typedef double complex complex_t;

typedef struct {
  uint32_t num_qubits;
  uint64_t dim;
  complex_t *data;
} statevector_t;

statevector_t* create_sv(uint32_t n);
void free_sv(statevector_t *sv);
double calculate_norm(statevector_t *sv);

#endif

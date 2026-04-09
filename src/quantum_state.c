#include "../includes/quantum_state.h"
#include <stdio.h>

void hadamard_gate(Complex cluster[N], int target_q) {
  int bit_step = (1 << target_q);
  for (int i = 0; i < N; i++) {
    if (((i >> target_q) & 1) == 0) {
      int zero_idx = i;
      int one_idx = i + bit_step;

      Complex old_zero = cluster[zero_idx];
      Complex old_one = cluster[one_idx];

      cluster[zero_idx].real = (old_zero.real + old_one.real) * INV_SQRT2;
      cluster[zero_idx].img = (old_zero.img + old_one.img) * INV_SQRT2;

      cluster[one_idx].real = (old_zero.real - old_one.real) * INV_SQRT2;
      cluster[one_idx].img = (old_zero.img - old_one.img) * INV_SQRT2;
    }
  }
}

void cz_gate(Complex cluster[N], int control_q, int target_q) {
  for (int i = 0; i < N; i++) {
    int control_bit = (i >> control_q) & 1;
    int target_bit = (i >> target_q) & 1;

    if (control_bit && target_bit) {
      cluster[i].real *= -1.0;
      cluster[i].img *= -1.0;
    }
  }
}

void initialize_qubit_cluster(Complex cluster[]) {
  for (int i = 0; i < N; i++) {
    cluster[i].real = AMP;
    cluster[i].img = 0.0;
  }
}

void entangle_qubits(Complex cluster[]) {
  for (int j = 0; j < QUBITS_NUM - 1; j++) {
    cz_gate(cluster, j, j + 1);
  }
}

void print_qstates(Complex cluster[]) {
  printf("\n");
  for (int i = 0; i < N; i++) {
    printf("%f, ", cluster[i].real);
    printf("%f\n", cluster[i].img);
  }
}

int main() {
  Complex cluster[N];
  // TEST 1: Inicialización limpia a |00>
  for (int i = 0; i < N; i++) {
    cluster[i].real = 0.0;
    cluster[i].img = 0.0;
  }
  cluster[0].real = 1.0;
  print_qstates(cluster);
  hadamard_gate(cluster, 0);
  print_qstates(cluster);

  // TEST 2: Doble Hadamard (Identidad)
  hadamard_gate(cluster, 0);
  print_qstates(cluster);

  // TEST 3: Verificación de Fase con CZ
  initialize_qubit_cluster(cluster);
  entangle_qubits(cluster);
  print_qstates(cluster);

  /*
    initialize_qubit_cluster(cluster);
    print_qstates(cluster);

    cz_gate(cluster,0,1);
    print_qstates(cluster);

    entangle_qubits(cluster);
    print_qstates(cluster);
  */
  return 0;
}

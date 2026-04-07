#include "../includes/quantum_state.h"
#include <stdio.h>

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
  initialize_qubit_cluster(cluster);
  print_qstates(cluster);
  entangle_qubits(cluster);
  print_qstates(cluster);
}

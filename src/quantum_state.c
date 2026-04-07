#include "../includes/quantum_state.h"
#include <stdio.h>

void initialize_qubit_cluster(Complex cluster[]) {
  for (int i = 0; i < N; i++) {
    cluster[i].real = AMP;
    cluster[i].img = 0;
  }
}

int main() {
  Complex cluster[N];
  initialize_qubit_cluster(cluster);

  for (int i = 0; i < N; i++) {
    printf("%f, ", cluster[i].real);
    printf("%f\n", cluster[i].img);
  }
}

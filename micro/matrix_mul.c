// Count number of memory operations in matrix addition
// tags: integer, resource-bound

#include "assert.h"

int nb_memops = 0;

void mul(int n) {
  __VERIFIER_assume(0 <= n && n < LARGE_INT);

  // clear destination matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      nb_memops ++; // a[i][j] = 0
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
	nb_memops += 4; //a[i][j] += b[i][k]*c[k][j];
      }
    }
  }
}

void main() {
  int n = __VERIFIER_nondet_nat();
  mul(n);
  __VERIFIER_assert(nb_memops == 4 * n * n * n + n * n);
}

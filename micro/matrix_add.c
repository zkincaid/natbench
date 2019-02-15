// Count number of memory operations in matrix addition
// tags: integer, resource-bound, safe

#include "assert.h"

int nb_memops = 0;

void add(int m, int n) {
  __VERIFIER_assume(0 <= m && m < LARGE_INT);
  __VERIFIER_assume(0 <= n && n < LARGE_INT);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      nb_memops += 3; // a[i][j] = b[i][j] + c[i][j]
    }
  }
}

void main() {
  int m = __VERIFIER_nondet_nat();
  int n = __VERIFIER_nondet_nat();
  add(m, n);
  __VERIFIER_assert(nb_memops <= 3 * m * n);
}

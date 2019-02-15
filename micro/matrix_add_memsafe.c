// Memory safey of matrix addition
// tags: integer, mem-safety, safe

#include "assert.h"

void add(int m, int n) {
  __VERIFIER_assume(0 <= m && m < MEDIUM_INT);
  __VERIFIER_assume(0 <= n && n < MEDIUM_INT);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      // a[i][j] = b[i][j] + c[i][j]
      __VERIFIER_assert(0 <= n*i + j);
      __VERIFIER_assert(n*i + j < n * m);
    }
  }
}

void main() {
  int m = __VERIFIER_nondet_nat();
  int n = __VERIFIER_nondet_nat();

  add(m, n);
}

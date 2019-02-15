// Count number of memory operations in matrix addition
// tags: integer, mem-safety, safe

#include "assert.h"

void mul(int n) {
  __VERIFIER_assume(0 <= n && n < MEDIUM_INT);

  // clear destination matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      __VERIFIER_assert(0 <= i*n + j);
      __VERIFIER_assert(i*n + j < n*n);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
	//a[i][j] += b[i][k]*c[k][j];

	__VERIFIER_assert(0 <= i*n + j);
	__VERIFIER_assert(i*n + j < n*n);
	__VERIFIER_assert(0 <= i*n + k);
	__VERIFIER_assert(i*n + k < n*n);
	__VERIFIER_assert(0 <= k*n + j);
	__VERIFIER_assert(k*n + j < n*n);
      }
    }
  }
}

void main() {
  int n = __VERIFIER_nondet_nat();
  mul(n);
}

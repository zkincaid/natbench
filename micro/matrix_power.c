// Count memory options in fast matrix powering
// tags: integer, resource-bound, safe

#include "util.h"
#include "assert.h"

int nb_memops;

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

void pow(int size, int exp) {
  if (exp == 0) {
    return;
  } else if (exp == 1) {
    return;
  } else {
    // y = mat^(exp/2)
    pow(size, exp / 2);
    // yy = mul(y,y)
    mul(size);
    if (exp % 2 == 0) {
      return;
    } else {
      // return mul(mat,yy)
      mul(size);
      return;
    }
  }
}

void main() {
  int size = __VERIFIER_nondet_nat();
  int exp = __VERIFIER_nondet_nat();
  pow(size, exp);
  __VERIFIER_assert(nb_memops <= 2*log2(exp)*(4 * size * size * size + size * size));
}

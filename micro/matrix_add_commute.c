// Matrix addition is commutative
// tags: array, relational, safe

#include "assert.h"
#include <stdlib.h>

int* add(int *a, int *b, int m, int n) {
  int i, j;
  int *result = malloc(sizeof(int) * m * n);
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      *(result + (i*n) + j) = *(a + (i * n) + j) + *(b + (i * n) + j);
    }
  }
  return result;
}

void init_matrix (int *a, int m, int n) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      *(a + (i*n) + j) = __VERIFIER_nondet_int();
    }
  }
}

void assert_equal_mat (int *a, int *b, int m, int n) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      __VERIFIER_assert(*(a + (i * n) + j) == *(b + (i * n) + j));
    }
  }
}

int main() {
  int m = __VERIFIER_nondet_nat();
  int n = __VERIFIER_nondet_nat();
  int *a = malloc(sizeof(int) * m * n);
  int *b = malloc(sizeof(int) * m * n);
  int *a_plus_b = add(a, b, m, n);
  int *b_plus_a = add(b, a, m, n);
  assert_equal_mat(a_plus_b, b_plus_a, m, n);
  return 0;
}

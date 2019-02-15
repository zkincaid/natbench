// Vector addition is commutative
// tags: array, relational, safe

#include "assert.h"
#include <stdlib.h>

int* add(int *u, int *v, int dim) {
  int *result = malloc(sizeof(int) * dim);
  int i;
  for (i = 0; i < dim; i++) {
    result[i] += u[i] + v[i];
  }
  return result;
}

void init_vec (int *v, int dim) {
  int i;
  for (i = 0; i < dim; i++) {
    v[i] = __VERIFIER_nondet_int();
  }
}

void assert_equal_vec (int *u, int *v, int dim) {
  int i;
  for (i = 0; i < dim; i++) {
    __VERIFIER_assert(v[i] == u[i]);
  }
}

int main () {
  int dim = __VERIFIER_nondet_nat();
  int *u = malloc(sizeof(int) * dim);
  int *v = malloc(sizeof(int) * dim);
  init_vec(u, dim);
  init_vec(v, dim);
  int *u_plus_v = add(u, v, dim);
  int *v_plus_u = add(v, u, dim);
  assert_equal_vec(u_plus_v, v_plus_u, dim);
  return 0;
}

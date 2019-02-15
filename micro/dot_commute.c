// dot product of u and v is the dot product of v and u
// tags: array, safe, relational, c

#include "assert.h"
#include <stdlib.h>

int dot(int *u, int *v, int dim) {
  int result = 0;
  int i;
  for (i = 0; i < dim; i++) {
    result += u[i]*v[i];
  }
  return result;
}

void init_vec (int *v, int dim) {
  int i;
  for (i = 0; i < dim; i++) {
    v[i] = __VERIFIER_nondet_int();
  }
}

int main() {
  int n = __VERIFIER_nondet_nat();
  int *u = (int*) malloc(n * sizeof(int));
  int *v = (int*) malloc(n * sizeof(int));
  init_vec(u, n);
  init_vec(v, n);
  __VERIFIER_assert(dot(u,v,n) == dot(v,u,n));
}

// Count number of memory options in dot product
// tags: integer, linear, resource-bound, safe

#include "assert.h"

int nb_ops = 0;

void dot(int size) {
  for (int i = 0; i < size; i++) {
    nb_ops += 2; // dot += a[i]*b[i]
  }
}

void main() {
  int size = __VERIFIER_nondet_int();
  __VERIFIER_assume(0 <= size && size < LARGE_INT);
  dot(size);
  __VERIFIER_assert(nb_ops <= 2*size);
}

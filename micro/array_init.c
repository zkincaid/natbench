// Initialize an array
// tags: array, safe

#include "assert.h"

int time = 0;

int main() {
  int n = __VERIFIER_nondet_nat();
  int i;
  int *array = malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    array[i] = 0;
  }
  for (i = 0; i < n; i++) {
    __VERIFIER_assert(array[i] == 0);
  }
}

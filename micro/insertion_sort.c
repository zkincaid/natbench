// Count number of comparisons in an insertion sort
// tags: integer, resource-bound, safe

#include "assert.h"

int nb_comparisons = 0;
void insert_sort(int length) {
  __VERIFIER_assume(0 <= length && length < LARGE_INT);

  for (int i = 0; i < length; i++) {
    // insert
    int j = i - 1;
    while(j > 0 && __VERIFIER_nondet_int()) {
      j--;
      nb_comparisons++;
    }
  }
}

void main() {
  int length = __VERIFIER_nondet_nat();
  insert_sort(length);
  __VERIFIER_assert(nb_comparisons <= (length * (length - 1))/2);
}

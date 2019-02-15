// Count number of comparisons in quick sort
// tags: integer, resource-bound, safe

#include "assert.h"

int nb_comparisons = 0;

void quicksort(int lo, int hi) {
  __VERIFIER_assume(0 <= lo && lo < LARGE_INT);
  __VERIFIER_assume(0 <= hi && hi < LARGE_INT);

  if (hi <= lo) {
    return;
  }

  // partition
  int lower = lo + 1;
  int upper = hi;
  while (lower < upper) {
    nb_comparisons++;
    if (__VERIFIER_nondet_int()) {
      lower++;
    } else {
      upper--;
    }
  }

  quicksort(lo, lower - 1);
  quicksort(upper, hi);
}

void main() {
  int size = __VERIFIER_nondet_nat();
  quicksort(0, size);
  __VERIFIER_assert(nb_comparisons <= size * size);
}

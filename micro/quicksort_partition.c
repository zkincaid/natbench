// Count number of comparisons in quick sort, partition step only
// tags: integer, linear, resource-bound, safe

#include "assert.h"

int nb_comparisons = 0;

void partition(int lo, int hi) {
  __VERIFIER_assume(0 <= lo && lo < LARGE_INT);
  __VERIFIER_assume(0 <= hi && hi < LARGE_INT);
  __VERIFIER_assume(lo < hi);

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
}

void main() {
  int lo = __VERIFIER_nondet_nat();
  int hi = __VERIFIER_nondet_nat();
  __VERIFIER_assume(lo < hi);
  partition(lo, hi);
  __VERIFIER_assert(nb_comparisons == hi - lo - 1);
}

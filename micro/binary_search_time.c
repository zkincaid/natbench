// Count number of comparisons in a binary search
// tags: integer, resource-bound, safe

#include "assert.h"
#include "util.h"

int nb_comparisons = 0;

void search(int n) {
    int lo = 1;
    int hi = n;
    while (lo <= hi) {
	int mid = lo + (hi-lo)/2;
	nb_comparisons++;
	if (__VERIFIER_nondet()) {
	  return;
	} else if (__VERIFIER_nondet()) {
	    lo = mid + 1;
	} else {
	    hi = mid - 1;
	}
    }
}

void main() {
    int n = __VERIFIER_nondet_int();
    search(n);
    __VERIFIER_assert(nb_comparisons <= log2(n) + 1);
}

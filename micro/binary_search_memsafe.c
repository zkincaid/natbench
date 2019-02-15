// Memory safety of binary search
// tags: integer, mem-safety, linear, safe

#include "assert.h"
#include "util.h"

void search(int n) {
    int lo = 1;
    int hi = n;
    while (lo <= hi) {
	int mid = lo + (hi-lo)/2;
	__VERIFIER_assert(0 <= mid - 1);
	__VERIFIER_assert(mid - 1 < n);
	if (__VERIFIER_nondet()) {
	  return;
	} else if (__VERIFIER_nondet()) {
	    lo = mid + 1;
	} else {
	    hi = mid - 1;
	}
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    search(n);
    return 0;
}

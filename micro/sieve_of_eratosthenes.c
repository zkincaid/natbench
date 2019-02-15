// Time complexity of the Sieve of Eratosthenes
// tags: integer, resource-bound, safe

#include "assert.h"

int time = 0;

int main() {
  int n = __VERIFIER_nondet_nat();
  __VERIFIER_assume(2 <= n && n < LARGE_INT);
  for (int i = 2; i < n; i++) {
    time ++;
    if (__VERIFIER_nondet_int()) {
      // i is prime
      for (int j = i; j < n; j += i) {
	// sieve
	time ++;
      }
    }
  }
  __VERIFIER_assert(time <= n*n/2 + n);
}

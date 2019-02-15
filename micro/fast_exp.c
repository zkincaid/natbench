// Equivalence between n/logn exponentiation
// tags: integer, relational, safe

#include "assert.h"

int pow_slow(int x, int n) {
  int result = 1;
  for (int i = 0; i < n; i++) {
    result *= x;
  }
  return result;
}

int pow_fast(int x, int n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return x;
  } else {
    int y = pow_fast(x, n / 2);
    if (n % 2 == 0) {
      return y * y;
    } else {
      return x * y * y;
    }
  }
}

void main() {
  int x = __VERIFIER_nondet_int();
  int n = __VERIFIER_nondet_int();
  __VERIFIER_assume(-5 <= x && x <= 5);
  __VERIFIER_assume(0 <= n && n <= 12);
  __VERIFIER_assert(pow_slow(x,n) == pow_fast(x,n));
}

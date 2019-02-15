// gcd(x,y) divides both x and y
// tags: integer, safe

#include "assert.h"

int gcd(int a, int b) {
  __VERIFIER_assume(1 <= a && a < LARGE_INT);
  __VERIFIER_assume(1 <= b && b < LARGE_INT);
  while (a != b) {
    if (a > b) {
      a = a - b;
    } else {
      b = b - a;
    }
  }
  return a;
}

void main() {
  int x = __VERIFIER_nondet_nat();
  int y = __VERIFIER_nondet_nat();
  int z = gcd(x, y);
  __VERIFIER_assert(x % z == 0);
  __VERIFIER_assert(y % z == 0);
}

/* Algorithm for computing the floor of the square root of a natural number
   Source: Enric Rodríguez Carbonell
   http://www.lsi.upc.edu/~erodri/webpage/polynomial_invariants/sqrt.htm */
// tags: integer, safe

#include "assert.h"
int sqrt (int n) {
  __VERIFIER_assume(n >= 0);
  int a,su,t;

  a = 0;
  su = 1;
  t = 1;

  while(su <= n) {
    a = a + 1;
    t = t + 2;
    su = su + t;
  }

  return a;
}

int main() {
  int n = __VERIFIER_nondet_nat();
  int result = sqrt(n);
  __VERIFIER_assert(result * result <= n && (result + 1)*(result +1) > n);
  return 0;
}

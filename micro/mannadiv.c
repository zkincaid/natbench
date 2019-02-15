/* Division algorithm from "Z. Manna, Mathematical Theory of
   Computation, McGraw-Hill, 1974"
   http://www.lsi.upc.edu/~erodri/webpage/polynomial_invariants/mannadiv.html
 */
// tags: integer, safe

#include "assert.h"

int main () {
  int x1 = __VERIFIER_nondet_nat();
  int x2 = __VERIFIER_nondet_nat();
  __VERIFIER_assume(x2 > 0);
  int y1 = 0;
  int y2 = 0;
  int y3 = x1;
  while (y3 != 0) {
    if (y2 + 1 == x2) {
      y1 = y1 + 1;
      y2 = 0;
      y3 = y3 - 1;
    } else {
      y2 = y2 + 1;
      y3 = y3 - 1;
    }
  }
  __VERIFIER_assert(y2 == x1 % x2 && y1 == x1 / x2);
  return 0;
}

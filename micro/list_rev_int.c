// Count number of memory operations in integer model of list reversal
// tags: integer, linear, resource-bound, safe

#include "assert.h"


int main() {
  int nb_operations = 0;
  int list_len = 0;
  int rev_len = 0;
  int n = __VERIFIER_nondet_int();
  __VERIFIER_assume(0 <= n && n < LARGE_INT);

  // allocate list of size n
  for (int i = 0; i < n; i++) {
    list_len++;
    nb_operations++;
  }

  // reverse list
  for (int i = 0; i < list_len; i++) {
    rev_len++;
    nb_operations += 2;
  }

  __VERIFIER_assert(nb_operations <= 3 * n);
  return 0;
}

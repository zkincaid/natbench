#include "assert.h"

/* find the least k such that n <= 2^k */
int log2(int n) {
  __VERIFIER_assume(0 <= n && n < LARGE_INT);
  int result = 0;
  int pow = 1;
  while(pow < n) {
    pow *= 2;
    result ++;
  }
  return result;
}

int pow2(int n) {
  int pow = 1;
  while (n > 0) {
    n--;
    pow *= 2;
  }
  return pow;
}
  
  

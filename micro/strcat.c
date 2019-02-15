// tags: integer, linear, safe

#include "assert.h"

// compute length of dest after catenating src
int strcat_len(int dest_len, int src_len) {
  __VERIFIER_assume(0 <= dest_len && dest_len < LARGE_INT);
  __VERIFIER_assume(0 <= src_len && src_len < LARGE_INT);
  
  int i, j;
  // advance i to end of dest
  for(i = 0; i < dest_len; i++);
  // copy src to dest
  for(j = 0; j < src_len; j++) {
    // dest[i + j] = src[j]
    if (j < src_len - 1) {
      // dest no longer null-terminated -- havoc length
      dest_len = __VERIFIER_nondet_int();
    } else {
      // copied null
      dest_len = i + j + 1;
    }
  }
  return dest_len;
}


int main() {
  int src, dest;
  src = __VERIFIER_nondet_nat();
  dest = __VERIFIER_nondet_nat();
  int result = strcat_len(dest, src);
  __VERIFIER_assert(result == dest + src);
}

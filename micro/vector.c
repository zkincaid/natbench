// Resizable vectors with exponential re-allocation
// tags: integer, linear, resource-bound, safe

#include "assert.h"

int capacity = 2;
int length = 0;

int nb_writes = 0;

void push() {
  __VERIFIER_assume(0 <= length && length < LARGE_INT);
  __VERIFIER_assume(2 <= capacity && capacity < LARGE_INT);
  __VERIFIER_assume(0 <= nb_writes && nb_writes < LARGE_INT);

  __VERIFIER_assert(length <= nb_writes);
  __VERIFIER_assert(length <= capacity);

  if (length < capacity) {
    length++;
    nb_writes++;
  } else {
    __VERIFIER_assert(capacity == length);
    int new_capacity = 2*capacity;

    // nb_writes = nb_writes + length + 1
    // copy contents
    for(int i = 0; i < length; i++) {
      nb_writes++;
    }
    nb_writes++; // new element
    
    capacity = new_capacity;
    length++;
  }

}

int main() {
  int to_push = __VERIFIER_nondet_int();
  __VERIFIER_assume(0 <= to_push);
  __VERIFIER_assume(to_push <= MEDIUM_INT);

  __VERIFIER_assume(0 <= length && length < LARGE_INT);
  __VERIFIER_assume(2 <= capacity && capacity < LARGE_INT);
  __VERIFIER_assume(0 <= nb_writes && nb_writes < LARGE_INT);


  for (int i = 0; i < to_push; i++) {
    push();
  }

  __VERIFIER_assert(nb_writes <= 3*to_push);
}

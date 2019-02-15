// Functional queue with amortized constant operations
// tags: integer, linear, resource-bound, safe

#include "assert.h"

// queue implemented as two lists front and back.  We abstract their
// lengths and the total size of the queue
int front_len = 0;
int back_len = 0;
int size = 0;

int memops = 0;

void enqueue() {
  size++;
  back_len++; // add to back
  memops+=1;
}

void dequeue() {
  __VERIFIER_assume(0 <= front_len && front_len < LARGE_INT);
  __VERIFIER_assume(0 <= back_len && back_len < LARGE_INT);
  __VERIFIER_assume(0 <= size && size < LARGE_INT);
  if (front_len == 0) {
    // shift back to front
    while(back_len > 0) {
      back_len--;
      front_len++;
      memops+=3;
    }
  }
  size--;
  front_len--;  
  memops+=2;
}

int main() {
  int nb_operations;

  nb_operations = __VERIFIER_nondet_int();
  __VERIFIER_assume(0 <= nb_operations && nb_operations < LARGE_INT);

  /* nondeterministically do nb_operations enqueues/dequeues */
  for (int i = 0; i < nb_operations; i++) {
    if (size > 0 && __VERIFIER_nondet_int()) {
      dequeue();
    } else {
      enqueue();
    }
  }

  __VERIFIER_assert(memops <= 4*nb_operations);
  return 0;
}

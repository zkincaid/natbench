// check that insertion sort produces a sorted array

// tags: array, safe

#include "assert.h"
#include <stdlib.h>

void insert_sort(int a[], int n) { 
  int i, j, curr; 
  for (i = 1; i < n; i++) {
    curr = a[i];
    j = i-1;
    while (j >= 0 && a[j] > curr) {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = curr;
  }
} 

void is_sorted(int a[], int n) {
  int i;
  for (i = 1; i < n; i++) {
    __VERIFIER_assert(a[i-1] <= a[i]);
  }
}

int main () {
  int n = __VERIFIER_nondet_nat ();
  int *a = malloc(n * sizeof(int));
  int i;
  for (i = 0; i < n; i++) {
    a[i] = __VERIFIER_nondet_int();
  }
  insert_sort(a, n);
  is_sorted(a, n);
  return 0;
}

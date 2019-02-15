// Integer model of merging two sorted lists
// tags: integer, linear, resource-bound, safe

#include "assert.h"

int time = 0;

int merge(int list1_len, int list2_len) {
  int i = 0;
  int merged_len = 0;
  __VERIFIER_assume(0 <= list1_len && list1_len < LARGE_INT);
  __VERIFIER_assume(0 <= list2_len && list2_len < LARGE_INT);

  while (1) {
    //    __VERIFIER_assume(0 <= list1_len);
    //    __VERIFIER_assume(0 <= list2_len);

    time ++;
    if (list1_len == 0) {
      // merged->next = list2
      merged_len += list2_len;
      return merged_len;
    }
    if (list2_len == 0) {
      // merged->next = list1
      merged_len += list1_len;
      return merged_len;
    }
    if (__VERIFIER_nondet()) {
      // list1->data < list2->data
      list1_len --;
      merged_len ++;
    } else {
      // list2->data <= list1->data
      list2_len --;
      merged_len ++;
    }
  }
}
// time' + list1_len' + list2_len'  = time + list1_len + list2_len

int main() {
  int list1_len = __VERIFIER_nondet_int();
  int list2_len = __VERIFIER_nondet_int();

  int merged_len = merge(list1_len, list2_len);

  __VERIFIER_assert(time <= list1_len + list2_len + 1);
  __VERIFIER_assert(merged_len == list1_len + list2_len);

  return 0;
}

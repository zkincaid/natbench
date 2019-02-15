#ifndef __ASSERT_H
#define __ASSERT_H
extern void __VERIFIER_error() __attribute__((noreturn));
extern void __VERIFIER_assume (int);
extern int __VERIFIER_nondet_int ();

#define assume __VERIFIER_assume
#define LARGE_INT 1000000
#define MEDIUM_INT 1000

#ifndef __VERIFIER_duet
#define __VERIFIER_assert(c) do { if(!(c)) __VERIFIER_error(); } while(0)
#endif

int __VERIFIER_nondet_nat () {
  int r = __VERIFIER_nondet_int();
  __VERIFIER_assume(0 <= r && r < LARGE_INT);
  return r;
}
#endif

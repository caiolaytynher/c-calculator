#include "../src/calc.h"
#include "../src/quadratic.h"
#include "minunit.h"
#include <stdio.h>

int tests_run = 0;

static char *test_counter() {
  size_t size = 10;
  int nums[10];

  for (int i = 0; i < size / 2; i++) {
    nums[i] = 1;
  }

  for (int i = size / 2; i < size; i++) {
    nums[i] = 2;
  }

  mu_assert("Count must be 5", array_count(1, nums, 10) == 5);
  mu_assert("Count must be 5", array_count(2, nums, 10) == 5);
  return 0;
}

static char *test_prime_factors() {
  size_t size = 10;
  int prime_factors[10];
  int checker[] = {2, 2, 2, 3};

  find_prime_factors(24, prime_factors, size);

  for (size_t i = 0; i < size; i++) {
    if (i < 4) {
      mu_assert("Prime factors must be equal to checker",
                prime_factors[i] == checker[i]);
    } else {
      mu_assert("The remaining factors must be zero", prime_factors[i] == 0);
    }
  }

  return 0;
}

static char *test_simplify_root() {
  Root root = root_simplify(24);
  mu_assert("Scalar numerator should equal 2", root.scalar.numerator == 2);
  mu_assert("Scalar denominator should equal 1", root.scalar.denominator == 1);
  mu_assert("Root should equal 6", root.root == 6);
  return 0;
}

static char *test_quadratic_eq() {
  QuadraticAnswer ans = solve_quadratic_eq(3, -2, -1);

  // printf("x1 numerator: %d\n", ans.x1.real.numerator);

  mu_assert("x2 numerator should equal -1", ans.x2.real.numerator == -1);
  mu_assert("x2 denominator should equal 3", ans.x2.real.denominator == 3);
  mu_assert("x2 root should equal 0", ans.x2.imaginary.scalar.numerator == 0);
  mu_assert("x2 root scalar numerator should equal 0",
            ans.x2.imaginary.scalar.numerator == 0);
  mu_assert("x2 root scalar denominator should equal 1",
            ans.x2.imaginary.scalar.denominator == 1);

  mu_assert("x1 numerator should equal 1", ans.x1.real.numerator == 1);
  mu_assert("x1 denominator should equal 1", ans.x1.real.numerator == 1);
  mu_assert("x1 root should equal 0", ans.x1.imaginary.scalar.numerator == 0);
  mu_assert("x1 root scalar numerator should equal 0",
            ans.x1.imaginary.scalar.numerator == 0);
  mu_assert("x1 root scalar denominator should equal 1",
            ans.x1.imaginary.scalar.denominator == 1);

  return 0;
}

static char *test_simplify_ratio() {
  printf("FIRST TEST:\n");
  Rational ans = ratio_simplify(24, 6);

  mu_assert("Numerator should be 4", ans.numerator == 4);
  mu_assert("Denominator should be 1", ans.denominator == 1);

  printf("SECOND TEST:\n");
  ans = ratio_simplify(6, 24);
  printf("RATIO: %d / %d\n", ans.numerator, ans.denominator);
  mu_assert("Numerator should be 1", ans.numerator == 1);
  mu_assert("Denominator should be 4", ans.denominator == 4);
  return 0;
}

static char *all_tests() {
  mu_run_test(test_counter);
  mu_run_test(test_prime_factors);
  mu_run_test(test_simplify_root);
  mu_run_test(test_quadratic_eq);
  mu_run_test(test_simplify_ratio);
  return 0;
}

int main(int argc, char *argv[]) {
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  } else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}

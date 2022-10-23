#include "../src/calc.h"
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

static char *all_tests() {
  mu_run_test(test_counter);
  mu_run_test(test_prime_factors);
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

#include "quadratic.h"
#include "calc.h"
#include "helpers.h"
#include <stdio.h>

Root simplify_root(int root) {
  Root ans = {
      .scalar = 1,
      .root = 1,
  };
  int prime_factors[MAX_PRIME_FACTORS];

  find_prime_factors(root, prime_factors, MAX_PRIME_FACTORS);

  int higher_prime = array_max_int(prime_factors, MAX_PRIME_FACTORS);

  int amount;
  for (int prime = 2; prime <= higher_prime; prime++) {
    if (!is_prime(prime))
      continue;

    amount = array_count(prime, prime_factors, MAX_PRIME_FACTORS);
    if (amount % 2 == 0)
      ans.scalar *= prime * amount / 2;
    else {
      if (amount > 1)
        ans.scalar *= prime * (amount - 1) / 2;

      ans.root *= prime;
    }
  }

  return ans;
}

Rational simplify_ratio(int num, int denom) {
  int num_prime_factors[MAX_PRIME_FACTORS];
  int denom_prime_factors[MAX_PRIME_FACTORS];
  int denom_index;

  find_prime_factors(num, num_prime_factors, MAX_PRIME_FACTORS);
  find_prime_factors(denom, denom_prime_factors, MAX_PRIME_FACTORS);

  for (int num_index = 0; num_index < MAX_PRIME_FACTORS; num_index++) {
    if (num_prime_factors[num_index] == 0)
      break;

    if (is_in(num_prime_factors[num_index], denom_prime_factors,
              MAX_PRIME_FACTORS)) {
      denom_index = index_of(num_prime_factors[num_index], denom_prime_factors,
                             MAX_PRIME_FACTORS);
      num_prime_factors[num_index] = 0;
      denom_prime_factors[denom_index] = 0;
    }
  }

  Rational ans = {
      .numerator = 1,
      .denominator = 1,
  };
  for (int i = 0; i < MAX_PRIME_FACTORS; i++) {
    if (num_prime_factors[i] == 0)
      continue;

    ans.numerator *= num_prime_factors[i];

    if (denom_prime_factors[i] == 0)
      continue;

    ans.denominator *= denom_prime_factors[i];
  }

  return ans;
}

QuadraticAnswer solve_quadratic_eq(int a, int b, int c) {
  QuadraticAnswer answer;
  Complex number = {.real = 0,
                    .imaginary = {
                        .scalar = 0,
                        .root = 0,
                    }};

  int delta = potentiate(b, 2) - 4 * a * c;
  printf("DELTA = %d\n", delta);

  if (delta < 0) {
    number.real = -(float)b / (2 * a);
    number.imaginary = simplify_root(-delta);
    number.imaginary.scalar = number.imaginary.scalar / (2 * a);
    answer.a = number;

    number.imaginary.scalar = -number.imaginary.scalar;
    answer.b = number;
  } else if (delta == 0) {
    number.real = -(float)b / (2 * a);
    answer.a = answer.b = number;
  } else {
    printf("DELTA > 0\n");
    number.imaginary = simplify_root(potentiate(2 * a, 2) * delta);
    printf("SCALAR = %d\n", number.imaginary.scalar);

    number.real = -(float)b / (2 * a) + number.imaginary.scalar;
    answer.a = number;

    number.real = -(float)b / (2 * a) - number.imaginary.scalar;
    answer.b = number;
  }

  return answer;
}

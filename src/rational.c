#include "rational.h"
#include "calc.h"
#include "helpers.h"
#include <stdio.h>

Rational ratio_simplify(int num, int denom) {
  int num_prime_factors[MAX_PRIME_FACTORS];
  int denom_prime_factors[MAX_PRIME_FACTORS];
  int denom_index;

  find_prime_factors(num, num_prime_factors, MAX_PRIME_FACTORS);
  find_prime_factors(denom, denom_prime_factors, MAX_PRIME_FACTORS);

  for (int num_index = 0; num_index < MAX_PRIME_FACTORS; num_index++) {
    // printf("numerator prime factors: ");
    // array_print(num_prime_factors, MAX_PRIME_FACTORS);
    // printf("denominator prime factors: ");
    // array_print(denom_prime_factors, MAX_PRIME_FACTORS);

    if (num_prime_factors[num_index] == 0)
      break;

    if (is_in(num_prime_factors[num_index], denom_prime_factors,
              MAX_PRIME_FACTORS)) {
      denom_index = index_of(num_prime_factors[num_index], denom_prime_factors,
                             MAX_PRIME_FACTORS);
      num_prime_factors[num_index] = 1;
      denom_prime_factors[denom_index] = 1;
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
  }

  for (int i = 0; i < MAX_PRIME_FACTORS; i++) {
    if (denom_prime_factors[i] == 0)
      continue;

    ans.denominator *= denom_prime_factors[i];
  }

  return ans;
}

Rational ratio_sum(Rational a, Rational b) {
  Rational ans;

  if (a.denominator == b.denominator) {
    ans.numerator = a.numerator + b.numerator;
    ans.denominator = a.denominator;

    return ans;
  }

  Rational new_a = {
      .numerator = a.numerator * b.denominator,
      .denominator = a.denominator * b.denominator,
  };
  Rational new_b = {
      .numerator = b.numerator * a.denominator,
      .denominator = b.denominator * a.denominator,
  };

  ans.numerator = new_a.numerator + new_b.numerator;
  ans.denominator = new_a.denominator;
  ans = ratio_simplify(ans.numerator, ans.denominator);

  return ans;
}

Rational ratio_sub(Rational a, Rational b) {
  Rational ans;

  if (a.denominator == b.denominator) {
    ans.numerator = a.numerator - b.numerator;
    ans.denominator = a.denominator;

    return ans;
  }

  Rational new_a = {
      .numerator = a.numerator * b.denominator,
      .denominator = a.denominator * b.denominator,
  };
  Rational new_b = {
      .numerator = b.numerator * a.denominator,
      .denominator = b.denominator * a.denominator,
  };

  ans.numerator = new_a.numerator - new_b.numerator;
  ans.denominator = new_a.denominator;
  ans = ratio_simplify(ans.numerator, ans.denominator);

  return ans;
}

void ratio_print(Rational ratio) {
  if (ratio.denominator == 1)
    printf("%d\n", ratio.numerator);
  else
    printf("%d/%d\n", ratio.numerator, ratio.denominator);
}

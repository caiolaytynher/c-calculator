#include "quadratic.h"
#include "calc.h"
#include "helpers.h"
#include <stdio.h>

Root simplify_root(int root) {
  Root ans = {
      .scalar =
          {
              .numerator = 1,
              .denominator = 1,
          },
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
      ans.scalar.numerator *= prime * amount / 2;
    else {
      if (amount > 1)
        ans.scalar.numerator *= prime * (amount - 1) / 2;

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

Rational rational_sum(Rational a, Rational b) {
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
  ans = simplify_ratio(ans.numerator, ans.denominator);

  return ans;
}

Rational rational_sub(Rational a, Rational b) {
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
  ans = simplify_ratio(ans.numerator, ans.denominator);

  return ans;
}

QuadraticAnswer solve_quadratic_eq(int a, int b, int c) {
  QuadraticAnswer answer;
  Complex number = {.real =
                        {
                            .numerator = 0,
                            .denominator = 1,
                        },
                    .imaginary = {
                        .scalar =
                            {
                                .numerator = 0,
                                .denominator = 1,
                            },
                        .root = 0,
                    }};

  int delta = potentiate(b, 2) - 4 * a * c;
  printf("DELTA = %d\n", delta);

  if (delta < 0) {
    number.real = simplify_ratio(-b, 2 * a);

    number.imaginary = simplify_root(delta);
    number.imaginary.scalar =
        simplify_ratio(number.imaginary.scalar.numerator, 2 * a);

    answer.x1 = number;

    number.imaginary.scalar.numerator = -number.imaginary.scalar.numerator;
    answer.x2 = number;
  } else if (delta == 0) {
    number.real = simplify_ratio(-b, 2 * a);
    answer.x1 = answer.x2 = number;
  } else {
    Root delta_root = simplify_root(delta);
    delta_root.scalar.denominator = 2 * a;
    Rational real_part = {
        .numerator = -b,
        .denominator = 2 * a,
    };

    if (delta_root.root == 1) {
      number.real = rational_sum(real_part, delta_root.scalar);
      answer.x1 = number;

      number.real = rational_sub(real_part, delta_root.scalar);
      answer.x2 = number;
    } else {
      number.real = simplify_ratio(real_part.numerator, real_part.denominator);
      number.imaginary.scalar = simplify_ratio(delta_root.scalar.numerator,
                                               delta_root.scalar.denominator);
      number.imaginary.root = delta_root.root;
      answer.x1 = number;

      number.imaginary.scalar.numerator = -number.imaginary.scalar.numerator;
      answer.x2 = number;
    }
  }

  return answer;
}

void print_quadratic_answer(QuadraticAnswer answer) {}

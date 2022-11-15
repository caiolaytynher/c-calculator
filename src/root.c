#include "root.h"
#include "calc.h"
#include <stdio.h>

Root root_simplify(int root) {
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

void root_print(Root root) {
  if (root.root == 1) {
    ratio_print(root.scalar);
  } else {
    if (root.scalar.denominator == 1)
      printf("%dsqrt(%d)\n", root.scalar.numerator, root.root);
    else
      printf("%dsqrt(%d)/%d\n", root.scalar.numerator, root.root,
             root.scalar.denominator);
  }
}

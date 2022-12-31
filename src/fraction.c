#include "fraction.h"
#include "log.h"
#include "more_math.h"
#include <stdio.h>

Frac fr_create(int num, int denom) {
  if (denom == 0)
    perror("Cannot divide by zero.\n");

  if (denom < 0) {
    num *= -1;
    denom *= -1;
  }

  Frac frac = {num, denom};
  return frac;
}

Frac fr_simplify(Frac frac) {
  if (frac.denom < 0) {
    frac.num *= -1;
    frac.denom *= -1;
  }

  int gcd = mm_gcd(frac.num, frac.denom);

  return fr_create(frac.num / gcd, frac.denom / gcd);
}

Frac fr_sum(Frac a, Frac b) {
  int common_denom = mm_lcm(a.denom, b.denom);

  int num =
      (a.num * (common_denom / a.denom)) + (b.num * (common_denom / b.denom));

  Frac frac = fr_create(num, common_denom);
  return fr_simplify(frac);
}

Frac fr_sub(Frac a, Frac b) {
  int common_denom = mm_lcm(a.denom, b.denom);

  int num =
      (a.num * (common_denom / a.denom)) - (b.num * (common_denom / b.denom));

  Frac frac = fr_create(num, common_denom);
  return fr_simplify(frac);
}

bool fr_is_equal(Frac a, Frac b) {
  if (a.num == b.num && a.denom == b.denom)
    return true;

  return false;
}

void fr_to_str(Frac frac, char *string) {
  if (frac.denom == 1 || frac.num == 0) {
    sprintf(string, "%d", frac.num);
    return;
  }

  sprintf(string, "%d/%d", frac.num, frac.denom);
}

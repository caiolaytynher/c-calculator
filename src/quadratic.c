#include "quadratic.h"
#include "fraction.h"
#include "square_root.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

ComplexAns qd_create(Frac frac, SqrRoot root, bool is_complex) {
  ComplexAns complex_ans = {frac, root, is_complex};

  return complex_ans;
}

bool qd_is_equal(ComplexAns a, ComplexAns b) {
  if (fr_is_equal(a.frac, b.frac) && rt_is_equal(a.root, b.root) &&
      a.is_complex == b.is_complex)
    return true;

  return false;
}

QuadAns qd_solve(int a, int b, int c) {
  ComplexAns x1, x2;
  x1 = x2 = qd_create(fr_create(0, 1), rt_create(fr_create(0, 1), 0), false);

  int delta = b * b - 4 * a * c;
  SqrRoot delta_root = rt_simplify(rt_create(fr_create(1, 2 * a), abs(delta)));
  x1.frac = x2.frac = fr_simplify(fr_create(-b, 2 * a));

  if (delta != 0) {
    x1.root = x2.root = delta_root;
    x2.root.scalar.num *= -1;
  }

  if (delta < 0) {
    x1.is_complex = x2.is_complex = true;
  }

  if (delta > 0 && delta_root.root == 1) {
    x1.frac = fr_sum(x1.frac, delta_root.scalar);
    x2.frac = fr_sub(x2.frac, delta_root.scalar);

    // TODO: remove redundance, use the default values
    x1.root = x2.root = rt_create(fr_create(0, 1), 0);
  }

  QuadAns quad_ans = {x1, x2};
  return quad_ans;
}

void qd_to_str(ComplexAns complex_ans, char *string) {
  bool frac_is_zero = complex_ans.frac.num == 0;
  bool root_is_zero =
      complex_ans.root.root == 0 || complex_ans.root.scalar.num == 0;

  if (frac_is_zero && root_is_zero) {
    sprintf(string, "%d", 0);
    return;
  }

  char frac_str[10];
  fr_to_str(complex_ans.frac, frac_str);

  if (root_is_zero) {
    sprintf(string, "%s", frac_str);
    return;
  }

  char root_str[15];
  rt_to_str(complex_ans.root, root_str);

  if (frac_is_zero) {
    if (!complex_ans.is_complex) {
      sprintf(string, "%s", root_str);
      return;
    }

    sprintf(string, "%s i", root_str);
    return;
  }

  if (!complex_ans.is_complex) {
    sprintf(string, "%s + %s", frac_str, root_str);
    return;
  }

  sprintf(string, "%s + %s i", frac_str, root_str);
}

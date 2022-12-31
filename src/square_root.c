#include "square_root.h"
#include "fraction.h"
#include "more_math.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

SqrRoot rt_create(Frac scalar, int root) {
  SqrRoot sqr_root = {scalar, root};

  return sqr_root;
}

bool rt_is_equal(SqrRoot a, SqrRoot b) {
  if (fr_is_equal(a.scalar, b.scalar) && a.root == b.root)
    return true;

  return false;
}

SqrRoot rt_simplify(SqrRoot sqr_root) {
  int perfect_square = mm_find_higher_perfect_square(sqr_root.root);
  int square_complement =
      mm_find_square_complement(sqr_root.root, perfect_square);

  Frac scalar = fr_simplify(fr_create(
      sqr_root.scalar.num * sqrt(perfect_square), sqr_root.scalar.denom));

  return rt_create(scalar, square_complement);
}

void rt_to_str(SqrRoot sqr_root, char *string) {
  if (sqr_root.root == 0 || sqr_root.scalar.num == 0) {
    sprintf(string, "%d", 0);
    return;
  }

  char frac_str[10];
  fr_to_str(sqr_root.scalar, frac_str);

  if (sqr_root.root == 1) {
    sprintf(string, "%s", frac_str);
    return;
  }

  sprintf(string, "(%s)sqrt(%d)", frac_str, sqr_root.root);
}

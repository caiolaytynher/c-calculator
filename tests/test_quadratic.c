#include "../src/quadratic.h"
#include <criterion/criterion.h>

typedef struct {
  int a;
  int b;
  int c;
} QuadEq;

QuadEq create(int a, int b, int c) {
  QuadEq quad_eq = {a, b, c};
  return quad_eq;
}

Test(quadratic, solver) {
  QuadEq test_cases[] = {
      create(1, -3, 2), create(1, 1, 1),  create(1, -2, 1), create(1, -2, 5),
      create(1, 2, -5), create(1, 3, -5), create(1, 3, 0),  create(1, 0, 5),
  };

  ComplexAns expected_results[][2] = {
      {
          qd_create(fr_create(2, 1), rt_create(fr_create(0, 1), 0), false),
          qd_create(fr_create(1, 1), rt_create(fr_create(0, 1), 0), false),
      },
      {
          qd_create(fr_create(-1, 2), rt_create(fr_create(1, 2), 3), true),
          qd_create(fr_create(-1, 2), rt_create(fr_create(-1, 2), 3), true),
      },
      {
          qd_create(fr_create(1, 1), rt_create(fr_create(0, 1), 0), false),
          qd_create(fr_create(1, 1), rt_create(fr_create(0, 1), 0), false),
      },
      {
          qd_create(fr_create(1, 1), rt_create(fr_create(2, 1), 1), true),
          qd_create(fr_create(1, 1), rt_create(fr_create(-2, 1), 1), true),
      },
      {
          qd_create(fr_create(-1, 1), rt_create(fr_create(1, 1), 6), false),
          qd_create(fr_create(-1, 1), rt_create(fr_create(-1, 1), 6), false),
      },
      {
          qd_create(fr_create(-3, 2), rt_create(fr_create(1, 2), 29), false),
          qd_create(fr_create(-3, 2), rt_create(fr_create(-1, 2), 29), false),
      },
      {
          qd_create(fr_create(0, 1), rt_create(fr_create(0, 1), 0), false),
          qd_create(fr_create(-3, 1), rt_create(fr_create(0, 1), 0), false),
      },
      {
          qd_create(fr_create(0, 1), rt_create(fr_create(1, 1), 5), true),
          qd_create(fr_create(0, 1), rt_create(fr_create(-1, 1), 5), true),
      },
  };

  QuadEq tc;
  QuadAns ans;
  ComplexAns x1, x2;
  for (int i = 0; i < 8; i++) {
    tc = test_cases[i];
    ans = qd_solve(tc.a, tc.b, tc.c);
    x1 = expected_results[i][0];
    x2 = expected_results[i][1];

    cr_expect(qd_is_equal(ans.x1, x1));
    cr_expect(qd_is_equal(ans.x2, x2));
  }
}

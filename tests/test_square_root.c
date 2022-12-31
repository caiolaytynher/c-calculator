#include "../src/square_root.h"
#include <criterion/criterion.h>

Test(square_root, create) {
  SqrRoot sqr_root = rt_create(fr_create(2, 3), 3);

  cr_expect(sqr_root.scalar.num == 2);
  cr_expect(sqr_root.scalar.denom == 3);
  cr_expect(sqr_root.root == 3);
}

Test(square_root, simplify) {
  SqrRoot test_cases[] = {
      rt_create(fr_create(1, 1), 25), rt_create(fr_create(1, 1), 10),
      rt_create(fr_create(1, 2), 20), rt_create(fr_create(1, 5), 16),
      rt_create(fr_create(1, 5), 32),
  };

  SqrRoot expected_results[] = {
      rt_create(fr_create(5, 1), 1), rt_create(fr_create(1, 1), 10),
      rt_create(fr_create(1, 1), 5), rt_create(fr_create(4, 5), 1),
      rt_create(fr_create(4, 5), 2),
  };

  SqrRoot test_case;
  for (int i = 0; i < 5; i++) {
    test_case = rt_simplify(test_cases[i]);

    cr_expect(rt_is_equal(test_case, expected_results[i]));
  }
}

#include "../src/fraction.h"
#include <criterion/criterion.h>
#include <stdbool.h>

Test(fraction, create) {
  Frac frac = fr_create(1, 2);

  cr_expect(frac.num == 1, "expected num = 1");
  cr_expect(frac.denom == 2, "expected denom = 2");
}

Test(fraction, equal) {
  Frac frac = fr_create(3, 2);
  bool is_equal = fr_is_equal(frac, frac);

  cr_expect(is_equal, "Is equal");
}

Test(fraction, simplify) {
  Frac test_cases[] = {
      fr_create(2, 4), fr_create(6, 9), fr_create(1, 2),  fr_create(8, 4),
      fr_create(5, 5), fr_create(0, 4), fr_create(-4, 8), fr_create(10, -2),
  };
  Frac expected_results[] = {
      fr_create(1, 2), fr_create(2, 3), fr_create(1, 2),  fr_create(2, 1),
      fr_create(1, 1), fr_create(0, 1), fr_create(-1, 2), fr_create(-5, 1),
  };

  Frac test_case;
  Frac expected_result;
  for (int i = 0; i < 8; i++) {
    test_case = fr_simplify(test_cases[i]);
    expected_result = expected_results[i];
    cr_expect(fr_is_equal(test_case, expected_result));
  }
}

Test(fraction, sum) {
  Frac test_cases[] = {
      fr_sum(fr_create(1, 2), fr_create(1, 2)),
      fr_sum(fr_create(1, 3), fr_create(1, 4)),
      fr_sum(fr_create(1, 2), fr_create(3, 1)),
      fr_sum(fr_create(-1, 2), fr_create(-1, 3)),
      fr_sum(fr_create(1, 2), fr_create(0, 1)),
  };

  Frac expected_results[] = {
      fr_create(1, 1),  fr_create(7, 12), fr_create(7, 2),
      fr_create(-5, 6), fr_create(1, 2),
  };

  for (int i = 0; i < 5; i++) {
    cr_expect(fr_is_equal(test_cases[i], expected_results[i]));
  }
}

Test(fraction, sub) {
  Frac test_cases[] = {
      fr_sub(fr_create(1, 2), fr_create(1, 2)),
      fr_sub(fr_create(1, 3), fr_create(1, 4)),
      fr_sub(fr_create(1, 2), fr_create(3, 1)),
      fr_sub(fr_create(-1, 2), fr_create(-1, 3)),
      fr_sub(fr_create(1, 2), fr_create(0, 1)),
  };

  Frac expected_results[] = {
      fr_create(0, 1),  fr_create(1, 12), fr_create(-5, 2),
      fr_create(-1, 6), fr_create(1, 2),
  };

  for (int i = 0; i < 5; i++) {
    cr_expect(fr_is_equal(test_cases[i], expected_results[i]));
  }
}

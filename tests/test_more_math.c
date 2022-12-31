#include "../src/more_math.h"
#include <criterion/criterion.h>
#include <stdbool.h>

Test(gcd, functionality) {
  cr_expect(mm_gcd(2, 3) == 1);
  cr_expect(mm_gcd(1071, 462) == 21);
  cr_expect(mm_gcd(-24, -36) == 12);
  cr_expect(mm_gcd(24, -36) == 12);
  cr_expect(mm_gcd(0, 0) == 0);
  cr_expect(mm_gcd(24, 0) == 24);
  cr_expect(mm_gcd(-24, 0) == 24);
}

Test(lcm, functionality) {
  cr_expect(mm_lcm(2, 3) == 6);
  cr_expect(mm_lcm(1071, 462) == 23562);
  cr_expect(mm_lcm(-24, -36) == 72);
  cr_expect(mm_lcm(24, -36) == 72);
  cr_expect(mm_lcm(0, 0) == 0);
  cr_expect(mm_lcm(24, 0) == 0);
  cr_expect(mm_lcm(-24, 0) == 0);
}

Test(is_perfect_square, functionality) {
  for (int i = 0; i < 10; i++)
    cr_expect(mm_is_perfect_square(i * i));

  cr_expect(mm_is_perfect_square(24) == false);
  cr_expect(mm_is_perfect_square(12) == false);
  cr_expect(mm_is_perfect_square(7) == false);
}

Test(find_higher_perfect_square, functionality) {
  cr_expect(mm_find_higher_perfect_square(10) == 1);
  cr_expect(mm_find_higher_perfect_square(20) == 4);
  cr_expect(mm_find_higher_perfect_square(36) == 36);
  cr_expect(mm_find_higher_perfect_square(150) == 25);
  cr_expect(mm_find_higher_perfect_square(112) == 16);
  cr_expect(mm_find_higher_perfect_square(468) == 36);
  cr_expect(mm_find_higher_perfect_square(1) == 1);
  cr_expect(mm_find_higher_perfect_square(0) == 0);
}

Test(find_square_complement, functionality) {
  cr_expect(mm_find_square_complement(10, 1) == 10);
  cr_expect(mm_find_square_complement(20, 4) == 5);
  cr_expect(mm_find_square_complement(36, 36) == 1);
  cr_expect(mm_find_square_complement(150, 25) == 6);
  cr_expect(mm_find_square_complement(112, 16) == 7);
  cr_expect(mm_find_square_complement(468, 36) == 13);
  cr_expect(mm_find_square_complement(1, 1) == 1);
  cr_expect(mm_find_square_complement(0, 0) == 1);
}

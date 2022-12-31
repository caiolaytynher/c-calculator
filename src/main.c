#include "math_wrappers.h"
#include "menu.h"
#include "quadratic.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int option;
  double ans;

  QuadAns quad_ans;
  char x1_str[32];
  char x2_str[32];

  do {
    option = main_menu();

    switch (option) {
    case ADDITION:
      ans = mw_sum();
      printf("Result: %.2lf\n", ans);
      continue;
    case SUBTRACTION:
      ans = mw_sub();
      printf("Result: %.2lf\n", ans);
      continue;
    case MULTIPLICATION:
      ans = mw_mul();
      printf("Result: %.2lf\n", ans);
      continue;
    case DIVISION:
      ans = mw_div();
      printf("Result: %.2lf\n", ans);
      continue;
    case POWER:
      ans = mw_pow();
      printf("Result: %.2lf\n", ans);
      continue;
    case MEAN:
      ans = mw_mean();
      printf("Result: %.2lf\n", ans);
      continue;
    case MAX:
      ans = mw_max();
      printf("Result: %.2lf\n", ans);
      continue;
    case MIN:
      ans = mw_min();
      printf("Result: %.2lf\n", ans);
      continue;
    case QUADRATIC:
      quad_ans = wm_quadratic();

      qd_to_str(quad_ans.x1, x1_str);
      qd_to_str(quad_ans.x2, x2_str);

      printf("x1: %s\nx2: %s\n", x1_str, x2_str);
      continue;
    default:
      break;
    }
  } while (option != 0);

  return 0;
}

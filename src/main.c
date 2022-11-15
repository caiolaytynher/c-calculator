#include "calc_wrappers.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int option;
  double ans;

  do {
    option = main_menu();

    switch (option) {
    case 1:
      ans = make_sum();
      printf("Result: %.2lf\n", ans);
      continue;
    case 2:
      ans = make_sub();
      printf("Result: %.2lf\n", ans);
      continue;
    case 3:
      ans = make_mul();
      printf("Result: %.2lf\n", ans);
      continue;
    case 4:
      ans = make_div();
      printf("Result: %.2lf\n", ans);
      continue;
    case 5:
      ans = make_pow();
      printf("Result: %.2lf\n", ans);
      continue;
    case 6:
      ans = make_mean();
      printf("Result: %.2lf\n", ans);
      continue;
    case 7:
      ans = make_max();
      printf("Result: %.2lf\n", ans);
      continue;
    case 8:
      ans = make_min();
      printf("Result: %.2lf\n", ans);
      continue;
    case 9:
      ans = make_min();
      printf("Result: %.2lf\n", ans);
      continue;
    default:
      break;
    }
  } while (option != 0);

  return 0;
}

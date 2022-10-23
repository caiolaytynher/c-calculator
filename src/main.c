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
      ans = get_sum();
      printf("Result: %.2lf\n", ans);
      continue;
    case 2:
      ans = get_sub();
      printf("Result: %.2lf\n", ans);
      continue;
    case 3:
      ans = get_mul();
      printf("Result: %.2lf\n", ans);
      continue;
    case 4:
      ans = get_div();
      printf("Result: %.2lf\n", ans);
      continue;
    case 5:
      ans = get_pow();
      printf("Result: %.2lf\n", ans);
      continue;
    case 6:
      ans = get_mean();
      printf("Result: %.2lf\n", ans);
      continue;
    case 7:
      ans = get_max();
      printf("Result: %.2lf\n", ans);
      continue;
    case 8:
      ans = get_min();
      printf("Result: %.2lf\n", ans);
      continue;
    case 9:
      ans = get_min();
      printf("Result: %.2lf\n", ans);
      continue;
    default:
      break;
    }
  } while (option != 0);

  return 0;
}

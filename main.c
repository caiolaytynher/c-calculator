#include "calculations.h"
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
      printf("Result: %.2f\n", ans);
      continue;
    case 2:
      ans = get_sub();
      printf("Result: %.2f\n", ans);
      continue;
    case 3:
      ans = get_mul();
      printf("Result: %.2f\n", ans);
      continue;
    default:
      break;
    }
  } while (option != 0);

  return 0;
}

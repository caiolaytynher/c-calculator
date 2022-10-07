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
      printf("Result: %.2fl\n", ans);
      continue;
    default:
      break;
    }
  } while (option != 0);

  return 0;
}

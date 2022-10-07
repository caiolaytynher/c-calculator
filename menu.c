#include <stdio.h>

int main_menu() {
  int option;

  printf("Main menu.\n"
         "Basic calculations:\n"
         "\t1) Addition (+)\n"
         "\t2) Subtraction (-)\n"
         "\t3) Multiplication (*)\n"
         "\t4) Division (/)\n"
         "\t5) Power (^)\n"
         "Statistics:\n"
         "\t6) Mean\n"
         "\t7) Max\n"
         "\t8) Min\n"
         "Advanced calculations:\n"
         "\t9) Quadratic equations\n"
         "Choose an option: ");
  scanf("%d", &option);

  while (option < 0 || option > 9) {
    printf("Not a valid option. Please try again: ");
    scanf("%d", &option);
  }

  return option;
}

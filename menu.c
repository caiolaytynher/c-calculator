#include <stdio.h>

int main_menu() {
  int option;
  while (1) {
    printf("Main menu.\n"
           "1) Addition (+)\n"
           "2) Subtraction (-)\n"
           "3) Multiplication (*)\n"
           "4) Division (/)\n"
           "Choose an option: ");

    scanf("%d", &option);
    if (option > 0 && option < 3)
      break;

    printf("Not a valid option. Please try again: ");
  }

  return option;
}

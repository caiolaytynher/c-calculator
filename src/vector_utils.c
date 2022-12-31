#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vec_fill(Vector *vector, const char *prompt, const char *stop_flag) {
  char input[16];
  double num;

  printf("Type \"%s\" to stop.\n", stop_flag);
  printf("%s", prompt);
  while (true) {
    fscanf(stdin, "%s", input);

    if (strcmp(input, stop_flag) == 0)
      break;

    num = (double)strtod(input, NULL);
    vec_append(vector, num);
  }
}

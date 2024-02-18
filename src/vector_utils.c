#include "vector_utils.h"
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

void vec_save(Vector *vector, DataFile file_name) {
  char *file_path;

  switch ((int)file_name) {
  case DATA_FILE_SUM:
    file_path = strcat(DATA_FILE, "sum.txt");
    break;
  case DATA_FILE_SUB:
    file_path = strcat(DATA_FILE, "subtraction.txt");
    break;
  case DATA_FILE_MUL:
    file_path = strcat(DATA_FILE, "multiplication.txt");
    break;
  case DATA_FILE_DIV:
    file_path = strcat(DATA_FILE, "division.txt");
    break;
  case DATA_FILE_MEAN:
    file_path = strcat(DATA_FILE, "mean.txt");
    break;
  case DATA_FILE_MAX:
    file_path = strcat(DATA_FILE, "max.txt");
    break;
  case DATA_FILE_MIN:
    file_path = strcat(DATA_FILE, "min.txt");
    break;
  }

  FILE *file = fopen(file_path, "a");
  if (file == NULL) {
    vec_delete(&vector);
    perror("Not able to create file.\n");
  }

  fputs("Input: ", file);
  for (size_t i = 0; i < vec_get_size(vector); i++) {
    // fprintf(file, "%d, ")
  }

  if (file != NULL)
    fclose(file);
}

#include <stdio.h>
#include <stdlib.h>

void populate_arr(double *arr, size_t size, const char *prompt) {
  printf("%s", prompt);
  for (size_t i = 0; i < size; i++)
    scanf("%lf", &arr[i]);
}

size_t get_size(const char *prompt, size_t min_val) {
  size_t size;
  printf("%s", prompt);
  scanf("%zu", &size);

  while (size < min_val) {
    printf("The min value is %zu. Please try again: ", min_val);
    scanf("%zu", &size);
  }

  return size;
}

double *create_double_array(size_t size) {
  double *array = malloc(size * sizeof(double));
  if (array == NULL)
    perror("Not able to allocate memory.\n");

  return array;
}

void delete_double_array(double *array) {
  free(array);
  array = NULL;
}
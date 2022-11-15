#include <stdbool.h>
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

bool is_in(int target, int *array, size_t size) {
  for (size_t i = 0; i < size; i++) {
    if (target == array[i])
      return true;
  }

  return false;
}

int index_of(int target, int *array, size_t size) {
  for (size_t i = 0; i < size; i++) {
    if (target == array[i])
      return i;
  }

  return -1;
}

void array_print(int *array, size_t size) {
  printf("[");

  for (size_t i = 0; i < size - 1; i++)
    printf("%d, ", array[i]);

  printf("%d]\n", array[size - 1]);
}

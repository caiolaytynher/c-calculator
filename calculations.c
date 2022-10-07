#include <stdio.h>
#include <stdlib.h>

size_t _get_size(const char *prompt, size_t min_val) {
  size_t size;
  printf("%s", prompt);
  scanf("%zu", &size);

  while (size < min_val) {
    printf("The min value is %zu. Please try again: ", size);
    scanf("%zu", &size);
  }

  return size;
}

double get_sum() {
  double *nums = NULL;
  size_t size = _get_size("Choose how many numbers to sum: ", 2);
  double sum = 0.0;

  // TODO: research for calloc
  nums = malloc(size * sizeof(double));
  if (nums == NULL) {
    // TODO: research for perror
    perror("Not able to allocate memory.\n");
  }

  printf("Choose your numbers: ");
  for (size_t i = 0; i < size; i++) {
    scanf("%lf", &nums[i]);
  }

  for (size_t i = 0; i < size; i++) {
    sum += nums[i];
  }

  free(nums);
  return sum;
}

double get_sub() {
  double *nums = NULL;
  size_t size = _get_size("Choose how many numbers to subtract: ", 2);

  // TODO: research for calloc
  nums = malloc(size * sizeof(double));
  if (nums == NULL) {
    // TODO: research for perror
    perror("Not able to allocate memory.\n");
  }

  printf("Choose your numbers: ");
  for (size_t i = 0; i < size; i++) {
    scanf("%lf", &nums[i]);
  }

  double sub = nums[0];

  for (size_t i = 1; i < size; i++) {
    sub -= nums[i];
  }

  free(nums);
  return sub;
}

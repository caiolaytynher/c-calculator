#include <stdio.h>
#include <stdlib.h>

size_t _get_size(const char *prompt) {
  size_t size;
  printf("%s", prompt);
  scanf("%zu", &size);

  return size;
}

double get_sum() {
  double *nums = NULL;
  size_t size = _get_size("Choose how many numbers to sum: ");
  double sum = 0.0;

  nums = malloc(size * sizeof(double));
  if (nums == NULL) {
    perror("Not able to alloc memory.\n");
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

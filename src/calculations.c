#include "custom_math.h"
#include "helper_funcs.h"
#include <stdio.h>
#include <stdlib.h>

double get_sum() {
  double *nums = NULL;
  size_t size = get_size("Choose how many numbers to sum: ", 2);

  // TODO: research for calloc and perror
  nums = malloc(size * sizeof(double));
  if (nums == NULL)
    perror("Not able to allocate memory.\n");

  populate_arr(nums, size, "Choose your numbers: ");
  double sum = sum_arr(nums, size);

  free(nums);
  return sum;
}

double get_sub() {
  double *nums = NULL;
  size_t size = get_size("Choose how many numbers to subtract: ", 2);

  // TODO: research for calloc and perror
  nums = malloc(size * sizeof(double));
  if (nums == NULL)
    perror("Not able to allocate memory.\n");

  populate_arr(nums, size, "Choose your numbers: ");
  double sub = sub_arr(nums, size);

  free(nums);
  return sub;
}

double get_mul() {
  double *nums = NULL;
  size_t size = get_size("Choose how many numbers to multiply: ", 2);

  // TODO: research for calloc and perror
  nums = malloc(size * sizeof(double));
  if (nums == NULL)
    perror("Not able to allocate memory.\n");

  populate_arr(nums, size, "Choose your numbers: ");
  double mul = mul_arr(nums, size);

  free(nums);
  return mul;
}

double get_div() {
  double *nums = NULL;
  size_t size = get_size("Choose how many numbers to multiply: ", 2);

  // TODO: research for calloc and perror
  nums = malloc(size * sizeof(double));
  if (nums == NULL)
    perror("Not able to allocate memory.\n");

  populate_arr(nums, size, "Choose your numbers: ");
  double div = sub_arr(nums, size);

  free(nums);
  return div;
}

double get_pow() {
  double base;
  printf("Base: ");
  scanf("%lf", &base);

  int power;
  printf("Power: ");
  scanf("%d", &power);

  double ans = make_pow(base, power);

  return ans;
}

double get_mean() {
  double *nums = NULL;
  size_t size = get_size("Choose how many numbers to store: ", 1);

  // TODO: research for calloc and perror
  nums = malloc(size * sizeof(double));
  if (nums == NULL)
    perror("Not able to allocate memory.\n");

  populate_arr(nums, size, "Choose your numbers: ");

  double sum = sum_arr(nums, size);

  free(nums);
  return sum / size;
}

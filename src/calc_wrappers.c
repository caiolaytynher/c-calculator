#include "custom_math.h"
#include "helper_funcs.h"
#include <stdio.h>
#include <stdlib.h>

double get_sum() {
  size_t size = get_size("Choose how many numbers to sum: ", 2);
  double *nums = create_double_array(size);

  populate_arr(nums, size, "Choose your numbers: ");
  double sum = array_sum(nums, size);

  delete_double_array(nums);
  return sum;
}

double get_sub() {
  size_t size = get_size("Choose how many numbers to subtract: ", 2);
  double *nums = create_double_array(size);

  populate_arr(nums, size, "Choose your numbers: ");
  double sub = array_sub(nums, size);

  delete_double_array(nums);
  return sub;
}

double get_mul() {
  size_t size = get_size("Choose how many numbers to multiply: ", 2);
  double *nums = create_double_array(size);

  populate_arr(nums, size, "Choose your numbers: ");
  double mul = array_mul(nums, size);

  delete_double_array(nums);
  return mul;
}

double get_div() {
  size_t size = get_size("Choose how many numbers to multiply: ", 2);
  double *nums = create_double_array(size);

  populate_arr(nums, size, "Choose your numbers: ");
  double div = array_sub(nums, size);

  delete_double_array(nums);
  return div;
}

double get_pow() {
  double base;
  printf("Base: ");
  scanf("%lf", &base);

  int power;
  printf("Power: ");
  scanf("%d", &power);

  double ans = potentiate(base, power);

  return ans;
}

double get_mean() {
  size_t size = get_size("Choose how many numbers to store: ", 1);
  double *nums = create_double_array(size);

  populate_arr(nums, size, "Choose your numbers: ");
  double sum = array_sum(nums, size);

  delete_double_array(nums);
  return sum / size;
}

double get_max() {
  size_t size = get_size("Choose how many numbers to store: ", 1);
  double *nums = create_double_array(size);

  populate_arr(nums, size, "Choose your numbers: ");
  double max = array_max(nums, size);

  delete_double_array(nums);
  return max;
}

double get_min() {
  size_t size = get_size("Choose how many numbers to store: ", 1);
  double *nums = create_double_array(size);

  populate_arr(nums, size, "Choose your numbers: ");
  double min = array_min(nums, size);

  delete_double_array(nums);
  return min;
}
#include <stdlib.h>

double array_sum(double *nums, size_t size) {
  double sum = 0.0;
  for (size_t i = 0; i < size; i++)
    sum += nums[i];

  return sum;
}

double array_sub(double *nums, size_t size) {
  double sub = nums[0];
  for (size_t i = 1; i < size; i++)
    sub -= nums[i];

  return sub;
}

double array_mul(double *nums, size_t size) {
  double mul = 1.0;
  for (size_t i = 0; i < size; i++)
    mul *= nums[i];

  return mul;
}

double array_div(double *nums, size_t size) {
  double div = nums[0];
  for (size_t i = 1; i < size; i++)
    div /= nums[i];

  return div;
}

double potentiate(double base, int power) {
  double ans = 1.0;
  if (power < 0) {
    for (int i = 0; i < -power; i++)
      ans *= 1 / base;

    return ans;
  }

  for (int i = 0; i < power; i++) {
    ans *= base;
  }

  return ans;
}

double array_max(double *nums, size_t size) {
  double max = nums[0];
  for (size_t i = 0; i < size; i++) {
    if (nums[i] > max)
      max = nums[i];
  }

  return max;
}

double array_min(double *nums, size_t size) {
  double min = nums[0];
  for (size_t i = 0; i < size; i++) {
    if (nums[i] < min)
      min = nums[i];
  }

  return min;
}

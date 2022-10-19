#include <stdlib.h>

double sum_arr(double *nums, size_t size) {
  double sum = 0.0;

  for (size_t i = 0; i < size; i++)
    sum += nums[i];

  return sum;
}

double sub_arr(double *nums, size_t size) {
  double sub = nums[0];
  for (size_t i = 1; i < size; i++)
    sub -= nums[i];

  return sub;
}

double mul_arr(double *nums, size_t size) {
  double mul = 1.0;

  for (size_t i = 0; i < size; i++)
    mul *= nums[i];

  return mul;
}

double div_arr(double *nums, size_t size) {
  double div = nums[0];
  for (size_t i = 1; i < size; i++)
    div /= nums[i];

  return div;
}

double make_pow(double base, int power) {
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

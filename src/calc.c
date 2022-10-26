#include <stdbool.h>
#include <stdio.h>
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

double array_max_double(double *nums, size_t size) {
  double max = nums[0];
  for (size_t i = 0; i < size; i++) {
    if (nums[i] > max)
      max = nums[i];
  }

  return max;
}

int array_max_int(int *nums, size_t size) {
  int max = nums[0];
  for (size_t i = 0; i < size; i++) {
    if (nums[i] > max)
      max = nums[i];
  }

  printf("returned %d\n", max);
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

void find_prime_factors(int num, int *prime_factors, size_t size) {
  int factor_counter = 0;
  for (int i = 2; num > 1; i++) {
    if (factor_counter == size)
      return;

    while (num % i == 0) {
      prime_factors[factor_counter] = i;
      num /= i;
      factor_counter++;
    }
  }

  for (size_t i = factor_counter; i < size; i++) {
    prime_factors[i] = 0;
  }
}

int array_count(int target, int *nums, size_t size) {
  int counter = 0;
  for (size_t i = 0; i < size; i++) {
    if (nums[i] == target)
      counter++;
  }

  return counter;
}

bool is_prime(int num) {
  for (int i = 2; i < num; i++) {
    if (num % i == 0)
      return false;
  }

  return true;
}

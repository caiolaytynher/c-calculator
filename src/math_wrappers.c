#include "quadratic.h"
#include "vector.h"
#include "vector_math.h"
#include "vector_utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double mw_sum() {
  Vector *nums = vec_create();

  vec_fill(nums, "Choose your numbers: ", "=");
  double total = vec_sum(nums);

  vec_delete(&nums);
  return total;
}

double mw_sub() {
  Vector *nums = vec_create();

  vec_fill(nums, "Choose your numbers: ", "=");
  double total = vec_sub(nums);

  vec_delete(&nums);
  return total;
}

double mw_mul() {
  Vector *nums = vec_create();

  vec_fill(nums, "Choose your numbers: ", "=");
  double total = vec_mul(nums);

  vec_delete(&nums);
  return total;
}

double mw_div() {
  Vector *nums = vec_create();

  vec_fill(nums, "Choose your numbers: ", "=");
  double total = vec_div(nums);

  vec_delete(&nums);
  return total;
}

double mw_pow() {
  double base;
  printf("Base: ");
  scanf("%lf", &base);

  int power;
  printf("Power: ");
  scanf("%d", &power);

  double ans = pow(base, power);

  return ans;
}

double mw_mean() {
  Vector *nums = vec_create();

  vec_fill(nums, "Choose your numbers: ", "=");
  double mean = vec_mean(nums);

  vec_delete(&nums);
  return mean;
}

double mw_max() {
  Vector *nums = vec_create();

  vec_fill(nums, "Choose your numbers: ", "=");
  double max = vec_max(nums);

  vec_delete(&nums);
  return max;
}

double mw_min() {
  Vector *nums = vec_create();

  vec_fill(nums, "Choose your numbers: ", "=");
  double min = vec_min(nums);

  vec_delete(&nums);
  return min;
}

QuadAns wm_quadratic() {
  int a, b, c;

  printf("Equation format: (a)x^2 + (b)x + (c).\n"
         "a: ");
  scanf("%d", &a);
  printf("b: ");
  scanf("%d", &b);
  printf("c: ");
  scanf("%d", &c);

  QuadAns quad_ans = qd_solve(a, b, c);

  return quad_ans;
}

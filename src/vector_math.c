#include "vector.h"

double vec_sum(Vector *vector) {
  size_t size = vec_get_size(vector);
  if (size == 0)
    return 0.0;

  double total = 0.0;
  for (size_t i = 0; i < size; i++)
    total += vec_get(vector, i);

  return total;
}

double vec_sub(Vector *vector) {
  size_t size = vec_get_size(vector);
  if (size == 0)
    return 0.0;

  double total = vec_get(vector, 0);
  for (size_t i = 1; i < size; i++)
    total -= vec_get(vector, i);

  return total;
}

double vec_mul(Vector *vector) {
  size_t size = vec_get_size(vector);
  if (size == 0)
    return 0.0;

  double total = 1.0;
  for (size_t i = 0; i < size; i++)
    total *= vec_get(vector, i);

  return total;
}

double vec_div(Vector *vector) {
  size_t size = vec_get_size(vector);
  if (size == 0)
    return 0.0;

  double total = vec_get(vector, 0);
  for (size_t i = 1; i < size; i++)
    total /= vec_get(vector, i);

  return total;
}

double vec_mean(Vector *vector) {
  size_t size = vec_get_size(vector);
  if (size == 0)
    return 0.0;

  double sum = vec_sum(vector);

  return sum / size;
}

double vec_max(Vector *vector) {
  size_t size = vec_get_size(vector);
  if (size == 0)
    return 0.0;

  double max = vec_get(vector, 0);
  double current_value;
  for (size_t i = 1; i < size; i++) {
    current_value = vec_get(vector, i);

    if (current_value > max)
      max = current_value;
  }

  return max;
}

double vec_min(Vector *vector) {
  size_t size = vec_get_size(vector);
  if (size == 0)
    return 0.0;

  double min = vec_get(vector, 0);
  double current_value;
  for (size_t i = 1; i < size; i++) {
    current_value = vec_get(vector, i);

    if (current_value < min)
      min = current_value;
  }

  return min;
}

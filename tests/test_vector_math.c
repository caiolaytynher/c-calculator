#include "../src/vector.h"
#include "../src/vector_math.h"
#include <criterion/criterion.h>

Test(vector, sum) {
  Vector *vector = vec_create();
  for (int i = 1; i <= 5; i++)
    vec_append(vector, i);

  double total = vec_sum(vector);

  cr_expect(total == 15.0);

  vec_delete(&vector);
}

Test(vector, sub) {
  Vector *vector = vec_create();
  for (int i = 1; i <= 5; i++)
    vec_append(vector, i);

  double total = vec_sub(vector);

  cr_expect(total == -13.0);

  vec_delete(&vector);
}

Test(vector, mul) {
  Vector *vector = vec_create();
  for (int i = 1; i <= 5; i++)
    vec_append(vector, i);

  double total = vec_mul(vector);

  cr_expect(total == 120.0);

  vec_delete(&vector);
}

Test(vector, div) {
  Vector *vector = vec_create();
  vec_append(vector, 100);
  for (int _ = 0; _ <= 1; _++)
    vec_append(vector, 2);

  double total = vec_div(vector);

  cr_expect(total == 25.0);

  vec_delete(&vector);
}

Test(vector, mean) {
  Vector *vector = vec_create();
  for (int i = 1; i <= 5; i++)
    vec_append(vector, i);

  double total = vec_mean(vector);

  cr_expect(total == 3.0);

  vec_delete(&vector);
}

Test(vector, max) {
  Vector *vector = vec_create();
  for (int i = 1; i <= 5; i++)
    vec_append(vector, i);

  double total = vec_max(vector);

  cr_expect(total == 5.0);

  vec_delete(&vector);
}

Test(vector, min) {
  Vector *vector = vec_create();
  for (int i = 1; i <= 5; i++)
    vec_append(vector, i);

  double total = vec_min(vector);

  cr_expect(total == 1.0);

  vec_delete(&vector);
}

#include "../src/vector.h"
#include <criterion/criterion.h>
#include <stdio.h>

Test(vector, creation) {
  Vector *vector = vec_create();
  cr_expect(vec_get_size(vector) == 0);

  vec_delete(&vector);
  cr_expect(vector == NULL);
}

Test(vector, append) {
  Vector *vector = vec_create();
  for (int i = 0; i < 10; i++)
    vec_append(vector, i);

  for (int i = 0; i < 10; i++)
    cr_expect(vec_get(vector, i) == i);

  cr_expect(vec_get_size(vector) == 10);

  vec_delete(&vector);
}

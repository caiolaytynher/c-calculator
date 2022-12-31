#include "vector.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct _Vector {
  double *values;
  size_t size;
  size_t capacity;
};

Vector *vec_create() {
  Vector *vector = malloc(sizeof(Vector));
  if (vector == NULL)
    perror("Unable to create vector.\n");

  vector->values = malloc(MIN_VEC_CAPACITY * sizeof(double));
  if (vector->values == NULL) {
    free(vector);
    vector = NULL;
    perror("Unable to create vector values array.\n");
  }

  vector->size = 0;
  vector->capacity = MIN_VEC_CAPACITY;

  return vector;
}

void vec_delete(Vector **vector) {
  if ((*vector)->values != NULL) {
    free((*vector)->values);
    (*vector)->values = NULL;
  }

  if (*vector != NULL) {
    free(*vector);
    *vector = NULL;
  }
}

double vec_get(Vector *vector, int index) {
  if (index > vector->size - 1) {
    vec_delete(&vector);
    perror("Array index out of range.\n");
  }

  return vector->values[index];
}

void vec_set(Vector *vector, double number, int index) {
  if (index > vector->size - 1) {
    vec_delete(&vector);
    perror("Array index out of range.\n");
  }

  vector->values[index] = number;
}

size_t vec_get_size(Vector *vector) { return vector->size; }

void vec_append(Vector *vector, double value) {
  if (vector->capacity == vector->size) {
    vector->capacity += vector->capacity / 2;
    vector->values = realloc(vector->values, vector->capacity * sizeof(double));
  }

  vector->values[vector->size] = value;
  vector->size++;
}

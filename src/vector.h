#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>

#define MIN_VEC_CAPACITY 2

typedef struct _Vector Vector;

Vector *vec_create();
void vec_delete(Vector **);
double vec_get(Vector *, int);
void vec_set(Vector *, double, int);
size_t vec_get_size(Vector *);
void vec_append(Vector *, double);

#endif

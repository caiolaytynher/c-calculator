#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H

#include "vector.h"

#define DATA_FILE "data/"

typedef enum {
  DATA_FILE_SUM,
  DATA_FILE_SUB,
  DATA_FILE_MUL,
  DATA_FILE_DIV,
  DATA_FILE_MEAN,
  DATA_FILE_MAX,
  DATA_FILE_MIN,
} DataFile;

void vec_fill(Vector *, const char *, const char *);
void vec_save(Vector *, DataFile);

#endif

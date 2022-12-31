#ifndef SQUARE_ROOT_H
#define SQUARE_ROOT_H

#include "fraction.h"
#include <stdbool.h>

typedef struct {
  Frac scalar;
  int root;
} SqrRoot;

SqrRoot rt_create(Frac, int);
bool rt_is_equal(SqrRoot, SqrRoot);
SqrRoot rt_simplify(SqrRoot);
void rt_to_str(SqrRoot, char *);

#endif

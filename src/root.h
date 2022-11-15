#ifndef ROOT_H
#define ROOT_H

#include "rational.h"

typedef struct {
  Rational scalar;
  int root;
} Root;

Root root_simplify(int);
void root_print(Root);

#endif

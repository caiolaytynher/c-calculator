#ifndef QUADRATIC_H
#define QUADRATIC_H

#include "fraction.h"
#include "square_root.h"
#include <stdbool.h>

typedef struct {
  Frac frac;
  SqrRoot root;
  bool is_complex;
} ComplexAns;

typedef struct {
  ComplexAns x1;
  ComplexAns x2;
} QuadAns;

ComplexAns qd_create(Frac, SqrRoot, bool);
bool qd_is_equal(ComplexAns, ComplexAns);
QuadAns qd_solve(int, int, int);
void qd_to_str(ComplexAns, char *);

#endif

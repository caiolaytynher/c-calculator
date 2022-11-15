#ifndef QUADRATIC_H
#define QUADRATIC_H

#include "rational.h"
#include "root.h"

typedef struct {
  Rational real;
  Root imaginary;
} Complex;

typedef struct {
  Complex x1;
  Complex x2;
} QuadraticAnswer;

QuadraticAnswer solve_quadratic_eq(int, int, int);

#endif

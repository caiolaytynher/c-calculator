#ifndef QUADRATIC_H
#define QUADRATIC_H

#define MAX_PRIME_FACTORS 20

typedef struct {
  int numerator;
  int denominator;
} Rational;

typedef struct {
  Rational scalar;
  int root;
} Root;

typedef struct {
  Rational real;
  Root imaginary;
} Complex;

typedef struct {
  Complex x1;
  Complex x2;
} QuadraticAnswer;

Root simplify_root(int);
Rational simplify_ratio(int, int);
QuadraticAnswer solve_quadratic_eq(int, int, int);

#endif

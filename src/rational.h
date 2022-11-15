#ifndef RATIONAL_H
#define RATIONAL_H

#define MAX_PRIME_FACTORS 20

typedef struct {
  int numerator;
  int denominator;
} Rational;

Rational ratio_simplify(int, int);
Rational ratio_sum(Rational, Rational);
Rational ratio_sub(Rational, Rational);
void ratio_print(Rational);

#endif

#ifndef FRACTION_H
#define FRACTION_H

#include <stdbool.h>

typedef struct {
  int num;
  int denom;
} Frac;

Frac fr_create(int, int);
Frac fr_simplify(Frac);
Frac fr_sum(Frac, Frac);
Frac fr_sub(Frac, Frac);
bool fr_is_equal(Frac, Frac);
void fr_to_str(Frac, char *);

#endif

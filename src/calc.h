#ifndef CALC_H
#define CALC_H

#include <stdbool.h>
#include <stdlib.h>

double array_sum(double *, size_t);
double array_sub(double *, size_t);
double array_mul(double *, size_t);
double array_div(double *, size_t);
double potentiate(double, int);
double array_max_double(double *, size_t);
int array_max_int(int *, size_t);
double array_min(double *, size_t);
void find_prime_factors(int, int *, size_t);
int array_count(int, int *, size_t);
bool is_prime(int);

#endif

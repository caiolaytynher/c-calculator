#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>

void populate_arr(double *, size_t, const char *);
size_t get_size(const char *, size_t);
double *create_double_array(size_t);
void delete_double_array(double *);

#endif

#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>

void populate_arr(double *, size_t, const char *);
size_t get_size(const char *, size_t);
double *create_double_array(size_t);
void delete_double_array(double *);
bool is_in(int, int *, size_t);
int index_of(int, int *, size_t);
void array_print(int *, size_t);

#endif

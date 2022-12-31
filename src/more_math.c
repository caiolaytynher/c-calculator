#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int mm_gcd(int a, int b) {
  a = abs(a);
  b = abs(b);
  // If one is zero, the gcd is the other
  if (a == 0)
    return b;
  if (b == 0)
    return a;

  int tmp;
  while (b != 0) {
    tmp = b;
    b = a % b;
    a = tmp;
  }

  // When b becomes 0, the gcd is just a
  return a;
}

int mm_lcm(int a, int b) {
  a = abs(a);
  b = abs(b);

  int gcd = mm_gcd(a, b);
  if (gcd == 0)
    return 0;

  return (a * b) / gcd;
}

bool mm_is_perfect_square(int number) {
  int root = sqrt(number); // Truncate sqrt
  return root * root == number;
}

int mm_find_higher_perfect_square(int number) {
  int higher = 0;
  bool is_divisor;
  for (int i = 1; i <= number; i++) {
    is_divisor = number % i == 0;
    if (is_divisor && mm_is_perfect_square(i) && i > higher)
      higher = i;
  }

  return higher;
}

int mm_find_square_complement(int number, int perfect_square) {
  for (int i = 2; i <= number; i++) {
    if (i * perfect_square == number)
      return i;
  }

  return 1;
}

#include "quadratic.h"
#include "calc.h"
#include "helpers.h"
#include "rational.h"
#include "root.h"
#include <stdio.h>

QuadraticAnswer solve_quadratic_eq(int a, int b, int c) {
  QuadraticAnswer answer;
  Complex number = {.real =
                        {
                            .numerator = 0,
                            .denominator = 1,
                        },
                    .imaginary = {
                        .scalar =
                            {
                                .numerator = 0,
                                .denominator = 1,
                            },
                        .root = 0,
                    }};

  int delta = potentiate(b, 2) - 4 * a * c;
  printf("DELTA = %d\n", delta);

  if (delta < 0) {
    number.real = ratio_simplify(-b, 2 * a);

    number.imaginary = root_simplify(delta);
    number.imaginary.scalar =
        ratio_simplify(number.imaginary.scalar.numerator, 2 * a);

    answer.x1 = number;

    number.imaginary.scalar.numerator = -number.imaginary.scalar.numerator;
    answer.x2 = number;
  } else if (delta == 0) {
    number.real = ratio_simplify(-b, 2 * a);
    answer.x1 = answer.x2 = number;
  } else {
    Root delta_root = root_simplify(delta);
    delta_root.scalar.denominator = 2 * a;
    Rational real_part = {
        .numerator = -b,
        .denominator = 2 * a,
    };

    if (delta_root.root == 1) {
      printf("DELTA ROOT IS 1\n");
      printf("BEFORE\n");
      ratio_print(real_part);
      root_print(delta_root);
      number.real = ratio_sum(real_part, delta_root.scalar);
      printf("AFTER SUM\n");
      ratio_print(number.real);
      answer.x1 = number;

      number.real = ratio_sub(real_part, delta_root.scalar);
      printf("AFTER SUB\n");
      ratio_print(number.real);
      answer.x2 = number;
    } else {
      number.real = ratio_simplify(real_part.numerator, real_part.denominator);
      number.imaginary.scalar = ratio_simplify(delta_root.scalar.numerator,
                                               delta_root.scalar.denominator);
      number.imaginary.root = delta_root.root;
      answer.x1 = number;

      number.imaginary.scalar.numerator = -number.imaginary.scalar.numerator;
      answer.x2 = number;
    }
  }

  return answer;
}

void print_quadratic_answer(QuadraticAnswer answer) {}

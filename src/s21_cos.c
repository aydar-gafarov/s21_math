#include "s21_math.h"

long double s21_cos(double x) {
  long double res = 1;
  if (x == 0) {
    return 1;
  } else if (x == S_NAN || x == S_N_INF || x == S_P_INF) {
    res = S_NAN;
  } else if (x == S_PI / 2 || x == -S_PI / 2) {
    res = 0;
  } else {
    int rg = 1;
    if (x < 0) x *= -1;
    while (x >= S_PI) {
      x -= S_PI;
      rg *= -1;
    }
    if (x >= S_PI / 2) {
      x = S_PI - x;
      rg *= -1;
    }

    double x_square = x * x;
    double step = 1;
    for (int i = 1; i < 100; i++) {
      step = (-1) * step * x_square / ((2 * i) * (2 * i - 1));
      res += step;
    }
    res *= rg;
  }
  return res;
}

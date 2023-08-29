#include "s21_math.h"

long double s21_exp(double x) {
  if (x == S_N_INF || x < -15) {
    return 0;
  } else if (S_ISNAN(x) || x == S_P_INF) {
    return x;
  }
  long double res = 0;
  long double step = 1;
  for (int i = 1; i < 100; i++) {
    res += step;
    step *= x / i;
  }
  if (x == 0) {
    res = 1;
  }
  return res;
}

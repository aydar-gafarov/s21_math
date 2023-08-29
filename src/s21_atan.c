#include "s21_math.h"

long double s21_atan(double x) {
  long double result = 0.0;
  if (x == S_P_INF) {
    result = S_PI / 2;
    return result;
  }
  if (x == S_N_INF) {
    result = -S_PI / 2;
    return result;
  }
  if (x == 0) {
    result = 0.0;
  } else if (x == 1 || x == -1) {
    result = S_PI / 4 * x;
  } else if (x > -1.0 && x < 1.0) {
    for (int i = 0; i < 700; i++) {
      result += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
    }
  } else if (S_ISNAN(x)) {
    result = S_NAN;
  } else {
    for (int i = 0; i < 700; i++) {
      result += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
    }
    result = S_PI * s21_sqrt(x * x) / (2 * x) - result;
  }
  return result;
}

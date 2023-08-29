#include "s21_math.h"

long double s21_log(double src) {
  if (src == 0) {
    return S_N_INF;
  }
  if (src == S_P_INF) {
    return src;
  }
  if (src < 0) {
    return S_NAN;
  }

  long double result = 0;
  double compare = 0;
  for (int i = 0; i < 100; i++) {
    compare = result;
    result = compare + 2 * (src - s21_exp(compare)) / (src + s21_exp(compare));
  }
  return result;
}

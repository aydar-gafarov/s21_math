#include "s21_math.h"

long double s21_asin(double x) {
  long double res;
  if (x == S_N_INF) {
    res = S_NAN;
  } else if (x == S_P_INF) {
    res = S_NAN;
  } else if (x == 0.0) {
    res = 0.0;
  } else {
    if ((x > 1 || x < -1) && S_ISNAN(x)) {
      res = S_NAN;
    } else {
      double p = x / s21_sqrt(1 - x * x);
      res = s21_atan(p);
    }
  }
  return res;
}
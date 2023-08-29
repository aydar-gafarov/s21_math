#include "s21_math.h"

long double s21_acos(double x) {
  long double res;
  if (x == S_P_INF || x == S_N_INF) {
    res = S_N_INF;
  } else if (S_ISNAN(x)) {
    res = S_NAN;
  } else {
    if (x == -1) {
      return S_PI;
    }
    if (x < -1 || x > 1) {
      return S_NAN;
    } else {
      res = s21_asin(s21_sqrt(1 - x * x));
      if (x < 0) {
        res = -res + S_PI;
      }
    }
  }
  return res;
}

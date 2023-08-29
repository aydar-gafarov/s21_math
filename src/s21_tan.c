#include "s21_math.h"

long double s21_tan(double x) {
  long double res = 0;
  if (s21_cos(x) == 0) {
    res = S_NAN;
  } else {
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}

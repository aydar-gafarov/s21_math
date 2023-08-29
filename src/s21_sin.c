#include "s21_math.h"

long double s21_sin(double x) {
  long double res;
  res = s21_cos(x - S_PI / 2.0);
  return res;
}

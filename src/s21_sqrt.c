#include "s21_math.h"

long double s21_sqrt(double src) {
  long double result = 1.0;
  double a = 0, b = src;
  double mid = 0;
  if (!s21_sqrt_edges(src, &result)) {
    a = s21_min(src, 1);
    b = s21_max(src, 1);
    while (100 * a * a < src) a *= 10;
    while (0.01 * b * b > src) b *= 0.1;
    for (; s21_fabs(b - a) > 1E-7;) {
      mid = a + (b - a) / 2;
      if (mid * mid > src) {
        b = mid;
      } else {
        a = mid;
      }
    }
    result = (long double)mid;
  }
  return result;
}

int s21_sqrt_edges(double src, long double *result) {
  int detected = 0;
  if (S_ISNAN(src)) {
    *result = S_NAN;
    detected++;
  } else if (src == 1.0) {
    *result = src;
    detected++;
  }
  return detected;
}

double s21_max(double x, double y) {
  double result = S_NAN;
  if (S_ISNAN(x) == 0 && S_ISNAN(y) == 0) {
    if (x > y)
      result = x;
    else
      result = y;
  }
  return result;
}

double s21_min(double x, double y) {
  double result = S_NAN;
  if (S_ISNAN(x) == 0 && S_ISNAN(y) == 0) {
    if (x < y)
      result = x;
    else
      result = y;
  }
  return result;
}
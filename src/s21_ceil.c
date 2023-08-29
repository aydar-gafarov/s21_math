#include "s21_math.h"

long double s21_ceil(double x) {
  int status = 0;
  long double result = (long long int)x;
  if (result == x) status = 1;
  if (status == 0) {
    if (x > 0.) result += 1;
  }
  if (S_ISNAN(x) == 1 || x == S_P_INF || x == S_N_INF) {
    result = x;
  }
  return result;
}
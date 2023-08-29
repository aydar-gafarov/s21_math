#include "s21_math.h"

long double s21_floor(double x) {
  long double result;
  int status = 0;
  if (S_ISNAN(x) == x || S_N_INF == x || S_P_INF == x) {
    result = x;
  } else {
    result = (long long int)x;
    if (result == x) status = 1;
    if (status == 0) {
      if (x < 0.0) {
        result -= 1;
      }
    }
  }
  return result;
}

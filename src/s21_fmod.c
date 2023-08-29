#include "s21_math.h"
long double s21_fmod(double x, double y);

long double s21_fmod(double x, double y) {
  long double res;
  long double got = s21_fabs(y);

  if ((x == S_P_INF && y == S_N_INF) || (x == S_N_INF && y == S_P_INF) ||
      (x == S_P_INF && y == S_P_INF) || y == 0.0 || x == S_N_INF) {
    return S_NAN;
  }

  if (y == S_N_INF || y == S_P_INF) {
    return x;
  }
  int sign = 0;
  if (x < 0.0) {
    sign = 1;
  }
  x = s21_fabs(x);
  y = s21_fabs(y);
  while (got <= x && x != S_P_INF) {
    got += y;
  }
  if (got > x) {
    got -= y;
  }
  res = x - got;
  if (sign) {
    res *= -1.0;
  }
  return res;
}
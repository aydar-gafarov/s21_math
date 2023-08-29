#include "s21_math.h"

long double s21_pow(double base, double expon) {
  long double result = 0;
  double copy = base;

  if (!s21_pow_edges(base, expon, &result)) {
    if (copy <= 0) {
      copy = -copy;
      result = s21_exp(expon * s21_log(copy));
      if ((int)expon % 2) {
        result = -result;
      }
    } else {
      result = s21_exp(expon * s21_log(copy));
    }
  }
  return result;
}

int s21_pow_edges(double base, double expon, long double *result) {
  int detect = 0;
  if ((S_ISNAN(base) == 1 && expon == S_N_INF) ||
      (S_ISNAN(base) && (expon == S_P_INF || expon == S_N_INF)) ||
      ((base == S_P_INF || base == S_N_INF) && expon == S_P_INF)) {
    *result = S_N_INF;
    detect++;
  } else if (expon == 0 || (base == 0.0 && expon == 0.0) || base == 1 ||
             (base == -1 && (expon == S_N_INF || expon == S_P_INF))) {
    *result = 1.0;
    detect++;
  } else if ((expon == S_N_INF || expon == S_N_INF)) {
    *result = 0.0;
    detect++;
  } else if (expon - (double)(int)expon != 0 && base < 0) {
    *result = S_NAN;
    detect++;
  }
  return detect;
}
#include <stdio.h>
#include <stdlib.h>

#define S_N_INF -1.0 / 0.0
#define S_NAN (0.0 / 0.0)
#define S_P_INF 1.0 / 0.0
#define S_F_EXP 709
#define S_ISNAN(x) ((x) != (x))
#define S_PI 3.14159265358979323846

int s21_abs(int x);
long double s21_exp(double x);
long double s21_acos(double x);
long double s21_cos(double x);
long double s21_log(double x);
long double s21_sqrt(double x);
long double s21_fabs(double x);
long double s21_pow(double base, double expo);
long double s21_floor(double x);
long double s21_ceil(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_fmod(double x, double y);

int s21_pow_edges(double base, double expon, long double *result);
int s21_sqrt_edges(double src, long double *result);
double s21_min(double x, double y);
double s21_max(double x, double y);

#include "s21_math_tests.h"

int main() {
  Suite *example_suite;
  int failed = 0;
  SRunner *SRunner_suite;

  example_suite = lib_suite();
  SRunner_suite = srunner_create(example_suite);
  srunner_run_all(SRunner_suite, CK_VERBOSE);
  failed = srunner_ntests_failed(SRunner_suite);
  srunner_free(SRunner_suite);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

START_TEST(s21_abs_tests) {
  ck_assert_int_eq(s21_abs(1), abs(1));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(-10), abs(-10));
  ck_assert_int_eq(s21_abs(10), abs(10));
  ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
}
END_TEST

START_TEST(s21_acos_tests) {
  ck_assert_float_eq_tol(s21_acos(0.0), acos(0.0), PRECISION);
  ck_assert_float_eq_tol(s21_acos(1.0), acos(1.0), PRECISION);
  ck_assert_int_eq(s21_acos(2.314), acos(2.314));
  ck_assert_int_eq(s21_acos(-1.2), acos(-1.2));
  for (double i = -1.0; i < 1; i += 0.924) {
    ck_assert_float_eq_tol(s21_acos(i), acos(i), PRECISION);
  }
  for (double i = 1.0; i > -1; i -= 0.924) {
    ck_assert_float_eq_tol(s21_acos(i), acos(i), PRECISION);
  }
  ck_assert_int_eq(s21_acos(9.312932941), acos(9.312932941));
  ck_assert_int_eq(s21_acos(-21394.1234), acos(-21394.1234));
  ck_assert_int_eq(s21_acos(S_NAN), acos(S_NAN));
  ck_assert_int_eq(s21_acos(S_P_INF), acos(S_P_INF));
  ck_assert_int_eq(s21_acos(S_N_INF), acos(S_N_INF));
}
END_TEST

START_TEST(s21_asin_tests) {
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), PRECISION);
  ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), PRECISION);
  for (double i = -1.0; i < 1; i += 0.924) {
    ck_assert_float_eq_tol(s21_asin(i), asin(i), PRECISION);
  }
  for (double i = 1.0; i > -1; i -= 0.924) {
    ck_assert_ldouble_eq_tol(s21_asin(i), asin(i), PRECISION);
  }
  ck_assert_int_eq(s21_asin(S_NAN), asin(S_NAN));
  ck_assert_int_eq(s21_asin(S_P_INF), asin(S_P_INF));
  ck_assert_int_eq(s21_asin(S_N_INF), asin(S_N_INF));
}
END_TEST

START_TEST(s21_atan_tests) {
  ck_assert_float_eq_tol(s21_atan(0.0), atan(0.0), PRECISION);
  ck_assert_float_eq_tol(s21_atan(1.0), atan(1.0), PRECISION);
  ck_assert_float_eq_tol(s21_atan(2.314), atan(2.314), PRECISION);
  ck_assert_float_eq_tol(s21_atan(-1.2), atan(-1.2), PRECISION);
  ck_assert_float_eq_tol(s21_atan(9.311), atan(9.311), PRECISION);
  ck_assert_float_eq_tol(s21_atan(-21394.1234), atan(-21394.1234), PRECISION);
  ck_assert_int_eq(s21_atan(S_NAN), atan(S_NAN));
  ck_assert_int_eq(s21_atan(S_P_INF), atan(S_P_INF));
  ck_assert_int_eq(s21_atan(S_N_INF), atan(S_N_INF));
}
END_TEST

START_TEST(s21_ceil_tests) {
  ck_assert_double_eq_tol(s21_ceil(11.22), ceil(11.22), PRECISION);
  ck_assert_double_eq_tol(s21_ceil(-110.22), ceil(-110.22), PRECISION);
  ck_assert_double_nan(s21_ceil(S_NAN));
  ck_assert_double_nan(ceil(S_NAN));
  ck_assert_double_eq(s21_ceil(S_N_INF), ceil(S_N_INF));
  ck_assert_double_eq(s21_ceil(S_P_INF), ceil(S_P_INF));
  ck_assert_double_eq_tol(s21_ceil(-0.672), ceil(-0.672), PRECISION);
}
END_TEST

START_TEST(s21_cos_tests) {
  ck_assert_float_eq_tol(s21_cos(0.0), cos(0.0), PRECISION);
  ck_assert_float_eq_tol(s21_cos(1.0), cos(1.0), PRECISION);
  ck_assert_float_eq_tol(s21_cos(2.314), cos(2.314), PRECISION);
  ck_assert_float_eq_tol(s21_cos(-1.2), cos(-1.2), PRECISION);
  for (double i = -1.0; i < 0; i += 0.03) {
    ck_assert_float_eq_tol(s21_cos(i), cos(i), PRECISION);
  }
  for (double i = -1.0; i < 1; i += 0.924) {
    ck_assert_float_eq_tol(s21_cos(i), cos(i), PRECISION);
  }
  for (double i = 1.0; i > -1; i -= 0.924) {
    ck_assert_float_eq_tol(s21_cos(i), cos(i), PRECISION);
  }
  ck_assert_float_eq_tol(s21_cos(9.312932941), cos(9.312932941), PRECISION);
  ck_assert_float_eq_tol(s21_cos(-21394.1234), cos(-21394.1234), PRECISION);
  ck_assert_int_eq(s21_cos(S_NAN), cos(S_NAN));
  ck_assert_int_eq(s21_cos(S_P_INF), cos(S_P_INF));
  ck_assert_int_eq(s21_cos(S_N_INF), cos(S_N_INF));
}
END_TEST

START_TEST(s21_exp_tests) {
  ck_assert_float_eq_tol(s21_exp(0.0), exp(0.0), PRECISION);
  ck_assert_float_eq_tol(s21_exp(1.0), exp(1.0), PRECISION);
  ck_assert_float_eq_tol(s21_exp(2.314), exp(2.314), PRECISION);
  ck_assert_float_eq_tol(s21_exp(-1.2), exp(-1.2), PRECISION);
  for (double i = -1.0; i < 0; i += 0.0001) {
    ck_assert_float_eq_tol(s21_exp(i), exp(i), PRECISION);
  }
  for (double i = -1.0; i < 1; i += 0.924) {
    ck_assert_float_eq_tol(s21_exp(i), exp(i), PRECISION);
  }
  for (double i = 1.0; i > -1; i -= 0.924) {
    ck_assert_float_eq_tol(s21_exp(i), exp(i), PRECISION);
  }
  ck_assert_float_eq_tol(s21_exp(9.312932941), exp(9.312932941), PRECISION);
  ck_assert_float_eq_tol(s21_exp(-21394.1234), exp(-21394.1234), PRECISION);
  ck_assert_int_eq(s21_exp(S_NAN), exp(S_NAN));
  ck_assert_int_eq(s21_exp(S_P_INF), exp(S_P_INF));
  ck_assert_int_eq(s21_exp(S_N_INF), exp(S_N_INF));
}
END_TEST

START_TEST(s21_fabs_tests) {
  ck_assert_float_eq_tol(s21_fabs(0.0), fabs(0.0), PRECISION);
  ck_assert_float_eq_tol(s21_fabs(1.0), fabs(1.0), PRECISION);
  ck_assert_float_eq_tol(s21_fabs(2.314), fabs(2.314), PRECISION);
  ck_assert_float_eq_tol(s21_fabs(-1.2), fabs(-1.2), PRECISION);
  for (double i = -1.0; i < 0; i += 0.0001) {
    ck_assert_float_eq_tol(s21_fabs(i), fabs(i), PRECISION);
  }
  for (double i = -1.0; i < 1; i += 0.924) {
    ck_assert_float_eq_tol(s21_fabs(i), fabs(i), PRECISION);
  }
  for (double i = 1.0; i > -1; i -= 0.924) {
    ck_assert_float_eq_tol(s21_fabs(i), fabs(i), PRECISION);
  }
  ck_assert_float_eq_tol(s21_fabs(9.312932941), fabs(9.312932941), PRECISION);
  ck_assert_float_eq_tol(s21_fabs(-21394.1234), fabs(-21394.1234), PRECISION);
  ck_assert_int_eq(s21_fabs(S_NAN), fabs(S_NAN));
  ck_assert_int_eq(s21_fabs(S_P_INF), fabs(S_P_INF));
  ck_assert_int_eq(s21_fabs(S_N_INF), fabs(S_N_INF));
}
END_TEST

START_TEST(s21_floor_tests) {
  ck_assert_float_eq_tol(s21_floor(0.0), floor(0.0), PRECISION);
  ck_assert_float_eq_tol(s21_floor(1.0), floor(1.0), PRECISION);
  ck_assert_float_eq_tol(s21_floor(2.314), floor(2.314), PRECISION);
  ck_assert_float_eq_tol(s21_floor(-1.2), floor(-1.2), PRECISION);
  for (double i = -1.0; i < 0; i += 0.0001) {
    ck_assert_float_eq_tol(s21_floor(i), floor(i), PRECISION);
  }
  for (double i = -1.0; i < 1; i += 0.924) {
    ck_assert_float_eq_tol(s21_floor(i), floor(i), PRECISION);
  }
  for (double i = 1.0; i > -1; i -= 0.924) {
    ck_assert_float_eq_tol(s21_floor(i), floor(i), PRECISION);
  }
  ck_assert_float_eq_tol(s21_floor(9.312932941), floor(9.312932941), PRECISION);
  ck_assert_float_eq_tol(s21_floor(-21394.1234), floor(-21394.1234), PRECISION);
  ck_assert_int_eq(s21_floor(S_NAN), floor(S_NAN));
  ck_assert_int_eq(s21_floor(S_P_INF), floor(S_P_INF));
  ck_assert_int_eq(s21_floor(S_N_INF), floor(S_N_INF));
}
END_TEST

START_TEST(s21_fmod_tests) {
  ck_assert_float_eq_tol(s21_fmod(2.0, 0.3), fmod(2.0, 0.3), PRECISION);
  ck_assert_float_eq_tol(s21_fmod(32.324, 1.123), fmod(32.324, 1.123),
                         PRECISION);
  ck_assert_float_eq_tol(s21_fmod(91.0, 1), fmod(91.0, 1), PRECISION);
  ck_assert_float_eq_tol(s21_fmod(-1.234, 0.12), fmod(-1.234, 0.12), PRECISION);
  ck_assert_float_eq_tol(s21_fmod(928.0, -20.3), fmod(928.0, -20.3), PRECISION);
  ck_assert_float_eq_tol(s21_fmod(-1234.0, -12.23), fmod(-1234.0, -12.23),
                         PRECISION);
  ck_assert_float_eq_tol(s21_fmod(0.0, 1.2), fmod(0.0, 1.2), PRECISION);
  ck_assert_float_eq_tol(s21_fmod(0.0, -14.2), fmod(0.0, -14.2), PRECISION);
  ck_assert_int_eq(s21_fmod(230.0, 0.0), fmod(230.0, 0.0));
  ck_assert_int_eq(s21_fmod(-81.0, 0.0), fmod(-81.0, 0.0));
  ck_assert_int_eq(s21_fmod(S_NAN, S_NAN), fmod(S_NAN, S_NAN));
  ck_assert_int_eq(s21_fmod(S_NAN, S_P_INF), fmod(S_NAN, S_P_INF));
  ck_assert_int_eq(s21_fmod(S_NAN, S_N_INF), fmod(S_NAN, S_N_INF));
  ck_assert_int_eq(s21_fmod(S_P_INF, S_N_INF), fmod(S_P_INF, S_N_INF));
  ck_assert_int_eq(s21_fmod(S_P_INF, S_NAN), fmod(S_P_INF, S_NAN));
  ck_assert_int_eq(s21_fmod(S_P_INF, S_P_INF), fmod(S_P_INF, S_P_INF));
  ck_assert_int_eq(s21_fmod(S_N_INF, S_N_INF), fmod(S_N_INF, S_N_INF));
  ck_assert_int_eq(s21_fmod(S_N_INF, S_NAN), fmod(S_N_INF, S_NAN));
  ck_assert_int_eq(s21_fmod(S_N_INF, S_P_INF), fmod(S_N_INF, S_P_INF));
}
END_TEST

START_TEST(s21_log_tests) {
  ck_assert_float_eq_tol(s21_log(2.12), log(2.12), PRECISION);
  ck_assert_float_eq_tol(s21_log(0.12), log(0.12), PRECISION);
  ck_assert_int_eq(s21_log(-1.12), log(-1.12));
  ck_assert_int_eq(s21_log(0), log(0));
  ck_assert_int_eq(s21_log(S_NAN), log(S_NAN));
  ck_assert_int_eq(s21_log(S_P_INF), log(S_P_INF));
  ck_assert_int_eq(s21_log(S_N_INF), log(S_N_INF));
  for (int i = 1; i != 0; i--) {
    ck_assert_float_eq_tol(s21_log(i), log(i), PRECISION);
  }
}
END_TEST

START_TEST(s21_pow_tests) {
  ck_assert_float_eq_tol(s21_pow(2.12, 4.55), pow(2.12, 4.55), PRECISION);
  ck_assert_float_eq_tol(s21_pow(3.0, 22.0), pow(3.0, 22.0), PRECISION);
  ck_assert_float_eq_tol(s21_pow(31.456, 4.3), pow(31.456, 4.3), PRECISION);
  ck_assert_float_eq_tol(s21_pow(0.3, 2.1), pow(0.3, 2.1), PRECISION);
  ck_assert_int_eq(s21_pow(-123, 6.9), pow(-123, 6.9));
  ck_assert_float_eq_tol(s21_pow(1.3, 1.3), pow(1.3, 1.3), PRECISION);
  ck_assert_int_eq(s21_pow(-123, 2.8), pow(-123, 2.8));
  ck_assert_int_eq(s21_pow(-234, -3.1), pow(-234, -3.1));
  ck_assert_int_eq(s21_pow(198, -3), pow(193, -3));
  ck_assert_int_eq(s21_pow(S_NAN, S_NAN), pow(S_NAN, S_NAN));
  ck_assert_int_eq(s21_pow(S_NAN, S_P_INF), pow(S_NAN, S_P_INF));
  ck_assert_int_eq(s21_pow(S_NAN, S_N_INF), pow(S_NAN, S_N_INF));
  ck_assert_int_eq(s21_pow(S_P_INF, S_N_INF), pow(S_P_INF, S_N_INF));
  ck_assert_int_eq(s21_pow(S_P_INF, S_NAN), pow(S_P_INF, S_NAN));
  ck_assert_int_eq(s21_pow(S_P_INF, S_P_INF), pow(S_P_INF, S_P_INF));
  ck_assert_int_eq(s21_pow(S_N_INF, S_N_INF), pow(S_N_INF, S_N_INF));
  ck_assert_int_eq(s21_pow(S_N_INF, S_NAN), pow(S_N_INF, S_NAN));
  ck_assert_int_eq(s21_pow(S_N_INF, S_P_INF), pow(S_N_INF, S_P_INF));
}
END_TEST

START_TEST(s21_sin_tests) {
  ck_assert_float_eq_tol(s21_sin(0.0), sin(0.0), PRECISION);
  ck_assert_float_eq_tol(s21_sin(1.0), sin(1.0), PRECISION);
  ck_assert_float_eq_tol(s21_sin(2.314), sin(2.314), PRECISION);
  ck_assert_float_eq_tol(s21_sin(-1.2), sin(-1.2), PRECISION);
  for (double i = -1.0; i < 0; i += 0.03) {
    ck_assert_float_eq_tol(s21_sin(i), sin(i), PRECISION);
  }
  for (double i = -1.0; i < 1; i += 0.924) {
    ck_assert_float_eq_tol(s21_sin(i), sin(i), PRECISION);
  }
  for (double i = 1.0; i > -1; i -= 0.924) {
    ck_assert_float_eq_tol(s21_sin(i), sin(i), PRECISION);
  }
  ck_assert_float_eq_tol(s21_sin(9.312932941), sin(9.312932941), PRECISION);
  ck_assert_float_eq_tol(s21_sin(-21394.1234), sin(-21394.1234), PRECISION);
  ck_assert_int_eq(s21_sin(S_NAN), sin(S_NAN));
  ck_assert_int_eq(s21_sin(S_P_INF), sin(S_P_INF));
  ck_assert_int_eq(s21_sin(S_N_INF), sin(S_N_INF));
}
END_TEST

START_TEST(s21_sqrt_tests) {
  ck_assert_float_eq_tol(s21_sqrt(16.0), sqrt(16.0), PRECISION);
  ck_assert_float_eq_tol(s21_sqrt(45.35), sqrt(45.35), PRECISION);
  ck_assert_int_eq(s21_sqrt(S_NAN), sqrt(S_NAN));
  ck_assert_int_eq(s21_sqrt(S_P_INF), sqrt(S_P_INF));
  for (double i = 0; i < 1; i += 0.001) {
    ck_assert_float_eq_tol(s21_sqrt(i), sqrt(i), PRECISION);
  }
  ck_assert_double_eq(s21_sqrt(S_P_INF), sqrt(S_P_INF));
  ck_assert_double_eq(s21_sqrt(S_P_INF), sqrt(S_P_INF));
  ck_assert_double_eq(s21_sqrt(0), sqrt(0));
  ck_assert_double_nan(s21_sqrt(S_NAN));
  ck_assert_double_nan(sqrt(S_NAN));
}
END_TEST

START_TEST(s21_tan_tests) {
  ck_assert_float_eq_tol(s21_tan(0.0), tan(0.0), PRECISION);
  ck_assert_float_eq_tol(s21_tan(1.0), tan(1.0), PRECISION);
  ck_assert_float_eq_tol(s21_tan(2.314), tan(2.314), PRECISION);
  ck_assert_float_eq_tol(s21_tan(-1.2), tan(-1.2), PRECISION);
  for (double i = -1.0; i < 0; i += 0.03) {
    ck_assert_float_eq_tol(s21_tan(i), tan(i), PRECISION);
  }
  for (double i = -1.0; i < 1; i += 0.924) {
    ck_assert_float_eq_tol(s21_tan(i), tan(i), PRECISION);
  }
  for (double i = 1.0; i > -1; i -= 0.924) {
    ck_assert_float_eq_tol(s21_tan(i), tan(i), PRECISION);
  }
  ck_assert_float_eq_tol(s21_tan(9.312932941), tan(9.312932941), PRECISION);
  ck_assert_float_eq_tol(s21_tan(-21394.1234), tan(-21394.1234), PRECISION);
  ck_assert_int_eq(s21_tan(S_NAN), tan(S_NAN));
  ck_assert_int_eq(s21_tan(S_P_INF), tan(S_P_INF));
  ck_assert_int_eq(s21_tan(S_N_INF), tan(S_N_INF));
  ck_assert_ldouble_eq_tol(s21_tan(0.99), tan(0.99), PRECISION);
  ck_assert_double_eq_tol(s21_tan(0.5), tan(0.5), PRECISION);
  ck_assert_float_nan(s21_tan(S_NAN));
  ck_assert_double_nan(s21_tan(NAN));
  ck_assert_double_nan(s21_tan(S_N_INF));
  ck_assert_double_nan(s21_tan(S_N_INF));
  ck_assert_double_nan(s21_tan(S_P_INF));
  ck_assert_double_nan(s21_tan(S_P_INF));
}
END_TEST

Suite *lib_suite() {
  Suite *curr_s;
  curr_s = suite_create("CHECK");

  TCase *abs;
  TCase *acos;
  TCase *asin;
  TCase *atan;
  TCase *ceil;
  TCase *cos;
  TCase *exp;
  TCase *fabs;
  TCase *floor;
  TCase *fmod;
  TCase *log;
  TCase *pow;
  TCase *sin;
  TCase *sqrt;
  TCase *tan;

  abs = tcase_create("abs_TESTS");
  acos = tcase_create("abs_TESTS");
  asin = tcase_create("abs_TESTS");
  atan = tcase_create("abs_TESTS");
  ceil = tcase_create("abs_TESTS");
  cos = tcase_create("abs_TESTS");
  exp = tcase_create("abs_TESTS");
  fabs = tcase_create("abs_TESTS");
  floor = tcase_create("abs_TESTS");
  fmod = tcase_create("abs_TESTS");
  log = tcase_create("abs_TESTS");
  pow = tcase_create("abs_TESTS");
  sin = tcase_create("abs_TESTS");
  sqrt = tcase_create("abs_TESTS");
  tan = tcase_create("abs_TESTS");

  suite_add_tcase(curr_s, abs);
  suite_add_tcase(curr_s, acos);
  suite_add_tcase(curr_s, asin);
  suite_add_tcase(curr_s, atan);
  suite_add_tcase(curr_s, ceil);
  suite_add_tcase(curr_s, cos);
  suite_add_tcase(curr_s, exp);
  suite_add_tcase(curr_s, fabs);
  suite_add_tcase(curr_s, floor);
  suite_add_tcase(curr_s, fmod);
  suite_add_tcase(curr_s, log);
  suite_add_tcase(curr_s, pow);
  suite_add_tcase(curr_s, sin);
  suite_add_tcase(curr_s, sqrt);
  suite_add_tcase(curr_s, tan);

  tcase_add_test(abs, s21_abs_tests);
  tcase_add_test(acos, s21_acos_tests);
  tcase_add_test(asin, s21_asin_tests);
  tcase_add_test(atan, s21_atan_tests);
  tcase_add_test(ceil, s21_ceil_tests);
  tcase_add_test(cos, s21_cos_tests);
  tcase_add_test(exp, s21_exp_tests);
  tcase_add_test(fabs, s21_fabs_tests);
  tcase_add_test(floor, s21_floor_tests);
  tcase_add_test(fmod, s21_fmod_tests);
  tcase_add_test(log, s21_log_tests);
  tcase_add_test(pow, s21_pow_tests);
  tcase_add_test(sin, s21_sin_tests);
  tcase_add_test(sqrt, s21_sqrt_tests);
  tcase_add_test(tan, s21_tan_tests);

  return curr_s;
}

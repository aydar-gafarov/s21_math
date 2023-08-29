CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11
GCOVFLAGS:=-fprofile-arcs -ftest-coverage
LDFLAGS:=-lcheck -lgcov -fprofile-arcs --coverage
OPEN= open
ifeq ($(shell uname), Linux)
LDFLAGS += -pthread -lcheck_pic -lrt -lm -lsubunit
endif


CMATHFUNC:= s21_abs.c s21_acos.c s21_asin.c s21_atan.c s21_ceil.c s21_cos.c s21_exp.c s21_fabs.c s21_floor.c s21_fmod.c s21_log.c s21_pow.c s21_sin.c s21_sqrt.c s21_tan.c

OBJ = $(addprefix obj/,$(CMATHFUNC:.c=.o))

OBJ_GCOV = $(addprefix gcov_obj/,$(CMATHFUNC:.c=.o))

all: test s21_math.a gcov_report s21_math_gcov.a 

s21_math.a: $(OBJ)
	ar -src $@ $(OBJ)

s21_math_gcov.a: $(OBJ_GCOV)
	ar -src $@ $(OBJ_GCOV)

test: gcov_obj/s21_math_tests.o s21_math_gcov.a
	$(CC) gcov_obj/s21_math_tests.o s21_math_gcov.a -o $@ $(LDFLAGS) $(GCOVFLAGS)
	./test

gcov_report: test
	lcov -t "test" -o gcov_obj/test.info -c -d gcov_obj/
	genhtml gcov_obj/test.info --output-directory report

gcov_obj/%.o: %.c
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c $< -o $@

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

rebuild: clean all

valgrind:	
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test

prepare_ws: 
	sudo apt update
	sudo apt install gcc valgrind lcov check

clean:
	rm -rf report
	rm -f obj/*.o
	rm -f gcov_obj/*.o
	rm -f gcov_obj/*.gc*
	rm -f ./test
	rm -f -r out
	rm -f gcov_obj/*.info
	rm -f .DS_Store
	rm -f *.a
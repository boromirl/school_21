CC = gcc
SRCS = $(wildcard c_functions/*.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra -std=c11 -g
LDFLAGS = -lcheck -lsubunit -lm
TEST_EXEC = test_21_matrix

REPORT_DIR = ./report

all: s21_matrix.a

test: clean s21_matrix.a
	$(CC) $(CFLAGS) --coverage -o $(TEST_EXEC) tests/*.c tests/test_suites/*.c $(SRCS) $(LDFLAGS)
	./$(TEST_EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

s21_matrix.a: $(OBJS)
	ar rcs $@ $^
	ranlib $@

gcov_report: test
	lcov -t "$(TEST_EXEC)" --output-file report.info --capture -q --directory ./
	genhtml -o $(REPORT_DIR) report.info
	@xdg-open report/index.html

clean:
	rm -rf c_functions/*.o *.a *.o *.gcno *.gcda *.out test_21_matrix report.info $(REPORT_DIR)

CLANG-FORMAT = clang-format -style='{CommentPragmas: Insert, BasedOnStyle: Google}'
clang_test:
	find . -name "*.h" -or -name "*.c" | xargs $(CLANG-FORMAT) -n
format:
	find . -name "*.h" -or -name "*.c" | xargs $(CLANG-FORMAT) -i

rebuild: clean all

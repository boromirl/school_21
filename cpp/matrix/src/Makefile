# all, clean, test, s21_matrix_oop.a
OPEN_BROWSER_CMD = $(shell which firefox || which xdg-open || which open || which x-www-browser)

CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++17 -g

SRCS_DIR = methods
SRCS = $(wildcard $(SRCS_DIR)/*.cc)
OBJS = $(SRCS:.cc=.o)

all: s21_matrix_oop.a

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

s21_matrix_oop.a: $(OBJS)
	ar rcs $@ $^
	ranlib $@

GTEST_LIB = -lgtest -lgtest_main
TEST_EXEC = s21_matrix_test
TEST_DIR = tests
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cc)
TEST_OBJS = $(TEST_SRCS:.cc=.o)
# add --coverage later
test: clean s21_matrix_oop.a
	$(CXX) $(CXXFLAGS) -O0 --coverage -o $(TEST_EXEC) $(TEST_SRCS) $(SRCS) $(GTEST_LIB) 
	./$(TEST_EXEC)

REPORT_DIR = ./report
gcov_report: test
	lcov -t "s21_matrix_test" --directory ./ --output-file report.info --capture -q --exclude '/usr/include/*' --ignore-errors mismatch
	genhtml -o $(REPORT_DIR) report.info
	$(OPEN_BROWSER_CMD) report/index.html


clean:
	rm -rf $(SRCS_DIR)/*.o *.a *.gcno *.gcda s21_matrix_test $(REPORT_DIR) report.info

rebuild: clean all
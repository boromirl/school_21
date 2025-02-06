# all, install, uninstall, clean, dvi, dist, test, gcov_report
CC = gcc
SRC_DIR_BACKEND = brick_game/tetris/src
OBJ_DIR_BACKEND  = brick_game/tetris/out
SRCS_BACKEND  = $(wildcard $(SRC_DIR_BACKEND)/*.c)
OBJS_BACKEND  = $(patsubst $(SRC_DIR_BACKEND)/%.c, $(OBJ_DIR_BACKEND)/%.o, $(SRCS_BACKEND))

SRC_DIR_FRONTEND = gui/cli/src
OBJ_DIR_FRONTEND = gui/cli/out
SRCS_FRONTEND = $(wildcard $(SRC_DIR_FRONTEND)/*.c) main.c
OBJS_FRONTEND = $(patsubst $(SRC_DIR_FRONTEND)/%.c, $(OBJ_DIR_FRONTEND)/%.o, $(SRCS_FRONTEND))

BUILD_DIR = game

CFLAGS = -Wall -Werror -Wextra -std=c11 -Wpedantic
EXEC = tetris

OPEN_BROWSER_CMD = $(shell which firefox || which xdg-open || which open || which x-www-browser)

all: install

$(OBJ_DIR_BACKEND)/%.o: $(SRC_DIR_BACKEND)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_FRONTEND)/%.o: $(SRC_DIR_FRONTEND)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

tetris.a: $(OBJS_BACKEND) build_dir
	ar rcs $(BUILD_DIR)/$@ $(OBJS_BACKEND)
	ranlib $(BUILD_DIR)/$@

build_dir:
	mkdir -p $(BUILD_DIR)

install: tetris.a $(OBJS_FRONTEND)
	$(CC) $(CFLAGS) $(OBJS_FRONTEND) -o $(BUILD_DIR)/$(EXEC) -lncurses -L. -l:$(BUILD_DIR)/tetris.a
	echo 0 > $(BUILD_DIR)/high_score.txt

uninstall:
	rm -rf $(BUILD_DIR)

TEST_EXEC = test_tetris
LDFLAGS = -lcheck -lsubunit -lm
test: clean tetris.a
	$(CC) $(CFLAGS) --coverage -o $(TEST_EXEC) tests/*.c tests/test_suites/*.c $(SRCS_BACKEND) $(LDFLAGS)
	./$(TEST_EXEC)

REPORT_DIR = ./report

gcov_report: test
	lcov -t "$(TEST_EXEC)" --output-file report.info --capture -q --directory ./
	genhtml -o $(REPORT_DIR) report.info
	$(OPEN_BROWSER_CMD) report/index.html


DIST_FILE = tetris.tar.gz
DIST_DIR = tetris

dvi:
	@doxygen
	$(OPEN_BROWSER_CMD) docs/html/index.html

dist:
	mkdir $(DIST_DIR)
	cp -r brick_game $(DIST_DIR)/brick_game && cp -r gui $(DIST_DIR)/gui && cp Makefile $(DIST_DIR)/Makefile && cp readme.md $(DIST_DIR)/readme.md  && cp main.c $(DIST_DIR)/main.c
	tar -cvf $(DIST_FILE) $(DIST_DIR)
	rm -rf $(DIST_DIR)

clean:
	rm -rf $(OBJ_DIR_BACKEND)/*.o $(OBJ_DIR_FRONTEND)/*.o *.gcno *.gcda *.out tetris *.a $(BUILD_DIR) test_tetris $(REPORT_DIR)/ report.info docs high_score.txt Doxyfile

CLANG-FORMAT = clang-format -style='{CommentPragmas: Insert, BasedOnStyle: Google}'
clang_test:
	find . -name "*.h" -or -name "*.c" | xargs $(CLANG-FORMAT) -n
format:
	find . -name "*.h" -or -name "*.c" | xargs $(CLANG-FORMAT) -i

rebuild: clean all

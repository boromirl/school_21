CC = g++
FLAGS = -Wall -Werror -Wextra -std=c++17
TEST_LIB = -lgtest
SRC = $(wildcard tests/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = test
OPEN = xdg-open

all: clean $(TARGET) run

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(TARGET) $(TEST_LIB)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./$(TARGET)

leaks:
	leaks --atExit -- ./$(TARGET)

CLANG-FORMAT = clang-format -style='{CommentPragmas: Insert, BasedOnStyle: Google}'
clang_test:
	find $(SRC_DIR) -name "*.h" -or -name "*.cpp" | xargs $(CLANG-FORMAT) -n
format:
	find $(SRC_DIR) -name "*.h" -or -name "*.cpp" | xargs $(CLANG-FORMAT) -i

gcov_report:
	$(CC) $(FLAGS) --coverage $(SRC) -o gcov_report $(TEST_LIB)
	./gcov_report
	lcov -c -d . -o gcov_report.info --no-external --ignore-errors gcov 
#--ignore-errors mismatch
	genhtml -o report/ gcov_report.info
	$(OPEN) ./report/index.html
	
clean:
	rm -rf *.o *.a *.log *.gcda *.gcno *.info *.out gcov_report report $(TARGET) tests/*.o
#include "s21_tests_main.h"
bool are_stacks_equal(s21::stack<int> myStack, std::stack<int> realStack) {
  if (myStack.size() != realStack.size()) {
    return false;
  }
  bool res = true;

  int size = myStack.size();
  for (int i = 0; i < size; i++) {
    if (myStack.top() != realStack.top()) {
      res = false;
      break;
    }
    myStack.pop();
    realStack.pop();
  }

  return res;
}

// default constructor
TEST(SuiteStack, DefaultConstructor) {
  s21::stack<int> s1;
  std::stack<int> s2;

  ASSERT_EQ(s1.size(), 0);
  ASSERT_EQ(s1.size(), s2.size());
  ASSERT_TRUE(s1.empty());
  ASSERT_EQ(s1.empty(), s2.empty());
}

// initializer list constructor
TEST(SuiteStack, InitListConstructor) {
  s21::stack<int> s1({1, 2, 3, 4});
  std::stack<int> s2({1, 2, 3, 4});

  ASSERT_TRUE(are_stacks_equal(s1, s2));

  s21::stack<int> s3({2, 3, 4, 5});
  std::stack<int> s4({0, 0, 0, 0});

  ASSERT_FALSE(are_stacks_equal(s3, s4));
}

// copy construcor
TEST(SuiteStack, CopyConstructor) {
  std::initializer_list list({1, 2, 3, 4, 5});
  s21::stack<int> s21_src(list);
  std::stack<int> std_src(list);

  s21::stack<int> s21_dst(s21_src);
  std::stack<int> std_dst(std_src);

  ASSERT_TRUE(are_stacks_equal(s21_src, std_src));
  ASSERT_TRUE(are_stacks_equal(s21_dst, std_dst));
}

// move constructor
TEST(SuiteStack, MoveConstructor) {
  std::initializer_list list({100, -2, 40, 33, 15, 10, -22, -40});
  s21::stack<int> s21_src(list);
  std::stack<int> std_src(list);

  s21::stack<int> s21_dst = std::move(s21_src);
  std::stack<int> std_dst = std::move(std_src);

  ASSERT_TRUE(s21_src.empty());
  ASSERT_TRUE(std_src.empty());

  ASSERT_TRUE(are_stacks_equal(s21_dst, std_dst));
}

// error: cannot pop(), stack is empty (не существует в оригинальном стеке)
TEST(SuiteStack, PopError) {
  s21::stack<int> st1({1});
  st1.pop();

  EXPECT_THROW(st1.pop(), std::out_of_range);

  s21::stack<std::string> st2;
  EXPECT_THROW(st2.pop(), std::out_of_range);
}

TEST(SuiteStack, TopError) {
  s21::stack<int> st1({1});
  st1.pop();

  EXPECT_THROW(st1.top(), std::out_of_range);

  s21::stack<std::string> st2;
  EXPECT_THROW(st2.top(), std::out_of_range);
}

// swap метод
TEST(SuiteStack, Swap) {
  std::initializer_list list1({200, 432, 45, -2, -50});
  std::initializer_list list2({200, 432, 45, -2, -50});

  s21::stack<int> s21_s1(list1);
  s21::stack<int> s21_s2(list2);

  std::stack<int> std_s1(list1);
  std::stack<int> std_s2(list2);

  s21_s1.swap(s21_s2);
  std_s1.swap(std_s2);

  ASSERT_TRUE(are_stacks_equal(s21_s1, std_s1));
  ASSERT_TRUE(are_stacks_equal(s21_s2, std_s2));
}

// оператор перемещение объекта
TEST(SuiteStack, Assignment) {
  std::initializer_list list1({200, 432, 45, -2, -50});
  std::initializer_list list2({15, 5, 2});

  s21::stack<int> s21_s1(list1);
  s21::stack<int> s21_s2(list2);

  std::stack<int> std_s1(list1);
  std::stack<int> std_s2(list2);

  s21_s1 = std::move(s21_s2);
  std_s1 = std::move(std_s2);

  ASSERT_TRUE(are_stacks_equal(s21_s1, std_s1));
  ASSERT_TRUE(s21_s2.empty());
}

// метод push()
TEST(SuiteStack, Push) {
  s21::stack<double> s1;
  ASSERT_EQ(s1.size(), 0);

  s1.push(4.2);
  s1.push(-3.2);
  s1.push(-0.00005);

  ASSERT_EQ(s1.size(), 3);
  ASSERT_EQ(s1.top(), -0.00005);

  s1.pop();
  ASSERT_EQ(s1.top(), -3.2);
  s1.pop();
  ASSERT_EQ(s1.top(), 4.2);
}

// метод top()
TEST(SuiteStack, Top) {
  s21::stack<char> s1({'a', 'b', 'd'});
  ASSERT_EQ(s1.top(), 'd');

  s21::stack<float> s2({4.1, 5.2, -2.2});
  ASSERT_EQ(s2.top(), -2.2f);

  s21::stack<int> s3({2, 3, 4, 10});
  ASSERT_EQ(s3.top(), 10);
}

// метод pop()
TEST(SuiteStack, Pop) {
  s21::stack<char> s1({'a', 'b', 'c', 'd'});

  ASSERT_EQ(s1.size(), 4);
  s1.pop();
  ASSERT_EQ(s1.top(), 'c');

  ASSERT_EQ(s1.size(), 3);
  s1.pop();
  ASSERT_EQ(s1.top(), 'b');

  ASSERT_EQ(s1.size(), 2);
  s1.pop();
  ASSERT_EQ(s1.top(), 'a');

  ASSERT_EQ(s1.size(), 1);
  s1.pop();
  ASSERT_TRUE(s1.empty());
}

// метод insert_many_back
TEST(SuiteStack, InsertManyBack) {
  s21::stack<int> s1({1, 2, 3, 4, 5});

  s1.insert_many_back(6, 7, 8, 9, 10);

  for (int i = 10; i > 0; i--) {
    ASSERT_EQ(s1.top(), i);
    s1.pop();
  }

  s21::stack<char> s2({'g', 's'});
  s2.insert_many_back('f', 'm');

  ASSERT_EQ(s2.top(), 'm');
  s2.pop();
  ASSERT_EQ(s2.top(), 'f');
  s2.pop();
  ASSERT_EQ(s2.top(), 's');
  s2.pop();
  ASSERT_EQ(s2.top(), 'g');
  s2.pop();

  ASSERT_TRUE(s2.empty());
}
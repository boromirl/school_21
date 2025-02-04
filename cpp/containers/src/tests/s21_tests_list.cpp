#include "s21_tests_main.h"

template <typename T>
int compare_with_s21(s21::list<T> list1, s21::list<T> list2) {
  if (list1.size() != list2.size()) return 1;
  if (list1.empty() != list2.empty()) return 2;

  typename s21::list<T>::iterator it1 = list1.begin();
  typename s21::list<T>::iterator it2 = list2.begin();

  for (; it1 != list1.end(); ++it1, ++it2) {
    if (*it1 != *it2) return 3;
  }

  if (it2 != list2.end()) return 4;

  return 0;
}

template <typename T>
bool compare_with_std(s21::list<T> s21_list, std::list<T> std_list) {
  if (s21_list.size() != std_list.size()) return 1;
  if (s21_list.empty() != std_list.empty()) return 2;

  typename s21::list<T>::iterator it1 = s21_list.begin();
  typename std::list<T>::iterator it2 = std_list.begin();

  for (; it1 != s21_list.end(); ++it1, ++it2) {
    if (*it1 != *it2) return 3;
  }

  if (it2 != std_list.end()) return 4;

  return 0;
};

// default constructor
TEST(SuiteList, DefaultConstructor) {
  s21::list<int> l1;
  std::list<int> l2;

  ASSERT_EQ(compare_with_std(l1, l2), 0);
}

// parameter constructor
TEST(SuiteList, ParameterConstructor) {
  s21::list<char> l1(5);
  std::list<char> l2(5);

  ASSERT_EQ(compare_with_std(l1, l2), 0);

  s21::list<char> l3(0);
  std::list<char> l4(0);

  ASSERT_EQ(compare_with_std(l3, l4), 0);

  s21::list<char> l5(1);
  std::list<char> l6(1);

  ASSERT_EQ(compare_with_std(l5, l6), 0);
}

// initializer list constructor
TEST(SuiteList, InitializerListConstructor) {
  s21::list<std::string> l1({"Hello", "it's", "a me", "Mario!"});
  std::list<std::string> l2({"Hello", "it's", "a me", "Mario!"});

  ASSERT_EQ(compare_with_std(l1, l2), 0);

  s21::list<double> l3({21.4, -2.003, -0.005, 15, 10E2});
  std::list<double> l4({21.4, -2.003, -0.005, 15, 10E2});

  ASSERT_EQ(compare_with_std(l3, l4), 0);

  s21::list<int> l5({});
  std::list<int> l6({});

  ASSERT_EQ(compare_with_std(l5, l6), 0);

  s21::list<char> l7({'s'});
  std::list<char> l8({'s'});

  ASSERT_EQ(compare_with_std(l7, l8), 0);
}

// copy constructor
TEST(SuiteList, CopyConstructor) {
  s21::list<int> l1({1, 2, 3, 4, 5});
  s21::list<int> l2(l1);

  ASSERT_EQ(compare_with_s21(l1, l2), 0);

  s21::list<double> l3({1.01, 2.92, -100.5, 54.2});
  s21::list<double> l4(l3);

  ASSERT_EQ(compare_with_s21(l3, l4), 0);

  s21::list<std::string> l5;
  s21::list<std::string> l6(l5);

  ASSERT_EQ(compare_with_s21(l5, l6), 0);
}

// move constructor
TEST(SuiteList, MoveConstructor) {
  std::initializer_list init_list({52, 14, -2, 54, -9, 5, 2});

  s21::list<int> s21_src({init_list});
  std::list<int> std_src({init_list});

  s21::list<int> s21_dst = std::move(s21_src);
  std::list<int> std_dst = std::move(std_src);

  ASSERT_EQ(compare_with_std(s21_src, std_src), 0);
  ASSERT_EQ(compare_with_std(s21_dst, std_dst), 0);
}

// оператор перемещения объекта
TEST(SuiteList, Assignment) {
  std::initializer_list init_list({1, 2, 3, 4, 5});
  s21::list<int> s21_src(init_list);
  std::list<int> std_src(init_list);

  s21::list<int> s21_dst({13, 3});
  std::list<int> std_dst({1, 2});

  s21_dst = std::move(s21_src);
  std_dst = std::move(std_src);

  ASSERT_EQ(compare_with_std(s21_src, std_src), 0);
  ASSERT_EQ(compare_with_std(s21_dst, std_dst), 0);
}

TEST(SuiteList, Front) {
  std::initializer_list init_list({1, 2, 3, 4, 5, 6, 7, -20, -30});
  s21::list<int> s21_list(init_list);
  std::list<int> std_list(init_list);

  int size = s21_list.size();
  for (int i = 0; i < size; i++) {
    ASSERT_EQ(s21_list.front(), std_list.front());
    s21_list.pop_front();
    std_list.pop_front();
  }

  ASSERT_EQ(s21_list.front(), int());

  s21::list<char> ch_list;
  ASSERT_EQ(ch_list.front(), char());

  s21::list<std::string> str_list({"like"});
  ASSERT_EQ(str_list.front(), "like");

  str_list.pop_front();
  ASSERT_EQ(str_list.front(), std::string());
}

TEST(SuiteList, Back) {
  std::initializer_list init_list({50, 14, 5, 18, 2});
  s21::list<int> s21_list(init_list);
  std::list<int> std_list(init_list);

  int size = s21_list.size();
  for (int i = 0; i < size; i++) {
    ASSERT_EQ(s21_list.back(), std_list.back());
    s21_list.pop_back();
    std_list.pop_back();
  }

  ASSERT_EQ(s21_list.back(), int());

  s21::list<std::string> str_list({"yellow", "submarine"});
  ASSERT_EQ(str_list.back(), "submarine");
  str_list.pop_back();
  str_list.pop_back();
  ASSERT_EQ(str_list.back(), std::string());
}

TEST(SuiteList, Clear) {
  std::initializer_list init_list({1, 2, 3, 4, 5});
  s21::list<int> s21_list(init_list);
  std::list<int> std_list(init_list);

  s21_list.clear();
  std_list.clear();

  ASSERT_EQ(compare_with_std(s21_list, std_list), 0);

  s21::list<char> ch_list;
  ch_list.clear();
  ASSERT_TRUE(ch_list.empty());

  s21::list<std::string> str_list({"some", "text", "is", "here"});
  str_list.clear();
  ASSERT_TRUE(str_list.empty());
}

TEST(SuiteList, Insert) {
  std::initializer_list init_list({1, 2, 3, 4, 5});
  s21::list<int> s21_list(init_list);
  std::list<int> std_list(init_list);

  s21::list<int>::iterator s21_it = s21_list.begin();
  std::list<int>::iterator std_it = std_list.begin();

  ++(s21_it);
  ++(s21_it);

  ++(std_it);
  ++(std_it);

  s21_list.insert(s21_it, 9);
  std_list.insert(std_it, 9);

  ASSERT_EQ(compare_with_std(s21_list, std_list), 0);
  ASSERT_EQ(*s21_it, *std_it);

  s21::list<char> ch_list_s21;
  std::list<char> ch_list_std;
  ch_list_s21.insert(ch_list_s21.end(), 'a');
  ch_list_std.insert(ch_list_std.end(), 'a');
  ASSERT_EQ(compare_with_std(ch_list_s21, ch_list_std), 0);
  ch_list_s21.insert(ch_list_s21.begin(), 'b');
  ch_list_std.insert(ch_list_std.begin(), 'b');
  ASSERT_EQ(compare_with_std(ch_list_s21, ch_list_std), 0);
}

TEST(SuiteList, InsertMany) {
  s21::list<int> s21_list({1, 2, 3, 4, 5});

  s21::list<int>::iterator s21_it = s21_list.begin();

  ++(s21_it);
  ++(s21_it);

  s21_list.insert_many(s21_it, 9, 15, 20);
  s21::list<int> result({1, 2, 9, 15, 20, 3, 4, 5});

  ASSERT_EQ(compare_with_s21(s21_list, result), 0);

  s21::list<char> ch_list_s21;

  ch_list_s21.insert_many(ch_list_s21.begin(), 'a', 'b', 'c');

  s21::list<char> ch_list_result({'a', 'b', 'c'});
  ASSERT_EQ(compare_with_s21(ch_list_s21, ch_list_result), 0);
}

TEST(SuiteList, InsertManyBack) {
  s21::list<int> s21_list({1, 2, 3, 4, 5});

  s21_list.insert_many_back(9, 15, 20);
  s21::list<int> result({1, 2, 3, 4, 5, 9, 15, 20});

  ASSERT_EQ(compare_with_s21(s21_list, result), 0);

  s21::list<char> ch_list_s21;

  ch_list_s21.insert_many_back('a', 'b', 'c');

  s21::list<char> ch_list_result({'a', 'b', 'c'});
  ASSERT_EQ(compare_with_s21(ch_list_s21, ch_list_result), 0);
}

TEST(SuiteList, InsertManyFront) {
  s21::list<double> s21_list({10.2, 11.5, -0.004, 5});
  s21_list.insert_many_front(5.2, 14, -9.12);
  s21::list<double> result({5.2, 14, -9.12, 10.2, 11.5, -0.004, 5});
  ASSERT_EQ(compare_with_s21(s21_list, result), 0);

  s21::list<std::string> str_list;
  str_list.insert_many_front("hello", "world");
  s21::list<std::string> str_result({"hello", "world"});
  ASSERT_EQ(compare_with_s21(str_list, str_result), 0);
}

TEST(SuiteList, Erase) {
  std::initializer_list init_list({1, 2, 3, 4, 5});

  s21::list<int> s21_list(init_list);
  std::list<int> std_list(init_list);

  s21::list<int>::iterator it_s21 = s21_list.begin();
  std::list<int>::iterator it_std = std_list.begin();

  it_s21 = s21_list.erase(it_s21);
  it_std = std_list.erase(it_std);

  ASSERT_EQ(compare_with_std(s21_list, std_list), 0);
  ASSERT_EQ(*it_s21, *it_std);

  ++it_s21;
  ++it_std;

  it_s21 = s21_list.erase(it_s21);
  it_std = std_list.erase(it_std);

  ASSERT_EQ(compare_with_std(s21_list, std_list), 0);
  ASSERT_EQ(*it_s21, *it_std);

  s21::list<int> empty_list_s21;

  s21::list<int>::iterator it_empty_s21 = empty_list_s21.end();

  ASSERT_THROW(empty_list_s21.erase(it_empty_s21), std::out_of_range);
}

TEST(SuiteList, PushBack) {
  std::initializer_list init_list({1, 2, 3, 4, 5, 6, 7});

  s21::list<int> s21_list(init_list);
  std::list<int> std_list(init_list);

  s21_list.push_back(5);
  std_list.push_back(5);

  ASSERT_EQ(compare_with_std(s21_list, std_list), 0);

  s21_list.push_back(30);
  std_list.push_back(30);

  ASSERT_EQ(compare_with_std(s21_list, std_list), 0);

  s21::list<int> result({1, 2, 3, 4, 5, 6, 7, 5, 30});
  ASSERT_EQ(compare_with_s21(s21_list, result), 0);

  s21::list<std::string> empty_s21_list;
  std::list<std::string> empty_std_list;

  empty_s21_list.push_back("hello");
  empty_std_list.push_back("hello");

  ASSERT_EQ(compare_with_std(empty_s21_list, empty_std_list), 0);
}

TEST(SuiteList, PopBack) {
  std::initializer_list init_list({1, 2, 3, 4, 5, 6, 7});

  s21::list<int> s21_list(init_list);
  std::list<int> std_list(init_list);

  s21_list.pop_back();
  std_list.pop_back();

  ASSERT_EQ(compare_with_std(s21_list, std_list), 0);

  s21_list.pop_back();
  std_list.pop_back();

  ASSERT_EQ(compare_with_std(s21_list, std_list), 0);

  s21::list<int> result({1, 2, 3, 4, 5});
  ASSERT_EQ(compare_with_s21(s21_list, result), 0);

  s21::list<std::string> empty_s21_list;

  ASSERT_THROW(empty_s21_list.pop_back(), std::out_of_range);
}

TEST(SuiteList, PushFront) {
  std::initializer_list init_list({1, 2, 3, 4, 5, 6, 7});

  s21::list<int> s21_list(init_list);
  std::list<int> std_list(init_list);

  s21_list.push_front(5);
  std_list.push_front(5);

  ASSERT_EQ(compare_with_std(s21_list, std_list), 0);

  s21_list.push_front(30);
  std_list.push_front(30);

  ASSERT_EQ(compare_with_std(s21_list, std_list), 0);

  s21::list<int> result({30, 5, 1, 2, 3, 4, 5, 6, 7});
  ASSERT_EQ(compare_with_s21(s21_list, result), 0);

  s21::list<std::string> empty_s21_list;
  std::list<std::string> empty_std_list;

  empty_s21_list.push_front("hello");
  empty_std_list.push_front("hello");

  ASSERT_EQ(compare_with_std(empty_s21_list, empty_std_list), 0);
}

TEST(SuiteList, PopFront) {
  std::initializer_list init_list({1, 2, 3, 4, 5, 6, 7});

  s21::list<int> s21_list(init_list);
  std::list<int> std_list(init_list);

  s21_list.pop_front();
  std_list.pop_front();

  ASSERT_EQ(compare_with_std(s21_list, std_list), 0);

  s21_list.pop_front();
  std_list.pop_front();

  ASSERT_EQ(compare_with_std(s21_list, std_list), 0);

  s21::list<int> result({3, 4, 5, 6, 7});
  ASSERT_EQ(compare_with_s21(s21_list, result), 0);

  s21::list<std::string> empty_s21_list;

  ASSERT_THROW(empty_s21_list.pop_front(), std::out_of_range);
}

TEST(SuiteList, Merge) {
  std::initializer_list l11({2, 4, 6, 8, 10, 12});
  std::initializer_list l12({1, 3, 5, 7, 9, 11});
  std::initializer_list merged1({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});

  s21::list<int> s21_list_11(l11);
  s21::list<int> s21_list_12(l12);

  std::list<int> std_list_11(l11);
  std::list<int> std_list_12(l12);

  s21_list_11.merge(s21_list_12);
  std_list_11.merge(std_list_12);

  ASSERT_EQ(compare_with_std(s21_list_11, std_list_11), 0);
  ASSERT_EQ(compare_with_std(s21_list_12, std_list_12), 0);

  s21::list<int> result1(merged1);
  ASSERT_EQ(compare_with_s21(s21_list_11, result1), 0);

  std::initializer_list<double> l21({5, 4.2, 2.1, 8});
  std::initializer_list<double> l22({2.5, 3.6, -2, 4, 4, 8, 11, 3});
  std::initializer_list<double> merged2(
      {2.5, 3.6, -2, 4, 4, 5, 4.2, 2.1, 8, 8, 11, 3});

  s21::list<double> s21_list_21(l21);
  s21::list<double> s21_list_22(l22);

  std::list<double> std_list_21(l21);
  std::list<double> std_list_22(l22);

  s21_list_21.merge(s21_list_22);
  std_list_21.merge(std_list_22);

  ASSERT_EQ(compare_with_std(s21_list_21, std_list_21), 0);
  ASSERT_EQ(compare_with_std(s21_list_22, std_list_22), 0);

  s21::list<double> result2(merged2);
  ASSERT_EQ(compare_with_s21(s21_list_21, result2), 0);

  // первый лист пустой
  std::initializer_list l3({1, 3, 5, 7, 9, 11});
  std::initializer_list merged3({1, 3, 5, 7, 9, 11});

  s21::list<int> s21_list_31;
  s21::list<int> s21_list_32(l3);

  std::list<int> std_list_31;
  std::list<int> std_list_32(l3);

  s21_list_31.merge(s21_list_32);
  std_list_31.merge(std_list_32);

  ASSERT_EQ(compare_with_std(s21_list_31, std_list_31), 0);
  ASSERT_EQ(compare_with_std(s21_list_32, std_list_32), 0);

  s21::list<int> result3(merged3);
  ASSERT_EQ(compare_with_s21(s21_list_31, result3), 0);
}

TEST(SuiteList, Swap) {
  s21::list<char> s21_list_1({'a', 'b', 'c'});
  s21::list<char> s21_list_2({'g', 'l', 'a', 'a'});

  std::list<char> std_list_1({'a', 'b', 'c'});
  std::list<char> std_list_2({'g', 'l', 'a', 'a'});

  ASSERT_EQ(compare_with_std(s21_list_1, std_list_1), 0);
  ASSERT_EQ(compare_with_std(s21_list_2, std_list_2), 0);

  s21_list_1.swap(s21_list_2);
  std_list_1.swap(std_list_2);

  ASSERT_EQ(compare_with_std(s21_list_1, std_list_1), 0);
  ASSERT_EQ(compare_with_std(s21_list_2, std_list_2), 0);

  s21::list<int> s21_list_empty;
  std::list<int> std_list_empty;

  s21::list<int> s21_list_3({5, 3});
  std::list<int> std_list_3({5, 3});

  s21_list_empty.swap(s21_list_3);
  std_list_empty.swap(std_list_3);

  ASSERT_EQ(compare_with_std(s21_list_empty, std_list_empty), 0);
  ASSERT_EQ(compare_with_std(s21_list_3, std_list_3), 0);
}

TEST(SuiteList, Splice) {
  // splice листа с самим собой
  std::initializer_list init_list({1, 2, 3});
  s21::list<int> s21_list_1(init_list);
  s21::list<int> s21_list_2(init_list);

  s21_list_1.splice(s21_list_1.cbegin(), s21_list_1);

  ASSERT_EQ(compare_with_s21(s21_list_1, s21_list_2), 0);

  // второй список пустой
  s21::list<int> s21_list_3(init_list);
  s21::list<int> s21_list_4;
  std::list<int> std_list_3(init_list);
  std::list<int> std_list_4;

  s21_list_3.splice(s21_list_3.cbegin(), s21_list_4);
  std_list_3.splice(std_list_3.cbegin(), std_list_4);

  ASSERT_EQ(compare_with_std(s21_list_3, std_list_3), 0);
  ASSERT_EQ(compare_with_std(s21_list_4, std_list_4), 0);

  // первый список пустой
  s21::list<int> s21_list_5;
  s21::list<int> s21_list_6(init_list);
  std::list<int> std_list_5;
  std::list<int> std_list_6(init_list);

  s21_list_5.splice(s21_list_5.cbegin(), s21_list_6);
  std_list_5.splice(std_list_5.cbegin(), std_list_6);

  ASSERT_EQ(compare_with_std(s21_list_5, std_list_5), 0);
  ASSERT_EQ(compare_with_std(s21_list_6, std_list_6), 0);

  // оба списка не пустые
  std::initializer_list<double> init_list_1({3.2, 5.2, 14.004, -7.2});
  std::initializer_list<double> init_list_2({14, 3.0032, 4.56, 12.6});
  s21::list<double> s21_list_7(init_list_1);
  s21::list<double> s21_list_8(init_list_2);

  std::list<double> std_list_7(init_list_1);
  std::list<double> std_list_8(init_list_2);

  s21::list<double>::const_iterator s21_cit = s21_list_7.cbegin();
  std::list<double>::const_iterator std_cit = std_list_7.cbegin();

  s21_list_7.splice(s21_cit, s21_list_8);
  std_list_7.splice(std_cit, std_list_8);

  ASSERT_EQ(compare_with_std(s21_list_7, std_list_7), 0);
  ASSERT_EQ(compare_with_std(s21_list_8, std_list_8), 0);
}

TEST(SuiteList, Reverse) {
  std::initializer_list init_list_1({1, 2, 3, 4, 5});
  s21::list<int> s21_list_1(init_list_1);
  std::list<int> std_list_1(init_list_1);

  s21_list_1.reverse();
  std_list_1.reverse();

  ASSERT_EQ(compare_with_std(s21_list_1, std_list_1), 0);

  std::initializer_list<std::string> init_list_2(
      {"I am", "very", "very", "extra", "ordinary"});
  s21::list<std::string> s21_list_2(init_list_2);
  std::list<std::string> std_list_2(init_list_2);

  s21_list_2.reverse();
  std_list_2.reverse();

  ASSERT_EQ(compare_with_std(s21_list_2, std_list_2), 0);

  s21::list<std::string> result({"ordinary", "extra", "very", "very", "I am"});
  ASSERT_EQ(compare_with_s21(s21_list_2, result), 0);
}

TEST(SuiteList, Unique) {
  // пустой лист
  s21::list<int> s21_empty;
  std::list<int> std_empty;

  s21_empty.unique();
  std_empty.unique();

  ASSERT_EQ(compare_with_std(s21_empty, std_empty), 0);

  // не пустой
  std::initializer_list init_list(
      {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 1, 1, 2, 3, 2});
  s21::list<int> s21_list_1(init_list);
  std::list<int> std_list_1(init_list);

  s21_list_1.unique();
  std_list_1.unique();

  ASSERT_EQ(compare_with_std(s21_list_1, std_list_1), 0);

  s21::list<int> result1({1, 2, 3, 4, 5, 1, 2, 3, 2});
  ASSERT_EQ(compare_with_s21(s21_list_1, result1), 0);

  std::initializer_list<std::string> str_list(
      {"first", "second", "second", "first", "third", "third"});
  s21::list<std::string> s21_list_2(str_list);
  std::list<std::string> std_list_2(str_list);

  s21_list_2.unique();
  std_list_2.unique();

  ASSERT_EQ(compare_with_std(s21_list_2, std_list_2), 0);

  s21::list<std::string> result2({"first", "second", "first", "third"});
  ASSERT_EQ(compare_with_s21(s21_list_2, result2), 0);
}

TEST(SuiteList, Sort) {
  // size == 0
  s21::list<int> s21_list_1;
  std::list<int> std_list_1;

  s21_list_1.sort();
  std_list_1.sort();

  ASSERT_EQ(compare_with_std(s21_list_1, std_list_1), 0);

  // size == 1
  s21::list<int> s21_list_2({5});
  std::list<int> std_list_2({5});

  s21_list_2.sort();
  std_list_2.sort();

  ASSERT_EQ(compare_with_std(s21_list_2, std_list_2), 0);

  // size > 1
  std::initializer_list init_list_1({4, -2, 15, 16, 16, 7, 8, -9, 5});
  s21::list<int> s21_list_3(init_list_1);
  std::list<int> std_list_3(init_list_1);

  s21_list_3.sort();
  std_list_3.sort();

  ASSERT_EQ(compare_with_std(s21_list_3, std_list_3), 0);

  s21::list<int> result_1({-9, -2, 4, 5, 7, 8, 15, 16, 16});
  ASSERT_EQ(compare_with_s21(s21_list_3, result_1), 0);

  std::initializer_list<char> init_list_2({'d', 'g', 'c', 'c', 'b', 'a'});
  s21::list<char> s21_list_4(init_list_2);
  std::list<char> std_list_4(init_list_2);

  s21_list_4.sort();
  std_list_4.sort();

  ASSERT_EQ(compare_with_std(s21_list_4, std_list_4), 0);

  s21::list<char> result_2({'a', 'b', 'c', 'c', 'd', 'g'});
  ASSERT_EQ(compare_with_s21(s21_list_4, result_2), 0);
}

TEST(SuiteList, BeginAndEnd) {
  std::initializer_list init_list({1, 2, 3, 4, 5, 6, 7});

  s21::list<int> s21_list(init_list);
  std::list<int> std_list(init_list);

  s21::list<int>::iterator s21_it = s21_list.begin();
  std::list<int>::iterator std_it = std_list.begin();

  for (; s21_it != s21_list.end(); s21_it++, std_it++) {
    ASSERT_EQ(*s21_it, *std_it);
  }

  ASSERT_TRUE(std_it == std_list.end());
}

TEST(SuiteList, CBeginAndCEnd) {
  std::initializer_list init_list({1, 2, 3, 4, 5, 6, 7});

  s21::list<int> s21_list(init_list);
  std::list<int> std_list(init_list);

  s21::list<int>::const_iterator s21_cit = s21_list.cbegin();
  std::list<int>::const_iterator std_cit = std_list.cbegin();

  for (; s21_cit != s21_list.cend(); s21_cit++, std_cit++) {
    ASSERT_EQ(*s21_cit, *std_cit);
  }

  ASSERT_TRUE(std_cit == std_list.cend());
}

TEST(SuiteList, IteratorOperators) {
  std::initializer_list init_list({1, 2, 3, 4, 5, 6, 7});
  s21::list<int> s21_list(init_list);
  std::list<int> std_list(init_list);

  // ++
  s21::list<int>::iterator s21_it = s21_list.begin();
  std::list<int>::iterator std_it = std_list.begin();

  s21_it++;
  std_it++;

  ASSERT_EQ(*s21_it, *std_it);

  (s21_it++)++;
  (std_it++)++;

  ASSERT_EQ(*s21_it, *std_it);

  // --
  s21_it = s21_list.end();
  std_it = std_list.end();

  s21_it--;
  std_it--;

  ASSERT_EQ(*s21_it, *std_it);

  (s21_it--)--;
  (std_it--)--;

  ASSERT_EQ(*s21_it, *std_it);

  // *
  s21_it = s21_list.begin();
  std_it = std_list.begin();

  *s21_it = 100;
  *std_it = 100;

  ASSERT_EQ(s21_list.front(), std_list.front());

  // ==
  ASSERT_TRUE(s21_it == s21_list.begin());
  ASSERT_FALSE(s21_it == s21_list.end());

  // !=
  ASSERT_TRUE(s21_it != s21_list.end());
  ASSERT_FALSE(s21_it != s21_list.begin());
}

TEST(SuiteList, ConstIteratorOperators) {
  std::initializer_list init_list({1, 2, 3, 4, 5, 6, 7});
  s21::list<int> s21_list(init_list);
  std::list<int> std_list(init_list);

  // ++
  s21::list<int>::const_iterator s21_it = s21_list.cbegin();
  std::list<int>::const_iterator std_it = std_list.cbegin();

  s21_it++;
  std_it++;

  ASSERT_EQ(*s21_it, *std_it);

  (s21_it++)++;
  (std_it++)++;

  ASSERT_EQ(*s21_it, *std_it);

  // --
  s21_it = s21_list.end();
  std_it = std_list.end();

  s21_it--;
  std_it--;

  ASSERT_EQ(*s21_it, *std_it);

  (s21_it--)--;
  (std_it--)--;

  ASSERT_EQ(*s21_it, *std_it);

  s21_it = s21_list.cbegin();
  std_it = std_list.cbegin();
  // ==
  ASSERT_TRUE(s21_it == s21_list.cbegin());
  ASSERT_FALSE(s21_it == s21_list.cend());

  // !=
  ASSERT_TRUE(s21_it != s21_list.cend());
  ASSERT_FALSE(s21_it != s21_list.cbegin());
}

#include "s21_tests_main.h"

template <typename K, typename T>
int compare_with_s21(s21::map<K, T> &map1, s21::map<K, T> &map2) {
  if (map1.size() != map2.size()) return 1;
  if (map1.empty() != map2.empty()) return 2;

  typename s21::map<K, T>::iterator it1 = map1.begin();
  typename s21::map<K, T>::iterator it2 = map2.begin();

  for (; it1 != map1.end(); ++it1, ++it2) {
    if (*it1 != *it2) return 3;
  }

  if (it2 != map2.end()) return 4;

  return 0;
}

template <typename K, typename T>
bool compare_with_std(s21::map<K, T> &s21_map, std::map<K, T> &std_map) {
  if (s21_map.size() != std_map.size()) return 1;
  if (s21_map.empty() != std_map.empty()) return 2;

  typename s21::map<K, T>::iterator it1 = s21_map.begin();
  typename std::map<K, T>::iterator it2 = std_map.begin();

  for (; it1 != s21_map.end(); ++it1, ++it2) {
    if (*it1 != *it2) return 3;
  }

  if (it2 != std_map.end()) return 4;

  return 0;
};

TEST(SuiteMap, DefaultConstructor) {
  s21::map<int, char> m1;
  EXPECT_EQ(m1.size(), 0);
  EXPECT_TRUE(m1.empty());

  s21::map<char, double> m2;
  EXPECT_EQ(m2.size(), 0);
  EXPECT_TRUE(m2.empty());

  s21::map<std::string, std::string> m3;
  EXPECT_EQ(m3.size(), 0);
  EXPECT_TRUE(m3.empty());
}

TEST(SuiteMap, InitListConstructor) {
  s21::map<int, int> m1({{1, 2}, {2, 3}, {3, 4}, {4, 5}});
  EXPECT_EQ(m1[1], 2);
  EXPECT_EQ(m1[2], 3);
  EXPECT_EQ(m1[3], 4);
  EXPECT_EQ(m1[4], 5);
  EXPECT_EQ(m1.size(), 4);

  s21::map<double, std::string> m2(
      {{2.5, "Rf4-"}, {-800.2, "afafe12!F"}, {8, "eight"}});
  EXPECT_EQ(m2[2.5], "Rf4-");
  EXPECT_EQ(m2[-800.2], "afafe12!F");
  EXPECT_EQ(m2[8], "eight");
  EXPECT_EQ(m2.size(), 3);
}

TEST(SuiteMap, CopyConstructor) {
  s21::map<int, char> m1({{1, '1'},
                          {2, '2'},
                          {3, '3'},
                          {4, '4'},
                          {5, '5'},
                          {6, '6'},
                          {7, '7'},
                          {8, '8'},
                          {9, '9'},
                          {10, '0'}});

  s21::map<int, char> m2(m1);
  EXPECT_EQ(compare_with_s21(m1, m2), 0);

  s21::map<std::string, std::string> m3({{"one", "1"},
                                         {"two", "2"},
                                         {"three", "3"},
                                         {"four", "4"},
                                         {"five", "5"}});

  s21::map<std::string, std::string> m4(m3);
  EXPECT_EQ(compare_with_s21(m3, m4), 0);
}

TEST(SuiteMap, MoveConstructor) {
  s21::map<int, std::string> src1({{1, "one"},
                                   {2, "two"},
                                   {3, "three"},
                                   {4, "four"},
                                   {5, "five"},
                                   {6, "six"},
                                   {7, "seven"},
                                   {8, "eight"},
                                   {9, "nine"},
                                   {10, "ten"}});
  s21::map<int, std::string> src1_copy(src1);
  s21::map<int, std::string> dst1(std::move(src1));
  EXPECT_EQ(compare_with_s21(src1_copy, dst1), 0);
  EXPECT_TRUE(src1.empty());

  s21::map<int, int> src2;
  s21::map<int, int> src2_copy(src2);
  s21::map<int, int> dst2(std::move(src2));
  EXPECT_EQ(compare_with_s21(src2_copy, dst2), 0);
  EXPECT_TRUE(src2.empty());
}

TEST(SuiteMap, AssignmentOperator) {
  s21::map<int, std::string> src1({{1, "one"},
                                   {2, "two"},
                                   {3, "three"},
                                   {4, "four"},
                                   {5, "five"},
                                   {6, "six"},
                                   {7, "seven"},
                                   {8, "eight"},
                                   {9, "nine"},
                                   {10, "ten"}});
  s21::map<int, std::string> src1_copy(src1);
  s21::map<int, std::string> dst1;
  dst1 = std::move(src1);
  EXPECT_EQ(compare_with_s21(src1_copy, dst1), 0);
  EXPECT_TRUE(src1.empty());

  s21::map<int, int> src2;
  s21::map<int, int> src2_copy(src2);
  s21::map<int, int> dst2;
  dst2 = std::move(src2);
  EXPECT_EQ(compare_with_s21(src2_copy, dst2), 0);
  EXPECT_TRUE(src2.empty());
}

TEST(SuiteMap, BeginAndEnd) {
  s21::map<int, char> m1({{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}});
  auto it1 = m1.begin();
  EXPECT_EQ((*it1).first, 1);
  EXPECT_EQ((*it1).second, 'a');
  it1++;
  EXPECT_EQ((*it1).first, 2);
  EXPECT_EQ((*it1).second, 'b');

  it1 = m1.end();
  it1--;
  EXPECT_EQ((*it1).first, 4);
  EXPECT_EQ((*it1).second, 'd');
  it1--;
  EXPECT_EQ((*it1).first, 3);
  EXPECT_EQ((*it1).second, 'c');

  m1.clear();
  it1 = m1.begin();
  auto it2 = m1.end();
  EXPECT_TRUE(it1 == it2);
}

TEST(SuiteMap, CBeginAndCEnd) {
  s21::map<int, char> m1({{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}});
  auto it1 = m1.cbegin();
  EXPECT_EQ((*it1).first, 1);
  EXPECT_EQ((*it1).second, 'a');
  it1++;
  EXPECT_EQ((*it1).first, 2);
  EXPECT_EQ((*it1).second, 'b');

  it1 = m1.cend();
  it1--;
  EXPECT_EQ((*it1).first, 4);
  EXPECT_EQ((*it1).second, 'd');
  it1--;
  EXPECT_EQ((*it1).first, 3);
  EXPECT_EQ((*it1).second, 'c');

  m1.clear();
  it1 = m1.cbegin();
  auto it2 = m1.cend();
  EXPECT_TRUE(it1 == it2);
}

TEST(SuiteMap, DereferenceIterator) {
  s21::map<int, char> m1({{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}});
  auto it1 = m1.begin();
  EXPECT_EQ((*it1).second, 'a');
  (*it1).second = 'l';
  EXPECT_EQ(m1[1], 'l');
}

TEST(SuiteMap, SizeAndEmpty) {
  s21::map<int, char> m1;
  ASSERT_EQ(m1.size(), 0);
  ASSERT_TRUE(m1.empty());

  m1.insert(5, 'a');
  ASSERT_EQ(m1.size(), 1);
  ASSERT_FALSE(m1.empty());

  s21::map<int, std::string> m2(
      {{1, "hello"}, {2, "it's"}, {3, "a"}, {4, "me"}, {5, "Mario"}});
  ASSERT_EQ(m2.size(), 5);
  ASSERT_FALSE(m2.empty());

  m2.clear();
  ASSERT_EQ(m2.size(), 0);
  ASSERT_TRUE(m2.empty());
}

TEST(SuiteMap, At) {
  s21::map<int, std::string> m1(
      {{1, "hello"}, {2, "it's"}, {3, "a"}, {4, "me"}, {5, "Mario"}});

  ASSERT_EQ(m1.at(4), "me");
  ASSERT_THROW(m1.at(7), std::out_of_range);
}

TEST(SuiteMap, Operator) {
  s21::map<int, std::string> m1(
      {{1, "hello"}, {2, "it's"}, {3, "a"}, {4, "me"}, {5, "Mario"}});

  ASSERT_EQ(m1[4], "me");
  ASSERT_EQ(m1[10], std::string());
}

TEST(SuiteMap, Clear) {
  s21::map<int, int> m1;
  m1.clear();
  ASSERT_EQ(m1.size(), 0);
  ASSERT_TRUE(m1.empty());

  s21::map<int, int> m2({{1, 2}, {2, 3}, {3, 4}});
  m2.clear();
  ASSERT_EQ(m2.size(), 0);
  ASSERT_TRUE(m2.empty());
}

TEST(SuiteMap, Insert1) {
  s21::map<int, std::string> m1({{1, "one"}, {3, "three"}, {6, "six"}});
  std::pair<s21::map<int, std::string>::iterator, bool> pair =
      m1.insert({2, "two"});
  ASSERT_EQ(m1.size(), 4);
  ASSERT_EQ(m1.at(2), "two");
  ASSERT_TRUE(pair.second);

  std::pair<int, std::string> value = *(pair.first);
  std::pair<int, std::string> res = std::make_pair(2, "two");

  ASSERT_EQ(value, res);

  pair = m1.insert({2, "two"});
  ASSERT_EQ(m1.size(), 4);
  ASSERT_EQ(m1.at(2), "two");
  ASSERT_FALSE(pair.second);

  value = *(pair.first);
  res = std::make_pair(2, "two");

  ASSERT_EQ(value, res);
}

TEST(SuiteMap, Insert2) {
  s21::map<int, std::string> m1({{1, "one"}, {3, "three"}, {6, "six"}});
  std::pair<s21::map<int, std::string>::iterator, bool> pair =
      m1.insert(2, "two");
  ASSERT_EQ(m1.size(), 4);
  ASSERT_EQ(m1.at(2), "two");
  ASSERT_TRUE(pair.second);

  std::pair<int, std::string> value = *(pair.first);
  std::pair<int, std::string> res = std::make_pair(2, "two");

  ASSERT_EQ(value, res);

  pair = m1.insert(2, "two");
  ASSERT_EQ(m1.size(), 4);
  ASSERT_EQ(m1.at(2), "two");
  ASSERT_FALSE(pair.second);

  value = *(pair.first);
  res = std::make_pair(2, "two");

  ASSERT_EQ(value, res);
}

TEST(SuiteMap, InserOrAssign) {
  s21::map<int, std::string> m1({{1, "one"}, {3, "three"}, {6, "six"}});
  std::pair<s21::map<int, std::string>::iterator, bool> pair =
      m1.insert_or_assign(2, "two");
  ASSERT_EQ(m1.size(), 4);
  ASSERT_EQ(m1.at(2), "two");
  ASSERT_TRUE(pair.second);

  std::pair<int, std::string> value = *(pair.first);
  std::pair<int, std::string> res = std::make_pair(2, "two");

  ASSERT_EQ(value, res);

  pair = m1.insert_or_assign(2, "three");
  ASSERT_EQ(m1.size(), 4);
  ASSERT_EQ(m1.at(2), "three");
  ASSERT_FALSE(pair.second);

  value = *(pair.first);
  res = std::make_pair(2, "three");

  ASSERT_EQ(value, res);
}

TEST(SuiteMap, Erase) {
  s21::map<char, int> m1({{'c', 3}, {'d', 4}, {'z', 26}});
  s21::map<char, int> m2({{'a', 1}, {'c', 3}, {'d', 4}, {'z', 26}});

  m2.erase(m2.begin());
  ASSERT_EQ(compare_with_s21(m1, m2), 0);

  m2.erase(m2.end());
  ASSERT_EQ(compare_with_s21(m1, m2), 0);
}

TEST(SuiteMap, Swap) {
  s21::map<char, int> m1({{'a', 1}, {'c', 3}, {'d', 4}, {'z', 26}});
  s21::map<char, int> m2({{'e', 5}, {'f', 6}, {'g', 7}});

  s21::map<char, int> m3({{'a', 1}, {'c', 3}, {'d', 4}, {'z', 26}});
  s21::map<char, int> m4({{'e', 5}, {'f', 6}, {'g', 7}});

  m1.swap(m2);

  ASSERT_EQ(compare_with_s21(m1, m4), 0);
  ASSERT_EQ(compare_with_s21(m2, m3), 0);
}

TEST(SuiteMap, Merge) {
  s21::map<char, int> m1({{'a', 1}, {'c', 3}, {'d', 4}, {'z', 26}});
  s21::map<char, int> m2({{'a', 1}, {'e', 5}, {'f', 6}, {'g', 7}});

  s21::map<char, int> res1(
      {{'a', 1}, {'c', 3}, {'d', 4}, {'z', 26}, {'e', 5}, {'f', 6}, {'g', 7}});
  s21::map<char, int> res2({{'a', 1}});

  m1.merge(m2);
  ASSERT_EQ(compare_with_s21(m1, res1), 0);
  ASSERT_EQ(compare_with_s21(m2, res2), 0);
}

TEST(SuiteMap, Contains) {
  s21::map<int, int> m1({{1, 2}, {2, 3}, {3, 4}, {4, 5}});
  ASSERT_TRUE(m1.contains(1));
  ASSERT_FALSE(m1.contains(9));

  s21::map<std::string, int> m2({{"hello", 1}, {"World", 2}, {"word", 3}});
  ASSERT_TRUE(m2.contains("hello"));
  ASSERT_FALSE(m2.contains("not"));
}

TEST(SuiteMap, InsertMany) {
  s21::map<int, std::string> m1(
      {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}});
  std::vector<std::pair<s21::map<int, std::string>::iterator, bool>> v =
      m1.insert_many(std::make_pair(5, "five"), std::make_pair(6, "six"),
                     std::make_pair(7, "seven"), std::make_pair(8, "eight"),
                     std::make_pair(9, "nine"), std::make_pair(10, "ten"));

  s21::map<int, std::string> res({{1, "one"},
                                  {2, "two"},
                                  {3, "three"},
                                  {4, "four"},
                                  {5, "five"},
                                  {6, "six"},
                                  {7, "seven"},
                                  {8, "eight"},
                                  {9, "nine"},
                                  {10, "ten"}});
  ASSERT_EQ(compare_with_s21(m1, res), 0);

  ASSERT_FALSE(v[0].second);
  ASSERT_TRUE(v[1].second);
  ASSERT_TRUE(v[2].second);
  ASSERT_TRUE(v[3].second);
  ASSERT_TRUE(v[4].second);
  ASSERT_TRUE(v[5].second);
}
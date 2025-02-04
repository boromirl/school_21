#include "s21_tests_main.h"

// тестируем дефолтный конструктор

TEST(TestOfMultiset, TestOfDefaultConstructor1) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;

  EXPECT_TRUE(s21_multiset.empty());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(TestOfMultiset, TestOfDefaultConstructor2) {
  s21::multiset<double> s21_multiset;
  std::multiset<double> std_multiset;

  EXPECT_TRUE(s21_multiset.empty());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(TestOfMultiset, TestOfDefaultConstructor3) {
  s21::multiset<char> s21_multiset;
  std::multiset<char> std_multiset;

  EXPECT_TRUE(s21_multiset.empty());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(TestOfMultiset, TestOfDefaultConstructor4) {
  s21::multiset<std::string> s21_multiset;
  std::multiset<std::string> std_multiset;

  EXPECT_TRUE(s21_multiset.empty());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

// тестируем конструктор со списком инициализиации

TEST(TestOfMultiset, TestOfConstructorWithInitializerList1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5};

  EXPECT_EQ(s21_multiset.size(), s21_multiset.size());
  for (int element : {1, 2, 3, 4, 5}) {
    EXPECT_EQ(s21_multiset.count(element), std_multiset.count(element));
  }
}

TEST(TestOfMultiset, TestOfConstructorWithInitializerList2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5};

  EXPECT_EQ(s21_multiset.size(), s21_multiset.size());
  for (double element : {1.1, 2.2, 3.3, 4.4, 5.5}) {
    EXPECT_EQ(s21_multiset.count(element), std_multiset.count(element));
  }
}

TEST(TestOfMultiset, TestOfConstructorWithInitializerList3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e'};

  EXPECT_EQ(s21_multiset.size(), s21_multiset.size());
  for (char element : {'a', 'b', 'c', 'd', 'e'}) {
    EXPECT_EQ(s21_multiset.count(element), std_multiset.count(element));
  }
}

TEST(TestOfMultiset, TestOfConstructorWithInitializerList4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5"};

  EXPECT_EQ(s21_multiset.size(), s21_multiset.size());
  for (std::string element : {"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"}) {
    EXPECT_EQ(s21_multiset.count(element), std_multiset.count(element));
  }
}

// тестируем конструктор копирования
TEST(TestOfMultiset, TestOfCopyConstructor1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  s21::multiset<int> s21_multiset_copy(s21_multiset);
  std::multiset<int> std_multiset_copy(std_multiset);

  EXPECT_EQ(s21_multiset_copy.size(), std_multiset_copy.size());
  for (int element : {1, 2, 3, 4, 5, 1, 2, 3, 4, 5}) {
    EXPECT_EQ(s21_multiset_copy.count(element),
              std_multiset_copy.count(element));
    EXPECT_EQ(
        s21_multiset_copy.contains(element),
        std_multiset_copy.find(element) !=
            std_multiset_copy.end());  // используем find т.к. в std::multiset
                                       // C++17 еще нет contains, он появится в
                                       // C++20, а мы используем C++17
  }
}

TEST(TestOfMultiset, TestOfCopyConstructor2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};

  s21::multiset<double> s21_multiset_copy(s21_multiset);
  std::multiset<double> std_multiset_copy(std_multiset);

  EXPECT_EQ(s21_multiset_copy.size(), std_multiset_copy.size());
  for (double element : {1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2, 3.3, 4.4, 5.5}) {
    EXPECT_EQ(s21_multiset_copy.count(element),
              std_multiset_copy.count(element));
    EXPECT_EQ(s21_multiset_copy.contains(element),
              std_multiset_copy.find(element) != std_multiset_copy.end());
  }
}

TEST(TestOfMultiset, TestOfCopyConstructor3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};

  s21::multiset<char> s21_multiset_copy(s21_multiset);
  std::multiset<char> std_multiset_copy(std_multiset);

  EXPECT_EQ(s21_multiset_copy.size(), std_multiset_copy.size());
  for (char element : {'a', 'b', 'c', 'd', 'e', 'a', 'b', 'c', 'd', 'e'}) {
    EXPECT_EQ(s21_multiset_copy.count(element),
              std_multiset_copy.count(element));
    EXPECT_EQ(s21_multiset_copy.contains(element),
              std_multiset_copy.find(element) != std_multiset_copy.end());
  }
}

TEST(TestOfMultiset, TestOfCopyConstructor4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};

  s21::multiset<std::string> s21_multiset_copy(s21_multiset);
  std::multiset<std::string> std_multiset_copy(std_multiset);

  EXPECT_EQ(s21_multiset_copy.size(), std_multiset_copy.size());
  for (std::string element : {"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5", "aaA1",
                              "bBb2", "Ccc3", "ddD4", "eeE5"}) {
    EXPECT_EQ(s21_multiset_copy.count(element),
              std_multiset_copy.count(element));
    EXPECT_EQ(s21_multiset_copy.contains(element),
              std_multiset_copy.find(element) != std_multiset_copy.end());
  }
}

// тестируем оператор перемещения
TEST(TestOfMultiset, TestOfMoveConstructor1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  s21::multiset<int> s21_multiset_move(std::move(s21_multiset));
  std::multiset<int> std_multiset_move(std::move(std_multiset));

  EXPECT_EQ(s21_multiset_move.size(), std_multiset_move.size());
  for (int element : {1, 2, 3, 4, 5, 1, 2, 3, 4, 5}) {
    EXPECT_EQ(s21_multiset_move.count(element),
              std_multiset_move.count(element));
    EXPECT_EQ(s21_multiset_move.contains(element),
              std_multiset_move.find(element) != std_multiset_move.end());
  }
}

TEST(TestOfMultiset, TestOfMoveConstructor2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};

  s21::multiset<double> s21_multiset_move(std::move(s21_multiset));
  std::multiset<double> std_multiset_move(std::move(std_multiset));

  EXPECT_EQ(s21_multiset_move.size(), std_multiset_move.size());
  for (double element : {1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2, 3.3, 4.4, 5.5}) {
    EXPECT_EQ(s21_multiset_move.count(element),
              std_multiset_move.count(element));
    EXPECT_EQ(s21_multiset_move.contains(element),
              std_multiset_move.find(element) != std_multiset_move.end());
  }
}

TEST(TestOfMultiset, TestOfMoveConstructor3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};

  s21::multiset<char> s21_multiset_move(std::move(s21_multiset));
  std::multiset<char> std_multiset_move(std::move(std_multiset));

  EXPECT_EQ(s21_multiset_move.size(), std_multiset_move.size());
  for (char element : {'a', 'b', 'c', 'd', 'e', 'a', 'b', 'c', 'd', 'e'}) {
    EXPECT_EQ(s21_multiset_move.count(element),
              std_multiset_move.count(element));
    EXPECT_EQ(s21_multiset_move.contains(element),
              std_multiset_move.find(element) != std_multiset_move.end());
  }
}

TEST(TestOfMultiset, TestOfMoveConstructor4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};

  s21::multiset<std::string> s21_multiset_move(std::move(s21_multiset));
  std::multiset<std::string> std_multiset_move(std::move(std_multiset));

  EXPECT_EQ(s21_multiset_move.size(), std_multiset_move.size());
  for (std::string element : {"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5", "aaA1",
                              "bBb2", "Ccc3", "ddD4", "eeE5"}) {
    EXPECT_EQ(s21_multiset_move.count(element),
              std_multiset_move.count(element));
    EXPECT_EQ(s21_multiset_move.contains(element),
              std_multiset_move.find(element) != std_multiset_move.end());
  }
}

// тестируем оператор присваивания перемещением

TEST(TestOfMultiset, TestOfOperatorMoveAssignement1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  s21::multiset<int> s21_multiset_move;
  std::multiset<int> std_multiset_move;

  s21_multiset_move = std::move(s21_multiset);
  std_multiset_move = std::move(std_multiset);

  EXPECT_EQ(s21_multiset_move.size(), std_multiset_move.size());
  for (int element : {1, 2, 3, 4, 5, 1, 2, 3, 4, 5}) {
    EXPECT_EQ(s21_multiset_move.count(element),
              std_multiset_move.count(element));
    EXPECT_EQ(s21_multiset_move.contains(element),
              std_multiset_move.find(element) != std_multiset_move.end());
  }
}

TEST(TestOfMultiset, TestOfOperatorMoveAssignement2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};

  s21::multiset<double> s21_multiset_move;
  std::multiset<double> std_multiset_move;

  s21_multiset_move = std::move(s21_multiset);
  std_multiset_move = std::move(std_multiset);

  EXPECT_EQ(s21_multiset_move.size(), std_multiset_move.size());
  for (double element : {1.1, 2.2, 3.3, 4.4, 5.5, 1.1, 2.2, 3.3, 4.4, 5.5}) {
    EXPECT_EQ(s21_multiset_move.count(element),
              std_multiset_move.count(element));
    EXPECT_EQ(s21_multiset_move.contains(element),
              std_multiset_move.find(element) != std_multiset_move.end());
  }
}

TEST(TestOfMultiset, TestOfOperatorMoveAssignement3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};

  s21::multiset<char> s21_multiset_move;
  std::multiset<char> std_multiset_move;

  s21_multiset_move = std::move(s21_multiset);
  std_multiset_move = std::move(std_multiset);

  EXPECT_EQ(s21_multiset_move.size(), std_multiset_move.size());
  for (char element : {'a', 'b', 'c', 'd', 'e', 'a', 'b', 'c', 'd', 'e'}) {
    EXPECT_EQ(s21_multiset_move.count(element),
              std_multiset_move.count(element));
    EXPECT_EQ(s21_multiset_move.contains(element),
              std_multiset_move.find(element) != std_multiset_move.end());
  }
}

TEST(TestOfMultiset, TestOfOperatorMoveAssignement4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};

  s21::multiset<std::string> s21_multiset_move;
  std::multiset<std::string> std_multiset_move;

  s21_multiset_move = std::move(s21_multiset);
  std_multiset_move = std::move(std_multiset);

  EXPECT_EQ(s21_multiset_move.size(), std_multiset_move.size());
  for (std::string element : {"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5", "aaA1",
                              "bBb2", "Ccc3", "ddD4", "eeE5"}) {
    EXPECT_EQ(s21_multiset_move.count(element),
              std_multiset_move.count(element));
    EXPECT_EQ(s21_multiset_move.contains(element),
              std_multiset_move.find(element) != std_multiset_move.end());
  }
}

// тестируем итераторы (неконстантный и константный)
TEST(TestOfMultiset, TestOfBeginAndEndIterator1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  auto s21_iterator = s21_multiset.begin();
  auto std_iterator = std_multiset.begin();

  for (;
       s21_iterator != s21_multiset.end() && std_iterator != std_multiset.end();
       ++s21_iterator, ++std_iterator) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  }
  EXPECT_EQ(s21_iterator,
            s21_multiset.end());  // после цикла оба итератора должны оказаться
                                  // за последним элементом множества
  EXPECT_EQ(std_iterator, std_multiset.end());
}

TEST(TestOfMultiset, TestOfBeginAndEndIterator2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};

  auto s21_iterator = s21_multiset.begin();
  auto std_iterator = std_multiset.begin();

  for (;
       s21_iterator != s21_multiset.end() && std_iterator != std_multiset.end();
       ++s21_iterator, ++std_iterator) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  }
  EXPECT_EQ(s21_iterator, s21_multiset.end());
  EXPECT_EQ(std_iterator, std_multiset.end());
}

TEST(TestOfMultiset, TestOfBeginAndEndIterator3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};

  auto s21_iterator = s21_multiset.begin();
  auto std_iterator = std_multiset.begin();

  for (;
       s21_iterator != s21_multiset.end() && std_iterator != std_multiset.end();
       ++s21_iterator, ++std_iterator) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  }
  EXPECT_EQ(s21_iterator, s21_multiset.end());
  EXPECT_EQ(std_iterator, std_multiset.end());
}

TEST(TestOfMultiset, TestOfBeginAndEndIterator4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};

  auto s21_iterator = s21_multiset.begin();
  auto std_iterator = std_multiset.begin();

  for (;
       s21_iterator != s21_multiset.end() && std_iterator != std_multiset.end();
       ++s21_iterator, ++std_iterator) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  }
  EXPECT_EQ(s21_iterator, s21_multiset.end());
  EXPECT_EQ(std_iterator, std_multiset.end());
}

TEST(TestOfMultiset, TestOfConstBeginAndEndIterator1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  auto s21_iterator = s21_multiset.cbegin();
  auto std_iterator = std_multiset.cbegin();

  for (; s21_iterator != s21_multiset.cend() &&
         std_iterator != std_multiset.cend();
       ++s21_iterator, ++std_iterator) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  }
  EXPECT_EQ(s21_iterator, s21_multiset.cend());
  EXPECT_EQ(std_iterator, std_multiset.cend());
}

TEST(TestOfMultiset, TestOfConstBeginAndEndIterator2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};

  auto s21_iterator = s21_multiset.cbegin();
  auto std_iterator = std_multiset.cbegin();

  for (; s21_iterator != s21_multiset.cend() &&
         std_iterator != std_multiset.cend();
       ++s21_iterator, ++std_iterator) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  }
  EXPECT_EQ(s21_iterator, s21_multiset.cend());
  EXPECT_EQ(std_iterator, std_multiset.cend());
}

TEST(TestOfMultiset, TestOfConstBeginAndEndIterator3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};

  auto s21_iterator = s21_multiset.cbegin();
  auto std_iterator = std_multiset.cbegin();

  for (; s21_iterator != s21_multiset.cend() &&
         std_iterator != std_multiset.cend();
       ++s21_iterator, ++std_iterator) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  }
  EXPECT_EQ(s21_iterator, s21_multiset.cend());
  EXPECT_EQ(std_iterator, std_multiset.cend());
}

TEST(TestOfMultiset, TestOfConstBeginAndEndIterator4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};

  auto s21_iterator = s21_multiset.cbegin();
  auto std_iterator = std_multiset.cbegin();

  for (; s21_iterator != s21_multiset.cend() &&
         std_iterator != std_multiset.cend();
       ++s21_iterator, ++std_iterator) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  }
  EXPECT_EQ(s21_iterator, s21_multiset.cend());
  EXPECT_EQ(std_iterator, std_multiset.cend());
}
// вот эти тесты пока не работают, возможно это связано с реализацией деревьев

// тестируем методы доступа к информации о наполнении контейнера

TEST(TestOfMultiset, TestOfEmpty1) {
  s21::multiset<int> s21_multiset;
  std::multiset<int> std_multiset;
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());

  s21_multiset.insert(1);
  std_multiset.insert(1);
  EXPECT_EQ(s21_multiset.empty(),
            std_multiset.empty());  // в обоих случаях должно быть фолс
}

TEST(TestOfMultiset, TestOfEmpty2) {
  s21::multiset<double> s21_multiset;
  std::multiset<double> std_multiset;
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());

  s21_multiset.insert(1.1);
  std_multiset.insert(1.1);
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
}

TEST(TestOfMultiset, TestOfEmpty3) {
  s21::multiset<char> s21_multiset;
  std::multiset<char> std_multiset;
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());

  s21_multiset.insert('a');
  std_multiset.insert('a');
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
}

TEST(TestOfMultiset, TestOfEmpty4) {
  s21::multiset<std::string> s21_multiset;
  std::multiset<std::string> std_multiset;
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());

  s21_multiset.insert("aaA1");
  std_multiset.insert("aaA1");
  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
}

TEST(TestOfMultiset, TestOfSize1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(TestOfMultiset, TestOfSize2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};

  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(TestOfMultiset, TestOfSize3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};

  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(TestOfMultiset, TestOfSize4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};

  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

// тестируем публичные методя для изменения контейнера

TEST(TestOfMultiset, TestOfClear1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  s21_multiset.clear();
  std_multiset.clear();

  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(TestOfMultiset, TestOfClear2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};

  s21_multiset.clear();
  std_multiset.clear();

  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(TestOfMultiset, TestOfClear3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};

  s21_multiset.clear();
  std_multiset.clear();

  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(TestOfMultiset, TestOfClear4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};

  s21_multiset.clear();
  std_multiset.clear();

  EXPECT_EQ(s21_multiset.empty(), std_multiset.empty());
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
}

TEST(TestOfMultiset, TestOfInsert1) {
  s21::multiset<int> s21_multiset{1};
  std::multiset<int> std_multiset{1};
  // вставляем новый элемент
  auto s21_multiset_result = s21_multiset.insert(1);
  auto std_multiset_result = std_multiset.insert(1);

  EXPECT_EQ(*s21_multiset_result,
            *std_multiset_result);  // итераторы указывают на новый вставленный
                                    // элемент
  EXPECT_TRUE(s21_multiset.contains(1));
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(
      s21_multiset.count(1),
      std_multiset.count(1));  // посчитаем количество всех элементов 1, и их
                               // количество должно совпадать для обоих множеств
}

TEST(TestOfMultiset, TestOfInsert2) {
  s21::multiset<double> s21_multiset{1.1};
  std::multiset<double> std_multiset{1.1};

  auto s21_multiset_result = s21_multiset.insert(1.1);
  auto std_multiset_result = std_multiset.insert(1.1);

  EXPECT_EQ(*s21_multiset_result, *std_multiset_result);
  EXPECT_TRUE(s21_multiset.contains(1.1));
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset.count(1.1), std_multiset.count(1.1));
}

TEST(TestOfMultiset, TestOfInsert3) {
  s21::multiset<char> s21_multiset{'a'};
  std::multiset<char> std_multiset{'a'};

  auto s21_multiset_result = s21_multiset.insert('a');
  auto std_multiset_result = std_multiset.insert('a');

  EXPECT_EQ(*s21_multiset_result, *std_multiset_result);
  EXPECT_TRUE(s21_multiset.contains('a'));
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset.count('a'), std_multiset.count('a'));
}

TEST(TestOfMultiset, TestOfInsert4) {
  s21::multiset<std::string> s21_multiset{"Aaa1"};
  std::multiset<std::string> std_multiset{"Aaa1"};

  auto s21_multiset_result = s21_multiset.insert("Aaa1");
  auto std_multiset_result = std_multiset.insert("Aaa1");

  EXPECT_EQ(*s21_multiset_result, *std_multiset_result);
  EXPECT_TRUE(s21_multiset.contains("Aaa1"));
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_EQ(s21_multiset.count("Aaa1"), std_multiset.count("Aaa1"));
}

TEST(TestOfMultiset, TestOfErase1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  auto s21_iterator = s21_multiset.find(1);
  auto std_iterator = std_multiset.find(1);

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    s21_multiset.erase(
        s21_iterator);  // мы удаляем только один элемет 1, второй - остается!
    std_multiset.erase(std_iterator);
  }

  EXPECT_EQ(s21_multiset.count(1), std_multiset.count(1));
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_FALSE(s21_multiset.contains(1) && std_multiset.count(1) > 1);
}

TEST(TestOfMultiset, TestOfErase2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};

  auto s21_iterator = s21_multiset.find(1.1);
  auto std_iterator = std_multiset.find(1.1);

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    s21_multiset.erase(s21_iterator);
    std_multiset.erase(std_iterator);
  }

  EXPECT_EQ(s21_multiset.count(1.1), std_multiset.count(1.1));
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_FALSE(s21_multiset.contains(1.1) && std_multiset.count(1.1) > 1);
}

TEST(TestOfMultiset, TestOfErase3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};

  auto s21_iterator = s21_multiset.find('a');
  auto std_iterator = std_multiset.find('a');

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    s21_multiset.erase(s21_iterator);
    std_multiset.erase(std_iterator);
  }

  EXPECT_EQ(s21_multiset.count('a'), std_multiset.count('a'));
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_FALSE(s21_multiset.contains('a') && std_multiset.count('a') > 1);
}

TEST(TestOfMultiset, TestOfErase4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};

  auto s21_iterator = s21_multiset.find("aaA1");
  auto std_iterator = std_multiset.find("aaA1");

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    s21_multiset.erase(s21_iterator);
    std_multiset.erase(std_iterator);
  }

  EXPECT_EQ(s21_multiset.count("aaA1"), std_multiset.count("aaA1"));
  EXPECT_EQ(s21_multiset.size(), std_multiset.size());
  EXPECT_FALSE(s21_multiset.contains("aaA1") && std_multiset.count("aaA1") > 1);
}

TEST(TestOfMultiset, TestOfSwap1) {
  s21::multiset<int> s21_multiset_1{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  s21::multiset<int> s21_multiset_2{6, 7, 8, 6, 7, 8};
  std::multiset<int> std_multiset_1{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset_2{6, 7, 8, 6, 7, 8};

  s21_multiset_1.swap(s21_multiset_2);
  std_multiset_1.swap(std_multiset_2);

  EXPECT_EQ(s21_multiset_1.size(), std_multiset_1.size());
  EXPECT_EQ(s21_multiset_2.size(), std_multiset_2.size());

  s21::multiset<int>::iterator s21_iterator_1 =
      s21_multiset_1.begin();  // явно объявим и инициализируем наши итераторы,
                               // без использования auto (иначе возникнут
                               // сложности при компиляции)
  std::multiset<int>::iterator std_iterator_1 = std_multiset_1.begin();
  while (s21_iterator_1 != s21_multiset_1.end() &&
         std_iterator_1 != std_multiset_1.end()) {
    EXPECT_EQ(*s21_iterator_1, *std_iterator_1);
    ++s21_iterator_1;
    ++std_iterator_1;
  }

  s21::multiset<int>::iterator s21_iterator_2 = s21_multiset_2.begin();
  std::multiset<int>::iterator std_iterator_2 = std_multiset_2.begin();
  while (s21_iterator_2 != s21_multiset_2.end() &&
         std_iterator_2 != std_multiset_2.end()) {
    EXPECT_EQ(*s21_iterator_2, *std_iterator_2);
    ++s21_iterator_2;
    ++std_iterator_2;
  }
}

TEST(TestOfMultiset, TestOfSwap2) {
  s21::multiset<double> s21_multiset_1{1.1, 2.2, 3.3, 4.4, 5.5,
                                       1.1, 2.2, 3.3, 4.4, 5.5};
  s21::multiset<double> s21_multiset_2{6.6, 7.7, 8.8, 6.6, 7.7, 8.8};
  std::multiset<double> std_multiset_1{1.1, 2.2, 3.3, 4.4, 5.5,
                                       1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset_2{6.6, 7.7, 8.8, 6.6, 7.7, 8.8};

  s21_multiset_1.swap(s21_multiset_2);
  std_multiset_1.swap(std_multiset_2);

  EXPECT_EQ(s21_multiset_1.size(), std_multiset_1.size());
  EXPECT_EQ(s21_multiset_2.size(), std_multiset_2.size());

  s21::multiset<double>::iterator s21_iterator_1 = s21_multiset_1.begin();
  std::multiset<double>::iterator std_iterator_1 = std_multiset_1.begin();
  while (s21_iterator_1 != s21_multiset_1.end() &&
         std_iterator_1 != std_multiset_1.end()) {
    EXPECT_EQ(*s21_iterator_1, *std_iterator_1);
    ++s21_iterator_1;
    ++std_iterator_1;
  }

  s21::multiset<double>::iterator s21_iterator_2 = s21_multiset_2.begin();
  std::multiset<double>::iterator std_iterator_2 = std_multiset_2.begin();
  while (s21_iterator_2 != s21_multiset_2.end() &&
         std_iterator_2 != std_multiset_2.end()) {
    EXPECT_EQ(*s21_iterator_2, *std_iterator_2);
    ++s21_iterator_2;
    ++std_iterator_2;
  }
}

TEST(TestOfMultiset, TestOfSwap3) {
  s21::multiset<char> s21_multiset_1{'a', 'b', 'c', 'd', 'e',
                                     'a', 'b', 'c', 'd', 'e'};
  s21::multiset<char> s21_multiset_2{'f', 'g', 'h', 'f', 'g', 'h'};
  std::multiset<char> std_multiset_1{'a', 'b', 'c', 'd', 'e',
                                     'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset_2{'f', 'g', 'h', 'f', 'g', 'h'};

  s21_multiset_1.swap(s21_multiset_2);
  std_multiset_1.swap(std_multiset_2);

  EXPECT_EQ(s21_multiset_1.size(), std_multiset_1.size());
  EXPECT_EQ(s21_multiset_2.size(), std_multiset_2.size());

  s21::multiset<char>::iterator s21_iterator_1 =
      s21_multiset_1.begin();  // явно объявим и инициализируем наши итераторы,
                               // без использования auto (иначе возникнут
                               // сложности при компиляции)
  std::multiset<char>::iterator std_iterator_1 = std_multiset_1.begin();
  while (s21_iterator_1 != s21_multiset_1.end() &&
         std_iterator_1 != std_multiset_1.end()) {
    EXPECT_EQ(*s21_iterator_1, *std_iterator_1);
    ++s21_iterator_1;
    ++std_iterator_1;
  }

  s21::multiset<char>::iterator s21_iterator_2 = s21_multiset_2.begin();
  std::multiset<char>::iterator std_iterator_2 = std_multiset_2.begin();
  while (s21_iterator_2 != s21_multiset_2.end() &&
         std_iterator_2 != std_multiset_2.end()) {
    EXPECT_EQ(*s21_iterator_2, *std_iterator_2);
    ++s21_iterator_2;
    ++std_iterator_2;
  }
}

TEST(TestOfMultiset, TestOfSwap4) {
  s21::multiset<std::string> s21_multiset_1{"aaA1", "bBb2", "Ccc3", "ddD4",
                                            "eeE5", "aaA1", "bBb2", "Ccc3",
                                            "ddD4", "eeE5"};
  s21::multiset<std::string> s21_multiset_2{"fFf6", "Hhh7", "ggG8",
                                            "fFf6", "Hhh7", "ggG8"};
  std::multiset<std::string> std_multiset_1{"aaA1", "bBb2", "Ccc3", "ddD4",
                                            "eeE5", "aaA1", "bBb2", "Ccc3",
                                            "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset_2{"fFf6", "Hhh7", "ggG8",
                                            "fFf6", "Hhh7", "ggG8"};

  s21_multiset_1.swap(s21_multiset_2);
  std_multiset_1.swap(std_multiset_2);

  EXPECT_EQ(s21_multiset_1.size(), std_multiset_1.size());
  EXPECT_EQ(s21_multiset_2.size(), std_multiset_2.size());

  s21::multiset<std::string>::iterator s21_iterator_1 =
      s21_multiset_1.begin();  // явно объявим и инициализируем наши итераторы,
                               // без использования auto (иначе возникнут
                               // сложности при компиляции)
  std::multiset<std::string>::iterator std_iterator_1 = std_multiset_1.begin();
  while (s21_iterator_1 != s21_multiset_1.end() &&
         std_iterator_1 != std_multiset_1.end()) {
    EXPECT_EQ(*s21_iterator_1, *std_iterator_1);
    ++s21_iterator_1;
    ++std_iterator_1;
  }

  s21::multiset<std::string>::iterator s21_iterator_2 = s21_multiset_2.begin();
  std::multiset<std::string>::iterator std_iterator_2 = std_multiset_2.begin();
  while (s21_iterator_2 != s21_multiset_2.end() &&
         std_iterator_2 != std_multiset_2.end()) {
    EXPECT_EQ(*s21_iterator_2, *std_iterator_2);
    ++s21_iterator_2;
    ++std_iterator_2;
  }
}

TEST(TestOfMultiset, TestOfMerge1) {
  s21::multiset<int> s21_multiset_1{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  s21::multiset<int> s21_multiset_2{1, 1, 2, 2, 6, 7, 8, 6, 7, 8};
  std::multiset<int> std_multiset_1{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset_2{1, 1, 2, 2, 6, 7, 8, 6, 7, 8};

  s21_multiset_1.merge(s21_multiset_2);
  std_multiset_1.merge(std_multiset_2);

  s21::multiset<int>::iterator s21_iterator_1 = s21_multiset_1.begin();
  std::multiset<int>::iterator std_iterator_1 = std_multiset_1.begin();
  while (s21_iterator_1 != s21_multiset_1.end() &&
         std_iterator_1 != std_multiset_1.end()) {
    EXPECT_EQ(*s21_iterator_1, *std_iterator_1);
    ++s21_iterator_1;
    ++std_iterator_1;
  }

  EXPECT_EQ(s21_multiset_1.size(), std_multiset_1.size());
  EXPECT_TRUE(s21_multiset_2.empty());
  EXPECT_TRUE(std_multiset_2.empty());
}

TEST(TestOfMultiset, TestOfMerge2) {
  s21::multiset<double> s21_multiset_1{1.1, 2.2, 3.3, 4.4, 5.5,
                                       1.1, 2.2, 3.3, 4.4, 5.5};
  s21::multiset<double> s21_multiset_2{6.6, 7.7, 8.8, 6.6, 7.7, 8.8};
  std::multiset<double> std_multiset_1{1.1, 2.2, 3.3, 4.4, 5.5,
                                       1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset_2{6.6, 7.7, 8.8, 6.6, 7.7, 8.8};

  s21_multiset_1.merge(s21_multiset_2);
  std_multiset_1.merge(std_multiset_2);

  s21::multiset<double>::iterator s21_iterator_1 = s21_multiset_1.begin();
  std::multiset<double>::iterator std_iterator_1 = std_multiset_1.begin();
  while (s21_iterator_1 != s21_multiset_1.end() &&
         std_iterator_1 != std_multiset_1.end()) {
    EXPECT_EQ(*s21_iterator_1, *std_iterator_1);
    ++s21_iterator_1;
    ++std_iterator_1;
  }

  EXPECT_EQ(s21_multiset_1.size(), std_multiset_1.size());
  EXPECT_TRUE(s21_multiset_2.empty());
  EXPECT_TRUE(std_multiset_2.empty());
}

TEST(TestOfMultiset, TestOfMerge3) {
  s21::multiset<char> s21_multiset_1{'a', 'b', 'c', 'd', 'e',
                                     'a', 'b', 'c', 'd', 'e'};
  s21::multiset<char> s21_multiset_2{'f', 'g', 'h', 'f', 'g', 'h'};
  std::multiset<char> std_multiset_1{'a', 'b', 'c', 'd', 'e',
                                     'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset_2{'f', 'g', 'h', 'f', 'g', 'h'};

  s21_multiset_1.merge(s21_multiset_2);
  std_multiset_1.merge(std_multiset_2);

  s21::multiset<char>::iterator s21_iterator_1 = s21_multiset_1.begin();
  std::multiset<char>::iterator std_iterator_1 = std_multiset_1.begin();
  while (s21_iterator_1 != s21_multiset_1.end() &&
         std_iterator_1 != std_multiset_1.end()) {
    EXPECT_EQ(*s21_iterator_1, *std_iterator_1);
    ++s21_iterator_1;
    ++std_iterator_1;
  }

  EXPECT_EQ(s21_multiset_1.size(), std_multiset_1.size());
  EXPECT_TRUE(s21_multiset_2.empty());
  EXPECT_TRUE(std_multiset_2.empty());
}

TEST(TestOfMultiset, TestOfMerge4) {
  s21::multiset<std::string> s21_multiset_1{"aaA1", "bBb2", "Ccc3", "ddD4",
                                            "eeE5", "aaA1", "bBb2", "Ccc3",
                                            "ddD4", "eeE5"};
  s21::multiset<std::string> s21_multiset_2{"fFf6", "Hhh7", "ggG8",
                                            "fFf6", "Hhh7", "ggG8"};
  std::multiset<std::string> std_multiset_1{"aaA1", "bBb2", "Ccc3", "ddD4",
                                            "eeE5", "aaA1", "bBb2", "Ccc3",
                                            "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset_2{"fFf6", "Hhh7", "ggG8",
                                            "fFf6", "Hhh7", "ggG8"};

  s21_multiset_1.merge(s21_multiset_2);
  std_multiset_1.merge(std_multiset_2);

  s21::multiset<std::string>::iterator s21_iterator_1 = s21_multiset_1.begin();
  std::multiset<std::string>::iterator std_iterator_1 = std_multiset_1.begin();
  while (s21_iterator_1 != s21_multiset_1.end() &&
         std_iterator_1 != std_multiset_1.end()) {
    EXPECT_EQ(*s21_iterator_1, *std_iterator_1);
    ++s21_iterator_1;
    ++std_iterator_1;
  }

  EXPECT_EQ(s21_multiset_1.size(), std_multiset_1.size());
  EXPECT_TRUE(s21_multiset_2.empty());
  EXPECT_TRUE(std_multiset_2.empty());
}

// проверим, наконец методы просмотра контейнера

TEST(TestOfMultiset, TestOfCount1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  EXPECT_EQ(s21_multiset.count(1), std_multiset.count(1));
  EXPECT_EQ(s21_multiset.count(99), std_multiset.count(99));
}

TEST(TestOfMultiset, TestOfCount2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};

  EXPECT_EQ(s21_multiset.count(1.1), std_multiset.count(1.1));
  EXPECT_EQ(s21_multiset.count(99.99), std_multiset.count(99.99));
}

TEST(TestOfMultiset, TestOfCount3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};

  EXPECT_EQ(s21_multiset.count('a'), std_multiset.count('a'));
  EXPECT_EQ(s21_multiset.count('x'), std_multiset.count('x'));
}

TEST(TestOfMultiset, TestOfCount4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};

  EXPECT_EQ(s21_multiset.count("aaA1"), std_multiset.count("aaA1"));
  EXPECT_EQ(s21_multiset.count("xxX24"), std_multiset.count("xxX25"));
}

TEST(TestOfMultiset, TestOfFind1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  auto s21_iterator = s21_multiset.find(
      1);  // сначала найдем элементы и установим на них итератор
  auto std_iterator = std_multiset.find(1);
  // а затем, сравним значения, на которые указываеют итераторы, чтобы
  // удостовериться, что элементы в обоих множествах найдены совпадают, учтем
  // случаей если элементы не найдены
  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  } else {
    EXPECT_EQ(s21_iterator == s21_multiset.end(),
              std_iterator == std_multiset.end());
  }
}

TEST(TestOfMultiset, TestOfFind2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};

  auto s21_iterator = s21_multiset.find(1.1);
  auto std_iterator = std_multiset.find(1.1);

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  } else {
    EXPECT_EQ(s21_iterator == s21_multiset.end(),
              std_iterator == std_multiset.end());
  }
}

TEST(TestOfMultiset, TestOfFind3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};

  auto s21_iterator = s21_multiset.find('a');
  auto std_iterator = std_multiset.find('a');

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  } else {
    EXPECT_EQ(s21_iterator == s21_multiset.end(),
              std_iterator == std_multiset.end());
  }
}

TEST(TestOfMultiset, TestOfFind4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};

  auto s21_iterator = s21_multiset.find("aaA1");
  auto std_iterator = std_multiset.find("aaA1");

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  } else {
    EXPECT_EQ(s21_iterator == s21_multiset.end(),
              std_iterator == std_multiset.end());
  }
}

TEST(TestOfMultiset, TestOfContains1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  EXPECT_EQ(s21_multiset.contains(1),
            std_multiset.find(1) != std_multiset.end());
  EXPECT_EQ(s21_multiset.contains(3),
            std_multiset.find(3) != std_multiset.end());
  EXPECT_EQ(s21_multiset.contains(2),
            std_multiset.find(2) != std_multiset.end());
}

TEST(TestOfMultiset, TestOfContains2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};

  EXPECT_EQ(s21_multiset.contains(1.1),
            std_multiset.find(1.1) != std_multiset.end());
  EXPECT_EQ(s21_multiset.contains(2.2),
            std_multiset.find(2.2) != std_multiset.end());
  EXPECT_EQ(s21_multiset.contains(3.3),
            std_multiset.find(3.3) != std_multiset.end());
}

TEST(TestOfMultiset, TestOfContains3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};

  EXPECT_EQ(s21_multiset.contains('a'),
            std_multiset.find('a') != std_multiset.end());
  EXPECT_EQ(s21_multiset.contains('b'),
            std_multiset.find('b') != std_multiset.end());
  EXPECT_EQ(s21_multiset.contains('c'),
            std_multiset.find('c') != std_multiset.end());
}

TEST(TestOfMultiset, TestOfContains4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};

  EXPECT_EQ(s21_multiset.contains("aaA1"),
            std_multiset.find("aaA1") != std_multiset.end());
  EXPECT_EQ(s21_multiset.contains("Ccc3"),
            std_multiset.find("Ccc3") != std_multiset.end());
  EXPECT_EQ(s21_multiset.contains("eeE5"),
            std_multiset.find("eeE5") != std_multiset.end());
}

// тестируем метод возврата диапазона определенных элементов
TEST(TestOfMultiset, TestOfEqualRange1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  auto s21_iterator = s21_multiset.equal_range(4);
  auto std_iterator = std_multiset.equal_range(4);
  // здесь first - это итератор на первый элемент в множестве, равный заданному
  // значению, а second - итератор на элемент, следующий за последним элементом,
  // равном заданному значению
  while (s21_iterator.first != s21_iterator.second &&
         std_iterator.first != std_iterator.second) {
    EXPECT_EQ(*s21_iterator.first, *std_iterator.first);
    ++s21_iterator.first;
    ++std_iterator.first;
  }
}

TEST(TestOfMultiset, TestOfEqualRange2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};

  auto s21_iterator = s21_multiset.equal_range(2.2);
  auto std_iterator = std_multiset.equal_range(2.2);

  while (s21_iterator.first != s21_iterator.second &&
         std_iterator.first != std_iterator.second) {
    EXPECT_EQ(*s21_iterator.first, *std_iterator.first);
    ++s21_iterator.first;
    ++std_iterator.first;
  }
}

TEST(TestOfMultiset, TestOfEqualRange3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};

  auto s21_iterator = s21_multiset.equal_range('e');
  auto std_iterator = std_multiset.equal_range('e');

  while (s21_iterator.first != s21_iterator.second &&
         std_iterator.first != std_iterator.second) {
    EXPECT_EQ(*s21_iterator.first, *std_iterator.first);
    ++s21_iterator.first;
    ++std_iterator.first;
  }
}

TEST(TestOfMultiset, TestOfEqualRange4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};

  auto s21_iterator = s21_multiset.equal_range("Ccc3");
  auto std_iterator = std_multiset.equal_range("Ccc3");

  while (s21_iterator.first != s21_iterator.second &&
         std_iterator.first != std_iterator.second) {
    EXPECT_EQ(*s21_iterator.first, *std_iterator.first);
    ++s21_iterator.first;
    ++std_iterator.first;
  }
}

// тестируем метод возврата итератора на первый элемент, который не меньше
// заданного значения

TEST(TestOfMultiset, TestOfLowerBound1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  auto s21_iterator = s21_multiset.lower_bound(-1);
  auto std_iterator = std_multiset.lower_bound(-1);

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  } else {
    EXPECT_EQ(s21_iterator == s21_multiset.end(),
              std_iterator == std_multiset.end());
  }
}

TEST(TestOfMultiset, TestOfLowerBound2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};

  auto s21_iterator = s21_multiset.lower_bound(-1.1);
  auto std_iterator = std_multiset.lower_bound(-1.1);

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  } else {
    EXPECT_EQ(s21_iterator == s21_multiset.end(),
              std_iterator == std_multiset.end());
  }
}

TEST(TestOfMultiset, TestOfLowerBound3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};

  auto s21_iterator = s21_multiset.lower_bound('A');
  auto std_iterator = std_multiset.lower_bound('A');

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  } else {
    EXPECT_EQ(s21_iterator == s21_multiset.end(),
              std_iterator == std_multiset.end());
  }
}

TEST(TestOfMultiset, TestOfLowerBound4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};

  auto s21_iterator = s21_multiset.lower_bound("Aaa1");
  auto std_iterator = std_multiset.lower_bound("Aaa1");

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  } else {
    EXPECT_EQ(s21_iterator == s21_multiset.end(),
              std_iterator == std_multiset.end());
  }
}

// протестируем метод поиска итератора на первый элемент, которы строго больше
// указанного значения

TEST(TestOfMultiset, TestOfUpperBound1) {
  s21::multiset<int> s21_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  std::multiset<int> std_multiset{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

  auto s21_iterator = s21_multiset.upper_bound(3);
  auto std_iterator = std_multiset.upper_bound(3);

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  } else {
    EXPECT_EQ(s21_iterator == s21_multiset.end(),
              std_iterator == std_multiset.end());
  }
}

TEST(TestOfMultiset, TestOfUpperBound2) {
  s21::multiset<double> s21_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};
  std::multiset<double> std_multiset{1.1, 2.2, 3.3, 4.4, 5.5,
                                     1.1, 2.2, 3.3, 4.4, 5.5};

  auto s21_iterator = s21_multiset.upper_bound(2.2);
  auto std_iterator = std_multiset.upper_bound(2.2);

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  } else {
    EXPECT_EQ(s21_iterator == s21_multiset.end(),
              std_iterator == std_multiset.end());
  }
}

TEST(TestOfMultiset, TestOfUpperBound3) {
  s21::multiset<char> s21_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};
  std::multiset<char> std_multiset{'a', 'b', 'c', 'd', 'e',
                                   'a', 'b', 'c', 'd', 'e'};

  auto s21_iterator = s21_multiset.upper_bound('c');
  auto std_iterator = std_multiset.upper_bound('c');

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  } else {
    EXPECT_EQ(s21_iterator == s21_multiset.end(),
              std_iterator == std_multiset.end());
  }
}

TEST(TestOfMultiset, TestOfUpperBound4) {
  s21::multiset<std::string> s21_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};
  std::multiset<std::string> std_multiset{"aaA1", "bBb2", "Ccc3", "ddD4",
                                          "eeE5", "aaA1", "bBb2", "Ccc3",
                                          "ddD4", "eeE5"};

  auto s21_iterator = s21_multiset.upper_bound("eeE5");
  auto std_iterator = std_multiset.upper_bound("eeE5");

  if (s21_iterator != s21_multiset.end() &&
      std_iterator != std_multiset.end()) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  } else {
    EXPECT_EQ(s21_iterator == s21_multiset.end(),
              std_iterator == std_multiset.end());
  }
}

TEST(TestOfMultiset, TestOfInsertMany1) {
  s21::multiset<int> s21_multiset;
  s21::multiset<int> std_multiset;

  auto s21_multiset_test = s21_multiset.insert_many(1, 1, 2, 2, 3, 3);
  std_multiset.insert(1);
  std_multiset.insert(1);
  std_multiset.insert(2);
  std_multiset.insert(2);
  std_multiset.insert(3);
  std_multiset.insert(3);

  EXPECT_EQ(s21_multiset_test.size(), std_multiset.size());

  for (auto s21_iterator = s21_multiset.begin(),
            std_iterator = std_multiset.begin();
       s21_iterator != s21_multiset.end() && std_iterator != std_multiset.end();
       ++s21_iterator, ++std_iterator) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  }
}

TEST(TestOfMultiset, TestOfInsertMany2) {
  s21::multiset<double> s21_multiset;
  s21::multiset<double> std_multiset;

  auto s21_multiset_test =
      s21_multiset.insert_many(1.1, 1.1, 2.2, 2.2, 3.3, 3.3);
  std_multiset.insert(1.1);
  std_multiset.insert(1.1);
  std_multiset.insert(2.2);
  std_multiset.insert(2.2);
  std_multiset.insert(3.3);
  std_multiset.insert(3.3);

  EXPECT_EQ(s21_multiset_test.size(), std_multiset.size());

  for (auto s21_iterator = s21_multiset.begin(),
            std_iterator = std_multiset.begin();
       s21_iterator != s21_multiset.end() && std_iterator != std_multiset.end();
       ++s21_iterator, ++std_iterator) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  }
}

TEST(TestOfMultiset, TestOfInsertMany3) {
  s21::multiset<char> s21_multiset;
  s21::multiset<char> std_multiset;

  auto s21_multiset_test =
      s21_multiset.insert_many('a', 'a', 'b', 'b', 'c', 'c');
  std_multiset.insert('a');
  std_multiset.insert('a');
  std_multiset.insert('b');
  std_multiset.insert('b');
  std_multiset.insert('c');
  std_multiset.insert('c');

  EXPECT_EQ(s21_multiset_test.size(), std_multiset.size());

  for (auto s21_iterator = s21_multiset.begin(),
            std_iterator = std_multiset.begin();
       s21_iterator != s21_multiset.end() && std_iterator != std_multiset.end();
       ++s21_iterator, ++std_iterator) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  }
}

TEST(TestOfMultiset, TestOfInsertMany4) {
  s21::multiset<std::string> s21_multiset;
  s21::multiset<std::string> std_multiset;

  auto s21_multiset_test =
      s21_multiset.insert_many("Aaa1", "Aaa1", "bBb2", "bBb2", "ccC3", "ccC3");
  std_multiset.insert("Aaa1");
  std_multiset.insert("Aaa1");
  std_multiset.insert("bBb2");
  std_multiset.insert("bBb2");
  std_multiset.insert("ccC3");
  std_multiset.insert("ccC3");

  EXPECT_EQ(s21_multiset_test.size(), std_multiset.size());

  for (auto s21_iterator = s21_multiset.begin(),
            std_iterator = std_multiset.begin();
       s21_iterator != s21_multiset.end() && std_iterator != std_multiset.end();
       ++s21_iterator, ++std_iterator) {
    EXPECT_EQ(*s21_iterator, *std_iterator);
  }
}
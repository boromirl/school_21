#include "s21_tests_main.h"

// тестируем конструкторы
TEST(TestOfSet, TestOfDefaultConstructor1) {
  s21::set<int> s21_set;
  EXPECT_EQ(s21_set.size(), 0);
  EXPECT_TRUE(s21_set.empty());
}

TEST(TestOfSet, TestOfDefaultConstructor2) {
  s21::set<double> s21_set;
  EXPECT_EQ(s21_set.size(), 0);
  EXPECT_TRUE(s21_set.empty());
}

TEST(TestOfSet, TestOfDefaultConstructor3) {
  s21::set<char> s21_set;
  EXPECT_EQ(s21_set.size(), 0);
  EXPECT_TRUE(s21_set.empty());
}

TEST(TestOfSet, TestOfDefaultConstructor4) {
  s21::set<std::string> s21_set;
  EXPECT_EQ(s21_set.size(), 0);
  EXPECT_TRUE(s21_set.empty());
}

TEST(TestOfSet, TestOfConstructorWithInitializerList1) {
  s21::set<int> s21_set{1, 2, 3, 4, 5};
  EXPECT_EQ(s21_set.size(), 5);
  EXPECT_TRUE(s21_set.contains(1));
  EXPECT_TRUE(s21_set.contains(5));
  EXPECT_FALSE(s21_set.contains(6));
}

TEST(TestOfSet, TestOfConstructorWithInitializerList2) {
  s21::set<double> s21_set{1.1, 2.2, 3.3, 4.4, 5.5};
  EXPECT_EQ(s21_set.size(), 5);
  EXPECT_TRUE(s21_set.contains(1.1));
  EXPECT_TRUE(s21_set.contains(5.5));
  EXPECT_FALSE(s21_set.contains(6.6));
}

TEST(TestOfSet, TestOfConstructorWithInitializerList3) {
  s21::set<char> s21_set{'a', 'b', 'c', 'd', 'e'};
  EXPECT_EQ(s21_set.size(), 5);
  EXPECT_TRUE(s21_set.contains('a'));
  EXPECT_TRUE(s21_set.contains('e'));
  EXPECT_FALSE(s21_set.contains('f'));
}

TEST(TestOfSet, TestOfConstructorWithInitializerList4) {
  s21::set<std::string> s21_set{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};
  EXPECT_EQ(s21_set.size(), 5);
  EXPECT_TRUE(s21_set.contains("aaA1"));
  EXPECT_TRUE(s21_set.contains("eeE5"));
  EXPECT_FALSE(s21_set.contains("fFf6"));
}

TEST(TestOfSet, TestOfCopyConstructor1) {
  s21::set<int> s21_set{1, 2, 3, 4, 5};
  s21::set<int> s21_set_1(s21_set);
  EXPECT_EQ(s21_set.size(), s21_set_1.size());
  EXPECT_TRUE(s21_set_1.contains(1));
  EXPECT_TRUE(s21_set_1.contains(5));
}

TEST(TestOfSet, TestOfCopyConstructor2) {
  s21::set<double> s21_set{1.1, 2.2, 3.3, 4.4, 5.5};
  s21::set<double> s21_set_1(s21_set);
  EXPECT_EQ(s21_set.size(), s21_set_1.size());
  EXPECT_TRUE(s21_set_1.contains(1.1));
  EXPECT_TRUE(s21_set_1.contains(5.5));
}

TEST(TestOfSet, TestOfCopyConstructor3) {
  s21::set<char> s21_set{'a', 'b', 'c', 'd', 'e'};
  s21::set<char> s21_set_1(s21_set);
  EXPECT_EQ(s21_set.size(), s21_set_1.size());
  EXPECT_TRUE(s21_set_1.contains('a'));
  EXPECT_TRUE(s21_set_1.contains('e'));
}

TEST(TestOfSet, TestOfCopyConstructor4) {
  s21::set<std::string> s21_set{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};
  s21::set<std::string> s21_set_1(s21_set);
  EXPECT_EQ(s21_set.size(), s21_set_1.size());
  EXPECT_TRUE(s21_set_1.contains("aaA1"));
  EXPECT_TRUE(s21_set_1.contains("eeE5"));
}

// тесты конструктора перемещения и перегруженного оператора присваивания
// приводят к segmentation fault, пока закомментированы

TEST(TestOfSet, TestOfMoveConstructor1) {
  s21::set<int> s21_set{1, 2, 3, 4, 5};
  s21::set<int> s21_set_1(std::move(s21_set));
  EXPECT_EQ(s21_set_1.size(), 5);
  EXPECT_TRUE(s21_set_1.contains(1));
  EXPECT_TRUE(s21_set_1.contains(5));
  EXPECT_TRUE(s21_set.empty());
}

TEST(TestOfSet, TestOfMoveConstructor2) {
  s21::set<double> s21_set{1.1, 2.2, 3.3, 4.4, 5.5};
  s21::set<double> s21_set_1(std::move(s21_set));
  EXPECT_EQ(s21_set_1.size(), 5);
  EXPECT_TRUE(s21_set_1.contains(1.1));
  EXPECT_TRUE(s21_set_1.contains(5.5));
  EXPECT_TRUE(s21_set.empty());
}

TEST(TestOfSet, TestOfMoveConstructor3) {
  s21::set<char> s21_set{'a', 'b', 'c', 'd', 'e'};
  s21::set<char> s21_set_1(std::move(s21_set));
  EXPECT_EQ(s21_set_1.size(), 5);
  EXPECT_TRUE(s21_set_1.contains('a'));
  EXPECT_TRUE(s21_set_1.contains('e'));
  EXPECT_TRUE(s21_set.empty());
}

TEST(TestOfSet, TestOfMoveConstructor4) {
  s21::set<std::string> s21_set{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};
  s21::set<std::string> s21_set_1(std::move(s21_set));
  EXPECT_EQ(s21_set_1.size(), 5);
  EXPECT_TRUE(s21_set_1.contains("aaA1"));
  EXPECT_TRUE(s21_set_1.contains("eeE5"));
  EXPECT_TRUE(s21_set.empty());
}

TEST(TestOfSet, TestOfAssignmentOperator1) {
  s21::set<int> s21_set{1, 2, 3, 4, 5};
  s21::set<int> s21_set_1;
  s21_set_1 = std::move(s21_set);
  EXPECT_EQ(s21_set_1.size(), 5);
  EXPECT_TRUE(s21_set_1.contains(3));
  EXPECT_TRUE(s21_set.empty());
}

TEST(TestOfSet, TestOfAssignmentOperator2) {
  s21::set<double> s21_set{1.1, 2.2, 3.3, 4.4, 5.5};
  s21::set<double> s21_set_1;
  s21_set_1 = std::move(s21_set);
  EXPECT_EQ(s21_set_1.size(), 5);
  EXPECT_TRUE(s21_set_1.contains(3.3));
  EXPECT_TRUE(s21_set.empty());
}

TEST(TestOfSet, TestOfAssignmentOperator3) {
  s21::set<char> s21_set{'a', 'b', 'c', 'd', 'e'};
  s21::set<char> s21_set_1;
  s21_set_1 = std::move(s21_set);
  EXPECT_EQ(s21_set_1.size(), 5);
  EXPECT_TRUE(s21_set_1.contains('c'));
  EXPECT_TRUE(s21_set.empty());
}

TEST(TestOfSet, TestOfAssignmentOperator4) {
  s21::set<std::string> s21_set{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};
  s21::set<std::string> s21_set_1;
  s21_set_1 = std::move(s21_set);
  EXPECT_EQ(s21_set_1.size(), 5);
  EXPECT_TRUE(s21_set_1.contains("Ccc3"));
  EXPECT_TRUE(s21_set.empty());
}

// Тестируем итератор на начало и конец контейнера
TEST(TestOfSet, TestOfIteratorOfBeginAndEnd1) {
  s21::set<int> s21_set{1, 2, 3, 4, 5};
  std::vector<int> s21_vector{1, 2, 3, 4, 5};
  size_t i = 0;

  for (auto iterator = s21_set.begin(); iterator != s21_set.end();
       ++iterator, ++i) {
    EXPECT_EQ(*iterator,
              s21_vector[i]);  // проверяем равенство элементов множества и
                               // вектора, двигаясь по ним одновременно
  }
  EXPECT_EQ(i, s21_vector.size());  // проверяем, что прошли все элементы
                                    // вектора для тестирования
}

TEST(TestOfSet, TestOfIteratorOfBeginAndEnd2) {
  s21::set<double> s21_set{1.1, 2.2, 3.3, 4.4, 5.5};
  std::vector<double> s21_vector{1.1, 2.2, 3.3, 4.4, 5.5};
  size_t i = 0;

  for (auto iterator = s21_set.begin(); iterator != s21_set.end();
       ++iterator, ++i) {
    EXPECT_EQ(*iterator,
              s21_vector[i]);  // проверяем равенство элементов множества и
                               // вектора, двигаясь по ним одновременно
  }
  EXPECT_EQ(i, s21_vector.size());  // проверяем, что прошли все элементы
                                    // вектора для тестирования
}

TEST(TestOfSet, TestOfIteratorOfBeginAndEnd3) {
  s21::set<char> s21_set{'a', 'b', 'c', 'd', 'e'};
  std::vector<char> s21_vector{'a', 'b', 'c', 'd', 'e'};
  size_t i = 0;

  for (auto iterator = s21_set.begin(); iterator != s21_set.end();
       ++iterator, ++i) {
    EXPECT_EQ(*iterator,
              s21_vector[i]);  // проверяем равенство элементов множества и
                               // вектора, двигаясь по ним одновременно
  }
  EXPECT_EQ(i, s21_vector.size());  // проверяем, что прошли все элементы
                                    // вектора для тестирования
}

TEST(TestOfSet, TestOfIteratorOfBeginAndEnd4) {
  s21::set<std::string> s21_set{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};
  std::vector<std::string> s21_vector{
      "Ccc3", "aaA1", "bBb2", "ddD4",
      "eeE5"};  // именно таким образом, так как в сете элементы при компиляции
                // будут отсортированы автоматически (в данном случае
                // лексикографически - с учетом регистра)
  size_t i = 0;

  for (auto iterator = s21_set.begin(); iterator != s21_set.end();
       ++iterator, ++i) {
    EXPECT_EQ(*iterator,
              s21_vector[i]);  // проверяем равенство элементов множества и
                               // вектора, двигаясь по ним одновременно
  }
  EXPECT_EQ(i, s21_vector.size());  // проверяем, что прошли все элементы
                                    // вектора для тестирования
}

// Тестируем константные методы доступа к началу и концу контейнера

TEST(TestOfSet, TestOfConstBeginAndEndEmptySet1) {
  s21::set<int> const s21_set_empty;
  // для пустого множества cbegin и cend должны вернуть одинаковый итератор
  auto iterator_begin = s21_set_empty.cbegin();
  auto iterator_end = s21_set_empty.cend();

  EXPECT_EQ(iterator_begin, iterator_end);
}

TEST(TestOfSet, TestOfConstBeginAndEndEmptySet2) {
  s21::set<double> const s21_set_empty;

  auto iterator_begin = s21_set_empty.cbegin();
  auto iterator_end = s21_set_empty.cend();

  EXPECT_EQ(iterator_begin, iterator_end);
}

TEST(TestOfSet, TestOfConstBeginAndEndEmptySet3) {
  s21::set<char> const s21_set_empty;

  auto iterator_begin = s21_set_empty.cbegin();
  auto iterator_end = s21_set_empty.cend();

  EXPECT_EQ(iterator_begin, iterator_end);
}

TEST(TestOfSet, TestOfConstBeginAndEndEmptySet4) {
  s21::set<std::string> const s21_set_empty;

  auto iterator_begin = s21_set_empty.cbegin();
  auto iterator_end = s21_set_empty.cend();

  EXPECT_EQ(iterator_begin, iterator_end);
}

template <typename T>
void test_of_const_begin_and_end_non_empty_set(
    const s21::set<T> &s21_set,
    const std::vector<T>
        &expected_values) {  // передаем сет и списко элементов auto
  auto iterator_begin = s21_set.cbegin();
  EXPECT_EQ(*iterator_begin,
            expected_values.front());  // Проверяем первый элемент

  // Перебор всех элементов и их сравнение с ожидаемыми значениями
  auto expected_it = expected_values.begin();
  for (auto iterator = s21_set.cbegin(); iterator != s21_set.cend();
       ++iterator, ++expected_it) {
    EXPECT_EQ(*iterator, *expected_it);
  }

  // Проверяем, что cend() корректно завершается (разыменование не проверяем)
  auto iterator_end = s21_set.cend();
  EXPECT_NO_THROW(iterator_end == iterator_end);
}

// Тесты
TEST(TesOfSet, TestOfConstBeginAndEndNonEmptySet1) {
  s21::set<int> s21_set{1, 2, 3, 4, 5};
  test_of_const_begin_and_end_non_empty_set(s21_set, {1, 2, 3, 4, 5});
}

TEST(TesOfSet, TestOfConstBeginAndEndNonEmptySet2) {
  s21::set<double> s21_set{1.1, 2.2, 3.3, 4.4, 5.5};
  test_of_const_begin_and_end_non_empty_set(s21_set, {1.1, 2.2, 3.3, 4.4, 5.5});
}

TEST(TesOfSet, TestOfConstBeginAndEndNonEmptySet3) {
  s21::set<char> s21_set{'a', 'b', 'c', 'd', 'e'};
  test_of_const_begin_and_end_non_empty_set(s21_set, {'a', 'b', 'c', 'd', 'e'});
}

TEST(TesOfSet, TestOfConstBeginAndEndNonEmptySet4) {
  s21::set<std::string> s21_set{"aaA1", "bBb2", "ccc3", "ddD4", "eeE5"};
  test_of_const_begin_and_end_non_empty_set(
      s21_set, {"aaA1", "bBb2", "ccc3", "ddD4", "eeE5"});
}

// тестируем что cbegin и cend не меняют состояние контейнера

TEST(TestOfSet, TestOfConstBeginAndEndNotModifySet1) {
  s21::set<int> const s21_set{1, 2, 3, 4, 5};

  auto iterator_begin = s21_set.cbegin();
  auto iterator_end = s21_set.cend();

  EXPECT_EQ(s21_set.size(), 5);
  EXPECT_EQ(*iterator_begin, 1);
  EXPECT_EQ(*(--iterator_end), 5);
}

TEST(TestOfSet, TestOfConstBeginAndEndNotModifySet2) {
  s21::set<double> const s21_set{1.1, 2.2, 3.3, 4.4, 5.5};

  auto iterator_begin = s21_set.cbegin();
  auto iterator_end = s21_set.cend();

  EXPECT_EQ(s21_set.size(), 5);
  EXPECT_EQ(*iterator_begin, 1.1);
  EXPECT_EQ(*(--iterator_end), 5.5);
}

TEST(TestOfSet, TestOfConstBeginAndEndNotModifySet3) {
  s21::set<char> const s21_set{'a', 'b', 'c', 'd', 'e'};

  auto iterator_begin = s21_set.cbegin();
  auto iterator_end = s21_set.cend();

  EXPECT_EQ(s21_set.size(), 5);
  EXPECT_EQ(*iterator_begin, 'a');
  EXPECT_EQ(*(--iterator_end), 'e');
}

TEST(TestOfSet, TestOfConstBeginAndEndNotModifySet4) {
  s21::set<std::string> const s21_set{"aaA1", "bBb2", "ccc3", "ddD4", "eeE5"};

  auto iterator_begin = s21_set.cbegin();
  auto iterator_end = s21_set.cend();

  EXPECT_EQ(s21_set.size(), 5);
  EXPECT_EQ(*iterator_begin, "aaA1");
  EXPECT_EQ(*(--iterator_end), "eeE5");
}

// Тестируем многократные вызовы cbegin и cend, что они возвращают корректные
// итераторы

TEST(TestOfSet, TestOfConstBeginAndEndMultipleCalls1) {
  s21::set<int> const s21_set{1, 2, 3, 4, 5};

  auto iterator_begin_1 = s21_set.cbegin();
  auto iterator_end_1 = s21_set.cend();
  auto iterator_begin_2 = s21_set.cbegin();
  auto iterator_end_2 = s21_set.cend();

  EXPECT_NE(iterator_begin_1, iterator_end_1);
  EXPECT_EQ(iterator_end_1, iterator_end_2);
  EXPECT_EQ(iterator_begin_1, iterator_begin_2);
}

TEST(TestOfSet, TestOfConstBeginAndEndMultipleCalls2) {
  s21::set<double> const s21_set{1.1, 2.2, 3.3, 4.4, 5.5};

  auto iterator_begin_1 = s21_set.cbegin();
  auto iterator_end_1 = s21_set.cend();
  auto iterator_begin_2 = s21_set.cbegin();
  auto iterator_end_2 = s21_set.cend();

  EXPECT_NE(iterator_begin_1, iterator_end_1);
  EXPECT_EQ(iterator_end_1, iterator_end_2);
  EXPECT_EQ(iterator_begin_1, iterator_begin_2);
}

TEST(TestOfSet, TestOfConstBeginAndEndMultipleCalls3) {
  s21::set<char> const s21_set{'a', 'b', 'c', 'd', 'e'};

  auto iterator_begin_1 = s21_set.cbegin();
  auto iterator_end_1 = s21_set.cend();
  auto iterator_begin_2 = s21_set.cbegin();
  auto iterator_end_2 = s21_set.cend();

  EXPECT_NE(iterator_begin_1, iterator_end_1);
  EXPECT_EQ(iterator_end_1, iterator_end_2);
  EXPECT_EQ(iterator_begin_1, iterator_begin_2);
}

TEST(TestOfSet, TestOfConstBeginAndEndMultipleCalls4) {
  s21::set<std::string> const s21_set{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};

  auto iterator_begin_1 = s21_set.cbegin();
  auto iterator_end_1 = s21_set.cend();
  auto iterator_begin_2 = s21_set.cbegin();
  auto iterator_end_2 = s21_set.cend();

  EXPECT_NE(iterator_begin_1, iterator_end_1);
  EXPECT_EQ(iterator_end_1, iterator_end_2);
  EXPECT_EQ(iterator_begin_1, iterator_begin_2);
}

// Тестируем метод очистки содержимого контейнера
TEST(TestOfSet, TestOfClear1) {
  s21::set<int> s21_set{1, 2, 3, 4, 5};
  s21_set.clear();
  EXPECT_TRUE(s21_set.empty());
  EXPECT_EQ(s21_set.size(), 0);
}

TEST(TestOfSet, TestOfClear2) {
  s21::set<double> s21_set{1.1, 2.2, 3.3, 4.4, 5.5};
  s21_set.clear();
  EXPECT_TRUE(s21_set.empty());
  EXPECT_EQ(s21_set.size(), 0);
}

TEST(TestOfSet, TestOfClear3) {
  s21::set<char> s21_set{'a', 'b', 'c', 'd', 'e'};
  s21_set.clear();
  EXPECT_TRUE(s21_set.empty());
  EXPECT_EQ(s21_set.size(), 0);
}

TEST(TestOfSet, TestOfClear4) {
  s21::set<std::string> s21_set{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};
  s21_set.clear();
  EXPECT_TRUE(s21_set.empty());
  EXPECT_EQ(s21_set.size(), 0);
}

/*тестируем вставку и проверку наличия элемента в контейнере*/
TEST(TestOfSet, TestOfInsertAndContains1) {
  s21::set<int> s21_set;
  auto result = s21_set.insert(1);
  EXPECT_TRUE(
      result.second);  // insert состоит из итератора на элемент, кторый будет
                       // вставлен или уже есть во множестве - это first, а
                       // second - логическое выражение была ли вставка успешной
                       // или нет. true - успешно, false - нет
  EXPECT_TRUE(s21_set.contains(1));
  EXPECT_EQ(s21_set.size(), 1);

  result = s21_set.insert(1);
  EXPECT_FALSE(result.second);  // повторный элемент не добавляется
  EXPECT_EQ(s21_set.size(), 1);
}

TEST(TestOfSet, TestOfInsertAndContains2) {
  s21::set<double> s21_set;
  auto result = s21_set.insert(1.1);
  EXPECT_TRUE(result.second);
  EXPECT_TRUE(s21_set.contains(1.1));
  EXPECT_EQ(s21_set.size(), 1);

  result = s21_set.insert(1.1);
  EXPECT_FALSE(result.second);
  EXPECT_EQ(s21_set.size(), 1);
}

TEST(TestOfSet, TestOfInsertAndContains3) {
  s21::set<char> s21_set;
  auto result = s21_set.insert('a');
  EXPECT_TRUE(result.second);
  EXPECT_TRUE(s21_set.contains('a'));
  EXPECT_EQ(s21_set.size(), 1);

  result = s21_set.insert('a');
  EXPECT_FALSE(result.second);
  EXPECT_EQ(s21_set.size(), 1);
}

TEST(TestOfSet, TestOfInsertAndContains4) {
  s21::set<std::string> s21_set;
  auto result = s21_set.insert("Aaa1");
  EXPECT_TRUE(result.second);
  EXPECT_TRUE(s21_set.contains("Aaa1"));
  EXPECT_EQ(s21_set.size(), 1);

  result = s21_set.insert("Aaa1");
  EXPECT_FALSE(result.second);
  EXPECT_EQ(s21_set.size(), 1);
}

// тестируем удаление элемента из множества

TEST(TestOfSet, TestOfErase1) {
  s21::set<int> s21_set{1, 2, 3, 4, 5};
  auto iterator_element =
      s21_set.find(2);  // проверим, что нужный нам элемент есть
  s21_set.erase(iterator_element);  // теперь удаляем элемент и проверям, что
                                    // его нет, а размер контейнера изменился
  EXPECT_FALSE(s21_set.contains(2));
  EXPECT_EQ(s21_set.size(), 4);
}

TEST(TestOfSet, TestOfErase2) {
  s21::set<double> s21_set{1.1, 2.2, 3.3, 4.4, 5.5};
  auto iterator_element = s21_set.find(2.2);
  s21_set.erase(iterator_element);
  EXPECT_FALSE(s21_set.contains(2.2));
  EXPECT_EQ(s21_set.size(), 4);
}

TEST(TestOfSet, TestOfErase3) {
  s21::set<char> s21_set{'a', 'b', 'c', 'd', 'e'};
  auto iterator_element = s21_set.find('b');
  s21_set.erase(iterator_element);
  EXPECT_FALSE(s21_set.contains('b'));
  EXPECT_EQ(s21_set.size(), 4);
}

TEST(TestOfSet, TestOfErase4) {
  s21::set<std::string> s21_set{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};
  auto iterator_element = s21_set.find("bBb2");
  s21_set.erase(iterator_element);
  EXPECT_FALSE(s21_set.contains("bBb2"));
  EXPECT_EQ(s21_set.size(), 4);
}

// тестируем обмен содержимого контейнеров
TEST(TestOfSet, TestOfSwap1) {
  s21::set<int> s21_set{1, 2, 3};
  s21::set<int> s21_set_1{4, 5};
  s21_set.swap(s21_set_1);

  EXPECT_EQ(s21_set.size(), 2);
  EXPECT_EQ(s21_set_1.size(), 3);
  EXPECT_TRUE(s21_set.contains(4));
  EXPECT_TRUE(s21_set_1.contains(2));
}

TEST(TestOfSet, TestOfSwap2) {
  s21::set<double> s21_set{1.1, 2.2, 3.3};
  s21::set<double> s21_set_1{4.4, 5.5};
  s21_set.swap(s21_set_1);

  EXPECT_EQ(s21_set.size(), 2);
  EXPECT_EQ(s21_set_1.size(), 3);
  EXPECT_TRUE(s21_set.contains(4.4));
  EXPECT_TRUE(s21_set_1.contains(2.2));
}

TEST(TestOfSet, TestOfSwap3) {
  s21::set<char> s21_set{'a', 'b', 'c'};
  s21::set<char> s21_set_1{'d', 'e'};
  s21_set.swap(s21_set_1);

  EXPECT_EQ(s21_set.size(), 2);
  EXPECT_EQ(s21_set_1.size(), 3);
  EXPECT_TRUE(s21_set.contains('d'));
  EXPECT_TRUE(s21_set_1.contains('b'));
}

TEST(TestOfSet, TestOfSwap4) {
  s21::set<std::string> s21_set{"aaA1", "bBb2", "Ccc3"};
  s21::set<std::string> s21_set_1{"ddD4", "eeE5"};
  s21_set.swap(s21_set_1);

  EXPECT_EQ(s21_set.size(), 2);
  EXPECT_EQ(s21_set_1.size(), 3);
  EXPECT_TRUE(s21_set.contains("ddD4"));
  EXPECT_TRUE(s21_set_1.contains("bBb2"));
}

// тестируем сливание одной ветки с другой (вторая должна остаться пустой после
// этого или останутся те ноды, которые уже есть в первой, т.к. мерджит только
// неповторяющиеся)
TEST(TestOfSet, TestOfMerge1) {
  s21::set<int> s21_set{1, 2, 3};
  s21::set<int> s21_set_1{4, 5};
  s21_set.merge(s21_set_1);

  EXPECT_EQ(s21_set.size(), 5);
  EXPECT_TRUE(s21_set.contains(1));
  EXPECT_TRUE(s21_set.contains(5));
  EXPECT_EQ(s21_set_1.size(), 0);
}

TEST(TestOfSet, TestOfMerge2) {
  s21::set<double> s21_set{1.1, 2.2, 3.3};
  s21::set<double> s21_set_1{4.4, 5.5};
  s21_set.merge(s21_set_1);

  EXPECT_EQ(s21_set.size(), 5);
  EXPECT_TRUE(s21_set.contains(1.1));
  EXPECT_TRUE(s21_set.contains(5.5));
  EXPECT_EQ(s21_set_1.size(), 0);
}

TEST(TestOfSet, TestOfMerge3) {
  s21::set<char> s21_set{'a', 'b', 'c'};
  s21::set<char> s21_set_1{'d', 'e'};
  s21_set.merge(s21_set_1);

  EXPECT_EQ(s21_set.size(), 5);
  EXPECT_TRUE(s21_set.contains('a'));
  EXPECT_TRUE(s21_set.contains('e'));
  EXPECT_EQ(s21_set_1.size(), 0);
}

TEST(TestOfSet, TestOfMerge4) {
  s21::set<std::string> s21_set{"aaA1", "bBb2", "Ccc3"};
  s21::set<std::string> s21_set_1{"ddD4", "eeE5"};
  s21_set.merge(s21_set_1);

  EXPECT_EQ(s21_set.size(), 5);
  EXPECT_TRUE(s21_set.contains("aaA1"));
  EXPECT_TRUE(s21_set.contains("eeE5"));
  EXPECT_EQ(s21_set_1.size(), 0);
}

// тестируем метод поиска элемента
TEST(TestOfSet, TestOfFind1) {
  s21::set<int> s21_set{1, 2, 3, 4, 5};
  auto iterator = s21_set.find(3);
  EXPECT_NE(iterator,
            s21_set.end());  // expect non equal - т.е. итератор нашел нужный
                             // элемент и указывает на него, в противном случае
                             // ничего не было бы найдено и итератор стал бы
                             // указазывать на "конец" множества
  EXPECT_EQ(*iterator, 3);

  iterator = s21_set.find(14);
  EXPECT_EQ(iterator, s21_set.end());  // теперь метод ничего не нашел, итератор
                                       // указывает на "конец" множества
}

TEST(TestOfSet, TestOfFind2) {
  s21::set<double> s21_set{1.1, 2.2, 3.3, 4.4, 5.5};
  auto iterator = s21_set.find(3.3);
  EXPECT_NE(iterator, s21_set.end());
  EXPECT_EQ(*iterator, 3.3);

  iterator = s21_set.find(7.8);
  EXPECT_EQ(iterator, s21_set.end());
}

TEST(TestOfSet, TestOfFind3) {
  s21::set<char> s21_set{'a', 'b', 'c', 'd', 'e'};
  auto iterator = s21_set.find('c');
  EXPECT_NE(iterator, s21_set.end());
  EXPECT_EQ(*iterator, 'c');

  iterator = s21_set.find('y');
  EXPECT_EQ(iterator, s21_set.end());
}

TEST(TestOfSet, TestOfFind4) {
  s21::set<std::string> s21_set{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};
  auto iterator = s21_set.find("Ccc3");
  EXPECT_NE(iterator, s21_set.end());
  EXPECT_EQ(*iterator, "Ccc3");

  iterator = s21_set.find("xxX24");
  EXPECT_EQ(iterator, s21_set.end());
}
// тестируем вставку множества элементов
TEST(TestOfSet, TestOfInsertMany1) {
  s21::set<int> s21_set;
  auto results = s21_set.insert_many(1, 2, 3, 3, 4, 5);
  EXPECT_EQ(results.size(), 6);
  EXPECT_TRUE(results[0].second);
  EXPECT_TRUE(results[1].second);
  EXPECT_FALSE(results[3].second);  // повтроная вставка элемента не произошла
  EXPECT_EQ(s21_set.size(), 5);
}

TEST(TestOfSet, TestOfInsertMany2) {
  s21::set<double> s21_set;
  auto results = s21_set.insert_many(1.1, 2.2, 3.3, 3.3, 4.4, 5.5);
  EXPECT_EQ(results.size(), 6);
  EXPECT_TRUE(results[0].second);
  EXPECT_TRUE(results[1].second);
  EXPECT_FALSE(results[3].second);
  EXPECT_EQ(s21_set.size(), 5);
}

TEST(TestOfSet, TestOfInsertMany3) {
  s21::set<char> s21_set;
  auto results = s21_set.insert_many('a', 'b', 'c', 'c', 'd', 'e');
  EXPECT_EQ(results.size(), 6);
  EXPECT_TRUE(results[0].second);
  EXPECT_TRUE(results[1].second);
  EXPECT_FALSE(results[3].second);
  EXPECT_EQ(s21_set.size(), 5);
}

TEST(TestOfSet, TestOfInsertMany4) {
  s21::set<std::string> s21_set;
  auto results =
      s21_set.insert_many("aaA1", "bBb2", "Ccc3", "Ccc3", "ddD4", "eeE5");
  EXPECT_EQ(results.size(), 6);
  EXPECT_TRUE(results[0].second);
  EXPECT_TRUE(results[1].second);
  EXPECT_FALSE(results[3].second);
  EXPECT_EQ(s21_set.size(), 5);
}

// specific cases of deleteFix
TEST(TestOfSet, DeleteSpecific) {
  s21::set<int> s1({100, 50, 150, 30, 70, 75});

  s1.erase(s1.find(150));
  ASSERT_FALSE(s1.contains(150));

  s21::set<int> s2({100, 50, 150, 200, 130, 250});

  s2.erase(s2.find(50));
  ASSERT_FALSE(s2.contains(50));

  s21::set<int> s3({100, 50, 150, 70, 90, 10, 40, 60, 65, 55});

  s3.erase(s3.find(40));
  ASSERT_FALSE(s3.contains(40));

  s3.insert(130);
  s3.erase(s3.find(90));
  ASSERT_FALSE(s3.contains(90));
}
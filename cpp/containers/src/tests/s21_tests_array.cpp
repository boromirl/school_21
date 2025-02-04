#include "s21_tests_main.h"

TEST(TestOfArray, TestOfInitializationList) {
  s21::array<int, 10> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(v.front(), 1);
  EXPECT_EQ(v.back(), 10);
  EXPECT_EQ(*v.begin(), 1);
  EXPECT_EQ(*(v.end() - 1), 10);
  EXPECT_EQ(v.size(), 10);

  std::array<int, 10> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(v.front(), vec.front());
  EXPECT_EQ(v.back(), vec.back());
  EXPECT_EQ(*v.begin(),
            *vec.begin());  // здесь тестируем итераторы, разыменовываем и
                            // получаем значение элемента статического массива
  EXPECT_EQ(*(v.end() - 1), *(vec.end() - 1));
  EXPECT_EQ(v.size(), vec.size());
}

TEST(TestOfArray, TestOfInitializationList1) {
  s21::array<double, 10> v{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  EXPECT_EQ(v.front(), 1.1);
  EXPECT_EQ(v.back(), 10.1);
  EXPECT_EQ(*v.begin(), 1.1);
  EXPECT_EQ(*(v.end() - 1), 10.1);
  EXPECT_EQ(v.size(), 10);

  std::array<double, 10> vec{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  EXPECT_EQ(v.front(), vec.front());
  EXPECT_EQ(v.back(), vec.back());
  EXPECT_EQ(*v.begin(), *vec.begin());
  EXPECT_EQ(*(v.end() - 1), *(vec.end() - 1));
  EXPECT_EQ(v.size(), vec.size());
}

TEST(TestOfArray, TestOfInitializationList2) {
  s21::array<char, 10> v{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  EXPECT_EQ(v.front(), 'a');
  EXPECT_EQ(v.back(), 'k');
  EXPECT_EQ(*v.begin(), 'a');
  EXPECT_EQ(*(v.end() - 1), 'k');
  EXPECT_EQ(v.size(), 10);

  std::array<char, 10> vec{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  EXPECT_EQ(v.front(), vec.front());
  EXPECT_EQ(v.back(), vec.back());
  EXPECT_EQ(*v.begin(), *vec.begin());
  EXPECT_EQ(*(v.end() - 1), *(vec.end() - 1));
  EXPECT_EQ(v.size(), vec.size());
}

TEST(TestOfArray, TestOfCopyConstructor) {
  s21::array<int, 10> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::array<int, 10> v1(v);
  EXPECT_EQ(v1.front(), 1);
  EXPECT_EQ(v1.back(), 10);
  EXPECT_EQ(*v1.begin(), 1);
  EXPECT_EQ(*(v1.end() - 1), 10);
  EXPECT_EQ(v1.size(), 10);

  std::array<int, 10> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::array<int, 10> vec1(vec);
  EXPECT_EQ(v1.front(), vec1.front());
  EXPECT_EQ(v1.back(), vec1.back());
  EXPECT_EQ(*v1.begin(), *vec1.begin());
  EXPECT_EQ(*(v1.end() - 1), *(vec1.end() - 1));
  EXPECT_EQ(v1.size(), vec1.size());
}

TEST(TestOfArray, TestOfCopyConstructor1) {
  s21::array<double, 10> v{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  s21::array<double, 10> v1(v);
  EXPECT_EQ(v1.front(), 1.1);
  EXPECT_EQ(v1.back(), 10.1);
  EXPECT_EQ(*v1.begin(), 1.1);
  EXPECT_EQ(*(v1.end() - 1), 10.1);
  EXPECT_EQ(v1.size(), 10);

  std::array<double, 10> vec{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  std::array<double, 10> vec1(vec);
  EXPECT_EQ(v1.front(), vec1.front());
  EXPECT_EQ(v1.back(), vec1.back());
  EXPECT_EQ(*v1.begin(), *vec1.begin());
  EXPECT_EQ(*(v1.end() - 1), *(vec1.end() - 1));
  EXPECT_EQ(v1.size(), vec1.size());
}

TEST(TestOfArray, TestOfCopyConstructor2) {
  s21::array<char, 10> v{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  s21::array<char, 10> v1(v);
  EXPECT_EQ(v1.front(), 'a');
  EXPECT_EQ(v1.back(), 'k');
  EXPECT_EQ(*v1.begin(), 'a');
  EXPECT_EQ(*(v1.end() - 1), 'k');
  EXPECT_EQ(v1.size(), 10);

  std::array<char, 10> vec{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  std::array<char, 10> vec1(vec);
  EXPECT_EQ(v1.front(), vec1.front());
  EXPECT_EQ(v1.back(), vec1.back());
  EXPECT_EQ(*v1.begin(), *vec1.begin());
  EXPECT_EQ(*(v1.end() - 1), *(vec1.end() - 1));
  EXPECT_EQ(v1.size(), vec1.size());
}

TEST(TestOfArray, TestOfMovingConstructor) {
  s21::array<int, 10> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::array<int, 10> v1(std::move(
      v));  // это инициализация объекта v1 с использованием перемещенных
            // ресурсов v, без лишнего копирования - это инициализация
            // перемещением! Т.е. объект v1 создается сразу инициализированным
            // данными v, полученными путем перемещения
  EXPECT_EQ(v1.front(), 1);
  EXPECT_EQ(v1.back(), 10);
  EXPECT_EQ(*v1.begin(), 1);
  EXPECT_EQ(*(v1.end() - 1), 10);
  EXPECT_EQ(v1.size(), 10);

  std::array<int, 10> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::array<int, 10> vec1(std::move(vec));
  EXPECT_EQ(v1.front(), vec1.front());
  EXPECT_EQ(v1.back(), vec1.back());
  EXPECT_EQ(*v1.begin(), *vec1.begin());
  EXPECT_EQ(*(v1.end() - 1), *(vec1.end() - 1));
  EXPECT_EQ(v1.size(), vec1.size());
}

TEST(TestOfArray, TestOfMovingConstructor1) {
  s21::array<double, 10> v{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  s21::array<double, 10> v1(std::move(v));
  EXPECT_EQ(v1.front(), 1.1);
  EXPECT_EQ(v1.back(), 10.1);
  EXPECT_EQ(*v1.begin(), 1.1);
  EXPECT_EQ(*(v1.end() - 1), 10.1);
  EXPECT_EQ(v1.size(), 10);

  std::array<double, 10> vec{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  std::array<double, 10> vec1(std::move(vec));
  EXPECT_EQ(v1.front(), vec1.front());
  EXPECT_EQ(v1.back(), vec1.back());
  EXPECT_EQ(*v1.begin(), *vec1.begin());
  EXPECT_EQ(*(v1.end() - 1), *(vec1.end() - 1));
  EXPECT_EQ(v1.size(), vec1.size());
}

TEST(TestOfArray, TestOfMovingConstructor2) {
  s21::array<char, 10> v{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  s21::array<char, 10> v1(std::move(v));
  EXPECT_EQ(v1.front(), 'a');
  EXPECT_EQ(v1.back(), 'k');
  EXPECT_EQ(*v1.begin(), 'a');
  EXPECT_EQ(*(v1.end() - 1), 'k');
  EXPECT_EQ(v1.size(), 10);

  std::array<char, 10> vec{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  std::array<char, 10> vec1(std::move(vec));
  EXPECT_EQ(v1.front(), vec1.front());
  EXPECT_EQ(v1.back(), vec1.back());
  EXPECT_EQ(*v1.begin(), *vec1.begin());
  EXPECT_EQ(*(v1.end() - 1), *(vec1.end() - 1));
  EXPECT_EQ(v1.size(), vec1.size());
}

TEST(TestOfArray, TestOfMovingOperator) {
  s21::array<int, 10> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::array<int, 10> v1;
  v1 = std::move(
      v);  // а это использование перегруженного оператора присваивания
           // перемещением, т.е. объект v1 уже создан ранее, и ему ПРИСВАИВАЮТСЯ
           // элементы v путем перемещения в уже существующий объект
  EXPECT_EQ(v1.front(), 1);
  EXPECT_EQ(v1.back(), 10);
  EXPECT_EQ(*v1.begin(), 1);
  EXPECT_EQ(*(v1.end() - 1), 10);
  EXPECT_EQ(v1.size(), 10);

  std::array<int, 10> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::array<int, 10> vec1;
  vec1 = std::move(vec);
  EXPECT_EQ(v1.front(), vec1.front());
  EXPECT_EQ(v1.back(), vec1.back());
  EXPECT_EQ(*v1.begin(), *vec1.begin());
  EXPECT_EQ(*(v1.end() - 1), *(vec1.end() - 1));
  EXPECT_EQ(v1.size(), vec1.size());
}

TEST(TestOfArray, TestOfMovingOperator1) {
  s21::array<double, 10> v{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  s21::array<double, 10> v1;
  v1 = std::move(v);
  EXPECT_EQ(v1.front(), 1.1);
  EXPECT_EQ(v1.back(), 10.1);
  EXPECT_EQ(*v1.begin(), 1.1);
  EXPECT_EQ(*(v1.end() - 1), 10.1);
  EXPECT_EQ(v1.size(), 10);

  std::array<double, 10> vec{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  std::array<double, 10> vec1;
  vec1 = std::move(vec);
  EXPECT_EQ(v1.front(), vec1.front());
  EXPECT_EQ(v1.back(), vec1.back());
  EXPECT_EQ(*v1.begin(), *vec1.begin());
  EXPECT_EQ(*(v1.end() - 1), *(vec1.end() - 1));
  EXPECT_EQ(v1.size(), vec1.size());
}

TEST(TestOfArray, TestOfMovingOperator2) {
  s21::array<char, 10> v{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  s21::array<char, 10> v1;
  v1 = std::move(v);
  EXPECT_EQ(v1.front(), 'a');
  EXPECT_EQ(v1.back(), 'k');
  EXPECT_EQ(*v1.begin(), 'a');
  EXPECT_EQ(*(v1.end() - 1), 'k');
  EXPECT_EQ(v1.size(), 10);

  std::array<char, 10> vec{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  std::array<char, 10> vec1;
  vec1 = std::move(vec);
  EXPECT_EQ(v1.front(), vec1.front());
  EXPECT_EQ(v1.back(), vec1.back());
  EXPECT_EQ(*v1.begin(), *vec1.begin());
  EXPECT_EQ(*(v1.end() - 1), *(vec1.end() - 1));
  EXPECT_EQ(v1.size(), vec1.size());
}

TEST(TestOfArray, TestOfConstObject) {
  const s21::array<int, 10> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v.front(), 1);
  EXPECT_EQ(v.back(), 10);
  EXPECT_EQ(*v.begin(), 1);
  EXPECT_EQ(*(v.end() - 1), 10);
  EXPECT_EQ(v.size(), 10);
  EXPECT_EQ(v.max_size(), 10);

  const std::array<int, 10> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(v[2], vec[2]);
  EXPECT_EQ(v.front(), vec.front());
  EXPECT_EQ(v.back(), v.back());
  EXPECT_EQ(*v.begin(), *vec.begin());
  EXPECT_EQ(*(v.end() - 1), *(vec.end() - 1));
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.max_size(), vec.max_size());
}

TEST(TestOfArray, TestOfConstObject1) {
  const s21::array<double, 10> v{1.1, 2.2, 3.3, 4.4, 5.5,
                                 6.6, 7.7, 8.8, 9.9, 10.1};
  EXPECT_EQ(v[2], 3.3);
  EXPECT_EQ(v.front(), 1.1);
  EXPECT_EQ(v.back(), 10.1);
  EXPECT_EQ(*v.begin(), 1.1);
  EXPECT_EQ(*(v.end() - 1), 10.1);
  EXPECT_EQ(v.size(), 10);
  EXPECT_EQ(v.max_size(), 10);

  const std::array<double, 10> vec{1.1, 2.2, 3.3, 4.4, 5.5,
                                   6.6, 7.7, 8.8, 9.9, 10.1};
  EXPECT_EQ(v[2], vec[2]);
  EXPECT_EQ(v.front(), vec.front());
  EXPECT_EQ(v.back(), v.back());
  EXPECT_EQ(*v.begin(), *vec.begin());
  EXPECT_EQ(*(v.end() - 1), *(vec.end() - 1));
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.max_size(), vec.max_size());
}

TEST(TestOfArray, TestOfConstObject2) {
  const s21::array<char, 10> v{'a', 'b', 'c', 'd', 'e',
                               'f', 'g', 'h', 'j', 'k'};
  EXPECT_EQ(v[2], 'c');
  EXPECT_EQ(v.front(), 'a');
  EXPECT_EQ(v.back(), 'k');
  EXPECT_EQ(*v.begin(), 'a');
  EXPECT_EQ(*(v.end() - 1), 'k');
  EXPECT_EQ(v.size(), 10);
  EXPECT_EQ(v.max_size(), 10);

  const std::array<int, 10> vec{'a', 'b', 'c', 'd', 'e',
                                'f', 'g', 'h', 'j', 'k'};
  EXPECT_EQ(v[2], vec[2]);
  EXPECT_EQ(v.front(), vec.front());
  EXPECT_EQ(v.back(), v.back());
  EXPECT_EQ(*v.begin(), *vec.begin());
  EXPECT_EQ(*(v.end() - 1), *(vec.end() - 1));
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.max_size(), vec.max_size());
}

TEST(TestOfArray, TestAccessorAtAndBrackets) {
  s21::array<int, 10> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(v.at(8), 9);
  EXPECT_ANY_THROW(v.at(15));
  EXPECT_EQ(v[4], 5);

  std::array<int, 10> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(v.at(8), vec.at(8));
  EXPECT_EQ(v[4], vec[4]);
}

TEST(TestOfArray, TestAccessorAtAndBrackets1) {
  s21::array<double, 10> v{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  EXPECT_EQ(v.at(8), 9.9);
  EXPECT_ANY_THROW(v.at(15));
  EXPECT_EQ(v[4], 5.5);

  std::array<double, 10> vec{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  EXPECT_EQ(v.at(8), vec.at(8));
  EXPECT_EQ(v[4], vec[4]);
}

TEST(TestOfArray, TestAccessorAtAndBrackets2) {
  s21::array<char, 10> v{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  EXPECT_EQ(v.at(8), 'j');
  EXPECT_ANY_THROW(v.at(15));
  EXPECT_EQ(v[4], 'e');

  std::array<char, 10> vec{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  EXPECT_EQ(v.at(8), vec.at(8));
  EXPECT_EQ(v[4], vec[4]);
}

TEST(TestOfArray, TestOfCapacityDataEmptySizeAndMaxSize) {
  s21::array<int, 10> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(v.size(), 10);
  EXPECT_EQ(v.max_size(), 10);
  EXPECT_EQ(v.empty(), false);

  s21::array<int, 0> v1;
  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v1.empty(), true);

  auto ptr = v.data();
  EXPECT_EQ(ptr[6], 7);

  std::array<int, 10> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::array<int, 0> vec1;
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.max_size(), vec.max_size());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v1.size(), vec1.size());
  EXPECT_EQ(v1.empty(), vec1.empty());

  auto ptr1 = vec.data();
  EXPECT_EQ(ptr[6], ptr1[6]);
}

TEST(TestOfArray, TestOfCapacityDataEmptySizeAndMaxSize1) {
  s21::array<double, 10> v{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  EXPECT_EQ(v.size(), 10);
  EXPECT_EQ(v.max_size(), 10);
  EXPECT_EQ(v.empty(), false);

  s21::array<double, 0> v1;
  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v1.empty(), true);

  auto ptr = v.data();
  EXPECT_EQ(ptr[6], 7.7);

  std::array<double, 10> vec{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  std::array<double, 0> vec1;
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.max_size(), vec.max_size());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v1.size(), vec1.size());
  EXPECT_EQ(v1.empty(), vec1.empty());

  auto ptr1 = vec.data();
  EXPECT_EQ(ptr[6], ptr1[6]);
}

TEST(TestOfArray, TestOfCapacityDataEmptySizeAndMaxSize2) {
  s21::array<char, 10> v{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  EXPECT_EQ(v.size(), 10);
  EXPECT_EQ(v.max_size(), 10);
  EXPECT_EQ(v.empty(), false);

  s21::array<char, 0> v1;
  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v1.empty(), true);

  auto ptr = v.data();
  EXPECT_EQ(ptr[6], 'g');

  std::array<char, 10> vec{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  std::array<char, 0> vec1;
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.max_size(), vec.max_size());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v1.size(), vec1.size());
  EXPECT_EQ(v1.empty(), vec1.empty());

  auto ptr1 = vec.data();
  EXPECT_EQ(ptr[6], ptr1[6]);
}

TEST(TestOfArray, TestOfModifierSwap) {  // массив обязательно должны быть
                                         // одинаковых размеров!
  s21::array<int, 10> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21::array<int, 10> v1{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  v1.swap(v);
  EXPECT_EQ(v.front(), 11);
  EXPECT_EQ(v1.front(), 1);
  EXPECT_EQ(v.back(), 20);
  EXPECT_EQ(v1.back(), 10);
  EXPECT_EQ(*v.begin(), 11);
  EXPECT_EQ(*v1.begin(), 1);
  EXPECT_EQ(*(v.end() - 1), 20);
  EXPECT_EQ(*(v1.end() - 1), 10);
  EXPECT_EQ(v.size(), 10);
  EXPECT_EQ(v1.size(), 10);

  std::array<int, 10> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::array<int, 10> vec1{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  vec1.swap(vec);
  EXPECT_EQ(v1.front(), vec1.front());
  EXPECT_EQ(v1.back(), vec1.back());
  EXPECT_EQ(*v1.begin(), *vec1.begin());
  EXPECT_EQ(*(v1.end() - 1), *(vec1.end() - 1));
  EXPECT_EQ(v1.size(), vec1.size());
}

TEST(TestOfArray, TestOfModifierSwap1) {
  s21::array<double, 10> v{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  s21::array<double, 10> v1{11.11, 12.12, 13.13, 14.14, 15.15,
                            16.16, 17.17, 18.18, 19.19, 20.2};
  v1.swap(v);
  EXPECT_EQ(v.front(), 11.11);
  EXPECT_EQ(v1.front(), 1.1);
  EXPECT_EQ(v.back(), 20.2);
  EXPECT_EQ(v1.back(), 10.1);
  EXPECT_EQ(*v.begin(), 11.11);
  EXPECT_EQ(*v1.begin(), 1.1);
  EXPECT_EQ(*(v.end() - 1), 20.2);
  EXPECT_EQ(*(v1.end() - 1), 10.1);
  EXPECT_EQ(v.size(), 10);
  EXPECT_EQ(v1.size(), 10);

  std::array<double, 10> vec{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  std::array<double, 10> vec1{11.11, 12.12, 13.13, 14.14, 15.15,
                              16.16, 17.17, 18.18, 19.19, 20.2};
  vec1.swap(vec);
  EXPECT_EQ(v1.front(), vec1.front());
  EXPECT_EQ(v1.back(), vec1.back());
  EXPECT_EQ(*v1.begin(), *vec1.begin());
  EXPECT_EQ(*(v1.end() - 1), *(vec1.end() - 1));
  EXPECT_EQ(v1.size(), vec1.size());
}

TEST(TestOfArray, TestOfModifierSwap2) {
  s21::array<char, 10> v{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  s21::array<char, 10> v1{'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'};
  v1.swap(v);
  EXPECT_EQ(v.front(), 'l');
  EXPECT_EQ(v1.front(), 'a');
  EXPECT_EQ(v.back(), 'u');
  EXPECT_EQ(v1.back(), 'k');
  EXPECT_EQ(*v.begin(), 'l');
  EXPECT_EQ(*v1.begin(), 'a');
  EXPECT_EQ(*(v.end() - 1), 'u');
  EXPECT_EQ(*(v1.end() - 1), 'k');
  EXPECT_EQ(v.size(), 10);
  EXPECT_EQ(v1.size(), 10);

  std::array<char, 10> vec{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  std::array<char, 10> vec1{'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'};
  vec1.swap(vec);
  EXPECT_EQ(v1.front(), vec1.front());
  EXPECT_EQ(v1.back(), vec1.back());
  EXPECT_EQ(*v1.begin(), *vec1.begin());
  EXPECT_EQ(*(v1.end() - 1), *(vec1.end() - 1));
  EXPECT_EQ(v1.size(), vec1.size());
}

TEST(TestOfArray, TestOfModifierFilling) {
  s21::array<int, 10> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  v.fill(43);
  auto s21_it = v.begin();
  for (size_t i = 0; i < v.size(); ++i) {
    EXPECT_EQ(*s21_it, 43);
    ++s21_it;
  }
  EXPECT_EQ(s21_it, v.end());

  std::array<int, 10> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec.fill(43);
  auto std_it = vec.begin();
  for (size_t i = 0; i < vec.size(); ++i) {
    EXPECT_EQ(*std_it, 43);
    ++std_it;
  }
  EXPECT_EQ(std_it, vec.end());

  while (s21_it != v.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it, ++std_it;
  }
}

TEST(TestOfArray, TestOfModifierFilling1) {
  s21::array<double, 10> v{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  v.fill(43.43);
  auto s21_it = v.begin();
  for (size_t i = 0; i < v.size(); ++i) {
    EXPECT_EQ(*s21_it, 43.43);
    ++s21_it;
  }
  EXPECT_EQ(s21_it, v.end());

  std::array<double, 10> vec{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
  vec.fill(43.43);
  auto std_it = vec.begin();
  for (size_t i = 0; i < vec.size(); ++i) {
    EXPECT_EQ(*std_it, 43.43);
    ++std_it;
  }
  EXPECT_EQ(std_it, vec.end());

  while (s21_it != v.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it, ++std_it;
  }
}

TEST(TestOfArray, TestOfModifierFilling2) {
  s21::array<char, 10> v{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  v.fill('z');
  auto s21_it = v.begin();
  for (size_t i = 0; i < v.size(); ++i) {
    EXPECT_EQ(*s21_it, 'z');
    ++s21_it;
  }
  EXPECT_EQ(s21_it, v.end());

  std::array<char, 10> vec{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k'};
  vec.fill('z');
  auto std_it = vec.begin();
  for (size_t i = 0; i < vec.size(); ++i) {
    EXPECT_EQ(*std_it, 'z');
    ++std_it;
  }
  EXPECT_EQ(std_it, vec.end());

  while (s21_it != v.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    ++s21_it, ++std_it;
  }
}
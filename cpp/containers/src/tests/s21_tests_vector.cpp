#include "s21_tests_main.h"

// Testing of Vector Member functions

TEST(TestVectorMemberFunctions, TestOfDefaultConstructor) {
  s21::vector<int> v;
  std::vector<int> vec;
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
}

TEST(TestVectorMemberFunctions, TestOfConstructorWithParameter) {
  s21::vector<int> v(7);
  std::vector<int> vec(7);
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
}

TEST(TestVectorMemberFunctions, TestOfConstructorWithParameter1) {
  s21::vector<double> v(9);
  std::vector<double> vec(9);
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
}

TEST(TestVectorMemberFunctions, TestOfConstructorWithInitialization) {
  s21::vector<int> v = {1, 2, 3, 4, 5, 6};
  std::vector<int> vec = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v.front(), vec.front());
  EXPECT_EQ(v.back(), vec.back());
}

TEST(TestVectorMemberFunctions, TestOfConstructorWithInitialization1) {
  s21::vector<double> v = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
  std::vector<double> vec = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v.front(), vec.front());
  EXPECT_EQ(v.back(), vec.back());
}

TEST(TestVectorMemberFunctions, TestOfConstructorWithInizializedList1) {
  s21::vector<double> v{1.1, 2.2, 3.3, 4.4};
  std::vector<double> vec{1.1, 2.2, 3.3, 4.4};
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v.at(0), vec.at(0));
  EXPECT_EQ(v.at(1), vec.at(1));
  EXPECT_EQ(v.at(2), vec.at(2));
  EXPECT_EQ(v.at(3), vec.at(3));
}

TEST(TestVectorMemberFunctions, TestOfConstructorWithInizializedList2) {
  s21::vector<char> v{'a', 'b', 'c', 'd'};
  std::vector<char> vec{'a', 'b', 'c', 'd'};
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v.at(0), vec.at(0));
  EXPECT_EQ(v.at(1), vec.at(1));
  EXPECT_EQ(v.at(2), vec.at(2));
  EXPECT_EQ(v.at(3), vec.at(3));
}

TEST(TestVectorMemberFunctions, TestOfConstructorWithEmptyInitializedList) {
  std::initializer_list<int> x;
  s21::vector<int> v{x};
  std::vector<int> vec{x};
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
}

TEST(TestVectorMemberFunctions, TestOfDestructor) {
  s21::vector<int> v{11, 22, 33, 44, 55, 66};
  v.~vector();

  EXPECT_EQ(0, v.size());
  EXPECT_EQ(0, v.capacity());
  EXPECT_EQ(0, v.data());
}

TEST(TestVectorMemberFunctions, TestOfCopyConstructor) {
  s21::vector<int> v = {1, 2, 3, 4, 5};
  std::vector<int> vec = {1, 2, 3, 4, 5};
  s21::vector<int> v1 = v;
  std::vector<int> vec1 = vec;

  EXPECT_EQ(v.size(), v1.size());
  EXPECT_EQ(vec.size(), vec1.size());
  EXPECT_EQ(v.capacity(), v1.capacity());
  EXPECT_EQ(vec.capacity(), vec1.capacity());

  auto s21_it = v.begin();
  auto s21_it1 = v1.begin();

  while (s21_it != v.end()) {
    EXPECT_EQ(*s21_it, *s21_it1);
    s21_it++, s21_it1++;
  }

  auto std_it = vec.begin();
  auto std_it1 = vec1.begin();

  while (std_it != vec.end()) {
    EXPECT_EQ(*std_it, *std_it1);
    std_it++, std_it1++;
  }
}

TEST(TestVectorMemberFunctions, TestOfCopyConstructor1) {
  s21::vector<double> v = {1.1, 2.2, 3.3, 4.4, 5.5};
  std::vector<double> vec = {1.1, 2.2, 3.3, 4.4, 5.5};
  s21::vector<double> v1 = v;
  std::vector<double> vec1 = vec;

  EXPECT_EQ(v.size(), v1.size());
  EXPECT_EQ(vec.size(), vec1.size());
  EXPECT_EQ(v.capacity(), v1.capacity());
  EXPECT_EQ(vec.capacity(), vec1.capacity());

  auto s21_it = v.begin();
  auto s21_it1 = v1.begin();

  while (s21_it != v.end()) {
    EXPECT_EQ(*s21_it, *s21_it1);
    s21_it++, s21_it1++;
  }

  auto std_it = vec.begin();
  auto std_it1 = vec1.begin();

  while (std_it != vec.end()) {
    EXPECT_EQ(*std_it, *std_it1);
    std_it++, std_it1++;
  }
}

TEST(TestVectorMemberFunctions, TestOfCopyConstructor2) {
  s21::vector<char> v = {'a', 'b', 'c', 'd', 'e'};
  std::vector<char> vec = {'a', 'b', 'c', 'd', 'e'};
  s21::vector<char> v1 = v;
  std::vector<char> vec1 = vec;

  EXPECT_EQ(v.size(), v1.size());
  EXPECT_EQ(vec.size(), vec1.size());
  EXPECT_EQ(v.capacity(), v1.capacity());
  EXPECT_EQ(vec.capacity(), vec1.capacity());

  auto s21_it = v.begin();
  auto s21_it1 = v1.begin();

  while (s21_it != v.end()) {
    EXPECT_EQ(*s21_it, *s21_it1);
    s21_it++, s21_it1++;
  }

  auto std_it = vec.begin();
  auto std_it1 = vec1.begin();

  while (std_it != vec.end()) {
    EXPECT_EQ(*std_it, *std_it1);
    std_it++, std_it1++;
  }
}

TEST(TestVectorMemberFunctions, TestOfCopyConstructorWithoutParameters) {
  s21::vector<int> v;
  std::vector<int> vec;
  s21::vector<int> s21_v(v);
  std::vector<int> std_vec(vec);

  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v.empty(), vec.empty());

  EXPECT_EQ(s21_v.size(), std_vec.size());
  EXPECT_EQ(s21_v.capacity(), std_vec.capacity());
  EXPECT_EQ(s21_v.empty(), std_vec.empty());
}

TEST(TestVectorMemberFunctions, TestOfCopyConstructorWithAt) {
  s21::vector<int> v = {1, 2, 3, 4};
  std::vector<int> vec = {1, 2, 3, 4};
  s21::vector<int> s21_v(v);
  std::vector<int> std_vec(vec);

  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v.at(0), vec.at(0));
  EXPECT_EQ(v.at(1), vec.at(1));
  EXPECT_EQ(v.at(2), vec.at(2));
  EXPECT_EQ(v.at(3), vec.at(3));

  EXPECT_EQ(s21_v.size(), std_vec.size());
  EXPECT_EQ(s21_v.capacity(), std_vec.capacity());
  EXPECT_EQ(s21_v.empty(), std_vec.empty());
  EXPECT_EQ(s21_v.at(0), std_vec.at(0));
  EXPECT_EQ(s21_v.at(1), std_vec.at(1));
  EXPECT_EQ(s21_v.at(2), std_vec.at(2));
  EXPECT_EQ(s21_v.at(3), std_vec.at(3));
}

TEST(TestVectorMemberFunctions, TestOfCopyConstructorWithAt1) {
  s21::vector<double> v = {1.1, 2.2, 3.3, 4.4};
  std::vector<double> vec = {1.1, 2.2, 3.3, 4.4};
  s21::vector<double> s21_v(v);
  std::vector<double> std_vec(vec);

  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v.at(0), vec.at(0));
  EXPECT_EQ(v.at(1), vec.at(1));
  EXPECT_EQ(v.at(2), vec.at(2));
  EXPECT_EQ(v.at(3), vec.at(3));

  EXPECT_EQ(s21_v.size(), std_vec.size());
  EXPECT_EQ(s21_v.capacity(), std_vec.capacity());
  EXPECT_EQ(s21_v.empty(), std_vec.empty());
  EXPECT_EQ(s21_v.at(0), std_vec.at(0));
  EXPECT_EQ(s21_v.at(1), std_vec.at(1));
  EXPECT_EQ(s21_v.at(2), std_vec.at(2));
  EXPECT_EQ(s21_v.at(3), std_vec.at(3));
}

TEST(TestVectorMemberFunctions, TestOfCopyConstructorWithAt2) {
  s21::vector<char> v = {'a', 'b', 'c', 'd'};
  std::vector<char> vec = {'a', 'b', 'c', 'd'};
  s21::vector<char> s21_v(v);
  std::vector<char> std_vec(vec);

  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v.at(0), vec.at(0));
  EXPECT_EQ(v.at(1), vec.at(1));
  EXPECT_EQ(v.at(2), vec.at(2));
  EXPECT_EQ(v.at(3), vec.at(3));

  EXPECT_EQ(s21_v.size(), std_vec.size());
  EXPECT_EQ(s21_v.capacity(), std_vec.capacity());
  EXPECT_EQ(s21_v.empty(), std_vec.empty());
  EXPECT_EQ(s21_v.at(0), std_vec.at(0));
  EXPECT_EQ(s21_v.at(1), std_vec.at(1));
  EXPECT_EQ(s21_v.at(2), std_vec.at(2));
  EXPECT_EQ(s21_v.at(3), std_vec.at(3));
}

TEST(TestVectorMemberFunctions, TestOfMovingConstructorEmptyVector) {
  s21::vector<int> v;
  std::vector<int> vec;
  s21::vector<int> v1(v);
  std::vector<int> vec1(vec);

  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v1.size(), vec1.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v1.capacity(), vec1.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v1.empty(), vec1.empty());
}

TEST(TestVectorMemberFunctions, TestOfMovingConstructor) {
  s21::vector<int> v = {1, 2, 3, 4};
  std::vector<int> vec = {1, 2, 3, 4};
  s21::vector<int> v1 = std::move(v);
  std::vector<int> vec1 = std::move(vec);

  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v1.size(), vec1.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v1.capacity(), vec1.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v1.empty(), vec1.empty());

  auto s21_it = v1.begin();
  auto std_it = vec1.begin();

  while (s21_it != v1.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    s21_it++, std_it++;
  }
}

TEST(TestVectorMemberFunctions, TestOfMovingConstructor1) {
  s21::vector<double> v = {1.1, 2.2, 3.3, 4.4};
  std::vector<double> vec = {1.1, 2.2, 3.3, 4.4};
  s21::vector<double> v1 = std::move(v);
  std::vector<double> vec1 = std::move(vec);

  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v1.size(), vec1.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v1.capacity(), vec1.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v1.empty(), vec1.empty());

  auto s21_it = v1.begin();
  auto std_it = vec1.begin();

  while (s21_it != v1.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    s21_it++, std_it++;
  }
}

TEST(TestVectorMemberFunctions, TestOfMovingConstructor2) {
  s21::vector<char> v = {'a', 'b', 'c', 'd'};
  std::vector<char> vec = {'a', 'b', 'c', 'd'};
  s21::vector<char> v1 = std::move(v);
  std::vector<char> vec1 = std::move(vec);

  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v1.size(), vec1.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v1.capacity(), vec1.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v1.empty(), vec1.empty());

  auto s21_it = v1.begin();
  auto std_it = vec1.begin();

  while (s21_it != v1.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    s21_it++, std_it++;
  }
}

TEST(TestVectorMemberFunctions, TestOfMovingConstructor3) {
  s21::vector<int> v = {2, 5, 6, 9, -99};
  std::vector<int> vec = {2, 5, 6, 9, -99};
  s21::vector<int> v1(v);
  std::vector<int> vec1(vec);

  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v1.size(), vec1.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v1.capacity(), vec1.capacity());
  EXPECT_EQ(v.empty(), vec.empty());
  EXPECT_EQ(v1.empty(), vec1.empty());

  auto s21_it = v1.begin();
  auto std_it = vec1.begin();

  while (s21_it != v1.end()) {
    EXPECT_EQ(*s21_it, *std_it);
    s21_it++, std_it++;
  }
}

TEST(TestVectorMemberFunctions, TestOfMovingOperator) {
  s21::vector<int> v{6, 7, 10, -43};
  s21::vector<int> vec;
  vec = std::move(v);
  EXPECT_EQ(vec.size(), 4);
  EXPECT_EQ(vec.at(0), 6);
  EXPECT_EQ(vec.at(1), 7);
  EXPECT_EQ(vec.at(2), 10);
  EXPECT_EQ(vec.at(3), -43);
}

TEST(TestVectorMemberFunctions, TestOfMovingOperator1) {
  s21::vector<double> v{6.2, 7.1, 10.6, -43.9};
  s21::vector<double> vec{1.1, 1.2, 1.3};
  vec = std::move(v);
  EXPECT_EQ(vec.size(), 4);
  EXPECT_EQ(vec.at(0), 6.2);
  EXPECT_EQ(vec.at(1), 7.1);
  EXPECT_EQ(vec.at(2), 10.6);
  EXPECT_EQ(vec.at(3), -43.9);
}

// Testing of Vector Element access

TEST(TestVectorElementAccess, TestOfAccessorAt) {
  s21::vector<int> v{1, 2, 3, 4};
  std::vector<int> vec{1, 2, 3, 4};
  EXPECT_EQ(v.at(0), vec.at(0));
  EXPECT_EQ(v.at(1), vec.at(1));
  EXPECT_EQ(v.at(2), vec.at(2));
  EXPECT_EQ(v.at(3), vec.at(3));
}

// Testing of Vector modifiers

TEST(TestVectorElementAccess, TestOfAccessorAt1) {
  s21::vector<int> v{1, 2, 3, 4};
  std::vector<int> vec{1, 2, 3, 4};
  EXPECT_ANY_THROW(v.at(7));
  EXPECT_ANY_THROW(vec.at(7));
}

TEST(TestVectorElementAccess, TestOfAccessorAt2) {
  s21::vector<int> v;
  std::vector<int> vec;
  EXPECT_ANY_THROW(v.at(7));
  EXPECT_ANY_THROW(vec.at(7));
}

TEST(TestVectorElementAccess, TestOfAccessorSquareBrackets) {
  s21::vector<int> v{3, 7, 99};
  std::vector<int> vec{3, 7, 99};
  EXPECT_EQ(v[0], vec[0]);
  EXPECT_EQ(v[1], vec[1]);
  EXPECT_EQ(v[2], vec[2]);
}

TEST(TestVectorElementAccess, TestOfAccessorFront) {
  s21::vector<double> v{1.1, 2.2, 3.3, 4.4};
  std::vector<double> vec{1.1, 2.2, 3.3, 4.4};
  EXPECT_EQ(v.front(), vec.front());
}

TEST(TestVectorElementAccess, TestOfAccessorFront1) {
  s21::vector<char> v;
  std::vector<char> vec;
  EXPECT_ANY_THROW(v.front());
}

TEST(TestVectorElementAccess, TestOfAccessorBack) {
  s21::vector<char> v{'a', 'b', 'c'};
  std::vector<char> vec{'a', 'b', 'c'};
  EXPECT_EQ(v.back(), vec.back());
}

TEST(TestVectorElementAccess, TestOfAccessorBack1) {
  s21::vector<double> v;
  std::vector<double> vec;
  EXPECT_ANY_THROW(v.back());
}

TEST(TestVectorElementAccess, TestOfAccessorData) {
  s21::vector<int> v{-7, 4, 52};
  std::vector<int> vec{-7, 4, 52};
  EXPECT_EQ(*v.data(), *vec.data());
}

// Testing of Vector Capacity

TEST(TestVectorCapacity, TestOfCapacityEmpty) {
  s21::vector<int> v;
  std::vector<int> vec;
  EXPECT_EQ(v.empty(), vec.empty());
}

TEST(TestVectorCapacity, TestOfCapacityEmpty1) {
  s21::vector<int> v{8, 9, 2};
  std::vector<int> vec{8, 9, 2};
  EXPECT_EQ(v.empty(), vec.empty());
}

TEST(TestVectorCapacity, TestOfCapacitySize) {
  s21::vector<double> v;
  std::vector<double> vec;
  EXPECT_EQ(v.size(), vec.size());
}

TEST(TestVectorCapacity, TestOfCapacitySize1) {
  s21::vector<double> v{1.1, 2.2, 3.3};
  std::vector<double> vec{1.1, 2.2, 3.3};
  EXPECT_EQ(v.size(), vec.size());
}

TEST(TestVectorCapacity, TestOfCapacityReserve) {
  s21::vector<int> v;
  std::vector<int> vec;
  v.reserve(6);
  vec.reserve(6);

  EXPECT_EQ(v.capacity(), vec.capacity());
}

TEST(TestVectorCapacity, TestOfCapacityReserve1) {
  s21::vector<int> v{2, 3, 6};
  std::vector<int> vec{2, 3, 6};
  v.reserve(6);
  vec.reserve(6);

  EXPECT_EQ(v.capacity(), vec.capacity());
}

TEST(TestVectorCapacity, TestOfCapacityReserve2) {
  s21::vector<int> v{2, 3, 6};
  std::vector<int> vec{2, 3, 6};
  v.reserve(1);
  vec.reserve(1);

  EXPECT_EQ(v.capacity(), vec.capacity());
}

TEST(TestVectorCapacity, TestOfCapacityReserve3) {
  s21::vector<int> v{2, 3, 6};
  std::vector<int> vec{2, 3, 6};
  EXPECT_ANY_THROW(v.reserve(-100));
  EXPECT_ANY_THROW(vec.reserve(-100));
}

TEST(TestVectorCapacity, TestOfCapacityCapacity) {
  s21::vector<char> v;
  std::vector<char> vec;
  EXPECT_EQ(v.capacity(), vec.capacity());
}

TEST(TestVectorCapacity, TestOfCapacityCapacity1) {
  s21::vector<int> v{88, -199, 40};
  std::vector<int> vec{88, -199, 40};
  EXPECT_EQ(v.capacity(), vec.capacity());
}

TEST(TestVectorCapacity, TestOfCapacityShrinkToFit) {
  s21::vector<int> v{2, 3, 6};
  std::vector<int> vec{2, 3, 6};
  v.reserve(100);
  vec.reserve(100);
  v.shrink_to_fit();
  vec.shrink_to_fit();
  EXPECT_EQ(v.capacity(), vec.capacity());
}

TEST(TestVectorCapacity, TestOfCapacityShrinkToFit1) {
  s21::vector<double> v;
  std::vector<double> vec;
  v.reserve(100);
  vec.reserve(100);
  v.shrink_to_fit();
  vec.shrink_to_fit();
  EXPECT_EQ(v.capacity(), vec.capacity());
}

// Testing of Vector Modifiers

TEST(TestVectorModifiers, TestOfModifierClear) {
  s21::vector<int> v;
  std::vector<int> vec;
  v.clear();
  vec.clear();
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v.begin(), v.end());
  EXPECT_EQ(vec.begin(), vec.end());
}

TEST(TestVectorModifiers, TestOfModifierClear1) {
  s21::vector<int> v{5, 25, 55, 75};
  std::vector<int> vec{5, 25, 55, 75};
  v.clear();
  vec.clear();
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v.begin(), v.end());
  EXPECT_EQ(vec.begin(), vec.end());
}

TEST(TestVectorModifiers, TestOfModifierInsert) {
  s21::vector<int> v = {1, 2, 3, 4};
  s21::vector<int> v1 = {1, 5, 2, 3, 4};

  auto s21_it = v.begin();
  s21_it++;
  v.insert(s21_it, 5);

  auto s21_it1 = v.begin();
  auto s21_it2 = v1.begin();

  while (s21_it1 != v.end()) {
    EXPECT_EQ(*s21_it1, *s21_it2);
    s21_it1++, s21_it2++;
  }
  EXPECT_EQ(v.size(), v1.size());

  v.insert(v.end(), 6);
  EXPECT_EQ(v.back(), 6);
}

TEST(TestVectorModifiers, TestOfModifierInsert1) {
  s21::vector<double> v{1.2, 2.3, 4.5};
  std::vector<double> vec{1.2, 2.3, 4.5};
  v.insert(v.begin() + 2, 6.7);
  vec.insert(vec.begin() + 2, 6.7);
  EXPECT_EQ(v.at(0), vec.at(0));
  EXPECT_EQ(v.at(1), vec.at(1));
  EXPECT_EQ(v.at(2), vec.at(2));
  EXPECT_EQ(v.at(3), vec.at(3));
}

TEST(TestVectorModifiers, TestOfModifierInsert2) {
  s21::vector<double> v{1.2, 2.3, 4.5};
  std::vector<double> vec{1.2, 2.3, 4.5};
  v.insert(v.begin() + v.size(), 6.7);
  vec.insert(vec.begin() + vec.size(), 6.7);
  EXPECT_EQ(v.at(3), vec.at(3));
}

TEST(TestVectorModifiers, TestOfModifierInsert3) {
  s21::vector<int> v{1, 2, 3, 4, 5};

  EXPECT_ANY_THROW(v.insert(v.begin() - 1, 10));
  EXPECT_ANY_THROW(v.insert(v.end() + 1, 10));

  s21::vector<int> empty_vec;
  EXPECT_ANY_THROW(empty_vec.insert(empty_vec.begin() - 1, 10));
  EXPECT_ANY_THROW(empty_vec.insert(empty_vec.end() + 1, 10));
}

TEST(TestVectorModifiers, TestOfModifierErase) {
  s21::vector<double> v = {1.1, 2.2, 3.3, 5.5};
  s21::vector<double> vec = {1.1, 2.2, 3.3, 4.4, 5.5};

  auto s21_it = vec.begin();
  std::advance(s21_it, 3);
  vec.erase(s21_it);

  auto s21_it1 = v.begin();
  auto s21_it2 = vec.begin();

  while (s21_it1 != v.end()) {
    EXPECT_EQ(*s21_it1, *s21_it2);
    s21_it1++, s21_it2++;
  }
  EXPECT_EQ(v.size(), vec.size());
}

TEST(TestVectorModifiers, TestOfModifierErase1) {
  s21::vector<int> v{4, 3, 2, 1};
  std::vector<int> vec{4, 3, 2, 1};
  v.erase(v.begin());
  vec.erase(vec.begin());
  EXPECT_EQ(v.at(0), vec.at(0));
  EXPECT_EQ(v.at(1), vec.at(1));
  EXPECT_EQ(v.at(2), vec.at(2));
}

TEST(TestVectorModifiers, TestOfModifierErase2) {
  s21::vector<int> v{4, 3, 2, 1};
  std::vector<int> vec{4, 3, 2, 1};
  v.erase(v.begin() + 2);
  vec.erase(vec.begin() + 2);
  EXPECT_EQ(v.at(0), vec.at(0));
  EXPECT_EQ(v.at(1), vec.at(1));
  EXPECT_EQ(v.at(2), vec.at(2));
}

TEST(TestVectorModifiers, TestOfModifierErase3) {
  s21::vector<int> v{4, 3, 2, 1};
  std::vector<int> vec{4, 3, 2, 1};
  v.erase(v.end() - 1);
  vec.erase(vec.end() - 1);
  EXPECT_EQ(v.at(0), vec.at(0));
  EXPECT_EQ(v.at(1), vec.at(1));
  EXPECT_EQ(v.at(2), vec.at(2));
}

TEST(TestVectorModifiers, TestOfModifierErase4) {
  s21::vector<int> v{1, 2, 3, 4, 5};

  EXPECT_ANY_THROW(v.erase(v.begin() - 1));
  EXPECT_ANY_THROW(v.erase(v.end()));

  s21::vector<int> empty_v;
  EXPECT_ANY_THROW(empty_v.erase(empty_v.begin()));
}

TEST(TestVectorModifiers, TestOfModifierPushBack) {
  s21::vector<char> v = {'a', 'b', 'c', 'd', 'e'};
  std::vector<char> vec = {'a', 'b', 'c', 'd', 'e'};

  v.push_back('f');
  vec.push_back('f');

  EXPECT_EQ(v.front(), vec.front());
  EXPECT_EQ(v.back(), vec.back());
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.empty(), v.empty());

  auto s21_it1 = v.begin();
  auto std_it1 = vec.begin();

  while (s21_it1 != v.end()) {
    EXPECT_EQ(*s21_it1, *std_it1);
    s21_it1++, std_it1++;
  }
}

TEST(TestVectorModifiers, TestOfModifierPushBack1) {
  s21::vector<int> v;
  std::vector<int> vec;
  v.push_back(100);
  v.push_back(101);
  vec.push_back(100);
  vec.push_back(101);

  EXPECT_EQ(v.at(0), vec.at(0));
  EXPECT_EQ(v.at(1), vec.at(1));
}

TEST(TestVectorModifiers, TestOfModifierPushBack2) {
  s21::vector<int> v{3, 4};
  std::vector<int> vec{3, 4};
  v.push_back(100);
  v.push_back(101);
  vec.push_back(100);
  vec.push_back(101);

  EXPECT_EQ(v.at(0), vec.at(0));
  EXPECT_EQ(v.at(1), vec.at(1));
  EXPECT_EQ(v.at(2), vec.at(2));
  EXPECT_EQ(v.at(3), vec.at(3));
}

TEST(TestVectorModifiers, TestOfModifierPopBack) {
  s21::vector<int> v = {11, 23, 34, -6};
  std::vector<int> vec = {11, 23, 34, -6};

  v.pop_back();
  vec.pop_back();

  EXPECT_EQ(v.front(), vec.front());
  EXPECT_EQ(v.back(), vec.back());
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.empty(), vec.empty());

  auto s21_it1 = v.begin();
  auto std_it1 = vec.begin();

  while (s21_it1 != v.end()) {
    EXPECT_EQ(*s21_it1, *std_it1);
    ++s21_it1, ++std_it1;
  }
}

TEST(TestVectorModifiers, TestOfModifierPopBack1) {
  s21::vector<int> v{3, 4};
  std::vector<int> vec{3, 4};
  v.pop_back();
  v.pop_back();
  vec.pop_back();
  vec.pop_back();

  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 2);
  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
}

TEST(TestVectorModifiers, TestOfModifierPopBack2) {
  s21::vector<int> v;
  std::vector<int> vec;
  v.pop_back();
  v.pop_back();
  vec.pop_back();
  vec.pop_back();

  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 0);
  EXPECT_EQ(v.capacity(), vec.capacity());
}

TEST(TestVectorModifiers, TestOfModifierSwap) {
  s21::vector<double> v1 = {1.2, 2.3, 3.4, 4.5};
  s21::vector<double> v2 = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};
  s21::vector<double> v3 = {1.2, 2.3, 3.4, 4.5};
  s21::vector<double> v4 = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};

  v1.swap(v2);
  auto s21_it1 = v1.begin();
  auto s21_it2 = v2.begin();
  auto s21_it3 = v3.begin();
  auto s21_it4 = v4.begin();

  while (s21_it1 != v1.end()) {
    EXPECT_EQ(*s21_it1, *s21_it4);
    ++s21_it1, ++s21_it4;
  }

  while (s21_it2 != v2.end()) {
    EXPECT_EQ(*s21_it2, *s21_it3);
    ++s21_it2, ++s21_it3;
  }

  EXPECT_EQ(v1.size(), v4.size());
  EXPECT_EQ(v2.size(), v3.size());
}

TEST(TestVectorModifiers, TestOfModifierSwap1) {
  s21::vector<int> v;
  s21::vector<int> v1;
  std::vector<int> vec;
  std::vector<int> vec1;

  v1.swap(v);
  vec1.swap(vec);

  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v1.size(), vec1.size());
  EXPECT_EQ(v1.capacity(), vec1.capacity());
}

TEST(TestVectorModifiers, TestOfModifierSwap2) {
  s21::vector<double> v{1.1, 2.2, 3.3};
  s21::vector<double> v1;
  std::vector<double> vec{1.1, 2.2, 3.3};
  std::vector<double> vec1;

  v1.swap(v);
  vec1.swap(vec);

  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v1.size(), vec1.size());
  EXPECT_EQ(v1.capacity(), vec1.capacity());
}

TEST(TestVectorModifiers, TestOfModifierSwap3) {
  s21::vector<char> v{'a', 'b', 'c'};
  s21::vector<char> v1{'d', 'e'};
  std::vector<char> vec{'a', 'b', 'c'};
  std::vector<char> vec1{'d', 'e'};

  v1.swap(v);
  vec1.swap(vec);

  EXPECT_EQ(v.size(), vec.size());
  EXPECT_EQ(v.capacity(), vec.capacity());
  EXPECT_EQ(v1.size(), vec1.size());
  EXPECT_EQ(v1.capacity(), vec1.capacity());
}

TEST(TestVectorInsertMany, TestOfInsertMany) {
  s21::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> vec = {5, 6, 7};
  vec.insert_many(vec.begin(), 1, 2, 3, 4);
  for (int i = 0; i < 4; i++) {
    EXPECT_EQ(v[i], vec[i]);
  }
}

TEST(TestVectorInsertMany, TestOfInsertMany1) {
  s21::vector<double> v = {1.1, 2.2, 3.3, 4.4};
  s21::vector<double> vec = {1.1, 3.3, 4.4};
  vec.insert_many(vec.begin() + 1, 2.2);
  for (int i = 0; i < 4; i++) {
    EXPECT_EQ(v[i], vec[i]);
  }
}
/*аналогично для типа дабл*/

TEST(TestVectorInsertMany, TestOfInserManyBack) {
  s21::vector<char> v{'a', 'b', 'c', 'd'};
  s21::vector<char> vec{'a'};
  vec.insert_many_back('b', 'c', 'd');
  for (int i = 0; i < 4; i++) {
    EXPECT_EQ(v[i], vec[i]);
  }
}
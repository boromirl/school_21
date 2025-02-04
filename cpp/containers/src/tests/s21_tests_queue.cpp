#include "s21_tests_main.h"

// тестируем дефолтный конструктор для разных типов данных

TEST(TestOfQueueConstructor, TestOfDefaultConstructor1) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestOfQueueConstructor, TestOfDefaultConstructor2) {
  s21::queue<double> s21_queue;
  std::queue<double> std_queue;
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestOfQueueConstructor, TestOfDefaultConstructor3) {
  s21::queue<char> s21_queue;
  std::queue<char> std_queue;
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestOfQueueConstructor, TestOfDefaultConstructor4) {
  s21::queue<std::string> s21_queue;
  std::queue<std::string> std_queue;
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

// тестируем конструктор со списком инициализации
TEST(TestOfQueueConstructor, TestOfIntializerList1) {
  s21::queue<int> s21_queue{1, 2, 3, 4, 5};
  std::queue<int> std_queue(std::deque<int>{
      1, 2, 3, 4,
      5});  // здесь приходится выходить из ситуации именно таким образом, с
            // помощью deque (двухсторонней учереди), так как использовать лист
            // инициализации напрямую очередь в базовой реализации не позволяет
  EXPECT_EQ(s21_queue.front(), 1);
  EXPECT_EQ(s21_queue.back(), 5);
  EXPECT_EQ(s21_queue.size(), 5);
  EXPECT_EQ(s21_queue.empty(), false);
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestOfQueueConstructor, TestOfIntializerList2) {
  s21::queue<double> s21_queue{1.1, 2.2, 3.3, 4.4, 5.5};
  std::queue<double> std_queue(std::deque<double>{1.1, 2.2, 3.3, 4.4, 5.5});
  EXPECT_EQ(s21_queue.front(), 1.1);
  EXPECT_EQ(s21_queue.back(), 5.5);
  EXPECT_EQ(s21_queue.size(), 5);
  EXPECT_EQ(s21_queue.empty(), false);
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestOfQueueConstructor, TestOfIntializerList3) {
  s21::queue<char> s21_queue{'a', 'b', 'c', 'd', 'e'};
  std::queue<char> std_queue(std::deque<char>{'a', 'b', 'c', 'd', 'e'});
  EXPECT_EQ(s21_queue.front(), 'a');
  EXPECT_EQ(s21_queue.back(), 'e');
  EXPECT_EQ(s21_queue.size(), 5);
  EXPECT_EQ(s21_queue.empty(), false);
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestOfQueueConstructor, TestOfIntializerList4) {
  s21::queue<std::string> s21_queue{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};
  std::queue<std::string> std_queue(
      std::deque<std::string>{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"});
  EXPECT_EQ(s21_queue.front(), "aaA1");
  EXPECT_EQ(s21_queue.back(), "eeE5");
  EXPECT_EQ(s21_queue.size(), 5);
  EXPECT_EQ(s21_queue.empty(), false);
  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

// тестируем конструктор копирования
TEST(TestOfQueueConstructor, TestOfCopyConstructor1) {
  s21::queue<int> s21_queue{1, 2, 3, 4, 5};
  s21::queue<int> s21_queue_copy = s21_queue;

  for (int i = 0; i < 5;
       i++) {  // i здесь это просто счетчик итераций, к индексу или количеству
               // элементов в очереди он не имеет никакого отношения
    EXPECT_EQ(s21_queue.front(), s21_queue_copy.front());
    EXPECT_EQ(s21_queue.back(), s21_queue_copy.back());
    EXPECT_EQ(s21_queue.size(), s21_queue_copy.size());
    EXPECT_EQ(s21_queue.empty(), s21_queue_copy.empty());
    s21_queue.pop(),
        s21_queue_copy.pop();  // при каждой итерации удаляем очередной элемент
                               // из начала очереди
  }
}

TEST(TestOfQueueConstructor, TestOfCopyConstructor2) {
  s21::queue<double> s21_queue{1.1, 2.2, 3.3, 4.4, 5.5};
  s21::queue<double> s21_queue_copy = s21_queue;

  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(s21_queue.front(), s21_queue_copy.front());
    EXPECT_EQ(s21_queue.back(), s21_queue_copy.back());
    EXPECT_EQ(s21_queue.size(), s21_queue_copy.size());
    EXPECT_EQ(s21_queue.empty(), s21_queue_copy.empty());
    s21_queue.pop(), s21_queue_copy.pop();
  }
}

TEST(TestOfQueueConstructor, TestOfCopyConstructor3) {
  s21::queue<char> s21_queue{'a', 'b', 'c', 'd', 'e'};
  s21::queue<char> s21_queue_copy = s21_queue;

  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(s21_queue.front(), s21_queue_copy.front());
    EXPECT_EQ(s21_queue.back(), s21_queue_copy.back());
    EXPECT_EQ(s21_queue.size(), s21_queue_copy.size());
    EXPECT_EQ(s21_queue.empty(), s21_queue_copy.empty());
    s21_queue.pop(), s21_queue_copy.pop();
  }
}

TEST(TestOfQueueConstructor, TestOfCopyConstructor4) {
  s21::queue<std::string> s21_queue{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};
  s21::queue<std::string> s21_queue_copy = s21_queue;

  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(s21_queue.front(), s21_queue_copy.front());
    EXPECT_EQ(s21_queue.back(), s21_queue_copy.back());
    EXPECT_EQ(s21_queue.size(), s21_queue_copy.size());
    EXPECT_EQ(s21_queue.empty(), s21_queue_copy.empty());
    s21_queue.pop(), s21_queue_copy.pop();
  }
}

// тестируем конструктор перемещения
TEST(TestOfQueueConstructor, TestOfMoveConstructor1) {
  s21::queue<int> s21_queue{1, 2, 3, 4, 5};
  s21::queue<int> s21_queue_1 =
      std::move(s21_queue);  // сюда мы передадим первую очередь
  s21::queue<int> s21_queue_2{1, 2, 3, 4, 5};  // а это для проверки

  EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
  EXPECT_EQ(s21_queue.size(), 0);
  EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
  EXPECT_EQ(s21_queue_1.back(), s21_queue_2.back());
  EXPECT_EQ(s21_queue.empty(), true);

  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
    EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
    s21_queue_1.pop(), s21_queue_2.pop();
  }
}

TEST(TestOfQueueConstructor, TestOfMoveConstructor2) {
  s21::queue<double> s21_queue{1.1, 2.2, 3.3, 4.4, 5.5};
  s21::queue<double> s21_queue_1 = std::move(s21_queue);
  s21::queue<double> s21_queue_2{1.1, 2.2, 3.3, 4.4, 5.5};

  EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
  EXPECT_EQ(s21_queue.size(), 0);
  EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
  EXPECT_EQ(s21_queue_1.back(), s21_queue_2.back());
  EXPECT_EQ(s21_queue.empty(), true);

  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
    EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
    s21_queue_1.pop(), s21_queue_2.pop();
  }
}

TEST(TestOfQueueConstructor, TestOfMoveConstructor3) {
  s21::queue<char> s21_queue{'a', 'b', 'c', 'd', 'e'};
  s21::queue<char> s21_queue_1 = std::move(s21_queue);
  s21::queue<char> s21_queue_2{'a', 'b', 'c', 'd', 'e'};

  EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
  EXPECT_EQ(s21_queue.size(), 0);
  EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
  EXPECT_EQ(s21_queue_1.back(), s21_queue_2.back());
  EXPECT_EQ(s21_queue.empty(), true);

  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
    EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
    s21_queue_1.pop(), s21_queue_2.pop();
  }
}

TEST(TestOfQueueConstructor, TestOfMoveConstructor4) {
  s21::queue<std::string> s21_queue{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};
  s21::queue<std::string> s21_queue_1 = std::move(s21_queue);
  s21::queue<std::string> s21_queue_2{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};

  EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
  EXPECT_EQ(s21_queue.size(), 0);
  EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
  EXPECT_EQ(s21_queue_1.back(), s21_queue_2.back());
  EXPECT_EQ(s21_queue.empty(), true);

  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
    EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
    s21_queue_1.pop(), s21_queue_2.pop();
  }
}

// тестируем оператор присваивания перемещением
TEST(TestOfOperator, TestOfAssignmentOperator1) {
  s21::queue<int> s21_queue{1, 2, 3, 4, 5};
  s21::queue<int> s21_queue_1{6, 7, 8, 9};

  s21_queue_1 = std::move(s21_queue);

  EXPECT_EQ(s21_queue_1.front(), 1);
  EXPECT_EQ(s21_queue_1.back(), 5);
  EXPECT_EQ(s21_queue_1.size(), 5);
  EXPECT_EQ(s21_queue_1.empty(), false);

  EXPECT_EQ(s21_queue.size(), 0);
  EXPECT_EQ(s21_queue.empty(), true);
}

TEST(TestOfOperator, TestOfAssignmentOperator2) {
  s21::queue<double> s21_queue{1.1, 2.2, 3.3, 4.4, 5.5};
  s21::queue<double> s21_queue_1{6.6, 7.7, 8.8, 9.9};

  s21_queue_1 = std::move(s21_queue);

  EXPECT_EQ(s21_queue_1.front(), 1.1);
  EXPECT_EQ(s21_queue_1.back(), 5.5);
  EXPECT_EQ(s21_queue_1.size(), 5);
  EXPECT_EQ(s21_queue_1.empty(), false);

  EXPECT_EQ(s21_queue.size(), 0);
  EXPECT_EQ(s21_queue.empty(), true);
}

TEST(TestOfOperator, TestOfAssignmentOperator3) {
  s21::queue<char> s21_queue{'a', 'b', 'c', 'd', 'e'};
  s21::queue<char> s21_queue_1{'f', 'g', 'h', 'i'};

  s21_queue_1 = std::move(s21_queue);

  EXPECT_EQ(s21_queue_1.front(), 'a');
  EXPECT_EQ(s21_queue_1.back(), 'e');
  EXPECT_EQ(s21_queue_1.size(), 5);
  EXPECT_EQ(s21_queue_1.empty(), false);

  EXPECT_EQ(s21_queue.size(), 0);
  EXPECT_EQ(s21_queue.empty(), true);
}

TEST(TestOfOperator, TestOfAssignmentOperator4) {
  s21::queue<std::string> s21_queue{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};
  s21::queue<std::string> s21_queue_1{"ffF6", "Ggg7", "hHh8", "iIi9"};

  s21_queue_1 = std::move(s21_queue);

  EXPECT_EQ(s21_queue_1.front(), "aaA1");
  EXPECT_EQ(s21_queue_1.back(), "eeE5");
  EXPECT_EQ(s21_queue_1.size(), 5);
  EXPECT_EQ(s21_queue_1.empty(), false);

  EXPECT_EQ(s21_queue.size(), 0);
  EXPECT_EQ(s21_queue.empty(), true);
}

// тестируем метод вставки в конец очереди
TEST(TestOfModifiers, TestOfPushModifier1) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;

  s21_queue.push(1);
  s21_queue.push(2);
  std_queue.push(1);
  std_queue.push(2);

  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestOfModifiers, TestOfPushModifier2) {
  s21::queue<double> s21_queue;
  std::queue<double> std_queue;

  s21_queue.push(1.1);
  s21_queue.push(2.2);
  std_queue.push(1.1);
  std_queue.push(2.2);

  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestOfModifiers, TestOfPushModifier3) {
  s21::queue<char> s21_queue;
  std::queue<char> std_queue;

  s21_queue.push('a');
  s21_queue.push('b');
  std_queue.push('a');
  std_queue.push('b');

  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestOfModifiers, TestOfPushModifier4) {
  s21::queue<std::string> s21_queue;
  std::queue<std::string> std_queue;

  s21_queue.push("aaA5");
  s21_queue.push("bBb5");
  std_queue.push("aaA5");
  std_queue.push("bBb5");

  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

// тестируем метод удаления элемента из начала очереди

TEST(TestOfModifiers, TestOfPopModifier1) {
  s21::queue<int> s21_queue;
  std::queue<int> std_queue;

  s21_queue.push(1);
  s21_queue.push(2);
  std_queue.push(1);
  std_queue.push(2);

  s21_queue.pop();
  std_queue.pop();

  s21_queue.push(3);
  std_queue.push(3);

  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestOfModifiers, TestOfPopModifier2) {
  s21::queue<double> s21_queue;
  std::queue<double> std_queue;

  s21_queue.push(1.1);
  s21_queue.push(2.2);
  std_queue.push(1.1);
  std_queue.push(2.2);

  s21_queue.pop();
  std_queue.pop();

  s21_queue.push(3.3);
  std_queue.push(3.3);

  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestOfModifiers, TestOfPopModifier3) {
  s21::queue<char> s21_queue;
  std::queue<char> std_queue;

  s21_queue.push('a');
  s21_queue.push('b');
  std_queue.push('a');
  std_queue.push('b');

  s21_queue.pop();
  std_queue.pop();

  s21_queue.push('c');
  std_queue.push('c');

  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

TEST(TestOfModifiers, TestOfPopModifier4) {
  s21::queue<std::string> s21_queue;
  std::queue<std::string> std_queue;

  s21_queue.push("Aaa1");
  s21_queue.push("bBb2");
  std_queue.push("Aaa1");
  std_queue.push("bBb2");

  s21_queue.pop();
  std_queue.pop();

  s21_queue.push("ccC3");
  std_queue.push("ccC3");

  EXPECT_EQ(s21_queue.front(), std_queue.front());
  EXPECT_EQ(s21_queue.back(), std_queue.back());
  EXPECT_EQ(s21_queue.size(), std_queue.size());
  EXPECT_EQ(s21_queue.empty(), std_queue.empty());
}

// тестируем метод замены содержимого

TEST(TestOfModifiers, TestOfSwapModifier1) {
  s21::queue<int> s21_queue{1, 2, 3, 4, 5};
  s21::queue<int> s21_queue_1{6, 7, 8, 9};
  s21::queue<int> s21_queue_2{1, 2, 3, 4, 5};
  s21::queue<int> s21_queue_3{6, 7, 8, 9};

  s21_queue.swap(s21_queue_1);

  EXPECT_EQ(s21_queue.front(), s21_queue_3.front());
  EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
  EXPECT_EQ(s21_queue.back(), s21_queue_3.back());
  EXPECT_EQ(s21_queue_1.back(), s21_queue_2.back());
  EXPECT_EQ(s21_queue.size(), s21_queue_3.size());
  EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
  EXPECT_EQ(s21_queue.empty(), s21_queue_3.empty());
  EXPECT_EQ(s21_queue_1.empty(), s21_queue_2.empty());

  for (auto i = 0u; i < s21_queue.size();
       i++) {  // 0u т.к. размер size имеет тип long unsigned int - чтобы не
               // было конфликта типов между i и size при компиляции
    EXPECT_EQ(s21_queue.front(), s21_queue_3.front());
    EXPECT_EQ(s21_queue.size(), s21_queue_3.size());
    s21_queue.pop();
    s21_queue_3.pop();
  }

  for (auto i = 0u; i < s21_queue_1.size(); i++) {
    EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
    EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
    s21_queue_1.pop();
    s21_queue_2.pop();
  }
}

TEST(TestOfModifiers, TestOfSwapModifier2) {
  s21::queue<double> s21_queue{1.1, 2.2, 3.3, 4.4, 5.5};
  s21::queue<double> s21_queue_1{6.6, 7.7, 8.8, 9.9};
  s21::queue<double> s21_queue_2{1.1, 2.2, 3.3, 4.4, 5.5};
  s21::queue<double> s21_queue_3{6.6, 7.7, 8.8, 9.9};

  s21_queue.swap(s21_queue_1);

  EXPECT_EQ(s21_queue.front(), s21_queue_3.front());
  EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
  EXPECT_EQ(s21_queue.back(), s21_queue_3.back());
  EXPECT_EQ(s21_queue_1.back(), s21_queue_2.back());
  EXPECT_EQ(s21_queue.size(), s21_queue_3.size());
  EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
  EXPECT_EQ(s21_queue.empty(), s21_queue_3.empty());
  EXPECT_EQ(s21_queue_1.empty(), s21_queue_2.empty());

  for (auto i = 0u; i < s21_queue.size(); i++) {
    EXPECT_EQ(s21_queue.front(), s21_queue_3.front());
    EXPECT_EQ(s21_queue.size(), s21_queue_3.size());
    s21_queue.pop();
    s21_queue_3.pop();
  }

  for (auto i = 0u; i < s21_queue_1.size(); i++) {
    EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
    EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
    s21_queue_1.pop();
    s21_queue_2.pop();
  }
}

TEST(TestOfModifiers, TestOfSwapModifier3) {
  s21::queue<char> s21_queue{'a', 'b', 'c', 'd', 'e'};
  s21::queue<char> s21_queue_1{'f', 'g', 'h', 'i'};
  s21::queue<char> s21_queue_2{'a', 'b', 'c', 'd', 'e'};
  s21::queue<char> s21_queue_3{'f', 'g', 'h', 'i'};

  s21_queue.swap(s21_queue_1);

  EXPECT_EQ(s21_queue.front(), s21_queue_3.front());
  EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
  EXPECT_EQ(s21_queue.back(), s21_queue_3.back());
  EXPECT_EQ(s21_queue_1.back(), s21_queue_2.back());
  EXPECT_EQ(s21_queue.size(), s21_queue_3.size());
  EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
  EXPECT_EQ(s21_queue.empty(), s21_queue_3.empty());
  EXPECT_EQ(s21_queue_1.empty(), s21_queue_2.empty());

  for (auto i = 0u; i < s21_queue.size(); i++) {
    EXPECT_EQ(s21_queue.front(), s21_queue_3.front());
    EXPECT_EQ(s21_queue.size(), s21_queue_3.size());
    s21_queue.pop();
    s21_queue_3.pop();
  }

  for (auto i = 0u; i < s21_queue_1.size(); i++) {
    EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
    EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
    s21_queue_1.pop();
    s21_queue_2.pop();
  }
}

TEST(TestOfModifiers, TestOfSwapModifier4) {
  s21::queue<std::string> s21_queue{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};
  s21::queue<std::string> s21_queue_1{"ffF6", "Ggg7", "hHh8", "iIi9"};
  s21::queue<std::string> s21_queue_2{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};
  s21::queue<std::string> s21_queue_3{"ffF6", "Ggg7", "hHh8", "iIi9"};

  s21_queue.swap(s21_queue_1);

  EXPECT_EQ(s21_queue.front(), s21_queue_3.front());
  EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
  EXPECT_EQ(s21_queue.back(), s21_queue_3.back());
  EXPECT_EQ(s21_queue_1.back(), s21_queue_2.back());
  EXPECT_EQ(s21_queue.size(), s21_queue_3.size());
  EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
  EXPECT_EQ(s21_queue.empty(), s21_queue_3.empty());
  EXPECT_EQ(s21_queue_1.empty(), s21_queue_2.empty());

  for (auto i = 0u; i < s21_queue.size(); i++) {
    EXPECT_EQ(s21_queue.front(), s21_queue_3.front());
    EXPECT_EQ(s21_queue.size(), s21_queue_3.size());
    s21_queue.pop();
    s21_queue_3.pop();
  }

  for (auto i = 0u; i < s21_queue_1.size(); i++) {
    EXPECT_EQ(s21_queue_1.front(), s21_queue_2.front());
    EXPECT_EQ(s21_queue_1.size(), s21_queue_2.size());
    s21_queue_1.pop();
    s21_queue_2.pop();
  }
}

// проверим вставку многих элементов
TEST(TestOfModifiers, TestOfInsertManyBackModifier1) {
  s21::queue<int> s21_queue{1, 2, 3};
  s21::queue<int> s21_queue_1{1, 2, 3, 4, 5};

  s21_queue.insert_many_back(4, 5);

  for (auto i = 0u; i < s21_queue.size(); i++) {
    EXPECT_EQ(s21_queue.front(), s21_queue_1.front());
    s21_queue.pop();
    s21_queue_1.pop();
  }
}

TEST(TestOfModifiers, TestOfInsertManyBackModifier2) {
  s21::queue<double> s21_queue{1.1, 2.2, 3.3};
  s21::queue<double> s21_queue_1{1.1, 2.2, 3.3, 4.4, 5.5};

  s21_queue.insert_many_back(4, 5);

  for (auto i = 0u; i < s21_queue.size(); i++) {
    EXPECT_EQ(s21_queue.front(), s21_queue_1.front());
    s21_queue.pop();
    s21_queue_1.pop();
  }
}

TEST(TestOfModifiers, TestOfInsertManyBackModifier3) {
  s21::queue<char> s21_queue{'a', 'b', 'c'};
  s21::queue<char> s21_queue_1{'a', 'b', 'c', 'd', 'e'};

  s21_queue.insert_many_back(4, 5);

  for (auto i = 0u; i < s21_queue.size(); i++) {
    EXPECT_EQ(s21_queue.front(), s21_queue_1.front());
    s21_queue.pop();
    s21_queue_1.pop();
  }
}

TEST(TestOfModifiers, TestOfInsertManyBackModifier4) {
  s21::queue<std::string> s21_queue{"aaA1", "bBb2", "Ccc3"};
  s21::queue<std::string> s21_queue_1{"aaA1", "bBb2", "Ccc3", "ddD4", "eeE5"};

  s21_queue.insert_many_back(4, 5);

  for (auto i = 0u; i < s21_queue.size(); i++) {
    EXPECT_EQ(s21_queue.front(), s21_queue_1.front());
    s21_queue.pop();
    s21_queue_1.pop();
  }
}

// протестируем выброс исключений
TEST(TestOfExceptions, TestOfFrontException) {
  s21::queue<int> s21_queue;
  EXPECT_THROW(s21_queue.front(), std::out_of_range);
}

TEST(TestOfExceptions, TestOfBackException) {
  s21::queue<double> s21_queue;
  EXPECT_THROW(s21_queue.back(), std::out_of_range);
}

TEST(TestOfExceptions, TestOfPopException) {
  s21::queue<char> s21_queue;
  EXPECT_THROW(s21_queue.pop(), std::out_of_range);
}
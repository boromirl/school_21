#ifndef S21_BINARY_TREE
#define S21_BINARY_TREE

#include "../stack/s21_stack.h"

namespace s21 {
// красно-черное дерево
template <typename Key, typename T, bool isMap = false>
class BinaryTree {
 private:
  class BinaryTreeIterator;
  class BinaryTreeConstIterator;

 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;

  using iterator = BinaryTreeIterator;
  using const_iterator = BinaryTreeConstIterator;

 private:
  struct Node {       // это структура узла дерева
    value_type data;  // данные
    Node *left;  // указатели на левого, правого ребенка и родителя
    Node *right;
    Node *parent;
    int color;  // 0 - черный, 1 - красный

    // default constructor
    Node()
        : data(std::make_pair(key_type(), mapped_type())),
          left(nullptr),
          right(nullptr),
          parent(nullptr),
          color(0) {}

    Node(value_type value)
        : data(value),
          left(nullptr),
          right(nullptr),
          parent(nullptr),
          color(0) {
    }  // конструктор для ноды с данными, но еще непривязанной к дереву
    // конструктор со всеми значениями
    Node(value_type value, Node *left_child, Node *right_child,
         Node *parent_node, int clr)
        : data(value),
          left(left_child),
          right(right_child),
          parent(parent_node),
          color(clr) {}
  };

  Node *root;  // это указатель на кореь дерева
  Node *
      TNULL;  // NULL нода, на которую ссылаются все ноды, которым нужен nullptr
  size_type size_;  // размер дерева
  bool is_unique;  // для multiset значение false, для других - true

  class BinaryTreeIterator {
   public:
    friend class BinaryTree;
    // конструкторы
    BinaryTreeIterator()
        : current(nullptr) {}  // конструктор итератора по умолчанию
    explicit BinaryTreeIterator(Node *ptr, BinaryTree *parent_tree)
        : current(ptr), tree(parent_tree) {};  // конструктор с параметрами
    BinaryTreeIterator(const BinaryTreeIterator &other)
        : current(other.current),
          tree(other.tree) {};  // конструктор копирования
    BinaryTreeIterator(BinaryTreeIterator &&other) noexcept
        : current(other.current), tree(other.tree) {
      other.current = nullptr;  // конструкто перемещения
    }

    BinaryTreeIterator &operator=(const BinaryTreeIterator &other) {
      if (*this != other) {
        current = other.current;
      }
      return *this;
    }  // оператор присваивания

    auto &operator*() {
      if constexpr (isMap) {
        return current->data;
      } else {
        return current->data.first;
      }
    }  // вспомогательный оператор разыменования, работает на стадии компиляции,
       // чтобы показать комплиятору работает ли он с сетом/мультисетом или
       // словарем

    bool operator==(const BinaryTreeIterator &other) const {
      return (current == other.current);
    }  // оператор сравенеия двух итераторов на равенство
    bool operator!=(const BinaryTreeIterator &other) const {
      return !(*this == other);
    }  // оператор сравнения двух итераторов на неравенство

    BinaryTreeIterator &operator++() {
      if (current == tree->TNULL) {
        current = tree->minimum(tree->root);
        return *this;
      }

      // если у ноды есть правый потомок, то следующим всегда будет минимальный
      // потомок справа
      if (current->right != tree->TNULL) {
        current = tree->minimum(current->right);
      } else {
        // если правого потомка нет, то следующим будет ближайший больший
        // родитель
        Node *parent = current->parent;
        while (parent != tree->TNULL && current == parent->right) {
          current = parent;
          parent = parent->parent;
        }
        current = parent;
      }

      return *this;
    }  // префиксный оператор инкрементации

    BinaryTreeIterator operator++(int) {
      // чтобы отличать постфикс от префикс
      BinaryTreeIterator copy = *this;  // в отличие от префикс оператора
                                        // возвращает копию до изменения
      ++(*this);
      return copy;
    }  // постфиксный оператор инкрементации

    BinaryTreeIterator &operator--() {
      if (current == tree->TNULL) {
        current = tree->maximum(tree->root);
        return *this;
      }

      // если у ноды есть левый потомок, то предыдущим всегда будет максимальный
      // потомок слева
      if (current->left != tree->TNULL) {
        current = tree->maximum(current->left);
      } else {
        // если левого потомка нет, то предыдущим будет ближайший меньший
        // родитель
        Node *parent = current->parent;
        while (parent != tree->TNULL && current == parent->left) {
          current = parent;
          parent = parent->parent;
        }
        current = parent;
      }

      return *this;
    }  // префиксный оператор декрементации

    BinaryTreeIterator operator--(int) {  // чтобы отличать постфикс от префикс
      BinaryTreeIterator copy = *this;  // в отличие от префикс оператора
                                        // возвращает копию до изменения
      --(*this);
      return copy;
    }  // постфиксный оператор декрементации

   private:
    Node *current;     // указатель на ноду
    BinaryTree *tree;  // указатель на дерево
  };

  class BinaryTreeConstIterator {  // здесь аналогично предыдущему, только
                                   // итератор константный
   public:
    // конструкторы
    BinaryTreeConstIterator() : current(nullptr) {}
    explicit BinaryTreeConstIterator(Node *ptr, BinaryTree *parent_tree)
        : current(ptr), tree(parent_tree) {};
    BinaryTreeConstIterator(const BinaryTreeConstIterator &other)
        : current(other.current), tree(other.tree) {};
    BinaryTreeConstIterator(BinaryTreeConstIterator &&other) noexcept
        : current(other.current), tree(other.tree) {
      other.current = nullptr;
    }

    BinaryTreeConstIterator &operator=(const BinaryTreeConstIterator &other) {
      if (*this != other) {
        current = other.current;
      }
      return *this;
    }

    auto &operator*() const {
      if constexpr (isMap) {
        return current->data;
      } else {
        return current->data.first;
      }
    }

    bool operator==(const BinaryTreeConstIterator &other) const {
      return (current == other.current);
    }

    bool operator!=(const BinaryTreeConstIterator &other) const {
      return !(*this == other);
    }

    BinaryTreeConstIterator &operator++() {
      if (current == tree->TNULL) {
        current = tree->minimum(tree->root);
        return *this;
      }

      // если у ноды есть правый потомок, то следующим всегда будет минимальный
      // потомок справа
      if (current->right != tree->TNULL) {
        current = tree->minimum(current->right);
      } else {
        // если правого потомка нет, то следующим будет ближайший больший
        // родитель
        Node *parent = current->parent;
        while (parent != tree->TNULL && current == parent->right) {
          current = parent;
          parent = parent->parent;
        }
        current = parent;
      }

      return *this;
    }

    BinaryTreeConstIterator operator++(
        int) {  // int параметр нужен исключительного для того,
      // чтобы отличать постфикс от префикс
      BinaryTreeConstIterator copy = *this;  // в отличие от префикс оператора
                                             // возвращает копию до изменения
      ++(*this);
      return copy;
    }

    BinaryTreeConstIterator &operator--() {
      if (current == tree->TNULL) {
        current = tree->maximum(tree->root);
        return *this;
      }

      // если у ноды есть левый потомок, то предыдущим всегда будет максимальный
      // потомок слева
      if (current->left != tree->TNULL) {
        current = tree->maximum(current->left);
      } else {
        // если левого потомка нет, то предыдущим будет ближайший меньший
        // родитель
        Node *parent = current->parent;
        while (parent != tree->TNULL && current == parent->left) {
          current = parent;
          parent = parent->parent;
        }
        current = parent;
      }

      return *this;
    }

    BinaryTreeConstIterator operator--(
        int) {  // int параметр нужен исключительного для того,
      // чтобы отличать постфикс от префикс
      BinaryTreeConstIterator copy = *this;  // в отличие от префикс оператора
                                             // возвращает копию до изменения
      --(*this);
      return copy;
    }

   private:
    Node *current;
    BinaryTree *tree;
  };

 public:
  // default constructor
  BinaryTree() {
    this->TNULL = new Node(value_type(), nullptr, nullptr, nullptr, 0);
    this->root = TNULL;
    this->size_ = 0;
    this->is_unique = true;
  }

  BinaryTree(bool unique) : BinaryTree() {
    this->is_unique = unique;
  }  // конструктор с параметром, заодно проверяет работает контейнер с
     // уникальными элементами или допускает повторение

  BinaryTree(std::initializer_list<Key> const &items) : BinaryTree() {
    for (auto item : items) {
      insert(item);
    }
  }  // конструктор с использованием списка инициализациии

  BinaryTree(const BinaryTree &other) : BinaryTree() {
    this->root = copyTree(other.root, TNULL);
    this->size_ = other.size_;
    this->is_unique = other.is_unique;
  }  // конструктор копирования

  BinaryTree(BinaryTree &&other) : BinaryTree() {
    this->root = other.root;
    delete this->TNULL;
    this->TNULL = other.TNULL;
    this->size_ = other.size_;
    this->is_unique = other.is_unique;

    other.size_ = 0;
    other.TNULL = new Node(value_type(), nullptr, nullptr, nullptr, 0);
    other.root = other.TNULL;
  }  // конструктор перемещения

  BinaryTree &operator=(BinaryTree &&other) {
    if (&other != this) {
      this->root = other.root;
      delete this->TNULL;
      this->TNULL = other.TNULL;
      this->size_ = other.size_;
      this->is_unique = other.is_unique;

      other.size_ = 0;
      other.TNULL = new Node(value_type(), nullptr, nullptr, nullptr, 0);
      other.root = other.TNULL;
    }
    return *this;
  }  // оператор присваивания перемещением

  // destructor
  ~BinaryTree() {
    clear();
    delete TNULL;
  }

  // возвращает пару: итератор, указывающий на новый элемент, и bool,
  // указывающий произошла ли вставка(или елемент уже был)
  std::pair<iterator, bool> insert(value_type value) {
    // если нет корня, вставить корень
    if (root == TNULL) {
      root = new Node(value, TNULL, TNULL, TNULL, 0);  // корень всегда черный
      size_++;
      return std::make_pair(iterator(root, this), true);
    }

    // ищем куда вставить новую ноду
    Node *current = root;
    Node *parentNode = TNULL;
    while (current != TNULL) {
      parentNode = current;
      if (value.first < current->data.first) {
        // если value меньше, двигаемся влево
        current = current->left;
      } else if (value.first > current->data.first) {
        // если value больше, двигаемся вправо
        current = current->right;
      } else {
        // если ни больше, ни меньше, т.е. совпадает
        // не делаем ничего или, если это мультисет, добавляем повторяющийся
        // элемент
        if (this->is_unique == true) {
          return std::make_pair(iterator(current, this), false);
        } else {
          current = current->right;
        }
      }
    }

    // создаем ноду
    Node *newNode = new Node(value, TNULL, TNULL, TNULL, 1);
    newNode->parent = parentNode;
    if (parentNode->data.first > value.first) {
      parentNode->left = newNode;
    } else {
      parentNode->right = newNode;
    }
    this->size_++;

    // если родитель красный, то нарушается правило
    // (красные ноды не могут иметь потомков)
    if (newNode->parent->color == 1) {
      fixInsert(newNode);  // исправляем цвета
    }

    return std::make_pair(iterator(newNode, this), true);
  }  // вставка элемента в дерево

  template <typename... Args>
  void insert_many(Args &&...args) {
    (this->insert(std::forward<Args>(args)), ...);
  }  // вставка множества элементов в дерево

  // найти ноду с данным значением и вернуть указатель
  // если ноды нет в дереве - вернуть TNULL
  Node *search(key_type value) const {
    Node *current = root;

    while (current != TNULL) {
      if (value == current->data.first) {
        break;
      } else if (value > current->data.first) {
        current = current->right;
      } else {
        current = current->left;
      }
    }

    return current;
  }  // поиск ноды в дереве по значению

  iterator find(key_type value) {
    Node *node = search(value);
    return iterator(node, this);
  }  // поиск элемента в дереве

  const_iterator find(key_type value) const {
    Node *node = search(value);
    return const_iterator(node, this);
  }  // аналогично, но константные

  bool contains(key_type value) const {
    Node *node = search(value);
    return (node != TNULL);
  }  // проверка есть

  void deleteNode(iterator pos) {
    Node *node = pos.current;
    if (node == TNULL) {
      return;
    }

    Node *z = node;  // удаляемая нода
    Node *x;  // потомок z, которым будет заменена z
    Node *y;  // вспомогательная нода

    y = z;
    int y_original_color = y->color;  // сохраняем цвет удаляемой ноды для фикса
    // z имеет только правого потомка, тогда
    // заменяем им z
    if (z->left == TNULL) {
      x = z->right;
      transplant(z, z->right);
    }
    // z имеет только левого потомка, тогда
    // заменяем им z
    else if (z->right == TNULL) {
      x = z->left;
      transplant(z, z->left);
    }
    // z имеет двух потомков
    else {
      // тогда находим наследника z (наибольшую ноду слева,
      // самую правую ноду слева)
      y = maximum(z->left);
      y_original_color = y->color;  // цвет меняется, так как будет удален цвет
                                    // наследника, а не z
      x = y->left;
      // если найденный наследник является прямым потомком, обновляем родителя x
      if (y->parent == z) {
        x->parent = y;
      }
      // если наследника не прямой
      else {
        // заменяем наследника, его потомком
        transplant(y, y->left);
        // и забираем левого потомка у удаляемой ноды
        y->left = z->left;
        y->left->parent = y;
      }

      // подменяем удаляемую ноду на наследника
      transplant(z, y);
      // забираем у удаляемой ноды правого наследника
      y->right = z->right;
      y->right->parent = y;
      y->color = z->color;
    }
    delete z;
    size_--;
    // если удаляется черная нода, то может нарушиться черное правило, нужен
    // фикс
    if (y_original_color == 0) {
      fixDelete(x);
    }
  }  // удаление ноды

  // Левый поворот опускает current влево, а правый потомок current занимает его
  // место
  void rotateLeft(Node *current) {
    // edge case: current == nullptr или не имеет right
    if (current == TNULL || current->right == TNULL) return;

    Node *x = current;
    Node *y = x->right;

    // переносим левое субдерево y в правое субдерево x
    x->right = y->left;
    if (y->left != TNULL) {
      y->left->parent = x;
    }

    // обновляем предка x, чтобы он указывал на y
    Node *ancestor = x->parent;
    if (ancestor != TNULL) {
      if (ancestor->left == x) {
        ancestor->left = y;
      } else {
        ancestor->right = y;
      }
    }
    y->parent = ancestor;

    // обновляем указатели x и y
    x->parent = y;
    y->left = x;

    // в конце концов меняем поле root
    if (root == x) root = y;
  }

  // Правый поворот опускает current вправо, а левый потомок current занимает
  // его место
  void rotateRight(Node *current) {
    // edge case: current == nullptr или не имеет left
    if (current == TNULL || current->left == TNULL) return;

    Node *x = current;
    Node *y = x->left;

    // переносим левое субдерево y в правое субдерево x
    x->left = y->right;
    if (y->right != TNULL) {
      y->right->parent = x;
    }

    // обновляем предка x, чтобы он указывал на y
    Node *ancestor = x->parent;
    if (ancestor != TNULL) {
      if (ancestor->left == x) {
        ancestor->left = y;
      } else {
        ancestor->right = y;
      }
    }
    y->parent = ancestor;

    // обновляем указатели x и y
    x->parent = y;
    y->right = x;

    // в конце концов меняем поле root
    if (root == x) root = y;
  }

  size_type size() const { return this->size_; }  // возврат размера
  bool empty() const { return (this->size_ == 0); }  // проверка на пустоту

  // Находит минимальную ноду в поддереве
  Node *minimum(Node *current) const {
    while (current->left != TNULL) {
      current = current->left;
    }

    return current;
  }  // влево до упора - там минимальная нода

  // Находит максимальную ноду в поддереве
  Node *maximum(Node *current) const {
    while (current->right != TNULL) {
      current = current->right;
    }

    return current;
  }  // вправо до упора - там максимальная нода

  iterator begin() {
    if (this->size_ != 0) {
      return iterator(minimum(root), this);
    } else
      return iterator(TNULL, this);
  }  // итератор на первый элемент дерева

  iterator end() { return iterator(TNULL, this); }  // итератор на конец дерева

  const_iterator cbegin() {
    if (this->size_ != 0) {
      return const_iterator(minimum(root), this);
    } else
      return const_iterator(TNULL, this);
  }  // аналогично константный

  const_iterator cend() {
    return const_iterator(TNULL, this);
  }  // константный итератор на конец дерева

  void clear() {
    clearTree(root);
    root = TNULL;
    size_ = 0;
  }  // метод полной очистки дерева

  void merge(BinaryTree &other) {
    for (auto it = other.begin(); it != other.end();) {
      std::pair<iterator, bool> insert_result;
      if constexpr (isMap) {
        insert_result = this->insert(*it);
      } else {
        insert_result = this->insert(std::make_pair(*it, key_type()));
      }
      if (insert_result.second == true) {
        iterator temp(it);
        ++it;
        other.deleteNode(temp);
      } else {
        ++it;
      }
    }
  }  // слиянеие двух деревьев

 private:
  void clearTree(Node *root) {
    if (root == TNULL) return;

    s21::stack<Node *> stack;
    stack.push(root);

    while (!stack.empty()) {
      Node *node = stack.top();
      stack.pop();

      if (node->left != TNULL) stack.push(node->left);
      if (node->right != TNULL) stack.push(node->right);

      delete node;
    }
  }  // метод очистки дереве, начинаем с потомком и до корня

  // Трансплантация. Вспомогательный метод. Замещает одно поддерево другим
  // поддеревом, сохраняя при этом структуры и связи остальных узлов дерева
  void transplant(Node *first, Node *second) {
    if (first->parent == TNULL) {
      this->root = second;
    } else if (first->parent->right == first) {
      first->parent->right = second;
    } else {
      first->parent->left = second;
    }
    second->parent = first->parent;
  }

  // Исправление окрашивания после удаления
  void fixDelete(Node *node) {
    while (node != root && node->color == 0) {
      // если node - левый потомок
      if (node->parent->left == node) {
        Node *sibling = node->parent->right;

        // случай 1. sibling - красный
        // перекрасить родителя в красный, а sibling в черный,
        // а затем повернуть родителя влево
        if (sibling->color == 1) {
          node->parent->color = 1;
          sibling->color = 0;
          rotateLeft(node->parent);
          // sibling ноды меняется после поворота
          sibling = node->parent->right;
        }

        // случай 2. Оба потомка sibling - черные
        // перекрасить sibling в красный, а далее работать с родителем ноды
        // (переход на следующий этап цикла)
        if (sibling->right->color == 0 && sibling->left->color == 0) {
          sibling->color = 1;
          node = node->parent;
        }
        // случай 3. Правый потомок sibling - черный
        // поменять цвет левого потомка sibling на черный,
        // поменять цвет sibling на красный
        // повернуть sibling  направо
        else {
          if (sibling->right->color == 0) {
            sibling->left->color = 0;
            sibling->color = 1;
            rotateRight(sibling);

            // sibling ноды меняется после поворота
            sibling = node->parent->right;
          }
          // случай 4. Ничего из вышеперечисленного не подходит
          // Перекрасить sibling в цвет родителя
          // Перекрасить родителя в черный
          // Перекрасить правого потомка sibling в черный
          // Повернуть родителя ноды влево
          // а далее работать с корнем

          sibling->color = node->parent->color;
          node->parent->color = 0;
          sibling->right->color = 0;
          rotateLeft(node->parent);
          node = root;
        }
      }
      // если node - правый потомок
      else {
        Node *sibling = node->parent->left;

        // случай 1. sibling - красный
        // перекрасить родителя в красный, а sibling в черный,
        // а затем повернуть родителя вправо
        if (sibling->color == 1) {
          node->parent->color = 1;
          sibling->color = 0;
          rotateRight(node->parent);
          // sibling ноды меняется после поворота
          sibling = node->parent->left;
        }

        // случай 2. Оба потомка sibling - черные
        // перекрасить sibling в красный, а далее работать с родителем ноды
        // (переход на следующий этап цикла)
        if (sibling->right->color == 0 && sibling->left->color == 0) {
          sibling->color = 1;
          node = node->parent;
        }
        // случай 3. левый потомок sibling - черный
        // поменять цвет правого потомка sibling на черный,
        // поменять цвет sibling на красный
        // повернуть sibling налево
        else {
          if (sibling->left->color == 0) {
            sibling->right->color = 0;
            sibling->color = 1;
            rotateLeft(sibling);

            // sibling ноды меняется после поворота
            sibling = node->parent->left;
          }
          // случай 4. Ничего из вышеперечисленного не подходит
          // Перекрасить sibling в цвет родителя
          // Перекрасить родителя в черный
          // Перекрасить левого потомка sibling в черный
          // Повернуть родителя ноды вправо
          // а далее работать с корнем

          sibling->color = node->parent->color;
          node->parent->color = 0;
          sibling->left->color = 0;
          rotateRight(node->parent);
          node = root;
        }
      }
    }
    node->color = 0;
  }

  void fixInsert(Node *n) {
    // Случай 1: Родитель и дядя ноды - красные
    // перекрасить предка и дядю в черный, а дедушку в красный,
    // затем рекурсивно применить фикс к дедушке

    while (n != root && n->parent->color == 1) {
      // если родитель - левая нода, дядя - правая
      if (n->parent->parent->left == n->parent) {
        Node *uncle = n->parent->parent->right;
        // случай 1: И родитель и дядя красные
        if (uncle != TNULL && uncle->color == 1) {
          // перекрашиваем родителя и дядю в черный,
          // а дедушку в красный
          // затем проверяем дедушку на нарушения
          n->parent->color = 0;
          uncle->color = 0;
          n->parent->parent->color = 1;
          n = n->parent->parent;
        }
        // случай 2: родитель - красный, дядя - черный
        else {
          // если нода правый потомок, а родитель левый потомок
          // то нужно поменять местами ноду с родителем при помощи поворота
          // влево и работать дальше с нодой родителем таким образом мы сведем
          // все к ситуации, когда и нода и родитель являются левыми потомкам
          if (n->parent->right == n) {
            n = n->parent;
            rotateLeft(n);
          }
          // если и нода и родитель левые, то достаточно перекрасить дедушку в
          // красный, родителя в черный, а затем повернуть дедушку вправо, тем
          // самым родитель встанет на место дедушки
          n->parent->color = 0;
          n->parent->parent->color = 1;
          rotateRight(n->parent->parent);
        }
      }
      // иначе - родитель правая нода, дядя - левая
      else {
        Node *uncle = n->parent->parent->left;
        // случай 1: И родитель и дядя красные
        if (uncle != TNULL && uncle->color == 1) {
          // перекрашиваем родителя и дядю в черный,
          // а дедушку в красный
          // затем проверяем дедушку на нарушения
          n->parent->color = 0;
          uncle->color = 0;
          n->parent->parent->color = 1;
          n = n->parent->parent;
        }
        // случай 2: родитель - красный, дядя - черный
        else {
          // если нода левый потомок, а родитель правый потомок
          // то нужно поменять местами ноду с родителем при помощи поворота
          // впарво и работать дальше с нодой родителем таким образом мы сведем
          // все к ситуации, когда и нода и родитель являются правыми потомками
          if (n->parent->left == n) {
            n = n->parent;
            rotateRight(n);
          }
          // если и нода и родитель правые, то достаточно перекрасить дедушку в
          // красный, родителя в черный, а затем повернуть дедушку влево, тем
          // самым родитель встанет на место дедушки
          n->parent->color = 0;
          n->parent->parent->color = 1;
          rotateLeft(n->parent->parent);
        }
      }
    }
    // может случиться, что root будет перекрашен в красный
    // его нужно вернуть в черный
    // это перекрашивание не нарушит правил
    root->color = 0;
  }

  Node *copyTree(Node *otherRoot, Node *parent) {
    if (otherRoot->parent ==
        nullptr) {  // нельзя проверить на TNULL, так как нужен other.TNULL
      return TNULL;
    }

    Node *newNode = new Node(otherRoot->data, TNULL, TNULL, parent, 0);
    newNode->parent = parent;
    newNode->left = copyTree(otherRoot->left, newNode);
    newNode->right = copyTree(otherRoot->right, newNode);

    return newNode;
  }
};  // метод для копирования дерева/поддерева

}  // namespace s21

#endif
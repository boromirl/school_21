#ifndef S21_LIST_H
#define S21_LIST_H

namespace s21 {

template <typename T>
class list {
 private:
  class ListIterator;  // обычный и константый итераторы по листу
  class ListConstIterator;

 public:
  // ***    list member type    ***
  // - внутриклассовые переопределения типов -
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

 private:
  // структура для хранения элементов списка
  struct Node {
    T data;      // данные ноды
    Node *next;  // указатель на следующую ноду
    Node *prev;  // указатель на предыдущую

    Node()
        : data(T()),
          next(nullptr),
          prev(nullptr) {}  // конструктор ноды по умолчанию
    Node(T value)
        : data(value),
          next(nullptr),
          prev(nullptr) {
    }  // констуктор для создания ноды с данными, но без указателей
    Node(T value, Node *next, Node *prev)
        : data(value), next(next), prev(prev) {}  // конструктор с параметрами
  };

  Node *sentinel_head;  // псевдо нода, обозначает собой начало списка даже если
                        // список пуст
  Node *sentinel_tail;  // псевдо нода, обозначает собой конец списка даже если
                        // список пуст

  size_type size_;  // переменная - размер списка

  // внутренний клас итератора
  class ListIterator {
   public:
    using node_pointer = Node *;  // указатель на узел
    // теги (необязательные)
    using difference_type =
        std::ptrdiff_t;  // для хранения разности двух указателей
    using iterator_category =
        std::bidirectional_iterator_tag;  // указывает компилятору, что список
                                          // двусвязный, а значит итератор может
                                          // двигаться по нему вперед (++) и
                                          // назад (--)

    friend class list;  // дает возможность классу list работать с private
                        // итератора

    // конструкторы
    ListIterator()
        : current(nullptr) {}  // конструктор по умолчанию для итератора
    explicit ListIterator(node_pointer ptr)
        : current(ptr) {
          };  // конструктор с указателем на конкретную ноду, explicit - для
              // предоствращения неявного присваивания, чтобы случайно не
              // присвоить итератору данные ноды вместо указателя
    ListIterator(const ListIterator &other)
        : current(other.current) {};  // конструктор копирования
    ListIterator(ListIterator &&other) noexcept
        : current(other.current) {  // конструктор перемещения
      other.current = nullptr;
    }

    ListIterator &operator=(const ListIterator &other) {
      if (*this != other) {
        current = other.current;
      }
      return *this;
    }  // оператор присваивания

    // dereference operator
    reference operator*() { return current->data; }

    // prefix operator ++it
    ListIterator &operator++() {
      current = current->next;
      return *this;
    }

    // postfix operator it++
    ListIterator operator++(
        int) {  // int параметр нужен исключительного для того,
      // чтобы отличать постфикс от префикс
      ListIterator copy = *this;  // в отличие от префикс оператора возвращает
                                  // копию до изменения
      ++(*this);
      return copy;
    }

    // prefix operator --it
    ListIterator &operator--() {
      current = current->prev;
      return *this;
    }

    // postfix operator it--
    ListIterator operator--(
        int) {  // int параметр нужен исключительного для того,
      // чтобы отличать постфикс от префикс
      ListIterator copy = *this;  // в отличие от префикс оператора возвращает
                                  // копию до изменения
      --(*this);
      return copy;
    }

    bool operator==(const ListIterator &other) const {
      return (current == other.current);
    }  // оператор проверки равенства итераторов - т.е. что указывают на одну и
       // ту же ноду

    bool operator!=(const ListIterator &other) const {
      return !(*this == other);
    }  // проверка итераторов на неравенство

   private:
    node_pointer current;  // указатель на текущую Node
  };

  // внутренний класс const итератора
  class ListConstIterator {  // здесь аналогично предыдущему итератор, с той
                             // лишь разницей, что он константный, а значит
                             // может использоваться только для чтения
   public:
    using node_const_pointer = Node *;

    friend class list;

    ListConstIterator() : current(nullptr) {}
    explicit ListConstIterator(node_const_pointer const_ptr)
        : current(const_ptr) {};
    ListConstIterator(const ListConstIterator &other)
        : current(other.current) {};
    ListConstIterator(ListConstIterator &&other) noexcept
        : current(other.current) {
      other.current = nullptr;
    }
    ListConstIterator(const ListIterator &it)
        : current(it.current) {}  // конвертация из обычного в конст итератор

    ListConstIterator &operator=(const ListConstIterator &other) {
      if (*this != other) {
        current = other.current;
      }
      return *this;
    }

    // dereference operator
    const_reference operator*() const { return current->data; }

    // prefix operator ++it
    ListConstIterator &operator++() {
      current = current->next;
      return *this;
    }

    // postfix operator it++
    ListConstIterator operator++(
        int) {  // int параметр нужен исключительного для того,
      // чтобы отличать постфикс от префикс
      ListConstIterator copy = *this;  // в отличие от префикс оператора
                                       // возвращает копию до изменения
      ++(*this);
      return copy;
    }

    // prefix operator --it
    ListConstIterator &operator--() {
      current = current->prev;
      return *this;
    }

    // postfix operator it--
    ListConstIterator operator--(
        int) {  // int параметр нужен исключительного для того,
      // чтобы отличать постфикс от префикс
      ListConstIterator copy = *this;  // в отличие от префикс оператора
                                       // возвращает копию до изменения
      --(*this);
      return copy;
    }

    bool operator==(const ListConstIterator &other) const {
      return (current == other.current);
    }

    bool operator!=(const ListConstIterator &other) const {
      return !(*this == other);
    }

   private:
    node_const_pointer current;  // указатель на текущую Node
  };

 public:
  // ***    list member functions    ***
  // - публичные методы для взаимоействия с классом -

  // конструкторы
  list() : size_(0) {
    sentinel_head = new Node(
        T(), nullptr,
        nullptr);  // это две мнимых ноды - они обозначают начало и конец списка
    sentinel_tail = new Node(T(), nullptr, nullptr);

    sentinel_head->next = sentinel_tail;  // соединим эти ноды между собой
    sentinel_tail->prev = sentinel_head;
  };  // конструктор по умолчанию

  list(size_type n) : list() {
    for (size_type i = 0; i < n; i++) {
      push_back(T());
    }
  };  // создание двусвязного списка с заданным количеством аргументов, значение
      // аргументов - по-умолчанию (0, 0.0 т.д.)

  list(std::initializer_list<value_type> const &items) : list() {
    for (auto item : items) {
      push_back(item);
    }
  };  // конструктор списка и использованием списка инициализации

  list(const list &l) : list() {
    Node *current = l.sentinel_head->next;
    while (current != l.sentinel_tail) {
      push_back(current->data);
      current = current->next;
    }
  };  // конструктор копирования списка

  list(list &&l) noexcept : list() {
    this->sentinel_head->next = l.sentinel_head->next;
    this->sentinel_tail->prev = l.sentinel_tail->prev;
    l.sentinel_head->next->prev = this->sentinel_head;
    l.sentinel_tail->prev->next = this->sentinel_tail;

    l.size_ = 0;
    l.sentinel_head->next = l.sentinel_tail;
    l.sentinel_tail->prev = l.sentinel_head;
  };  // конструктор перемщения списка

  ~list() {
    Node *current = sentinel_head;
    while (current != nullptr) {
      Node *nextNode = current->next;
      delete current;
      current = nextNode;
    }
  };  // деструктор списка

  list &operator=(list &&l) {
    if (&l != this) {
      reset();  // полная очиска списка
      sentinel_head = l.sentinel_head;
      sentinel_tail = l.sentinel_tail;
      size_ = l.size_;

      l.sentinel_head = new Node(T(), nullptr, nullptr);
      l.sentinel_tail = new Node(T(), nullptr, nullptr);
      l.sentinel_head->next = l.sentinel_tail;
      l.sentinel_tail->prev = l.sentinel_head;
      l.size_ = 0;
    }
    return *this;
  }  // оператор присваивания перемещением

  // ***    list element access    ***
  // - публичные методы для доступа к элементам класса -
  const_reference front() {
    return *cbegin();
  };  // метод получения первого элемента списка

  const_reference back() {
    const_iterator tmp = end();
    --tmp;
    return *tmp;
  };  // получение последнего элемента списка

  // ***    list iterators    ***
  // - итераторы -
  iterator begin() {
    return iterator(sentinel_head->next);
  }  // итератор на первый элемент списка
  iterator end() {
    return iterator(sentinel_tail);
  }  // итератор на конец списка (т.е. область за последним элементом списка)

  const_iterator cbegin() const {
    return const_iterator(sentinel_head->next);
  }  // аналогично, только константные итераторы
  const_iterator cend() const { return const_iterator(sentinel_tail); }

  // ***    list capacity    ***
  // - публичные методы для доступа к информации о наполнении контейнера -
  bool empty() { return size_ == 0; };  // проверка листа на пустоту
  size_type size() { return size_; };  // возврат размера списка
  size_type max_size() {
    std::allocator<T> allocator;
    return allocator.max_size() / sizeof(T);
  };  // возврат максимального размера списка

  // ***    list modifiers    ***
  // - публичные методы для изменения контейнера -
  void clear() {
    while (size_ > 0) {
      pop_back();
    }
  };  // метод очищаение списка

  // вставляет в указанное место новый элемент и возвращает указатель на новый
  // элемент в виде итератора
  iterator insert(iterator pos, const_reference value) {
    // создаем новый элемент
    Node *newNode = new Node(value);

    newNode->next = pos.current;
    newNode->prev = pos.current->prev;

    pos.current->prev->next = newNode;
    pos.current->prev = newNode;

    pos.current = newNode;
    size_++;
    return pos;
  }  // метод вставки нового элемента в список

  // в спецификации указано, что метод должен возвращать void,
  // но оригинальный лист возвращает итератор на следующий элемент
  // я сделал как в оригинале
  iterator erase(iterator pos) {
    Node *current = pos.current;

    if (current == sentinel_head || current == sentinel_tail) {
      throw std::out_of_range("Cannot erase end() iterator");
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    iterator nextIt = iterator(current->next);
    delete current;
    size_--;

    return nextIt;
  }  // метод удаления узла, на который указывает итератор

  void push_back(const_reference value) {
    Node *newNode = new Node(value, sentinel_tail, sentinel_tail->prev);
    sentinel_tail->prev->next = newNode;
    sentinel_tail->prev = newNode;
    size_++;
  }  // вставка элемента в конец списка

  void pop_back() {
    if (empty()) {
      throw(std::out_of_range("The list is empty, cannot pop_back."));
    }
    Node *node_to_pop = sentinel_tail->prev;
    sentinel_tail->prev = sentinel_tail->prev->prev;

    sentinel_tail->prev->next = sentinel_tail;
    delete node_to_pop;
    size_--;
  };  // удаление узла в конце списка

  void push_front(const_reference value) {
    Node *newNode = new Node(value, sentinel_head->next, sentinel_head);
    sentinel_head->next->prev = newNode;
    sentinel_head->next = newNode;
    size_++;
  };  // вставка узла в начало списка

  void pop_front() {
    if (empty()) {
      throw(std::out_of_range("The list is empty, cannot pop_front."));
    }
    Node *node_to_pop = sentinel_head->next;
    sentinel_head->next = sentinel_head->next->next;
    sentinel_head->next->prev = sentinel_head;
    delete node_to_pop;
    size_--;
  };  // вставка узла в конец списка

  void swap(list &other) {
    std::swap(size_, other.size_);
    std::swap(sentinel_head, other.sentinel_head);
    std::swap(sentinel_tail, other.sentinel_tail);
  };  // обмен двух списков между собой (именно меняя указатели без копирования
      // элементов)

  // вставляем целых лист other в указанную позицию листа
  void splice(const_iterator pos, list &other) {
    if (this == &other) return;
    // если второй лист пустой, то переносить нечего
    if (other.empty()) return;

    // если первый лист пустой
    if (this->empty()) {
      // забираем у второго листа элементы через указатели
      this->sentinel_head->next = other.sentinel_head->next;
      this->sentinel_tail->prev = other.sentinel_tail->prev;

      this->sentinel_head->next->prev = this->sentinel_head;
      this->sentinel_tail->prev->next = this->sentinel_tail;

    } else {
      Node *before_pos = pos.current->prev;
      Node *splice_head = other.sentinel_head->next;
      Node *splice_tail = other.sentinel_tail->prev;

      before_pos->next = splice_head;
      splice_head->prev = before_pos;

      splice_tail->next = pos.current;
      pos.current->prev = splice_tail;
    }

    // меняем указатели у второго листа,
    // фактически, опустошаем его
    other.sentinel_head->next = other.sentinel_tail;
    other.sentinel_tail->prev = other.sentinel_head;

    this->size_ += other.size_;

    other.size_ = 0;
  };  // вставка листа в указанную позицию
  // перегрузка splice для вставки группы элементов (вставить не весь лист, а
  // лишь его часть)
  void splice(const_iterator pos, list &other, const_iterator first,
              const_iterator last) {
    if (this == &other || first == last || other.empty()) return;

    // отсоединяем часть от второго списка
    Node *splice_head = first.current;
    Node *splice_tail = last.current->prev;

    first.current->prev->next = last.current;
    last.current->prev = first.current->prev;

    // вставляем в первый список
    // присоединение спереди
    splice_head->prev = pos.current->prev;
    pos.current->prev->next = splice_head;

    // присоединение сзади
    splice_tail->next = pos.current;
    pos.current->prev = splice_tail;

    this->size_ = this->calc_size();
    other.size_ = other.calc_size();
  }  // встака в лист выбранного количества элементов

  void merge(list &other) {
    // второй лист пустой - нечего делать
    if (other.empty()) return;

    // первый лист пустой - просто вставить в него второй
    if (this->empty()) {
      this->splice(other.begin(), other);
      return;
    }

    iterator it1 = this->begin();
    iterator it2 = other.begin();

    while (it1 != this->end() && it2 != other.end()) {
      // если элемент второго листа меньше, его надо вставить в первый
      if (*it2 < *it1) {
        Node *to_transfer = it2.current;
        it2++;

        to_transfer->prev->next = to_transfer->next;
        to_transfer->next->prev = to_transfer->prev;

        Node *current = it1.current;
        Node *prev_node = it1.current->prev;

        prev_node->next = to_transfer;
        to_transfer->prev = prev_node;

        current->prev = to_transfer;
        to_transfer->next = current;

        this->size_++;
        other.size_--;

      } else {
        it1++;
      }
    }
    // если во втором листе остались элементы
    if (it2 != other.end()) {
      this->splice(this->end(), other);
    }
  };  // слияние двух листов в один с сохранение порядка элементов

  void reverse() {
    Node *current = sentinel_head;
    Node *temp = nullptr;

    // цикл по всем нодам (включая пустые крайние)
    while (current != nullptr) {
      // меняем местами указатели (тем самым разворачивая лист)
      temp = current->next;
      current->next = current->prev;
      current->prev = temp;

      current = temp;
    }

    // меняем местами голову и хвост списка
    temp = sentinel_head;
    sentinel_head = sentinel_tail;
    sentinel_tail = temp;
  };  // инверсия двусвязного списка

  void unique() {
    if (empty()) return;

    iterator it = begin();
    while (it != end()) {
      Node *next_node = it.current->next;
      if (next_node != nullptr && *it == next_node->data) {
        it = erase(it);
      } else
        it++;
    }
  };  // удаление всех повторяющихся (идущих последовательно) элементов из
      // списка

  void sort() {
    if (size_ == 0 || size_ == 1) return;
    merge_sort();
  };  // сортировка элементов списка

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args) {
    list<T> temp;
    (temp.push_back(std::forward<Args>(args)), ...);
    this->splice(pos, temp);
    iterator it(pos.current);
    for (size_t i = 0; i < sizeof...(args); i++) {
      --it;
    }
    return it;  // указатель на первый из вставленных элементов
  }  // вставка нескольких элементов в список

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    (push_back(std::forward<Args>(args)), ...);
  }  // вставка нескольких элементов в конец списка

  template <typename... Args>
  void insert_many_front(Args &&...args) {
    list<T> temp;
    (temp.push_back(std::forward<Args>(args)), ...);
    this->splice(this->cbegin(), temp);
  }  // вставка нескольких элементов в начало списка

 private:
  // полностью опустошает список с очисткой памяти
  void reset() {
    clear();

    delete sentinel_head;
    delete sentinel_tail;

    size_ = 0;
  }

  // вычислить размер, пройдясь по всем элементам
  size_type calc_size() {
    size_type count = 0;
    for (iterator it = begin(); it != end(); ++it) {
      ++count;
    }
    return count;
  }

  void merge_sort() {
    list<T> second_half;
    this->split(second_half);

    if (this->size_ > 1) {
      this->merge_sort();
      second_half.merge_sort();
    }
    this->merge(second_half);
  }  // сортировка списка с использованием слияния

  void split(list &second_half) {
    if (empty()) return;

    second_half.clear();

    Node *fast = sentinel_head->next;
    Node *slow = sentinel_head->next;

    while (fast != sentinel_tail && fast->next != sentinel_tail &&
           fast->next->next != sentinel_tail) {
      fast = fast->next->next;
      slow = slow->next;
    }

    const_iterator first = const_iterator(slow->next);
    const_iterator last = this->end();

    second_half.splice(second_half.cbegin(), *this, first, last);
  }  // метод разделенения текущего списка на 2 части, вспомогательный метод для
     // сортировки слиянием
};
}  // namespace s21

#endif

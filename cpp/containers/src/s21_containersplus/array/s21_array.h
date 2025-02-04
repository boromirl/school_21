#ifndef S21_ARRAY_H
#define S21_ARRAY_H

namespace s21 {
template <typename T, std::size_t Size>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  // Array member functions (основные публичные методы для взаимодействия с
  // классом)
  array() = default;  // конструктор по умолчанию

  array(std::initializer_list<value_type> const &items) : array() {
    if (items.size() > Size) {
      throw std::out_of_range(
          "The initialization list is larger than the allowed size!");
    }
    size_type i = 0;  // счетчик для записи элементов в массив
    for (const auto &element_of_initialization_list : items) {
      arr_[i] = element_of_initialization_list;
      ++i;
    }
  }  // конструктор статического массива с использованием списка инициализации

  array(const array &a) {
    for (size_type i = 0; i < Size; i++) {
      arr_[i] = a.arr_[i];
    }
  }  // конструктор копирования

  array(array &&a) noexcept {
    if (this != &a) {
      for (size_type i = 0; i < Size; i++) {
        arr_[i] = std::move(a.arr_[i]);
      }
    }
  }  // конструктор перемещения

  ~array() = default;  // деструктор по умолчанию

  array &operator=(array &&a) noexcept {
    if (this != &a) {
      swap(a);
    }
    return *this;
  }  // оператор присваивания перемещением

  // Array Element access - публичные методы для доступа к элементам класса
  reference at(size_type pos) {
    if (pos >= Size) {
      throw std::out_of_range("Index is outside array!");
    }
    return arr_[pos];
  }  // доступ к элементу статического массив по индексу с проверкой границ

  const_reference at(size_type pos) const {
    if (pos >= Size) {
      throw std::out_of_range("Index is outside array!");
    }
    return arr_[pos];
  }  // аналогично константный

  reference operator[](size_type pos) {
    return arr_[pos];
  }  // доступ по индексу к элементу без проверки границ

  const_reference operator[](size_type pos) const {
    return arr_[pos];
  }  // аналогично константный

  const_reference front() const {
    return arr_[0];
  }  // константный доступ к первому элементу

  const_reference back() const {
    return arr_[Size - 1];
  }  // константный доступ к последнему элементу

  iterator data() noexcept { return arr_; }  // прямой доступ к данным массива

  // Array iterators - публичные методы для итерирования по элементам класса
  iterator begin() noexcept { return arr_; }  // итератор на начало массива

  const_iterator begin() const noexcept {
    return arr_;
  }  // аналогично константный

  iterator end() noexcept {
    if (empty()) {
      return arr_;
    }
    return arr_ + Size;
  }  // оператор на конец массива

  const_iterator end() const noexcept {
    if (empty()) {
      return arr_;
    }
    return arr_ + Size;
  }  // аналогично константный

  // Array Capacity - публичные методы для доступа к информации о наполнении
  // контейнера

  bool empty() const noexcept { return Size == 0; }  // проверка на пустоту

  size_type size() const noexcept { return Size; }  // возврат размера

  size_type max_size() const noexcept {
    return Size;
  }  // возврат максимального размера - он равен заданному, т.к. массив
     // статический

  // Array Modifiers - публичные методы для изменения контейнера

  void swap(array &other) noexcept {
    std::swap(arr_, other.arr_);
  }  // меняем содержимое двух массивов, фактически меняем только указатели

  void fill(const_reference value) {
    for (auto &element_of_array : arr_) {
      element_of_array = value;
    }
  }  // заполнение массива указанным значением

 private:
  value_type
      arr_[Size]{};  // объявим массив указанного размера с определенным типом
                     // данных, инициализирован он будет "нулями" для выбранного
                     // типа данных. Не требует динамической памяти!
};
}  // namespace s21
#endif
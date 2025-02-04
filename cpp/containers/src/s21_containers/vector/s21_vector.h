#ifndef S21_VECTOR_H
#define S21_VECTOR_H

namespace s21 {
template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  // Vector Member functions - функции-члены - публичные методы для
  // взаимодействия с классом

  vector()
      : arr_(nullptr), size_(0), capacity_(0) {};  // конструктор по умолчанию

  vector(size_type n) : vector() {
    size_ = n;
    capacity_ = n;
    if (size_ > 0) {
      arr_ = new value_type[n];
    }
  }  // конструктор с параметром

  vector(std::initializer_list<value_type> const &items) : vector() {
    size_ = items.size();
    capacity_ = items.size();
    if (size_ > 0) {
      arr_ = new value_type[capacity_];
      std::copy(items.begin(), items.end(), arr_);
    }
  }  // конструктор с использованием списка инициализации

  vector(const vector<value_type> &v) : vector() {
    operator=(v);
  }  // конструктор копирования

  vector<value_type> &operator=(const vector<value_type> &v) {
    if (this != &v) {
      clear_();
      size_ = v.size_;

      capacity_ = v.capacity_;
      if (size_ > 0) {
        arr_ = new value_type[capacity_];
        for (size_type i = 0; i < size_; i += 1) {
          arr_[i] = *(v.begin() + i);
        }
      }
    }
    return *this;
  }  // вспомогательный оператор присваивания копированием

  vector(vector<value_type> &&v) noexcept : vector() {
    operator=(std::move(v));
  }  // конструктор перемещения

  ~vector() { clear_(); }  // деструктор

  vector<value_type> &operator=(vector<value_type> &&v) noexcept {
    if (this != &v) {
      clear_();
      arr_ = v.arr_;
      size_ = v.size_;
      capacity_ = v.capacity_;
      v.arr_ = nullptr;
      v.size_ = 0;
      v.capacity_ = 0;
    }
    return *this;
  }  // оператор перемещения присваиванием

  // Vector Element access - публичные методы для доступа к элементам класса
  // (учитывать, что иногда доступ должен учитывать неизменяемость объекта -
  // константность)
  reference at(size_type pos) {
    if (pos >= size_) {
      throw std::out_of_range(
          "Attempting to access an inaccessible memory "
          "area!");
    }
    return arr_[pos];
  }  // доступ к элементу класса по индексу с проверкой границ вектора

  const_reference at(size_type pos) const {
    if (pos >= size_) {
      throw std::out_of_range(
          "Attempting to access an inaccessible memory area!");
    }
    return arr_[pos];
  }  // аналогично константный

  reference operator[](size_type pos) {
    return arr_[pos];
  }  // быстрой доступ к элементу вектора по индексу, без проверки границ
     // вектора

  const_reference operator[](size_type pos) const {
    return arr_[pos];
  }  // аналогично константный

  const_reference front() const {
    if (empty()) {
      throw std::logic_error("Vector is empty!");
    }
    return arr_[0];
  }  // доступ к первому элементу вектора

  const_reference back() const {
    if (empty()) {
      throw std::logic_error("Vector is empty!");
    }
    return arr_[size_ - 1];
  }  // доступ к последнему элементу вектора

  iterator data() {
    return &arr_[0];
  }  // метод прямого доступа к данным
     // вектора

  // Vector Iterators - публичные методы для итерирования по элементам класса
  // (доступ к итераторам), учитывать возможную работу с константными объектами
  iterator begin() { return &arr_[0]; }  // итератор на первый элемент

  const_iterator begin() const {
    return &arr_[0];
  }  // аналогично константный итератор

  iterator end() { return &arr_[size_]; }  // итератор на конец вектора

  const_iterator end() const {
    return &arr_[size_];
  }  // итератор на конец вектора

  // Vector Capacity - публичные методы для доступа к информации о наполнении
  // контейнера
  bool empty() const { return size_ == 0; }  // проверка на пустоту

  size_type size() const { return size_; }  // проверка размера

  size_type max_size() {
    return std::numeric_limits<size_type>::max() / 2 /
           sizeof(value_type);  // проверка максимального размера вектора
  }

  void reserve(size_type size) {
    if (size > max_size()) {
      throw std::length_error("Requested size exceeds maximus size!");
    }
    if (size > capacity_) {
      value_type *old_arr = arr_;
      arr_ = new value_type[size];
      for (size_t i = 0; i < size_; i++) {
        arr_[i] = old_arr[i];
      }
      delete[] old_arr;
      old_arr = nullptr;
      capacity_ = size;
    }
  }  // увеличение емкости контенера

  size_type capacity() const {
    return capacity_;
  }  // возврат емкости
     // контейнера

  void shrink_to_fit() {
    if (capacity_ != size_) {
      capacity_ = size_;
    }
    reserve(capacity_);
  }  // метод уменьшения выделенной памяти динамического массива (вектора)

  // Vector Modifiers - публичные методы для изменения контейнера
  void clear() { size_ = 0; }  // очищаем содержимое вектора

  iterator insert(iterator pos, const_reference value) {
    if (pos < begin() || pos > end()) {
      throw std::length_error("Index out of vector!");
    }
    if (pos == end()) {
      push_back(value);

      return arr_ + size() - 1;
    }
    auto insertion_position = std::distance(begin(), pos);
    push_back(value_type());
    auto temp_value = arr_[insertion_position];
    arr_[insertion_position] = value;
    for (size_type i = insertion_position + 1; i < size() - 1; i++) {
      std::swap(temp_value, arr_[i]);
    }
    arr_[size() - 1] = temp_value;
    return arr_ + insertion_position;
  }  // вставка элемента в вектор

  iterator erase(iterator pos) {
    if (pos < begin() || pos >= end()) {
      throw std::length_error(
          "Trying to remove an element outside of an array!");
    }
    size_type index = std::distance(begin(), pos);
    for (size_type i = index; i + 1 < size(); i++) {
      arr_[i] = arr_[i + 1];
    }
    size_ -= 1;
    return begin() + index;
  }  // удаление элемента вектора в заданной позиции

  void push_back(const_reference value) {
    if (size_ >= capacity_) {
      if (capacity_ == 0) {
        reserve(1);
      } else {
        reserve(capacity_ * 2);
      }
    }
    arr_[size_] = value;
    size_ += 1;
  }  // вставка элемента в конец вектора

  void pop_back() {
    if (size_ > 0) {
      size_ -= 1;
    }
  }  // удаление последнего элемента вектора

  void swap(vector &other) {
    std::swap(arr_, other.arr_);

    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
  }  // обмен содержимого двух векторов

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args) {
    if (pos < begin() || pos > end()) {
      throw std::length_error("Index out of vector!");
    }
    size_type index_of_insertion_place = pos - begin();
    insert_additional(const_cast<iterator>(pos), std::forward<Args>(args)...);

    return begin() + index_of_insertion_place;
  }  // вставка множества элементов в контейнер

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    insert_additional(end(), std::forward<Args>(args)...);
  }  // вставка множества элементов в конец контейнера

 private:
  iterator arr_;  // приватные поля - указатель на массив с данным вектора,
                  // размер, емкость
  size_type size_;
  size_type capacity_;

  void clear_() {
    if (arr_ != nullptr) {
      delete[] arr_;
      arr_ = nullptr;
      size_ = 0;
      capacity_ = 0;
    }
  }  // полная очистка вектора

  template <typename... Args>
  void insert_additional(iterator pos, Args &&...args) {
    size_type elements_for_insertion = sizeof...(args);
    size_type insertion_place = pos - begin();

    if (size_ + elements_for_insertion > capacity_) {
      size_type updated_capacity =
          std::max(capacity_ * 2, size_ + elements_for_insertion);
      reserve(updated_capacity);
    }
    std::move_backward(begin() + insertion_place, end(),
                       end() + elements_for_insertion);
    iterator actual_position = begin() + insertion_place;
    ((*(actual_position++) = std::forward<Args>(args)), ...);

    size_ += elements_for_insertion;
  }  // вспомогательный метод для вставки множества элементов в контейнер
};
}  // namespace s21
#endif
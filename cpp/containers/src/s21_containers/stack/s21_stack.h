#ifndef S21_STACK_H
#define S21_STACK_H

namespace s21 {
template <typename T>
class stack {
 public:
  // ***    stack member type    ***
  // - внутриклассовые переопределения типов -
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // ***    stack member functions    ***
  // - публичные методы для взаимоействия с классом -

  // конструкторы
  stack() : size_(0), capacity_(1) {
    elements_ = new T[capacity_];
  };  // конструктор по умолчанию, что интересно, он не совсем нулевой, т.к.
      // емкость 1 отвечает за тип данных который будет храниться в стеке

  stack(std::initializer_list<value_type> const &items)
      : size_(0), capacity_(1) {
    elements_ = new T[capacity_];
    for (auto item : items) {
      push(item);
    }
  }  // конструктор стека с использованием списка инициализации

  stack(const stack &s) : size_(s.size_), capacity_(s.capacity_) {
    elements_ = new T[capacity_];
    for (int i = 0; i < (int)size_; i++) {
      elements_[i] = s.elements_[i];
    }
  }  // конструктор копирования

  stack(stack &&s) noexcept
      : elements_(s.elements_), size_(s.size_), capacity_(s.capacity_) {
    s.size_ = 0;
    s.capacity_ = 0;
    s.elements_ = nullptr;
  }  // конструктор перемещения

  // деструктор
  ~stack() { delete[] elements_; };

  // перемещение объекта
  stack &operator=(stack &&s) {
    if (this != &s) {      // self-assignment check
      delete[] elements_;  // очистить старые ресурсы

      // перенести ресурсы
      elements_ = s.elements_;
      size_ = s.size_;
      capacity_ = s.capacity_;

      // занулить источник
      s.elements_ = nullptr;
      s.size_ = 0;
      s.capacity_ = 0;
    }
    return *this;
  }

  // ***    stack element access    ***
  // - публичный метод для доступа к элементам класса -

  const_reference top() {
    if (this->empty()) {
      throw std::out_of_range("Stack is empty");
    } else
      return elements_[size_ - 1];
  }  // доступ к первому элементу контейнера

  // ***    stack capacity    ***
  // - публичные методы для доступа к информации о наполнении контейнера -

  bool empty() { return (size_ == 0); }  // проверка на пустоту
  size_type size() { return size_; }  // возврат размера стека

  // ***    stack modifiers    ***
  // - публичные методы для изменения контейнера -
  void push(const_reference value) {
    if (size_ == capacity_) resize();
    elements_[size_] = value;
    size_++;
  };  // вставка нового элемента в стек

  void pop() {
    if (this->empty()) {
      throw std::out_of_range("Stack is empty");
    } else {
      size_--;
    }
  }  // удаление верхнего элемент из стека

  void swap(stack &other) {
    std::swap(elements_, other.elements_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
  }  // обмена содержимого двух стеков

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    (push(std::forward<Args>(args)), ...);  // fold expression
  }  // вставка множества элементов в стек

 private:
  T *elements_;
  size_type size_;
  size_type capacity_;

  void resize() {
    capacity_ *= 2;
    T *new_elements = new T[capacity_];
    for (size_type i = 0; i < size_; i++) {
      new_elements[i] = elements_[i];
    }

    delete[] elements_;
    elements_ = new_elements;
  }  // увеличение емкости стека
};
}  // namespace s21

#endif

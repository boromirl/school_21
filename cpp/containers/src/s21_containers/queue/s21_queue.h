#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include "../vector/s21_vector.h"

namespace s21 {
template <typename T>
class queue {
 public:
  // переопределим типы - создадим всевдонимы
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // Кострукторы и оператор
  queue() = default;  // конструктор по умолчанию

  queue(std::initializer_list<value_type> const &items)
      : container_(items) {
  }  // конструктор по умолчанию с использование списка инициализации,
     // фактически передаст список в контейнер вектора, который и произведет
     // создание
  queue(const queue &q)
      : container_(q.container_) {}  // конструктор
                                     // копирования
  queue(queue &&q) noexcept
      : container_(std::move(q.container_)) {}  // конструктор перемещения

  ~queue() = default;  // деструктор, автоматически вызовет деструктор вектора

  queue &operator=(queue &&q) noexcept {
    if (this != &q) {
      container_ = std::move(q.container_);
    }
    return *this;
  }  // оператор присваивания перемещением

  // Доступ к элементам
  const_reference front() const {
    if (empty()) throw std::out_of_range("Queue is empty!");
    return container_.front();
  }  // константный метод доступа к первому элементу

  const_reference back() const {
    if (empty()) throw std::out_of_range("Queue is empty!");
    return container_.back();
  }  // константный методо доступа к последнему элементу

  // Доступ к информации о наполнении контейнера/емкости
  bool empty() const noexcept {
    return container_.empty();
  }  // проверка на пустоту

  size_type size() const noexcept {
    return container_.size();
  }  // возврат размера

  // Модификаторы контейнера
  void push(const_reference value) {
    container_.push_back(value);
  }  // вставка элемента в конец контейнера

  void pop() {
    if (empty()) throw std::out_of_range("Queue is empty!");
    container_.erase(container_.begin());
  }  // удаление элемента из начала контейнера

  void swap(queue &other) noexcept {
    container_.swap(other.container_);
  }  // обмен содержимого двух очередей

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    container_.insert_many_back(std::forward<Args>(args)...);
  };  // вставка нескольких элементов в конец очереди

 private:
  s21::vector<T> container_;
};
}  // namespace s21
#endif

/*очередь организована по принципу FIFO - первый вошел,
первый вышел. Это как труба. Вставка производится в конец,
а удаление строго из начала.*/
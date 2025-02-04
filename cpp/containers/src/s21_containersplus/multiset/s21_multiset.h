#ifndef S21_MULTISET_H
#define S21_MULTISET_H

#include "../../s21_containers/rb_tree/s21_rb_tree.h"

namespace s21 {
template <typename Key>
class multiset {
 public:  // зададим псевдонимы (алиасы) для типов данных
  using key_type = Key;
  using value_type = Key;  // одно и то же см строку выше
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BinaryTree<key_type, key_type>::iterator;
  using const_iterator =
      typename BinaryTree<key_type, key_type>::const_iterator;
  using size_type = size_t;

 private:
  BinaryTree<key_type, key_type> *tree;  // указатель на наше дерево

 public:
  multiset() {
    this->tree = new BinaryTree<key_type, key_type>(false);
  }  // конструктор по умолчанию, false - не уникальный, может работать с
     // дубликатами
  multiset(std::initializer_list<value_type> const &items) {
    this->tree = new BinaryTree<key_type, key_type>(false);
    for (auto item : items) {
      this->tree->insert(
          std::make_pair(item, key_type()));  // нам важно только значение item,
                                              // а второй ключ - "нулевой"
    }
  }  // конструктор и использованием списка инициализации

  multiset(const multiset &ms) {
    this->tree = new BinaryTree<key_type, key_type>(*(ms.tree));
  }  // конструктор копирования
  multiset(multiset &&ms) {
    this->tree = std::move(ms.tree);
    ms.tree = new BinaryTree<key_type, key_type>;
  }  // конструктор перемещения
  ~multiset() { delete this->tree; }  // деструктор

  multiset &operator=(multiset &&ms) {
    if (&ms != this) {
      delete this->tree;
      this->tree = std::move(ms.tree);
      ms.tree = new BinaryTree<key_type, key_type>;
    }
    return *this;
  }  // оператор присваивания перемещение

  iterator begin() {
    return this->tree->begin();
  }  // итреатор на начало контейнера
  iterator end() { return this->tree->end(); }  // итератор на конец контейнера

  const_iterator cbegin() const {
    return this->tree->cbegin();
  }  // аналогично только константные
  const_iterator cend() const { return this->tree->cend(); }

  bool empty() const { return this->tree->empty(); }  // проверяем на пустоту
  size_type size() const { return this->tree->size(); }  // возврат размера
  size_type max_size() const {
    return std::numeric_limits<size_t>::max() /
           sizeof(
               std::pair<key_type, key_type>);  // возврат максимального размера
  }
  void clear() { this->tree->clear(); }  // очистка мультисета
  iterator insert(const value_type &value) {
    return (tree->insert(std::make_pair(value, key_type()))).first;
  }  // вставка элемента в контейнера
  void erase(iterator pos) {
    this->tree->deleteNode(pos);
  }  // удаление ноды из мультисета
  void swap(multiset &other) {
    std::swap(this->tree, other.tree);
  }  // замена содержимого двух нод, фактически меняем указатели
  void merge(multiset &other) {
    this->tree->merge(*(other.tree));
  }  // слияение двух контейнеров

  size_type count(const Key &key) const {
    size_type res = 0;
    for (const_iterator it = this->cbegin(); it != this->cend(); it++) {
      if (*it == key) res++;
    }
    return res;
  }  // подсчитываем количество заданных элементов в контейнере
  iterator find(const Key &key) const {
    return this->tree->find(key);
  }  // поиск элемента в контейнере
  bool contains(const Key &key) const {
    return this->tree->contains(key);
  }  // проверка наличия элемента в контейнере
  std::pair<iterator, iterator> equal_range(const Key &key) {
    iterator start = this->end();
    iterator end = this->end();

    iterator it = this->begin();
    while (it != this->end() && *it != key) {
      it++;
    }

    if (it == this->end()) {
      return std::make_pair(start, end);
    }

    start = it;

    while (it != this->end() && *it == key) {
      it++;
    }

    end = it;
    return std::make_pair(start, end);
  }  // возврат диапазона элементов равных заданному ключу, вернет 2 итератора -
     // на начало и конец диапазона

  iterator lower_bound(const Key &key) {
    iterator it = this->begin();
    while (it != this->end() && *it < key) {
      it++;
    }
    return it;
  }  // вернет итератор на первый элемент, который не меньше чем заданный ключ
  iterator upper_bound(const Key &key) {
    iterator it = this->begin();
    while (it != this->end() && *it <= key) {
      it++;
    }
    return it;
  }  // вернет итератор на первый элемент, который строго больше заданного ключа

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> res;
    (res.push_back(this->tree->insert(
         std::make_pair(std::forward<Args>(args), key_type()))),
     ...);
    return res;
  }  // вставка нескольких элементов в контейнер
};
}  // namespace s21

#endif
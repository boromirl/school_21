#ifndef S21_SET_H
#define S21_SET_H

#include "../rb_tree/s21_rb_tree.h"

namespace s21 {
template <typename Key>
class set {
 public:
  using key_type = Key;
  using value_type = Key;  // ключ и значение для сет/мультисет - одно и то же
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BinaryTree<key_type, key_type>::iterator;
  using const_iterator =
      typename BinaryTree<key_type, key_type>::const_iterator;
  using size_type = size_t;

 private:
  BinaryTree<key_type, key_type> *tree;  // указатель на дерево

 public:
  set() {
    this->tree = new BinaryTree<key_type, key_type>;
  }  // конструктор по умолчанию
  set(std::initializer_list<value_type> const &items) {
    this->tree = new BinaryTree<key_type, key_type>;
    for (auto item : items) {
      this->tree->insert(std::make_pair(item, key_type()));
    }  // конструктор с использованием списка инициализации
  }
  set(const set &s) {
    this->tree = new BinaryTree<key_type, key_type>(*(s.tree));
  }  // конструктор копирования
  set(set &&s) {
    this->tree = std::move(s.tree);
    s.tree = new BinaryTree<key_type, key_type>;
  }  // конструктор перемещения
  ~set() { delete this->tree; }  // деструктор

  set &operator=(set &&s) {
    if (&s != this) {
      delete this->tree;
      this->tree = std::move(s.tree);
      s.tree = new BinaryTree<key_type, key_type>;
    }
    return *this;
  }  // оператор присваивания перемещением

  iterator begin() {
    return this->tree->begin();
  }  // итераторы на первый элемент и конец сета
  iterator end() { return this->tree->end(); }

  const_iterator cbegin() const {
    return this->tree->cbegin();
  }  // аналогично, только итераторы константные
  const_iterator cend() const { return this->tree->cend(); }

  bool empty() const {
    return this->tree->empty();
  }  // проверка сета на
     // пустоту
  size_type size() const { return this->tree->size(); }
  size_type max_size() const {
    return std::numeric_limits<size_t>::max() /
           sizeof(std::pair<key_type, key_type>);
  }  // возврат максимального размера контейнера

  void clear() { this->tree->clear(); }  // очистка контейнера
  std::pair<iterator, bool> insert(const value_type &value) {
    return tree->insert(std::make_pair(value, key_type()));
  }  // вставка элемента в контейрена

  void erase(iterator pos) {
    this->tree->deleteNode(pos);
  }  // удалени элемента из контейнера
  void swap(set &other) {
    std::swap(this->tree, other.tree);
  }  // замена содержимого двух контейнеров, фактически меняются лишь указатели
  void merge(set &other) {
    this->tree->merge(*(other.tree));
  }  // слияние двух контейнеров

  iterator find(const Key &key) const {
    return this->tree->find(key);
  }  // поиск элемента по заданному ключу
  bool contains(const Key &key) const {
    return this->tree->contains(key);
  }  // проверка наличия элемента в контейнере

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> res;
    (res.push_back(this->insert(std::forward<Args>(args))), ...);
    return res;
  }  // вставка множества элементов в контейнер
};
}  // namespace s21

#endif
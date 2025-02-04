#ifndef S21_MAP_H
#define S21_MAP_H

#include "../rb_tree/s21_rb_tree.h"

namespace s21 {
template <typename Key, typename T>  // т.к. map работает с парой ключ значение
class map {
 public:
  using key_type = Key;   // ключ
  using mapped_type = T;  // тип данных
  using value_type = std::pair<const key_type, mapped_type>;  // ключ значение
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BinaryTree<key_type, mapped_type, true>::iterator;
  using const_iterator =
      typename BinaryTree<key_type, mapped_type, true>::const_iterator;
  using size_type = size_t;

 private:
  BinaryTree<key_type, mapped_type, true> *tree;  // указатель на наше дерево

 public:
  map() {
    this->tree = new BinaryTree<key_type, mapped_type, true>();
  }  // конструктор по умолчанию для дерева
  map(std::initializer_list<value_type> const &items) {
    this->tree = new BinaryTree<key_type, mapped_type, true>;
    for (auto item : items) {
      this->tree->insert(std::make_pair(item.first, item.second));
    }
  }  // конструктор словаря с использованием списка инициализации
  map(const map &m) {
    this->tree = new BinaryTree<key_type, mapped_type, true>(*(m.tree));
  }  // конструктор копирования
  map(map &&m) {
    this->tree = std::move(m.tree);
    m.tree = new BinaryTree<key_type, mapped_type, true>;
  }  // конструктор перемещения
  ~map() { delete this->tree; }  // деструктор

  map &operator=(map &&map) {
    if (&map != this) {
      delete this->tree;
      this->tree = std::move(map.tree);
      map.tree = new BinaryTree<key_type, mapped_type, true>;
    }
    return *this;
  }  // оператор перемещения присваиванием

  T &at(const Key &key) {
    iterator it = this->tree->find(key);
    if (it == this->end()) {
      throw std::out_of_range("Error: map::at: key not found");
    }
    return (*it).second;
  }
  T &operator[](const Key &key) {
    iterator it = this->tree->find(key);
    if (it == this->end()) {
      it = (this->tree->insert(std::make_pair(key, mapped_type()))).first;
    }
    return (*it).second;
  }  // оператор получения доступа к значению в словаре по элементу, с проверкой
     // есть такой ключ в словаре

  iterator begin() {
    return this->tree->begin();
  }  // метод возвращает итератор на первый элемент контейнера
  iterator end() {
    return this->tree->end();
  }  // метод возвращает итератор на конец контейнера

  const_iterator cbegin() const {
    return this->tree->cbegin();
  }  // аналогично, только константный
  const_iterator cend() const { return this->tree->cend(); }

  bool empty() const {
    return this->tree->empty();
  }  // проверка словаря на пустоту
  size_type size() const { return this->tree->size(); }  // возврат размера
  size_type max_size() const {
    return std::numeric_limits<size_t>::max() /
           sizeof(std::pair<key_type, mapped_type>);
  }  // возврат максимального размера

  void clear() { this->tree->clear(); }  // очистка словаря
  std::pair<iterator, bool> insert(const value_type &value) {
    return this->tree->insert(value);
  }  // метод вставки уже готовой пары ключ-значение в словарь
  std::pair<iterator, bool> insert(const Key &key, const T &obj) {
    return (this->tree->insert(std::make_pair(key, obj)));
  }  // метод вставки значения по ключу в словарь, но пара ключ-значение
     // создается уже внутри метода
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj) {
    std::pair<iterator, bool> result =
        this->tree->insert(std::make_pair(key, obj));
    if (result.second == false) {
      (*result.first).second = obj;
    }
    return result;  // вставка элемента или присвоение его текущему элементу,
                    // если указанный ключ уже существует
  }
  void erase(iterator pos) {
    this->tree->deleteNode(pos);
  }  // удаление ноды из словаря
  void swap(map &other) {
    std::swap(this->tree, other.tree);
  }  // обмен между двумя словаря - фактически меняем указатели на их деревья
  void merge(map &other) {
    this->tree->merge(*(other.tree));
  }  // слияние двух словарей

  bool contains(const Key &key) const {
    return this->tree->contains(key);
  }  // проверяем содержится элемент в контейнере с указанным ключом

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> res;
    (res.push_back(this->tree->insert(std::forward<Args>(args))), ...);
    return res;
  }  // вставка нескольких элементов в словарь
};
}  // namespace s21

#endif
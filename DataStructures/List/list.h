#pragma once
#include <string>  // exception
template <class T>
class List {
 protected:
  struct Node {
    T data_;
    Node* prev_;
    Node* next_;
    Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
        : data_(data), prev_(prev), next_(next) {}
    Node(const Node& node)
        : data_(node.data_), prev_(node.prev_), next_(node.next_) {}
    const Node& operator=(const Node& node) {
      data_ = node.data_;
      prev_ = node.prev_;
      next_ = node.next_;
    }
    ~Node() = default;
  };
  Node* first_;
  size_t size_;

 public:
  List() : first_(nullptr), size_(0) {}  // CTOR +
  List(const List<T>& list) {
    if (list.first_ == nullptr) {
      size_ = 0;
      first_ = nullptr;
      return;
    }
    first_ = new Node(*list.first_);
    size_ = 1;
    for (Node *other_cur = list.first_, *this_cur = first_;
         other_cur->next_ != nullptr;
         other_cur = other_cur->next_, this_cur = this_cur->next_) {
      this_cur->next_ = new Node(other_cur->next_->data_);
      size_++;
    }
  }  // Copy-CTOR +
  ~List() {
    clear();
    delete first_;
  }  // DTOR +
  const List<T>& operator=(const List<T>& list) {
    List<T> tmp(list);
    first_ = tmp.first_;
    size_ = tmp.size_;
    tmp.first_ = nullptr;
    return *this;
  }  // Copy-assignment +
  List<T>& operator=(List&& list) noexcept {
    std::swap(list, *this);
    list.clear();
    return *this;
  }  // Move-assignment +
  bool empty() const noexcept {
    return size_ == 0;
  }  // checks whether the container is empty + +
  size_t size() const noexcept {
    return size_;
  }  // returns the number of elements + +
  const T& front() const {
    if (size_ == 0) {
      throw std::string("List is empty");
    }
    return first_->data_;
  }  // access the first element +
  void push_front(const T& elem) {
    Node* node = new Node(elem, nullptr, first_);
    first_ = node;
    size_++;
  }  // inserts an element to the beginning + +
  void pop_front() noexcept {
    if (size_ == 0) return;
    Node* tmp(first_);
    first_ = first_->next_;
    delete tmp;
    size_--;
  }  // removes the first element + +
  void resize(size_t size) {
    if (size == size_) {
      return;
    }
    if (size < size_) {
      Node* cur = first_;
      for (int i = 1; i < size; i++) {
        cur = cur->next_;
      }
      if (size_ > 0) {
        {
          cur = cur->next_;
          while (cur != nullptr) {
            Node* tmp = cur;
            cur = cur->next_;
            delete tmp;
          }
        }
      }
      size_ = size;
    } else {
      T empty_data{};
      Node* cur = first_;
      for (; cur->next_ != nullptr; cur = cur->next_)
        ;
      for (; size_ <= size; size_++) {
        cur->next_ = new Node(empty_data);
        cur = cur->next_;
      }
    }
  }  // changes the number of elements stored +
  void clear() noexcept {
    while (first_ != nullptr) {
      Node* tmp = first_;
      first_ = first_->next_;
      delete tmp;
    }
    size_ = 0;
  }  // clears the contents +
  void remove(const T& elem) {
    if (size_ == 0) {
      return;
    }
    while (first_ != nullptr && first_->data_ == elem) {
      Node* tmp = first_;
      first_ = first_->next_;
      delete tmp;
      size_--;
    }
    Node* cur = first_->next_;
    Node* prev = first_;
    for (Node* prev = first_; cur != nullptr; prev = prev->next_) {
      if (cur->data_ == elem) {
        Node* tmp = cur;
        cur = cur->next_;
        prev->next_ = cur;
        delete tmp;
        size_--;
      }
    }
  }  // removes all elements that are equal to passed value +
  void reverse() {
    if (first_ == nullptr || first_->next_ == nullptr) {
      return;
    }
    Node* reverse_cur = first_;
    reverse_cur->next_ = nullptr;
    for (Node* cur = first_; cur->next_ != nullptr; cur = cur->next_) {
      reverse_cur = cur->next_;
      reverse_cur->next_ = cur;
    }
    first_ = reverse_cur;
  }  // reverses the order of the elements +
};

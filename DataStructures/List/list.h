#pragma once
#include <string>  // exception

template <class T>
class List {
 protected:
  struct Node {
    T data_;
    Node* next_;
    Node(const T& data, Node* next = nullptr) : data_(data), next_(next) {}
    Node(const Node& node) : data_(node.data_), next_(node.next_) {}
    const Node& operator=(const Node& node) {
      data_ = node.data_;
      next_ = node.next_;
    }
    ~Node() = default;
  };
  Node* first_;
  size_t size_;

 public:
  struct iterator {
   private:
    friend class List<T>;
   protected:
    Node* cur_;

   public:
    iterator(Node* cur = nullptr) : cur_(cur) {}
    iterator(const iterator& it) : cur_(it.cur_) {}
    T& operator*() const { return cur_->data_; }
    /*T* operator->() const {
      if (cur_ != nullptr) {
        return &(cur_->data);
      } else {
        return nullptr;
      }
    }*/
    bool operator!=(const iterator& i) const { return cur_ != i.cur_; }
    bool operator==(const iterator& i) const { return cur_ == i.cur_; }
    const iterator& operator++() {
      cur_ = cur_->next_;
      return *this;
    }
    iterator operator++(int) {
      iterator tmp = *this;
      cur_ = cur_->next_;
      return tmp;
    }
  };

  List() : first_(nullptr), size_(0) {}  // CTOR
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
  }  // Copy-CTOR
  ~List() {
    clear();
    delete first_;
  }  // DTOR
  const List<T>& operator=(const List<T>& list) {
    List<T> tmp(list);
    first_ = tmp.first_;
    size_ = tmp.size_;
    tmp.first_ = nullptr;
    return *this;
  }  // Copy-assignment
  List<T>& operator=(List&& list) noexcept {
    std::swap(list, *this);
    list.clear();
    return *this;
  }  // Move-assignment
  bool empty() const noexcept {
    return size_ == 0;
  }  // checks whether the container is empty
  size_t size() const noexcept {
    return size_;
  }  // returns the number of elements
  const T& front() const {
    if (empty()) {
      throw std::string("List is empty");
    }
    return first_->data_;
  }  // access the first element
  void push_front(const T& elem) {
    Node* node = new Node(elem, first_);
    first_ = node;
    size_++;
  }  // inserts an element to the beginning
  void pop_front() noexcept {
    if (empty()) return;
    Node* tmp(first_);
    first_ = first_->next_;
    delete tmp;
    size_--;
  }  // removes the first element
  void resize(size_t size) {
    if (size_ == size) {
      return;
    }
    if (size_ > size) {
      do {
        pop_front();
      } while (size_ > size);
    } else {
      T empty_elem{};
      do {
        push_front(empty_elem);
      } while (size_ < size);
    }
  }  // changes the number of elements stored from the beginnig (as in stack)
  void clear() noexcept {
    while (first_ != nullptr) {
      Node* tmp = first_;
      first_ = first_->next_;
      delete tmp;
    }
    size_ = 0;
  }  // clears the contents +
  void remove(const T& elem) {
    if (empty()) {
      return;
    }
    while (first_ != nullptr && first_->data_ == elem) {
      Node* tmp = first_;
      first_ = first_->next_;
      delete tmp;
      size_--;
    }
    if (empty() || size_ == 1) {
      return;  // because it cannot be size_== 1 and first_->data_==elem (in
               // that case first_ will be nullptr)
    }
    Node* cur = first_->next_;
    Node* prev = first_;
    for (; cur != nullptr;) {
      if (cur->data_ == elem) {
        Node* tmp = cur;
        cur = cur->next_;
        prev->next_ = cur;
        delete tmp;
        size_--;
      } else {
        prev = prev->next_;
        cur = cur->next_;
      }
    }
  }  // removes all elements that are equal to passed value
  void reverse() {
    List<T> tmp;
    for (Node* cur = first_; cur != nullptr; cur = cur->next_) {
      tmp.push_front(cur->data_);
    }
    first_ = tmp.first_;
    tmp.first_ = nullptr;
  }  // reverses the order of the elements
  void swap(List<T>& b) noexcept {
    std::swap(this->first_, b.first_);
    std::swap(this->size_, b.size_);
  }  // swaps content of two lists
  iterator begin() const noexcept { return iterator(first_); }
  iterator end() const noexcept { return iterator(nullptr); }
  void push_after(iterator& it, const T& elem) {
    Node* tmp = new Node(elem, it.cur_->next_);
    it.cur_->next_ = tmp;
  }
  void erase_after(iterator& it) { Node* tmp = it.cur_->next_;
    if (it.cur_->next_ != nullptr && it.cur_->next_->next_ != nullptr) {
      it.cur_->next_ = it.cur_->next_->next_;
    }
    delete tmp;
  }
};
template <class T>
void swap(List<T>& a, List<T>& b) {
  a.swap(b);
}

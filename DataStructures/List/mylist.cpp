#include "mylist.h"

bool List<class T>::empty() const noexcept { return size_ == 0; }
size_t List<class T>::size() const noexcept { return size_; }
void List<class T>::push_front(const T& elem) {
  Node<T>* node = new Node<T>(elem, nullptr, first_);
  first_ = node;
  size_++;
}
void List<class T>::pop_front() noexcept {
  if (size_ == 0) return;
  Node<T>* tmp(first_);
  first_ = first_->next_;
  delete tmp;
  size_--;
}
const T& List<class T>::front() const {
  if (size_ == 0) {
    throw std::string("List is empty");
  }
  return first_->data_;
}
void List<class T>::clear() noexcept {
  while (first_ != nullptr) {
    Node<T>* tmp = first_;
    first_ = first_->next_;
    delete tmp;
  }
  size_ = 0;
}
void List<class T>::remove(const T& elem) {
  if (size_ == 0) {
    return;
  }
  while (first_ != nullptr && first_->data_ == elem) {
    Node<T>* tmp = first_;
    first_ = first_->next_;
    delete tmp;
    size_--;
  }
  Node<T>* cur = first_->next_;
  Node<T>* prev = first_;
  for (Node<T>* prev = first_; cur != nullptr; prev = prev->next_) {
    if (cur->data_ == elem) {
      Node<T>* tmp = cur;
      cur = cur->next_;
      prev->next_ = cur;
      delete tmp;
      size_--;
    }
  }
}
void List<class T>::resize(size_t size) {
  if (size == size_) {
    return;
  }
  if (size < size_) {
    Node<T>* cur = first_;
    for (int i = 1; i < size; i++) {
      cur = cur->next_;
    }
    if (size_ > 0) {
      {
        cur = cur->next_;
        while (cur != nullptr) {
          Node<T>* tmp = cur;
          cur = cur->next_;
          delete tmp;
        }
      }
    }
    size_ = size;
  } else {
    T* empty_data = new T{0};
    Node<T>* cur = first_;
    for (; cur->next_ != nullptr; cur = cur->next_)
      ;
    for (; size_ <= size; size_++) {
      cur->next_ = new Node<T>(empty_data);
      cur = cur->next_;
    }
  }
}
void List<class T>::reverse() {
  if (first_ == nullptr || first_->next_ == nullptr) {
    return;
  }
  Node<T>* reverse_cur = first_;
  reverse_cur->next_ = nullptr;
  for (Node<T>* cur = first_; cur->next_ != nullptr; cur = cur->next_) {
    reverse_cur = cur->next_;
    reverse_cur->next_ = cur;
  }
  first_ = reverse_cur;
}
const List<class T>& List<class T>::operator=(const List<T>& list) {
  List<T> tmp(list);
  std::swap(tmp, *this);
}
List<class T>& List<class T>::operator=(List&& list) noexcept {
  std::swap(list, *this);
  list.clear();
}

List<class T>::List(const List<T>& list) {
  if (list.first_ == nullptr) {
    size_ = 0;
    first_ = nullptr;
    return;
  }
  first_ = new Node<T>(*list.first_);
  size_ = 1;
  for (Node<T> *other_cur = list.first_, *this_cur = first_;
       other_cur->next_ != nullptr;
       other_cur = other_cur->next_, this_cur = this_cur->next_) {
    this_cur->next_ = new Node<T>(other_cur->next_->data_);
    size_++;
  }
}

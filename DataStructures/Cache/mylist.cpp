#include "mylist.h"

#include <vector>
bool List<class T>::empty() const { return size_ == 0; }
size_t List<class T>::size() const { return size_; }
void List<class T>::push_front(const T& elem) {
  Node<T>* node{elem, nullptr, (*this).first_};
  first_ = node;
  size_++;
}
void List<class T>::pop_front() {
  if (first_ == nullptr) return;
  Node<T>* tmp(first_);
  first_ = first_->next_;
  delete tmp;
  size_--;
}
const T& List<class T>::front() const {
  if (first_ == nullptr)
    ///////////////////////////////////////////////////////////
    return first_->data_;
}
void List<class T>::clear() {
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
      size_ = size;
    }
  } else {
    T elem;

    /////////////////////////////////////////////////
  }
}

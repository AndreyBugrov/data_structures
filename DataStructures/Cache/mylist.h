#pragma once
template <class T>
class List {
 protected:
  template <class T>
  struct Node {
    T data_;
    Node* prev_;
    Node* next_;
    Node(T data, Node* prev = nullptr, Node* next = nullptr)
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
  Node<T>* first_;
  size_t size_;

 public:
  List() : first_(nullptr), size_(0) {}  // CTOR +
  List(const List<T>& list)
      : first_(list.first_), size_(list.size_) {}  // Copy-CTOR +
  ~List() { clear(); }                             // DTOR +
  const List<T>& operator=(const List<T>& list);   // Copy-assignment
  List<T>& operator=(List<T>&& list);              // Move-assignment
  bool empty() const noexcept;     // checks whether the container is empty +
  size_t size() const noexcept;    // returns the number of elements +
  const T& front() const;          // access the first element
  void push_front(const T& elem);  // inserts an element to the beginning
  void pop_front() noexcept;       // removes the first element
  void resize(size_t size);        // changes the number of elements stored
  void clear() noexcept;           // clears the contents +
  void remove(const T& elem);   // removes all elements that are equal to passed value +
  void reverse();  // reverses the order of the elements
};

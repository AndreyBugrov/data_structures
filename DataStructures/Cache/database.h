#pragma once

// Consider two interacting systems. The first one – database that stores
// information about users, the second one – uses that information for decision
// making. Users usually use the system in periods (sessions) and make a lot of
// requests during the session. There is a fairly large time interval between
// sessions. We would like to save database resources and, if possible, return
// already stored result instead of execute repeated queries again. According to
// the system description you must design and implement efficient class for
// storing cache in C++. Then describe the complexity of your algorithm using O
// notation, write sample simulates the behavior of the system and calculate two
// metrics: cache hits and misses.

namespace std {
template <class Key>
struct hash {
  size_t operator()(const Key& key) const noexcept { return 0; }
};
}  // namespace std

#include <functional>  // std::hash
#include <string>
//#include <utility> // pair
//#include <memory> // allocator

// template <class Key= std::string, class T=std::string, class Hash =
// std::hash<Key>,
//          class Pred = std::equal_to<Key>>
// class Alloc = std::allocator<std::pair<const Key, T>>

template <class T, class Key = std::string>
class Cache {
 protected:
  // std::allocator<std::pair<const Key, T>> allocator_;
  std::pair<T, Key>** cache_;
  size_t jmp_num;
  std::hash<Key> hash_;
  size_t size_;

 public:
  Cache(size_t base_num = 1024) : size_(base_num) {
    cache_ = new std::pair<T, Key>*[size_];
    if (base_num % 3) {
      jmp_num = 3;
    } else {
      jmp_num = base_num - 1;
    }
  }
  const T* c_find(const Key& key) const;
  T* find(const Key& key) const;
  std::pair&<Key*, bool> insert(const Key& key, const T& val);
  ~Cache() { delete[] cache_; }
};

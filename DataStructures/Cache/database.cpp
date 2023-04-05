#include "database.h"
//Key* Cache<class Key, class T, class Hash, class Pred>::find(const Key& key)const {
//}
T* Cache<class T, class Key>::find(const Key& key) const {
  size_t pos = hash_(key);
  if (cache_[pos] == nullptr) {
    return nullptr;
  } else {
    while (cache_[pos]->first != key) {
    }
  }
}

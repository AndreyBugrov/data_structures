#include "mylist.h"
#include <iostream>
int main() { 
  List<int> l1;
  List<int> l2;
  for (int i = 0; i < 5; i++) {
    l2.push_front(i);
  }
  l2.pop_front();
  int two = l2.front();
  std::cout << two << "\n";
  l1 = l2;
  return 0; }
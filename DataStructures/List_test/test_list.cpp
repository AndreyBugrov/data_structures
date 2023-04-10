#include <gtest.h>

#include "../List/list.h"
TEST(List, can_create_empty_list) {
  ASSERT_NO_THROW(List<int> l);
  ASSERT_NO_THROW(List<std::string> l1);
}
TEST(List, empty_list_shows_that_it_is_empty) {
  List<int> l;
  ASSERT_EQ(l.empty(), true);
}
TEST(List, empty_list_shows_zero_size) {
  List<int> l;
  ASSERT_EQ(l.size(), 0);
}
TEST(List, can_push_front_element) { 
  List<int> l;
  ASSERT_NO_THROW(l.push_front(3));
}
TEST(List, pushing_front_increases_size) {
  List<int> l;
  l.push_front(3);
  ASSERT_EQ(l.size(), 1);
  l.push_front(-4);
  ASSERT_EQ(l.size(), 2);
}
TEST(List, non_empty_list_shows_that_it_is_non_empty) {
  List<int> l;
  l.push_front(3);
  ASSERT_EQ(l.empty(), false);
}
TEST(List, can_return_front_element) {
  List<int> l;
  l.push_front(3);
  l.push_front(-4);
  ASSERT_EQ(l.front(), -4);
}
TEST(List, returning_front_element_does_not_change_size) {
  List<int> l;
  l.push_front(3);
  l.front();
  ASSERT_EQ(l.size(), 1);
}
TEST(List, cant_return_front_element_from_empty_list) {
  List<int> l;
  ASSERT_ANY_THROW(l.front());
}
TEST(List, can_pop_front_element) {
  List<int> l;
  l.push_front(3);
  ASSERT_NO_THROW(l.pop_front());
}
TEST(List, poping_front_element_decreases_size) {
  List<int> l;
  l.push_front(3);
  l.push_front(-4);
  l.pop_front();
  ASSERT_EQ(l.size(), 1);
}
TEST(List, pop_only_front_element) {
  List<int> l;
  l.push_front(3);
  l.push_front(-4);
  l.pop_front();
  ASSERT_EQ(l.front(), 3);
}
TEST(List, poping_front_element_from_empty_list_does_nothing) {
  List<int> l;
  ASSERT_NO_THROW(l.pop_front());
  ASSERT_EQ(l.size(), 0);
}

//
//TEST(List, ){List<int> l; ASSERT_} 
// TEST(List, ){List<int> l;l.push_front(3); ASSERT_} 
// TEST(List, ){ASSERT_} TEST(List, ) {
//  ASSERT_
//}
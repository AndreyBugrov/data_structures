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
TEST(List, can_create_list_from_list) {
  List<int> l;
  l.push_front(3);
  ASSERT_NO_THROW(List<int> l1(l));
}
TEST(List, creates_equal_list_from_list) {
  List<int> l;
  l.push_front(3);
  List<int> l1(l);
  ASSERT_EQ(l1.size(), 1);
  ASSERT_EQ(l1.front(), 3);
}
TEST(List, can_assign_list_a_value_of_list) {
  List<int> l1;
  l1.push_front(3);
  List<int> l2;
  l2.push_front(-42);
  ASSERT_NO_THROW(l2 = l1);
}
TEST(List, assigns_list_a_value_of_list_and_they_are_equal) {
  List<int> l1;
  l1.push_front(3);
  List<int> l2;
  l2.push_front(-42);
  l2.push_front(99);
  l2 = l1;
  ASSERT_EQ(l2.size(), 1);
  ASSERT_EQ(l2.front(), 3);
}
TEST(List, can_resize_empty_list) {
  List<int> l;
  ASSERT_NO_THROW(l.resize(7));
}
TEST(List, resizes_empty_list_by_empty_values) {
  List<int> l;
  l.resize(10);
  ASSERT_EQ(l.size(), 10);
  int empty_value = l.front();
  l.pop_front();
  ASSERT_EQ(l.front(), empty_value);
}
TEST(List, resize_can_increase_size_of_non_empty_list) {
  List<int> l;
  l.push_front(3);
  l.resize(2);
  ASSERT_EQ(l.size(), 2);
  l.pop_front();
  ASSERT_EQ(l.front(), 3);
}
TEST(List, resize_can_decrease_size_of_non_empty_list) {
  List<int> l;
  l.push_front(3);
  l.push_front(31);
  l.push_front(-5);
  l.resize(1);
  ASSERT_EQ(l.size(), 1);
  ASSERT_EQ(l.front(), 3);
}
TEST(List, resize_can_make_non_empty_list_empty) {
  List<int> l;
  l.push_front(3);
  l.push_front(31);
  l.resize(0);
  ASSERT_EQ(l.empty(), true);
}
TEST(List, can_clear_empty_list) {
  List<int> l;
  ASSERT_NO_THROW(l.clear());
}
TEST(List, cleared_list_is_empty) {
  List<int> l;
  l.push_front(3);
  l.push_front(31);
  l.clear();
  ASSERT_EQ(l.size(), 0);
}
TEST(List, do_not_remove_element_from_empty_list) {
  List<int> l;
  ASSERT_NO_THROW(l.remove(16));
}
TEST(List, removes_one_element) {
  List<int> l;
  l.push_front(3);
  l.push_front(31);
  l.remove(31);
  ASSERT_EQ(l.size(), 1);
  ASSERT_EQ(l.front(), 3);
}
TEST(List, removes_many_elements_1) {
  List<int> l;
  for (int i = 9; i < 13; i++) {
    if (i % 3 != 0)
      l.push_front(i);
    else
      l.push_front(3);
  }
  l.remove(3);
  ASSERT_EQ(l.size(), 2);
  ASSERT_EQ(l.front(), 11);
  l.pop_front();
  ASSERT_EQ(l.front(), 10);
}
TEST(List, removes_many_elements_2) {
  List<int> l;
  for (int i = 9; i < 13; i++) {
    if (i % 3 == 0)
      l.push_front(i);
    else
      l.push_front(3);
  }
  l.remove(3);
  ASSERT_EQ(l.size(), 2);
  ASSERT_EQ(l.front(), 12);
  l.pop_front();
  ASSERT_EQ(l.front(), 9);
}
TEST(List, does_not_remove_non_existant_element) {
  List<int> l;
  l.push_front(3);
  l.push_front(31);
  l.remove(5);
  ASSERT_EQ(l.size(), 2);
}
TEST(List, can_remove_every_element) {
  List<int> l;
  for (int i = 9; i < 13; i++) {
      l.push_front(3);
  }
  l.remove(3);
  ASSERT_EQ(l.size(), 0);
}
TEST(List, can_reverse_empty_list) {
  List<int> l;
  ASSERT_NO_THROW(l.reverse());
}
TEST(List, reverses_list_with_one_element) {
  List<int> l;
  l.push_front(3);
  l.reverse();
  ASSERT_EQ(l.front(), 3);
  ASSERT_EQ(l.size(), 1);
}
TEST(List, reverses_list_with_many_elements) {
  List<int> l;
  l.push_front(-5);
  l.push_front(3);
  l.push_front(31);
  l.reverse();
  ASSERT_EQ(l.size(), 3);
  ASSERT_EQ(l.front(), -5);
  l.pop_front();
  ASSERT_EQ(l.front(), 3);
  l.pop_front();
  ASSERT_EQ(l.front(), 31);
}
//
// TEST(List, ){List<int> l; ASSERT_}
// TEST(List, ){List<int> l;l.push_front(3); ASSERT_}
// TEST(List, ){List<int> l1;l1.push_front(3); List<int>
// l2;l2.push_front(-42);ASSERT_} TEST(List, ) {
//  ASSERT_
//}
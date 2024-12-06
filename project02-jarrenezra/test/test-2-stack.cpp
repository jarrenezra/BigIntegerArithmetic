#include <limits>

#include "../stack.hpp"
#include "catch/catch.hpp"

TEST_CASE("class Stack") {
  Stack s;
  s.push(50);
  CHECK(!s.empty());
  CHECK(50 == s.peek());
  CHECK(50 == s.pop());
  CHECK(s.empty());  // only element was just popped, should be empty

  // Safe to pop from empty stack??
  // return negative value when empty
  CHECK(-1 == s.pop());
}

TEST_CASE("Push/Pop many") {
  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);
  // 30 -> 20 -> 10

  CHECK(30 == s.pop());
  CHECK(20 == s.pop());
  CHECK(10 == s.pop());
  CHECK(s.empty());  // only element was just popped, should be empty
  CHECK(-1 == s.pop());
}

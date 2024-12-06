#include "../stack.hpp"
#include "catch/catch.hpp"

TEST_CASE("Test default Node (next)") {
  Node n(50);
  CHECK(50 == n.getValue());
  CHECK(nullptr == n.getNext());
}

TEST_CASE("Test Node") {
  Node* next = new Node(30);
  Node n(50);
  n.setNext(next);
  CHECK(50 == n.getValue());
  CHECK(next == n.getNext());
  delete next;
}

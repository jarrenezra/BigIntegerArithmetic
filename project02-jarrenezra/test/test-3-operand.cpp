#include "../operand.hpp"
#include "catch/catch.hpp"

TEST_CASE("class Operand") {
  Operand o("1234567");
  CHECK(!o.isNegative());
  CHECK("1234567" == o.getValue());

  // setter
  o.setValue("76567840346789678565785986759874321");
  CHECK("76567840346789678565785986759874321" == o.getValue());

  // positive sign is removed
  Operand o1("+1234567");
  CHECK(!o1.isNegative());
  CHECK("1234567" == o1.getValue());

  // negative sign is kept
  Operand o2("-1234567");
  CHECK(o2.isNegative());
  CHECK("-1234567" == o2.getValue());

  // test flip sign
  o2.flipSign();
  CHECK(!o2.isNegative());
  CHECK("1234567" == o2.getValue());
}

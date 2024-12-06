#include <sstream>

#include "../arithmetic-expression.hpp"
#include "catch/catch.hpp"

TEST_CASE("class ArithmeticExpression") {
  ArithmeticExpression ae("1234567", "23456", '+');
  CHECK("1234567" == ae.getOp1());
  CHECK("23456" == ae.getOp2());
  CHECK('+' == ae.getOperator());

  // The sign of the second operand should be merged with the operator
  ArithmeticExpression aeNegative("1234567", "-23456", '+');
  CHECK("1234567" == aeNegative.getOp1());
  CHECK("23456" == aeNegative.getOp2());
  CHECK('-' == aeNegative.getOperator());

  // The sign of the second operand should be merged with the operator
  ArithmeticExpression aeDoubleNeg("1234567", "-23456", '-');
  CHECK("1234567" == aeDoubleNeg.getOp1());
  CHECK("23456" == aeDoubleNeg.getOp2());
  CHECK('+' == aeDoubleNeg.getOperator());

  // first operand being negative
  ArithmeticExpression aeFirstNegative("-1234567", "23456", '+');
  CHECK("-1234567" == aeFirstNegative.getOp1());
  CHECK("23456" == aeFirstNegative.getOp2());
  CHECK('+' == aeFirstNegative.getOperator());
}

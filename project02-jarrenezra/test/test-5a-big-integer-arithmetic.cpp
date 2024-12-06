#include<sstream>

#include "catch/catch.hpp"
#include "../arithmetic-expression.hpp"
#include "../big-integer-arithmetic.hpp"

TEST_CASE("class BigIntegerArithmetic part a")
{
  ArithmeticExpression ae;

  SECTION ("Simple sum")
  {
    ae = ArithmeticExpression("200","100",'+');
    BigIntegerArithmetic bia(ae);
    CHECK(0 < bia.operandComp(ae.getOp1(),ae.getOp2()));
    CHECK(" 200\n+100\n 300" == bia.getResults());
  }

  SECTION ("Bigger operand second")
  {
    ae = ArithmeticExpression("100","200",'+');
    BigIntegerArithmetic bia(ae);
    CHECK(0 > bia.operandComp(ae.getOp1(),ae.getOp2()));
  }

  SECTION ("Operands are equal")
  {
    ae = ArithmeticExpression("200","200",'+');
    BigIntegerArithmetic bia(ae);
    CHECK(0 == bia.operandComp(ae.getOp1(),ae.getOp2()));
  }

  SECTION ("1st operand much larger")
  {
    ae = ArithmeticExpression("10000","900",'+');
    BigIntegerArithmetic bia(ae);
    CHECK(0 < bia.operandComp(ae.getOp1(),ae.getOp2()));
  }

  SECTION ("2nd operand much larger")
  {
    ae = ArithmeticExpression("200","1000",'+');
    BigIntegerArithmetic bia(ae);
    CHECK(0 > bia.operandComp(ae.getOp1(),ae.getOp2()));
  }
}
#include<sstream>

#include "catch/catch.hpp"
#include "../arithmetic-expression.hpp"
#include "../big-integer-arithmetic.hpp"

TEST_CASE("class BigIntegerArithmetic")
{
	ArithmeticExpression ae;

	SECTION ("Large sum")
	{
		ae = ArithmeticExpression("364287463834623846283426384","923742938742934723947239847",'+');
		BigIntegerArithmetic bia(ae);
		CHECK("  364287463834623846283426384\n+ 923742938742934723947239847\n 1288030402577558570230666231" == bia.getResults());
	}

	SECTION ("Large subtraction")
	{
		ae = ArithmeticExpression("364287463834623846283426384","923742938742934723947239847",'-');
		BigIntegerArithmetic bia(ae);
		CHECK(" 364287463834623846283426384\n-923742938742934723947239847\n-559455474908310877663813463" == bia.getResults());
	}

	SECTION ("Subtracting larger - negative result")
	{
		ae = ArithmeticExpression("200","1000",'-');
		BigIntegerArithmetic bia(ae);
		REQUIRE("  200\n-1000\n -800" == bia.getResults());
	}

}

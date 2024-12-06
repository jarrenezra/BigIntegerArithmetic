#include<sstream>

#include "catch/catch.hpp"
#include "../expression-reader.hpp"


TEST_CASE("class ExpressionReader")
{
	ExpressionReader er("test/expressions.txt");
	CHECK(er.readNextExpression());
	CHECK(" 12\n+ 5\n 17" == er.getResult());

  CHECK(er.readNextExpression());
	CHECK("  5\n+12\n 17" == er.getResult());

  CHECK(er.readNextExpression());
	CHECK(" 12\n- 5\n  7" == er.getResult());

  CHECK(er.readNextExpression());
	CHECK("  5\n-12\n -7" == er.getResult());

  CHECK(er.readNextExpression());
	CHECK("  364287463834623846283426384\n+ 923742938742934723947239847\n 1288030402577558570230666231" == er.getResult());

  CHECK(er.readNextExpression());
	CHECK(" 364287463834623846283426384\n-923742938742934723947239847\n-559455474908310877663813463" == er.getResult());

	// no more expressions in file. Bad read should be safe
	CHECK(!er.readNextExpression());
}

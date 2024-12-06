#ifndef ARITHMETIC_EXPRESSION_HPP
#define ARITHMETIC_EXPRESSION_HPP

#include <string>
#include "operand.hpp"

class ArithmeticExpression
{

private:
    Operand firstValue;
    Operand secondValue;
    char operand;

public:
    ArithmeticExpression() = default;
    ArithmeticExpression(std::string, std::string, char);
    std::string getOp1();
    std::string getOp2();
    char getOperator();
};

#endif
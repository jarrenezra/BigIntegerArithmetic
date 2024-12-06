#include "arithmetic-expression.hpp"

ArithmeticExpression::ArithmeticExpression(std::string firstNumber, std::string secondNumber, char operationArg)
{
    firstValue.setValue(firstNumber);
    secondValue.setValue(secondNumber);
    operand = operationArg;
}

std::string ArithmeticExpression::getOp1()
{
    return firstValue.getValue();
}
std::string ArithmeticExpression::getOp2()
{
    if (secondValue.isNegative() && operand == '+')
    {
        std::string temp = secondValue.getValue();
        temp.erase(0, 1);
        secondValue.setValue(temp);
        operand = '-';
    }
    else if (secondValue.isNegative() && operand == '-')
    {
        std::string temp = secondValue.getValue();
        temp.erase(0, 1);
        secondValue.setValue(temp);
        operand = '+';
    }

    return secondValue.getValue();
}
char ArithmeticExpression::getOperator()
{
    return operand;
}
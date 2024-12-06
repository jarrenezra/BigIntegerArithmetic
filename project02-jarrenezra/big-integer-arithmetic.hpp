#ifndef BIG_INTEGER_ARITHMETIC_HPP
#define BIG_INTEGER_ARITHMETIC_HPP

#include "arithmetic-expression.hpp"
#include "stack.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

class BigIntegerArithmetic
{
private:
    ArithmeticExpression mathExpression;
    std::string firstNumber;
    std::string secondNumber;
    std::string sum;
    Stack topPortion;           // stack for integers
    Stack bottomPortion;        // stack for integers
    SStack stringTopPortion;    // stack for strings (for subtract)
    SStack stringBottomPortion; // stack for strings (for subtract)
public:
    BigIntegerArithmetic() = default;
    BigIntegerArithmetic(ArithmeticExpression);
    int operandComp(std::string, std::string);
    void prepareAdd(); // will push portion of the big numbers in numberPortion stack, they will always be paired with top portion and low portion.
    // example:
    // 123,456,789,123 + 987,654,321,987
    // push 987 push 123 push 321 push 789 and so on.
    void prepareSubtract();
    std::string add();
    std::string subtract();
    std::string getResults();
};

#endif
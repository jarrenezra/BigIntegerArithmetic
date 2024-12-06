#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <string>

class Operand
{
private:
    std::string value;

public:
    Operand();
    Operand(std::string);
    bool isNegative();
    std::string getValue();
    void setValue(std::string);
    void flipSign();
};

#endif
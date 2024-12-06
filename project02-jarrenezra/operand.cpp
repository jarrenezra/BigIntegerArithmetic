#include "operand.hpp"

Operand::Operand()
{
    value = "\0";
}

Operand::Operand(std::string number)
{
    value = number;
    if(value[0] == '+')
        value.erase(0,1);
}

bool Operand::isNegative()
{
    if (value[0] == '-')
        return true;
    else
        return false;
}

std::string Operand::getValue()
{
    return value;
}

void Operand::setValue(std::string value)
{
    this->value = value;
}

void Operand::flipSign()
{
    if (isNegative() == false)
        value.insert(0, "-");
    else
    {
        value.erase(0, 1);
    }
}
#include "expression-reader.hpp"
#include <iostream>

int main()
{
    ExpressionReader er("test/expressions.txt");
    while (er.readNextExpression())
    {
        std::cout << er.getResult() << "\n----------\n";
        
    }

    return 0;
}
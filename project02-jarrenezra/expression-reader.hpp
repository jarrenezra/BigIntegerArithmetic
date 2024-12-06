#ifndef EXPRESSION_READER_HPP
#define EXPRESSION_READER_HPP
#include "big-integer-arithmetic.hpp"
#include <fstream>
#include <vector>

class ExpressionReader
{
private:
    std::ifstream file;
    std::string lineFromFile;
    std::string result;

public:
    ExpressionReader(const std::string&);
    ~ExpressionReader();
    bool readNextExpression();
    std::string readLine();
    std::string getResult();
};

#endif
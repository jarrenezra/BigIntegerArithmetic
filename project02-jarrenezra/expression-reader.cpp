#include "expression-reader.hpp"

ExpressionReader::ExpressionReader(const std::string &filePath)
{
    result = "\0";
    lineFromFile = "\0";
    file.open(filePath);
    if (!file.is_open())
        std::cerr << "Failed to open the file: " << filePath << std::endl;
}

ExpressionReader::~ExpressionReader()
{
    if (file.is_open())
    {
        file.close();
    }
}

bool ExpressionReader::readNextExpression()
{
    lineFromFile = readLine();
    std::istringstream iss(lineFromFile);
    std::vector<std::string> arithmeticEx;
    std::string part;
    ArithmeticExpression ae;
    BigIntegerArithmetic bia;
    if(lineFromFile.size() < 1)
    {
        return false;
    }
    while (iss >> part)
    {
        arithmeticEx.push_back(part);
    }

    ae = ArithmeticExpression(arithmeticEx.at(0), arithmeticEx.at(2), arithmeticEx.at(1)[0]);
    bia = BigIntegerArithmetic(ae);
    result = bia.getResults();
    return true;
}

std::string ExpressionReader::readLine()
{
    std::string line;
    if (std::getline(file, line))
    {
        return line;
    }
    return ""; // Return an empty string if no more lines
}

std::string ExpressionReader::getResult()
{
    return result;
}
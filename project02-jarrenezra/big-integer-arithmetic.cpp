#include "big-integer-arithmetic.hpp"

BigIntegerArithmetic::BigIntegerArithmetic(ArithmeticExpression mathExArg)
{
    mathExpression = mathExArg;
    firstNumber = mathExpression.getOp1();
    secondNumber = mathExpression.getOp2();
    sum = "\0";
}

std::string BigIntegerArithmetic::getResults()
{
    std::stringstream stringStreamObj;
    std::string stringVersionOperator;

    int checkSizes = operandComp(firstNumber, secondNumber);
    int bigNumberLength;

    if (mathExpression.getOperator() == '+')
    {
        stringVersionOperator = "+";
        add();
    } // turn char to string so that I can concatenate
    else if (mathExpression.getOperator() == '-')
    {
        stringVersionOperator = "-";
        subtract();
    }

    if (!(sum[0] == '-'))//if a positive number
        sum = ' ' + sum;

    if (checkSizes == 1 || checkSizes == 0)
    {
        bigNumberLength = firstNumber.size()+1;
    } // for first column

    else if (checkSizes == -1)
    {
        bigNumberLength = firstNumber.size() + 1; // for first column
    }

    if (sum.size() > firstNumber.size())
    {
        bigNumberLength = sum.size();
    }


    if (sum[0] == '-')
    {
        stringStreamObj.clear();
        stringStreamObj << std::setfill(' ') << std::setw(bigNumberLength) << std::right << mathExpression.getOp1() << '\n';

        stringStreamObj << stringVersionOperator << std::setw(bigNumberLength - 1) << std::right << mathExpression.getOp2() << '\n';

        stringStreamObj << std::setw(bigNumberLength) << std::right << sum;
    }
    else
    {

        stringStreamObj.clear();
        stringStreamObj << std::setfill(' ') << std::setw(bigNumberLength) << std::right << mathExpression.getOp1() << '\n';

        stringStreamObj << stringVersionOperator << std::setw(bigNumberLength - 1) << std::right << mathExpression.getOp2() << '\n';

        stringStreamObj << std::setw(bigNumberLength) << std::right << sum;
    }
    return stringStreamObj.str();
}

int BigIntegerArithmetic::operandComp(std::string firstNumber, std::string secondNumber)
{
    int comparedLength = 0; // this is to compare i to, like i < comparedLength.
    int topDigit;
    int bottomDigit;
    if (firstNumber.size() > secondNumber.size())
    {
        // add zeroes to the start only if they're not divisible by 9 since I don't know if they're gonna have the same digits or not and this will be useful for subtraction.

        return 1;
    }
    else if (firstNumber.size() < secondNumber.size())
    {
        return -1;
    }
    else if (firstNumber.size() == secondNumber.size())
    {
        comparedLength = firstNumber.size();
    }

    for (int i = 0; i < comparedLength; ++i)
    {
        topDigit = firstNumber[i] - '0';
        bottomDigit = secondNumber[i] - '0';
        if (topDigit > bottomDigit)
        {
            return 1;
        }
        else if (topDigit < bottomDigit)
        {
            return -1;
        }
    }
    return 0; // return zero if digits and size are the same e.g. 9999-9999
}

void BigIntegerArithmetic::prepareAdd()
{ // go and keep taking at least 9 digits from the string
    // int j = operandComp(firstNumber, secondNumber);
    std::string fnCopy = firstNumber;
    std::string snCopy = secondNumber;
    std::string extracted;
    int startIndex; // this variable stores the index of extraction;
    const int lengthToExtract = 9;

    if (!(fnCopy.size() % 9 == 0))
    {
        while (!(fnCopy.size() % 9 == 0)) // while not divisible by 9
        {
            fnCopy = "0" + fnCopy;
        }
    }

    if (!(snCopy.size() % 9 == 0)) // while not divisible by 9
    {
        while (!(snCopy.size() % 9 == 0))
        {
            snCopy = "0" + snCopy;
        }
    }

    if (!(snCopy.size() == fnCopy.size())) // force to be the same size
    {
        if (snCopy.size() < fnCopy.size())
        {
            while (!(snCopy.size() == fnCopy.size())) // while not same size
            {
                snCopy = "0" + snCopy;
            }
        }
        else
        {
            while (!(snCopy.size() == fnCopy.size())) // while not same size
            {
                fnCopy = "0" + fnCopy;
            }
        }
    }

    while (fnCopy.size() > lengthToExtract)
    {

        startIndex = 0; // Length - 10

        extracted = fnCopy.substr(startIndex, lengthToExtract);

        topPortion.push(std::stoi(extracted));

        fnCopy.erase(startIndex, lengthToExtract);
    }
    while (snCopy.size() > lengthToExtract)
    {

        startIndex = 0; // Length - 10

        extracted = snCopy.substr(startIndex, lengthToExtract);

        bottomPortion.push(std::stoi(extracted));

        snCopy.erase(startIndex, lengthToExtract);
    }

    topPortion.push(std::stoi(fnCopy));
    bottomPortion.push(std::stoi(snCopy));

}

std::string BigIntegerArithmetic::add()
{
    sum = "\0";
    prepareAdd();
    int topNumberPopped;    // popped from stack
    int bottomNumberPopped; // popped from stack
    int carry = 0;          // will carry index 0 of the string
    std::string numberStringForm;

    while (true)
    {

        if (!(topPortion.peek() == -1))
        {
            topNumberPopped = topPortion.pop();
            bottomNumberPopped = bottomPortion.pop();
        }
        else
        {
            if(carry > 0)//if there's a carry.
                sum = "1" + sum;
            
            break;
        }

        topNumberPopped = topNumberPopped + bottomNumberPopped + carry;
        if (!(carry == 0))
            carry = 0; // carry reset after added

        numberStringForm = std::to_string(topNumberPopped);
        if (numberStringForm.size() > 9)
        {
            carry = numberStringForm[0] - 48; //it's the ascii value.
            numberStringForm.erase(0, 1); // after carry extraction, most significant digit needs to be erased.
        }
        sum = numberStringForm + sum;
    }
    return sum;
}

void BigIntegerArithmetic::prepareSubtract()
{
    std::string fnCopy = firstNumber;
    std::string snCopy = secondNumber;

    if (!(fnCopy.size() % 9 == 0))
    {
        while (!(fnCopy.size() % 9 == 0)) // while not divisible by 9
        {
            fnCopy = "0" + fnCopy;
        }
    }

    if (!(snCopy.size() % 9 == 0)) // while not divisible by 9
    {
        while (!(snCopy.size() % 9 == 0))
        {
            snCopy = "0" + snCopy;
        }
    }

    if (!(snCopy.size() == fnCopy.size())) // force to be the same size
    {
        if (snCopy.size() < fnCopy.size())
        {
            while (!(snCopy.size() == fnCopy.size())) // while not same size
            {
                snCopy = "0" + snCopy;
            }
        }
        else
        {
            while (!(snCopy.size() == fnCopy.size())) // while not same size
            {
                fnCopy = "0" + fnCopy;
            }
        }
    }


    std::string extracted;
    int startIndex; // this variable stores the index of extraction;
    const int lengthToExtract = 9;

    while (fnCopy.size() >= lengthToExtract)
    {

        // startIndex = fnCopy.size() - 9; // Length - 9
        startIndex = 0;

        extracted = fnCopy.substr(startIndex, lengthToExtract);

        stringTopPortion.push(extracted);
        fnCopy.erase(startIndex, lengthToExtract);
    }

    while (snCopy.size() >= lengthToExtract)
    {

        // startIndex = snCopy.size() - 9; // Length - 9
        startIndex = 0;

        extracted = snCopy.substr(startIndex, lengthToExtract);
        stringBottomPortion.push(extracted);
        snCopy.erase(startIndex, lengthToExtract);
    }
}

std::string BigIntegerArithmetic::subtract()
{
    sum = "\0";
    bool isNegative = false;
    std::string tempForSwap;
    if (operandComp(firstNumber, secondNumber) == 0) // meaning top and bottom are the same digit by digit
    {
        return "0";
    }
    else if (operandComp(firstNumber, secondNumber) == -1) // bottom is bigger, giving negative result
    {
        tempForSwap = firstNumber;
        firstNumber = secondNumber;
        secondNumber = tempForSwap;
        // sum = sum + "-";
        isNegative = true;
    }

    prepareSubtract();

    int topNumberDigit; // will store a number
    int bottomNumberDigit;
    const int BORROW = 10;
    bool borrowFlag = false;         // set if borrow is used, if set, add -1
    std::string topNumberStringForm; // string type.
    std::string botNumberStringForm; // string type.

    while (true)
    {

        if (!(stringTopPortion.peek() == ""))
        {
            topNumberStringForm = stringTopPortion.pop();
            botNumberStringForm = stringBottomPortion.pop();
        }
        else
        {                   // the top of the stack is -1 meaning it reached the end
            if (isNegative) // if negative flag is set, add the negative sign.
                sum = '-' + sum;
            break;
        }
        for (int i = topNumberStringForm.size() - 1; i > -1; --i)
        {
            // try 0 - 9
            topNumberDigit = topNumberStringForm[i]; // at the least significant digit
            bottomNumberDigit = botNumberStringForm[i];

            // subtract top digit to bottom digit, if result is negative, add borrow. if borrowed, set borrow flag, if borrow flag is set, add -1

            topNumberDigit -= bottomNumberDigit;

            if (topNumberDigit < 0) // if sum negative
            {
                topNumberDigit += BORROW;
                if (borrowFlag)
                    topNumberDigit += -1;
                borrowFlag = true;
            }
            else if (borrowFlag)
            {
                topNumberDigit += -1;
                if (topNumberDigit < 0)
                {
                    topNumberDigit += BORROW;
                    borrowFlag = true;
                }
                else
                    borrowFlag = false;
            }
            else
            {
                borrowFlag = false;
            }
            sum = std::to_string(topNumberDigit) + sum;
        }
    }

    if (sum[0] == '-') // we're gonna have zeroes at the most significant side, so this is to handle that
    {
        for (int i = 1; i < sum.size(); ++i)
        {
            if (sum[i] == '0')
                sum[i] = '\0';

            else
                break;
        }
    }
    else if (sum[0] == '0')
    {
        for (int i = 0; i < sum.size(); ++i)
        {
            if (sum[i] == '0')
                sum[i] = '\0';

            else
                break;
        }
    }

    sum.erase(std::remove(sum.begin(), sum.end(), '\0'), sum.end()); // removes null characters

    return sum;
}
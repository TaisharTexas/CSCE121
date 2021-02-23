#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;


unsigned int digit_to_decimal(char digit)
{
    if ((int)digit > 57 || (int)digit < 48)
    {
        throw std::invalid_argument("Invalid arguments -- not between 0 and 9");
    }
    else
    {
        return (digit - '0');
    }
}


char decimal_to_digit(unsigned int decimal)
{
		if (decimal > 9 || decimal < 0)
		{
				throw std::invalid_argument("Invalid arguments -- not between 0 and 9");
		}
		else
		{
				return (static_cast<char>(decimal));
		}

}


string trim_leading_zeros(string num) {

		string nonZeroNum;
		string finalNum;
		bool firstNum = false;
		bool isNegative = false;
		int theLength = num.length();

		for(int i = 0; i <= theLength; i++)
		{
				if(i == 0 && num[i] == '-')
				{
						isNegative = true;
				}
				if ((!(num[i] == '0')) && (!firstNum))
				{
						nonZeroNum += num[i];
						firstNum = true;
				}
				else if(firstNum)
				{
					nonZeroNum += num[i];
				}
		}

		cout << "nonZeroNum: " << nonZeroNum << endl;
		if(isNegative)
		{
				finalNum += '-';
				finalNum += nonZeroNum;
		}
		else
		{
				finalNum += nonZeroNum;
		}
		cout << "finalNum:   " << finalNum << endl;
    return finalNum;

}


string add(string lhs, string rhs) {
    // TODO(student): implement
		int leftNum;
		int rightNum;
		int sumNumber;
		string outputVal;
		try
		{
				leftNum = digit_to_decimal(lhs);
				rightNum = digit_to_decimal(rhs);
				sumNumber = leftNum + rightNum;
				outputVal = to_string(sumNumber);
		}
		catch(...)
		{
				cout << "exception thrown" << endl;
		}

		return "";

}


string multiply(string lhs, string rhs) {
    // TODO(student): implement
    return "";
}

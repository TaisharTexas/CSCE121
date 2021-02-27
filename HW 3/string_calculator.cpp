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
				return (decimal + '0');
		}

}


string trim_leading_zeros(string num) {

		// cout << "started trim"<< endl;
		string nonZeroNum;
		string finalNum;
		bool firstNum = false;
		bool isNegative = false;
		int theLength = num.length();

		// cout << "checkpoint" << endl;

		for(int i = 0; i < theLength; i++)
		{
				if(i == 0 && num.at(i) == '-')
				{
						// cout << "case 1" << endl;
						isNegative = true;
				}
				if ((!(num.at(i) == '0')) && (!firstNum))
				{
						// cout << "case 2" << endl;
						nonZeroNum += num.at(i);
						firstNum = true;
				}
				else if(firstNum)
				{
						// cout << "case 3" << endl;
						nonZeroNum += num.at(i);
				}
		}

		// cout << "nonZeroNum: " << nonZeroNum << endl;
		if(isNegative)
		{
				finalNum += '-';
				finalNum += nonZeroNum;
		}
		else
		{
				finalNum += nonZeroNum;
		}
		// cout << "finalNum:   " << finalNum << endl;
    return finalNum;

}


string add(string lhs, string rhs)
{
    // TODO(student): implement
		string finalNum = "";
		cout << "STARTED" << endl;
		string leftNum = trim_leading_zeros(lhs);
		// cout << "left zero trimmed" << endl;
		string rightNum = trim_leading_zeros(rhs);
		// cout << "right zero trimmed" << endl;
		int leftLength = leftNum.length();
		int rightLength = rightNum.length();
		cout << " left Length: " << leftLength << "\n right Length: " << rightLength << endl;
		bool carryNum = false;

		for(int i = leftLength-1; i >= 0; i--)
		{
				cout << abs(i - leftLength+1) << " run ----------- " << endl;

				int num1 = digit_to_decimal(leftNum.at(i));
				cout << " num 1: " << num1 << endl;
				int num2 = digit_to_decimal(rightNum.at(i));
				cout << " num 2: " << num2 << endl;
				int sum12 = num1 + num2;
				cout << "  sum12: " << sum12 << endl;
				if(carryNum)
				{
						sum12 += 1;
						carryNum = false;
						cout << "  carried a num " << endl;
				}
				if(sum12 > 9)
				{
						carryNum = true;
						sum12 -= 10;
						finalNum += decimal_to_digit(sum12);
						cout << "  final num: " << finalNum << endl;
				}
				else
				{
						carryNum = false;
						finalNum += decimal_to_digit(sum12);
						cout << "  final num: " << finalNum << endl;
				}

		}

		cout << "END OF SUMMATION ---------------" << endl;
		cout << "FINAL NUM: " << finalNum.reverse() << endl;

		return finalNum;

}


string multiply(string lhs, string rhs) {
    // TODO(student): implement
    return "";
}

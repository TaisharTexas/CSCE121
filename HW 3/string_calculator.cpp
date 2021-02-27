#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;


unsigned int digit_to_decimal(char digit)
{
    if ((int)digit < 48 || (int)digit > 57)
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
		if (decimal > 9)
		{
				throw std::invalid_argument("Invalid arguments -- not between 0 and 9");
		}
		else
		{
				return (decimal + '0');
		}

}


string trim_leading_zeros(string num)
{

		// cout << "started trim"<< endl;
		string nonZeroNum = "";
		bool firstNum = false;
		// bool isNegative = false;
		int theLength = num.length();

		// cout << "checkpoint" << endl;

		for(int i = 0; i < theLength; i++)
		{
				if(i == 0 && num.at(i) == '-')
				{
						// cout << "case 1" << endl;
						// isNegative = true;
            nonZeroNum += '-';
				}
				else if ((!(num.at(i) == '0')) && (!firstNum))
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

    if(nonZeroNum.length() == 0)
    {
        nonZeroNum.insert(0, 1, '0');
    }
    if(nonZeroNum == "-")
    {
        nonZeroNum = "0";
    }


    return nonZeroNum;

}


string add(string lhs, string rhs)
{
		string finalNum = "";
		// cout << "STARTED" << endl;
		string leftNum = trim_leading_zeros(lhs);
		// cout << "left zero trimmed" << endl;
		string rightNum = trim_leading_zeros(rhs);
    bool isNeg = false;

    if((leftNum.at(0) == '-') && (rightNum.at(0) == '-'))
    {
        leftNum.erase(0, 1);
        rightNum.erase(0, 1);
        isNeg = true;
        // cout << leftNum << endl << rightNum << endl;
    }
		// cout << "right zero trimmed" << endl;
		int leftLength = leftNum.length();
		int rightLength = rightNum.length();
    int theLength;
		// cout << " left Length: " << leftLength << "\n right Length: " << rightLength << endl;
		bool carryNum = false;

    if(leftLength != rightLength)
    {
        if(leftLength > rightLength)
        {
            for(int i = rightLength; i < leftLength; i++)
            {
                rightNum.insert(0, 1, '0');
            }
            theLength = leftLength;
        }
        else
        {
            for(int i = leftLength; i < rightLength; i++)
            {
                leftNum.insert(0, 1, '0');
            }
            theLength = rightLength;
        }
        // cout << "modified left:  " << leftNum << endl;
        // cout << "modified right: " << rightNum << endl;
    }
    else
    {
        theLength = leftLength;
    }

		for(int i = (theLength - 1); i >= 0; i--)
		{
				// cout << abs(i - theLength + 1) << " run ----------- " << endl;
				int num1 = digit_to_decimal(leftNum.at(i));
				// cout << " num 1: " << num1 << endl;
				int num2 = digit_to_decimal(rightNum.at(i));
				// cout << " num 2: " << num2 << endl;
				int sum12 = num1 + num2;
				// cout << "  sum12: " << sum12 << endl;
				if(carryNum)
				{
						sum12 += 1;
						carryNum = false;
						// cout << "  carried a num " << endl;
				}
				if(sum12 > 9)
				{
						carryNum = true;
						sum12 -= 10;
						finalNum.insert(0, 1, decimal_to_digit(sum12));
						// cout << "  final num: " << finalNum << endl;
				}
				else
				{
						carryNum = false;
						finalNum.insert(0, 1, decimal_to_digit(sum12));
						// cout << "  final num: " << finalNum << endl;
				}
		}
    if(carryNum)
    {
        finalNum.insert(0, 1, '1');
    }
    if(isNeg)
    {
        finalNum.insert(0, 1, '-');
    }
		// cout << "END OF SUMMATION ---------------" << endl;
		// cout << "FINAL NUM: " << finalNum << endl;

		return finalNum;
}


string multiply(string lhs, string rhs) {
    string finalNum = "";
    string multiplier = "";
    string multiplicand = "";
    bool isNeg = false;

    // cout << "STARTED" << endl;

    string leftNum = trim_leading_zeros(lhs);
    string rightNum = trim_leading_zeros(rhs);

    // cout << leftNum << endl << rightNum << endl;

    if((leftNum.at(0) == '-') && (rightNum.at(0) == '-'))
    {
        // cout << "double erase" << endl;
        leftNum.erase(0, 1);
        rightNum.erase(0, 1);
        isNeg = false;
        // cout << leftNum << endl << rightNum << endl;
    }
    else if(leftNum.at(0) == '-')
    {
        // cout << "left erase" << endl;
        leftNum.erase(0, 1);
        isNeg = true;
    }
    else if(rightNum.at(0) == '-')
    {
        // cout << "right erase" << endl;
        rightNum.erase(0, 1);
        isNeg = true;
    }

    // cout << "catch before length tests" << endl;
    if(leftNum.length() != rightNum.length())
    {
        if(leftNum.length() > rightNum.length())
        {
            // cout << "setting left to multiplicand" << endl;
            multiplicand = leftNum;
            multiplier = rightNum;
        }
        else
        {
            multiplicand = rightNum;
            multiplier = leftNum;
        }
    }
    else
    {
        // cout << "setting right to multiplicand" << endl;
        multiplicand = rightNum;
        multiplier = leftNum;
    }


    int multiplierLength = multiplier.length();
    int multiplicandLength = multiplicand.length();
    int carryNum = 0;
    bool needCarry = false;
    string row1 = "";
    string row2 = "";
    bool row1_Used = false;
    bool row2_Used = false;
    // cout << multiplierLength << endl << multiplicandLength << endl << multiplier << endl << multiplicand << endl;

    for(int i = multiplierLength-1; i >= 0; i--)
    {
        int numA = digit_to_decimal(multiplier.at(i));
        int product;

        // cout << "-----------------------------------------" << endl;
        //
        // cout << "multiplicandLength: " << multiplicandLength << endl;
        // cout << "multiplicand value: " << multiplicand << endl;
        // cout << "multiplierLength: " << multiplierLength << endl;
        // cout << "multiplier value: " << multiplier << endl;
        // cout << abs(i-(multiplierLength-1)) << " i run" << endl;
        // cout << "current numA @ i: " << numA << endl;
        // cout << endl;

        if(!row1_Used)
        {
          for(int j = multiplicandLength-1; j >= 0; j--)
          {
              // cout << abs(j-(multiplicandLength-1)) << " j run ----------" << endl;
              int numB = digit_to_decimal(multiplicand.at(j));
              // cout << "  current numB @ j: " << numB << endl;
              product = numA * numB;

              if(needCarry)
              {
                  product += carryNum;
                  needCarry = false;
              }
              if(product > 9)
              {
                  needCarry = true;
                  carryNum = product / 10;
                  product = product % 10;
                  row1.insert(0, 1, decimal_to_digit(product));
                  row1_Used = true;
                  // cout << "  row1: " << row1 << endl;
              }
              else
              {
                  needCarry = false;
                  row1.insert(0, 1, decimal_to_digit(product));
                  row1_Used = true;
                  // cout << "  row1: " << row1 << endl;
              }
          }
          if(needCarry)
          {
              row1.insert(0, 1, decimal_to_digit(carryNum));
              needCarry = false;
          }
        }
        else if(!row2_Used)
        {
          row2.insert(0, abs(i-(multiplierLength-1)), '0');
          for(int j = multiplicandLength-1; j >= 0; j--)
          {
              // cout << abs(j-(multiplicandLength-1))  << " j run ----------" << endl;
              int numB = digit_to_decimal(multiplicand.at(j));
              // cout << "  current numB @ j: " << numB << endl;
              product = numA * numB;

              if(needCarry)
              {
                  product += carryNum;
                  needCarry = false;
              }
              if(product > 9)
              {
                  needCarry = true;
                  carryNum = product / 10;
                  product = product % 10;
                  row2.insert(0, 1, decimal_to_digit(product));
                  row2_Used = true;
                  // cout << "  row2: " << row2 << endl;
              }
              else
              {
                  needCarry = false;
                  row2.insert(0, 1, decimal_to_digit(product));
                  row2_Used = true;
                  // cout << "  row2: " << row2 << endl;
              }
          }
          if(needCarry)
          {
              row2.insert(0, 1, decimal_to_digit(carryNum));
              needCarry = false;
          }
          row1 = add(row1, row2);
          row1_Used = true;
          row2 = "";
          row2_Used = false;
        }
        // cout << " " << endl;

    }
    if(needCarry)
    {
        row1.insert(0, 1, decimal_to_digit(carryNum));
    }
    if(isNeg)
    {
        row1.insert(0, 1, '-');
    }
    // row1 = add(row1, row2);
    // cout << " " << endl;
    // cout << "row1: " << row1 << endl;

    return row1;
}

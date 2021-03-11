#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <cctype>		// Contains isdigit, isalpha, isupper, etc.

using std::cin, std::cout, std::endl, std::string;
using std::invalid_argument;

bool is_valid_name(const string& str);


int main()
{

    bool dummy;
    string otherDummy = "Andrew Lee";

    cout << "Start of function test" << endl;
    cout << "---------------------------" << endl;

    dummy = is_valid_name(otherDummy);

    cout << "valid num function: " << dummy << endl;

    cout << "---------------------------" << endl;
    cout << "End of function test" << endl;

    return 0;
}

bool is_valid_name(const std::string& str)
{
		char theValue;
		bool isValid = false;

		for(int i = 0; i < str.length(); i++)
		{
				theValue = str.at(i);
        cout << "theValue: " << theValue << endl;
				if(theValue == ' ')
				{
						isValid = true;
				}
				else if(isalpha(theValue))
				{
						isValid = true;
				}
				else
				{
						return false;
				}
		}
		return isValid;
}

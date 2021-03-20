#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

string stringInterface(string string1, string string2, string theOperator);
float quakeMagnitude(float rigidity, float length, float width);


int main()
{
    float shearModulusCrust = 32000000000; //pascals
    float shearModulusMantle = 75000000000; //pascals

    float mag = quakeMagnitude(0.317, 1000, 1);
    cout << "magnitude: " << mag << endl;

}


/*  Function quakeMagnitude
 *  length: the length of the fault line (km)
 *  width: the width of the fault line (km)
 *  slide: the slide of the fault line (m)
 *  Return value: float
 */
float quakeMagnitude(float rigidity, float length, float width)
{
    float slide = length / 20000;
    cout << "rigidity: " << rigidity << endl
         << "length: " << length << endl
         << "width: " << width << endl
         << "slide: " << slide << endl;
    return rigidity * length * width * slide;
}

string stringInterface(string num1, string num2, string operation)
{
    string returnValue;
    if(operation == "+")
    {
        // cout << "ans =\n\n    " << add(string1, string2) << endl << endl;
        returnValue = add(num1, num2);
    }
    else if(operation == "*")
    {
        // cout << "ans =\n\n    " << multiply(string1, string2) << endl << endl;
        returnValue = multiply(num1, num2);
    }
    else
    {
        returnValue = "invalid inputs";
    }
    return returnValue;
}

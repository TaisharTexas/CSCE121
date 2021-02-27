#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    // cout << ">>" << endl;

    string string1;
    string theOperator;
    string string2;
    bool keepGoing = true;

    while(keepGoing)
    {
        cin >> string1;
        if(string1 == "q" || string1 == "quit")
        {
            break;
        }

        cin >> theOperator;
        if(theOperator == "q" || theOperator == "quit")
        {
            break;
        }

        cin >> string2;
        if(string2 == "q" || string2 == "quit")
        {
            break;
        }
        cout << ">>" << endl;

        if(theOperator == "+")
        {
            cout << "ans =\n\n    " << add(string1, string2) << endl << endl;
        }
        else if(theOperator == "*")
        {
            cout << "ans =\n\n    " << multiply(string1, string2) << endl << endl;
        }
    }
    cout << ">>" << endl;

    cout << "farvel!" << endl << endl;



}

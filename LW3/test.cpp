#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string, std::to_string;

int main() {

    string userIn;
    int num1 = -1;
    int num2 = -1;
    string operation;
    string segment;
    int pointer = 0;
    string theAns;

    cout << "Please enter word equation (type 'equals' at the end): ";
    getline(cin, userIn);

		cout << "length of input: " << userIn.length() << endl;

    for(int i = 0; i < userIn.length(); i++)
    {
				cout << i << " run ---------------------------------------" << endl;
        if(userIn.at(i) == ' ')
        {

            if((userIn.length() - userIn.at(i)) <= 6)
            {
								cout << "equals case --------------------------" << endl;
                theAns += (" = " + to_string(num1));
								cout << "theAns: " << theAns << endl;
            }
            else
            {
                segment = userIn.substr(pointer, i);
                pointer = i+1;

								cout << "segment: " << segment << endl;
								cout << "pointer: " << pointer << endl;

                if(!(num1 > -1))
                {
                    if(segment == "zero")
                    {
                        num1 = 0;
                    }
                    else if(segment == "one")
                    {
                        num1 = 1;
                    }
                    else if(segment == "two")
                    {
                        num1 = 2;
                    }
                    else if(segment == "three")
                    {
                        num1 = 3;
                    }
                    else if(segment == "four")
                    {
                        num1 = 4;
                    }
                    else if(segment == "five")
                    {
                        num1 = 5;
                    }
                    else if(segment == "six")
                    {
                        num1 = 6;
                    }
                    else if(segment == "seven")
                    {
                        num1 = 7;
                    }
                    else if(segment == "eight")
                    {
                        num1 = 8;
                    }
                    else if(segment == "nine")
                    {
                        num1 = 9;
                    }
                    else if(segment == "plus")
                    {
                        operation = "plus";
                    }
                    else if(segment == "minus")
                    {
                        operation = "minus";
                    }
                    else if(segment == "times")
                    {
                        operation = "times";
                    }
                    else if(segment == "divides")
                    {
                        operation == "divides";
                    }
                    theAns += to_string(num1);
                }
                else if(!(num2 > -1))
                {
                    if(segment == "zero")
                    {
                        num2 = 0;
                    }
                    else if(segment == "one")
                    {
                        num2 = 1;
                    }
                    else if(segment == "two")
                    {
                        num2 = 2;
                    }
                    else if(segment == "three")
                    {
                        num2 = 3;
                    }
                    else if(segment == "four")
                    {
                        num2 = 4;
                    }
                    else if(segment == "five")
                    {
                        num2 = 5;
                    }
                    else if(segment == "six")
                    {
                        num2 = 6;
                    }
                    else if(segment == "seven")
                    {
                        num2 = 7;
                    }
                    else if(segment == "eight")
                    {
                        num2 = 8;
                    }
                    else if(segment == "nine")
                    {
                        num2 = 9;
                    }
                    else if(segment == "plus")
                    {
                        operation = "plus";
                    }
                    else if(segment == "minus")
                    {
                        operation = "minus";
                    }
                    else if(segment == "times")
                    {
                        operation = "times";
                    }
                    else if(segment == "divides")
                    {
                        operation = "divides";
                    }
                }
                else
                {
                    if(operation == "plus")
                    {
                        num1 = num1 + num2;
                        theAns += (" + " + to_string(num2));
                        num2 = -1;
                    }
                    if(operation == "minus")
                    {
                        num1 = num1 - num2;
                        theAns += (" - " + to_string(num2));
                        num2 = -1;
                    }
                    if(operation == "times")
                    {
                        num1 = num1 * num2;
                        theAns += (" * " + to_string(num2));
                        num2 = -1;
                    }
                    if(operation == "divides")
                    {
                        num1 = num1 / num2;
                        theAns += (" / " + to_string(num2));
                        num2 = -1;
                    }
                }
            }



        }
    }

    cout << theAns << endl;


    return 0;
}

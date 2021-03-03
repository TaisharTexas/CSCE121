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

		// cout << "length of input: " << userIn.length() << endl;

    for(int i = 0; i < userIn.length(); i++)
    {

				// cout << i << " run ---------------------------------------" << endl;
        // cout << "slots left: " << userIn.length()-i << endl;
        if((userIn.length() - i) <= 6)
        {
            // cout << "equals case --------------------------" << endl;
            theAns += (" = " + to_string(num1));
            // cout << "theAns: " << theAns << endl;
            return 0;
        }
        else if(userIn.at(i) == ' ')
        {
              // cout << "pointer: " << pointer << endl;
              segment = userIn.substr(pointer, i-pointer);
              pointer = i+1;

							// cout << "segment: " << segment << endl;
							// cout << "pointer: " << pointer << endl;

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
                  // cout << "num1: " << num1 << endl;
                  theAns += to_string(num1);
                  // cout << "theAns: " << theAns << endl;
              }
              else if(!(num2 > -1))
              {
                  bool isNum = false;
                  if(segment == "zero")
                  {
                      num2 = 0;
                      isNum = true;
                  }
                  else if(segment == "one")
                  {
                      num2 = 1;
                      isNum = true;
                  }
                  else if(segment == "two")
                  {
                      num2 = 2;
                      isNum = true;
                  }
                  else if(segment == "three")
                  {
                      num2 = 3;
                      isNum = true;
                  }
                  else if(segment == "four")
                  {
                      num2 = 4;
                      isNum = true;
                  }
                  else if(segment == "five")
                  {
                      num2 = 5;
                      isNum = true;
                  }
                  else if(segment == "six")
                  {
                      num2 = 6;
                      isNum = true;
                  }
                  else if(segment == "seven")
                  {
                      num2 = 7;
                      isNum = true;
                  }
                  else if(segment == "eight")
                  {
                      num2 = 8;
                      isNum = true;
                  }
                  else if(segment == "nine")
                  {
                      num2 = 9;
                      isNum = true;
                  }
                  else if(segment == "plus")
                  {
                      operation = "plus";
                      isNum = false;
                  }
                  else if(segment == "minus")
                  {
                      operation = "minus";
                      isNum = false;
                  }
                  else if(segment == "times")
                  {
                      operation = "times";
                      isNum = false;
                  }
                  else if(segment == "divides")
                  {
                      operation = "divides";
                      isNum = false;
                  }

                  // if(isNum)
                  // {
                  //   cout << "num2: " << num2 << endl;
                  // }
                  // else
                  // {
                  //   cout << "operation: " << operation << endl;
                  // }


              }
              // cout << "-----" << endl;
              // cout << "num1: " << num1 << endl;
              // cout << "num2: " << num2 << endl;

              if(num1 != -1 && num2 != -1)
              {
                  // cout << "TRIGGER" << endl;
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
                  // cout << "theAns: " << theAns << endl;
                  // cout << "num1: " << num1 << endl;
                  // cout << "num2: " << num2 << endl;
            }

        }
    }

    // cout << theAns << endl;


    return 0;
}

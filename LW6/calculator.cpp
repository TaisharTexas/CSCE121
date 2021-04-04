#include <iostream>
#include <string>
#include <sstream>
#include "functions.h"
using std::cin, std::cout, std::endl, std::string, std::stoi, std::istringstream;

int main() {
  // prompt user input
  cout << "Type RPN expression (end with '=')." << endl;
  cout << "> ";

  //TODO: create a command-line interface for calculator GUI
  Stack myStack;

  string inputSequence;
  getline(cin, inputSequence);
  istringstream iss (inputSequence);
  int finalNum;

  while(!iss.eof())
  {
      // cout << "---------------Loop Start-----------------" << endl;
      string tempS;
      iss >> tempS;
      if(tempS == "+")
      {
          // cout << "add operation" << endl;
          int rNum = pop(myStack);
          int lNum = pop(myStack);
          lNum = lNum + rNum;
          push(myStack, lNum);
      }
      else if(tempS == "-")
      {
          // cout << "subtract operation" << endl;
          int rNum = pop(myStack);
          int lNum = pop(myStack);
          lNum = lNum - rNum;
          push(myStack, lNum);
      }
      else if(tempS == "*")
      {
          // cout << "multiply operation" << endl;
          int rNum = pop(myStack);
          int lNum = pop(myStack);
          lNum = lNum * rNum;
          push(myStack, lNum);
      }
      else if(tempS == "^")
      {
          // cout << "power operation" << endl;
          int rNum = pop(myStack);
          int lNum = pop(myStack);
          for(int i = rNum; i >= 1; i--)
          {
              lNum = lNum * lNum;
          }
          push(myStack, lNum);
      }
      else if(tempS == "=")
      {
          // cout << "equals operation" << endl;
          finalNum = pop(myStack);
      }
      else
      {
          // cout << "no operations, add value to stack" << endl;
          int num = stoi(tempS);
          push(myStack, num);
      }
  }
  delete[] myStack.numbers;

  cout << "Ans: " << finalNum << endl;



  return 0;
}

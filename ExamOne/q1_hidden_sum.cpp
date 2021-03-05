#include <iostream>

using std::cout, std::cin, std::endl;

int sumEvenNum(int theNum);

int main ()
{

  int data = 24103847;

  int theAns = sumEvenNum(data);
  cout << theAns << endl;

  return theAns;
}

int sumEvenNum(int theNum)
{
  int theSum = 0;
  int i = 1;
  int currentNum;
  
  //divide by increasing powers until the value is less than zero
  while(theNum / i > 0)
  {
    // grab the current number
    currentNum = theNum % i;
    cout << "currentNum: " << currentNum << endl;


    //check if the current number is even
    if((currentNum % 2) == 0)
    {
      //add the current number to the sum because it's even
      theSum += (theNum % i);
      cout << "check" << endl;
    }
    cout << "theSum: " << theSum << endl;
    //increase the power of i
    i = i * 10;
    cout << i << endl;
  }

  return theSum;
  }



}

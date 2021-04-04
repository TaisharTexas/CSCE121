#include "functions.h"
using std::cin, std::cout, std::endl, std::ostream, std::string;

#define INFO(X)  cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack& stack, int number) {
  // TODO: implement push function for stack
  // cout << "Push operation" << endl;
  if(stack.count == stack.capacity)
  {
      // cout << "       RESIZE" << endl;
      int newsize = stack.capacity * 2;
      // cout << "oldsize: " << stack.capacity << endl;
      // cout << "newsize: " << newsize << endl;
      int* newNums = new int[newsize] {};

      for(int i = 0; i <= stack.count-1; i++)
      {
          newNums[i] = stack.numbers[i];
      }
      delete[] stack.numbers;

      stack.numbers = newNums;
      stack.capacity = newsize;
      stack.numbers[stack.count] = number;
      stack.count++;
      // cout << "count: " << stack.count << endl;
      // cout << "current index: " << stack.currentIndex << endl;


  }
  else
  {
      stack.numbers[stack.count] = number;
      stack.count++;
      // cout << "count: " << stack.count << endl;
      // cout << "current index: " << stack.currentIndex << endl;
  }

  // INFO_STRUCT(stack);
  // INFO(number);
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack& stack) {
  // TODO: implement pop function for stack
  // cout << "POP CALLED" << endl;
  int poppedNum = 0;
  if(stack.count == 0)
  {
      return INT32_MAX;
  }
  else
  {
      poppedNum = stack.numbers[stack.count-1];
      // stack.numbers[stack.currentIndex] = 0;
      stack.count--;
  }
  // cout << "poppedNum: " << poppedNum << endl;
  // INFO_STRUCT(stack);
  return poppedNum;
}

/**
 * ----- OPTIONAL -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack& stack) {
    // TODO (optional): implement peek function for stack
    if(stack.count == 0)
    {
        return INT32_MAX;
    }
    else
    {
        return stack.numbers[stack.count-1];
    }
    // INFO_STRUCT(stack);
}

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

    // int test = -1;
		//
    // try{
    //   test = digit_to_decimal('/');
		//
    // }
    // catch(...){cout<<"caught an exception"<<endl;}
		//
    // cout << test << endl;
		string theName = "000024186000005752355";
		trim_leading_zeros(theName);

    // TODO(student): implement the UI
}

#include <iostream>
#include <fstream>

#include "MyString.h"

using std::cout, std::endl;


int main(){
    MyString testString("what about the droid attack on the wookies");
    MyString testString2(" there");
    MyString testString3("hello");

    const char* newTest = testString.data();

    // cout << "first test string------------" << endl;
    // cout << testString << endl;
    // cout << testString.data() << endl;
    // cout << "second test string-----------" << endl;
    // cout << testString2 << endl;
    // cout << testString2.data() << endl;
    // cout << testString << endl;
    // cout << testString.find(testString2) << endl;
    // cout << testString << endl;
    // cout << testString.at(28) << endl;
    //
    // testString.resize(30);
    //
    // cout << testString << endl;

    cout << testString << endl;
    testString = testString3 + testString2;
    cout << testString << endl;

    return 0;
}

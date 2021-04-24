// TODO: Implement this source file
#include "MyString.h"

ostream& operator<<(ostream& os, const MyString& str)
{
    //yeah not sure yet
    os << "<< operator called \n" << str.theSize;
    return os;
}

// MyString& operator=(const MyString& str)
// {
//     //so this needs to somehow set a MyString equal to the value of the str string
// }

// MyString& operator+=(const MyString& str)
// {
//     // needs to add str.theString to theString (prob needs to use resize function??)
// }

// bool operator==(const MyString& lhs, const MyString& rhs)
// {
//     //uhh, thinking I use a for loop to go through both strings and compare them element by element
//     // but how do I compare each element without using the == operator for them?
//     // Is it different cause I'm comapring chars and not MyStrings?
// }

MyString& operator+(const MyString& lhs, const MyString& rhs)
{
    //create and return a new MyString with a value of lhs+rhs back to back
}

//default constructor
MyString::MyString()
{
    theCapacity = 80;
    theSize = 0;
    char* theString[theCapacity];
}
//copy constructor
MyString::MyString(const MyString &str)
{
    theString = str.theString;
    theSize = str.theSize;
    theCapacity = str.theCapacity;
}
//from c-string constructor
MyString::MyString(const char* c)
{
    //dont actually know what this does
}
//destructor
MyString::~MyString()
{
    delete theString;
}

// void MyString::resize(size_t newSize){
//     if(newSize > size){
//         //create new array with increased size and copy values in from old array
//     }
//     else if(newSize < size){
//         //create new array and copy in values from old array until new array is full
//     }
//     else{
//         //do nothing because the resize doesn't actually change the size
//     }
// }

char* MyString::data()
{
    return theString;
}

bool MyString::empty()
{
    if(theSize > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

const char& MyString::front() const
{
    return theString[0];
}

const char& MyString::at(size_t n) const
{
    if(n >= theSize)
    {
        cout << "n value too big -- array index out of bounds" << endl;
        return '\0';
    }
    else if(n < 0)
    {
        cout << "n value less than zero -- array index out of bounds" << endl;
        return '\0';
    }
    else
    {
        return theString[n];
    }
}

void MyString::clear()
{
    //somehow clears all the values and set size to zero
    theString = { NULL };
    theSize = 0;
}

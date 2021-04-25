// TODO: Implement this source file
#include <iostream>
#include <fstream>
#include <limits>

using std::cout, std::endl, std::cin;
using std::istream, std::ostream;

#include "MyString.h"

ostream& operator<<(ostream& os, const MyString& str)
{
    //yeah not sure yet
    // os << "size: " << str.theSize << "\n";
    // os << "cap:  " << str.theCapacity << "\n";
    os << str.theString;
    return os;
}

MyString& MyString::operator=(const MyString& str)
{
    //so this needs to somehow set a MyString equal to the value of the str string
    if(theCapacity < str.theCapacity)
    {
        this->resize(str.theCapacity);
        theCapacity = str.theCapacity;
    }
    this->clear();
    theSize = str.theSize;
    for(unsigned int i = 0; i < theSize; i++)
    {
        theString[i] = str.theString[i];
    }
    return *this;
}

MyString& MyString::operator+=(const MyString& str)
{
    unsigned int newCap = theCapacity + str.theCapacity;
    unsigned int newSize = theSize + str.theSize;
    char* newString;
    newString = new char[newCap];
    for(unsigned int i = 0; i < newCap; i++)
    {
        newString[i] = '\0';
    }

    for(unsigned int i = 0; i < theSize; i++)
    {
        newString[i] = theString[i];
    }
    int j = 0;
    for(unsigned int i = theSize; i < newSize; i++)
    {
        newString[i] = str.theString[j];
        j++;
    }
    delete[] theString;
    theString = newString;
    theSize = newSize;
    theCapacity = newCap;

    return *this;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
    if(lhs.theSize == rhs.theSize && lhs.theCapacity == rhs.theCapacity)
    {
        for(unsigned int i = 0; i < rhs.theSize; i++)
        {
            if(rhs.theString[i] != lhs.theString[i])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    //create and return a new MyString with a value of lhs+rhs back to back
    MyString newString;
    newString += lhs;
    newString += rhs;

    return newString;
}

//default constructor
MyString::MyString() : theCapacity(80), theSize(0), theString(new char[theCapacity])
{
    // theString = new char[theCapacity];
    clear();
}
//copy constructor
MyString::MyString(const MyString &str) : theCapacity(str.theCapacity), theSize(str.theSize), theString(new char[theCapacity])
{
    // theString = new char[theCapacity];
    for(unsigned int i = 0; i < theSize; i++)
    {
        theString[i] = str.theString[i];
    }
    theString[theSize] = '\0';
}
//from c-string constructor
MyString::MyString(const char* c) : theCapacity(0), theSize(0), theString(nullptr)
{
    // cout << "entered constructor" << endl;
    unsigned int i = 0;
    while(c[i] != '\0')
    {
        // cout << "looping -- #" << i << endl;
        // cout << "ith char: " << c[i] << endl;
        theCapacity++;
        theSize++;
        i++;
    }
    // cout << "capacity should be 5, it is " << theCapacity << endl;
    theCapacity++;
    // cout << "finished while loop" << endl;
    theString = new char[theCapacity];
    // cout << "declared new char array with capacity=" << theCapacity << endl;
    // cout << "size should be 5, it is " << theSize << endl;
    for(unsigned int j = 0; j < theSize; j++)
    {
        // cout << "looping -- #" << j << endl;
        theString[j] = c[j];
    }
    theString[theSize] = '\0';
}
//destructor
MyString::~MyString()
{
    delete[] theString;
}

void MyString::resize(unsigned int newCap)
{

    if(newCap > 0)
    {
        char* newString;
        if(newCap <= theSize)
        {
            newCap++;
        }
        newString = new char[newCap];
        for(unsigned int i = 0; i < newCap; i++)
        {
            newString[i] = '\0';
        }

        if(newCap-1 >= theSize)
        {
            //create new array with increased size and copy values in from old array
            for(unsigned int i = 0; i < theSize; i++)
            {
                newString[i] = theString[i];
            }
            delete[] theString;
            theString = newString;
            theCapacity = newCap;
        }
        else if((newCap-1) < theSize)
        {
            //create new array and copy in values from old array until new array is full
            for(unsigned int i = 0; i < newCap-1; i++)
            {
                newString[i] = theString[i];
            }
            delete[] theString;
            theString = newString;
            theSize = newCap-1;
            theCapacity = newCap;
        }
    }
}

const char* MyString::data() const
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
        throw std::out_of_range("index not in range");
    }
    else
    {
        return theString[n];
    }
}

void MyString::clear()
{
    //somehow clears all the values and set size to zero
    for(unsigned int i = 0; i < theCapacity; i++)
    {
        theString[i] = '\0';
    }
    theSize = 0;
}

size_t MyString::find(const MyString& str, size_t pos)
{
    //check to ensure there's enough length left in the source string for a match to exist
    if((theSize-pos) < str.size())
    {
        // cout << "desired string is longer than source string, no match possible" << endl;
        // cout << "returning -1" << endl;
        return -1;
    }
    //if the lengths are equals, check the first characters for a match
    else if((theSize-pos) == str.size())
    {
        if(theString[pos] != str.at(0))
        {
            // cout << "lengths are equal and first character do not match, no match possible" << endl;
            // cout << "returning -1" << endl;
            return -1;
        }
    }

    bool isMatch = false;
    //cycle through source string looking for a first character match
    for(unsigned int i = pos; i < theSize; i++)
    {
        //if the current character matches the first character of str, investigate
        if(theString[i] == str.at(0))
        {
            // cout << "current character matches first character of desired string, investigating" << endl;
            //check to make sure there are enough characters left in the source string for a match to exist
            if(theSize-i < str.size())
            {
                // cout << "desired string is longer than remianing length of source string, no match possible" << endl;
                // cout << "returning -1" << endl;
                return -1;
            }
            //starting at position i, check the str string against the subsequent characters int he source string
            //if any of the characters don't match across the length of the str string, break the loop and keep looking
            // cout << "iterating through desired string, chekcing to make sure all characters match" << endl;
            for(unsigned int j = 0; j < str.size(); j++)
            {
                if(theString[i+j] == str.at(j))
                {
                    // cout << "source string character at loc(" << i+j << ") matches desired string character at loc(" << j << ")" << endl;
                    isMatch = true;
                }
                else
                {
                    // cout << "there is a difference between source string and desired string, no match" << endl;
                    // cout << "exiting investigation loop and returning to find first match loop" << endl;
                    isMatch = false;
                    break;
                }
            }
            if(isMatch)
            {
                // cout << "found matching sequence, returning loc of first character in source string" << endl;
                return i;
            }
        }
    }
    // cout << "no matches found, returning -1" << endl;
    return -1;


}

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using std::ostream;

class MyString
{
public:
    MyString(); //defualt constructor
    MyString(const MyString &str); //copy constructor
    MyString(const char* s);
    ~MyString(); //destructor

    void resize(unsigned int newCap);
    int capacity() const { return theCapacity; }
    unsigned int size() const { return theSize; }
    const char* data() const;
    bool empty();
    int length(){ return theSize; }
    const char& front() const;
    const char& at(size_t n) const;
    void clear();

//all examples have ostream as a friend
    friend ostream& operator<<(ostream& os, const MyString& str);

    MyString& operator=(const MyString& str);
    MyString& operator+=(const MyString& str);

    size_t find(const MyString& str, size_t pos = 0);

    friend bool operator==(const MyString& lhs, const MyString& rhs);
    friend MyString operator+(const MyString& lhs, const MyString& rhs);

private:
    unsigned int theCapacity;
    unsigned int theSize;
    char* theString;
};

#endif

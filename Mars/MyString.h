#include <iostream>
#include <fstream>
#include <tuple>
#include <limits>

using std::cout, std::endl, std::cin;
using std::istream, std::ostream;

class MyString
{
public:
    MyString(); //defualt constructor
    MyString(const MyString &str); //copy constructor
    MyString(const char* s);
    ~MyString(); //destructor

    void resize();
    int capacity(){ return theCapacity; };
    int size() { return theSize; };
    char* data();
    bool empty();
    const char& front() const;
    const char& at(size_t n) const;
    void clear();

    friend ostream& operator<<(ostream& os, const MyString& str);
    // friend MyString& operator=(const MyString& str);
    // friend MyString& operator+=(const MyString& str);

    size_t find(const MyString& str, size_t pos = 0) const;

    // friend bool& operator==(const MyString& lhs, const MyString& rhs);
    friend MyString& operator+(const MyString& lhs, const MyString& rhs);

private:
    int theSize;
    int theCapacity;
    char* theString;
};

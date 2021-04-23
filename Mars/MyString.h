
#include <iostream>
#include <fstream>
#include <tuple>
#include <limits>

class MyString{
    private:
        int size;
        int capacity;
        char* theString[];
    public:
        MyString(); //default constructor
        // need copy constructor
        // need constructor from cstring
        ~MyString();

        int size(){ return size; } // number of elements in array (length)
        int capacity(){ return capacity; } // the storage reserved for the string in bytes
        bool empty();// checks if the array is empty
        void clear(); // erases all values from the array and returns the capacity and size to zero
        void resize(size_t n); // resizes the array to capacity n
        char* at(int i); // gives the element at index i
        size_t find(const MyString& str, size_t pos); 


}

// TODO: Implement this source file
#include "MyString.h"

MyString::MyString() ; theString[] {}
    
MyString::~MyString(){
    delete []theString;
}

bool MyString::empty(){
    if(size > 0){
        return true;
    }
    else{
        return false;
    }
}

void MyString::clear(){
    //somehow clears all the values and set size to zero
}

void MyString::resize(size_t newSize){
    if(newSize > size){
        //create new array with increased size and copy values in from old array
    }
    else if(newSize < size){
        //create new array and copy in values from old array until new array is full
    }
    else{
        //do nothing because the resize doesn't actually change the size
    }
}


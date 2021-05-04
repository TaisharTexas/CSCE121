/*
----- Linked List Addition Problem -----
Implement the add function.
*/

#include "multi_digit_addition.h"
using std::ostream, std::cout, std::endl;

// copy constructor
Number::Number(const Number& other) : head(nullptr), tail(nullptr) {
    Digit* marker = other.head;
    while (nullptr != marker) {
        // insertFront(marker->value);
        insertBack(marker->value); // changed to not copy backwards
        marker = marker->next;
    }
}

// destructor
Number::~Number() {
    // initialize auxiliary pointer
    Digit* marker = nullptr;

    // iterate through list
    while (nullptr != head) {
        // set pointer to head node
        marker = head;

        // move head node to next node
        head = head->next;

        // disconect current node from rest of linked list
        marker->next = nullptr;
        if (nullptr != head) {
            head->prev   = nullptr;
        }

        // deallocate pointer
        delete marker;
        marker = nullptr;
    }
}

// copy assignment operator
Number& Number::operator=(const Number& other) {
    throw std::runtime_error("do not use operator= function");
    if (this == &other) { return *this; }
    return *this;
}

// insert front
void Number::insertFront(int value) {
    // create new node
    Digit* digit = new Digit(value);

    // case: list is empty => set tail node
    if (nullptr == tail) {
        tail = digit;
    }

    // case: list is non-empty => link head to new node
    else {
        head->prev = digit;
    }

    // link node to head and update head
    digit->next = head;
    head = digit;
}

// insert back
void Number::insertBack(int value) {
    // create new node
    Digit* digit = new Digit(value);

    // case: list is empty => set head node
    if (nullptr == head) {
        head = digit;
    }

    // case: list is non-empty => link tail to new node
    else {
        tail->next = digit;
    }

    // link node to tail and update tail
    digit->prev = tail;
    tail = digit;
}

// insertion operator
ostream& operator<<(ostream& out, const Number& number) {
    Digit* marker = number.getHead();
    while (nullptr != marker) {
        out << marker->value;
        marker = marker->next;
    }
    return out;
}

/*
TODO: Implement add function
*/

// add function
Number Number::add(const Number& rhs)
{
    /* I changed the copy constructor to not copy the list backwards */

    Number totalSum = Number();
    int carryValue = 0;
    Digit* marker1 = this->tail;
    Digit* marker2 = rhs.tail;

    // assuming this list is >= to rhs
    while(marker1 != nullptr)
    {
        int num1;
        int num2;
        num1 = marker1->value;

        if(marker2 != nullptr)
        {
            num2 = marker2->value;
        }
        else
        {
            //turns out rhs list is shorter than this List
            //continue to add the elements of this list to the sum list
            num2 = 0;
        }

        num1 += num2;
        num1 += carryValue;
        if(num1 > 9)
        {
            carryValue = num1 / 10;
        }
        else
        {
            carryValue = 0;
        }
        totalSum.insertFront(num1);

        marker1 = marker1->prev;
        if(marker2 != nullptr)
        {
            marker2 = marker2->prev;
        }

    }
    while(marker2 != nullptr)
    {
        //turns out rhs is longer than this list
        int num2 = marker2->value;
        totalSum.insertFront(num2);
        marker2 = marker2->prev;

    }

    return totalSum;

}

#include "linked_list.h"
#include <iostream>
#include <string>
using std::cout, std::endl, std::string, std::ostream;

void MyList::add(string name, int score) {
    // TODO
    //made new node with inputted vales
    MyNode* newNode = new MyNode(name, score);

    if(_headPtr == nullptr)
    {
        _headPtr = newNode;
        _tailPtr = newNode;
    }
    else
    {
        //assign the old last node's next node ptr to the new node
        _tailPtr->setNext(newNode);
        //reassign the last node pointer to the new node
        _tailPtr = newNode;
    }
    _size++;


}

void MyList::clear() {
    // TODO

      while(_headPtr != nullptr)
      {
          MyNode* tempPtr = _headPtr->next();
          delete _headPtr;
          _headPtr = tempPtr;
      }
      _tailPtr = nullptr;
      _size = 0;

}

bool MyList::remove(string name) {
    return false;
}

bool MyList::insert(string name, int score, size_t index) {
    // TODO
    return false;
}

MyList::MyList()
  : _size(0), _headPtr(nullptr), _tailPtr(nullptr) { }

MyList::~MyList() {
    clear();
}

size_t MyList::size() {
    return _size;
}

bool MyList::empty() {
    return _headPtr == nullptr;
}

MyNode* MyList::head() const {
    return _headPtr;
}

ostream& operator<<(ostream& os, const MyList& myList) {
    MyNode* _current = myList.head();
    if (_current == nullptr) {
        os << "Linked list is empty" << endl;
        return os;
    }

    while (_current != nullptr) {
        os << "[ " << _current->name() << ", " << _current->score() << " ]" << endl;
        _current = _current->next();
    }
    return os;
}

MyNode::MyNode(std::string name, int score)
    : _name(name), _score(score), _nextPtr(nullptr) {}

std::string MyNode::name()  {
    return _name;
}

int MyNode::score() {
    return _score;
}

void MyNode::setNext(MyNode* other) {
    _nextPtr = other;
}

MyNode* MyNode::next() {
    return _nextPtr;
}

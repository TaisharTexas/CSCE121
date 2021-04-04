###Object Oriented Programming

The focus of Object Oriented Programming, the focus is on the data

Grouping:
  - Related data (attributes)
  - Related Actions (methods)

Inheritance
  - base and derived classes
  - Class:
    - a blueprint
    - Houses of different colors in different locations are all instances of a single house class
    - public objects: objects that other classes can see (generally methods and member functions)
    - private objects: objects that other classes cannot see (generally data, variables, attributes, and helper functions)
    - used to represent abstractions of physical things/concepts
    - a derived class/child class is used to provide commonality between classes (ie, circle class and square class are both shape and use basic shape class attributes -- but circle adds a radius and a square adds a length and width)
    - Derived classes can access the parent class's protected and public objects, but not the private objects.
    - Any class can access the public objects in any other class.
Polymorphism
  - virtual functions
  - used when information from a child class needs to temporarily override the info in the parent class
  - Virtual functions: indicate in the parent that the child version of a function should be used instead of the parent function, if available.
Encapsulation
  - private and protected

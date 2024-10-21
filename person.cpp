#include "person.h"

Person::Person() {cout << "The constructor without parameters for the Base class was called\n";}
Person::Person(const string&n) {cout << "A constructor with parameters for the Base class was called\n";}
Person::Person(const Person& other) {cout << "Copy constructor called for Base class\n";}
Person::~Person() {cout << "The virtual destructor for the Base class has been called\n";}
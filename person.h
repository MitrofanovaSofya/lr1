#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(const string& n);
    Person(const Person& other);
    virtual ~Person();

    virtual void print() = 0;
    virtual void edit_info() = 0;
    virtual void save_to_file(ostream&) = 0;
    virtual void load_from_file(istream&) = 0;
};
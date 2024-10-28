#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "person.h"
#include "family_member.h"
#include "age.h"

using namespace std;

struct Element {
    Element* next;
    Person* data;
};

class Keeper
{
private:
    Element* head;
    Element* tail;
    int count;

public:
    Keeper();
    Keeper(Element* h, Element* t, int c=0);
    Keeper(Keeper& other);
    ~Keeper();

    Element* get_head();
    Element* get_tail();
    int get_count();

    void delete_head();
    void delete_all();
    Keeper& delete_element(int n);
    Keeper& edit_element(int n);

    void add_to_head(Person* mover);
    void add_to_tail(Person* mover);

    Keeper& operator++();
    friend Keeper& operator++(Keeper& K, int);

    Keeper& operator--(int);
    friend Keeper& operator--(Keeper& K);

    void print_keeper();

    void load_from_file(const string& filename);
    void save_to_file(const string& filename);

    void setSpouse(int index1, int index2);
    void setFatherChild(int index1, int index2);
    void setMotherChild(int index1, int index2);
};
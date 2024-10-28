#pragma once
#include <ctime>
#include "person.h"
#include "age.h"
#include "check.h"

class FamilyMember : public Person {
private:
    string name;
    int birthDay, birthMonth, birthYear;
    int deathDay, deathMonth, deathYear;
    int age;
    FamilyMember* spouse;
    FamilyMember* mother;
    FamilyMember* father;
    FamilyMember** children;
    int childrenCount;
    string spouseName;
    string fatherName;
    string motherName;
    string* childrenNames;
public:
    FamilyMember();
    FamilyMember(const string& name,int birthDay, int birthMonth, int birthYear,int deathDay = 0, int deathMonth = 0, int deathYear = 0, int age = 0, int childrenCount = 0, const string& spouseName = "", const string& fatherName = "", const string& motherName = "");
    FamilyMember(const FamilyMember& other);
    ~FamilyMember();

    string getName();
    void setName (string& name);
    void setBirthDate(int day, int month, int year);
    void setDeathDate(int day, int month, int year);
    int getAge();
    void setAge(int a);

    void setSpouse(FamilyMember* spouse);
    void setFather(FamilyMember* father);
    void setMother(FamilyMember* mother);
    void addChild(FamilyMember* child);

    string getSpouseName();
    string getFatherName();
    string getMotherName();
    void setSpouseName(FamilyMember* spouse);
    void setFatherName(FamilyMember* father);
    void setMotherName(FamilyMember* mother);
    string* getChildrenNames();
    void setChildrenNames(FamilyMember** children, int childrenCount);

    void print() override;
    void edit_info() override;
    void save_to_file(ostream& out) override;
    void load_from_file(istream& in) override;
};
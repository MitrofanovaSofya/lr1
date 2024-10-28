#include "family_member.h"

FamilyMember::FamilyMember():name(""), birthDay(0), birthMonth(0), birthYear(0),deathDay(0), deathMonth(0), deathYear(0), age(0), spouse(nullptr),  mother(nullptr), father(nullptr), children(nullptr), childrenCount(0), spouseName(""), childrenNames(nullptr) {cout << "Constructor called without parameters for FamilyMember class\n";}

FamilyMember::FamilyMember(const string& name,int birthDay, int birthMonth, int birthYear,int deathDay, int deathMonth, int deathYear, int age, int childrenCount, const string& spouseName, const string& fatherName, const string& motherName)
    : name(name), birthDay(birthDay), birthMonth(birthMonth), birthYear(birthYear),deathDay(deathDay), deathMonth(deathMonth), deathYear(deathYear), age(age), spouse(nullptr), mother(nullptr), father(nullptr), childrenCount(childrenCount), spouseName(spouseName), fatherName(fatherName), motherName(motherName), childrenNames(childrenCount > 0 ? new string[childrenCount] : nullptr) {
    cout << "Constructor called with parameters for FamilyMember class"<< endl;
    children = nullptr;
}

FamilyMember::FamilyMember(const FamilyMember& other)
    : name(other.name), birthYear(other.birthYear), deathYear(other.deathYear),age(other.age), spouse(other.spouse), mother(other.mother), father(other.father), childrenCount(other.childrenCount), spouseName(other.spouseName), fatherName(other.fatherName), motherName(other.motherName) {
    cout << "The copy constructor for the FamilyMember class has been called " << endl;
    if (other.childrenCount > 0) {
        children = new FamilyMember*[other.childrenCount];
        for (int i = 0; i < other.childrenCount; ++i) {
            children[i] = other.children[i];
        }
    } else {
        children = nullptr;
    }
}

FamilyMember::~FamilyMember() {
    cout << "The destructor for the FamilyMember class has been called" << endl;
    delete[] children;
    delete[] childrenNames;
}

string FamilyMember::getName()  { return this->name; }

void FamilyMember::setName(string& name) {
    this->name = name;
}

void FamilyMember::setBirthDate(int day, int month, int year) {
    this->birthDay = day;
    this->birthMonth = month;
    this->birthYear = year;
}

void FamilyMember::setDeathDate(int day, int month, int year) {
    this->deathDay = day;
    this->deathMonth = month;
    this->deathYear = year;
}

int FamilyMember::getAge() {
    return this->age;
}

void FamilyMember::setAge(int a) {
    this->age = a;
}

void FamilyMember::setSpouse(FamilyMember* spouse) {
    this->spouse = spouse;
}

void FamilyMember::setFather(FamilyMember* father) {
    this->father = father;
}

void FamilyMember::setMother(FamilyMember* mother) {
    this->mother = mother;
}

void FamilyMember::addChild(FamilyMember* child) {
    FamilyMember** newChildren = new FamilyMember*[childrenCount + 1];
    for (int i = 0; i < childrenCount; ++i) {
        newChildren[i] = children[i]; 
    }
    newChildren[childrenCount] = child;
    delete[] children;
    children = newChildren;
    childrenCount++;
    setChildrenNames(children, childrenCount);
}

string FamilyMember::getSpouseName() {
    return this->spouseName;
}
string FamilyMember::getFatherName() {
    return this->fatherName;
}
string FamilyMember::getMotherName() {
    return this->motherName;
}
void FamilyMember::setSpouseName(FamilyMember* spouse) {
    this->spouseName = spouse->getName();
}
void FamilyMember::setFatherName(FamilyMember* father) {
    this->fatherName = father->getName();
}
void FamilyMember::setMotherName(FamilyMember* mother) {
    this->motherName = mother->getName();
}

string* FamilyMember::getChildrenNames() {
    return this->childrenNames;
}
void FamilyMember::setChildrenNames(FamilyMember** children, int childrenCount) {
    delete[] childrenNames;

    this->childrenNames = new string[childrenCount];

    for (int i = 0; i < childrenCount; ++i) {
        this->childrenNames[i] = children[i]->getName(); // Сохраняем имя в массив
    }
}


void FamilyMember::print() {
    cout << "Name: " << this->name << endl;
    cout << "Date of birth: ";
    if (this->birthDay < 10) {
        cout <<"0" << this->birthDay;
    }
    else {
        cout << this->birthDay;
    }
    cout << ".";
    if (this->birthMonth < 10) {
        cout <<"0" << this->birthMonth;
    }
    else {
        cout << this->birthMonth;
    }
    cout<< "." << this->birthYear << endl;
    if(this->deathDay == 0){
        cout << "Date of death: -" << endl;
    }
    else {
        cout << "Date of death: " << this->deathDay << ".";
        if ((this->deathMonth) < 10){
            cout << "0" << this->deathMonth;
        }
        else  {
            cout << this->deathMonth;
        }
         cout<< "." << this->deathYear << endl;
    }
    cout << "Age: " << this->age << endl;

    if (spouseName != "") {
        cout << "Spouse: " << spouseName << endl;
    } else {
        cout << "Spouse: -" << endl;
    }

    if (motherName != "") {
        cout << "Mother: " << motherName<< endl;
    } else {
        cout << "Mother: -" << endl;
    }
    if (fatherName != "") {
        cout << "Father: " << fatherName << endl;
    } else {
        cout << "Father: -" << endl;
    }
    cout << "Children: " << childrenCount << endl;
    for (int i = 0; i < childrenCount; ++i) {
        cout << i+1 << ". " << childrenNames[i] << endl;
    }
    cout << endl;
}

void FamilyMember::edit_info() {
    int choice;
    string Nname;
    int NbirthDay, NbirthMonth, NbirthYear;
    int NdeathDay, NdeathMonth, NdeathYear;
    
    cout << "Select which data you want to change" << endl;
    cout << "1. The name"<< endl;
    cout << "2. The date of birth"<< endl;
    cout << "3. The date of death"<< endl;
    cout << "0. Exit" << endl;
    choice = check_input();

    switch (choice) {
        case 1: {
            cout << "Enter a new name: ";
            getline(cin, Nname);
            setName(Nname);
            cout << "Data changed successfully" << endl;
            break;
        }
        case 2: {
            cout << "Enter the day of birth (DD): ";
            NbirthDay = check_date_day();;
            cout << "Enter the month of birth (MM): ";
            NbirthMonth = check_date_month();
            cout << "Enter the year of birth (YYYY): ";
            NbirthYear = check_input();
            check_date(NbirthDay, NbirthMonth, NbirthYear);
            setBirthDate(NbirthDay, NbirthMonth, NbirthYear);
            cout << "Data changed successfully" << endl;
            break;
        }
        case 3: {
            cout << "Enter the day of death (0 if alive): ";
            NdeathDay = check_date_day();
            if (NdeathDay == 0) {
                NdeathMonth = NdeathYear = 0;
            }
            else {
                cout << "Enter the month of death (0 if alive): ";
                NdeathMonth = check_date_month();
                cout << "Enter the year of death (0 if alive): ";
                NdeathYear = check_input();
                check_date(NdeathDay, NdeathMonth, NdeathYear);
            }
            setDeathDate(NdeathDay, NdeathMonth, NdeathYear);
            cout << "Data changed successfully" << endl;
            break;
        }
        case 0:
            cout << "Exit from editing" << endl;
            break;
        default:
            cout << "Incorrect choice. Please try again." << endl;
            break;
    }

    age = calculateAge(birthDay, birthMonth, birthYear, deathDay, deathMonth, deathYear);
    setAge(age);
}

void FamilyMember::save_to_file(ostream& out) {
    out << "member" << endl;
    out << name << "\n" << birthDay << "\n" << birthMonth << "\n" << birthYear << "\n" << deathDay << "\n" << deathMonth << "\n" << deathYear << "\n"<< age << endl;
    if (spouse) {
        out << spouseName << endl; 
    } else {
        out << "0" << endl;
    }
    if (father) {
        out << fatherName << endl;
    } else {
        out << "0" << endl;
    }
    if (mother) {
        out << motherName << endl;
    } else {
        out << "0" << endl;
    }
    out << childrenCount << "\n";
    for (int i = 0; i < childrenCount; ++i) {
        out << childrenNames[i]<< "\n";
    }
}

void FamilyMember::load_from_file(istream& in) {
    getline(in, name);
    in >> birthDay;
    in >> birthMonth;
    in >> birthYear;
    in >> deathDay;
    in >> deathMonth;
    in >> deathYear;
    in >> age;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(in, spouseName);
    getline(in, fatherName);
    getline(in, motherName);
    in >> childrenCount;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    childrenNames = new string[childrenCount];
    for (int i = 0; i < childrenCount; ++i) {
        getline(in, childrenNames[i]);
    }
}



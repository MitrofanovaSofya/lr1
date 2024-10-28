#include "keeper.h"
Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) {cout << "Constructor called without parameters for Keeper class\n";}

Keeper::Keeper(Element* h, Element*t, int c) : head(h), tail(t), count(c) {cout << "The constructor with parameters for the Keeper class was called\n";}

Keeper::Keeper(Keeper& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "The copy constructor for the Keeper class has been called\n";
}

Keeper::~Keeper() {
cout << "The destructor for the Keeper class has been called\n";
    delete_all();
}


int Keeper::get_count() {
    return count;
}

Element* Keeper::get_head() {return this->head;}
Element* Keeper::get_tail() {return this->tail;}

void Keeper::delete_head() {
    if (head) {
        Element* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
        count--;
        if (count == 0) {
            tail = nullptr;
        }
    }
}

void Keeper::delete_all() {
    while (head != 0)
        delete_head();
}

Keeper& Keeper::delete_element(int n) {
    if (n < 1 || n > count) {
        cout << "Incorrect element index" << endl;
        return *this;
    }

    if (n == 1) {
        this->operator--(0); 
        return *this;
    }

    Element* temp = head;
    for (int i = 1; i < n - 1; i++) {
        temp = temp->next;
    }

    Element* toDelete = temp->next;
    temp->next = toDelete->next;

    if (toDelete == tail) {
        tail = temp;
    }

    delete toDelete->data;
    delete toDelete;
    count--;
    return *this;
}

Keeper& Keeper::edit_element(int n) {
    if (n < 1 || n > count) {
        cout << "Incorrect element index" << endl;
        return *this;
    }

    Element* temp = head;
    for (int i = 1; i < n; i++) {
        temp = temp->next;
    }

    if (temp->data) {
        temp->data->edit_info(); 
    } else {
        cout << "There is no data" << endl;
    }

    return *this;
}

void Keeper::add_to_head(Person* tmp) {
    Element* new_el = new Element;
    new_el->data = tmp;
    new_el->next = head;
    if (head == nullptr) {
        tail = new_el;
    }
    head = new_el;
    count++;
}

void Keeper::add_to_tail(Person* tmp) {
    Element* new_el = new Element;
    new_el->data = tmp;
    new_el->next = nullptr;
    if (head == nullptr) {
        head = tail = new_el;
    }
    else {
        tail->next = new_el;
        tail = new_el;
    }
    count++;
}

Keeper& operator--(Keeper& K) {
    if (K.count == 0) {
        cout << "There is no data. Cannot be deleted first" << endl;
        return K;
    }
    Element* temp = K.head;
    K.head = K.head->next;
    delete temp->data;
    delete temp;
    K.count--;
    if (K.count == 0) {
        K.tail = nullptr;
    }
    return K;
}

Keeper& Keeper::operator--(int) {
    if (this->count == 0) {
        cout << "There is no data. Cannot be deleted from the end" << endl;
        return *this;
    }
    if (this->count == 1) {
        delete this->head;
        this->head = this->tail = nullptr;
    } else {
        Element* temp = this->head;
        while (temp->next != this->tail) {
            temp = temp->next;
        }
        delete this->tail->data;
        delete this->tail;
        this->tail = temp;
        this->tail->next = nullptr;
    }
    this->count--;
    return *this;
}

Keeper& operator++(Keeper& K, int) {
    string name;
    int birthDay, birthMonth, birthYear;
    int deathDay, deathMonth, deathYear;
    int age;

    cout << "Enter the name: ";
    getline(cin, name);
    cout << "Enter the day of birth (DD): ";
    birthDay = check_date_day();
    cout << "Enter the month of birth (MM): ";
    birthMonth = check_date_month();
    cout << "Enter the year of birth (YYYY): ";
    birthYear = check_input();
    check_date(birthDay, birthMonth, birthYear);
    cout << "Enter the day of death (0 if alive): ";
    deathDay = check_date_day();
    if (deathDay == 0) {
        deathMonth = deathYear = 0;
    }
    else {
        cout << "Enter the month of death: ";
        deathMonth = check_date_month();
        cout << "Enter the year of death: ";
        deathYear = check_input();
        check_date(deathDay, deathMonth, deathYear);
    }
    age = calculateAge(birthDay, birthMonth, birthYear, deathDay, deathMonth, deathYear);

    FamilyMember* member = new FamilyMember(name, birthDay, birthMonth, birthYear, deathDay, deathMonth, deathYear, age);
    K.add_to_tail(member);
}

Keeper& Keeper::operator++() {
    string name;
    int birthDay, birthMonth, birthYear;
    int deathDay, deathMonth, deathYear;
    int age;

    cout << "Enter the name: ";
    getline(cin, name);
    cout << "Enter the day of birth (DD): ";
    birthDay = check_date_day();
    cout << "Enter the month of birth (MM): ";
    birthMonth = check_date_month();
    cout << "Enter the year of birth (YYYY): ";
    birthYear = check_input();
    check_date(birthDay, birthMonth, birthYear);
    cout << "Enter the day of death (0 if alive): ";
    deathDay = check_date_day();
    if (deathDay == 0) {
        deathMonth = deathYear = 0;
    }
    else {
        cout << "Enter the month of death: ";
        deathMonth = check_date_month();
        cout << "Enter the year of death: ";
        deathYear = check_input();
        check_date(deathDay, deathMonth, deathYear);
    }

    age = calculateAge(birthDay, birthMonth, birthYear, deathDay, deathMonth, deathYear);

    FamilyMember* member = new FamilyMember(name, birthDay, birthMonth, birthYear, deathDay, deathMonth, deathYear, age);
    add_to_head(member);   
}

void Keeper::print_keeper() {
    Element* temp = head;

    if (count == 0) {
        cout << "There is no data" << endl;
        return;
    }
    int i = 0;
    while (temp != 0) {
        cout << i + 1 <<" - ";
        if (temp->data) {
            temp->data->print(); 
        } else {
            cout << "There is no data";
        }
        cout << " " << endl;;
        temp = temp->next;
        i++;
    }
}

void Keeper::save_to_file(const string& filename) {
    ofstream out(filename);
    Element* current = head;
    while (current != nullptr) {
        current->data->save_to_file(out);
        current = current->next;
    }
    out.close();
}

void Keeper::load_from_file(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Error открытия файла для загрузки!" << endl;
        return;
    }
    string marker;
    while (getline(in, marker)) {
        if (!marker.empty() && marker.back() == '\r') {
            marker.pop_back();
        }
        Person* temp = nullptr;
        temp = new FamilyMember();
        if (temp) {
                temp->load_from_file(in);
                cout << "The object has been added to the container" << endl;
                this->add_to_tail(temp);
            }
    }
    in.close();
}


void Keeper::setSpouse(int index1, int index2) {
    if (index1 < 1 || index1 > count || index2 < 1 || index2 > count) {
        throw out_of_range("Index out of range");
    }

    Element* current = head;
    int i = 0;
    FamilyMember* member1 = nullptr;
    FamilyMember* member2 = nullptr;

    // Находим нужные элементы по индексам
    while (current) {
        if (i == (index1-1)) {
            member1 = dynamic_cast<FamilyMember*>(current->data);
        }
        if (i == (index2-1)) {
            member2 = dynamic_cast<FamilyMember*>(current->data);
        }
        current = current->next;
        i++;
    }

    if (member1 && member2) {
        member1->setSpouse(member2);
        member1->setSpouseName(member2);
        member2->setSpouse(member1);
        member2->setSpouseName(member1);
    } else {
        throw runtime_error("One of the members is not a FamilyMember or does not exist.");
    }
}

void Keeper::setFatherChild(int index1, int index2) {
    if (index1 < 1 || index1 > count || index2 < 1 || index2 > count) {
        throw out_of_range("Index out of range");
    }

    Element* current = head;
    int i = 0;
    FamilyMember* member1 = nullptr;
    FamilyMember* member2 = nullptr;

    while (current) {
        if (i == (index1-1)) {
            member1 = dynamic_cast<FamilyMember*>(current->data);
        }
        if (i == (index2-1)) {
            member2 = dynamic_cast<FamilyMember*>(current->data);
        }
        current = current->next;
        i++;
    }

    if (member1 && member2 && index1 != index2 ) {
        member1->addChild(member2);
        member2->setFather(member1);
        member2->setFatherName(member1);
    } else {
        throw runtime_error("One of the members is not a FamilyMember or does not exist.");
    }
}
void Keeper::setMotherChild(int index1, int index2) {
    if (index1 < 1 || index1 > count || index2 < 1 || index2 > count) {
        throw out_of_range("Index out of range");
    }

    Element* current = head;
    int i = 0;
    FamilyMember* member1 = nullptr;
    FamilyMember* member2 = nullptr;

    while (current) {
        if (i == (index1-1)) {
            member1 = dynamic_cast<FamilyMember*>(current->data);
        }
        if (i == (index2-1)) {
            member2 = dynamic_cast<FamilyMember*>(current->data);
        }
        current = current->next;
        i++;
    }

    if (member1 && member2 && index1 != index2 ) {
        member1->addChild(member2);
        member2->setMother(member1);
        member2->setMotherName(member1);
    } else {
        throw runtime_error("One of the members is not a FamilyMember or does not exist.");
    }
}

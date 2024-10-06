#include "check.h"

int check_input() {
    int val;
    while (true) {
        cin >> val;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Incorrect input. Please enter a number: " << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return val;
        }
    }
}

#include <iostream>
#include "keeper.h"
#include "check.h"

using namespace std;

void display_menu() {
    cout << "Menu:" << endl;
    cout << "1. Add a family member to the end" << endl;
    cout << "2. Add a family member to the beginning" << endl;
    cout << "3. Delete a family member by index" << endl;
    cout << "4. Delete a family member from the end" << endl;
    cout << "5. Delete a family member from the beginning" << endl;
    cout << "6. Edit information about a family member" << endl;
    cout << "7. Show all family members" << endl;
    cout << "8. Save data to a file" << endl;
    cout << "9. Download data from a file" << endl;
    cout << "10. Set spouse for a family member" << endl;
    cout << "11. Set father and child" << endl;
    cout << "12. Set mother and child" << endl;
    cout << "0. Exit" << endl;
    cout << "Select an option: ";
}

int main() {
    Keeper keeper;
    int choice;
    while (choice != 0) {
            try {
                display_menu();
                choice = check_input();
                switch (choice) {
                    case 1: {
                        keeper++;
                        break;
                    }
                    case 2: {
                        ++keeper;
                        break;
                    }
                    case 3: {
                        cout << "Enter the number of the family member to delete: ";
                        int index = check_input();
                        keeper.delete_element(index); 
                        break;
                    }
                    case 4: {
                        keeper--;
                        break;
                    }
                    case 5: {
                        --keeper;
                        break;
                    }
                    case 6: {
                        cout << "Enter the family member's number to edit:  ";
                        int index = check_input();
                        keeper.edit_element(index); 
                        break;
                    }
                    case 7:
                        keeper.print_keeper(); 
                        break;
                    case 8: {
                        try {
                            keeper.save_to_file("out.txt");
                        } catch (const runtime_error& e) {
                            cerr << "Error saving the file: " << e.what() << endl;
                        }
                        break;
                    }
                    case 9: {
                        try {
                            keeper.load_from_file("out.txt");
                        } catch (const runtime_error& e) {
                            cerr << "Error uploading the file: " << e.what() << endl;
                        }
                        break;
                    }
                    case 10: { // Установка супруга
                        cout << "Enter the index of the family member: ";
                        int index1 = check_input();
                        cout << "Enter the index of the spouse: ";
                        int index2 = check_input();
                        keeper.setSpouse(index1, index2);
                        break;
                    }
                    case 11: { 
                        cout << "Enter the index of the father: ";
                        int index1 = check_input();
                        cout << "Enter the index of the child: ";
                        int index2 = check_input();
                        keeper.setFatherChild(index1, index2);
                        break;
                    }
                    case 12: { 
                        cout << "Enter the index of the mother: ";
                        int index1 = check_input();
                        cout << "Enter the index of the child: ";
                        int index2 = check_input();
                        keeper.setMotherChild(index1, index2);
                        break;
                    }
                    case 0:
                        cout << "Exit" << endl;
                        break;
                    default:
                        cout << "Incorrect choice. Please try again." << endl;
                        break;
                }
            } catch (const invalid_argument& e) {
                cerr << "Error: " << e.what() << endl;
            } catch (const out_of_range& e) {
                cerr << "Error: " << e.what() << endl;
            } catch (const runtime_error& e) {
                cerr << "Error: " << e.what() << endl;
            } catch (...) {
                cerr << "Unknown error!" << endl;
            }
        }
        cout << "Thanks)";
        return 0;
        
}
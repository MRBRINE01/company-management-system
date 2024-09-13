#include <iostream>
#include "admin_main.hpp"

using namespace std;

void adminMenu() {
    int adminChoice;

    do {
        cout << "\n\t\t|-----------------------------------------------|\n";
        cout << "\t\t|\t Choose your option:\t                |\n"; 
        cout << "\t\t|-----------------------------------------------|\n";
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 1) ADD EMPLOYEE                |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 2) REMOVE EMPLOYEE             |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 3) VIEW EMPLOYEES              |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 4) ADD PROJECT                 |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 5) VIEW PROJECT                |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 6) EXIT                        |\n"; 
        cout << "\t\t|-----------------------------------------------|\n";

        cin >> adminChoice;

        switch (adminChoice) {
        case 1:
            cout << "Add Employee functionality is not implemented yet.\n";
            break;
        case 2:
            cout << "Remove Employee functionality is not implemented yet.\n";
            break;
        case 3:
            cout << "View Employees functionality is not implemented yet.\n";
            break;
        case 4:
            cout << "Add Project functionality is not implemented yet.\n";
            break;
        case 5:
            cout << "View Project functionality is not implemented yet.\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (adminChoice != 6);
}

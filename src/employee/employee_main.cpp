#include <iostream>
#include "employee_main.hpp"

using namespace std;

void employeeMenu(){
    int adminChoice;

    do {
        cout << "\n\t\t|-----------------------------------------------|\n";
        cout << "\t\t|\t Choose your option:\t                |\n"; 
        cout << "\t\t|-----------------------------------------------|\n";
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 1) ADD LOG                     |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 2) REMOVE LOG                  |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 3) VIEW PROJECTS ASSIGNED      |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 4) EXIT                        |\n"; 
        cout << "\t\t|-----------------------------------------------|\n";

        cin >> adminChoice;

        switch (adminChoice) {
        case 1:
            cout << "Add Log functionality is not implemented yet.\n";
            break;
        case 2:
            cout << "Remove Log functionality is not implemented yet.\n";
            break;
        case 3:
            cout << "View Project assigned functionality is not implemented yet.\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (adminChoice != 4);
}
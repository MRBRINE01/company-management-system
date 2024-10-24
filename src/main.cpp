#include <iostream>
#include "admin/admin_main.hpp"
#include "employee/employee_main.hpp"

using namespace std;

int main() {
    int mainMenuCh;

    string adminpass = "admin123";
    string enteredpass;



    do {
        cout << "\n\t\t|-----------------------------------------------|\n";
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|     WELCOME TO COMPANY MANAGEMENT SYSTEM      |\n";
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|-----------------------------------------------|\n";
        cout << "\t\t|\t Choose your option:\t                |\n"; 
        cout << "\t\t|-----------------------------------------------|\n";
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 1) ADMINISTRATOR               |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 2) EMPLOYEE                    |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 3) GENERATE REPORT             |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 4) EXIT                        |\n"; 
        cout << "\t\t|-----------------------------------------------|\n";

        cin >> mainMenuCh;

        switch (mainMenuCh) {
        case 1: 
            cout << "Enter the password for the Admin: ";
            cin >> enteredpass;
            if (enteredpass == adminpass)
            {
                cout << "Access granted.\n";
                adminMenu();
            }
            else{
                cout << "Access Denied.\n";
            }
            break;
        case 2:
            employeeMenu();
            break;
        case 3:
            break;
        case 4:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (mainMenuCh != 4);

    return 0;
}
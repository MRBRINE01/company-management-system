#include <iostream>
#include <string>
using namespace std;

class employee_log
{
private:
    int logId;
    int projectId;
    int HoursWorked;
    string details;
    string isCompleted;
public:
    // employee_log(/* args */);
    // ~employee_log();
    void createLog();
    void deleteLog();
};

void employee_log::createLog() {
    cout << "\n\t\t|-----------------------------------------------|\n";
    cout << "\t\t|\t Enter Log Details:\t                |\n";
    cout << "\t\t|-----------------------------------------------|\n";

    cout << "Enter Log ID: ";
    cin >> logId;

    cout << "Enter Project ID: ";
    cin >> projectId;

    cout << "Enter Hours Worked: ";
    cin >> HoursWorked;

    cout << "Enter Log Details: ";
    cin.ignore();
    getline(cin, details);

    cout << "Projected completed? yes or no: ";
    cin >> isCompleted;

}

void employee_log::deleteLog(){
    int LogId;
    cout << "\n\t\t|-----------------------------------------------|\n";
    cout << "\t\t|\t Enter Log ID to Delete:\t        |\n";
    cout << "\t\t|-----------------------------------------------|\n";
    cout << "Enter Log ID: ";
    cin >>  LogId;
    
}

void employeeMenu(){
    int adminChoice;

    int count=0;
   employee_log al[200];

    do {
        cout << "\n\t\t|-----------------------------------------------|\n";
        cout << "\t\t|\t Choose your option:\t                |\n"; 
        cout << "\t\t|-----------------------------------------------|\n";
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 1) ADD LOG                     |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 2) REMOVE LOG                  |\n"; 
        cout << "\t\t|                                               |\n";
        cout << "\t\t|\t\t 2) EDIT LOG                    |\n"; 
        cout << "\t\t|                                               |\n";
        cout << "\t\t|\t\t 4) VIEW PROJECTS ASSIGNED      |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 5) EXIT                        |\n"; 
        cout << "\t\t|-----------------------------------------------|\n";

        cin >> adminChoice;

        switch (adminChoice) {
        case 1:
            al[count].createLog();
            count++;
            break;
        case 2:
            al[count].deleteLog();
            count--;
            break;
        case 3:
            cout << "Edit Log";
            break;
        case 4:
            cout << "View Project assigned functionality is not implemented yet.\n";
            break;
        case 5:
            cout << "Heading back to main menu.\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (adminChoice != 5);
}
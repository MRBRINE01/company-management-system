#include <iostream>
#include <string>
#include <vector>
using namespace std;

class employee_log {
private:
    int logId;
    int projectId;
    int HoursWorked;
    string details;
    string isCompleted;

public:
    employee_log(){};
    employee_log(int logId, int projectId, int HoursWorked, string details, string isCompleted) {
        this->logId = logId;
        this->projectId = projectId;
        this->HoursWorked = HoursWorked;
        this->details = details;
        this->isCompleted = isCompleted;
    }
    void createLog();
    bool deleteLog(int logIdToDelete);
    bool editLog(int logIdToEdit);
    void displayLog();
    bool viewLogById(int logIdToView);
    
    int getLogId() { return logId; }
};

// Function to create a new log entry
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

    cout << "Is Project completed? (yes or no): ";
    cin >> isCompleted;
}

// Function to delete a log based on logId
bool employee_log::deleteLog(int logIdToDelete) {
    if (logId == logIdToDelete) {
        logId = -1;
        cout << "Log with ID " << logIdToDelete << " deleted successfully.\n";
        return true;
    } else {
        return false;
    }
}

// Function to edit an existing log based on logId
bool employee_log::editLog(int logIdToEdit) {
    if (logId == logIdToEdit) {
        cout << "\nEditing log with ID " << logIdToEdit << "...\n";
        cout << "Enter new Project ID: ";
        cin >> projectId;

        cout << "Enter new Hours Worked: ";
        cin >> HoursWorked;

        cout << "Enter new Log Details: ";
        cin.ignore();
        getline(cin, details);

        cout << "Is Project completed? (yes or no): ";
        cin >> isCompleted;

        cout << "Log with ID " << logIdToEdit << " updated successfully.\n";
        return true;
    } else {
        return false;
    }
}

bool employee_log::viewLogById(int logIdToView) {
    bool flag = false;
    if (logId == logIdToView) {
        displayLog(); 
        return true;
    }

    return false;
}

// Function to display the log details 
void employee_log::displayLog() {
    if (logId != -1) {
        cout << "\nLog ID: " << logId;
        cout << "\nProject ID: " << projectId;
        cout << "\nHours Worked: " << HoursWorked;
        cout << "\nDetails: " << details;
        cout << "\nCompleted: " << isCompleted << endl;
    }
}

// Menu function for employee log management
void employeeMenu() {
    int adminChoice;
    int count = 0;
    bool flag;

    vector<employee_log> logs; 
    employee_log newlog; 

    int logIdToEditOrDelete;
    int logIdToView;

    do {
        cout << "\n\t\t|-----------------------------------------------|\n";
        cout << "\t\t|\t Choose your option:\t                |\n"; 
        cout << "\t\t|-----------------------------------------------|\n";
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 1) ADD LOG                     |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 2) REMOVE LOG                  |\n"; 
        cout << "\t\t|                                               |\n";
        cout << "\t\t|\t\t 3) EDIT LOG                    |\n"; 
        cout << "\t\t|                                               |\n";
        cout << "\t\t|\t\t 4) VIEW PROJECTS ASSIGNED      |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 5) VIEW LOG BY ID              |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 6) EXIT                        |\n";
        cout << "\t\t|-----------------------------------------------|\n";

        cin >> adminChoice; 

        flag = false;

        switch (adminChoice) {
            case 1:
                newlog.createLog();
                logs.push_back(newlog);
                break;
            case 2:
                cout << "Enter Log ID to Delete: ";
                cin >> logIdToEditOrDelete;
                for (auto i = logs.begin(); i != logs.end(); ++i) {
                    if (i->deleteLog(logIdToEditOrDelete)) {
                        logs.erase(i);  
                        flag = true;
                        break;
                    }
                }
                    if (!flag)
                {
                    cout << "Log with ID " << logIdToEditOrDelete << " not found.\n";
                }
                
                break;
            case 3:
                cout << "Enter Log ID to Edit: ";
                cin >> logIdToEditOrDelete;
                for (auto& log : logs) { //using auto& ensures that you're working with the actual employee_log objects and not copies
                    flag = log.editLog(logIdToEditOrDelete);
                }
                if (!flag)
                {
                    cout << "Log with ID " << logIdToEditOrDelete << " not found.\n";
                }
                break;
            case 4:
                cout << "Displaying all logs:\n";
                 for (auto& log : logs) { //using auto& ensures that you're working with the actual employee_log objects and not copies
                    log.displayLog();
                }
                break;
            case 5: 
                cout << "Enter Log ID to View: ";
                cin >> logIdToView;
                for (auto& log : logs) { //using auto& ensures that you're working with the actual employee_log objects and not copies
                    flag = log.viewLogById(logIdToView);
                }
                if (!flag)
                {
                    cout << "Log with ID " << logIdToView << " not found.\n";
                }
                
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (adminChoice != 6);  
}

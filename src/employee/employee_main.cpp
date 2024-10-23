#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
    void createLog(int newLogId);
    bool deleteLog(int logIdToDelete);
    bool editLog(int logIdToEdit);
    void displayLog();
    bool viewLogById(int logIdToView);
    
    int getLogId() { return logId; }

    void saveLogToFile() {
        ofstream logFile("logs.txt", ios::app); // Open in append mode
        if (logFile.is_open()) {
            logFile << logId << "," << projectId << "," << HoursWorked << "," 
                    << details << "," << isCompleted << endl;
            logFile.close();
        } else {
            cout << "Unable to open log file for writing.\n";
        }
    }

    // Static function to load logs from a file and populate the logs vector
    static vector<employee_log> loadLogsFromFile(int &maxLogId) {
        vector<employee_log> logs;
        ifstream logFile("logs.txt");
        maxLogId = 0;
        if (logFile.is_open()) {
            string line;
            while (getline(logFile, line)) {
                int logId, projectId, hours;
                string details, isCompleted;
                size_t pos = 0;

                // Extracting the logId
                pos = line.find(",");
                logId = stoi(line.substr(0, pos));
                line.erase(0, pos + 1);

                // Extracting the projectId
                pos = line.find(",");
                projectId = stoi(line.substr(0, pos));
                line.erase(0, pos + 1);

                // Extracting HoursWorked
                pos = line.find(",");
                hours = stoi(line.substr(0, pos));
                line.erase(0, pos + 1);

                // Extracting the details
                pos = line.find(",");
                details = line.substr(0, pos);
                line.erase(0, pos + 1);

                // Extracting isCompleted
                isCompleted = line;

                // Create a new log object and add to the vector
                employee_log log(logId, projectId, hours, details, isCompleted);
                logs.push_back(log);
                if (logId > maxLogId) {
                    maxLogId = logId;
                }
            }
            logFile.close();
        } else {
            cout << "Unable to open log file for reading.\n";
        }
        return logs;
    }

    // Update function to rewrite the logs to the file after any changes
    static void updateLogFile(const vector<employee_log>& logs) {
        ofstream logFile("logs.txt", ios::trunc); // Open in truncation mode (overwrite)
        if (logFile.is_open()) {
            for (const auto& log : logs) {
                logFile << log.logId << "," << log.projectId << "," << log.HoursWorked << "," 
                        << log.details << "," << log.isCompleted << endl;
            }
            logFile.close();
        } else {
            cout << "Unable to open log file for updating.\n";
        }
    }
};

// Function to create a new log entry
void employee_log::createLog(int newLogId) {
    cout << "\n\t\t|-----------------------------------------------|\n";
    cout << "\t\t|\t Enter Log Details:\t                |\n";
    cout << "\t\t|-----------------------------------------------|\n";

       logId = newLogId;

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
    bool flag;
    int maxLogId = 0;

    // Load logs from file at the beginning
    vector<employee_log> logs = employee_log::loadLogsFromFile(maxLogId);
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
                newlog.createLog(++maxLogId);
                logs.push_back(newlog);
                newlog.saveLogToFile();  // Save new log to file
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
                if (!flag) {
                    cout << "Log with ID " << logIdToEditOrDelete << " not found.\n";
                } else {
                    employee_log::updateLogFile(logs);  // Update the log file after deletion
                }
                break;
            case 3:
                cout << "Enter Log ID to Edit: ";
                cin >> logIdToEditOrDelete;
                for (auto& log : logs) {
                    flag = log.editLog(logIdToEditOrDelete);
                    if (flag) break;
                }
                if (!flag) {
                    cout << "Log with ID " << logIdToEditOrDelete << " not found.\n";
                } else {
                    employee_log::updateLogFile(logs);  
                }
                break;
            case 4:
                cout << "Displaying all logs:\n";
                for (auto& log : logs) {
                    log.displayLog();
                }
                break;
            case 5: 
                cout << "Enter Log ID to View: ";
                cin >> logIdToView;
                for (auto& log : logs) {
                    flag = log.viewLogById(logIdToView);
                }
                if (!flag) {
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

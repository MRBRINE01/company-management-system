#include <iostream>
#include <string>
#include <fstream>
 //Give path as per your directory
#include "F:/a Study/engg/sem-3/OOC/mini project/company-management-system/json/single_include/nlohmann/json.hpp"
#include "employee_main.hpp"

using json = nlohmann::json;
using namespace std;

class add_log
{
private:
    int logId;
    int projectId;
    int HoursWorked;
    string details;
    string isCompleted;
public:
    // add_log(/* args */);
    // ~add_log();
    void createLog();
};

void add_log::createLog() {
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
    cin.ignore();  // Ignore the newline character left in the input stream
    getline(cin, details);

    cout << "Projected completed? yes or no: ";
    cin >> isCompleted;
    
    //Give path as per your directory
    const string filename = "F:/a Study/engg/sem-3/OOC/mini project/company-management-system/src/employee/employee_data.json";
    json new_log = {
        {"id", logId},
        {"projectId", projectId},
        {"hoursWorked", HoursWorked},
        {"Details", details}
    };

    json data = json::array();

    ifstream infile(filename);
    if (infile.is_open()) {
        if (infile.peek() != ifstream::traits_type::eof()) {
            infile >> data;
        }
        infile.close();
    }

    data.push_back(new_log);

    ofstream outfile(filename);
    if (outfile.is_open()) {
        outfile << data.dump(4);
        outfile.close();
        cout << "Contact added successfully!" << endl;
    } else {
        cout << "Unable to open file for writing!" << endl;
    }

}

void employeeMenu(){
    int adminChoice;

    add_log al;

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
            al.createLog();
            break;
        case 2:
            cout << "Remove Log functionality is not implemented yet.\n";
            break;
        case 3:
            cout << "View Project assigned functionality is not implemented yet.\n";
            break;
        case 4:
            cout << "Heading back to main menu.\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (adminChoice != 4);
}
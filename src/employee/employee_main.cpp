#include <iostream>
#include <string>
#include <fstream>
 //Give path as per your directory
#include "F:/a Study/engg/sem-3/OOC/mini project/company-management-system/json/single_include/nlohmann/json.hpp"
#include "employee_main.hpp"

using json = nlohmann::json;
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
    cin.ignore();  // Ignore the newline character left in the input stream
    getline(cin, details);

    cout << "Projected completed? yes or no: ";
    cin >> isCompleted;
    
    //Give path as per your directory
    const string filename = "./employee_data.json";
    json new_log = {
        {"id", logId},
        {"projectId", projectId},
        {"hoursWorked", HoursWorked},
        {"details", details}
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

void employee_log::deleteLog(){
    int LogId;
    cout << "\n\t\t|-----------------------------------------------|\n";
    cout << "\t\t|\t Enter Log ID to Delete:\t        |\n";
    cout << "\t\t|-----------------------------------------------|\n";
    cout << "Enter Log ID: ";
    cin >>  LogId;

      const string filename = "./employee_data.json";
    json data;

    // Open and read the JSON file
    ifstream infile(filename);
    if (infile.is_open()) {
        if (infile.peek() != ifstream::traits_type::eof()) {
            infile >> data;
        }
        infile.close();
    } else {
        cout << "Unable to open file for reading!" << endl;
        return;
    }
    bool logFound = false;
    for (auto i = data.begin(); i != data.end(); i++)
    {
       if((*i)["id"] == LogId){
        data.erase(i);
        logFound = true;
        break;
       }
    }
    
    if (logFound)
    {
        ofstream outfile(filename);
        if (outfile.is_open()) {
            outfile << data.dump(4);  // Save JSON with indentation for readability
            outfile.close();
            cout << "Log deleted successfully!" << endl;
        } else {
            cout << "Unable to open file for writing!" << endl;
        }
    } else {
        cout << "Log ID not found!" << endl;
    }
    
    

}

void employeeMenu(){
    int adminChoice;

    int count=0;
   employee_log al[20];

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
            count++;
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
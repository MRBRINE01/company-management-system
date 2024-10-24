#include <iostream>
#include <vector>
#include <string>
#include <fstream>  // For file handling

using namespace std;

class Employee {
public:
    int id;
    string name;
    string role;
    string username;
    string password;
    vector<int> assignedProjects;

    Employee(int id, string name, string role, string username, string password) {
        //When you use this->, you're explicitly referring to a member (like a variable or method) of the current object that called the function.
        this->id = id;
        this->name = name;
        this->role = role;
        this->username = username;
        this->password = password; 
    }

    void assignProject(int projectId);

    void displayEmployee();
};

void Employee::assignProject(int projectId) {
        assignedProjects.push_back(projectId);
        cout << "Project ID " << projectId << " assigned to employee " << name << endl;
    }

void Employee::displayEmployee(){
        cout << "ID: " << id << ", Name: " << name << ", Role: " << role << endl;
        if (assignedProjects.empty()) {
            cout << "No project assigned.\n";
        }
        else {
            cout << "Assigned Projects: ";
            for (auto projectId : assignedProjects) {
                cout << projectId << " ";
            }
            cout << endl;
        }
    }

class Project {
public:
    int id;
    string name;
    string description;
    int assignedEmployeeId;
    int budget;

    Project(int id, string name, string description, int assignedEmployeeId, int budget) {
        this->id = id;
        this->name = name;
        this->description = description;
        this->assignedEmployeeId = assignedEmployeeId;
        this->budget = budget;
    }

    void displayProject() {
        cout << "ID: " << id << ", Name: " << name << ", Description: " << description << ", Budget: $" << budget << endl;
    }
};

class Admin {
private:
    vector<Employee> employees;
    vector<Project> projects;

public:
    void addEmployee();
    void removeEmployee();
    void viewEmployees();
    void addProject();
    void viewProjects();
    void saveData(); // Save employees and projects to file
    void loadData();
    // Load employees and projects from file
};



void Admin::addEmployee() {
    int id;
    string name, role, username, password;

    cout << "\nEnter Employee ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Employee Name: ";
    getline(cin, name);
    cout << "Enter Employee Role: ";
    getline(cin, role);
    cout << "Enter Employee Username: ";
    getline(cin, username);
    cout << "Enter Employee Password: ";
    getline(cin, password);

    employees.push_back(Employee(id, name, role, username, password));
    cout << "Employee added successfully!\n";
}

void Admin::removeEmployee() {
    int id;
    cout << "\nEnter Employee ID to Remove: ";
    cin >> id;

    bool found = false;
    for (size_t i = 0; i < employees.size(); i++) {
        if (employees[i].id == id) {
            employees.erase(employees.begin() + i);
            cout << "Employee with ID " << id << " removed successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Employee with ID " << id << " not found.\n";
    }
}

void Admin::viewEmployees() {
    if (employees.empty()) {
        cout << "No employees to display.\n";
    } else {
        cout << "\nList of Employees:\n";
        for (int i = 0; i < employees.size(); i++) {
            employees[i].displayEmployee();
        }
    }
}

void Admin::addProject() {
    int id;
    string name, description;
    int budget;
    int emp_id;

    cout << "Enter the employee id you want to assign this project to: ";
    cin >> emp_id;

    bool employeeFound = false;

    for (auto& employee : employees) {
        if (employee.id == emp_id) {

            employeeFound = true;

            bool projectExists = false;

            do {
                cout << "\nEnter Project ID: ";
                cin >> id;

                projectExists = false;
                for (const auto& project : projects) {
                    if (project.id == id) {
                        projectExists = true;
                        cout << "Project with ID " << id << " already exists. Please enter a unique Project ID.\n";
                        break;
                    }
                }
            } while (projectExists);

            cin.ignore();
            employee.assignProject(id);
            cout << "Enter Project Name: ";
            getline(cin, name);
            cout << "Enter Project Description: ";
            getline(cin, description);
            cout << "Enter the budget of the project: ";
            cin >> budget;

            projects.push_back(Project(id, name, description, emp_id, budget));
            cout << "Project added successfully!\n";
        }
    }
    if (!employeeFound) {
        cout << "No employee found with that id\n";
    }

    cout << endl;
}

void Admin::viewProjects() {
    if (projects.empty()) {
        cout << "No projects to display.\n";
    } else {
        cout << "\nList of Projects:\n";
        for (size_t i = 0; i < projects.size(); i++) {
            projects[i].displayProject();
        }
    }
}

void Admin::saveData() {
    ofstream employeeFile("employees.txt");
    ofstream projectFile("projects.txt");

    // Save employees
    for (const auto& emp : employees) {
       employeeFile << emp.id << "," << emp.name << "," << emp.role << "," << emp.username << "," << emp.password;
        if (!emp.assignedProjects.empty()) {
            employeeFile << ","; // Add a comma before listing project IDs
            for (size_t i = 0; i < emp.assignedProjects.size(); i++) {
                employeeFile << emp.assignedProjects[i];
                if (i != emp.assignedProjects.size() - 1) {
                    employeeFile << ",";  // Add a comma between project IDs
                }
            }
        }
        employeeFile << endl; // Move to the next line for the next employee
    }
    

    // Save projects
    for (const auto& proj : projects) {
        projectFile << proj.id << "," << proj.name << "," << proj.description << "," << proj.assignedEmployeeId << "," << proj.budget << endl;
    }

    cout << "Data saved successfully!\n";

    employeeFile.close();
    projectFile.close();
}

void Admin::loadData() {
    ifstream employeeFile("employees.txt");
    ifstream projectFile("projects.txt");

    // Load employees
    if (employeeFile.is_open()) {
        string line;
        while (getline(employeeFile, line)) {
            int id;
            string name, role, username, password;
            vector<int> assignedProjects;

            size_t pos = 0;
            pos = line.find(",");
            id = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            name = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            role = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            username = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            password = line.substr(0, pos);
            line.erase(0, pos + 1);

            // Parse the assigned projects (if any)
            while (!line.empty()) {
                pos = line.find(",");
                if (pos != string::npos) {
                    assignedProjects.push_back(stoi(line.substr(0, pos)));
                    line.erase(0, pos + 1);
                } else {
                    assignedProjects.push_back(stoi(line));
                    line.clear();
                }
            }

            employees.push_back(Employee(id, name, role, username, password));
            employees.back().assignedProjects = assignedProjects;
        }
        employeeFile.close();
    }

    // Load projects
    if (projectFile.is_open()) {
        string line;
        while (getline(projectFile, line)) {
            int id, assignedEmployeeId, budget;
            string name, description;
            
            size_t pos = 0;
            pos = line.find(",");
            id = stoi(line.substr(0, pos)); //convert string to int using stoi
            line.erase(0, pos + 1);

            pos = line.find(",");
            name = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            description = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            assignedEmployeeId = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            budget = stoi(line);

            projects.push_back(Project(id, name, description, assignedEmployeeId, budget));
        }
        projectFile.close();
    }

    cout << "Data loaded successfully!\n";
}

void adminMenu() {
    Admin admin;
    admin.loadData();  // Load data when the program starts
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
        cout << "\t\t|\t\t 5) VIEW PROJECTS               |\n"; 
        cout << "\t\t|                                               |\n"; 
        cout << "\t\t|\t\t 6) SAVE & EXIT                 |\n"; 
        cout << "\t\t|-----------------------------------------------|\n";
        cout << endl;
        cout << "Enter your choice: ";
        cin >> adminChoice;

        switch (adminChoice) {
        case 1:
            admin.addEmployee();
            break;
        case 2:
            admin.removeEmployee();
            break;
        case 3:
            admin.viewEmployees();
            break;
        case 4:
            admin.addProject();
            break;
        case 5:
            admin.viewProjects();
            break;
        case 6:
            admin.saveData(); // Save data before exiting
            cout << "Exiting admin menu...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (adminChoice != 6);
}


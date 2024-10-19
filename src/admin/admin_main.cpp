#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
public:
    int id;
    string name;
    string role;
    vector<int> assignedProjects;


    Employee(int id, string name, string role) {
        //When you use this->, you're explicitly referring to a member (like a variable or method) of the current object that called the function.
        this->id = id;
        this->name = name;
        this->role = role;
    }

    void assignProject(int projectId) {
        assignedProjects.push_back(projectId);
        cout << "Project ID " << projectId << " assigned to employee " << name << endl;
    }

    void displayEmployee() {
        cout << "ID: " << id << ", Name: " << name << ", Role: " << role << endl;
        if(assignedProjects.empty()){
            cout << "No project assigned.\n";
        }
        else{
            cout << "Assigned Projects: ";
            for(auto projectId : assignedProjects){
                cout << projectId << " ";
            }
            cout << endl;
        }
    }
};

class Project {
public:
    int id;
    string name;
    string description;
    int assignedEmployeeId;
    string assignedEmployee;

    Project(int id, string name, string description, int assignedEmployeeId) {
        this->id = id;
        this->name = name;
        this->description = description;
        this->assignedEmployeeId = assignedEmployeeId; 
    }

    void displayProject() {
        cout << "ID: " << id << ", Name: " << name << ", Description: " << description << endl;
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
};

void Admin::addEmployee() {
    int id;
    string name, role;

    cout << "\nEnter Employee ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Employee Name: ";
    getline(cin, name);
    cout << "Enter Employee Role: ";
    getline(cin, role);

    employees.push_back(Employee(id, name, role));
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

    for(auto& employee : employees){
        if(employee.id == emp_id){

            employeeFound = true;

            cout << "\nEnter Project ID: ";
            cin >> id;
            cin.ignore(); 
            employee.assignProject(id);
            cout << "Enter Project Name: ";
            getline(cin, name);
            cout << "Enter Project Description: ";
            getline(cin, description);
            cout << "Enter the budget of the project: ";
            cin >> budget;

            projects.push_back(Project(id, name, description, emp_id));
            cout << "Project added successfully!\n";
        }
    }
    if (!employeeFound)
    {
        cout << "No employee found with that id";
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

void adminMenu() {
    Admin admin;
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
        cout << "\t\t|\t\t 6) EXIT                        |\n"; 
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
            cout << "Exiting admin menu...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (adminChoice != 6);
}



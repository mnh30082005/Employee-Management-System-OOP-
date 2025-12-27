
// Program Name : Employee Management System (OOP)
// Author       : Muhammad Naqi Ul Hassan
// Date         : December 25, 2024
//===========================================================
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
//================ BASE CLASS =================
class Employee {
protected:
    int id;
    string name;
    double baseSalary;
public:
    Employee(int i, string n, double s) {
        id = i;
        name = n;
        baseSalary = s;
    }
    virtual double calculateSalary() = 0;
    virtual void display() = 0;
};
//================ DERIVED CLASS: Developer =================
class Developer : public Employee {
public:
    Developer(int i, string n, double s) : Employee(i, n, s) {}

    double calculateSalary() {
        return baseSalary + 5000;
    }

    void display() {
        cout << id << "\t" << name << "\tDeveloper\t"
             << calculateSalary() << endl;
    }
};

//================ DERIVED CLASS: Manager =================
class Manager : public Employee {
public:
    Manager(int i, string n, double s) : Employee(i, n, s) {}

    double calculateSalary() {
        return baseSalary + 10000;
    }

    void display() {
        cout << id << "\t" << name << "\tManager\t\t"
             << calculateSalary() << endl;
    }
};

//================ COMPANY CLASS =================
class Company {
private:
    vector<Employee*> employees;

public:
    void addEmployee(Employee* e) {
        employees.push_back(e);

        ofstream file("employees.txt", ios::app);
        if (file.is_open()) {
            file << "ID: " << e << endl;
            file.close();
        }
    }

    void showEmployees() {
        cout << "\nID\tName\tRole\t\tSalary\n";
        cout << "------------------------------------\n";
        for (int i = 0; i < employees.size(); i++) {
            employees[i]->display();
        }
    }
};

//================ MAIN FUNCTION =================
int main() {
    Company company;
    int choice;

    do {
        cout << "\n===== Employee Management System =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Show Employees\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, role;
            string name;
            double salary;

            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Select Role (1-Developer, 2-Manager): ";
            cin >> role;

            cout << "Enter Base Salary: ";
            cin >> salary;

            if (role == 1) {
                company.addEmployee(new Developer(id, name, salary));
            } 
            else if (role == 2) {
                company.addEmployee(new Manager(id, name, salary));
            } 
            else {
                cout << "Invalid Role!\n";
            }
        }
        else if (choice == 2) {
            company.showEmployees();
        }

    } while (choice != 3);

    cout << "Program Ended.\n";
    return 0;
}


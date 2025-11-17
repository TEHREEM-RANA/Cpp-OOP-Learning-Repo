/*6. Extend the employee class of Exercise 4 to include a date class (see Exercise 5) and an
etype enum (see Exercise 6 in Chapter 4). An object of the date class should be used to
hold the date of first employment; that is, the date when the employee was hired. The
etype variable should hold the employee’s type: laborer, secretary, manager, and so on.
These two items will be private member data in the employee definition, just like the
employee number and salary. You’ll need to extend the getemploy() and putemploy()
functions to obtain this new information from the user and display it. These functions will
probably need switch statements to handle the etype variable. Write a main() program that
allows the user to enter data for three employee variables and then displays this data.*/
#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

class Date {
private:
    int day, month, year;
public:
    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void getDate() {
        char ch;
        cout << "Enter hire date (dd/mm/yyyy): ";
        cin >> day >> ch >> month >> ch >> year;
    }

    void showDate() {
        cout << day << "/" << month << "/" << year;
    }
};

class Employee {
private:
    int empNo;
    float compensation;
    Date hireDate;
    etype empType;
public:
    Employee() : empNo(0), compensation(0.0f), empType(laborer) {}
    Employee(int e, float c, Date d, etype t) : empNo(e), compensation(c), hireDate(d), empType(t) {}

    ~Employee() {
        cout << "Destructor called (Employee)\n";
    }

    void getEmployee() {
        cout << "Enter Employee Number: ";
        cin >> empNo;
        cout << "Enter Compensation: ";
        cin >> compensation;
        hireDate.getDate();

        char ch;
        cout << "Enter employee type (first letter only - l/s/m/a/e/r): ";
        cin >> ch;
        switch(ch) {
            case 'l': empType = laborer; break;
            case 's': empType = secretary; break;
            case 'm': empType = manager; break;
            case 'a': empType = accountant; break;
            case 'e': empType = executive; break;
            case 'r': empType = researcher; break;
            default: empType = laborer;
        }
    }

    void display() {
        cout << "Employee Number: " << empNo 
             << ", Compensation: $" << compensation 
             << ", Hire Date: ";
        hireDate.showDate();
        cout << ", Type: ";
        switch(empType) {
            case laborer: cout << "Laborer"; break;
            case secretary: cout << "Secretary"; break;
            case manager: cout << "Manager"; break;
            case accountant: cout << "Accountant"; break;
            case executive: cout << "Executive"; break;
            case researcher: cout << "Researcher"; break;
        }
        cout << endl;
    }
};

int main() {
    Employee e1, e2, e3;
    cout << "Enter details of 3 employees:\n";
    e1.getEmployee();
    e2.getEmployee();
    e3.getEmployee();

    cout << "\nEmployee Details:\n";
    e1.display();
    e2.display();
    e3.display();
    return 0;
}

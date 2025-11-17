/*4. Create an employee class, basing it on Exercise 4 of Chapter 4. The member data should
comprise an int for storing the employee number and a float for storing the employee’s
compensation. Member functions should allow the user to enter this data and display it.
Write a main() that allows the user to enter data for three employees and display it.*/
#include <iostream>
using namespace std;

class Employee {
private:
    int empNo;
    float compensation;
public:
    // Constructors
    Employee() : empNo(0), compensation(0.0f) {}
    Employee(int e, float c) : empNo(e), compensation(c) {}

    // Destructor
    ~Employee() {
        cout << "Destructor called (Employee)\n";
    }

    void getEmployee() {
        cout << "Enter Employee Number: ";
        cin >> empNo;
        cout << "Enter Compensation: ";
        cin >> compensation;
    }

    void display() {
        cout << "Employee Number: " << empNo 
             << ", Compensation: $" << compensation << endl;
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

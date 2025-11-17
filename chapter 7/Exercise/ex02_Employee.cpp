
// *2. Create a class called employee that contains a name (an object of class string) and an
// employee number (type long). Include a member function called getdata() to get data
// from the user for insertion into the object, and another function called putdata() to
// display the data. Assume the name has no embedded blanks.
// Write a main() program to exercise this class. It should create an array of type employee,
// and then invite the user to input data for up to 100 employees. Finally, it should print out
// the data for all the employees.
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    long employeeNumber;

public:
    // Constructor
    Employee(string n = "", long num = 0) {
        name = n;
        employeeNumber = num;
    }

    // Destructor
    ~Employee() {
        // Just for demonstration
        cout << "Destructor called for Employee: " << name << endl;
    }

    // Getter functions
    string getName() const { return name; }
    long getEmployeeNumber() const { return employeeNumber; }

    // Setter functions
    void setName(string n) { name = n; }
    void setEmployeeNumber(long num) { employeeNumber = num; }

    // Member functions
    void getdata() {
        cout << "Enter employee name (no spaces): ";
        cin >> name;
        cout << "Enter employee number: ";
        cin >> employeeNumber;
    }

    void putdata() const {
        cout << "Name: " << name << ", Employee Number: " << employeeNumber << endl;
    }
};

int main() {
    Employee employees[100];
    int count = 0;
    char choice;

    do {
        cout << "\nEnter data for employee " << count + 1 << ":\n";
        employees[count].getdata();
        count++;

        cout << "Add another employee? (y/n): ";
        cin >> choice;
    } while ((choice == 'y' || choice == 'Y') && count < 100);

    cout << "\nEmployee Details:\n";
    for (int i = 0; i < count; i++) {
        employees[i].putdata();
    }

    return 0;
}

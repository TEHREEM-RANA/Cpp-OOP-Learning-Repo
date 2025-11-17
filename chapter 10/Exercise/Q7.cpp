// Q7.cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    float salary;

public:
    // Default constructor
    Person() {
        name = "";
        salary = 0.0;
    }

    // Parameterized constructor
    Person(const string& n, float s) {
        name = n;
        salary = s;
    }

    // Destructor
    ~Person() {
        // Nothing special to delete since no dynamic memory used
    }

    // Set data
    void setData(const string& n, float s) {
        name = n;
        salary = s;
    }

    // Show data
    void printData() const {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }

    // Getter for salary
    float getSalary() const {
        return salary;
    }
};

// Function to sort Person pointers by salary using pointer notation
void salsort(Person* persPtr[], int n) {
    for (int j = 0; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            if ((*(persPtr + j))->getSalary() > (*(persPtr + k))->getSalary()) {
                // Swap the pointers
                Person* temp = *(persPtr + j);
                *(persPtr + j) = *(persPtr + k);
                *(persPtr + k) = temp;
            }
        }
    }
}

// Main function to test the program
int main() {
    const int SIZE = 4;
    Person p1("Alice", 5000.0), p2("Bob", 3000.0), p3("Charlie", 7000.0), p4("Diana", 6000.0);

    // Array of pointers to Person objects
    Person* persPtr[SIZE] = { &p1, &p2, &p3, &p4 };

    cout << "Before sorting by salary:\n";
    for (int i = 0; i < SIZE; i++) {
        persPtr[i]->printData();
    }

    // Sort pointers by salary
    salsort(persPtr, SIZE);

    cout << "\nAfter sorting by salary:\n";
    for (int i = 0; i < SIZE; i++) {
        persPtr[i]->printData();
    }

    return 0;
}

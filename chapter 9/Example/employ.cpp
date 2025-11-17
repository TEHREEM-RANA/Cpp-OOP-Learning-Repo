// employ.cpp
// models employee database using inheritance
#include <iostream>
using namespace std;

const int LEN = 80; // maximum length of names

//-------------------------------------------------------------
// Base class: employee
//-------------------------------------------------------------
class employee {
private:
    char name[LEN];      // employee name
    unsigned long number; // employee number
public:
    void getdata() {
        cout << "\nEnter last name: "; cin >> name;
        cout << "Enter number: "; cin >> number;
    }
    void putdata() const {
        cout << "\nName: " << name;
        cout << "\nNumber: " << number;
    }
};

//-------------------------------------------------------------
// Derived class: manager
//-------------------------------------------------------------
class manager : public employee {
private:
    char title[LEN];  // title like "Vice-President"
    double dues;      // golf club dues
public:
    void getdata() {
        employee::getdata(); // get name and number
        cout << "Enter title: "; cin >> title;
        cout << "Enter golf club dues: "; cin >> dues;
    }
    void putdata() const {
        employee::putdata(); // show name and number
        cout << "\nTitle: " << title;
        cout << "\nGolf club dues: " << dues;
    }
};

//-------------------------------------------------------------
// Derived class: scientist
//-------------------------------------------------------------
class scientist : public employee {
private:
    int pubs;  // number of publications
public:
    void getdata() {
        employee::getdata();
        cout << "Enter number of publications: "; cin >> pubs;
    }
    void putdata() const {
        employee::putdata();
        cout << "\nNumber of publications: " << pubs;
    }
};

//-------------------------------------------------------------
// Derived class: laborer
//-------------------------------------------------------------
class laborer : public employee {
    // no extra data, inherits everything from employee
};

//-------------------------------------------------------------
// Main function
//-------------------------------------------------------------
int main() {
    manager m1, m2;
    scientist s1;
    laborer l1;

    cout << "\nEnter data for manager 1";
    m1.getdata();
    cout << "\nEnter data for manager 2";
    m2.getdata();
    cout << "\nEnter data for scientist 1";
    s1.getdata();
    cout << "\nEnter data for laborer 1";
    l1.getdata();

    cout << "\n\nData on manager 1";
    m1.putdata();
    cout << "\n\nData on manager 2";
    m2.putdata();
    cout << "\n\nData on scientist 1";
    s1.putdata();
    cout << "\n\nData on laborer 1";
    l1.putdata();

    cout << endl;
    return 0;
}

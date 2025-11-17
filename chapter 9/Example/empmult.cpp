// empmult.cpp
// Demonstrates multiple inheritance (employee + student → manager/scientist)

#include <iostream>
using namespace std;

const int LEN = 80; // maximum length of names

//-------------------------------------------------------------
// Base class 1: student (educational background)
//-------------------------------------------------------------
class student
{
private:
    char school[LEN]; // name of school or university
    char degree[LEN]; // highest degree earned

public:
    void getedu()
    {
        cout << "Enter name of school or university: ";
        cin >> school;
        cout << "Enter highest degree earned\n";
        cout << "(Highschool, Bachelor’s, Master’s, PhD): ";
        cin >> degree;
    }

    void putedu() const
    {
        cout << "\nSchool or university: " << school;
        cout << "\nHighest degree earned: " << degree;
    }
};

//-------------------------------------------------------------
// Base class 2: employee
//-------------------------------------------------------------
class employee
{
private:
    char name[LEN];           // employee name
    unsigned long number;     // employee number

public:
    void getdata()
    {
        cout << "\nEnter last name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> number;
    }

    void putdata() const
    {
        cout << "\nName: " << name;
        cout << "\nNumber: " << number;
    }
};

//-------------------------------------------------------------
// Derived class: manager (inherits from employee and student)
//-------------------------------------------------------------
class manager : private employee, private student
{
private:
    char title[LEN];  // “vice-president” etc.
    double dues;      // golf club dues

public:
    void getdata()
    {
        employee::getdata();  // get name and number
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter golf club dues: ";
        cin >> dues;
        student::getedu();    // get education info
    }

    void putdata() const
    {
        employee::putdata();
        cout << "\nTitle: " << title;
        cout << "\nGolf club dues: " << dues;
        student::putedu();    // show education info
    }
};

//-------------------------------------------------------------
// Derived class: scientist (inherits from employee and student)
//-------------------------------------------------------------
class scientist : private employee, private student
{
private:
    int pubs; // number of publications

public:
    void getdata()
    {
        employee::getdata();  // get name and number
        cout << "Enter number of publications: ";
        cin >> pubs;
        student::getedu();    // get education info
    }

    void putdata() const
    {
        employee::putdata();
        cout << "\nNumber of publications: " << pubs;
        student::putedu();
    }
};

//-------------------------------------------------------------
// Derived class: laborer (inherits only from employee)
//-------------------------------------------------------------
class laborer : public employee
{
    // no extra members
};

//-------------------------------------------------------------
// main() function
//-------------------------------------------------------------
int main()
{
    manager m1;
    scientist s1, s2;
    laborer l1;

    cout << "\n--- Enter data for manager 1 ---";
    m1.getdata();

    cout << "\n--- Enter data for scientist 1 ---";
    s1.getdata();

    cout << "\n--- Enter data for scientist 2 ---";
    s2.getdata();

    cout << "\n--- Enter data for laborer 1 ---";
    l1.getdata();

    cout << "\n\n--- Data on manager 1 ---";
    m1.putdata();

    cout << "\n\n--- Data on scientist 1 ---";
    s1.putdata();

    cout << "\n\n--- Data on scientist 2 ---";
    s2.putdata();

    cout << "\n\n--- Data on laborer 1 ---";
    l1.putdata();

    cout << endl;
    return 0;
}

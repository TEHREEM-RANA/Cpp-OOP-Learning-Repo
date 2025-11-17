// employ2.cpp
// Demonstrates multiple levels of inheritance (employee → laborer → foreman)

#include <iostream>
using namespace std;

const int LEN = 80; // maximum length of names

//-------------------------------------------------------------
// Base class: employee
//-------------------------------------------------------------
class employee
{
private:
    char name[LEN];          // employee name
    unsigned long number;    // employee number

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
// Derived class: manager
//-------------------------------------------------------------
class manager : public employee
{
private:
    char title[LEN];  // "vice-president" etc.
    double dues;      // golf club dues

public:
    void getdata()
    {
        employee::getdata();
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter golf club dues: ";
        cin >> dues;
    }

    void putdata() const
    {
        employee::putdata();
        cout << "\nTitle: " << title;
        cout << "\nGolf club dues: " << dues;
    }
};

//-------------------------------------------------------------
// Derived class: scientist
//-------------------------------------------------------------
class scientist : public employee
{
private:
    int pubs; // number of publications

public:
    void getdata()
    {
        employee::getdata();
        cout << "Enter number of publications: ";
        cin >> pubs;
    }

    void putdata() const
    {
        employee::putdata();
        cout << "\nNumber of publications: " << pubs;
    }
};

//-------------------------------------------------------------
// Derived class: laborer
//-------------------------------------------------------------
class laborer : public employee
{
    // inherits everything from employee
};

//-------------------------------------------------------------
// Derived class: foreman (derived from laborer)
//-------------------------------------------------------------
class foreman : public laborer
{
private:
    float quotas; // percent of quotas met successfully

public:
    void getdata()
    {
        laborer::getdata();
        cout << "Enter quotas (in percentage): ";
        cin >> quotas;
    }

    void putdata() const
    {
        laborer::putdata();
        cout << "\nQuotas: " << quotas;
    }
};

//-------------------------------------------------------------
// main() function
//-------------------------------------------------------------
int main()
{
    laborer l1;
    foreman f1;

    cout << "\n--- Enter data for laborer 1 ---";
    l1.getdata();

    cout << "\n--- Enter data for foreman 1 ---";
    f1.getdata();

    cout << "\n--- Data on laborer 1 ---";
    l1.putdata();

    cout << "\n--- Data on foreman 1 ---";
    f1.putdata();

    cout << endl;
    return 0;
}

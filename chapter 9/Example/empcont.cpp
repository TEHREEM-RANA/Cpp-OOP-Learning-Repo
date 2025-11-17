// empcont.cpp
// containership (aggregation) with employees and degrees

#include <iostream>
#include <string>
using namespace std;

//--------------------------------------------------------------
// Class: student (educational background)
//--------------------------------------------------------------
class student
{
private:
    string school;  // name of school or university
    string degree;  // highest degree earned
public:
    void getedu()
    {
        cout << "Enter name of school or university: ";
        cin >> school;
        cout << "Enter highest degree earned (Highschool, Bachelor, Master, PhD): ";
        cin >> degree;
    }
    void putedu() const
    {
        cout << "\nSchool or university: " << school;
        cout << "\nHighest degree earned: " << degree;
    }
};

//--------------------------------------------------------------
// Class: employee (basic employee info)
//--------------------------------------------------------------
class employee
{
private:
    string name;        // employee name
    unsigned long number; // employee number
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

//--------------------------------------------------------------
// Class: manager (has-a employee and student)
//--------------------------------------------------------------
class manager
{
private:
    string title;  // job title
    double dues;   // golf club dues
    employee emp;  // object of employee
    student stu;   // object of student
public:
    void getdata()
    {
        emp.getdata();
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter golf club dues: ";
        cin >> dues;
        stu.getedu();
    }
    void putdata() const
    {
        emp.putdata();
        cout << "\nTitle: " << title;
        cout << "\nGolf club dues: " << dues;
        stu.putedu();
    }
};

//--------------------------------------------------------------
// Class: scientist (has-a employee and student)
//--------------------------------------------------------------
class scientist
{
private:
    int pubs;      // number of publications
    employee emp;  // object of employee
    student stu;   // object of student
public:
    void getdata()
    {
        emp.getdata();
        cout << "Enter number of publications: ";
        cin >> pubs;
        stu.getedu();
    }
    void putdata() const
    {
        emp.putdata();
        cout << "\nNumber of publications: " << pubs;
        stu.putedu();
    }
};

//--------------------------------------------------------------
// Class: laborer (has-a employee)
//--------------------------------------------------------------
class laborer
{
private:
    employee emp; // object of employee
public:
    void getdata() { emp.getdata(); }
    void putdata() const { emp.putdata(); }
};

//--------------------------------------------------------------
// main()
//--------------------------------------------------------------
int main()
{
    manager m1;
    scientist s1, s2;
    laborer l1;

    cout << "\nEnter data for manager 1\n";
    m1.getdata();

    cout << "\nEnter data for scientist 1\n";
    s1.getdata();

    cout << "\nEnter data for scientist 2\n";
    s2.getdata();

    cout << "\nEnter data for laborer 1\n";
    l1.getdata();

    cout << "\n\nData on manager 1";
    m1.putdata();

    cout << "\n\nData on scientist 1";
    s1.putdata();

    cout << "\n\nData on scientist 2";
    s2.putdata();

    cout << "\n\nData on laborer 1";
    l1.putdata();

    cout << endl;
    return 0;
}

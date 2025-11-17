// Q5.cpp
#include <iostream>
#include <string>
using namespace std;

// ---------- Base Class: employee ----------
class employee {
private:
    string name;
    long number;

public:
    // Default Constructor
    employee() : name(""), number(0) {}

    // Parameterized Constructor
    employee(string n, long num) : name(n), number(num) {}

    // Destructor
    virtual ~employee() {}

    // Input Function
    virtual void getdata() {
        cout << "Enter employee name: ";
        getline(cin, name);
        cout << "Enter employee number: ";
        cin >> number;
        cin.ignore();
    }

    // Output Function
    virtual void putdata() const {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};

// ---------- Derived Class: employee2 ----------
class employee2 : public employee {
public:
    enum period { hourly, weekly, monthly };

private:
    double compensation;
    period payType;

public:
    // Default Constructor
    employee2() : employee(), compensation(0.0), payType(monthly) {}

    // Parameterized Constructor
    employee2(string n, long num, double comp, period p)
        : employee(n, num), compensation(comp), payType(p) {}

    // Destructor
    ~employee2() {}

    // Input Function
    void getdata() {
        employee::getdata();
        cout << "Enter compensation: $";
        cin >> compensation;

        char ch;
        cout << "Enter pay period (h = hourly, w = weekly, m = monthly): ";
        cin >> ch;
        cin.ignore();

        if (ch == 'h' || ch == 'H')
            payType = hourly;
        else if (ch == 'w' || ch == 'W')
            payType = weekly;
        else
            payType = monthly;
    }

    // Output Function
    void putdata() const {
        employee::putdata();
        cout << "Compensation: $" << compensation << endl;
        cout << "Pay Period: ";
        switch (payType) {
            case hourly:  cout << "Hourly";  break;
            case weekly:  cout << "Weekly";  break;
            case monthly: cout << "Monthly"; break;
        }
        cout << endl;
    }
};

// ---------- Derived Class: manager ----------
class manager : public employee2 {
private:
    string title;   // e.g. "Project Manager"
    double dues;    // golf club dues or similar

public:
    // Default Constructor
    manager() : employee2(), title(""), dues(0.0) {}

    // Destructor
    ~manager() {}

    void getdata() {
        employee2::getdata();
        cout << "Enter manager title: ";
        getline(cin, title);
        cout << "Enter golf club dues: $";
        cin >> dues;
        cin.ignore();
    }

    void putdata() const {
        cout << "\n--- Manager Information ---\n";
        employee2::putdata();
        cout << "Title: " << title << endl;
        cout << "Golf Club Dues: $" << dues << endl;
    }
};

// ---------- Derived Class: scientist ----------
class scientist : public employee2 {
private:
    int pubs; // number of publications

public:
    scientist() : employee2(), pubs(0) {}

    ~scientist() {}

    void getdata() {
        employee2::getdata();
        cout << "Enter number of publications: ";
        cin >> pubs;
        cin.ignore();
    }

    void putdata() const {
        cout << "\n--- Scientist Information ---\n";
        employee2::putdata();
        cout << "Publications: " << pubs << endl;
    }
};

// ---------- Derived Class: laborer ----------
class laborer : public employee2 {
public:
    laborer() : employee2() {}
    ~laborer() {}

    void getdata() {
        employee2::getdata();
    }

    void putdata() const {
        cout << "\n--- Laborer Information ---\n";
        employee2::putdata();
    }
};

// ---------- Main Function ----------
int main() {
    manager m1;
    scientist s1;
    laborer l1;

    cout << "Enter data for manager:\n";
    m1.getdata();

    cout << "\nEnter data for scientist:\n";
    s1.getdata();

    cout << "\nEnter data for laborer:\n";
    l1.getdata();

    cout << "\n=========== OUTPUT ===========\n";
    m1.putdata();
    s1.putdata();
    l1.putdata();

    return 0;
}

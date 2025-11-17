// Q10.cpp
#include <iostream>
#include <string>
using namespace std;

// ---------- Base Class: employee ----------
class employee {
protected:
    string name;
    int empID;

public:
    // Default Constructor
    employee() : name(""), empID(0) {}

    // Parameterized Constructor
    employee(string n, int id) : name(n), empID(id) {}

    // Destructor
    virtual ~employee() {}

    // Input
    virtual void getdata() {
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter employee ID: ";
        cin >> empID;
    }

    // Display
    virtual void putdata() const {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << empID << endl;
    }
};

// ---------- Derived Class: manager ----------
class manager : public employee {
protected:
    string title;
    double clubDues;

public:
    // Default Constructor
    manager() : employee(), title(""), clubDues(0.0) {}

    // Parameterized Constructor
    manager(string n, int id, string t, double dues)
        : employee(n, id), title(t), clubDues(dues) {}

    // Destructor
    ~manager() {}

    // Input
    void getdata() override {
        employee::getdata();
        cout << "Enter title (e.g., Sales Manager): ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter club dues: ";
        cin >> clubDues;
    }

    // Display
    void putdata() const override {
        employee::putdata();
        cout << "Title: " << title << endl;
        cout << "Club Dues: $" << clubDues << endl;
    }
};

// ---------- Derived Class: executive ----------
class executive : public manager {
private:
    double yearlyBonus;
    int stockShares;

public:
    // Default Constructor
    executive() : manager(), yearlyBonus(0.0), stockShares(0) {}

    // Parameterized Constructor
    executive(string n, int id, string t, double dues, double bonus, int shares)
        : manager(n, id, t, dues), yearlyBonus(bonus), stockShares(shares) {}

    // Destructor
    ~executive() {}

    // Input
    void getdata() override {
        manager::getdata();
        cout << "Enter yearly bonus: ";
        cin >> yearlyBonus;
        cout << "Enter number of stock shares: ";
        cin >> stockShares;
    }

    // Display
    void putdata() const override {
        manager::putdata();
        cout << "Yearly Bonus: $" << yearlyBonus << endl;
        cout << "Stock Shares: " << stockShares << endl;
    }
};

// ---------- Main Function ----------
int main() {
    executive e1;

    cout << "\n--- Enter Executive Details ---" << endl;
    e1.getdata();

    cout << "\n=============================" << endl;
    cout << "--- Executive Information ---" << endl;
    e1.putdata();

    return 0;
}

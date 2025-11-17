// 12. Create a class called bMoney. It should store money amounts as long doubles. Use the
// function mstold() to convert a money string entered as input into a long double, and
// the function ldtoms() to convert the long double to a money string for display. (See
// Exercises 6 and 10.) You can call the input and output member functions getmoney()
// and putmoney(). Write another member function that adds two bMoney amounts; you can
// call it madd(). Adding bMoney objects is easy: Just add the long double member data
// amounts in two bMoney objects. Write a main() program that repeatedly asks the user to
// enter two money strings, and then displays the sum as a money string. Here’s how the
// class specifier might look:
// class bMoney
// {
// private:
// long double money;
// public:
// bMoney();
// bMoney(char s[]);
// void madd(bMoney m1, bMoney m2);
// void getmoney();
// void putmoney();
// };


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>
using namespace std;

class bMoney {
private:
    long double money; // store money value as long double

    // helper: convert money string to long double
    long double mstold(string s) {
        // remove $, commas, and spaces
        string clean = "";
        for (char ch : s)
            if (isdigit(ch) || ch == '.' || ch == '-')
                clean += ch;

        long double val = 0.0;
        stringstream ss(clean);
        ss >> val;
        return val;
    }

    // helper: convert long double to money string
    string ldtoms(long double amount) const {
        stringstream ss;
        ss << fixed << setprecision(2) << amount;
        string str = ss.str();

        // insert commas
        int pos = str.find('.');
        for (int i = pos - 3; i > 0; i -= 3)
            str.insert(i, ",");

        str = "$" + str;
        return str;
    }

public:
    // Default constructor
    bMoney() {
        money = 0.0;
    }

    // Parameterized constructor (from string)
    bMoney(string s) {
        money = mstold(s);
    }

    // Destructor
    ~bMoney() {
        cout << "bMoney object destroyed.\n";
    }

    // Getter
    long double getMoneyValue() const { return money; }

    // Setter
    void setMoneyValue(long double val) { money = val; }

    // Input function
    void getmoney() {
        string s;
        cout << "Enter money amount (e.g. $1,234.56): ";
        cin >> s;
        money = mstold(s);
    }

    // Output function
    void putmoney() const {
        cout << ldtoms(money);
    }

    // Add two bMoney objects
    void madd(bMoney m1, bMoney m2) {
        money = m1.money + m2.money;
    }
};

int main() {
    bMoney m1, m2, m3;
    char choice;

    do {
        cout << "\nEnter first money amount:\n";
        m1.getmoney();

        cout << "Enter second money amount:\n";
        m2.getmoney();

        m3.madd(m1, m2);

        cout << "Sum = ";
        m3.putmoney();
        cout << endl;

        cout << "\nDo you want to add more amounts? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

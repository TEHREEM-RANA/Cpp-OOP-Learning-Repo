// Q5.cpp
#include <iostream>
#include <string>
using namespace std;

class bMoney {
private:
    long double amount; // store money as a number
public:
    // Constructors
    bMoney() : amount(0.0) {}
    bMoney(long double a) : amount(a) {}

    // Getter and Setter
    void setAmount(long double a) { amount = a; }
    long double getAmount() { return amount; }

    // Friend functions for arithmetic with numbers
    friend bMoney operator*(long double num, const bMoney& m);
    friend bMoney operator/(long double num, const bMoney& m);

    // Display
    void show() {
        cout << "$" << amount << endl;
    }
};

// Multiply number * money
bMoney operator*(long double num, const bMoney& m) {
    return bMoney(num * m.amount);
}

// Divide number / money
bMoney operator/(long double num, const bMoney& m) {
    if (m.amount == 0) {
        cout << "Error: Division by zero!" << endl;
        return bMoney(0);
    }
    return bMoney(num / m.amount);
}

int main() {
    bMoney m1, m2;
    long double num;

    cout << "Enter first money amount: $";
    cin >> num;
    m1.setAmount(num);

    cout << "Enter second money amount: $";
    cin >> num;
    m2.setAmount(num);

    cout << "Enter a number for operations: ";
    cin >> num;

    cout << "\nOriginal Money Values:\n";
    cout << "m1: "; m1.show();
    cout << "m2: "; m2.show();

    cout << "\nOperations:\n";
    bMoney result;

    result = num * m1;
    cout << num << " * m1 = "; result.show();

    result = num / m2;
    cout << num << " / m2 = "; result.show();

    return 0;
}

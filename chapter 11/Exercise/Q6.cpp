// Q6.cpp
#include <iostream>
#include <cmath>    // for std::round()
using namespace std;

class bMoney {
private:
    long double amount;
public:
    // Constructors
    bMoney() : amount(0.0) {}
    bMoney(long double a) : amount(a) {}

    // Set and get functions
    void setAmount(long double a) { amount = a; }
    long double getAmount() const { return amount; }  // const added

    // Display function
    void show() { cout << "$" << amount << endl; }
};

// Rounded function using std::round()
bMoney roundMoney(const bMoney& m) {
    long double roundedValue = std::round(m.getAmount());
    return bMoney(roundedValue);
}

int main() {
    bMoney m1, m2;
    long double input;

    cout << "Enter money amount to round: $";
    cin >> input;
    m1.setAmount(input);

    cout << "Original amount: ";
    m1.show();

    m2 = roundMoney(m1);
    cout << "Rounded amount: ";
    m2.show();

    cout << "\nTest multiple values from 0.48 to 0.52:\n";
    for (long double val = 0.48; val <= 0.52; val += 0.01) {
        bMoney temp(val);
        cout << "Original: $" << val << " -> Rounded: ";
        roundMoney(temp).show();
    }

    // Test negative values
    cout << "\nTest negative values from -2.6 to -2.4:\n";
    for (long double val = -2.6; val <= -2.4; val += 0.1) {
        bMoney temp(val);
        cout << "Original: $" << val << " -> Rounded: ";
        roundMoney(temp).show();
    }

    return 0;
}

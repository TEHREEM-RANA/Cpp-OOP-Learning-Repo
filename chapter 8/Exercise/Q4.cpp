// Q4.cpp
// Program: Int class with arithmetic operator overloading and overflow detection
#include <iostream>
#include <limits>
#include <cstdlib> // for exit()
using namespace std;

class Int {
private:
    int value;

public:
    // Constructors
    Int() : value(0) {}
    Int(int v) : value(v) {}

    // Destructor
    ~Int() {}

    // Getter and Setter
    void setValue(int v) { value = v; }
    int getValue() const { return value; }

    // Display function
    void display() const {
        cout << value;
    }

    // Check for overflow
    void checkOverflow(long double result) const {
        if (result > numeric_limits<int>::max() || result < numeric_limits<int>::min()) {
            cout << "\n⚠️ Arithmetic Overflow! Program terminated.\n";
            exit(1);
        }
    }

    // Overloaded +
    Int operator+(const Int& other) const {
        long double result = (long double)value + (long double)other.value;
        checkOverflow(result);
        return Int((int)result);
    }

    // Overloaded -
    Int operator-(const Int& other) const {
        long double result = (long double)value - (long double)other.value;
        checkOverflow(result);
        return Int((int)result);
    }

    // Overloaded *
    Int operator*(const Int& other) const {
        long double result = (long double)value * (long double)other.value;
        checkOverflow(result);
        return Int((int)result);
    }

    // Overloaded /
    Int operator/(const Int& other) const {
        if (other.value == 0) {
            cout << "\n⚠️ Division by zero! Program terminated.\n";
            exit(1);
        }
        long double result = (long double)value / (long double)other.value;
        checkOverflow(result);
        return Int((int)result);
    }
};

int main() {
    Int n1, n2, result;
    int v1, v2;
    char op;

    cout << "Enter first integer: ";
    cin >> v1;
    n1.setValue(v1);

    cout << "Enter second integer: ";
    cin >> v2;
    n2.setValue(v2);

    cout << "Enter operation (+, -, *, /): ";
    cin >> op;

    switch (op) {
        case '+': result = n1 + n2; break;
        case '-': result = n1 - n2; break;
        case '*': result = n1 * n2; break;
        case '/': result = n1 / n2; break;
        default:
            cout << "Invalid operator!" << endl;
            return 0;
    }

    cout << "\nResult = ";
    result.display();
    cout << endl;

    return 0;
}

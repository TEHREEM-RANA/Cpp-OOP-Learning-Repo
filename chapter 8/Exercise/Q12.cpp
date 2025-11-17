// Q12.cpp
// Program: Fraction class with overloaded arithmetic and comparison operators
#include <iostream>
#include <cstdlib>  // for abs()
using namespace std;

class Fraction {
private:
    int num;  // numerator
    int den;  // denominator

public:
    // Default constructor
    Fraction() : num(0), den(1) {}

    // Parameterized constructor
    Fraction(int n, int d) {
        setFraction(n, d);
    }

    // Copy constructor
    Fraction(const Fraction& f) {
        num = f.num;
        den = f.den;
    }

    // Destructor
    ~Fraction() {}

    // Setters
    void setFraction(int n, int d) {
        if (d == 0) {
            cout << "Error: Denominator cannot be zero. Setting to 1.\n";
            den = 1;
        } else {
            num = n;
            den = d;
        }
        lowterms();
    }

    // Getters
    void getFraction() {
        cout << "Enter numerator: ";
        cin >> num;
        cout << "Enter denominator: ";
        cin >> den;
        if (den == 0) {
            cout << "Error: Denominator cannot be zero. Setting to 1.\n";
            den = 1;
        }
        lowterms();
    }

    void showFraction() const {
        cout << num << "/" << den;
    }

    // Function to reduce fraction to lowest terms
    void lowterms() {
        long tnum = labs(num);
        long tden = labs(den);
        long temp, gcd;

        if (tden == 0) {
            cout << "Illegal fraction: division by 0\n";
            exit(1);
        } else if (tnum == 0) {
            num = 0;
            den = 1;
            return;
        }

        while (tnum != 0) {
            if (tnum < tden) {
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum = tnum - tden;
        }
        gcd = tden;
        num = num / gcd;
        den = den / gcd;
    }

    // Arithmetic Operators
    Fraction operator+(Fraction f2) const {
        return Fraction(num * f2.den + den * f2.num, den * f2.den);
    }

    Fraction operator-(Fraction f2) const {
        return Fraction(num * f2.den - den * f2.num, den * f2.den);
    }

    Fraction operator*(Fraction f2) const {
        return Fraction(num * f2.num, den * f2.den);
    }

    Fraction operator/(Fraction f2) const {
        return Fraction(num * f2.den, den * f2.num);
    }

    // Comparison Operators
    bool operator==(Fraction f2) const {
        return (num == f2.num && den == f2.den);
    }

    bool operator!=(Fraction f2) const {
        return !(*this == f2);
    }
};

// Main function
int main() {
    Fraction f1, f2, result;
    char op;

    cout << "Enter first fraction:\n";
    f1.getFraction();

    cout << "Enter second fraction:\n";
    f2.getFraction();

    while (!(f1 == Fraction(0, 1) && f2 == Fraction(0, 1))) {
        cout << "\nEnter operator (+, -, *, /): ";
        cin >> op;

        switch (op) {
            case '+': result = f1 + f2; break;
            case '-': result = f1 - f2; break;
            case '*': result = f1 * f2; break;
            case '/': result = f1 / f2; break;
            default:
                cout << "Invalid operator!";
                continue;
        }

        cout << "\nResult = ";
        result.showFraction();
        cout << endl;

        cout << "\nEnter next fractions (0/1 0/1 to quit):\n";
        cout << "First fraction:\n";
        f1.getFraction();
        cout << "Second fraction:\n";
        f2.getFraction();
    }

    cout << "\nProgram terminated.";
    return 0;
}

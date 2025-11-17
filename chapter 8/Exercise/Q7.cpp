// Q7.cpp
// Program: Fraction class with overloaded +, -, *, /, ==, != operators
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    // Helper function to simplify fraction using GCD
    int gcd(int a, int b) const {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    // Simplify fraction
    void simplify() {
        if (denominator < 0) { // handle negative denominator
            numerator = -numerator;
            denominator = -denominator;
        }
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
    }

public:
    // Constructors
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int n, int d) {
        if (d == 0) {
            cout << "❌ Error: Denominator cannot be zero!\n";
            numerator = 0;
            denominator = 1;
        } else {
            numerator = n;
            denominator = d;
            simplify();
        }
    }

    // Input and display
    void getFraction() {
        cout << "Enter numerator and denominator: ";
        cin >> numerator >> denominator;
        if (denominator == 0) {
            cout << "❌ Error: Denominator cannot be zero. Setting to 1.\n";
            denominator = 1;
        }
        simplify();
    }

    void showFraction() const {
        cout << numerator << "/" << denominator;
    }

    // Overloaded + operator
    Fraction operator+(const Fraction& f) const {
        int n = numerator * f.denominator + f.numerator * denominator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    // Overloaded - operator
    Fraction operator-(const Fraction& f) const {
        int n = numerator * f.denominator - f.numerator * denominator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    // Overloaded * operator
    Fraction operator*(const Fraction& f) const {
        int n = numerator * f.numerator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    // Overloaded / operator
    Fraction operator/(const Fraction& f) const {
        if (f.numerator == 0) {
            cout << "❌ Division by zero fraction not allowed!\n";
            return Fraction(0, 1);
        }
        int n = numerator * f.denominator;
        int d = denominator * f.numerator;
        return Fraction(n, d);
    }

    // Overloaded == operator
    bool operator==(const Fraction& f) const {
        return (numerator == f.numerator && denominator == f.denominator);
    }

    // Overloaded != operator
    bool operator!=(const Fraction& f) const {
        return !(*this == f);
    }
};

int main() {
    Fraction f1, f2, result;
    cout << "Enter first fraction:\n";
    f1.getFraction();

    cout << "Enter second fraction:\n";
    f2.getFraction();

    cout << "\n--- Results ---\n";
    cout << "Addition: ";
    result = f1 + f2;
    result.showFraction();

    cout << "\nSubtraction: ";
    result = f1 - f2;
    result.showFraction();

    cout << "\nMultiplication: ";
    result = f1 * f2;
    result.showFraction();

    cout << "\nDivision: ";
    result = f1 / f2;
    result.showFraction();

    cout << "\n\nComparison:\n";
    cout << "f1 == f2 : " << (f1 == f2 ? "True" : "False") << endl;
    cout << "f1 != f2 : " << (f1 != f2 ? "True" : "False") << endl;

    return 0;
}

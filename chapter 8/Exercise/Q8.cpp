// Q8.cpp
// Program: Complex number class with overloaded +, -, *, == operators
#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Constructors
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    // Destructor
    ~Complex() {
        // Just to show when object is destroyed
        // cout << "Destructor called for Complex(" << real << ", " << imag << ")\n";
    }

    // Getters
    float getReal() const { return real; }
    float getImag() const { return imag; }

    // Setters
    void setReal(float r) { real = r; }
    void setImag(float i) { imag = i; }

    // Input function
    void getComplex() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    // Display function
    void showComplex() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }

    // Overloaded + operator
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overloaded - operator
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Overloaded * operator
    Complex operator*(const Complex& c) const {
        float r = real * c.real - imag * c.imag;
        float i = real * c.imag + imag * c.real;
        return Complex(r, i);
    }

    // Overloaded == operator
    bool operator==(const Complex& c) const {
        return (real == c.real && imag == c.imag);
    }
};

int main() {
    Complex c1, c2, result;

    cout << "Enter first complex number:\n";
    c1.getComplex();

    cout << "\nEnter second complex number:\n";
    c2.getComplex();

    cout << "\n--- Results ---\n";

    cout << "Addition: ";
    result = c1 + c2;
    result.showComplex();

    cout << "\nSubtraction: ";
    result = c1 - c2;
    result.showComplex();

    cout << "\nMultiplication: ";
    result = c1 * c2;
    result.showComplex();

    cout << "\n\nComparison:\n";
    cout << "c1 == c2 : " << (c1 == c2 ? "True" : "False") << endl;

    return 0;
}

// 5. Start with the fraction class from Exercises 11 and 12 in Chapter 6. Write a main()
// program that obtains an arbitrary number of fractions from the user, stores them in an
// array of type fraction, averages them, and displays the result.
#include <iostream>
using namespace std;

class Fraction {
private:
    int num;  // numerator
    int den;  // denominator

public:
    // Constructor
    Fraction(int n = 0, int d = 1) {
        if (d == 0) d = 1; // avoid division by zero
        num = n;
        den = d;
    }

    // Destructor
    ~Fraction() {
        cout << "Destructor called for fraction " << num << "/" << den << endl;
    }

    // Getters
    int getNum() const { return num; }
    int getDen() const { return den; }

    // Setters
    void setNum(int n) { num = n; }
    void setDen(int d) { if (d != 0) den = d; }

    // Input data
    void getFraction() {
        cout << "Enter numerator: ";
        cin >> num;
        cout << "Enter denominator: ";
        cin >> den;
        if (den == 0) {
            cout << "Denominator cannot be zero. Reset to 1.\n";
            den = 1;
        }
    }

    // Display fraction
    void display() const {
        cout << num << "/" << den;
    }

    // Add two fractions
    Fraction add(const Fraction& f2) const {
        int n = num * f2.den + den * f2.num;
        int d = den * f2.den;
        return Fraction(n, d);
    }

    // Divide fraction by integer
    Fraction divideByInt(int n) const {
        return Fraction(num, den * n);
    }

    // Simplify fraction
    void simplify() {
        int a = num, b = den;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        num /= a;
        den /= a;
    }
};

int main() {
    Fraction fractions[100], total(0, 1), average;
    int count = 0;
    char choice;

    do {
        cout << "\nEnter fraction #" << count + 1 << endl;
        fractions[count].getFraction();
        total = total.add(fractions[count]);
        count++;

        cout << "Add another fraction? (y/n): ";
        cin >> choice;
    } while ((choice == 'y' || choice == 'Y') && count < 100);

    average = total.divideByInt(count);
    average.simplify();

    cout << "\nAverage of fractions = ";
    average.display();
    cout << endl;

    return 0;
}

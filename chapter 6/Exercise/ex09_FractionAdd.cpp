/*Transform the fraction structure from Exercise 8 in Chapter 4 into a fraction class.
Member data is the fraction’s numerator and denominator. Member functions should
accept input from the user in the form 3/5, and output the fraction’s value in the same
format. Another member function should add two fraction values. Write a main() program
that allows the user to repeatedly input two fractions and then displays their sum. After
each operation, ask whether the user wants to continue.*/
#include <iostream>
using namespace std;

class Fraction {
private:
    int num, den;
public:
    Fraction() : num(0), den(1) {}
    Fraction(int n, int d) : num(n), den(d) {}

    ~Fraction() {
        cout << "Destructor called (Fraction)\n";
    }

    void getFraction() {
        char ch;
        cout << "Enter fraction (a/b): ";
        cin >> num >> ch >> den;
    }

    void display() {
        cout << num << "/" << den;
    }

    Fraction add(Fraction f2) {
        Fraction temp;
        temp.num = num * f2.den + f2.num * den;
        temp.den = den * f2.den;
        return temp;
    }
};

int main() {
    char choice;
    do {
        Fraction f1, f2, result;
        cout << "Enter first fraction:\n";
        f1.getFraction();
        cout << "Enter second fraction:\n";
        f2.getFraction();
        result = f1.add(f2);
        cout << "Sum = ";
        result.display();
        cout << endl;
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
    } while(choice == 'y');
    return 0;
}

/*12. Note that one advantage of the OOP approach is that an entire class can be used, without
modification, in a different program. Use the fraction class from Exercise 11 in a program that generates a multiplication table for fractions. Let the user input a denominator,
and then generate all combinations of two such fractions that are between 0 and 1, and
multiply them together. Here’s an example of the output if the denominator is 6:
1/6 1/3 1/2 2/3 5/6
-----------------------------------------
1/6 1/36 1/18 1/12 1/9 5/36
1/3 1/18 1/9 1/6 2/9 5/18
1/2 1/12 1/6 1/4 1/3 5/12
2/3 1/9 2/9 1/3 4/9 5/9
5/6 5/36 5/18 5/12 5/9 25/36*/
#include <iostream>
using namespace std;

class Fraction {
private:
    int num, den;

    int gcd(int a, int b) {
        while(b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

public:
    Fraction() : num(0), den(1) {}
    Fraction(int n, int d) : num(n), den(d) { lowterms(); }

    void lowterms() {
        if(num == 0) { den = 1; return; }
        int g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;
    }

    void display() {
        cout << num << "/" << den;
    }

    Fraction mul(Fraction f2) {
        Fraction temp(num * f2.num, den * f2.den);
        return temp;
    }
};

int main() {
    int d;
    cout << "Enter denominator for fractions: ";
    cin >> d;

    // Header row
    for(int i = 1; i < d; i++) {
        Fraction f(i, d);
        f.display();
        cout << "\t";
    }
    cout << endl;

    cout << "---------------------------------------------\n";

    // Table
    for(int i = 1; i < d; i++) {
        Fraction f1(i, d);
        f1.display();
        cout << "\t";
        for(int j = 1; j < d; j++) {
            Fraction f2(j, d);
            Fraction result = f1.mul(f2);
            result.display();
            cout << "\t";
        }
        cout << endl;
    }

    return 0;
}

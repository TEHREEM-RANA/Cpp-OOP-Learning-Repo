/*11. Modify the four-function fraction calculator of Exercise 12 in Chapter 5 to use a
fraction class rather than a structure. There should be member functions for input and
output, as well as for the four arithmetical operations. While you’re at it, you might as
well install the capability to reduce fractions to lowest terms. Here’s a member function
that will reduce the fraction object of which it is a member to lowest terms. It finds the
greatest common divisor (gcd) of the fraction’s numerator and denominator, and uses this
gcd to divide both numbers.
void fraction::lowterms() // change ourself to lowest terms
{
long tnum, tden, temp, gcd;
tnum = labs(num); // use non-negative copies
tden = labs(den); // (needs cmath)
if(tden==0 ) // check for n/0
{ cout << “Illegal fraction: division by 0”; exit(1); }
else if( tnum==0 ) // check for 0/n
{ num=0; den = 1; return; }
// this ‘while’ loop finds the gcd of tnum and tden
while(tnum != 0)
{
if(tnum < tden) // ensure numerator larger
{ temp=tnum; tnum=tden; tden=temp; } // swap them
tnum = tnum - tden; // subtract them
}
gcd = tden; // this is greatest common divisor
num = num / gcd; // divide both num and den by gcd
den = den / gcd; // to reduce frac to lowest terms
}
You can call this function at the end of each arithmetic function, or just before you perform output. You’ll also need the usual member functions: four arithmetic operations,
input, and display. You may find a two-argument constructor useful.*/
#include <iostream>
#include <cstdlib>
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

    ~Fraction() {
        cout << "Destructor called (Fraction)\n";
    }

    void getFraction() {
        char ch;
        cout << "Enter fraction (a/b): ";
        cin >> num >> ch >> den;
        lowterms();
    }

    void display() {
        cout << num << "/" << den;
    }

    void lowterms() {
        if(den == 0) {
            cout << "Illegal fraction: division by 0\n";
            exit(1);
        }
        if(num == 0) {
            den = 1;
            return;
        }
        int g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;
    }

    Fraction add(Fraction f2) {
        Fraction temp(num * f2.den + f2.num * den, den * f2.den);
        return temp;
    }

    Fraction sub(Fraction f2) {
        Fraction temp(num * f2.den - f2.num * den, den * f2.den);
        return temp;
    }

    Fraction mul(Fraction f2) {
        Fraction temp(num * f2.num, den * f2.den);
        return temp;
    }

    Fraction div(Fraction f2) {
        Fraction temp(num * f2.den, den * f2.num);
        return temp;
    }
};

int main() {
    Fraction f1, f2, result;
    char op, choice;
    do {
        cout << "Enter first fraction:\n";
        f1.getFraction();
        cout << "Enter operation (+,-,*,/): ";
        cin >> op;
        cout << "Enter second fraction:\n";
        f2.getFraction();

        switch(op) {
            case '+': result = f1.add(f2); break;
            case '-': result = f1.sub(f2); break;
            case '*': result = f1.mul(f2); break;
            case '/': result = f1.div(f2); break;
            default: cout << "Invalid operation\n"; continue;
        }

        cout << "Result = ";
        result.display();
        cout << endl;

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;
    } while(choice == 'y');
    return 0;
}

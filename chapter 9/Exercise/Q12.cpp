// Q12.cpp
#include <iostream>
#include <cmath>
using namespace std;

//---------------------------------------------
// Base Class: sterling
//---------------------------------------------
class sterling {
protected:
    long pounds;
    int shillings;
    int pence;

public:
    // Constructors
    sterling() : pounds(0), shillings(0), pence(0) {}
    sterling(long p, int s, int pe) : pounds(p), shillings(s), pence(pe) {}
    ~sterling() {}

    // Function to get data from user
    void getSterling() {
        char ch;
        cout << "Enter amount in format £pounds.shillings.pence : £";
        cin >> pounds >> ch >> shillings >> ch >> pence;
    }

    // Display function
    void putSterling() const {
        cout << "£" << pounds << "." << shillings << "." << pence;
    }

    // Convert sterling to total pence
    long toPence() const {
        return pounds * 240 + shillings * 12 + pence;
    }

    // Convert total pence back to sterling
    void fromPence(long totalPence) {
        pounds = totalPence / 240;
        totalPence %= 240;
        shillings = totalPence / 12;
        pence = totalPence % 12;
    }

    // Arithmetic operators
    sterling operator+(const sterling& s2) const {
        sterling temp;
        long total = this->toPence() + s2.toPence();
        temp.fromPence(total);
        return temp;
    }

    sterling operator-(const sterling& s2) const {
        sterling temp;
        long total = this->toPence() - s2.toPence();
        temp.fromPence(total);
        return temp;
    }

    sterling operator*(double val) const {
        sterling temp;
        long total = lround(this->toPence() * val);
        temp.fromPence(total);
        return temp;
    }

    sterling operator/(double val) const {
        sterling temp;
        long total = lround(this->toPence() / val);
        temp.fromPence(total);
        return temp;
    }
};

//---------------------------------------------
// Derived Class: sterfrac (adds fractional pennies)
//---------------------------------------------
class sterfrac : public sterling {
private:
    int eighths; // number of eighths of a penny

public:
    // Constructors
    sterfrac() : sterling(), eighths(0) {}
    sterfrac(long p, int s, int pe, int e) : sterling(p, s, pe), eighths(e) {}
    ~sterfrac() {}

    // Input function
    void getSterfrac() {
        char ch;
        cout << "Enter amount (e.g. £9.19.11-3): £";
        cin >> pounds >> ch >> shillings >> ch >> pence;
        cin >> ch >> eighths; // after '-' sign
    }

    // Output function
    void putSterfrac() const {
        cout << "£" << pounds << "." << shillings << "." << pence << "-" << eighths << "/8";
    }

    // Convert to total eighths of a penny
    long toEighths() const {
        return toPence() * 8 + eighths;
    }

    // Convert total eighths back to sterling + fraction
    void fromEighths(long totalEighths) {
        long totalPence = totalEighths / 8;
        eighths = totalEighths % 8;
        fromPence(totalPence);
    }

    // Arithmetic operators
    sterfrac operator+(const sterfrac& s2) const {
        sterfrac temp;
        long total = this->toEighths() + s2.toEighths();
        temp.fromEighths(total);
        return temp;
    }

    sterfrac operator-(const sterfrac& s2) const {
        sterfrac temp;
        long total = this->toEighths() - s2.toEighths();
        temp.fromEighths(total);
        return temp;
    }

    sterfrac operator*(double val) const {
        sterfrac temp;
        long total = lround(this->toEighths() * val);
        temp.fromEighths(total);
        return temp;
    }

    sterfrac operator/(double val) const {
        sterfrac temp;
        long total = lround(this->toEighths() / val);
        temp.fromEighths(total);
        return temp;
    }
};

//---------------------------------------------
// Example main()
//---------------------------------------------
int main() {
    sterfrac s1(5, 10, 6, 4);  // £5.10.6-4/8
    sterfrac s2(3, 5, 8, 2);   // £3.5.8-2/8

    cout << "First amount: ";
    s1.putSterfrac();
    cout << "\nSecond amount: ";
    s2.putSterfrac();

    sterfrac sum = s1 + s2;
    cout << "\n\nAfter addition: ";
    sum.putSterfrac();

    sterfrac diff = s1 - s2;
    cout << "\nAfter subtraction: ";
    diff.putSterfrac();

    sterfrac mul = s1 * 2.5;
    cout << "\nAfter multiplication (×2.5): ";
    mul.putSterfrac();

    sterfrac div = s1 / 2;
    cout << "\nAfter division (÷2): ";
    div.putSterfrac();

    cout << endl;
    return 0;
}

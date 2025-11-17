/**1. Create a class that imitates part of the functionality of the basic data type int. Call the
class Int (note different capitalization). The only data in this class is an int variable.
Include member functions to initialize an Int to 0, to initialize it to an int value, to display it (it looks just like an int), and to add two Int values.
Write a program that exercises this class by creating one uninitialized and two initialized
Int values, adding the two initialized values and placing the response in the uninitialized
value, and then displaying this result.*/
#include <iostream>
using namespace std;

class Int {
private:
    int value;
public:
    // Constructors
    Int() : value(0) {}
    Int(int v) : value(v) {}

    // Destructor
    ~Int() {
        cout << "Destructor called (Int)\n";
    }

    void getValue() {
        cout << "Enter value: ";
        cin >> value;
    }

    void setValue(int v) {
        value = v;
    }

    void display() {
        cout << "Value = " << value << endl;
    }

    void add(Int a, Int b) {
        value = a.value + b.value;
    }
};

int main() {
    Int a, b, c;
    a.getValue();
    b.getValue();
    c.add(a, b);
    c.display();
    return 0;
}

// countpp2.cpp
// increment counter variable with ++ operator (prefix), return value
#include <iostream>
using namespace std;

class Counter {
private:
    unsigned int count; // count
public:
    Counter() : count(0) { }      // constructor
    unsigned int get_count() {    // return count
        return count;
    }
    Counter operator++() {        // increment count and return a Counter
        ++count;                  // increment this object's count
        Counter temp;             // make a temporary Counter
        temp.count = count;       // give it same value as this object
        return temp;              // return the copy
    }
};

int main() {
    Counter c1, c2; // c1=0, c2=0

    cout << "\nc1=" << c1.get_count(); // display
    cout << "\nc2=" << c2.get_count();

    ++c1;            // c1 becomes 1
    c2 = ++c1;       // pre-increment c1 (c1 becomes 2) and assign returned value to c2

    cout << "\nc1=" << c1.get_count(); // display again
    cout << "\nc2=" << c2.get_count() << endl;

    return 0;
}
// Why this works: operator++() returns a temporary Counter (with the updated value), so c2
//  = ++c1; assigns that temporary to c2
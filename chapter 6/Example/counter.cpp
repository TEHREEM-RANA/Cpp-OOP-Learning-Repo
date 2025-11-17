#include <iostream>
using namespace std;

class Counter {
private:
    unsigned int count;  // count variable (always positive)

public:
    // Constructor (called automatically)
    Counter() : count(0) {
        // we can also write: count = 0;
        // but initializer list is preferred
    }

    void inc_count() { count++; }  // increase count
    int get_count() { return count; }  // return current count
};

int main() {
    Counter c1, c2;   // constructor called for both

    cout << "c1 = " << c1.get_count();  // shows 0
    cout << "\nc2 = " << c2.get_count();

    c1.inc_count();   // c1 = 1
    c2.inc_count();   // c2 = 1
    c2.inc_count();   // c2 = 2

    cout << "\nc1 = " << c1.get_count();
    cout << "\nc2 = " << c2.get_count();
    return 0;
}

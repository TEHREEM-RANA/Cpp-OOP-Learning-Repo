// countpp_postfix.cpp
// Demonstrate postfix ++ operator for Counter
#include <iostream>
using namespace std;

class Counter {
private:
    unsigned int count;
public:
    Counter() : count(0) { }
    unsigned int get_count() { return count; }

    // prefix ++
    Counter operator++() {
        ++count;
        Counter temp;
        temp.count = count;
        return temp;
    }

    // postfix ++ (int parameter distinguishes it)
    Counter operator++(int) {
        Counter old = *this; // save old value
        ++count;             // increment this object
        return old;          // return the old value
    }
};

int main() {
    Counter c;
    cout << "start c=" << c.get_count() << "\n"; // 0

    Counter a = c++; // a gets old value (0), c becomes 1
    cout << "after c++: c=" << c.get_count() << ", a=" << a.get_count() << "\n";

    Counter b = ++c; // c becomes 2, b gets value 2
    cout << "after ++c: c=" << c.get_count() << ", b=" << b.get_count() << "\n";

    return 0;
}

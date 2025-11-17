// copy_constructor_example.cpp
#include <iostream>
using namespace std;

class Alpha {
private:
    int data;
public:
    // No-argument constructor
    Alpha() { }

    // One-argument constructor
    Alpha(int d) { data = d; }

    // Copy constructor
    Alpha(Alpha &a) {
        data = a.data;
        cout << "Copy constructor invoked" << endl;
    }

    // Function to display data
    void display() {
        cout << data << endl;
    }
};

int main() {
    Alpha a1(37);       // create object a1
    Alpha a2(a1);       // copy constructor is called
    // Alpha a3 = a1;   // alternative syntax, also calls copy constructor

    cout << "a1 = "; a1.display();
    cout << "a2 = "; a2.display();

    return 0;
}

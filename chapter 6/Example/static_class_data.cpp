// static_class_data.cpp
// Demonstrating static data members in a class

#include <iostream>
using namespace std;

class Foo
{
private:
    static int count; // shared among all objects
public:
    // Constructor: increases count whenever a new object is created
    Foo() { count++; }

    // Function to return current count
    int getCount() { return count; }
};

// Definition of static variable outside the class
int Foo::count = 0;

int main()
{
    Foo f1, f2, f3; // three objects created, constructor runs 3 times

    cout << "Count is " << f1.getCount() << endl;
    cout << "Count is " << f2.getCount() << endl;
    cout << "Count is " << f3.getCount() << endl;

    return 0;
}

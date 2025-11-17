// const_member_function.cpp
// Demonstrating const member functions

#include <iostream>
using namespace std;

class MyClass
{
private:
    int value;

public:
    MyClass(int v) : value(v) {} // constructor

    void nonConstFunc() // normal function (can change members)
    {
        value = 100; // ✅ allowed
        cout << "Inside nonConstFunc, value changed to " << value << endl;
    }

    void constFunc() const // const member function (cannot change members)
    {
        // value = 200; // ❌ ERROR: not allowed
        cout << "Inside constFunc, value is " << value << endl;
    }
};

int main()
{
    MyClass obj(50);

    obj.nonConstFunc(); // modifies value
    obj.constFunc();    // only reads value

    return 0;
}

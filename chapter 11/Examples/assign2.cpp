// assign2.cpp
#include <iostream>
using namespace std;

class alpha
{
private:
    int data;

public:
    alpha() { }
    alpha(int d) { data = d; }

    void display() { cout << data; }

    // Overloaded assignment operator
    alpha& operator=(alpha& a) // return by reference
    {
        data = a.data;
        cout << "\nAssignment operator invoked";
        return *this; // return the object itself
    }
};

int main()
{
    alpha a1(37);
    alpha a2, a3;

    a3 = a2 = a1; // assignment operator called twice

    cout << "\na2="; a2.display();
    cout << "\na3="; a3.display();
    cout << endl;

    return 0;
}

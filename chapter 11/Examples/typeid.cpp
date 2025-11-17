// typeid.cpp
#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
    virtual void virtFunc() { } // needed for typeid
};

class Derv1 : public Base { };
class Derv2 : public Base { };

void displayName(Base* pB)
{
    cout << "pointer to an object of ";
    cout << typeid(*pB).name() << endl; // prints class name
}

int main()
{
    Base* pBase = new Derv1;
    displayName(pBase); // "pointer to an object of class Derv1"

    pBase = new Derv2;
    displayName(pBase); // "pointer to an object of class Derv2"

    return 0;
}

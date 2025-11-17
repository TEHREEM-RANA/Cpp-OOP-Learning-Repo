// dyncast2.cpp
#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
protected:
    int ba;
public:
    Base() : ba(0) { }
    Base(int b) : ba(b) { }
    virtual void vertFunc() { } // needed for dynamic_cast
    void show() { cout << "Base: ba=" << ba << endl; }
};

class Derv : public Base
{
private:
    int da;
public:
    Derv(int b, int d) : da(d) { ba = b; }
    void show() { cout << "Derv: ba=" << ba << ", da=" << da << endl; }
};

int main()
{
    Base* pBase = new Base(10);   // pointer to Base
    Derv* pDerv = new Derv(21,22); // pointer to Derv

    // Upcast: Derived -> Base (fine)
    pBase = dynamic_cast<Base*>(pDerv);
    pBase->show(); // prints "Base: ba=21"

    // Downcast: Base -> Derived (must point to Derv)
    pBase = new Derv(31, 32);
    pDerv = dynamic_cast<Derv*>(pBase);
    pDerv->show(); // prints "Derv: ba=31, da=32"

    return 0;
}

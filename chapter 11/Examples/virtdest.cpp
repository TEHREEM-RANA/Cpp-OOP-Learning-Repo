// virtdest.cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() { cout << "Base destroyed\n"; } // make virtual
};

class Derv : public Base {
public:
    ~Derv() { cout << "Derv destroyed\n"; }
};

int main() {
    Base* pBase = new Derv;
    delete pBase; // both destructors called
    return 0;
}

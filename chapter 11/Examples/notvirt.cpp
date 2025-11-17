// notvirt.cpp
#include <iostream>
using namespace std;

class Base {
public:
    void show() { cout << "Base\n"; } // normal function
};

class Derv1 : public Base {
public:
    void show() { cout << "Derv1\n"; }
};

class Derv2 : public Base {
public:
    void show() { cout << "Derv2\n"; }
};

int main() {
    Derv1 dv1; 
    Derv2 dv2; 
    Base* ptr; // pointer to base class

    ptr = &dv1; 
    ptr->show(); // executes Base::show()

    ptr = &dv2; 
    ptr->show(); // executes Base::show()
    
    return 0;
}

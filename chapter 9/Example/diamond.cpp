// diamond.cpp
// Investigates diamond-shaped multiple inheritance

#include <iostream>
using namespace std;

class A
{
public:
    void func() { cout << "Function in A\n"; }
};

class B : public A { };
class C : public A { };
class D : public B, public C { };

int main()
{
    D objD;
    // objD.func(); // ERROR: ambiguous (two copies of A)
    return 0;
}

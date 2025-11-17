// pubpriv.cpp
// Demonstration of Public and Private Inheritance in C++

#include <iostream>
#include <string>
using namespace std;

// --------------------------------------------------------------
// Base class
class A {
private:
    int privdataA;
protected:
    int protdataA;
public:
    int pubdataA;

    // Constructor
    A(int priv = 1, int prot = 2, int pub = 3)
        : privdataA(priv), protdataA(prot), pubdataA(pub) {
        cout << "Base class A constructed.\n";
    }

    // Getter to show private data (since derived classes can't access it)
    int getPrivData() const { return privdataA; }

    // Destructor
    ~A() {
        cout << "Base class A destroyed.\n";
    }
};

// --------------------------------------------------------------
// Publicly Derived Class
class B : public A {
public:
    B() : A(10, 20, 30) {
        cout << "Derived class B (public) constructed.\n";
    }

    void showAccess() {
        cout << "\n--- Inside class B (Public Inheritance) ---\n";
        // privdataA = 1; // ❌ Error: private not accessible
        protdataA = 200; // ✅ OK (protected accessible)
        pubdataA = 300;  // ✅ OK (public accessible)

        cout << "Protected data (from A): " << protdataA << endl;
        cout << "Public data (from A): " << pubdataA << endl;
    }

    ~B() {
        cout << "Derived class B destroyed.\n";
    }
};

// --------------------------------------------------------------
// Privately Derived Class
class C : private A {
public:
    C() : A(100, 200, 300) {
        cout << "Derived class C (private) constructed.\n";
    }

    void showAccess() {
        cout << "\n--- Inside class C (Private Inheritance) ---\n";
        // privdataA = 1; // ❌ Error: private not accessible
        protdataA = 2000; // ✅ OK
        pubdataA = 3000;  // ✅ OK

        cout << "Protected data (from A): " << protdataA << endl;
        cout << "Public data (from A): " << pubdataA << endl;
    }

    // Getter to show base's private member indirectly
    int getPrivFromBase() const {
        return getPrivData();
    }

    ~C() {
        cout << "Derived class C destroyed.\n";
    }
};

// --------------------------------------------------------------
// MAIN PROGRAM
int main() {
    cout << "\n=== Public and Private Inheritance Demo ===\n";

    // Object of publicly derived class
    B objB;
    objB.showAccess();

    cout << "\n--- Access from main() (Public Inheritance) ---\n";
    // objB.protdataA = 10;  // ❌ Error: protected not accessible to object
    cout << "objB.pubdataA = " << objB.pubdataA << endl; // ✅ OK

    // Object of privately derived class
    C objC;
    objC.showAccess();

    cout << "\n--- Access from main() (Private Inheritance) ---\n";
    // objC.pubdataA = 10;  // ❌ Error: not accessible (A is private to C)
    cout << "Private data of base A (via getter): " << objC.getPrivFromBase() << endl;

    cout << "\n=== End of Program ===\n";
    return 0;
}

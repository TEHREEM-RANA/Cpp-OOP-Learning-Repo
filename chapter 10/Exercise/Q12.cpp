// Q12.cpp
#include <iostream>
using namespace std;

// Simulated memory arrays
const int FMEM_SIZE = 100;
const int PMEM_SIZE = 100;

float fmemory[FMEM_SIZE];  // Simulated memory for float variables
int fmem_top = 0;           // Next free index in fmemory

int pmemory[PMEM_SIZE];     // Simulated memory for pointer addresses
int pmem_top = 0;           // Next free index in pmemory

// Class representing a Float stored in fmemory
class Float {
private:
    int addr;  // Index in fmemory where this float is stored

public:
    // Constructor stores float in fmemory and saves its "address"
    Float(float value) {
        if (fmem_top >= FMEM_SIZE) {
            cout << "fmemory overflow!" << endl;
            exit(1);
        }
        fmemory[fmem_top] = value;
        addr = fmem_top;
        fmem_top++;
    }

    // Overloaded & operator returns the "address" (index in fmemory)
    int operator&() const {
        return addr;
    }
};

// Class representing a pointer to Float
class ptrFloat {
private:
    int addr;  // Index in pmemory where the pointer is stored

public:
    // Constructor stores index of Float's address into pmemory
    ptrFloat(int float_addr) {
        if (pmem_top >= PMEM_SIZE) {
            cout << "pmemory overflow!" << endl;
            exit(1);
        }
        pmemory[pmem_top] = float_addr;
        addr = pmem_top;
        pmem_top++;
    }

    // Overloaded * operator returns reference to float value
    float& operator*() {
        return fmemory[pmemory[addr]];
    }
};

// Main function to test the classes
int main() {
    // Define and initialize Floats
    Float var1 = 1.234;
    Float var2 = 5.678;

    // Define pointers to Floats
    ptrFloat ptr1 = &var1;
    ptrFloat ptr2 = &var2;

    cout << "*ptr1 = " << *ptr1 << endl;  // Access via pointer
    cout << "*ptr2 = " << *ptr2 << endl;

    // Modify values through pointers
    *ptr1 = 7.123;
    *ptr2 = 8.456;

    cout << "*ptr1 = " << *ptr1 << endl;  // Access modified values
    cout << "*ptr2 = " << *ptr2 << endl;

    return 0;
}

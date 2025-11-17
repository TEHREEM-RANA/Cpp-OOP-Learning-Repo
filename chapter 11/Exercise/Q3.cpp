// Q3.cpp
#include <iostream>
using namespace std;

class Array {
private:
    int* ptr;
    int size;
public:
    // Constructor
    Array(int s) : size(s) {
        ptr = new int[s];
    }

    // Copy Constructor
    Array(const Array& arr) {
        size = arr.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
            ptr[i] = arr.ptr[i];
    }

    // Assignment Operator
    Array& operator=(const Array& arr) {
        if (this == &arr) return *this; // Self-assignment check

        // Delete old memory
        delete[] ptr;

        size = arr.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
            ptr[i] = arr.ptr[i];
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] ptr;
    }

    // Overload subscript operator
    int& operator[](int index) {
        return ptr[index];
    }

    // Function to display array
    void display() {
        for (int i = 0; i < size; i++)
            cout << ptr[i] << " ";
        cout << endl;
    }
};

int main() {
    const int ASIZE = 5;
    Array arr1(ASIZE);

    // Fill arr1 with squares
    for (int i = 0; i < ASIZE; i++)
        arr1[i] = i * i;

    cout << "arr1: ";
    arr1.display();

    // Copy constructor
    Array arr2(arr1);
    cout << "arr2 (copy of arr1): ";
    arr2.display();

    // Assignment operator
    Array arr3(ASIZE);
    arr3 = arr1;
    cout << "arr3 (assigned from arr1): ";
    arr3.display();

    // Modify arr1 to check deep copy
    arr1[0] = 100;
    cout << "\nAfter modifying arr1[0] = 100\n";
    cout << "arr1: ";
    arr1.display();
    cout << "arr2: ";
    arr2.display();
    cout << "arr3: ";
    arr3.display();

    return 0;
}

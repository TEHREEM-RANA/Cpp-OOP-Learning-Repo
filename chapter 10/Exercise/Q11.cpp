// Q11.cpp
#include <iostream>
using namespace std;

class TenArrays {
private:
    static const int SIZE = 10;       // Number of separate arrays
    static const int LENGTH = 5;      // Length of each array
    int data[SIZE][LENGTH];           // 2D array internally

public:
    // Constructor to initialize arrays with some values
    TenArrays() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < LENGTH; j++) {
                *(*(data + i) + j) = i * 10 + j;  // Using pointer notation
            }
        }
    }

    // Overloaded subscript operator to treat as single 1D array
    int& operator[](int index) {
        if (index < 0 || index >= SIZE * LENGTH) {
            cout << "Index out of range. Exiting.\n";
            exit(1);
        }
        int row = index / LENGTH;
        int col = index % LENGTH;
        return *(*(data + row) + col);  // Pointer notation to access element
    }

    // Function to display all elements
    void display() const {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < LENGTH; j++) {
                cout << *(*(data + i) + j) << " ";  // Pointer notation
            }
            cout << endl;
        }
    }
};

// Main function to test the class
int main() {
    TenArrays a;

    cout << "Original arrays:\n";
    a.display();

    // Access using single index
    cout << "\nAccessing elements using a single index:\n";
    for (int i = 0; i < 50; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Modify elements using single index
    for (int i = 0; i < 50; i++) {
        a[i] += 1;
    }

    cout << "\nAfter incrementing each element by 1:\n";
    a.display();

    return 0;
}

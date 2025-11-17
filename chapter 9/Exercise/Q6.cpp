// Q6.cpp
#include <iostream>
#include <cstdlib>  // for exit()
using namespace std;

const int LIMIT = 100;  // maximum array size

// ---------- Base Class: safearay ----------
class safearay {
protected:
    int arr[LIMIT];

public:
    // Overloaded [] operator with bounds check (0 to LIMIT-1)
    int& operator[](int n) {
        if (n < 0 || n >= LIMIT) {
            cout << "Index out of bounds!\n";
            exit(1);
        }
        return arr[n];
    }
};

// ---------- Derived Class: safehilo ----------
class safehilo : public safearay {
private:
    int low, high;  // user-defined range

public:
    // Default Constructor
    safehilo() : low(0), high(LIMIT - 1) {}

    // Parameterized Constructor
    safehilo(int l, int h) {
        if ((h - l + 1) > LIMIT || l > h) {
            cout << "Invalid range!\n";
            exit(1);
        }
        low = l;
        high = h;
    }

    // Overload [] again to allow custom index range
    int& operator[](int n) {
        if (n < low || n > high) {
            cout << "Index out of bounds!\n";
            exit(1);
        }
        // Shift index to start from 0
        return arr[n - low];
    }

    int getlow() const { return low; }
    int gethigh() const { return high; }
};

// ---------- Main Function ----------
int main() {
    int low, high;
    cout << "Enter lower limit of array: ";
    cin >> low;
    cout << "Enter upper limit of array: ";
    cin >> high;

    safehilo sa(low, high);

    cout << "\nEnter values for array from " << low << " to " << high << ":\n";
    for (int i = low; i <= high; i++) {
        cout << "Element [" << i << "]: ";
        cin >> sa[i];
    }

    cout << "\nArray elements are:\n";
    for (int i = low; i <= high; i++) {
        cout << "sa[" << i << "] = " << sa[i] << endl;
    }

    return 0;
}

// arrover3.cpp
// creates safe array (index values are checked before access)
// uses overloaded [] operator for both put and get

#include <iostream>
using namespace std;
#include <process.h> // for exit()

const int LIMIT = 100;

class safearay {
private:
    int arr[LIMIT];
public:
    int& operator[](int n) { // overload [] and return by reference
        if (n < 0 || n >= LIMIT) {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n];
    }
};

int main() {
    safearay sa1;

    // Insert elements
    for (int j = 0; j < LIMIT; j++)
        sa1[j] = j * 10; // LEFT side of =

    // Display elements
    for (int j = 0; j < LIMIT; j++) {
        int temp = sa1[j]; // RIGHT side of =
        cout << "Element " << j << " is " << temp << endl;
    }

    return 0;
}

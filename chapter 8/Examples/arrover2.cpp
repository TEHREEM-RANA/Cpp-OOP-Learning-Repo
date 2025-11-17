// arrover2.cpp
// creates safe array (index values are checked before access)
// uses one access() function for both put and get

#include <iostream>
using namespace std;
#include <process.h> // for exit()

const int LIMIT = 100;

class safearay {
private:
    int arr[LIMIT];
public:
    int& access(int n) { // return by reference
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
        sa1.access(j) = j * 10; // LEFT side of =

    // Display elements
    for (int j = 0; j < LIMIT; j++) {
        int temp = sa1.access(j); // RIGHT side of =
        cout << "Element " << j << " is " << temp << endl;
    }

    return 0;
}

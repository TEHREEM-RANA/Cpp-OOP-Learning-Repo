// arrover1.cpp
// creates safe array (index values are checked before access)
// uses separate put and get functions

#include <iostream>
using namespace std;
#include <process.h> // for exit()

const int LIMIT = 100;

class safearay {
private:
    int arr[LIMIT];
public:
    void putel(int n, int elvalue) { // insert element
        if (n < 0 || n >= LIMIT) {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        arr[n] = elvalue;
    }

    int getel(int n) const { // get element
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
        sa1.putel(j, j * 10);

    // Display elements
    for (int j = 0; j < LIMIT; j++) {
        int temp = sa1.getel(j);
        cout << "Element " << j << " is " << temp << endl;
    }

    return 0;
}

// ptrorder.cpp
// orders two arguments using pointers
#include <iostream>
using namespace std;

void order(int*, int*); // prototype

int main() {
    int n1 = 99, n2 = 11;  // one pair not in order
    int n3 = 22, n4 = 88;  // one pair already in order

    order(&n1, &n2);  // passing addresses
    order(&n3, &n4);

    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;
    cout << "n3 = " << n3 << endl;
    cout << "n4 = " << n4 << endl;

    return 0;
}

//--------------------------------------------------------------
void order(int* numb1, int* numb2) {
    if (*numb1 > *numb2) { // if first is bigger, swap them
        int temp = *numb1;
        *numb1 = *numb2;
        *numb2 = temp;
    }
}

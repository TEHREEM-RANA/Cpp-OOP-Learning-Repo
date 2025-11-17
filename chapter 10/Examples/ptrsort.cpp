// ptrsort.cpp
// sorts an array using pointers
#include <iostream>
using namespace std;

void bsort(int*, int);   // prototype
void order(int*, int*);  // prototype

int main() {
    const int N = 10;
    int arr[N] = { 37, 84, 62, 91, 11, 65, 57, 28, 19, 49 };

    bsort(arr, N);  // sort the array

    for (int j = 0; j < N; j++)
        cout << arr[j] << " ";
    cout << endl;

    return 0;
}

//--------------------------------------------------------------
void bsort(int* ptr, int n) {
    for (int j = 0; j < n - 1; j++)
        for (int k = j + 1; k < n; k++)
            order(ptr + j, ptr + k); // pass addresses of two elements
}

//--------------------------------------------------------------
void order(int* numb1, int* numb2) {
    if (*numb1 > *numb2) {
        int temp = *numb1;
        *numb1 = *numb2;
        *numb2 = temp;
    }
}

// friend.cpp
#include <iostream>
using namespace std;

class beta; // forward declaration

class alpha {
private:
    int data;
public:
    alpha() : data(3) { } // constructor
    friend int frifunc(alpha, beta); // declare friend function
};

class beta {
private:
    int data;
public:
    beta() : data(7) { }
    friend int frifunc(alpha, beta); // declare friend function
};

// function definition (not a member of either class)
int frifunc(alpha a, beta b) {
    return a.data + b.data; // access private data
}

int main() {
    alpha aa;
    beta bb;
    cout << frifunc(aa, bb) << endl; // output: 10
    return 0;
}

// Q11.cpp
#include <iostream>
using namespace std;

//-------------------------------------------
// Structure to hold a pair of integers
//-------------------------------------------
struct Pair {
    int x;
    int y;
};

//-------------------------------------------
// Base class: Stack2 (stores int values)
//-------------------------------------------
class Stack2 {
protected:
    enum { MAX = 10 }; // maximum stack size
    int st[MAX];
    int top;

public:
    Stack2() : top(-1) {} // Constructor initializes empty stack
    ~Stack2() {} // Destructor

    void push(int var) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        st[++top] = var;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return st[top--];
    }

    void display() {
        cout << "Stack contents: ";
        for (int i = 0; i <= top; i++)
            cout << st[i] << " ";
        cout << endl;
    }
};

//-------------------------------------------
// Derived class: pairStack
//-------------------------------------------
class pairStack : public Stack2 {
public:
    // Pushes a pair (x, y) onto the stack
    void push(Pair p) {
        // store x and y using base class push()
        Stack2::push(p.x);
        Stack2::push(p.y);
    }

    // Pops a pair (x, y) from the stack
    Pair popPair() {
        Pair temp;
        temp.y = Stack2::pop(); // pop in reverse order
        temp.x = Stack2::pop();
        return temp;
    }
};

//-------------------------------------------
// Example main() function
//-------------------------------------------
int main() {
    pairStack ps;

    Pair p1 = {1, 2};
    Pair p2 = {3, 4};
    Pair p3 = {5, 6};

    cout << "Pushing pairs onto stack..." << endl;
    ps.push(p1);
    ps.push(p2);
    ps.push(p3);

    ps.display(); // optional, shows all elements

    cout << "\nPopping pairs from stack..." << endl;
    Pair temp = ps.popPair();
    cout << "Popped Pair: (" << temp.x << ", " << temp.y << ")" << endl;

    temp = ps.popPair();
    cout << "Popped Pair: (" << temp.x << ", " << temp.y << ")" << endl;

    return 0;
}

// stakaray.cpp
// a stack as a class
#include <iostream>
using namespace std;

class Stack {
private:
    enum { MAX = 10 };   // defines stack size (constant)
    int st[MAX];          // array of integers (stack storage)
    int top;              // index of top of stack

public:
    Stack() { top = 0; }  // constructor initializes top = 0

    void push(int var) {  // pushes number on stack
        st[++top] = var;
    }

    int pop() {           // pops number from stack
        return st[top--];
    }
};

int main() {
    Stack s1;             // create a stack object

    s1.push(11);
    s1.push(22);
    cout << "1: " << s1.pop() << endl; // prints 22
    cout << "2: " << s1.pop() << endl; // prints 11

    s1.push(33);
    s1.push(44);
    s1.push(55);
    s1.push(66);

    cout << "3: " << s1.pop() << endl; // 66
    cout << "4: " << s1.pop() << endl; // 55
    cout << "5: " << s1.pop() << endl; // 44
    cout << "6: " << s1.pop() << endl; // 33

    return 0;
}

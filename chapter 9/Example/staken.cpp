// staken.cpp
// overriding functions in base and derived classes

#include <iostream>
#include <process.h> // for exit()
using namespace std;

class Stack
{
protected:
    enum { MAX = 3 }; // size of stack
    int st[MAX];      // array to store data
    int top;          // index of top item

public:
    Stack() { top = -1; }

    void push(int var)      // push item
    { st[++top] = var; }

    int pop()               // pop item
    { return st[top--]; }
};

class Stack2 : public Stack
{
public:
    // Override push() to add error check
    void push(int var)
    {
        if(top >= MAX - 1) {
            cout << "\nError: stack is full";
            exit(1);
        }
        Stack::push(var); // call base push()
    }

    // Override pop() to add error check
    int pop()
    {
        if(top < 0) {
            cout << "\nError: stack is empty\n";
            exit(1);
        }
        return Stack::pop(); // call base pop()
    }
};

int main()
{
    Stack2 s1;

    s1.push(11);
    s1.push(22);
    s1.push(33);

    cout << endl << s1.pop();
    cout << endl << s1.pop();
    cout << endl << s1.pop();
    cout << endl << s1.pop(); // oops! one too many pops
    cout << endl;

    return 0;
}

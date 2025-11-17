// Q7.cpp
#include <iostream>
using namespace std;

// Abstract base class
class Token {
public:
    virtual float getNumber() = 0;   // Pure virtual
    virtual char getOperator() = 0;  // Pure virtual
    virtual ~Token() {}
};

// Derived class for operators
class Operator : public Token {
private:
    char oper;
public:
    Operator(char o) : oper(o) {}
    char getOperator() override { return oper; }
    float getNumber() override { return 0.0f; } // dummy
};

// Derived class for numbers
class Number : public Token {
private:
    float value;
public:
    Number(float v) : value(v) {}
    float getNumber() override { return value; }
    char getOperator() override { return '\0'; } // dummy
};

// Simple Stack class for Token*
class Stack {
private:
    Token* arr[100];
    int top;
public:
    Stack() : top(-1) {}

    void push(Token* t) {
        if (top < 99) arr[++top] = t;
        else cout << "Stack overflow!" << endl;
    }

    Token* pop() {
        if (top >= 0) return arr[top--];
        else { cout << "Stack underflow!" << endl; return nullptr; }
    }

    bool isEmpty() { return top == -1; }
};

int main() {
    Stack s;

    // Push numbers
    Number* n1 = new Number(3.14);
    Number* n2 = new Number(2.71);
    s.push(n1);
    s.push(n2);

    // Push operators
    Operator* op1 = new Operator('+');
    Operator* op2 = new Operator('*');
    s.push(op1);
    s.push(op2);

    // Pop and display
    cout << "Popping stack:\n";
    while (!s.isEmpty()) {
        Token* t = s.pop();
        if (t->getOperator() != '\0') {
            cout << "Operator: " << t->getOperator() << endl;
        } else {
            cout << "Number: " << t->getNumber() << endl;
        }
        delete t; // free memory
    }

    return 0;
}

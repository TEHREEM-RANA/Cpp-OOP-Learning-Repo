// Q10.cpp
#include <iostream>
#include <stack>
using namespace std;

// Abstract base class
class Token {
public:
    virtual float getNumber() = 0;
    virtual char getOperator() = 0;
    virtual ~Token() {}
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

// Derived class for operators
class Operator : public Token {
private:
    char op;
public:
    Operator(char o) : op(o) {}
    float getNumber() override { return 0.0f; } // dummy
    char getOperator() override { return op; }
};

int main() {
    stack<Token*> s;

    // Push numbers
    Number* n1 = new Number(3.14159);
    Number* n2 = new Number(2.0);
    Number* n3 = new Number(75.25);
    Number* n4 = new Number(3.333);
    Number* n5 = new Number(6.02);

    s.push(n1);
    s.push(n2);
    s.push(n3);
    s.push(n4);
    s.push(n5);

    // Push operators
    Operator* op1 = new Operator('/');
    Operator* op2 = new Operator('+');
    Operator* op3 = new Operator('*');
    Operator* op4 = new Operator('+');

    s.push(op1);
    s.push(op2);
    s.push(op3);
    s.push(op4);

    // Pop and display
    cout << "Tokens in stack (top to bottom):\n";
    while (!s.empty()) {
        Token* t = s.top();
        s.pop();
        if (t->getOperator() != '\0')
            cout << "Operator: " << t->getOperator() << endl;
        else
            cout << "Number: " << t->getNumber() << endl;
        delete t; // free memory
    }

    return 0;
}

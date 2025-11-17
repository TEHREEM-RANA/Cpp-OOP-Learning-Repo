// parse.cpp
// Evaluates arithmetic expressions composed of 1-digit numbers
#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 80;
const int MAX = 40;

class Stack {
private:
    char st[MAX];
    int top;
public:
    Stack() { top = 0; }
    void push(char var) { st[++top] = var; }
    char pop() { return st[top--]; }
    int gettop() { return top; }
};

class express {
private:
    Stack s;
    char* pStr;
    int len;
public:
    express(char* ptr) {
        pStr = ptr;
        len = strlen(pStr);
    }
    void parse();
    int solve();
};

void express::parse() {
    char ch, lastval, lastop;
    for(int j = 0; j < len; j++) {
        ch = pStr[j];
        if(ch >= '0' && ch <= '9')
            s.push(ch - '0');
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/') {
            if(s.gettop() == 1)
                s.push(ch);
            else {
                lastval = s.pop();
                lastop = s.pop();

                if((ch=='*' || ch=='/') && (lastop=='+' || lastop=='-')) {
                    s.push(lastop);
                    s.push(lastval);
                } else {
                    switch(lastop) {
                        case '+': s.push(s.pop() + lastval); break;
                        case '-': s.push(s.pop() - lastval); break;
                        case '*': s.push(s.pop() * lastval); break;
                        case '/': s.push(s.pop() / lastval); break;
                    }
                }
                s.push(ch);
            }
        }
    }
}

int express::solve() {
    char lastval;
    while(s.gettop() > 1) {
        lastval = s.pop();
        switch(s.pop()) {
            case '+': s.push(s.pop() + lastval); break;
            case '-': s.push(s.pop() - lastval); break;
            case '*': s.push(s.pop() * lastval); break;
            case '/': s.push(s.pop() / lastval); break;
        }
    }
    return int(s.pop());
}

int main() {
    char ans;
    char string[LEN];
    cout << "\nEnter arithmetic expression (no spaces, 1-digit numbers): ";
    do {
        cout << "\nExpression: ";
        cin >> string;
        express* eptr = new express(string);
        eptr->parse();
        cout << "Result: " << eptr->solve();
        delete eptr;
        cout << "\nDo another (y/n)? ";
        cin >> ans;
    } while(ans == 'y');
    return 0;
}

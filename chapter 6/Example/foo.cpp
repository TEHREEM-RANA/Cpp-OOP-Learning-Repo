# include <iostream>
using namespace std;

class Foo {
private:
    int data;
public:
    Foo() : data(0) { 
        cout << "Constructor called\n"; 
    }
    ~Foo() { 
        cout << "Destructor called\n"; 
    }
};

int main() {
    Foo obj;  // constructor runs here
            // destructor runs here (object destroyed)


    

    return 0;
}
// objmem.cpp
// Demonstrating object memory and lifetime
#include <iostream>
using namespace std;

class Demo
{
private:
    int id;

public:
    Demo(int i) : id(i)
    {
        cout << "Constructor called for object " << id << endl;
    }
    ~Demo()
    {
        cout << "Destructor called for object " << id << endl;
    }
};

Demo globalObj(1); // global object

void func()
{
    Demo localObj(2);         // automatic object
    Demo* dynamicObj = new Demo(3); // dynamic object

    cout << "Inside function.\n";

    delete dynamicObj; // manually delete
} // localObj destroyed here automatically

int main()
{
    cout << "Inside main.\n";
    func();
    cout << "Back in main.\n";
    return 0;
}

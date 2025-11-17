// struct_vs_class.cpp
// Difference between struct and class, and memory sharing

#include <iostream>
using namespace std;

// Using class (members private by default)
class FooClass
{
    int data1;   // private by default
public:
    void setData(int d) { data1 = d; }
    void showData() { cout << "Class data: " << data1 << endl; }
};

// Using struct (members public by default)
struct FooStruct
{
    int data1;   // public by default
    void showData() { cout << "Struct data: " << data1 << endl; }
};

////////////////////////////////////////////////////////////////
int main()
{
    // Demonstrate class
    FooClass obj1, obj2;
    obj1.setData(10);
    obj2.setData(20);

    obj1.showData(); // Class data: 10
    obj2.showData(); // Class data: 20

    // Demonstrate struct
    FooStruct s1, s2;
    s1.data1 = 100;   // directly accessible
    s2.data1 = 200;

    s1.showData(); // Struct data: 100
    s2.showData(); // Struct data: 200

    return 0;
}

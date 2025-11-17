// counten2.cpp
// constructors in derived class

#include <iostream>
using namespace std;

class Counter
{
protected:
    unsigned int count;
public:
    Counter() : count(0)       // no-argument constructor
    { }

    Counter(int c) : count(c)  // one-argument constructor
    { }

    unsigned int get_count() const
    {
        return count;
    }

    Counter operator++()       // prefix increment
    {
        return Counter(++count);
    }
};

// Derived class
class CountDn : public Counter
{
public:
    CountDn() : Counter()      // calls base no-arg constructor
    { }

    CountDn(int c) : Counter(c) // calls base one-arg constructor
    { }

    CountDn operator--()       // prefix decrement
    {
        return CountDn(--count);
    }
};

int main()
{
    CountDn c1;           // calls CountDn()
    CountDn c2(100);      // calls CountDn(int)

    cout << "c1=" << c1.get_count();
    cout << "\nc2=" << c2.get_count();

    ++c1; ++c1; ++c1;
    cout << "\nc1=" << c1.get_count();

    --c2; --c2;
    cout << "\nc2=" << c2.get_count();

    CountDn c3 = --c2;     // creates c3 from c2
    cout << "\nc3=" << c3.get_count();

    cout << endl;
    return 0;
}

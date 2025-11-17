// counten.cpp
// inheritance with Counter class (simple, clean example)

#include <iostream>
using namespace std;

class Counter // base class
{
protected:               // allow derived classes to access 'count'
    unsigned int count;

public:
    Counter() : count(0)            // no-arg constructor
    { }

    Counter(int c) : count(c)       // 1-arg constructor
    { }

    unsigned int get_count() const  // return count
    {
        return count;
    }

    // prefix increment
    Counter& operator++()
    {
        ++count;
        return *this;
    }
};

class CountDn : public Counter // derived class
{
public:
    // prefix decrement added in derived class
    CountDn& operator--()
    {
        --count;      // can access protected member 'count'
        return *this;
    }
};

int main()
{
    CountDn c1;                     // object of derived class
    cout << "c1=" << c1.get_count() << '\n'; // initial value

    ++c1; ++c1; ++c1;               // increment 3 times (uses Counter::operator++())
    cout << "c1=" << c1.get_count() << '\n';

    --c1; --c1;                     // decrement 2 times (uses CountDn::operator--())
    cout << "c1=" << c1.get_count() << '\n';

    // We can also make a base class object
    Counter c2(5);
    cout << "c2=" << c2.get_count() << '\n';
    ++c2;
    cout << "c2 after ++ =" << c2.get_count() << '\n';
    // Note: c2 cannot use -- because Counter has no decrement.

    return 0;
}

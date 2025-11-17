// constObj.cpp
// Demonstrating const objects in C++

#include <iostream>
using namespace std;

class Distance // English Distance class
{
private:
    int feet;
    float inches;

public:
    // constructor with two arguments
    Distance(int ft, float in) : feet(ft), inches(in) {}

    void getdist() // non-const function (modifies object)
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void showdist() const // const function (only reads object)
    {
        cout << feet << "\'-" << inches << '\"';
    }
};

int main()
{
    const Distance football(300, 0); // const object

    // football.getdist(); // ❌ ERROR: cannot call non-const function

    cout << "football = ";
    football.showdist(); // ✅ Allowed (const function)
    cout << endl;

    return 0;
}

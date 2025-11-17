// engless.cpp
// overloaded '<' operator compares two Distances

#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    // Constructor with no arguments
    Distance() : feet(0), inches(0.0) { }

    // Constructor with parameters
    Distance(int ft, float in) : feet(ft), inches(in) { }

    // Function to get distance from user
    void getdist()
    {
        cout << "\nEnter feet: "; 
        cin >> feet;
        cout << "Enter inches: "; 
        cin >> inches;
    }

    // Function to display distance
    void showdist() const
    {
        cout << feet << "\'-" << inches << '\"';
    }

    // Overload '<' operator to compare distances
    bool operator < (Distance d2) const
    {
        float bf1 = feet + inches / 12;       // convert this distance to feet
        float bf2 = d2.feet + d2.inches / 12; // convert d2 to feet

        return (bf1 < bf2) ? true : false;    // return true if smaller
    }
};

int main()
{
    Distance dist1;           // user input
    dist1.getdist();

    Distance dist2(6, 2.5);   // pre-defined distance

    cout << "\ndist1 = "; dist1.showdist();
    cout << "\ndist2 = "; dist2.showdist();

    if (dist1 < dist2)
        cout << "\ndist1 is less than dist2";
    else
        cout << "\ndist1 is greater than (or equal to) dist2";

    cout << endl;
    return 0;
}

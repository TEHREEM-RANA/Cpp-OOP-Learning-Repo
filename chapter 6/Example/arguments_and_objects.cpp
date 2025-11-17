// arguments_and_objects.cpp
// Demonstrating arguments and objects with Distance class

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
class Distance // English Distance class
{
private:
    int feet;
    float inches;

public:
    // constructor (no args)
    Distance() : feet(0), inches(0.0)
    { }

    // constructor (two args)
    Distance(int ft, float in) : feet(ft), inches(in)
    { }

    // get length from user
    void getdist()
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // display distance
    void showdist()
    {
        cout << feet << "\'-" << inches << '\"';
    }

    // add two Distance objects
    Distance add_dist(Distance);
};

//--------------------------------------------------------------
// add this distance to d2, return the sum
Distance Distance::add_dist(Distance d2)
{
    Distance temp; // temporary object

    temp.inches = inches + d2.inches; // add inches
    if (temp.inches >= 12.0)          // if inches >= 12
    {
        temp.inches -= 12.0; // adjust inches
        temp.feet = 1;       // carry 1 foot
    }

    temp.feet += feet + d2.feet; // add feet
    return temp;                 // return object
}

////////////////////////////////////////////////////////////////
int main()
{
    Distance dist1, dist3;       // define two lengths
    Distance dist2(11, 6.25);    // define, initialize dist2

    dist1.getdist();             // get dist1 from user
    dist3 = dist1.add_dist(dist2); // dist3 = dist1 + dist2

    // display all lengths
    cout << "\ndist1 = "; dist1.showdist();
    cout << "\ndist2 = "; dist2.showdist();
    cout << "\ndist3 = "; dist3.showdist();
    cout << endl;

    return 0;
}

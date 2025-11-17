// englplus.cpp
// overloaded '+' operator adds two Distance objects
#include <iostream>
using namespace std;

class Distance // English Distance class
{
private:
    int feet;
    float inches;

public:
    // constructor (no args)
    Distance() : feet(0), inches(0.0f) { }

    // constructor (two args)
    Distance(int ft, float in) : feet(ft), inches(in) { }

    // get length from user
    void getdist() {
        cout << "\nEnter feet: ";  cin >> feet;
        cout << "Enter inches: ";  cin >> inches;
    }

    // display distance (note: prints like 10'-6.5")
    void showdist() const {
        cout << feet << "\'-" << inches << '\"';
    }

    // declaration: add two Distances (member function)
    Distance operator + (Distance) const; // returns Distance, takes one Distance argument
};

// definition: add this Distance (left operand) to d2 (right operand)
Distance Distance::operator + (Distance d2) const
{
    int f = feet + d2.feet;        // add the feet
    float i = inches + d2.inches;  // add the inches

    if (i >= 12.0f) {              // carry if inches >= 12.0
        i -= 12.0f;
        f++;                       // increase feet by 1
    }

    // return a new Distance object initialized with sum
    return Distance(f, i);
}

int main()
{
    Distance dist1, dist3, dist4;      // dist1 and dist3 and dist4
    dist1.getdist();                   // read dist1 from user
    Distance dist2(11, 6.25f);         // create dist2 with feet=11, inches=6.25

    dist3 = dist1 + dist2;             // single '+' operator
    dist4 = dist1 + dist2 + dist3;     // chaining: (dist1 + dist2) + dist3

    // display all lengths
    cout << "dist1 = "; dist1.showdist(); cout << endl;
    cout << "dist2 = "; dist2.showdist(); cout << endl;
    cout << "dist3 = "; dist3.showdist(); cout << endl;
    cout << "dist4 = "; dist4.showdist(); cout << endl;

    return 0;
}

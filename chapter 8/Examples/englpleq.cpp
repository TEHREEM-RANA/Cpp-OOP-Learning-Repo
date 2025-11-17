// englpleq.cpp
// Overloaded ‘+=’ assignment operator

#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

public:
    // Default constructor
    Distance() : feet(0), inches(0.0) { }

    // Parameterized constructor
    Distance(int ft, float in) : feet(ft), inches(in) { }

    // Function to input distance
    void getdist() {
        cout << "\nEnter feet: "; cin >> feet;
        cout << "Enter inches: "; cin >> inches;
    }

    // Function to display distance
    void showdist() const {
        cout << feet << "\'-" << inches << "\"";
    }

    // Overloaded operator +=
    void operator += (Distance d2);
};

//--------------------------------------------------------------
// Function definition for += operator
void Distance::operator += (Distance d2) {
    feet += d2.feet;       // add feet
    inches += d2.inches;   // add inches

    // If inches reach 12 or more, convert to feet
    if (inches >= 12.0) {
        inches -= 12.0;
        feet++;
    }
}

//--------------------------------------------------------------
int main() {
    Distance dist1;
    dist1.getdist();                // get first distance from user
    cout << "\ndist1 = "; dist1.showdist();

    Distance dist2(11, 6.25);       // second distance fixed
    cout << "\ndist2 = "; dist2.showdist();

    dist1 += dist2;                 // add dist2 to dist1

    cout << "\nAfter addition,";
    cout << "\ndist1 = "; dist1.showdist();
    cout << endl;

    return 0;
}

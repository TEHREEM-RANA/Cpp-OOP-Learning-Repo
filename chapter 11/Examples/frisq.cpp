// frisq.cpp
#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) { }
    Distance(int ft, float in) : feet(ft), inches(in) { }

    void showdist() { cout << feet << "\'-" << inches << "\""; }

    friend float square(Distance); // friend function
};

float square(Distance d) {
    float fltfeet = d.feet + d.inches / 12; // convert to float
    return fltfeet * fltfeet; // square in square feet
}

int main() {
    Distance dist(3, 6); // 3'-6"
    float sqft = square(dist); // functional notation
    cout << "\nDistance = "; dist.showdist();
    cout << "\nSquare = " << sqft << " square feet\n";
    return 0;
}

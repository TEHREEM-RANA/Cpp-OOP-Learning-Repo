// Q2.cpp
#include <iostream>
using namespace std;

class Distance {
private:
    float meters;
public:
    // Constructors
    Distance() : meters(0.0f) {}
    Distance(float m) : meters(m) {}  // One-argument constructor

    // Getter and Setter
    void setMeters(float m) { meters = m; }
    float getMeters() { return meters; }

    // Overload * operator as friend
    friend Distance operator*(float factor, const Distance& d);

    void show() {
        cout << meters << " meters" << endl;
    }
};

// Friend function to multiply a float with Distance
Distance operator*(float factor, const Distance& d) {
    return Distance(factor * d.meters);
}

int main() {
    Distance d1(5.0);  // 5 meters
    Distance d2(10.0); // 10 meters

    cout << "Original Distances:\n";
    d1.show();
    d2.show();

    Distance d3 = 2.5 * d1; // Multiply by float
    cout << "\nAfter multiplying 2.5 * d1:\n";
    d3.show();

    Distance d4 = 3 * d2; // Multiply by integer (auto converted to float)
    cout << "\nAfter multiplying 3 * d2:\n";
    d4.show();

    return 0;
}

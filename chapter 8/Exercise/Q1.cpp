// Q1.cpp
// Program: Distance class with overloaded - operator
#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

public:
    // Default constructor
    Distance() : feet(0), inches(0.0) {}

    // Parameterized constructor
    Distance(int f, float i) : feet(f), inches(i) {}

    // Copy constructor
    Distance(const Distance& d) {
        feet = d.feet;
        inches = d.inches;
    }

    // Destructor
    ~Distance() {
        // (No dynamic memory used, so nothing special here)
    }

    // Getter methods
    int getFeet() const { return feet; }
    float getInches() const { return inches; }

    // Setter methods
    void setFeet(int f) { feet = f; }
    void setInches(float i) { inches = i; }

    // Function to display distance
    void display() const {
        cout << feet << "\'-" << inches << "\"";
    }

    // Overloaded - operator
    Distance operator-(Distance d2) const {
        int f = feet - d2.feet;
        float i = inches - d2.inches;

        if (i < 0) {
            i += 12;
            f--;
        }

        return Distance(f, i);
    }
};

int main() {
    Distance dist1(5, 8.5);   // 5 feet 8.5 inches
    Distance dist2(3, 10.2);  // 3 feet 10.2 inches

    cout << "Distance 1 = ";
    dist1.display();
    cout << endl;

    cout << "Distance 2 = ";
    dist2.display();
    cout << endl;

    Distance dist3 = dist1 - dist2;  // Using overloaded - operator

    cout << "After subtraction, Distance 3 = ";
    dist3.display();
    cout << endl;

    return 0;
}

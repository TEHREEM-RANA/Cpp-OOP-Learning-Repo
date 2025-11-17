// *3. Write a program that calculates the average of up to 100 English distances input by the
// user. Create an array of objects of the Distance class, as in the ENGLARAY example in
// this chapter. To calculate the average, you can borrow the add_dist() member function
// from the ENGLCON example in Chapter 6. You’ll also need a member function that divides
// a Distance value by an integer. Here’s one possibility:
// void Distance::div_dist(Distance d2, int divisor)
// {
// float fltfeet = d2.feet + d2.inches/12.0;
// fltfeet /= divisor;
// feet = int(fltfeet);
// inches = (fltfeet-feet) * 12.0;
// }
#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

public:
    // Constructor
    Distance(int f = 0, float i = 0.0) {
        feet = f;
        inches = i;
    }

    // Destructor
    ~Distance() {
        cout << "Destructor called for Distance object\n";
    }

    // Getters
    int getFeet() const { return feet; }
    float getInches() const { return inches; }

    // Setters
    void setFeet(int f) { feet = f; }
    void setInches(float i) { inches = i; }

    // Input data
    void getdist() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // Display data
    void showdist() const {
        cout << feet << "\'-" << inches << "\"";
    }

    // Add two distances
    Distance add_dist(Distance d2) const {
        int f = feet + d2.feet;
        float i = inches + d2.inches;
        if (i >= 12.0) {
            i -= 12.0;
            f++;
        }
        return Distance(f, i);
    }

    // Divide distance by an integer
    void div_dist(Distance d2, int divisor) {
        float fltfeet = d2.feet + d2.inches / 12.0;
        fltfeet /= divisor;
        feet = int(fltfeet);
        inches = (fltfeet - feet) * 12.0;
    }
};

int main() {
    Distance dist[100], total(0, 0), average;
    int count = 0;
    char choice;

    do {
        cout << "\nEnter distance #" << count + 1 << endl;
        dist[count].getdist();
        total = total.add_dist(dist[count]);
        count++;

        cout << "Add another distance? (y/n): ";
        cin >> choice;
    } while ((choice == 'y' || choice == 'Y') && count < 100);

    average.div_dist(total, count);

    cout << "\nAverage distance: ";
    average.showdist();
    cout << endl;

    return 0;
}

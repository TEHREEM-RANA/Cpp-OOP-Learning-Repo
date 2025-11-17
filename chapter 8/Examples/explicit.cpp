#include <iostream>
using namespace std;

class Distance {
private:
    const float MTF;  // meters to feet
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0), MTF(3.280833F) { }

    // EXPLICIT one-arg constructor
    explicit Distance(float meters) : MTF(3.280833F) {
        float fltfeet = MTF * meters;
        feet = int(fltfeet);
        inches = 12 * (fltfeet - feet);
    }

    void showdist() {
        cout << feet << "\'-" << inches << '\"';
    }
};

void fancyDist(Distance d) {
    cout << " (in feet and inches) = ";
    d.showdist();
    cout << endl;
}

int main() {
    Distance dist1(2.35F);   // ✅ allowed
    // Distance dist1 = 2.35F;  // ❌ ERROR (explicit stops this)

    float mtrs = 3.0F;
    // fancyDist(mtrs);  // ❌ ERROR (implicit conversion stopped)

    cout << "dist1 = ";
    dist1.showdist();
    cout << endl;
    return 0;
}

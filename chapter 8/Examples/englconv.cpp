// englconv.cpp
// conversions: Distance to meters, meters to Distance

#include <iostream>
using namespace std;

class Distance {
private:
    const float MTF;   // meters to feet conversion factor
    int feet;
    float inches;
public:
    // constructor (no arguments)
    Distance() : feet(0), inches(0.0), MTF(3.280833F) { }

    // constructor (one argument) → converts meters to Distance
    Distance(float meters) : MTF(3.280833F) {
        float fltfeet = MTF * meters;   // convert meters to feet
        feet = int(fltfeet);            // get the whole feet
        inches = 12 * (fltfeet - feet); // convert remaining part into inches
    }

    // constructor (two arguments)
    Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) { }

    void showdist() const {
        cout << feet << "\'-" << inches << '\"';
    }

    // conversion operator → converts Distance to float (meters)
    operator float() const {
        float fracfeet = inches / 12;               // convert inches to feet
        fracfeet += static_cast<float>(feet);       // add total feet
        return fracfeet / MTF;                      // convert feet to meters
    }
};

int main() {
    float mtrs;

    Distance dist1 = 2.35F;  // uses constructor to convert meters → Distance
    cout << "\ndist1 = "; dist1.showdist();

    mtrs = static_cast<float>(dist1);  // uses conversion operator
    cout << "\ndist1 = " << mtrs << " meters\n";

    Distance dist2(5, 10.25); // 5 feet 10.25 inches
    mtrs = dist2;             // also uses conversion operator
    cout << "\ndist2 = " << mtrs << " meters\n";

    return 0;
}
// | Conversion Type | How It's Done                  | Example              |
// | --------------- | ------------------------------ | -------------------- |
// | Basic → Basic   | Compiler handles automatically | `int x = 3.5;`       |
// | Basic → Class   | Use a **constructor**          | `Distance d = 2.35;` |
// | Class → Basic   | Use a **conversion operator**  | `float m = dist1;`   |
// class Distance {
// private:
//     const float MTF; // meters to feet
//     int feet;
//     float inches;

// public:
//     Distance() : feet(0), inches(0.0), MTF(3.280833F) {}
//     Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) {}

//     // 👇 Conversion operator
//     operator float() {
//         float fracfeet = inches / 12;
//         fracfeet += float(feet);
//         return fracfeet / MTF;
//     }
// };

// int main() {
//     Distance dist2(5, 10.25);
//     float meters;

//     meters = static_cast<float>(dist2); // explicit
//     cout << meters << " meters\n";

//     meters = dist2; // implicit
//     cout << meters << " meters\n";
// }

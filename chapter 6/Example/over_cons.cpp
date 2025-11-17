# include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;
public:
    // default constructor (no arguments)
    Distance() : feet(0), inches(0.0) { }

    // constructor with two arguments
    Distance(int ft, float in) : feet(ft), inches(in) { }

    void showdist() {
        cout << feet << "'-" << inches << "\"";
    }
};

int main() {
    Distance d1;           // calls default constructor
    Distance d2(11, 6.25); // calls two-arg constructor

    cout << "\nd1 = "; d1.showdist();
    cout << "\nd2 = "; d2.showdist();
    return 0;
}

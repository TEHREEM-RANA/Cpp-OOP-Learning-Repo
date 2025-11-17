# include <iostream>
using namespace std;
class Distance {
private:
    int feet;
    float inches;
public:
    Distance(int ft, float in) : feet(ft), inches(in) { }
    void showdist() { cout << feet << "'-" << inches << "\""; }
};

int main() {
    Distance dist1(11, 6.25);
    Distance dist2(dist1);   // copy constructor
    Distance dist3 = dist1;  // also copy constructor

    cout << "\ndist1 = "; dist1.showdist();
    cout << "\ndist2 = "; dist2.showdist();
    cout << "\ndist3 = "; dist3.showdist();

    return 0;
}
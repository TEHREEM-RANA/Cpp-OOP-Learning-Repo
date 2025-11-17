# include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) { }
    Distance(int ft, float in) : feet(ft), inches(in) { }

    void showdist();
    void add_dist(Distance d1, Distance d2); // only declared here
};

// defined outside class
void Distance::showdist() {
    cout << feet << "'-" << inches << "\"";
}

void Distance::add_dist(Distance d1, Distance d2) {
    inches = d1.inches + d2.inches;
    feet = 0;
    if (inches >= 12.0) {
        inches -= 12.0;
        feet++;
    }
    feet += d1.feet + d2.feet;
}

int main() {
    Distance dist1(11, 6.25);
    Distance dist2(17, 5.75);
    Distance dist3;

    dist3.add_dist(dist1, dist2);

    cout << "\ndist1 = "; dist1.showdist();
    cout << "\ndist2 = "; dist2.showdist();
    cout << "\ndist3 = "; dist3.showdist();
    return 0;
}

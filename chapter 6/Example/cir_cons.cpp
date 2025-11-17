#include <iostream>
using namespace std;
class circle {
protected:
    int xCo, yCo;     // coordinates
    int radius;
    string color;
    string fillstyle;

public:
    // constructor with parameters
    circle(int x, int y, int r, string c, string fs) 
        : xCo(x), yCo(y), radius(r), color(c), fillstyle(fs) { }

    void showCircle() {
        cout << "Circle at (" << xCo << "," << yCo << ") "
             << "Radius: " << radius 
             << " Color: " << color 
             << " Fill: " << fillstyle << endl;
    }
};

int main() {
    circle c1(15, 7, 5, "Blue", "Solid");
    circle c2(41, 12, 7, "Red", "Outline");
    circle c3(65, 18, 4, "Green", "Medium");

    c1.showCircle();
    c2.showCircle();
    c3.showCircle();
}

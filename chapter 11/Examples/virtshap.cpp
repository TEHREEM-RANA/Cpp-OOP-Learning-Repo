// virtshap.cpp
#include <iostream>
using namespace std;

// Assume graphics functions are defined in msoftcon.h
class shape {
protected:
    int xCo, yCo;
public:
    shape() : xCo(0), yCo(0) { }
    virtual void draw() = 0; // pure virtual function
};

class ball : public shape {
private:
    int radius;
public:
    ball(int x, int y, int r) : radius(r) { xCo = x; yCo = y; }
    void draw() { cout << "Draw ball at (" << xCo << "," << yCo << ") with radius " << radius << endl; }
};

class rect : public shape {
private:
    int width, height;
public:
    rect(int x, int y, int w, int h) : width(w), height(h) { xCo = x; yCo = y; }
    void draw() { cout << "Draw rectangle at (" << xCo << "," << yCo << ") size " << width << "x" << height << endl; }
};

int main() {
    shape* pShapes[2];
    pShapes[0] = new ball(10, 5, 3);
    pShapes[1] = new rect(2, 3, 4, 5);

    for(int j=0; j<2; j++)
        pShapes[j]->draw();

    for(int j=0; j<2; j++)
        delete pShapes[j];

    return 0;
}

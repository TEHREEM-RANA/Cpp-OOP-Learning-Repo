// This code will only work if you have the graphics library (msoftcon.h) that provides:
/*# include <iostream>
using namespace std;
class circle   // graphics circle
{
protected:
    int xCo, yCo;     // center position
    int radius;       // size
    color fillcolor;  // color
    fstyle fillstyle; // fill pattern

public:
    void set(int x, int y, int r, color fc, fstyle fs)
    {
        xCo = x;
        yCo = y;
        radius = r;
        fillcolor = fc;
        fillstyle = fs;
    }

    void draw()
    {
        set_color(fillcolor);      
        set_fill_style(fillstyle); 
        draw_circle(xCo, yCo, radius);  
    }
};

int main()
{
circle c1, c2, c3;   // three circle objects

c1.set(15, 7, 5, cBLUE, X_FILL);
c2.set(41, 12, 7, cRED, O_FILL);
c3.set(65, 18, 4, cGREEN, MEDIUM_FILL);

c1.draw();   // draws blue circle
c2.draw();   // draws red circle
c3.draw();   // draws green circle

    

    return 0;
}*/
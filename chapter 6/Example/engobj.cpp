#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////
// English Distance class
class Distance
{
private:
    int feet;       // whole feet
    float inches;   // fractional inches

public:
    // set Distance using given values
    void setdist(int ft, float in)
    {
        feet = ft;
        inches = in;
    }

    // get Distance from user input
    void getdist()
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // display Distance
    void showdist()
    {
        cout << feet << "\'-" << inches << '\"';
    }
};
//////////////////////////////////////////////////////////////

int main()
{
    Distance dist1, dist2;   // define two Distance objects

    // set dist1 manually
    dist1.setdist(11, 6.25);

    // get dist2 from user
    dist2.getdist();

    // display both distances
    cout << "\ndist1 = ";
    dist1.showdist();

    cout << "\ndist2 = ";
    dist2.showdist();

    cout << endl;
    return 0;
}

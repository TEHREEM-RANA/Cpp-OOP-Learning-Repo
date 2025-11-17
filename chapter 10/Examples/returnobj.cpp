// returnobj.cpp
// Demonstration of returning object from a function
#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    // Constructor
    Distance(int f = 0, float i = 0.0)
    {
        feet = f;
        inches = i;
    }

    // Function to display distance
    void showDistance()
    {
        cout << feet << " feet " << inches << " inches" << endl;
    }

    // Function to add two Distance objects and return new one
    Distance addDistance(Distance d)
    {
        Distance temp;
        temp.inches = inches + d.inches;
        temp.feet = feet + d.feet;

        // Adjust if inches >= 12
        if (temp.inches >= 12.0)
        {
            temp.inches -= 12.0;
            temp.feet++;
        }

        return temp;  // returning object
    }
};

int main()
{
    Distance d1(5, 9.5);
    Distance d2(3, 11.0);

    Distance d3; // empty object

    d3 = d1.addDistance(d2); // function returns object

    cout << "Sum of distances = ";
    d3.showDistance();

    return 0;
}

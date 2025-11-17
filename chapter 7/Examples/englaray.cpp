// englaray.cpp
// objects using English measurements

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
class Distance  // English Distance class
{
private:
    int feet;
    float inches;

public:
    void getdist()  // get distance from user
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void showdist() const  // display distance
    {
        cout << feet << "\'-" << inches << '\"';
    }
};
////////////////////////////////////////////////////////////////

int main()
{
    Distance dist[100];  // array of Distance objects
    int n = 0;           // number of distances entered
    char ans;            // user response ('y' or 'n')

    cout << endl;
    do {
        cout << "Enter distance number " << n + 1 << endl;
        dist[n++].getdist();       // take input for object n
        cout << "Enter another (y/n)?: ";
        cin >> ans;
    } while (ans != 'n');          // repeat until user says 'n'

    // display all distances entered
    for (int j = 0; j < n; j++)
    {
        cout << "\nDistance number " << j + 1 << " is ";
        dist[j].showdist();
    }

    cout << endl;
    return 0;
}

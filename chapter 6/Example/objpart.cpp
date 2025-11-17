# include <iostream>
using namespace std;
class part   // define class
{
private:
    int modelnumber;   // model ID
    int partnumber;    // part ID
    float cost;        // price

public:
    void setpart(int mn, int pn, float c)  // assign values
    {
        modelnumber = mn;
        partnumber = pn;
        cost = c;
    }

    void showpart()   // display values
    {
        cout << "Model " << modelnumber;
        cout << ", part " << partnumber;
        cout << ", costs $" << cost << endl;
    }
};
int main(){
    part part1;   // create an object (like a real widget)
part1.setpart(6244, 373, 217.55F);  // set details
part1.showpart();                   // display details
return 0;
}
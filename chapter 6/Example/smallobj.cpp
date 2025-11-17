# include <iostream>
using namespace std;
class smallobj //define a class
{
private:
    int somedata; // class data (variable)
public:
    void setdata(int d)  // function to set value
    { somedata = d; }

    void showdata()  // function to display value
    { cout << "Data is " << somedata << endl; }
};
int main()
{
    smallobj s1, s2;  // create two objects (like two cookies from one cutter)

    s1.setdata(1066); // set value for s1
    s2.setdata(1776); // set value for s2

    s1.showdata(); // prints "Data is 1066"
    s2.showdata(); // prints "Data is 1776"

    return 0;
}

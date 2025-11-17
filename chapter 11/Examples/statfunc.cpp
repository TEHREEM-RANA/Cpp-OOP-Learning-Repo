// statfunc.cpp
#include <iostream>
using namespace std;

class Gamma {
private:
    static int total; // static data shared by all objects
    int id;           // unique for each object
public:
    Gamma() { total++; id = total; }     // constructor
    ~Gamma() { total--; cout << "Destroying ID number " << id << endl; } // destructor

    static void showTotal() { cout << "Total is " << total << endl; } // static function
    void showID() { cout << "ID number is " << id << endl; }          // non-static function
};

int Gamma::total = 0; // definition of static variable

int main() {
    Gamma g1;
    Gamma::showTotal();

    Gamma g2, g3;
    Gamma::showTotal();

    g1.showID();
    g2.showID();
    g3.showID();

    cout << "----------end of program----------\n";
    return 0;
}

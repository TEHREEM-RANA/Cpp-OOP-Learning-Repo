// englmult.cpp
// multiple inheritance with English Distances

#include <iostream>
#include <string>
using namespace std;

//--------------------------------------------------------------
// Base class: Type (represents kind of lumber)
//--------------------------------------------------------------
class Type
{
private:
    string dimensions; // e.g., "2x4"
    string grade;      // e.g., "construction"

public:
    // No-argument constructor
    Type() : dimensions("N/A"), grade("N/A") { }

    // 2-argument constructor
    Type(string di, string gr) : dimensions(di), grade(gr) { }

    void gettype()
    {
        cout << "Enter nominal dimensions (2x4 etc.): ";
        cin >> dimensions;
        cout << "Enter grade (rough, const, etc.): ";
        cin >> grade;
    }

    void showtype() const
    {
        cout << "\nDimensions: " << dimensions;
        cout << "\nGrade: " << grade;
    }
};

//--------------------------------------------------------------
// Base class: Distance (represents length of lumber)
//--------------------------------------------------------------
class Distance
{
private:
    int feet;
    float inches;

public:
    // No-argument constructor
    Distance() : feet(0), inches(0.0) { }

    // 2-argument constructor
    Distance(int ft, float in) : feet(ft), inches(in) { }

    void getdist()
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void showdist() const
    {
        cout << feet << "'-" << inches << "\"";
    }
};

//--------------------------------------------------------------
// Derived class: Lumber (inherits from Type and Distance)
//--------------------------------------------------------------
class Lumber : public Type, public Distance
{
private:
    int quantity;  // number of pieces
    double price;  // price per piece

public:
    // No-argument constructor
    Lumber() : Type(), Distance(), quantity(0), price(0.0) { }

    // Constructor with 6 arguments
    Lumber(string di, string gr, int ft, float in, int qu, float prc)
        : Type(di, gr), Distance(ft, in), quantity(qu), price(prc)
    { }

    void getlumber()
    {
        Type::gettype();
        Distance::getdist();
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price per piece: ";
        cin >> price;
    }

    void showlumber() const
    {
        Type::showtype();
        cout << "\nLength: ";
        Distance::showdist();
        cout << "\nPrice for " << quantity << " pieces: $" << price * quantity;
    }
};

//--------------------------------------------------------------
// main()
//--------------------------------------------------------------
int main()
{
    Lumber siding; // uses no-arg constructor
    cout << "\nSiding data:\n";
    siding.getlumber();

    Lumber studs("2x4", "const", 8, 0.0, 200, 4.45F); // 6-arg constructor

    cout << "\nSiding";
    siding.showlumber();

    cout << "\nStuds";
    studs.showlumber();

    cout << endl;
    return 0;
}

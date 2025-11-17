// Q4.cpp
#include <iostream>
#include <string>
using namespace std;

// ---------- Base Class: publication ----------
class publication {
private:
    string title;
    float price;

public:
    // Default Constructor
    publication() : title(""), price(0.0) {}

    // Parameterized Constructor
    publication(string t, float p) : title(t), price(p) {}

    // Destructor
    ~publication() {}

    // Setter and Getter for Title
    void setTitle(string t) { title = t; }
    string getTitle() const { return title; }

    // Setter and Getter for Price
    void setPrice(float p) { price = p; }
    float getPrice() const { return price; }

    // Input Function
    void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();
    }

    // Output Function
    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

// ---------- Derived Class: book ----------
class book : public publication {
private:
    int pageCount;

public:
    // Default Constructor
    book() : publication(), pageCount(0) {}

    // Parameterized Constructor
    book(string t, float p, int pc) : publication(t, p), pageCount(pc) {}

    // Destructor
    ~book() {}

    // Input Function
    void getdata() {
        publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
        cin.ignore();
    }

    // Output Function
    void putdata() const {
        publication::putdata();
        cout << "Page Count: " << pageCount << endl;
    }
};

// ---------- Derived Class: tape ----------
class tape : public publication {
private:
    float playTime;

public:
    // Default Constructor
    tape() : publication(), playTime(0.0) {}

    // Parameterized Constructor
    tape(string t, float p, float pt) : publication(t, p), playTime(pt) {}

    // Destructor
    ~tape() {}

    // Input Function
    void getdata() {
        publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playTime;
        cin.ignore();
    }

    // Output Function
    void putdata() const {
        publication::putdata();
        cout << "Playing Time: " << playTime << " minutes" << endl;
    }
};

// ---------- Derived Class: disk ----------
class disk : public publication {
public:
    enum dtype { CD, DVD }; // enumeration for disk type

private:
    dtype diskType; // either CD or DVD

public:
    // Default Constructor
    disk() : publication(), diskType(CD) {}

    // Parameterized Constructor
    disk(string t, float p, dtype dt) : publication(t, p), diskType(dt) {}

    // Destructor
    ~disk() {}

    // Input Function
    void getdata() {
        publication::getdata();
        char ch;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> ch;
        cin.ignore();
        if (ch == 'c' || ch == 'C')
            diskType = CD;
        else if (ch == 'd' || ch == 'D')
            diskType = DVD;
        else {
            cout << "Invalid input! Defaulting to CD.\n";
            diskType = CD;
        }
    }

    // Output Function
    void putdata() const {
        publication::putdata();
        cout << "Disk Type: ";
        if (diskType == CD)
            cout << "CD" << endl;
        else
            cout << "DVD" << endl;
    }
};

// ---------- Main Function ----------
int main() {
    book b1;
    tape t1;
    disk d1;

    cout << "Enter book details:\n";
    b1.getdata();

    cout << "\nEnter tape details:\n";
    t1.getdata();

    cout << "\nEnter disk details:\n";
    d1.getdata();

    cout << "\n--- Book Details ---\n";
    b1.putdata();

    cout << "\n--- Tape Details ---\n";
    t1.putdata();

    cout << "\n--- Disk Details ---\n";
    d1.putdata();

    return 0;
}

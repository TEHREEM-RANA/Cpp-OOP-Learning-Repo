// Q1.cpp
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

    // Getter and Setter for Title
    void setTitle(string t) { title = t; }
    string getTitle() const { return title; }

    // Getter and Setter for Price
    void setPrice(float p) { price = p; }
    float getPrice() const { return price; }

    // Input Function
    void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore(); // clear buffer
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

    // Getter and Setter for pageCount
    void setPageCount(int pc) { pageCount = pc; }
    int getPageCount() const { return pageCount; }

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
    float playTime; // in minutes

public:
    // Default Constructor
    tape() : publication(), playTime(0.0) {}

    // Parameterized Constructor
    tape(string t, float p, float pt) : publication(t, p), playTime(pt) {}

    // Destructor
    ~tape() {}

    // Getter and Setter for playTime
    void setPlayTime(float pt) { playTime = pt; }
    float getPlayTime() const { return playTime; }

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

// ---------- Main Function ----------
int main() {
    book b1;
    tape t1;

    cout << "Enter book details:\n";
    b1.getdata();

    cout << "\nEnter tape details:\n";
    t1.getdata();

    cout << "\n--- Book Details ---\n";
    b1.putdata();

    cout << "\n--- Tape Details ---\n";
    t1.putdata();

    return 0;
}

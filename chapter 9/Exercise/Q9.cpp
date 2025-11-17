// Q9.cpp
#include <iostream>
#include <string>
using namespace std;

// ---------- Date Class ----------
class date {
private:
    int day, month, year;

public:
    // Default Constructor
    date() : day(1), month(1), year(2000) {}

    // Parameterized Constructor
    date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Destructor
    ~date() {}

    // Input
    void getdate() {
        cout << "Enter publication date (day month year): ";
        cin >> day >> month >> year;
    }

    // Display
    void showdate() const {
        cout << day << "/" << month << "/" << year;
    }
};

// ---------- Base Class: publication ----------
class publication {
protected:
    string title;
    float price;

public:
    // Default Constructor
    publication() : title(""), price(0.0) {}

    // Parameterized Constructor
    publication(string t, float p) : title(t), price(p) {}

    // Destructor
    ~publication() {}

    // Input
    virtual void getdata() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    // Display
    virtual void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

// ---------- Derived Class: publication2 (adds date) ----------
class publication2 : public publication {
protected:
    date pubDate;

public:
    // Default Constructor
    publication2() : publication(), pubDate() {}

    // Destructor
    ~publication2() {}

    // Input
    void getdata() override {
        publication::getdata();
        pubDate.getdate();
    }

    // Display
    void putdata() const override {
        publication::putdata();
        cout << "Publication Date: ";
        pubDate.showdate();
        cout << endl;
    }
};

// ---------- Derived Class: book ----------
class book : public publication2 {
private:
    int pageCount;

public:
    // Default Constructor
    book() : publication2(), pageCount(0) {}

    // Destructor
    ~book() {}

    // Input
    void getdata() override {
        publication2::getdata();
        cout << "Enter number of pages: ";
        cin >> pageCount;
    }

    // Display
    void putdata() const override {
        publication2::putdata();
        cout << "Page Count: " << pageCount << endl;
    }
};

// ---------- Derived Class: tape ----------
class tape : public publication2 {
private:
    float playTime; // in minutes

public:
    // Default Constructor
    tape() : publication2(), playTime(0.0) {}

    // Destructor
    ~tape() {}

    // Input
    void getdata() override {
        publication2::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playTime;
    }

    // Display
    void putdata() const override {
        publication2::putdata();
        cout << "Playing Time: " << playTime << " minutes" << endl;
    }
};

// ---------- Main Function ----------
int main() {
    book b1;
    tape t1;

    cout << "\n--- Enter Book Details ---" << endl;
    b1.getdata();

    cout << "\n--- Enter Tape Details ---" << endl;
    t1.getdata();

    cout << "\n=============================" << endl;
    cout << "--- Book Information ---" << endl;
    b1.putdata();

    cout << "\n--- Tape Information ---" << endl;
    t1.putdata();

    return 0;
}

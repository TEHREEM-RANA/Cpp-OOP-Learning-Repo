// Q8.cpp
#include <iostream>
#include <string>
using namespace std;

// ---------- Base Class: student ----------
class student {
protected:
    string name;
    int rollNo;

public:
    // Default constructor
    student() : name(""), rollNo(0) {}

    // Parameterized constructor
    student(string n, int r) : name(n), rollNo(r) {}

    // Destructor
    ~student() {}

    // Input data
    void getStudentData() {
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore(); // clear buffer
    }

    // Display data
    void showStudentData() const {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
    }
};

// ---------- Derived Class: science ----------
class science : virtual public student {
protected:
    float physics, chemistry;

public:
    // Default constructor
    science() : physics(0), chemistry(0) {}

    // Destructor
    ~science() {}

    // Input data
    void getScienceMarks() {
        cout << "Enter Physics Marks: ";
        cin >> physics;
        cout << "Enter Chemistry Marks: ";
        cin >> chemistry;
    }

    // Display data
    void showScienceMarks() const {
        cout << "Physics: " << physics << endl;
        cout << "Chemistry: " << chemistry << endl;
    }
};

// ---------- Derived Class: arts ----------
class arts : virtual public student {
protected:
    float history, english;

public:
    // Default constructor
    arts() : history(0), english(0) {}

    // Destructor
    ~arts() {}

    // Input data
    void getArtsMarks() {
        cout << "Enter History Marks: ";
        cin >> history;
        cout << "Enter English Marks: ";
        cin >> english;
    }

    // Display data
    void showArtsMarks() const {
        cout << "History: " << history << endl;
        cout << "English: " << english << endl;
    }
};

// ---------- Derived Class: result ----------
class result : public science, public arts {
private:
    float total, average;

public:
    // Default constructor
    result() : total(0), average(0) {}

    // Destructor
    ~result() {}

    // Calculate total and average
    void calculate() {
        total = physics + chemistry + history + english;
        average = total / 4.0;
    }

    // Display result
    void showResult() const {
        cout << "\n--- Result ---" << endl;
        showStudentData();
        showScienceMarks();
        showArtsMarks();
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
    }
};

// ---------- Main Function ----------
int main() {
    result r1;

    cout << "--- Enter Student Details ---" << endl;
    r1.getStudentData();

    cout << "\n--- Enter Science Marks ---" << endl;
    r1.getScienceMarks();

    cout << "\n--- Enter Arts Marks ---" << endl;
    r1.getArtsMarks();

    r1.calculate();

    cout << "\n===============================" << endl;
    r1.showResult();

    return 0;
}

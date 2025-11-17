// Q11.cpp
// Program: Time class with overloaded - and * operators
#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Default constructor
    Time() : hours(0), minutes(0), seconds(0) {}

    // Parameterized constructor
    Time(int h, int m, int s) {
        setTime(h, m, s);
    }

    // Copy constructor
    Time(const Time& t) {
        hours = t.hours;
        minutes = t.minutes;
        seconds = t.seconds;
    }

    // Destructor
    ~Time() {
        // No dynamic memory used
    }

    // Setter
    void setTime(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
        normalize();
    }

    // Getter
    void getTime() const {
        cout << hours << ":" << minutes << ":" << seconds;
    }

    // Normalize to keep time valid
    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        } else if (seconds < 0) {
            seconds += 60;
            minutes--;
        }

        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        } else if (minutes < 0) {
            minutes += 60;
            hours--;
        }

        if (hours >= 24) hours %= 24;
        if (hours < 0) hours += 24;
    }

    // Overloaded - operator (subtract two Time objects)
    Time operator-(const Time& t2) const {
        long totalSec1 = hours * 3600 + minutes * 60 + seconds;
        long totalSec2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
        long diff = totalSec1 - totalSec2;
        if (diff < 0) diff = 0; // avoid negative time

        Time temp;
        temp.hours = diff / 3600;
        diff %= 3600;
        temp.minutes = diff / 60;
        temp.seconds = diff % 60;
        return temp;
    }

    // Overloaded * operator (multiply time by float)
    Time operator*(float factor) const {
        long totalSec = hours * 3600 + minutes * 60 + seconds;
        totalSec = static_cast<long>(totalSec * factor);

        Time temp;
        temp.hours = totalSec / 3600;
        totalSec %= 3600;
        temp.minutes = totalSec / 60;
        temp.seconds = totalSec % 60;
        temp.normalize();
        return temp;
    }

    // Display in HH:MM:SS format
    void display() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds;
    }
};

// Main function
int main() {
    Time t1(4, 20, 30);
    Time t2(2, 10, 20);

    cout << "First time: ";
    t1.display();
    cout << "\nSecond time: ";
    t2.display();

    // Subtraction
    Time t3 = t1 - t2;
    cout << "\n\nAfter subtraction (t1 - t2): ";
    t3.display();

    // Multiplication
    Time t4 = t1 * 1.5;
    cout << "\nAfter multiplying t1 * 1.5: ";
    t4.display();

    cout << endl;
    return 0;
}

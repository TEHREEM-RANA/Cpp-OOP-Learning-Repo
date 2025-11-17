// Q5.cpp
// Program: Time class with overloaded ++ and -- operators (prefix and postfix)
#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    // Normalize the time values
    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
        if (seconds < 0) {
            seconds += 60;
            minutes--;
        }
        if (minutes < 0) {
            minutes += 60;
            hours--;
        }
        if (hours < 0)
            hours = minutes = seconds = 0;
    }

public:
    // Constructors
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    // Destructor
    ~Time() {}

    // Getters
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }

    // Setters
    void setHours(int h) { hours = h; }
    void setMinutes(int m) { minutes = m; }
    void setSeconds(int s) { seconds = s; normalize(); }

    // Input and display
    void getTime() {
        cout << "Enter hours, minutes, and seconds: ";
        cin >> hours >> minutes >> seconds;
        normalize();
    }

    void showTime() const {
        cout << hours << "h:" << minutes << "m:" << seconds << "s";
    }

    // Prefix ++
    Time operator++() {
        seconds++;
        normalize();
        return *this;
    }

    // Postfix ++
    Time operator++(int) {
        Time temp = *this;
        seconds++;
        normalize();
        return temp;
    }

    // Prefix --
    Time operator--() {
        seconds--;
        normalize();
        return *this;
    }

    // Postfix --
    Time operator--(int) {
        Time temp = *this;
        seconds--;
        normalize();
        return temp;
    }
};

int main() {
    Time t1;
    cout << "Enter time: " << endl;
    t1.getTime();

    cout << "\nOriginal time: ";
    t1.showTime();

    cout << "\n\nAfter prefix ++: ";
    (++t1).showTime();

    cout << "\nAfter postfix ++: ";
    (t1++).showTime();
    cout << " (then time becomes: ";
    t1.showTime();
    cout << ")";

    cout << "\n\nAfter prefix --: ";
    (--t1).showTime();

    cout << "\nAfter postfix --: ";
    (t1--).showTime();
    cout << " (then time becomes: ";
    t1.showTime();
    cout << ")\n";

    return 0;
}

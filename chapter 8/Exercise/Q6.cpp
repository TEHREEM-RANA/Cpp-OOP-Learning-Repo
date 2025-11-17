// Q6.cpp
// Program: Time class with overloaded - and * operators
#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    // Normalize time (convert overflow or underflow)
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

    // Overloaded - operator (subtract two times)
    Time operator-(const Time& t) const {
        long total1 = hours * 3600 + minutes * 60 + seconds;
        long total2 = t.hours * 3600 + t.minutes * 60 + t.seconds;

        if (total1 < total2) {
            cout << "\n⚠️ Negative time not allowed! Returning zero time.\n";
            return Time(0, 0, 0);
        }

        long diff = total1 - total2;
        int h = diff / 3600;
        int m = (diff % 3600) / 60;
        int s = diff % 60;

        return Time(h, m, s);
    }

    // Overloaded * operator (multiply by float)
    Time operator*(float factor) const {
        long totalSeconds = hours * 3600 + minutes * 60 + seconds;
        totalSeconds = static_cast<long>(totalSeconds * factor);

        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;

        return Time(h, m, s);
    }
};

int main() {
    Time t1, t2, t3;
    float f;

    cout << "Enter first time:\n";
    t1.getTime();

    cout << "Enter second time:\n";
    t2.getTime();

    cout << "\nSubtracting times...\n";
    t3 = t1 - t2;
    cout << "Result of subtraction: ";
    t3.showTime();

    cout << "\n\nEnter multiplication factor (float): ";
    cin >> f;

    t3 = t1 * f;
    cout << "Result of multiplication: ";
    t3.showTime();

    cout << endl;
    return 0;
}


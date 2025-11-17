// Q10.cpp
// Program: Time class with overloaded increment and decrement operators (++ and --)
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
        // No dynamic memory, so nothing special here
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

    // Normalize time (to handle overflow/underflow)
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

    // Overloaded prefix increment ++t
    Time operator++() {
        ++seconds;
        normalize();
        return *this;
    }

    // Overloaded postfix increment t++
    Time operator++(int) {
        Time temp = *this;
        ++seconds;
        normalize();
        return temp;
    }

    // Overloaded prefix decrement --t
    Time operator--() {
        --seconds;
        normalize();
        return *this;
    }

    // Overloaded postfix decrement t--
    Time operator--(int) {
        Time temp = *this;
        --seconds;
        normalize();
        return temp;
    }

    // Display time in HH:MM:SS format
    void display() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds;
    }
};

int main() {
    Time t1(10, 59, 58);

    cout << "Initial time: ";
    t1.display();
    cout << endl;

    cout << "\nUsing prefix ++t1: ";
    ++t1;
    t1.display();

    cout << "\nUsing postfix t1++: ";
    t1++;
    t1.display();

    cout << "\nUsing prefix --t1: ";
    --t1;
    t1.display();

    cout << "\nUsing postfix t1--: ";
    t1--;
    t1.display();

    cout << endl;
    return 0;
}

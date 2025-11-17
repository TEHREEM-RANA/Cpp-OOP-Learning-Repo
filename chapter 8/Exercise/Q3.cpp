// Q3.cpp
// Program: Time class with overloaded + operator
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
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Destructor
    ~Time() {}

    // Getter functions
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }

    // Setter function
    void setTime(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // Display function
    void display() const {
        cout << hours << ":" << (minutes < 10 ? "0" : "") << minutes 
             << ":" << (seconds < 10 ? "0" : "") << seconds;
    }

    // Overloaded + operator
    Time operator+(const Time& t) const {
        Time temp;
        temp.seconds = seconds + t.seconds;
        temp.minutes = minutes + t.minutes + (temp.seconds / 60);
        temp.seconds %= 60;
        temp.hours = hours + t.hours + (temp.minutes / 60);
        temp.minutes %= 60;
        return temp;
    }
};

int main() {
    Time t1(2, 45, 50);
    Time t2(1, 30, 30);

    cout << "First time: ";
    t1.display();
    cout << "\nSecond time: ";
    t2.display();

    // Using overloaded + operator
    Time t3 = t1 + t2;

    cout << "\n\nSum of times: ";
    t3.display();
    cout << endl;

    return 0;
}

// times2.cpp
// Converts from time24 to time12 using constructor in time12

#include <iostream>
#include <string>
using namespace std;

//-------------------- time24 class --------------------
class time24 {
private:
    int hours, minutes, seconds;
public:
    time24() : hours(0), minutes(0), seconds(0) { }
    time24(int h, int m, int s) : hours(h), minutes(m), seconds(s) { }

    void display() const {
        if (hours < 10) cout << '0';
        cout << hours << ':';
        if (minutes < 10) cout << '0';
        cout << minutes << ':';
        if (seconds < 10) cout << '0';
        cout << seconds;
    }

    // Getter functions (to access private data)
    int getHrs() const { return hours; }
    int getMins() const { return minutes; }
    int getSecs() const { return seconds; }
};

//-------------------- time12 class --------------------
class time12 {
private:
    bool pm;
    int hrs, mins;
public:
    time12() : pm(true), hrs(0), mins(0) { }
    time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m) { }

    // Conversion constructor
    time12(time24 t24) {
        int hrs24 = t24.getHrs();
        pm = (t24.getHrs() < 12) ? false : true;
        mins = (t24.getSecs() < 30) ? t24.getMins() : t24.getMins() + 1;

        if (mins == 60) {
            mins = 0;
            ++hrs24;
            if (hrs24 == 12 || hrs24 == 24)
                pm = (pm == true) ? false : true;
        }

        hrs = (hrs24 < 13) ? hrs24 : hrs24 - 12;
        if (hrs == 0) { hrs = 12; pm = false; }
    }

    void display() const {
        cout << hrs << ':';
        if (mins < 10) cout << '0';
        cout << mins << ' ';
        string am_pm = pm ? "p.m." : "a.m.";
        cout << am_pm;
    }
};

//-------------------- main() --------------------
int main() {
    int h, m, s;
    while (true) {
        cout << "Enter 24-hour time:\n";
        cout << " Hours (0 to 23): "; cin >> h;
        if (h > 23) return 1;
        cout << " Minutes: "; cin >> m;
        cout << " Seconds: "; cin >> s;

        time24 t24(h, m, s);
        cout << "You entered: ";
        t24.display();

        time12 t12 = t24;  // conversion via constructor
        cout << "\n12-hour time: ";
        t12.display();
        cout << "\n\n";
    }
    return 0;
}
// | Feature    | Conversion Operator (Source)    | One-Argument Constructor (Destination) |
// | ---------- | ------------------------------- | -------------------------------------- |
// | Defined In | Source class                    | Destination class                      |
// | Syntax     | `operator DestinationType()`    | `DestinationType(SourceType)`          |
// | Used When  | You can modify the source class | You can only modify destination class  |
// | Example    | `operator time12()` in `time24` | `time12(time24)` in `time12`           |
// | Purpose    | Source object converts itself   | Destination object builds from source  |

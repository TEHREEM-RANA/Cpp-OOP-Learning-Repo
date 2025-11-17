/*5. Start with the date structure in Exercise 5 in Chapter 4 and transform it into a date
class. Its member data should consist of three ints: month, day, and year. It should also
have two member functions: getdate(), which allows the user to enter a date in
12/31/02 format, and showdate(), which displays the date.*/
#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    ~Date() {
        cout << "Destructor called (Date)\n";
    }

    void getDate() {
        char ch; // to read '/'
        cout << "Enter date (dd/mm/yyyy): ";
        cin >> day >> ch >> month >> ch >> year;
    }

    void showDate() {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    Date d;
    d.getDate();
    cout << "Entered date is: ";
    d.showDate();
    return 0;
}

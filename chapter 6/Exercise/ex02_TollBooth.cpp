/*Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50 cent
toll. Mostly they do, but sometimes a car goes by without paying. The tollbooth keeps
track of the number of cars that have gone by, and of the total amount of money collected.
Model this tollbooth with a class called tollBooth. The two data items are a type
unsigned int to hold the total number of cars, and a type double to hold the total amount
of money collected. A constructor initializes both of these to 0. A member function called
payingCar() increments the car total and adds 0.50 to the cash total. Another function,
called nopayCar(), increments the car total but adds nothing to the cash total. Finally, a
member function called display() displays the two totals. Make appropriate member
functions const.
Include a program to test this class. This program should allow the user to push one key
to count a paying car, and another to count a nonpaying car. Pushing the Esc key should
cause the program to print out the total cars and total cash and then exit.*/
#include <iostream>
using namespace std;

class TollBooth {
private:
    unsigned int totalCars;
    double totalCash;
public:
    TollBooth() : totalCars(0), totalCash(0.0) {}

    ~TollBooth() {
        cout << "Destructor called (TollBooth)\n";
    }

    void payingCar() {
        totalCars++;
        totalCash += 0.5;
    }

    void noPayCar() {
        totalCars++;
    }

    void display() {
        cout << "Total cars = " << totalCars << endl;
        cout << "Total cash = $" << totalCash << endl;
    }
};

int main() {
    TollBooth t;
    char choice;
    cout << "Press p = paying car, n = no pay, e = exit\n";
    do {
        cin >> choice;
        if(choice == 'p') t.payingCar();
        else if(choice == 'n') t.noPayCar();
    } while(choice != 'e');
    t.display();
    return 0;
}

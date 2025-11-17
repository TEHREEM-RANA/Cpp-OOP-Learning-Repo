/*10. Create a class called ship that incorporates a ship’s number and location. Use the
approach of Exercise 8 to number each ship object as it is created. Use two variables of
the angle class from Exercise 7 to represent the ship’s latitude and longitude. A member
function of the ship class should get a position from the user and store it in the object;
another should report the serial number and position. Write a main() program that creates three ships, asks the user to input the position of each, and then displays each ship’s
number and position.*/
#include <iostream>
using namespace std;

class Angle {
private:
    int degrees;
    float minutes;
    char direction;
public:
    Angle() : degrees(0), minutes(0.0f), direction('N') {}
    Angle(int d, float m, char dir) : degrees(d), minutes(m), direction(dir) {}

    void getAngle() {
        cout << "Enter degrees: ";
        cin >> degrees;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter direction (N/S/E/W): ";
        cin >> direction;
    }

    void display() {
        cout << degrees << "\xF8" << minutes << "' " << direction;
    }
};

class Ship {
private:
    int shipNo;
    Angle latitude;
    Angle longitude;
    static int count;
public:
    Ship() {
        count++;
        shipNo = count;
    }

    ~Ship() {
        cout << "Destructor called (Ship)\n";
    }

    void getPosition() {
        cout << "Enter latitude:\n";
        latitude.getAngle();
        cout << "Enter longitude:\n";
        longitude.getAngle();
    }

    void display() {
        cout << "Ship #" << shipNo << " Position -> Latitude: ";
        latitude.display();
        cout << ", Longitude: ";
        longitude.display();
        cout << endl;
    }
};

int Ship::count = 0;

int main() {
    Ship s1, s2, s3;
    cout << "Enter position of Ship 1:\n";
    s1.getPosition();
    cout << "Enter position of Ship 2:\n";
    s2.getPosition();
    cout << "Enter position of Ship 3:\n";
    s3.getPosition();

    cout << "\nShip Positions:\n";
    s1.display();
    s2.display();
    s3.display();
    return 0;
}

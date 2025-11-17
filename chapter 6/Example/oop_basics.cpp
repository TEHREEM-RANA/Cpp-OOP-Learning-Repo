#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    string color;
    static int carCount;  // static data (shared by all objects)

public:
    // Constructor (with arguments)
    Car(string b, string c) {
        brand = b;
        color = c;
        carCount++; // count every new car
        cout << "Car created: " << brand << ", " << color << endl;
    }

    // Destructor
    ~Car() {
        cout << "Car destroyed: " << brand << endl;
        carCount--;
    }

    // Member function (public)
    void showCar() {
        cout << "Brand: " << brand << ", Color: " << color << endl;
    }

    // Static function to access static data
    static void showCarCount() {
        cout << "Total cars: " << carCount << endl;
    }
};

// Define static variable outside the class
int Car::carCount = 0;

int main() {
    Car c1("Toyota", "Red");   // Constructor runs automatically
    Car c2("Honda", "Blue");

    c1.showCar();
    c2.showCar();

    Car::showCarCount();  // Access static data (class-level)

    return 0; // destructors will run automatically here
}

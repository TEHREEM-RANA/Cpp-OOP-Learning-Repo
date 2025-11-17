// Q7.cpp
#include <iostream>
#include <string>
using namespace std;

// ---------- Base Class: ship ----------
class ship {
private:
    string name;
    int yearBuilt;

public:
    // Default Constructor
    ship() : name(""), yearBuilt(0) {}

    // Parameterized Constructor
    ship(string n, int y) : name(n), yearBuilt(y) {}

    // Destructor
    ~ship() {}

    // Setters
    void setName(string n) { name = n; }
    void setYear(int y) { yearBuilt = y; }

    // Getters
    string getName() const { return name; }
    int getYear() const { return yearBuilt; }

    // Virtual function to display ship info (for polymorphism)
    virtual void display() const {
        cout << "Ship Name: " << name << endl;
        cout << "Year Built: " << yearBuilt << endl;
    }
};

// ---------- Derived Class: cargoShip ----------
class cargoShip : public ship {
private:
    int cargoCapacity;  // in tons

public:
    // Default Constructor
    cargoShip() : ship(), cargoCapacity(0) {}

    // Parameterized Constructor
    cargoShip(string n, int y, int c) : ship(n, y), cargoCapacity(c) {}

    // Destructor
    ~cargoShip() {}

    // Setter
    void setCargoCapacity(int c) { cargoCapacity = c; }

    // Getter
    int getCargoCapacity() const { return cargoCapacity; }

    // Overridden display function
    void display() const override {
        cout << "Cargo Ship Name: " << getName() << endl;
        cout << "Year Built: " << getYear() << endl;
        cout << "Cargo Capacity: " << cargoCapacity << " tons" << endl;
    }
};

// ---------- Derived Class: passengerShip ----------
class passengerShip : public ship {
private:
    int passengerCount;

public:
    // Default Constructor
    passengerShip() : ship(), passengerCount(0) {}

    // Parameterized Constructor
    passengerShip(string n, int y, int p) : ship(n, y), passengerCount(p) {}

    // Destructor
    ~passengerShip() {}

    // Setter
    void setPassengerCount(int p) { passengerCount = p; }

    // Getter
    int getPassengerCount() const { return passengerCount; }

    // Overridden display function
    void display() const override {
        cout << "Passenger Ship Name: " << getName() << endl;
        cout << "Year Built: " << getYear() << endl;
        cout << "Passenger Capacity: " << passengerCount << " people" << endl;
    }
};

// ---------- Main Function ----------
int main() {
    // Using parameterized constructors
    cargoShip cargo("Ocean Carrier", 2005, 15000);
    passengerShip passenger("Sea Voyager", 2015, 2000);

    cout << "--- Cargo Ship Details ---\n";
    cargo.display();

    cout << "\n--- Passenger Ship Details ---\n";
    passenger.display();

    // Using polymorphism
    cout << "\n--- Demonstrating Polymorphism ---\n";
    ship* ships[2];
    ships[0] = &cargo;
    ships[1] = &passenger;

    for (int i = 0; i < 2; i++) {
        ships[i]->display();
        cout << endl;
    }

    return 0;
}

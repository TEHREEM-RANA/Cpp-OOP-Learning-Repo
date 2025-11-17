// Q8.cpp
#include <iostream>
#include <vector>
using namespace std;

// Base horse class
class Horse {
protected:
    string name;
    float position; // in furlongs
public:
    Horse(string n) : name(n), position(0.0f) {}
    virtual ~Horse() {}

    virtual void horseTick() {
        position += 1.0f; // default speed per tick
    }

    float getPosition() { return position; }
    string getName() { return name; }

    virtual void showStatus() {
        cout << name << " at position: " << position << " furlongs" << endl;
    }
};

// Derived class: competitive horse
class ComHorse : public Horse {
private:
    vector<ComHorse*>* raceArray; // pointer to array of horses
public:
    ComHorse(string n, vector<ComHorse*>* arr) : Horse(n), raceArray(arr) {}

    void horseTick() override {
        position += 1.0f; // base speed

        // Check if front-runner
        float maxPos = 0.0f;
        for (auto h : *raceArray) {
            if (h != this && h->getPosition() > maxPos)
                maxPos = h->getPosition();
        }

        if (position >= maxPos + 0.1f) { // slightly ahead
            position += 0.5f; // speed up
        }
    }

    void showStatus() override {
        cout << name << " at position: " << position << " furlongs";
        cout << endl;
    }
};

int main() {
    vector<ComHorse*> race;

    // Create horses
    race.push_back(new ComHorse("Thunder", &race));
    race.push_back(new ComHorse("Lightning", &race));
    race.push_back(new ComHorse("Blaze", &race));

    cout << "--- Starting Race ---\n";

    // Simulate 5 ticks
    for (int t = 0; t < 5; t++) {
        cout << "\nTick " << t + 1 << ":\n";
        for (auto h : race) {
            h->horseTick();
            h->showStatus();
        }
    }

    // Clean up memory
    for (auto h : race) delete h;

    return 0;
}

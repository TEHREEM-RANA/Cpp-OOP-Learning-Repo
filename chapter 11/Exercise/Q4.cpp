// Q4.cpp
#include <iostream>
#include <string>
using namespace std;

// Base class
class Publication {
protected:
    string title;
    float price;
public:
    Publication() : title(""), price(0.0f) {}
    Publication(string t, float p) : title(t), price(p) {}
    virtual ~Publication() {}

    void setTitle(string t) { title = t; }
    void setPrice(float p) { price = p; }
    string getTitle() { return title; }
    float getPrice() { return price; }

    virtual void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void putData() {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }

    virtual bool isOversize() = 0; // Pure virtual function
};

// Derived class Book
class Book : public Publication {
private:
    int pageCount;
public:
    Book() : Publication(), pageCount(0) {}
    Book(string t, float p, int pc) : Publication(t, p), pageCount(pc) {}
    ~Book() {}

    void setPageCount(int pc) { pageCount = pc; }
    int getPageCount() { return pageCount; }

    void getData() override {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void putData() override {
        Publication::putData();
        cout << "Pages: " << pageCount;
        if (isOversize()) cout << " (Oversize)";
        cout << endl;
    }

    bool isOversize() override {
        return pageCount > 800;
    }
};

// Derived class Tape
class Tape : public Publication {
private:
    float playTime;
public:
    Tape() : Publication(), playTime(0.0f) {}
    Tape(string t, float p, float pt) : Publication(t, p), playTime(pt) {}
    ~Tape() {}

    void setPlayTime(float pt) { playTime = pt; }
    float getPlayTime() { return playTime; }

    void getData() override {
        Publication::getData();
        cout << "Enter playing time (minutes): ";
        cin >> playTime;
    }

    void putData() override {
        Publication::putData();
        cout << "Playing Time: " << playTime << " minutes";
        if (isOversize()) cout << " (Oversize)";
        cout << endl;
    }

    bool isOversize() override {
        return playTime > 90.0;
    }
};

int main() {
    const int MAX = 5;
    Publication* pubArr[MAX];
    int count = 0;
    char choice;

    do {
        cout << "\nEnter type (b for book, t for tape): ";
        cin >> choice;
        if (choice == 'b' || choice == 'B') {
            pubArr[count] = new Book();
        } else if (choice == 't' || choice == 'T') {
            pubArr[count] = new Tape();
        } else {
            cout << "Invalid choice!" << endl;
            continue;
        }
        pubArr[count]->getData();
        count++;

        cout << "Do you want to enter another (y/n)? ";
        cin >> choice;
    } while ((choice == 'y' || choice == 'Y') && count < MAX);

    cout << "\n--- Publication Details ---\n";
    for (int i = 0; i < count; i++) {
        pubArr[i]->putData();
        cout << "------------------------\n";
    }

    // Free memory
    for (int i = 0; i < count; i++) {
        delete pubArr[i];
    }

    return 0;
}

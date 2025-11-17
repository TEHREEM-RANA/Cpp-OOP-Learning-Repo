// Q2.cpp
// Program: String class with overloaded += operator
#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char str[100];

public:
    // Default constructor
    String() {
        str[0] = '\0';
    }

    // Parameterized constructor
    String(const char s[]) {
        strcpy(str, s);
    }

    // Copy constructor
    String(const String& s) {
        strcpy(str, s.str);
    }

    // Destructor
    ~String() {
        // nothing to release (static array)
    }

    // Getter
    const char* getString() const {
        return str;
    }

    // Setter
    void setString(const char s[]) {
        strcpy(str, s);
    }

    // Display function
    void display() const {
        cout << str;
    }

    // Overloaded += operator
    String& operator+=(const String& s) {
        strcat(str, s.str);
        return *this;
    }
};

int main() {
    String s1("Hello");
    String s2("World");
    String s3;

    cout << "Before concatenation:" << endl;
    cout << "s1 = "; s1.display(); cout << endl;
    cout << "s2 = "; s2.display(); cout << endl;

    // Using overloaded +=
    s3 = s1 += s2;

    cout << "\nAfter s1 += s2:" << endl;
    cout << "s1 = "; s1.display(); cout << endl;
    cout << "s3 = "; s3.display(); cout << endl;

    return 0;
}

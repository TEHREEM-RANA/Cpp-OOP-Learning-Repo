// Q2.cpp
#include <iostream>
#include <cstring>  // for strcpy(), strlen()
using namespace std;

const int SZ = 80; // maximum size of string (including null terminator)

// ---------- Base Class: String ----------
class String {
protected:
    char str[SZ]; // fixed-size character array

public:
    // Default Constructor
    String() { str[0] = '\0'; }

    // Parameterized Constructor
    String(const char s[]) {
        if (strlen(s) < SZ)
            strcpy(str, s);
        else
            cout << "Warning: String too long, may overflow in base class!\n";
    }

    // Destructor
    ~String() {}

    // Getter (to show string)
    const char* getStr() const { return str; }

    // Setter (without safety)
    void setStr(const char s[]) {
        strcpy(str, s);
    }

    // Display Function
    void display() const {
        cout << str;
    }
};

// ---------- Derived Class: Pstring (Protected String) ----------
class Pstring : public String {
public:
    // Default Constructor
    Pstring() : String() {}

    // Parameterized Constructor (safe copy)
    Pstring(const char s[]) {
        int len = strlen(s);
        if (len >= SZ) {
            strncpy(str, s, SZ - 1); // copy only SZ-1 chars
            str[SZ - 1] = '\0';      // null-terminate
        } else {
            strcpy(str, s);          // safe copy
        }
    }

    // Destructor
    ~Pstring() {}

    // Safe Setter (checks overflow)
    void setStr(const char s[]) {
        int len = strlen(s);
        if (len >= SZ) {
            strncpy(str, s, SZ - 1);
            str[SZ - 1] = '\0';
            cout << "(String truncated to fit size limit)\n";
        } else {
            strcpy(str, s);
        }
    }

    // Safe Getter Display
    void show() const {
        cout << str;
    }
};

// ---------- Main Function for Testing ----------
int main() {
    cout << "--- Safe Pstring Demonstration ---\n\n";

    // Short string (safe)
    Pstring shortStr("Hello, World!");
    cout << "Short string: ";
    shortStr.show();
    cout << "\n\n";

    // Long string (will be truncated safely)
    Pstring longStr("This string will surely exceed the width of the screen, "
                    "which is what the SZ constant represents.");
    cout << "Long string (truncated safely): ";
    longStr.show();
    cout << "\n\n";

    // Modify a string using safe setter
    Pstring userStr;
    char input[SZ * 2];
    cout << "Enter a string: ";
    cin.getline(input, SZ * 2);
    userStr.setStr(input);
    cout << "Stored safely as: ";
    userStr.show();
    cout << endl;

    return 0;
}

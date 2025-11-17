// Q2.cpp
#include <iostream>
#include <cstring>
#include <cctype>  // For toupper()

using namespace std;

class String {
private:
    char* str;
    int length;

public:
    // Default constructor
    String() {
        str = new char[1];
        str[0] = '\0';
        length = 0;
    }

    // Parameterized constructor
    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // Copy constructor
    String(const String& s) {
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Getter
    const char* getStr() const {
        return str;
    }

    // Setter
    void setStr(const char* s) {
        delete[] str;
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // Show data
    void showData() const {
        cout << str << endl;
    }

    // Convert string to uppercase
    void upit() {
        for (int i = 0; i < length; i++) {
            str[i] = toupper(str[i]);
        }
    }
};

// Main function to test upit()
int main() {
    String s1("Hello, World!");
    
    cout << "Original string: ";
    s1.showData();
    
    s1.upit();
    
    cout << "Uppercase string: ";
    s1.showData();
    
    return 0;
}

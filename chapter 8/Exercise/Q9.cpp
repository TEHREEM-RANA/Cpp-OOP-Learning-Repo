// Q9.cpp
// Program: String class with overloaded + and == operators
#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;   // pointer to dynamically allocated string
    int length;  // length of the string

public:
    // Default constructor
    String() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
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

    // Setter
    void setString(const char* s) {
        delete[] str;
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // Getter
    const char* getString() const {
        return str;
    }

    // Overloaded + operator for concatenation
    String operator+(const String& s) const {
        String temp;
        temp.length = length + s.length;
        delete[] temp.str;
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    // Overloaded == operator for comparison
    bool operator==(const String& s) const {
        return strcmp(str, s.str) == 0;
    }

    // Display function
    void display() const {
        cout << str;
    }
};

int main() {
    String s1, s2, s3;
    char input1[50], input2[50];

    cout << "Enter first string: ";
    cin.getline(input1, 50);
    s1.setString(input1);

    cout << "Enter second string: ";
    cin.getline(input2, 50);
    s2.setString(input2);

    cout << "\n--- Results ---\n";

    cout << "Concatenation: ";
    s3 = s1 + s2;
    s3.display();

    cout << "\nComparison:\n";
    cout << "s1 == s2 : " << (s1 == s2 ? "True" : "False") << endl;

    return 0;
}


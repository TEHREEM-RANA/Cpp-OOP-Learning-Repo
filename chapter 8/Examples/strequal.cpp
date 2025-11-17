// strequal.cpp
// overloaded '==' operator compares strings

#include <iostream>
#include <string.h>  // for strcmp()
using namespace std;

class String
{
private:
    enum { SZ = 80 };  // maximum size of a string
    char str[SZ];      // array to store characters

public:
    // Constructor with no arguments
    String()
    { strcpy(str, ""); }

    // Constructor with one argument
    String(char s[])
    { strcpy(str, s); }

    // Display the string
    void display() const
    { cout << str; }

    // Take string input from user
    void getstr()
    { cin.get(str, SZ); }

    // Overload '==' to compare two String objects
    bool operator == (String ss) const
    {
        // strcmp() returns 0 if both strings are equal
        return (strcmp(str, ss.str) == 0) ? true : false;
    }
};

//--------------------------------------------------------------

int main()
{
    String s1 = "yes";
    String s2 = "no";
    String s3;

    cout << "\nEnter 'yes' or 'no': ";
    s3.getstr();  // get user input

    if (s3 == s1)           // compare with "yes"
        cout << "You typed yes\n";
    else if (s3 == s2)      // compare with "no"
        cout << "You typed no\n";
    else
        cout << "You didn’t follow instructions\n";

    return 0;
}

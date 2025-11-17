// strconv.cpp
// convert between ordinary C-strings and class String

#include <iostream>
#include <string.h>   // for strcpy(), etc.
using namespace std;

////////////////////////////////////////////////////////////////
class String  // user-defined string type
{
private:
    enum { SZ = 80 };  // size of all String objects
    char str[SZ];      // holds a C-string

public:
    String()           // no-argument constructor
    { str[0] = '\0'; } // empty string

    String(char s[])   // 1-argument constructor
    { strcpy(str, s); } // convert C-string to String

    void display() const // display the String
    { cout << str; }

    operator char*()     // conversion operator
    { return str; }      // convert String to C-string
};
////////////////////////////////////////////////////////////////

int main()
{
    String s1;                // empty string
    char xstr[] = "Joyeux Noel! ";

    s1 = xstr;                // convert C-string → String
    s1.display();             // display String

    String s2 = "Bonne Annee!"; // convert C-string → String
    cout << static_cast<char*>(s2); // convert String → C-string

    cout << endl;
    return 0;
}

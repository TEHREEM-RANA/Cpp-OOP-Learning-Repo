// strplus.cpp
// overloaded '+' operator concatenates strings

#include <iostream>
#include <string.h>  // for strcpy(), strcat()
#include <stdlib.h>  // for exit()
using namespace std;

class String  // user-defined string type
{
private:
    enum { SZ = 80 };   // maximum size of string
    char str[SZ];       // character array to store string

public:
    String() { strcpy(str, ""); }          // empty constructor
    String(char s[]) { strcpy(str, s); }   // constructor with parameter

    void display() const { cout << str; }  // display string

    // Overload '+' operator
    String operator + (String ss) const
    {
        String temp; // temporary string object

        // check if total length is within limit
        if (strlen(str) + strlen(ss.str) < SZ)
        {
            strcpy(temp.str, str);      // copy current string to temp
            strcat(temp.str, ss.str);   // add the argument string
        }
        else
        {
            cout << "\nString overflow"; 
            exit(1);
        }

        return temp; // return new combined string
    }
};

int main()
{
    String s1 = "\nMerry Christmas! ";
    String s2 = "Happy new year!";
    String s3;

    s1.display();
    s2.display();
    s3.display();     // empty string

    s3 = s1 + s2;     // concatenate s1 and s2
    s3.display();

    cout << endl;
    return 0;
}

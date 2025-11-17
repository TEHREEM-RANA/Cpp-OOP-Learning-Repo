// filename: strobj.cpp
// a string as a class
#include <iostream>
#include <cstring> // for strcpy(), strcat(), strlen()
using namespace std;

class String {
private:
    enum { SZ = 80 }; // maximum size of Strings
    char str[SZ];     // array that holds characters
public:
    // constructor, no args -> create empty string
    String() { str[0] = '\0'; }

    // constructor with one argument (C-string) -> copy into object
    String(char s[]) { strcpy(str, s); }

    // display the string
    void display() { cout << str; }

    // concatenate s2 to this string
    void concat(String s2) { 
        if ( strlen(str) + strlen(s2.str) < SZ )
            strcat(str, s2.str);
        else
            cout << "\nString too long";
    }
};

int main() {
    String s1("Merry Christmas! ");       // uses constructor with arg
    String s2 = "Season's Greetings!";    // alternate form
    String s3;                            // empty string (default constructor)

    cout << "\ns1="; s1.display();
    cout << "\ns2="; s2.display();
    cout << "\ns3="; s3.display();

    s3 = s1;         // assignment between String objects
    cout << "\ns3="; s3.display();

    s3.concat(s2);   // append s2 to s3
    cout << "\ns3="; s3.display();
    cout << endl;
    return 0;
}

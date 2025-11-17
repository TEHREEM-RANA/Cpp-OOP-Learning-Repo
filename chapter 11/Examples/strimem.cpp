// strimem.cpp
// Memory-saving String class with string counting
#include <iostream>
#include <cstring>
using namespace std;

//////////////////////////////////////////////////////////////
// Class to store string and count
class strCount
{
private:
    int count;   // Number of String objects pointing to this string
    char* str;   // Pointer to actual string

    friend class String; // Make String class a friend

    // Constructor: takes a C-string and stores it
    strCount(char* s)
    {
        int length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s); // copy string
        count = 1;      // initial count is 1
    }

    // Destructor: free memory of string
    ~strCount()
    {
        delete[] str;
    }
};
//////////////////////////////////////////////////////////////

// String class
class String
{
private:
    strCount* psc; // Pointer to strCount object

public:
    // No-argument constructor
    String()
    {
        psc = new strCount((char*)"NULL");
    }

    // One-argument constructor
    String(char* s)
    {
        psc = new strCount(s);
    }

    // Copy constructor
    String(String& S)
    {
        psc = S.psc;    // Point to same strCount object
        (psc->count)++; // Increment count
    }

    // Destructor
    ~String()
    {
        if (psc->count == 1)  // If this is the last user
            delete psc;        // Delete strCount object
        else
            (psc->count)--;    // Otherwise, decrement count
    }

    // Display function
    void display()
    {
        cout << psc->str;       // Print string
        cout << " (addr=" << psc << ")"; // Print strCount address
    }

    // Overloaded assignment operator
    void operator=(String& S)
    {
        if (psc->count == 1)  // Delete old strCount if last user
            delete psc;
        else
            (psc->count)--;    // Decrement old count

        psc = S.psc;           // Assign new strCount
        (psc->count)++;         // Increment new count
    }
};
//////////////////////////////////////////////////////////////

// Main function
int main()
{
    String s3 = (char*)"When the fox preaches, look to your geese.";
    cout << "\ns3="; s3.display();

    String s1;
    s1 = s3; // Assignment operator
    cout << "\ns1="; s1.display();

    String s2(s3); // Copy constructor
    cout << "\ns2="; s2.display();

    cout << endl;
    return 0;
}

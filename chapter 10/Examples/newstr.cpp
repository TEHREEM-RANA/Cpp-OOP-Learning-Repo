// newstr.cpp
// using new to get memory for strings
#include <iostream>
#include <cstring> // for strcpy(), strlen()
using namespace std;

class String // user-defined string type
{
private:
    char* str; // pointer to string

public:
    // Constructor with one argument
    String(char* s)
    {
        int length = strlen(s);      // find string length
        str = new char[length + 1];  // get exact memory (+1 for '\0')
        strcpy(str, s);              // copy string into memory
    }

    // Destructor
    ~String()
    {
        cout << "Deleting str.\n";
        delete[] str; // free memory
    }

    // Display string
    void display()
    {
        cout << str << endl;
    }
};

int main()
{
    String s1 = "Who knows nothing doubts nothing.";
    cout << "s1 = ";
    s1.display();

    return 0;
}

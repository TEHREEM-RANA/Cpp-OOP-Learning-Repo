// ptrobjs.cpp
// array of pointers to objects
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
class person // class of persons
{
protected:
    char name[40]; // person’s name
public:
    void setName()  // set the name
    {
        cout << "Enter name: ";
        cin >> name;
    }
    void printName()  // display the name
    {
        cout << "\nName is: " << name;
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    person* persPtr[100]; // array of pointers to person
    int n = 0;            // number of persons in array
    char choice;

    do {
        persPtr[n] = new person;   // create new object dynamically
        persPtr[n]->setName();     // use -> to call function
        n++;
        cout << "Enter another (y/n)? ";
        cin >> choice;
    } while (choice == 'y');

    // Display all persons
    for (int j = 0; j < n; j++) {
        cout << "\nPerson number " << j + 1;
        persPtr[j]->printName();
    }

    cout << endl;
    return 0;
}

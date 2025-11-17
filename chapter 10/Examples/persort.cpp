// persort.cpp
// Sorts person objects using array of pointers
#include <iostream>
#include <string>
using namespace std;

class person
{
protected:
    string name; // person’s name
public:
    void setName()  // input name
    {
        cout << "Enter name: ";
        cin >> name;
    }
    void printName() // display name
    {
        cout << endl << name;
    }
    string getName() // return name
    {
        return name;
    }
};

// Function prototypes
void bsort(person**, int);
void order(person**, person**);

int main()
{
    person* persPtr[100]; // array of pointers to persons
    int n = 0;
    char choice;

    // Input names
    do {
        persPtr[n] = new person;  // create object dynamically
        persPtr[n]->setName();    // set name for object
        n++;

        cout << "Enter another (y/n)? ";
        cin >> choice;
    } while(choice == 'y');

    cout << "\nUnsorted list:";
    for(int j = 0; j < n; j++)
        persPtr[j]->printName();

    // Sort pointers
    bsort(persPtr, n);

    cout << "\nSorted list:";
    for(int j = 0; j < n; j++)
        persPtr[j]->printName();

    cout << endl;
    return 0;
}

//-----------------------------------------------
// Sort function
void bsort(person** pp, int n)
{
    for(int j = 0; j < n - 1; j++)
        for(int k = j + 1; k < n; k++)
            order(pp + j, pp + k);
}

//-----------------------------------------------
// Order function
void order(person** pp1, person** pp2)
{
    if( (*pp1)->getName() > (*pp2)->getName() )
    {
        person* temp = *pp1;
        *pp1 = *pp2;
        *pp2 = temp;
    }
}

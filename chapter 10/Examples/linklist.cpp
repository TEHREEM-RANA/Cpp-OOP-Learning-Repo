// linklist.cpp
// linked list example
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
struct link // one element of list
{
    int data;     // data item
    link* next;   // pointer to next link
};
////////////////////////////////////////////////////////////////
class linklist // a list of links
{
private:
    link* first;  // pointer to first link
public:
    linklist() { first = NULL; } // constructor: no first link yet

    void additem(int d); // add new node
    void display();      // display all nodes
};
////////////////////////////////////////////////////////////////
void linklist::additem(int d)
{
    link* newlink = new link; // make a new link (node)
    newlink->data = d;        // store data
    newlink->next = first;    // point to old first node
    first = newlink;          // now first points to this new node
}
////////////////////////////////////////////////////////////////
void linklist::display()
{
    link* current = first; // start from first node
    while (current != NULL) {
        cout << current->data << endl;
        current = current->next; // move to next node
    }
}
////////////////////////////////////////////////////////////////
int main()
{
    linklist li; // make linked list
    li.additem(25);
    li.additem(36);
    li.additem(49);
    li.additem(64);
    li.display();
    return 0;
}

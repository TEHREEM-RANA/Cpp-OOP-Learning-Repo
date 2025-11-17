// Q9.cpp
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// LinkList class
class LinkList {
private:
    Node* head;
public:
    // Constructor
    LinkList() : head(nullptr) {}

    // Copy Constructor (deep copy)
    LinkList(const LinkList& other) : head(nullptr) {
        if (!other.head) return;

        Node* currentOther = other.head;
        Node* last = nullptr;

        while (currentOther) {
            Node* newNode = new Node(currentOther->data);
            if (!head) head = newNode;
            else last->next = newNode;
            last = newNode;
            currentOther = currentOther->next;
        }
    }

    // Assignment Operator (deep copy)
    LinkList& operator=(const LinkList& other) {
        if (this == &other) return *this; // self-assignment check

        // Delete existing list
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        // Copy nodes from other
        Node* currentOther = other.head;
        Node* last = nullptr;
        while (currentOther) {
            Node* newNode = new Node(currentOther->data);
            if (!head) head = newNode;
            else last->next = newNode;
            last = newNode;
            currentOther = currentOther->next;
        }

        return *this;
    }

    // Destructor
    ~LinkList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Add node at end
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkList list1;
    list1.append(10);
    list1.append(20);
    list1.append(30);

    cout << "list1: ";
    list1.display();

    // Copy constructor
    LinkList list2(list1);
    cout << "list2 (copy of list1): ";
    list2.display();

    // Assignment operator
    LinkList list3;
    list3 = list1;
    cout << "list3 (assigned from list1): ";
    list3.display();

    // Modify list1 to test deep copy
    list1.append(40);
    cout << "\nAfter appending 40 to list1:\n";
    cout << "list1: "; list1.display();
    cout << "list2: "; list2.display();
    cout << "list3: "; list3.display();

    return 0;
}

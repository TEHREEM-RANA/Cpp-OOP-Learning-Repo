// Q4.cpp
#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

// LinkedList class
class LinkList {
private:
    Node* head;

public:
    // Constructor
    LinkList() {
        head = nullptr;
    }

    // Destructor - deletes all nodes
    ~LinkList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            cout << "Deleting node with data: " << temp->data << endl;
            delete temp;
        }
    }

    // Add node at the end
    void addNode(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Display all nodes
    void showList() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function to test destructor
int main() {
    LinkList list;

    list.addNode(10);
    list.addNode(20);
    list.addNode(30);

    cout << "Linked List: ";
    list.showList();

    cout << "Exiting program, destructor will be called automatically..." << endl;

    return 0;
}

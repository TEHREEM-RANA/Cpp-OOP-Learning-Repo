// Q8.cpp
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
            delete temp;
        }
    }

    // Add item at the end
    void addItem(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;  // Traverse to the last node
            }
            temp->next = newNode;  // Link last node to new node
        }
    }

    // Display the list
    void showList() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

// Main function to test adding at the end
int main() {
    LinkList list;

    list.addItem(25);
    list.addItem(36);
    list.addItem(49);
    list.addItem(64);

    cout << "Linked List after adding items at the end:\n";
    list.showList();

    return 0;
}

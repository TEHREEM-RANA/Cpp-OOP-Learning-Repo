// 9. A queue is a data storage device much like a stack. The difference is that in a stack the
// last data item stored is the first one retrieved, while in a queue the first data item stored
// is the first one retrieved. That is, a stack uses a last-in-first-out (LIFO) approach, while a
// queue uses first-in-first-out (FIFO). A queue is like a line of customers in a bank: The
// first one to join the queue is the first one served.
// Rewrite the STAKARAY program from this chapter to incorporate a class called queue
// instead of a class called stack. Besides a constructor, it should have two functions: one
// called put() to put a data item on the queue, and one called get() to get data from the
// queue. These are equivalent to push() and pop() in the stack class.
// Arrays and Strings
// 7
// A
// S
// RRAYS AND
// TRINGS
// 315

// Both a queue and a stack use an array to hold the data. However, instead of a single int
// variable called top, as the stack has, you’ll need two variables for a queue: one called
// head to point to the head of the queue, and one called tail to point to the tail. Items
// are placed on the queue at the tail (like the last customer getting in line at the bank) and
// removed from the queue at the head. The tail will follow the head along the array as
// items are added and removed from the queue. This results in an added complexity:
// When either the tail or the head gets to the end of the array, it must wrap around to the
// beginning. Thus you’ll need a statement like
// if(tail == MAX-1)
// tail = -1;
// to wrap the tail, and a similar one for the head. The array used in the queue is sometimes
// called a circular buffer, because the head and tail circle around it, with the data between
// them.
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 10;

class Queue {
private:
    int queue[MAX];
    int head, tail;

public:
    // Constructor
    Queue() {
        head = 0;
        tail = -1;
    }

    // Destructor
    ~Queue() {
        cout << "Queue destroyed.\n";
    }

    // Put (enqueue)
    void put(int value) {
        if ((tail == MAX - 1 && head == 0) || (tail + 1 == head)) {
            cout << "Queue overflow!\n";
            exit(1);
        }

        if (tail == MAX - 1)
            tail = -1;

        queue[++tail] = value;
    }

    // Get (dequeue)
    int get() {
        if (head == tail + 1 || (head == 0 && tail == -1)) {
            cout << "Queue underflow!\n";
            exit(1);
        }

        int value = queue[head++];
        if (head == MAX)
            head = 0;
        return value;
    }

    // Display
    void display() const {
        cout << "Queue elements: ";
        int i = head;
        while (true) {
            cout << queue[i] << " ";
            if (i == tail)
                break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    Queue q1;

    q1.put(11);
    q1.put(22);
    q1.put(33);

    cout << "Removed: " << q1.get() << endl;

    q1.put(44);
    q1.put(55);

    q1.display();

    return 0;
}

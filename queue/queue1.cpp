#include <iostream>
using namespace std;

// Purpose: Represents one node in a queue implemented using a linked list.
class Node {
public:
    Node *first; // Reference to the first node in the queue.
    Node *last;  // Reference to the last node in the queue.
    Node *next;  // Pointer to the next node in the queue.
    int data;    // Value stored in the node.

    // Purpose: Creates a queue node with a value and initializes all pointers to null.
    Node(int val)
    {
        data = val;
        first = last = next = nullptr;
    }
};

// Purpose: Implements a queue with insertion at the rear and removal from the front.
class queue {
    Node *first;
    Node *last;

public:
    // Purpose: Initializes an empty queue.
    queue()
    {
        first = last = nullptr;
    }

    // Purpose: Adds a new value to the end of the queue.
    void add_data(int val)
    {
        Node *newNode = new Node(val);

        if (first == nullptr)
        {
            first = last = newNode;
            return;
        }
        last->next = newNode;
        last = newNode;
    }

    // Purpose: Prints all values in the queue from front to rear.
    void print()
    {
        Node *temp = first;
        while (temp != nullptr)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
    }

    // Purpose: Removes the front element from the queue.
    void pop()
    {
        if (first == nullptr)
        {
            cout << "Queue is empty!";
            return;
        }

        Node *temp = first;
        first = first->next;

        if (first == nullptr)
        {
            last = nullptr;
        }

        delete temp;
    }

    //For Dequeueing from rear 
    void delete_last()
    {
        //checking whether queue is empty or not
        if(first == nullptr)
        {
            cout << "Queue is empty!";
            return;
        }

        Node *temp = first;
        //reaching the second last node
        while(temp -> next -> next != nullptr)
        {
            temp = temp -> next;
        }

        //declaring a var that stores last nodes address to delete
        Node *del = temp -> next;
        delete del;
        last = temp;
        last -> next = nullptr;
        

    }
};

// Purpose: Demonstrates queue insertion, display, and removal.
int main()
{
    queue q_1;

    q_1.add_data(90);
    q_1.add_data(89);
    q_1.add_data(32);

    q_1.print();
    cout << endl;

    cout << "poping from last = " << endl;
    q_1.delete_last();
    q_1.print();
    cout << endl;
    cout << "program ended !!" << endl;
    return 0;

}
#include <iostream>
using namespace std;

// Purpose: Represents one node in a singly linked list.
class Node {
public:
    int data;     // Value stored in the node.
    Node *next;   // Pointer to the next node in the list.
    Node *head;   // Head pointer for the list (kept for compatibility in this program).

    // Purpose: Initializes a node with a value and null links.
    Node(int val)
    {
        data = val;
        next = head = nullptr;
    }
};

// Purpose: Creates and manages a singly linked list.
class Createlist {
    Node *next;
    Node *head;

public:
    // Purpose: Initializes an empty list.
    Createlist()
    {
        head = next = nullptr;
    }

    // Purpose: Inserts a new value at the end of the list.
    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Purpose: Inserts a new value at the front of the list.
    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    // Purpose: Prints all values in the list from head to end.
    void print_list()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
    }
};

// Purpose: Demonstrates adding values to a linked list using back and front insertion.
int main()
{
    Createlist t, t1;

    t.push_back(10);
    t.push_back(90);
    t.push_back(12);
    t.push_back(91);

    cout << "pushed back List is given as = \n";
    cout << "Head -- > ";
    t.print_list();
    cout << "nullptr" << endl;

    t1.push_front(10);
    t1.push_front(90);
    t1.push_front(12);
    t1.push_front(91);

    cout << "pushed front List is given as = \n";
    cout << "Head -- > ";
    t1.print_list();
    cout << "nullptr";
    return 0;
}
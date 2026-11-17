#include <iostream>
using namespace std;

// Purpose: Represents one node in a stack implemented using a linked list.
class Node {
public:
    int data;   // Value stored in the node.
    Node *next; // Pointer to the next node.
    Node *top;  // Top pointer for the stack.

    // Purpose: Creates a node with the given value and null next pointer.
    Node(int val)
    {
        data = val;
        next = top = nullptr;
    }
};

// Purpose: Implements stack operations using a linked list.
class Stax {
public:
    Node *top;

    // Purpose: Initializes an empty stack.
    Stax()
    {
        top = nullptr;
    }

    // Purpose: Pushes a new element onto the top of the stack.
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (top == nullptr)
        {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    // Purpose: Removes the element currently on top of the stack.
    void delete_ele()
    {
        if (top == nullptr)
            return;

        Node *temp = top;
        top = temp->next;
        delete temp;
    }

    // Purpose: Returns the value of the top element without removing it.
    int peek()
    {
        return top->data;
    }

    // Purpose: Prints every element in the stack from top to bottom.
    void print()
    {
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
    }

    // Purpose: Counts how many elements are currently in the stack.
    int size()
    {
        Node *temp = top;
        int count = 0;
        while (temp != nullptr)
        {
            count += 1;
            temp = temp->next;
        }

        return count;
    }

    // Purpose: Searches the stack for a specific value and returns true if found.
    bool find(int val)
    {
        Node *temp = top;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                return true;
            }
            temp = temp->next;
        }

        return false;
    }
};

// Purpose: Demonstrates stack push, peek, size, print, and search operations.
int main()
{
    Stax s;

    s.push_back(90);
    s.push_back(100);
    s.push_back(12);
    s.push_back(98);

    cout << "top element = " << s.peek() << endl;
    cout << "Size of stack = " << s.size() << endl;
    s.print();
    cout << endl;

    if (s.find(98))
    {
        cout << "Element is present";
    }
    else
    {
        cout << "Element is not present";
    }
   return 0;
}
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node *top;

    Node(int val)
    {
        data = val;
        next = top = nullptr;
    }
};
class Stax{

public:
Node *top;
    Stax()
    {
        top = nullptr;
    }
        void push_back(int val)
    {
        Node *newNode  = new Node(val);
        if(top == nullptr)
        {
            top = newNode;
            return;
        }
        newNode -> next = top;
        top = newNode;
    }

    void delete_ele()
    {
        Node *temp = top;
        top = temp -> next;
        delete temp;
    }

    int peek()
    {
        return top->data;
    }

    void print()
    {
        Node *temp = top;
        while(temp != nullptr)
        {
            cout << temp -> data << ' ';
            temp = temp -> next;
        }
 
    }

    int size()
    {
        Node *temp = top;
        int count = 0;
        while(temp != nullptr)
        {
            count += 1;
            temp = temp -> next;
        }

        return count;
    }


};

int main()
{
    Stax s;

    s.push_back(90);
    s.push_back(100);
    s.push_back(12);
    s.push_back(98);


    // s.delete_ele();
    cout << "top element = " << s.peek() << endl;
    cout << "Size of stack = " << s.size() << endl;
    s.print();


}
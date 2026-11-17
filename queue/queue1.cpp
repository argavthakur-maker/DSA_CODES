#include <iostream>
using namespace std;
class Node{
    public:
        Node *first;
        Node *last;
        Node *next;
        int data;

        Node(int val)
        {
            data = val;
            first = last = next = nullptr;
        }
};
class queue{
    Node *first;
    Node *last;

    public:
        queue()
        {
            first=last=nullptr;
        }

        void add_data(int val)
        {
            Node *newNode = new Node(val);

            if(first == nullptr)
            {
                first = last = newNode;
                return;
            }
            last -> next = newNode;
            last = newNode;

        }

        void print()
        {
            Node *temp = first;
            while(temp != nullptr)
            {
                cout << temp -> data << ' ';
                temp = temp -> next;
            }
        }
            void pop()
            {
                if(first == nullptr)
                {
                    cout << "Queue is empty!";
                    return;
                }

                Node *temp = first;
                first = first -> next;

                if(first == nullptr)
                {
                    last = nullptr;
                }

                delete temp;
            }
};
int main()
{
    queue q_1;

    q_1.add_data(90);
    q_1.add_data(89);
    q_1.add_data(32);

    q_1.print();
    cout << endl;

    cout << "After pop = " << endl;
    q_1.pop();
    q_1.print();
    cout << "program ended !!"
    return 0;
}
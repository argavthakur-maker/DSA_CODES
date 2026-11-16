#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node *head;

    Node(int val)
    {
        data = val;
        next = head = nullptr;
    }
};

class Createlist{

    Node *next;
    Node *head;

    public:
        Createlist()
        {
            head = next = nullptr;
        }


        void push_back(int val)
        {
            Node *newNode = new Node(val);

            if(head == nullptr)
            {
                head = newNode;
                return;
            }

            Node *temp = head;
            while(temp->next != nullptr)
            {
                temp = temp -> next;
            }

            temp -> next = newNode;

        }


        void push_front(int val)
        {
            Node *newNode = new Node(val);

            if(head == nullptr)
            {
                head = newNode;
                return;
            }

            newNode -> next = head;
            head = newNode;
        }

        void print_list()
        {
            Node *temp = head;
            while(temp != nullptr)
            {
                cout << temp -> data << " --> ";
                temp = temp -> next;
            }

        }




};
int main()
{
    Createlist t , t1;


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
}
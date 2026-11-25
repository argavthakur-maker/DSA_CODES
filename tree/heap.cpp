#include <iostream>
#include <queue>
using namespace std;

// Node represents one element in the binary heap tree.
class Node{
public:
    Node *left;
    Node *right;
    Node *parent;
    int data;

    // Initialize a node with no children or parent.
    Node(int val)
    {
        data = val;
        left = right = parent =  nullptr;
    }
};


// This class builds a max-heap using a linked binary tree.
class builtheap{
    Node *root;


public:
    // Start with an empty heap.
    builtheap()
    {
        root = nullptr;
    }


    // Insert a value and restore the max-heap property.
    void create(int val)
    {
        Node *newNode = new Node(val);

        // The first inserted node becomes the root.
        if(root == nullptr)
        {
            root = newNode;
            return;
        }

        // Use level-order traversal to find the first empty position.
        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {

            Node *temp = q.front();
            q.pop();

            // Attach the new node to the left child if it is empty.
            if(temp -> left == nullptr)
            {
                temp -> left = newNode;
                newNode -> parent = temp;
                break;
            }
            else{
                q.push(temp -> left);
            }

            // Otherwise, attach it to the right child if it is empty.
            if(temp -> right == nullptr)
            {
                temp -> right = newNode;
                newNode -> parent = temp;
                break;
            }
            else{
                q.push(temp -> right);
            }

            
            
        }
        
        // Bubble the new node upward until every parent is larger.
        Node *curr = newNode;
        while(curr->parent!= nullptr && curr->data > curr -> parent ->data)
        {
            swap(curr -> data  , curr -> parent -> data);
            curr = curr -> parent;
        }


    }

    // Print heap nodes in level-order (breadth-first) order.
    void display()
    {
        queue<Node*> q;

        q.push(root);

        while(!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            cout << temp -> data << ' ';

            // Visit left and right children in the same queue.
            if(temp -> left != nullptr)
            {
                q.push(temp -> left);
            }
            if(temp -> right != nullptr){
                q.push(temp -> right);
            }
        }

    }
};
int main()
{
    builtheap b_1;

    b_1.create(90);
    b_1.create(89);
    b_1.create(45);
    b_1.create(67);


    b_1.display();
}
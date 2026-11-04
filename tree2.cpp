#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
class createtree{

    public:
    Node *root;
    createtree()
    {
        root = nullptr;
    }


    public: 
            void add_node(int val)
            {
                Node *newNode = new Node(val);

                if(root == nullptr)
                {
                    root = newNode;
                    return;
                }
                Node *curr = root;
                while(true)
                    {
                       if(newNode->data < curr->data)
                        {
                            if(curr->left == nullptr)
                            {
                                curr->left = newNode;
                                return;
                            }
                            else
                            {
                                curr = curr->left;
                            }
                        }
                        else
                        {
                            if(curr->right == nullptr)
                            {
                                curr->right = newNode;
                                return;
                            }
                            else
                            {
                                curr = curr->right;
                            }
                        }
    
                }

                }

            void postorder(Node *root)
            {
                Node *curr = root;
                if(curr == nullptr)
                {
                    return;
                }

                postorder(curr -> left);
                postorder(curr -> right);
                cout << root -> data << " ";


            }

            void preorder(Node *root)
            {
                Node *curr = root;
                if(curr == nullptr)
                {
                    return;
                }

                cout << root -> data << " ";
                postorder(curr -> left);
                postorder(curr -> right);


            }

            void inorder(Node *root)
            {
                Node *curr = root;
                if(curr == nullptr)
                {
                    return;
                }

                postorder(curr -> left);
                cout << root -> data << " ";
                postorder(curr -> right);


            }
            

};
int main()
{
    createtree t;


    t.add_node(10);
    t.add_node(20);
    t.add_node(21);


    cout << "inorder traversal"<< ' ';
    t.inorder(t.root);
    cout << "\n";
    cout << "preorder traversal"<< ' ';
    t.preorder(t.root);
    cout << "\n";
    cout << "postrorder traversal"<< ' ';
    t.postorder(t.root);




}
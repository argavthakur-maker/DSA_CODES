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
            


            int counte_nodes(Node *root)
            {
                int count = 0;

                Node *curr = root;
                while(true)
                {
                    if(root -> left != nullptr)
                    {
                        count += 1;
                        root = root -> left;
                    }
                    else{
                        count += 1;

                        root = root -> right;
                    }
                }
                   
            }

            void search(Node *root , int key){
                if(root == nullptr)
                {
                    cout << "Key is Absent" << endl;
                    return;
                }

                if(key == root -> data)
                {
                    cout << "Given key is present in the tree" << endl;
                    return;
                }
                
                else if(key < root -> data)
                {
                    search(root -> left , key);
                }

                else if(key > root -> data)
                {
                    search(root -> right , key);
                }
            }

            Node *deletenode(Node *root , int key)
            {
                if(root == nullptr)
                {
                    return nullptr;
                }

                if(key < root->data)
                {
                    root->left = deletenode(root->left , key);
                }
                else if(key > root->data)
                {
                    root->right = deletenode(root->right , key);
                }
                else{

                    if(root -> left == nullptr && root -> right == nullptr)
                    {
                        delete root;
                        return nullptr;
                    }
                    else if(root -> left == nullptr)
                    {
                        Node *temp = root -> right;
                        delete root;
                        return temp;
                    }
                    else if(root -> right == nullptr)
                    {
                        Node *temp = root -> left;
                        delete root;
                        return temp;

                    }
                    else if(root -> left != nullptr && root -> right != nullptr)
                    {
                        Node *temp = get(root -> right);
                        root -> data = temp -> data;
                        root -> right = deletenode(root -> right , temp -> data);
                    }
                }
                return root;


            }



            Node *get(Node *root)
            {
                while(root != nullptr && root -> left == nullptr)
                {
                    root = root -> left;
                }
                return root;
            }

};
int main()
{
    createtree t;


    t.add_node(10);
    t.add_node(20);
    t.add_node(21);


    cout << "Before deleting node = "<< endl;
    t.inorder(t.root);
    cout << "\n";
    // cout << "preorder traversal"<< ' ';
    // t.preorder(t.root);
    // cout << "\n";
    // cout << "postrorder traversal"<< ' ';
    // t.postorder(t.root);
    // cout << endl;

    t.deletenode(t.root , 21);
    cout << "After deleting node = " << endl;
    t.inorder(t.root);

    




}

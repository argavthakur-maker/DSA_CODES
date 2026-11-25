#include <iostream>
#include <queue> //using STL queue for level order traversal
using namespace std;

// Purpose: Represents one node in a binary search tree.
class Node {
public:
    int data;      // Value stored in the node.
    Node *left;    // Pointer to the left subtree.
    Node *right;   // Pointer to the right subtree.

    // Purpose: Creates a node with the given value and null child pointers.
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Purpose: Implements a binary search tree with insertion, traversal, search, and deletion features.
class createtree {
public:
    Node *root;

    // Purpose: Initializes the tree as empty.
    createtree()
    {
        root = nullptr;
    }

    // Purpose: Inserts a new value into the BST at its correct position.
    void add_node(int val)
    {
        Node *newNode = new Node(val);

        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        Node *curr = root;
        while (true)
        {
            if (newNode->data < curr->data)
            {
                if (curr->left == nullptr)
                {
                    curr->left = newNode;
                    return;
                }
                curr = curr->left;
            }
            else
            {
                if (curr->right == nullptr)
                {
                    curr->right = newNode;
                    return;
                }
                curr = curr->right;
            }
        }
    }

    // Purpose: Prints the tree in preorder: root, left, right.
    void preorder(Node *curr)
    {
        if (curr == nullptr)
        {
            return;
        }

        cout << curr->data << " ";
        preorder(curr->left);
        preorder(curr->right);
    }

    // Purpose: Prints the tree in postorder: left, right, root.
    void postorder(Node *curr)
    {
        if (curr == nullptr)
        {
            return;
        }

        postorder(curr->left);
        postorder(curr->right);
        cout << curr->data << " ";
    }

    // Purpose: Prints the tree in inorder: left, root, right.
    void inorder(Node *curr)
    {
        if (curr == nullptr)
        {
            return;
        }

        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }

    void level_order(Node *curr)
    {
        queue<Node*> nums;

        nums.push(curr);

        while(nums.size() > 0)
        {
            Node *read = nums.front();
            nums.pop();

            cout << read -> data << ' ';

            if(read -> left != nullptr)
            {
                nums.push(read -> left);
            }

            if(read -> right != nullptr)
            {
                nums.push(read -> right);
            }

        }

    }

    // Purpose: Counts how many nodes are present in the tree.
    int counte_nodes(Node *curr)
    {
        if (curr == nullptr)
        {
            return 0;
        }

        return 1 + counte_nodes(curr->left) + counte_nodes(curr->right);
    }

    // Purpose: Searches the tree for a given target value .
    bool search(Node *curr, int key)
    {
    
        while(curr != nullptr)
        {
            if (key == curr->data)
            {
                return true;
            }
            else if (key < curr->data)
            {
                curr = curr -> left;
            }
            else if (key > curr->data)
            {
                curr = curr -> right;
            }
        }
        return false;
    }

    // Purpose: Finds the smallest node in the right subtree to replace a deleted node.
    Node *get(Node *curr)
    {
        while (curr != nullptr && curr->left != nullptr)
        {
            curr = curr->left;
        }
        return curr;
    }

    // Purpose: Removes a node with a given key from the tree while preserving BST rules.
    Node *deletenode(Node *curr, int key)
    {
        if (curr == nullptr)
        {
            return nullptr;
        }

        if (key < curr->data)
        {
            curr->left = deletenode(curr->left, key);
        }
        else if (key > curr->data)
        {
            curr->right = deletenode(curr->right, key);
        }
        else
        {
            if (curr->left == nullptr && curr->right == nullptr)
            {
                delete curr;
                return nullptr;
            }
            else if (curr->left == nullptr)
            {
                Node *temp = curr->right;
                delete curr;
                return temp;
            }
            else if (curr->right == nullptr)
            {
                Node *temp = curr->left;
                delete curr;
                return temp;
            }
            else
            {
                Node *temp = get(curr->right);
                curr->data = temp->data;
                curr->right = deletenode(curr->right, temp->data);
            }
        }
        return curr;
    }

    bool neg_check(Node *curr)
    {
        if(curr == nullptr)
        {
            return false;
        }
    }


};

// Purpose: Demonstrates building a BST and performing traversal operations.
int main()
{
    createtree t;

    t.add_node(10);
    t.add_node(20);
    t.add_node(21);
    t.add_node(5);
    t.add_node(15);

    cout << "preorder traversal: ";
    t.preorder(t.root);
    cout << endl;

    cout << "postorder traversal: ";
    t.postorder(t.root);
    cout << endl;

    cout << "inorder traversal: ";
    t.inorder(t.root);
    cout << endl;

     cout << "levelorder traversal: ";
    t.level_order(t.root);
    cout << endl;

    cout << "Total nodes: " << t.counte_nodes(t.root) << endl;
    t.search(t.root, 15);
    t.search(t.root, 99);

    if (t.search(t.root, 21))
    {
        cout << "21 is present" << endl;
    }
    else
    {
        cout << "21 is absent" << endl;
    }

    t.root = t.deletenode(t.root, 20);
    cout << "After deleting 20, inorder traversal: ";
    t.inorder(t.root);
    cout << endl;
    return 0;
}

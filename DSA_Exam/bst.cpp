#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
class bst
{
public:
    void insert(node *root, int data)
    {
            node *subroot = root;
            while (subroot->left != NULL || subroot->right != NULL)
            {
                if (subroot->data > data)
                {
                    subroot = subroot->left;
                }
                if (subroot->data < data)
                {
                    subroot = subroot->right;
                }
            }
            if (subroot->data > data)
            {
                node *newnode;
                newnode = new node();
                newnode->data = data;
                newnode->left = NULL;
                newnode->right = NULL;
                subroot->left = newnode;
            }
            if (subroot->data < data)
            {
                node *newnode;
                newnode = new node();
                newnode->data = data;
                newnode->left = NULL;
                newnode->right = NULL;
                subroot->right = newnode;
            }
    }
    void inorder(node *root)
    {
        if (root->left != NULL)
        {
            inorder(root->left);
        }
        cout<<root->data << endl;
        if (root->right != NULL)
        {
            inorder(root->right);
        }
    }
};
int main()
{
    node *root = NULL;
    bst binst;
    int data;
    int choice;
    cout << "Enter 1 for insertion\n";
    cout << "Enter 2 for deletion\n";
    cout << "Enter 3 for traversal\n";
    cin >> choice;
    while (choice != -1)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter data to insert\n";
            cin >> data;
            if(root == NULL)
            {
            root = new node();
            root->data = data;
            root->left = NULL;
            root->right = NULL;
            }
            else
            {
            binst.insert(root, data);
            }
            break;
        case 3:
        binst.inorder(root);
        break;
        }
        cout << "Enter choice\n";
        cin >> choice;
    }
    return 0;
}
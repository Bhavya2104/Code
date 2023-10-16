/* code for level order insertion, deletion and traversal in bianry tree with menu*/
/* for inserrtion stack is used*/
#include <iostream>
#define MAX 50
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
};
class que
{
public:
    node *arr[MAX];
    int front = -1;
    int rear = -1;
    void q_insert(node *root)
    {
        if (front == (MAX + front - 1) % MAX)
        {
            cout << "Queue overflowed";
        }
        else
        {
            rear = (rear + 1) % MAX;
            arr[rear] = root;
        }
    }
    node *q_delete()
    {
        node *temp;
        if (front == rear)
        {
            cout << "Queue underflowed";
            return NULL;
        }
        else
        {
            if (front == -1)
            {
                temp = arr[front + 1];
            }
            else
                temp = arr[front];
            front = (front + 1) % MAX;
            return temp;
        }
    }
    int isempty()
    {
        if (front == rear)
        {
            cout << "Queue underflowed";
            return 0;
        }
        else
            return 1;
    }
};
class tree : public node
{
public:
    void inorder(node *root)
    {
        if (root->left != NULL)
        {
            inorder(root->left);
        }
        cout << root->data << " ";
        if (root->right != NULL)
        {
            inorder(root->right);
        }
    }
    void preorder(node *root)
    {
        cout << root->data << " ";
        if (root->left != NULL)
        {
            preorder(root->left);
        }
        if (root->right != NULL)
        {
            preorder(root->right);
        }
    }
    void postorder(node *root)
    {
        if (root->left != NULL)
        {
            postorder(root->left);
        }
        if (root->right != NULL)
        {
            postorder(root->right);
        }
        cout << root->data << " ";
    }
    void insert(node *root, int data)
    {
        que q;
        node *newnode = new node();
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        q.q_insert(root);
        int t = 0;
        while (t == 0)
        {
            node *temp = q.q_delete();
            if (temp->left != NULL && temp->right != NULL)
            {
                q.q_insert(temp->left);
                q.q_insert(temp->right);
            }
            else if (temp->left == NULL)
            {
                temp->left = newnode;
                t++;
            }
            else
            {
                temp->right = newnode;
                t++;
            }
        }
    }
    void del()
    {
    }
    void levelorder(node *root)
    {
        que q;
        q.q_insert(root);
        while (!(q.rear == q.front))
        {
            node *temp = q.q_delete();
            cout << temp->data << " ";
            if (temp->left != NULL && temp->right != NULL)
            {
                q.q_insert(temp->left);
                q.q_insert(temp->right);
            }
            else if (temp->left != NULL)
            {
                q.q_insert(temp->left);
            }
        }
    }
};
int main()
{
    node *root = NULL;
    tree t;
    int choice;
    int data;
    cout << "Enter 1 for insertion\n";
    cout << "Enter 2 for deletion\n";
    cout << "Enter 3 for preorder traversal\n";
    cout << "Enter 4 for inorder traversal\n";
    cout << "Enter 5 for postorder traversal\n";
    cout << "Enter 5 for levelorder traversal\n";
    cin >> choice;
    while (choice != -1)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter data to insert : ";
            cin >> data;
            if (root == NULL)
            {
                root = new node();
                root->data = data;
                root->left = NULL;
                root->right = NULL;
            }
            else
            {
                t.insert(root, data);
            }
            break;
        case 2:
        case 3:
            cout << "\nPreorder: ";
            t.preorder(root);
            cout << "\n";
            cout << "\n";
            break;
        case 4:
            cout << "\nInorder: ";
            t.inorder(root);
            cout << "\n";
            cout << "\n";
            break;
        case 5:
            cout << "\nPostorder: ";
            t.postorder(root);
            cout << "\n";
            cout << "\n";
            break;
        case 6:
            cout<<"\nLevelorder: ";
            t.levelorder(root);
            cout<<"\n";
            cout<<"\n";
            break;
        }
        cout << "Enter choice\n";
        cin >> choice;
    }
    return 0;
}
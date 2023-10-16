#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
class stack : public node
{
    public:
    node *top;
    int isempty(stack *head)
    {
        if(top==NULL)
        {
            return 1;
        }
        else
        return 0;
    }
    void insert(stack *head,int data)
    {
        node *newnode = new node();
        newnode->data = data;
        newnode->next = head->top;
        head->top = newnode;
    }
    int dlt(stack *head)
    {
        node *tempnode = head->top;
        int temp = tempnode->data;
        head->top = tempnode->next;
        delete(tempnode);
    }
};
int main()
{
    stack* st;
    st = new stack();
    st->next = NULL;
    cout << "Enter any to choose option and -1 to exit choice menu\n";
    int choice, data;
    cin >> choice;
    while (choice != -1)
    {
        cout << "Enter 1 to insert in stack\n";
        cout << "Enter 2 to check stack is Empty\n";
        cout << "Enter 3 to delete in stack\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data to insert\n";
            cin >> data;
            st->insert(st, data);
            break;
        case 2:
            data = st->isempty(st);
            cout << data<<endl;
            break;
        case 3:
            st->dlt(st);
        }
    }
    return 0;
}
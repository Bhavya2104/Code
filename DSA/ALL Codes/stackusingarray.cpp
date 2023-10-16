#include <iostream>
using namespace std;
class stack
{
public:
    int size;
    int top;
    int *s;
    int isempty(stack *arr)
    {
        if (arr->top == -1)
            return 1;
        else
            return 0;
    }
    int isfull(stack *arr)
    {
        if (arr->top == arr->size - 1)
            return 1;
        else
            return 0;
    }
    void insert(stack *arr, int data)
    {
        if (arr->top == arr->size - 1)
        {
            cout << "Array is full\n";
        }
        else
        {
            arr->top++;
            (arr->s)[arr->top] = data;
        }
    }
    int dlt(stack *arr)
    {
        int temp = arr->s[arr->top];
        (arr->top)--;
    }
};
int main()
{
    stack *st = new stack();
    cout << "Enter size of stack\n";
    cin >> st->size;
    st->s = new int(st->size);
    st->top = -1;
    cout << "Enter any to choose option and -1 to exit choice menu\n";
    int choice, data;
    cin >> choice;
    while (choice != -1)
    {
        cout << "Enter 1 to insert in stack\n";
        cout << "Enter 2 to check stack is full\n";
        cout << "Enter 3 to check stack is Empty\n";
        cout << "Enter 4 to delete in stack\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data to insert\n";
            cin >> data;
            st->insert(st, data);
            break;
        case 2:
            data = st->isfull(st);
            cout << data<<endl;
            break;
        case 3:
            data = st->isempty(st);
            cout << data<<endl;
            break;
        case 4:
            st->dlt(st);
        }
    }
    return 0;
}
#include<iostream>
using namespace std;
class node
{
    int data;
    node *next;
};
int main()
{
    node *root;
    int choice;
    cout<<"Enter 1 for insertion\n";
    cout<<"Enter 2 for deletion\n";
    cout<<"Enter 3 for traversal\n";
    cin>>choice;
    while(choice!= -1)
    {
       cout<<"Enter choice\n";
       cin>>choice;
    }
    return 0;
}
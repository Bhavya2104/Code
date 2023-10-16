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
    stack()
    {
        next = NULL;
    }
    void insert(int data)
    {
        
    }
};
int main()
{
    
    return 0;
}
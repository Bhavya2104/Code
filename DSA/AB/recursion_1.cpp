#include<iostream>
using namespace std;
void fun(int x)
{
    if(x>0)
    {
    cout<<x<<endl;
    fun(x-1);
    }
}
void fun2(int x)
{
    if(x>0)
    {
    fun(x-1);
    cout<<x<<endl;
    }
}
int main()
{
    int x=3;
    fun(x);
    cout<<"fun2\n";
    fun2(4);
    return 0;
}
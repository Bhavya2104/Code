/*code for finding nth elemet of fibbonaci series using recurrsion*/
#include<iostream>
using namespace std;
int fibbo(int n)
{
    if(n==0)
    {
        return 0;        
    }
    else if(n==1)
    {
        return 1;
    }
    else
    return fibbo(n-1) + fibbo(n-2);
}

int main()
{
    int x;
    x=fibbo(4);
    cout<<x;
    return 0;
}
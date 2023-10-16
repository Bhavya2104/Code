/*
Best cast o(n)
worst case o(n2) / o(n3)
*/
#include <iostream>
using namespace std;

int main()
{
    int n; //size of arr
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] < a[j])
            {
                int imposter = a[i];
                for(int k=i;k>j;k--)
                {
                    a[k] = a[k-1];
                }
                a[j] = imposter;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
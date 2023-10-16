// bubble sort 
// Time complexity = o(n2)
// inefficient 

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int k = arr[j];
                arr[j] = arr[i];
                arr[i] = k;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
    return 0;
}
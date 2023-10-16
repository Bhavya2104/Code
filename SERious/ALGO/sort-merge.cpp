// merge sort 
// time complexity = o(nlogn)
// no best case no worst case
// very efficient for large no of inputs

#include<iostream>
using namespace std;
void merge(int *arr , int s ,int e);
void mergesort(int* arr  , int s, int e)
{
    if(s>=e)
    return ;
    int mid = (s+e)/2;
    //left subarray
    mergesort(arr,s,mid);
    //right subarray
    mergesort(arr,mid+1,e);

    merge(arr,s,e);
}
void merge(int *arr , int s ,int e)
{
    int mid = (s+e)/2;
    int len1 = mid +1-s;
    int len2 = e-mid;

    //two arrays

    int * first = new int[len1];
    int * second = new int[len2];

    //input in two arrays
    int k=s;
    for(int i=0;i<len1;i++)
    {
        first[i] = arr[k++];
    }
    k = mid +1;
    for(int i=0;i<len2;i++)
    {
        second[i] = arr[k++];
    }

    //merge
    int index1=0;
    int index2=0;
    k=s;
    while(index1<len1 && index2 <len2)
    {
        if(first[index1]<second[index2])
        {
            arr[k++] = first[index1++];
        }
        else
            arr[k++] = second[index2++];
    }

    while(index1<len1)
    {
            arr[k++] = first[index1++];
    }
    while(index2<len2)
    {
            arr[k++] = second[index2++];
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
// Q- find maximum sum of all possible subarrays 
/*here solved using divide and conquer 
Time complexity - o(nlogn)

we can also solve it using brute-force method o(n2)*/


#include <iostream>
using namespace std;
int max(int a,int b,int c)
{
    if(a>b && a>c)
    return a;
    else if(b>a && b>c)
    return b;
    else
    return c;
}
int cs(int* arr,int s,int e)
{
    int mid = (s+e)/2;
    int leftmax = INT_MIN,rightmax = INT_MIN;
    int leftsum = 0, rightsum =0;
    for(int i= mid;i>=0;i--)
    {
        leftsum += arr[i];
        if(leftsum>leftmax)
        {
            leftmax = leftsum;
        }
    }
    for(int i= mid+1;i<e+1;i++)
    {
        rightsum += arr[i];
        if(rightsum>rightmax)
        {
            rightmax = rightsum;
        }
    }
    return leftmax + rightmax;
}
int maxi(int *arr, int s,int e)
{
    if(s>=e)
    return arr[s];
    else
    {
    int mid = (s+e)/2;
    int lss = maxi(arr,0,mid);
    int rss = maxi(arr,mid+1,e);
    int css = cs(arr,0,e);
    return max(lss,rss,css);
    }
}
int main()
{
    cout << "Enter size  of array\n";
    int n;
    cin >> n;
    int arr[n];
    cout << "Give Inputs\n";
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    int max = maxi(arr,0,n -1);
    cout<<max;
    return 0;
}
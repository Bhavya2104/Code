#include<iostream>
using namespace std;
class heap
{
    public:
    int arr[1000];
    int size;
    heap()
    {
        size = 0;
        arr[0] = -1;
    }

    void insert(int data)
    {
        if(size==1000)
        {
            cout<<"Heap is already Full\n";
            return;
        }
        else
        {
            size++;
            arr[size] = data;
            int i = size;
            int parent = size/2;
            while(parent>0 && arr[parent]<arr[i])
            {
                swap(arr[parent],arr[i]);
                i = parent;
                parent = i/2;
            }

            return ;
        }

    }
    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
    }

    int del()
    {
        if(size==0)
        {
            cout<<"Noting to delete\n";
            return -1;
        }
        swap(arr[1],arr[size]);
        int todel = arr[size];
        size--;
        int i = 1;
        while(i<size)
        {
            int leftchild = 2*i;
            int rightchild = 2*i+1;

             int swapIndex = i;

            if(leftchild <= size && arr[swapIndex] < arr[leftchild]){
                swapIndex = leftchild;
            }
            if(rightchild <= size && arr[swapIndex] < arr[rightchild]){
                swapIndex = rightchild;
            }

            if(i != swapIndex){
                swap(arr[i], arr[swapIndex]);
                i = swapIndex;
            }
            else{
                return todel;
            }
        }

        return todel;
    }
};
int main()
{
    int choice;
    cin>>choice;
    heap myheap;
    while(choice!=-1)
    {
        switch(choice)
        {
        case 1:
        {

            cout<<"Insert input size: ";
            int size;
            cin>>size;
            int data;
            cout<<"Enter data\n";
            while(size--)
            {
            cin>>data;
            myheap.insert(data);
            }
            break;
        }
        case 2:
        {
            int data;
            data = myheap.del();
            if(data!=-1)cout<<"Removed "<<data<<"\n";
            break;
        }
        case 3:
        {
            myheap.print();
            cout<<endl;
        }
        }
        cout<<"Enter Choice\n";
        cin>>choice;
    }
    return 0;
}
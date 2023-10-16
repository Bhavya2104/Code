#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

class myStack
{
public:
    vector<int> v;
    int top;
    myStack()
    {
        top = -1;
    }
    void push(int n)
    {
        v.push_back(n);
        top++;
    }
    int pop()
    {
        if (top == -1)
            return -1;
        int temp = v[top];
        top--;
        return temp;
    }
    int size()
    {
        return top;
    }
    bool empty()
    {
        if (top == -1)
            return true;
        return false;
    }
    int topEle()
    {
        return v[top];
    }

};

int main()
{
    bool test = false;
    int t = 1;
    if (test)
        cin >> t;
    while (t--)
    {
        int n;
        cout << "ENTER SIZE:-";
        cin >> n;
        myStack *s = new myStack();
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            s->push(x);
        }


        while (!(s->empty()))
        {
            cout << s->pop() << " ";
        }
    }
    return 0;
}

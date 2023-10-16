#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
            int a, b, c, d;
    int x, y, ans;
    cin >> a >> b >> c >> d;
    if (a % b == 0)
    {
        x = a / b;
    }
    if (c % d == 0)
    {
        y = c / d;
    }
    if (x ==y )
    {
        ans = 0;
        cout << ans << endl;
    }
    else if ((a % c == 0 && b==d)|| (b % d == 0 && a==c))
    {
        ans = 1;
        cout << ans << endl;
    }
    else 
    {
        ans = 2;
        cout << ans << endl;

    }
    }
    return 0;
}
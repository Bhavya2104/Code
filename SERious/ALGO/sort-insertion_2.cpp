/*best case o(n)
worst case o(n2)*/
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int imposter = a[i];
        int j = i - 1;
        while (j >=0 && a[j] > imposter)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = imposter;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
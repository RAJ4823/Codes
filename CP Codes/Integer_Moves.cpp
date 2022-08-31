#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0)
        {
            cout << 0 << endl;
            continue;
        }
        ll int z = (x * x) + (y * y);
        ll int a = sqrt(z);
        if (a * a == z)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    return 0;
}
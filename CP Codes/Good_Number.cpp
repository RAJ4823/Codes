#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        ll x, y, z;
        ll a, b;
        cin >> a >> b;
        x = a;
        y = a*b;
        z = a*(b+1);
        if (b == 1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            cout << x << " " << y << " " << z << endl;
        }
    }
    return 0;
}